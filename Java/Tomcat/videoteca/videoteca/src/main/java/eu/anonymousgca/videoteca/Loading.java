package eu.anonymousgca.videoteca;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "Loading", value = "/Loading")
public class Loading extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (session.getAttribute("listaDVD") == null) {

            // Creo un ArrayList di DVD
            ArrayList<DVD> listaDVD = new ArrayList<>();
            listaDVD.add(new DVD("DVD1", "Il Signore degli Anelli"));
            listaDVD.add(new DVD("DVD2", "Il Signore degli Anelli - Le due torri"));
            listaDVD.add(new DVD("DVD3", "Il Signore degli Anelli - Il ritorno del re"));
            listaDVD.add(new DVD("DVD4", "Il Signore degli Anelli - La Compagnia dell'Anello"));

            // Salvo l'ArrayList in sessione
            session.setAttribute("listaDVD", listaDVD);
        }

        if (session.getAttribute("username") == null){
            session.setAttribute("username", "admin");
            session.setAttribute("password", "123456");
        }

        // Redirect alla pagina login.jsp
        response.sendRedirect("login.jsp");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
