package eu.anonymousgca.studente;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.util.ArrayList;
@WebServlet(name = "PagLogin", value = "/pagLogin")
public class PagLogin extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Creo la sessione
        HttpSession session = request.getSession();

        // Prendo nome, cognome, password, data di nascita, indirizzo, fotoProfilo
        String nome = request.getParameter("nome");
        String cognome = request.getParameter("cognome");
        String password = request.getParameter("password");
        String dataDiNascita = request.getParameter("dataNascita");
        String indirizzo = request.getParameter("indirizzo");
        String fotoProfilo = request.getParameter("linkFotoProfilo");

        if (fotoProfilo.equals("")){
            fotoProfilo = "";
        }

        // Verifico se la password è admin
        if (password.equals("admin")){
            // Creo una lista di messaggi da bacheca usando nome e cognome dello studente
            ArrayList<String> bacheca = new ArrayList<>();
            bacheca.add("Benvenuto " + nome + " " + cognome + "!");
            bacheca.add("Ricordati che domani ci sarà la verifica di latino!");
            bacheca.add("Inoltre devi fare TUTTI gli esercizi del capitolo! E un cartellone...");
            bacheca.add("Dimenticavamo di avvisarvi che dovete iscrivervi al corso di inglese per l'università!");

            // Creo oggetto studente con anche una lista di messaggi di benvenuto
            Studente studente = new Studente(nome, cognome, password, bacheca, dataDiNascita, indirizzo, fotoProfilo);

            // Creo un attributo studente nella sessione
            session.setAttribute("studente", studente);

            // Invio alla pagina bacheca
            request.getRequestDispatcher("pagBacheca.jsp").forward(request, response);
        } else {

            // Invio alla pagina pagLogin
            request.getRequestDispatcher("pagLogin.jsp").forward(request, response);

        }
    }
}
