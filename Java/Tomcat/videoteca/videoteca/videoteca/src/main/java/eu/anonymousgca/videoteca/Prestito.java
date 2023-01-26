package eu.anonymousgca.videoteca;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "Prestito", value = "/Prestito")
public class Prestito extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        // Verifico se esiste loggato
        if (session.getAttribute("loggato") == null){
            response.sendRedirect("login.jsp");
            return;
        }

        // Verifico se id nel get è presente
        if (request.getParameter("id") == null){
            response.sendRedirect("Videoteca");
            return;
        }

        // Prendo id dalla request
        String id = request.getParameter("id");

        // Prendo listaDVD dalla sessione
        ArrayList<DVD> listaDVD = (ArrayList<DVD>) session.getAttribute("listaDVD");

        if (listaDVD == null){
            response.sendRedirect("Videoteca");
            return;
        }

        // Cerco se tra i DVD c'è quello con id, e poi verifico se è noleggiabile, se lo è lo noleggio, se non lo è setto un messaggio di errore
        for (DVD dvd : listaDVD) {
            if (dvd.getCodice().equals(id)){
                if (!dvd.isNoleggiato()){
                    dvd.noleggia();
                    dvd.setNominativo((String) session.getAttribute("username"));
                    session.setAttribute("messaggio", "DVD noleggiato con successo");
                } else {
                    session.setAttribute("messaggio", "DVD non noleggiabile");
                }
                response.sendRedirect("Videoteca");
                return;
            }
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
