package eu.anonymousgca.verificajavabean;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.ResultSet;
import java.sql.SQLException;

@WebServlet(name = "autenticazione", value = "/autenticazione")
public class Autenticazione extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Prendo post da login.jsp con username e password e faccio l'autenticazione con la DBConnection.
        // Se l'autenticazione va a buon fine, creo una sessione e imposto la variabile di sessione loggedin a true e id.
        // Se l'autenticazione non va a buon fine, rimando alla pagina di login con un messaggio di errore.

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
            //UtenteBean utente = dbConnection.getUtente(username, password);
            if (!dbConnection.autenticazioneUtente(username, password)) {
                // Se l'utente non esiste, rimando alla pagina di login con un messaggio di errore.
                request.setAttribute("error", "Username o password errati.");
                request.getRequestDispatcher("login.jsp").forward(request, response);
            } else {

                // Facendo una query, ottengo l'id dell'utente.
                String query = "SELECT id FROM utenti WHERE username = '" + username + "' AND password = '" + password + "';";
                ResultSet rs = dbConnection.eseguiSelect(query);
                if (rs == null) {
                    // Se la query non va a buon fine, rimando alla pagina di login con un messaggio di errore.
                    request.setAttribute("error", "Errore interno.");
                    request.getRequestDispatcher("login.jsp").forward(request, response);
                    return;
                }

                int id = -1;
                try {
                    id = rs.getInt("id");
                } catch (SQLException e) {
                    throw new RuntimeException(e);
                }

                // Se l'utente esiste, creo una sessione.
                session = request.getSession();
                session.setAttribute("loggedin", true);
                session.setAttribute("id", id);
                response.sendRedirect("principale.jsp");
            }
        } else {
            // Se esiste la sessione, rimando alla pagina di conto corrente con un messaggio di errore.
            request.setAttribute("error", "Sei già loggato.");
            request.getRequestDispatcher("principale.jsp").forward(request, response);
        }
    }
}
