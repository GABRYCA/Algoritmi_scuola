package eu.anonymousgca.servletdb.servletdb;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

@WebServlet(name = "InsertDatabase", value = "/InsertDatabase")
public class InsertDatabase extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        try {
            Connection con = DatabaseConnection.initializeDatabase();
            inserisci(request, con);

            PrintWriter out = response.getWriter();
            out.println("<html><body><b>Inserito con successo" + " qualcosa " + "</b></body></html>");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void inserisci(HttpServletRequest request, Connection con) throws SQLException {
        PreparedStatement st = con.prepareStatement("insert into prova values(?,?)");

        st.setString(1, "Anonymous");
        st.setString(2, "esempioPassword");

        st.executeUpdate();

        st.close();
        con.close();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
