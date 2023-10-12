package eu.anonymousgca.verificajavabean;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "inserisciCorso", value = "/inserisciCorso")
public class InserisciCorso extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Imposto il tipo di risposta
        response.setContentType("text/html");

        // Verifico se esiste la sessione
        HttpSession session = request.getSession(false);
        if (session == null || session.getAttribute("loggedin") == null || !(boolean) session.getAttribute("loggedin")) {
            // Se non esiste la sessione, rimando alla pagina di login.
            request.getRequestDispatcher("login.jsp").forward(request, response);
            return;
        }

        // Ottengo i parametri
        String descrizione = request.getParameter("descrizione");
        int numeroIscritti = Integer.parseInt(request.getParameter("numeroIscritti"));
        int postiTotali = Integer.parseInt(request.getParameter("postiTotali"));
        int id_Palestra = (int)session.getAttribute("id");

        // Creo un nuovo corso
        Corso corso = new Corso();
        corso.setDescrizione(descrizione);
        corso.setNumeroIscritti(numeroIscritti);
        corso.setPostiTotali(postiTotali);
        corso.setId_Palestra(id_Palestra);
        if (corso.insertCorso()){
            // Ritorno messaggio di successo.
            response.getWriter().write("success");
        } else {
            // Ritorno messaggio di errore.
            response.getWriter().write("error");
        }
    }
}
