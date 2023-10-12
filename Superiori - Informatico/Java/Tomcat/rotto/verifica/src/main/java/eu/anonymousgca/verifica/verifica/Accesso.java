package eu.anonymousgca.verifica.verifica;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "Accesso", value = "/Accesso")
public class Accesso extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        // Carico gli utenti dalla session
        ArrayList<Utente> utenti = (ArrayList<Utente>) session.getAttribute("utenti");

        // Prendo i dati dal form
        String username = request.getParameter("username");
        String password = request.getParameter("password");

        // Controllo se l'utente esiste
        for (Utente utente : utenti){
            if (utente.getUsername().equals(username) && utente.getPassword().equals(password)){
                // Se l'utente esiste, lo metto in sessione
                session.setAttribute("utente", utente);
                // Redirect a benvenuto.jsp
                response.sendRedirect("benvenuto.jsp");
                return;
            }
        }

        response.sendRedirect("accesso.jsp");
    }
}
