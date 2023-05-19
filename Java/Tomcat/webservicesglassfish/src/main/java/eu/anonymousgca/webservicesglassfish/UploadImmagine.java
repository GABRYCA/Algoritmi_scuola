package eu.anonymousgca.webservicesglassfish;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "uploadImmagine", value = "/uploadImmagine")
@MultipartConfig(
        fileSizeThreshold = 1024 * 1024 * 1, // 1 MB
        maxFileSize = 1024 * 1024 * 10,      // 10 MB
        maxRequestSize = 1024 * 1024 * 100   // 100 MB
)
public class UploadImmagine extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        // Controllo che la sessione sia attiva. Se non lo è fermo tutto, se lo è continuo.
        HttpSession session = request.getSession(false);

        if (session == null || session.getAttribute("loggedin") == null || !(boolean) session.getAttribute("loggedin")) {
            // Sessione non attiva, fermo tutto.
            response.sendRedirect("login.jsp");
            return;
        }

        UtenteBean utente = (UtenteBean) session.getAttribute("utente");

        // Per debug, stampo tutti i parametri ricevuti.
        for (String key : request.getParameterMap().keySet()) {
            System.out.println(key + ": " + request.getParameter(key));
        }

        // Sessione attiva, continuo.
        // Prendo i parametri richiesti:
        int id_utente = utente.getId_utente();
        int id_utente_contatto = Integer.parseInt(request.getParameter("id_utente_contatto"));
        String testo = request.getParameter("testo");
        String nomeImmagine = request.getParameter("nomeImmagine");

        /* Receive file uploaded to the Servlet from the HTML5 form */
        Part filePart = request.getPart("file");
        String fileName = filePart.getSubmittedFileName();
        /*for (Part part : request.getParts()) {
            part.write("C:\\upload\\" + fileName);
        }*/

        // Creo un unico array di byte del file caricato.
        byte[] file = filePart.getInputStream().readAllBytes();

        // Usando ImgUtility, salvo il file caricato.
        ImgUtility imgUtility = new ImgUtility();
        if (!imgUtility.salvaImmagine(file, nomeImmagine)){
            System.out.println("Errore nel salvataggio dell'immagine.");
            return;
        }

        System.out.println("File caricato: " + fileName + " in " + imgUtility.getPercorsoUltimaImmagine());

        // Ottengo da imgUtility il percorso dell'immagine salvata.
        String percorsoImmagine = imgUtility.getPercorsoUltimaImmagine();

        // Creo un nuovo messaggio.
        MessaggioBean messaggioBean = new MessaggioBean();
        messaggioBean.setId_mittente(id_utente);
        messaggioBean.setId_destinatario(id_utente_contatto);
        messaggioBean.setTesto(testo);
        messaggioBean.setTipo_messaggio("immagine");
        messaggioBean.setUrl_immagine(percorsoImmagine);

        messaggioBean.inserisciMessaggio();

        // Reindirizzo alla pagina di chat.
        response.sendRedirect("home.jsp");

        // Invio codice di risposta di successo
        response.setStatus(200);
    }
}
