package eu.anonymousgca.databeans;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "InserisciVoto", value = "/InserisciVoto")
public class InserisciVoto extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Setto il tipo di risposta
        response.setContentType("text/html");

        // Controllo se esiste la sessione
        HttpSession session = request.getSession(false);
        if (session == null || session.getAttribute("loggedin") == null || !(boolean) session.getAttribute("loggedin")) {
            response.sendRedirect("login.jsp");
        } else {
            // Ottengo i parametri
            int voto = Integer.parseInt(request.getParameter("voto").trim());
            int idUtente = Integer.parseInt(request.getParameter("utente").trim());
            String descrizione = request.getParameter("descrizione");
            String data = request.getParameter("data");

            ValutazioneTPSBean votoBean = new ValutazioneTPSBean();

            votoBean.setVoto(voto);
            votoBean.setUtente_idUtente(idUtente);
            votoBean.setDescrizione(descrizione);
            votoBean.setData(data);

            // Eseguo l'insert
            if (!votoBean.getQueryInsert()){
                response.getWriter().write("error");
                return;
            }

            // Invio stato di successo per essere utilizzato da jquery nella pagina originale.
            response.getWriter().write("success");
        }
    }
}
