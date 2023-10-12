package eu.anonymousgca.formativa;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "autenticazione", value = "/autenticazione")
public class Autenticazione extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Eseguo autenticazione prendendo i parametri dalla richiesta (username e password) e poi
        // uso getUtente da DBConnection per verificare se esiste un utente con quell'username e password.
        // Se esiste, creo una sessione e la imposto come loggata.
        // Se non esiste, rimando alla pagina di login con un messaggio di errore.

        // Imposto il tipo di risposta
        response.setContentType("text/html");

        // Verifico se esiste la sessione
        HttpSession session = request.getSession(false);
        if (session == null || session.getAttribute("loggedin") == null || !(boolean) session.getAttribute("loggedin")) {
            // Ottengo i parametri
            String username = request.getParameter("username");
            String password = request.getParameter("password");

            DBConnection dbConnection = new DBConnection();

            // Eseguo l'autenticazione
            UtenteBean utente = dbConnection.getUtente(username, password);
            if (utente == null) {
                // Se l'utente non esiste, rimando alla pagina di login con un messaggio di errore.
                request.setAttribute("error", "Username o password errati.");
                request.getRequestDispatcher("login.jsp").forward(request, response);
            } else {
                // Se l'utente esiste, creo una sessione e la imposto come loggata.
                session = request.getSession();
                session.setAttribute("loggedin", true);
                session.setAttribute("id", utente.id);
                response.sendRedirect("contoCorrente.jsp");
            }
        } else {
            // Se esiste la sessione, rimando alla pagina di conto corrente con un messaggio di errore.
            request.setAttribute("error", "Sei già loggato.");
            request.getRequestDispatcher("contoCorrente.jsp").forward(request, response);
        }
    }
}
