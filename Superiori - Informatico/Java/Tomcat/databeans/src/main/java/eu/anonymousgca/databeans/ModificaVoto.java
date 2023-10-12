package eu.anonymousgca.databeans;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import javax.xml.crypto.Data;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet(name = "ModificaVoto", value = "/ModificaVoto")
public class ModificaVoto extends HttpServlet {
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
            int voto = Integer.parseInt(request.getParameter("voto").trim());
            int id = Integer.parseInt(request.getParameter("id").trim());
            String data = request.getParameter("data");
            String descrizione = request.getParameter("descrizione");

            // Ottengo dal database il voto dell'utente
            ValutazioneTPSBean votoBean = new ValutazioneTPSBean();
            votoBean.setId(id);
            try {
                votoBean.getQuerySelect();
            } catch (SQLException throwables) {
                response.getWriter().write("error");
                throwables.printStackTrace();
            }

            // Aggiorno i dati nell'oggetto dove non nulli.
            if (voto != -1) votoBean.setVoto(voto);
            if (data != null) votoBean.setData(data);
            if (descrizione != null) votoBean.setDescrizione(descrizione);

            // Eseguo l'update
            if (!votoBean.getQueryUpdate()){
                response.getWriter().write("error");
            }

            // Invio stato di successo per essere utilizzato da jquery nella pagina originale.
            response.getWriter().write("success");
        }
    }
}
