package eu.anonymousgca.studente;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "CambioPassword", value = "/cambioPsw")
public class CambioPassword extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
// Creo la sessione
        HttpSession session = request.getSession();

        // Prendo la password vecchia e la nuova
        String passwordVecchia = request.getParameter("passwordAttuale");
        String passwordNuova = request.getParameter("nuovaPassword");

        // Prendo lo studente dalla sessione
        Studente studente = (Studente) session.getAttribute("studente");

        // Verifico se la password vecchia è uguale a quella dello studente
        if (passwordVecchia.equals(studente.getPassword())){
            // Cambio la password
            studente.setPassword(passwordNuova);

            // Invio alla pagina bacheca
            request.getRequestDispatcher("pagBacheca.jsp").forward(request, response);
        } else {
            // Invio alla pagina cambioPassword
            request.getRequestDispatcher("cambioPsw.jsp").forward(request, response);
        }
    }
}
