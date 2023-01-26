package eu.anonymousgca.videoteca;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "Accesso", value = "/Accesso")
public class Accesso extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        // Prendo dalla sessione username e password
        String username = (String) session.getAttribute("username");
        String password = (String) session.getAttribute("password");

        // Prendo dalla request username e password
        String usernameRequest = request.getParameter("username");
        String passwordRequest = request.getParameter("password");

        // Controllo se username e password sono uguali
        if (username.equals(usernameRequest) && password.equals(passwordRequest)) {
            // Redirect alla pagina listaDVD.jsp
            response.sendRedirect("Videoteca");
            session.setAttribute("loggato", username);
        } else {
            // Redirect alla pagina login.jsp
            response.sendRedirect("login.jsp");
            session.setAttribute("messaggio", "Username o password errati");
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
