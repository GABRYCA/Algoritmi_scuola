package eu.anonymousgca.videoteca;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "Videoteca", value = "/Videoteca")
public class Videoteca extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        // Verifico se esiste loggato
        if (session.getAttribute("loggato") == null){
            response.sendRedirect("login.jsp");
            return;
        }

        // Imposto i parametri nella pagina videoteca.js
        request.setAttribute("titoloPagina", "Stato videonoleggio");
        request.setAttribute("descrizionePagina", "Questo è il pannello per noleggiare i DVD");

        request.getRequestDispatcher("videoteca.jsp").forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
