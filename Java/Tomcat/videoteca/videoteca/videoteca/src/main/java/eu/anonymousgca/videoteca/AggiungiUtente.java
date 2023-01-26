package eu.anonymousgca.videoteca;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "AggiungiUtente", value = "/AggiungiUtente")
public class AggiungiUtente extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (session.getAttribute("loggato") == null){
            response.sendRedirect("login.jsp");
            return;
        }

        String username = request.getParameter("username");
        String password = request.getParameter("password");

        ArrayList<Utente> utenti = (ArrayList<Utente>) session.getAttribute("utenti");
        utenti.add(new Utente(username, password));

        // Messaggio di successo.
        session.setAttribute("messaggio", "Utente aggiunto con successo!");

        response.sendRedirect("aggiungiutente.jsp");
    }
}
