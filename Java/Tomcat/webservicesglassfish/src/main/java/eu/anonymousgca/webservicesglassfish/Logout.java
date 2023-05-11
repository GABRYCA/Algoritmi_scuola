package eu.anonymousgca.webservicesglassfish;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "logout", value = "/logout")
public class Logout extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Controlla se è attiva la sessione, nel caso lo sia, esegue il logout distruggendo la sessione e rimandando alla pagina di login.
        HttpSession session = request.getSession(false);
        if (session != null && session.getAttribute("loggedin") != null && (boolean) session.getAttribute("loggedin")) {
            session.invalidate();
            response.sendRedirect("login.jsp");
        } else {
            response.sendRedirect("login.jsp");
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Controlla se è attiva la sessione, nel caso lo sia, esegue il logout distruggendo la sessione e rimandando alla pagina di login.
        HttpSession session = request.getSession(false);
        if (session != null && session.getAttribute("loggedin") != null && (boolean) session.getAttribute("loggedin")) {
            session.invalidate();
            response.sendRedirect("login.jsp");
        } else {
            response.sendRedirect("login.jsp");
        }
    }
}
