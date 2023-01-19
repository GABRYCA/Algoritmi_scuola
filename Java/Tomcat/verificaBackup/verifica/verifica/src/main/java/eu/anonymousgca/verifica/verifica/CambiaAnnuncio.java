package eu.anonymousgca.verifica.verifica;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "CambiaAnnuncio", value = "/CambiaAnnuncio")
public class CambiaAnnuncio extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        // Prendo l'array di appartamenti dalla sessione
        ArrayList<Appartamento> appartamenti = (ArrayList<Appartamento>) session.getAttribute("appartamenti");

        // Prendo l'indice (posizione nell'ArrayList) dell'appartamento da acquistare
        int indice = Integer.parseInt(request.getParameter("idAppartamento"));

        // Prendo l'appartamento dall'ArrayList
        Appartamento appartamento = appartamenti.get(indice);

        // Cambio l'annuncio
        if (appartamento.isAffitto()){
            appartamento.mettiInVendesi();
            session.setAttribute("messaggio", "Appartamento messo in vendita con successo!");
        } else {
            appartamento.mettiInAffitto();
            session.setAttribute("messaggio", "Appartamento messo in affitto con successo!");
        }

        // Redirect a benvenuto.jsp
        response.sendRedirect("benvenuto.jsp");
    }
}
