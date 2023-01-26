package eu.anonymousgca.videoteca;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "AggiungiDVD", value = "/AggiungiDVD")
public class AggiungiDVD extends HttpServlet {
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

        String titolo = request.getParameter("titolo");

        if (titolo == null || titolo.equals("")){
            session.setAttribute("messaggio", "Titolo non valido");
            response.sendRedirect("aggiungiDVD.jsp");
            return;
        }

        // Prendo DVD dalla sessione
        ArrayList<DVD> listaDVD = (ArrayList<DVD>) session.getAttribute("listaDVD");

        // Creo un nuovo ID DVDX sostituendo X con un numero e verificando che in listaDVD non ci sia già
        String id = "DVD";
        int i = 0;
        while (true){
            boolean trovato = false;
            for (DVD dvd : listaDVD) {
                if (dvd.getCodice().equals(id + i)){
                    trovato = true;
                    break;
                }
            }
            if (!trovato){
                break;
            }
            i++;
        }

        // Creo DVD
        listaDVD.add(new DVD(id + i, titolo));

        // Setto messaggio
        session.setAttribute("messaggio", "DVD aggiunto con successo!");

        // Redirect alla pagina aggiungidvd.jsp
        response.sendRedirect("aggiungidvd.jsp");
    }
}
