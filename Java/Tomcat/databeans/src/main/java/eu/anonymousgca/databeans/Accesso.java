package eu.anonymousgca.databeans;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;

@WebServlet(name = "Accesso", value = "/Accesso")
public class Accesso extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");

        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getDbConnection();

        PrintWriter out = response.getWriter();
        boolean connesso = false;
        if (connection == null) {
            out.println("Errore di connessione al database.<br>");
        } else {
            out.println("Connessione al database riuscito.<br>");
            connesso = true;
        }


        if (connesso){
            String username = request.getParameter("username");
            String password = request.getParameter("password");
            String tabella = "Utente";
            boolean trovato = DBConnection.login(connection, tabella, username, password);
            if (trovato){
                out.println("Accesso effettuato con successo.");
                // Creo sessione e imposto utente
                HttpSession session = request.getSession();
                session.setAttribute("loggedin", true);
                session.setAttribute("username", username);

                // Redirect a benvenuto.jsp con parametri get (username e password)
                response.sendRedirect("benvenuto.jsp?username=" + username + "&password=" + password);
            } else {
                out.println("Accesso non effettuato.<br>");
                // Invio nome utente e password inseriti
                out.println("Username: " + username);
                out.println("Password: " + password);
            }
        }
    }
}
