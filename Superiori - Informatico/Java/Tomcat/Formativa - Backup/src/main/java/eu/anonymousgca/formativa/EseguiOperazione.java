package eu.anonymousgca.formativa;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

@WebServlet(name = "eseguiOperazione", value = "/eseguiOperazione")
public class EseguiOperazione extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Imposto il tipo di dati di risposta.
        response.setContentType("text/html");

        // Controllo se esiste la sessione
        HttpSession session = request.getSession(false);

        // Se esiste la sessione, eseguo l'operazione.
        if (session != null && session.getAttribute("loggedin") != null && (boolean) session.getAttribute("loggedin")) {
            // Ottengo i parametri dalla richiesta.
            String descrizione = request.getParameter("descrizione");
            int euro = Integer.parseInt(request.getParameter("valore"));
            int id_utente = (int) session.getAttribute("id");

            // Creo un oggetto MovimentoBean e lo popolo.
            MovimentoBean movimento = new MovimentoBean();
            movimento.setDescrizione(descrizione);
            movimento.setEuro(euro);
            movimento.setId_utente(id_utente);

            // Eseguo l'inserimento del movimento nel database.
            if(movimento.insert()){
                // Aggiorno il saldo del conto corrente con euro.
                DBConnection con = new DBConnection();
                // Ottengo il vecchio saldo utente.
                String query = "SELECT saldo FROM utenti WHERE id = " + id_utente + ";";
                ResultSet rs = con.eseguiSelect(query);
                int saldo = 0;
                try {
                    if (rs.next()) {
                        saldo = rs.getInt("saldo");
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                    response.getWriter().write("error");
                }
                // Aggiorno il saldo.
                saldo += euro;
                // Eseguo l'update del saldo.
                String update = "UPDATE utenti SET saldo = " + saldo + " WHERE id = " + id_utente + ";";
                if (con.eseguiQuery(update)){
                    response.getWriter().write("success");
                } else {
                    response.getWriter().write("error");
                }
            } else {
                response.getWriter().write("error");
            }
        } else {
            // Se non esiste la sessione, rimando alla pagina di login con un messaggio di errore.
            request.setAttribute("error", "Devi essere loggato per eseguire questa operazione.");
            request.getRequestDispatcher("login.jsp").forward(request, response);
        }
    }
}
