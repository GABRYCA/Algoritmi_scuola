package eu.anonymousgca.pagina1;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "Login", value = "/login")
public class Login extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");

        String usernameGiusto = "admin";
        String passGiusta = "admin";

        // Creo sessione
        HttpSession session = request.getSession();

        // Prendo username
        String username = request.getParameter("username");
        // Prendo password
        String password = request.getParameter("password");

        // Controllo se username e password sono giusti
        if (username.equals(usernameGiusto) && password.equals(passGiusta)) {
            // Se sono giusti, comunico dati

            Studente studente = new Studente("Mario", "Rossi", 8.5);

            session.setAttribute("studente", studente);
            session.setMaxInactiveInterval(30*60); // 30 minuti

            PrintWriter out = response.getWriter();
            out.println("<html><body>");
            out.println("<h1>Username e password sono giusti</h1>");
            out.println("</body></html>");
        } else {
            // Se non sono giusti, reindirizzo alla pagina di login
            request.getRequestDispatcher("login.jsp").forward(request, response);
        }
    }
}
