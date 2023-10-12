package eu.anonymousgca.verificajavabean;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;

@WebServlet(name = "modificaCorso", value = "/modificaCorso")
public class ModificaCorso extends HttpServlet {
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
        int id = Integer.parseInt(request.getParameter("id"));
        String descrizione = request.getParameter("descrizione");
        int numeroIscritti = Integer.parseInt(request.getParameter("numeroIscritti"));
        int postiTotali = Integer.parseInt(request.getParameter("postiTotali"));
        int id_Palestra = (int)session.getAttribute("id");

        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query per modificare il corso con valori espliciti
        String query = "UPDATE corsi SET descrizione = '" + descrizione + "', numeroIscritti = '" + numeroIscritti + "', postiTotali = '" + postiTotali + "' WHERE id = '" + id + "' AND id_Palestra = '" + id_Palestra + "'";

        try {
            connection.createStatement().executeUpdate(query);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        // Comunico esito.
        response.getWriter().println("success");
    }
}
