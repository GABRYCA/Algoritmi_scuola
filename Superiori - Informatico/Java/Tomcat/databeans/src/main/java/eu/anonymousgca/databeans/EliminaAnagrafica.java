package eu.anonymousgca.databeans;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "EliminaAnagrafica", value = "/EliminaAnagrafica")
public class EliminaAnagrafica extends HttpServlet {
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
            int idAnagrafica = Integer.parseInt(request.getParameter("id").trim());

            AnagraficaBean anagraficaBean = new AnagraficaBean();
            anagraficaBean.setId(idAnagrafica);

            // Eseguo l'insert
            if (!anagraficaBean.getQueryDelete()){
                response.getWriter().write("error");
                return;
            }

            // Invio stato di successo per essere utilizzato da jquery nella pagina originale.
            response.getWriter().write("success");
        }
    }
}
