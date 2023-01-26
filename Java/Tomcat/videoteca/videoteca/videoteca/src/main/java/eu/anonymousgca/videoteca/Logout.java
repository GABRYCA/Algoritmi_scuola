package eu.anonymousgca.videoteca;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "Logout", value = "/Logout")
public class Logout extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (session.getAttribute("loggato") == null){
            session.setAttribute("messaggio", "Non sei loggato!");
            response.sendRedirect("login.jsp");
            return;
        }

        session.setAttribute("loggato", null);
        session.setAttribute("messaggio", "Logout effettuato con successo!");
        response.sendRedirect("login.jsp");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
