package eu.anonymousgca.verificajavabean;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;

@WebServlet(name = "promuovi", value = "/promuovi")
public class Promuovi extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Imposto il tipo di risposta
        response.setContentType("text/html");

        // Verifico se esiste la sessione
        HttpSession session = request.getSession(false);
        if (session == null || session.getAttribute("loggedin") == null || !(boolean) session.getAttribute("loggedin")) {
            // Se non esiste la sessione, rimando alla pagina di login.
            request.getRequestDispatcher("login.jsp").forward(request, response);
            return;
        }

        // Ottengo ID (il tipo di operazione)
        int id_Operazione = Integer.parseInt(request.getParameter("id"));
        int id_Palestra = (int)session.getAttribute("id");

        // Due numeri casuali tra il range in base al tipo di promozione, se uguali un numero casuale di utenti al corso tra 1 e 10
        // 1 = mySpace (0 e 5)
        // 2 = Facebook (0 e 3)
        // 3 = TikTok (0 e 1)
        switch (id_Operazione){
            case 1: {
                // Numero a caso tra 0 e 5
                int numeroCasuale = (int)(Math.random() * 6);
                int secondoCasuale = (int)(Math.random() * 6);

                if (numeroCasuale == secondoCasuale){
                    int numeroCasualeUtenti = (int)(Math.random() * 10) + 1;

                    // Aggiungo numeroCasualeUtenti utenti a tutti i corsi della palestra.
                    DBConnection dbConnection = new DBConnection();
                    Connection connection = dbConnection.getConnection();

                    // Ottengo a tutti i corsi con la query il numero specificato
                    String query = "UPDATE corsi SET numeroIscritti = numeroIscritti + '" + numeroCasualeUtenti + "' WHERE id_Palestra = '" + id_Palestra + "'";

                    try {
                        connection.createStatement().executeUpdate(query);
                    } catch (SQLException e) {
                        throw new RuntimeException(e);
                    }
                }

                break;
            }

            case 2: {
                // Numero a caso tra 0 e 3
                int numeroCasuale = (int)(Math.random() * 4);
                int secondoCasuale = (int)(Math.random() * 4);

                if (numeroCasuale == secondoCasuale){
                    int numeroCasualeUtenti = (int)(Math.random() * 10) + 1;

                    // Aggiungo numeroCasualeUtenti utenti a tutti i corsi della palestra.
                    DBConnection dbConnection = new DBConnection();
                    Connection connection = dbConnection.getConnection();

                    // Ottengo a tutti i corsi con la query il numero specificato
                    String query = "UPDATE corsi SET numeroIscritti = numeroIscritti + '" + numeroCasualeUtenti + "' WHERE id_Palestra = '" + id_Palestra + "'";

                    try {
                        connection.createStatement().executeUpdate(query);
                    } catch (SQLException e) {
                        throw new RuntimeException(e);
                    }
                }
                break;
            }

            case 3: {
                // Numero a caso tra 0 e 1
                int numeroCasuale = (int)(Math.random() * 2);
                int secondoCasuale = (int)(Math.random() * 2);

                if (numeroCasuale == secondoCasuale){
                    int numeroCasualeUtenti = (int)(Math.random() * 10) + 1;

                    // Aggiungo numeroCasualeUtenti utenti a tutti i corsi della palestra.
                    DBConnection dbConnection = new DBConnection();
                    Connection connection = dbConnection.getConnection();

                    // Ottengo a tutti i corsi con la query il numero specificato
                    String query = "UPDATE corsi SET numeroIscritti = numeroIscritti + '" + numeroCasualeUtenti + "' WHERE id_Palestra = '" + id_Palestra + "'";

                    try {
                        connection.createStatement().executeUpdate(query);
                    } catch (SQLException e) {
                        throw new RuntimeException(e);
                    }
                }
                break;
            }
            default:
                break;
        }

        // Scrivo esito e poi rimando alla homepage dopo 2 secondi.
        response.getWriter().println("<h1>Operazione eseguita con successo!</h1>");
        response.getWriter().println("<script>setTimeout(function(){window.location.href = '/';}, 2000);</script>");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
