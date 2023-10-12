package eu.anonymousgca.verifica.verifica;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "Acquista", value = "/Acquista")
public class Acquista extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        // Prendo l'array di appartamenti dalla sessione
        ArrayList<Appartamento> appartamenti = (ArrayList<Appartamento>) session.getAttribute("appartamenti");

        // Prendo l'utente dalla sessione (se c'è)
        Utente utente = (Utente) session.getAttribute("utente");

        // Prendo l'indice (posizione nell'ArrayList) dell'appartamento da acquistare
        int indice = Integer.parseInt(request.getParameter("idAppartamento"));

        // Prendo l'appartamento dall'ArrayList
        Appartamento appartamento = appartamenti.get(indice);

        // Acquisto l'appartamento
        if (appartamento.isArchiviato()){
            session.setAttribute("messaggio", "Appartamento già archiviato!");
        } else {
            if (utente != null){
                if (utente.getSaldo() >= appartamento.getPrezzo()){
                    utente.setSaldo(utente.getSaldo() - appartamento.getPrezzo());
                    appartamento.setProprietario(utente.getUsername());
                    appartamento.archivia();
                    session.setAttribute("messaggio", "Appartamento acquistato con successo!");
                } else {
                    session.setAttribute("messaggio", "Non hai abbastanza soldi! Appartamento non acquistato!");
                }
            } else {
                appartamento.archivia();
                session.setAttribute("messaggio", "Appartamento archiviato con successo!");
            }
        }

        // Redirect a benvenuto.jsp
        response.sendRedirect("benvenuto.jsp");
    }
}
