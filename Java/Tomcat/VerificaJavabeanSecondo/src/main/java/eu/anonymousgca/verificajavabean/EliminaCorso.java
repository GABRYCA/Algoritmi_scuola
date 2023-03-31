package eu.anonymousgca.verificajavabean;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;

@WebServlet(name = "eliminaCorso", value = "/eliminaCorso")
public class EliminaCorso extends HttpServlet {
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

        // Ottengo i parametri
        int id = Integer.parseInt(request.getParameter("id"));
        int id_Palestra = (int)session.getAttribute("id");

        // Elimino un corso.
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query per eliminare un corso con parametri espliciti.
        String query = "DELETE FROM corsi WHERE id = '" + id +  "' AND id_Palestra = '" + id_Palestra + "'";

        // Eseguo query.
        try {
            connection.createStatement().executeUpdate(query);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        // Comunico esito.
        response.getWriter().println("success");

        // Ricarico la pagina di origine.
        response.sendRedirect("homepage.jsp");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
