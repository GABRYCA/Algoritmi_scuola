package eu.anonymousgca.videoteca;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "Accesso", value = "/Accesso")
public class Accesso extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        // Prendo dal get i parametri username e password
        String username = request.getParameter("username");
        String password = request.getParameter("password");

        // Prendo dalla request username e password
        ArrayList<Utente> utenti = (ArrayList<Utente>) session.getAttribute("utenti");

        for (Utente utente : utenti) {
            if (utente.getUsername().equals(username) && utente.getPassword().equals(password)) {
                session.setAttribute("loggato", true);
                response.sendRedirect("Videoteca");
                session.setAttribute("messaggio", "Accesso effettuato con successo!");
                return;
            }
        }




        // Redirect alla pagina login.jsp
        response.sendRedirect("login.jsp");
        session.setAttribute("messaggio", "Username o password errati [" + username + " " + password + "]");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
