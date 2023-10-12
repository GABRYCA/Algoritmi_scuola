package eu.anonymousgca.verificajavabean;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.Connection;
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
            String nomeStazione = request.getParameter("nomeStazione");
            String pin = request.getParameter("pin");

            DBConnection dbConnection = new DBConnection();

            // Eseguo l'autenticazione
            //UtenteBean utente = dbConnection.getUtente(username, password);
            if (!dbConnection.autenticazione(nomeStazione, pin)) {
                // Se l'utente non esiste, rimando alla pagina di login con un messaggio di errore.
                request.setAttribute("error", "Username o password errati.");
                request.getRequestDispatcher("login.jsp").forward(request, response);
            } else {

                // Facendo una query, ottengo l'id dell'utente.
                String query = "SELECT id FROM stazioni WHERE nomeStazione = '" + nomeStazione + "' AND pin = '" + pin + "';";
                Connection connection = dbConnection.getConnection();
                ResultSet rs = null;
                try {
                    rs = connection.createStatement().executeQuery(query);
                } catch (SQLException e) {
                    throw new RuntimeException(e);
                }

                if (rs == null) {
                    // Se la query non va a buon fine, rimando alla pagina di login con un messaggio di errore.
                    request.setAttribute("error", "Errore interno.");
                    request.getRequestDispatcher("login.jsp").forward(request, response);
                    return;
                }

                // Ottengo id
                int id = -1;
                try {
                    if (rs.next()) {
                        id = rs.getInt("id");
                    }
                } catch (SQLException e) {
                    throw new RuntimeException(e);
                }

                // Se l'utente esiste, creo una sessione.
                session = request.getSession();
                session.setAttribute("loggedin", true);
                session.setAttribute("id", id);
                response.sendRedirect("homepage.jsp");
            }
        } else {
            // Se esiste la sessione, rimando alla pagina di conto corrente con un messaggio di errore.
            request.setAttribute("error", "Sei già loggato.");
            request.getRequestDispatcher("homepage.jsp").forward(request, response);
        }
    }
}
