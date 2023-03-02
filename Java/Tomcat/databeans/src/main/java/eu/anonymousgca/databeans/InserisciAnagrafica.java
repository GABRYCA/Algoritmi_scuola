package eu.anonymousgca.databeans;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.SQLException;

@WebServlet(name = "InserisciAnagrafica", value = "/InserisciAnagrafica")
public class InserisciAnagrafica extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Setto il tipo di risposta
        response.setContentType("text/html");

        // Controllo se esiste la sessione
        HttpSession session = request.getSession(false);
        if (session == null || session.getAttribute("loggedin") == null || !(boolean) session.getAttribute("loggedin")) {
            response.sendRedirect("login.jsp");
        } else {
            // Ottengo i parametri
            String nome = request.getParameter("nome");
            String cognome = request.getParameter("cognome");
            String indirizzo = request.getParameter("indirizzo");
            int idUtente = Integer.parseInt(request.getParameter("utente").trim());

            // Ottengo dal database l'anagrafica dell'utente
            AnagraficaBean anagrafica = new AnagraficaBean();

            anagrafica.setNome(nome);
            anagrafica.setCognome(cognome);
            anagrafica.setIndirizzo(indirizzo);
            anagrafica.setUtente_idUtente(idUtente);


            // Eseguo l'insert
            if (!anagrafica.getQueryInsert()){
                response.getWriter().write("error");
                return;
            }

            // Invio stato di successo per essere utilizzato da jquery nella pagina originale.
            response.getWriter().write("success");
        }
    }
}
