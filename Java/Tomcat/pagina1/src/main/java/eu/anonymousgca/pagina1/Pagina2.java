package eu.anonymousgca.pagina1;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "Pagina2", value = "/pagina2")
public class Pagina2 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");

        // Prendo il nome
        String nome = request.getParameter("nome");
        // Prendo il cognome
        String cognome = request.getParameter("cognome");
        // Prendo la media
        String media = request.getParameter("media");

        // Creo oggetto studente
        Studente studente = new Studente(nome, cognome, Double.parseDouble(media));

        /*request.setAttribute("nome", studente.getInfo());
        try {
            request.getRequestDispatcher("pagina2.jsp").forward(request, response);
        } catch (ServletException e) {
            e.printStackTrace();
        }*/

        // Stampo con println
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("<h1>" + studente.getInfo() + "</h1>");
        out.println("</body></html>");
    }
}
