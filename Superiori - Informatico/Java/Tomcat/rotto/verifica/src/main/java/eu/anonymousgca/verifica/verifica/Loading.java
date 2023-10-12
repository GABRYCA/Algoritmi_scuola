package eu.anonymousgca.verifica.verifica;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "Loading", value = "/Loading")
public class Loading extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        HttpSession session = request.getSession();

        // Inizializzo sei Appartamenti in automatico e li salvo nella sessione, poi faccio redirect a benvenuto.jsp
        // Array di appartamenti
        ArrayList<Appartamento> appartamenti = new ArrayList<>();
        appartamenti.add(new Appartamento("Milano", 10000));
        appartamenti.add(new Appartamento("Roma", 20000));
        appartamenti.add(new Appartamento("Napoli", 30000));
        appartamenti.add(new Appartamento("Torino", 40000));
        appartamenti.add(new Appartamento("Palermo", 50000));
        appartamenti.add(new Appartamento("Bologna", 60000));

        // Metto in affitto i primi tre (per esempio)
        appartamenti.get(0).mettiInAffitto();
        appartamenti.get(1).mettiInAffitto();
        appartamenti.get(2).mettiInAffitto();

        // Metto in vendita i successivi tre (per esempio)
        appartamenti.get(3).mettiInVendesi();
        appartamenti.get(4).mettiInVendesi();
        appartamenti.get(5).mettiInVendesi();

        // Salvo l'array di appartamenti nella sessione
        session.setAttribute("appartamenti", appartamenti);

        // Inizializzo due Utente in automatico e li salvo nella sessione (il primo ha saldo 100000 e il secondo 50000)
        ArrayList<Utente> utenti = new ArrayList<>();
        utenti.add(new Utente("Mario", "Rossi", "Mario", "admin", 100000));
        utenti.add(new Utente("Luigi", "Bianchi", "Luigi", "admin",50000));

        session.setAttribute("utenti", utenti);

        // Redirect a benvenuto.jsp
        response.sendRedirect("accesso.jsp");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    }
}
