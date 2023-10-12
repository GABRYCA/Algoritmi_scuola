package eu.anonymousgca.webservicesglassfish;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "login", value = "/login")
public class Login extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        // Controllo se esiste già la session (controllo anche se loggedin = true) nel caso esista, mando a home.jsp, altrimenti
        // Effettuo le solite operazioni di login.
        HttpSession session = request.getSession(false);

        if (session != null && session.getAttribute("loggedin") != null && (boolean) session.getAttribute("loggedin")) {
            // Sessione già esistente, mando a home.jsp
            response.sendRedirect("home.jsp");
        } else {
            String email = request.getParameter("email");
            String password = request.getParameter("password");


            DBConnection dbConnection = new DBConnection();
            if (dbConnection.autenticazione(email, password)) {
                // Autenticazione riuscita.
                session = request.getSession();
                session.setAttribute("loggedin", true);

                UtenteBean utenteBean = new UtenteBean();
                utenteBean.setEmail(email);
                utenteBean.getUtentePerEmail();
                session.setAttribute("utente", utenteBean);

                response.sendRedirect("home.jsp");
                response.getWriter().println("true");
            } else {
                // Autenticazione fallita.
                response.sendRedirect("login.jsp");
                // Stampo e invio in output un messaggio di errore.
                response.getWriter().println("false");
            }
        }

    }
}
