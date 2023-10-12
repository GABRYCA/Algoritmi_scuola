package eu.anonymousgca.formativa;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.ResultSet;

@WebServlet(name = "eseguiInvestimento", value = "/eseguiInvestimento")
public class EseguiInvestimento extends HttpServlet {
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
            String descrizione = request.getParameter("rischio");
            int euro = Integer.parseInt(request.getParameter("valore"));
            int id_utente = (int) session.getAttribute("id");

            // Modifico euro in base al rischio.
            // Rischio basso: due numeri random tra 0 e 2, se sono uguali guadagni un terzo della cifra investita altrimenti perdi.
            // Rischio medio: due numeri random tra 0 e 4, se sono uguali guadagni metà della cifra investita altrimenti perdi.
            // Rischio alto: due numeri random tra 0 e 8, se sono uguali guadagni la cifra investita altrimenti perdi.
            switch (descrizione) {
                case "basso": {
                    if (numeroRandom(0,2) == numeroRandom(0,2)) {
                        euro += euro / 3;
                    } else {
                        euro = -euro;
                    }
                    break;
                }
                case "medio": {
                    if (numeroRandom(0,4) == numeroRandom(0,4)) {
                        euro += euro / 2;
                    } else {
                        euro = -euro;
                    }
                    break;
                }
                case "alto": {
                    if (numeroRandom(0,8) == numeroRandom(0,8)) {
                        euro += euro;
                    } else {
                        euro = -euro;
                    }
                    break;
                }

                default: {
                    response.getWriter().write("error");
                    break;
                }
            }

            // Creo un oggetto MovimentoBean e lo popolo.
            MovimentoBean movimento = new MovimentoBean();
            movimento.setDescrizione("Investimento di rischio " + descrizione);
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
                    if (euro > 0) {
                        response.getWriter().write("Hai guadagnato " + euro + " euro!");
                    } else {
                        response.getWriter().write("Investimento negativo! " + euro + " euro!");
                    }
                } else {
                    response.getWriter().write("error");
                }
            } else {
                response.getWriter().write("error");
            }
        } else {
            response.getWriter().write("error");
        }
    }

    private int numeroRandom(int min, int max){
        int numeroRandom = (int) (Math.random() * (max - min + 1) + min);
        System.out.println(numeroRandom);
        return numeroRandom;
    }
}
