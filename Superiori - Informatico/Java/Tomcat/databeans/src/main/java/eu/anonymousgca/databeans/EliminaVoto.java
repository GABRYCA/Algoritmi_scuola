package eu.anonymousgca.databeans;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "EliminaVoto", value = "/EliminaVoto")
public class EliminaVoto extends HttpServlet {
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
            int idValutazione = Integer.parseInt(request.getParameter("id").trim());

            ValutazioneTPSBean votoBean = new ValutazioneTPSBean();
            votoBean.setId(idValutazione);

            // Eseguo l'insert
            if (!votoBean.getQueryDelete()){
                response.getWriter().write("error");
                return;
            }

            // Invio stato di successo per essere utilizzato da jquery nella pagina originale.
            response.getWriter().write("success");
        }
    }
}
