package eu.anonymousgca.formativa;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "eseguiOperazione", value = "/eseguiOperazione")
public class EseguiOperazione extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Imposto il tipo di dati di risposta.
        response.setContentType("text/html");

        // Controllo se esiste la sessione
        HttpSession session = request.getSession(false);

        // Se esiste la sessione, eseguo l'operazione.
        if (session != null && session.getAttribute("loggedin") != null && (boolean) session.getAttribute("loggedin")) {
            // Ottengo i parametri dalla richiesta.
            String descrizione = request.getParameter("descrizione");
            int euro = Integer.parseInt(request.getParameter("valore"));
            int id_utente = (int) session.getAttribute("id");

            // Creo un oggetto MovimentoBean e lo popolo.
            MovimentoBean movimento = new MovimentoBean();
            movimento.setDescrizione(descrizione);
            movimento.setEuro(euro);
            movimento.setId_utente(id_utente);

            // Eseguo l'inserimento del movimento nel database.
            if(movimento.insert()){
                response.getWriter().write("success");
            } else {
                response.getWriter().write("error");
            }
        } else {
            // Se non esiste la sessione, rimando alla pagina di login con un messaggio di errore.
            request.setAttribute("error", "Devi essere loggato per eseguire questa operazione.");
            request.getRequestDispatcher("login.jsp").forward(request, response);
        }
    }
}
