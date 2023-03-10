package eu.anonymousgca.formativa;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.PreparedStatement;

@WebServlet(name = "modificaDatiUtente", value = "/modificaDatiUtente")
public class ModificaDatiUtente extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Imposto il tipo di risposta
        response.setContentType("text/html");

        // Verifico se esiste la sessione
        HttpSession session = request.getSession(false);
        if (session != null && session.getAttribute("loggedin") != null && (boolean) session.getAttribute("loggedin")) {
            // Ottengo i parametri
            String username = request.getParameter("username");
            String nome = request.getParameter("nome");
            String cognome = request.getParameter("cognome");
            int id = (int) session.getAttribute("id");

            UtenteBean utente = new UtenteBean();
            utente.setId(id);

            // Ottengo dati utente.
            utente.selectUtente();

            // Setto i nuovi dati.
            utente.setUsername(username);
            utente.setNome(nome);
            utente.setCognome(cognome);

            // Aggiorno i dati.
            if (utente.updateUtente()) {

                // Stampo alert
                PrintWriter scrivi = response.getWriter();

                // Stampo alert e reindirizzo al contoCorrente.
                scrivi.println("<script type=\"text/javascript\">");
                scrivi.println("alert('Dati modificati con successo!');");
                scrivi.println("location='contoCorrente.jsp';");
                scrivi.println("</script>");
            } else {
                // Stampo alert
                PrintWriter scrivi = response.getWriter();

                // Stampo alert e reindirizzo al contoCorrente.
                scrivi.println("<script type=\"text/javascript\">");
                scrivi.println("alert('Errore durante la modifica dei dati!');");
                scrivi.println("location='modificaDati.jsp';");
                scrivi.println("</script>");
            }
        } else {
            PrintWriter scrivi = response.getWriter();
            // Non sei loggato.
            scrivi.println("<script type=\"text/javascript\">");
            scrivi.println("alert('Non sei loggato!');");
            scrivi.println("location='login.jsp';");
            scrivi.println("</script>");
        }
    }
}
