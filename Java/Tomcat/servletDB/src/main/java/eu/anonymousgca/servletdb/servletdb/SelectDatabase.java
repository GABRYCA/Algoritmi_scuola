package eu.anonymousgca.servletdb.servletdb;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "SelectDatabase", value = "/SelectDatabase")
public class SelectDatabase extends HttpServlet {

    ResultSet letto;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html><head><title>Prova Select</title></head><body>");
        out.println("<h1>Prova Select</h1>");

        try {
            Connection con = DatabaseConnection.initializeDatabase();
            leggi(request, con);

            // Verifico se letto è vuoto
            if (letto.next()) {
                // Se non è vuoto, allora stampo il risultato
                out.println("<b>Letto con successo" + " qualcosa " + "</b>");
                out.println("<b>" + letto.getString(1) + "</b>");
            } else {
                // Se è vuoto, allora stampo un messaggio di errore
                out.println("<b>Non ci sono dati" + " nella tabella " + "</b>");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        out.println("</body></html>");
    }

    private void leggi(HttpServletRequest request, Connection con) throws SQLException {
        // Usando il select, leggo dal database tutte le righe e le salvo nell'arraylist list
        PreparedStatement st = con.prepareStatement("select * from utente");

        letto = st.executeQuery();

        st.close();
        con.close();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
