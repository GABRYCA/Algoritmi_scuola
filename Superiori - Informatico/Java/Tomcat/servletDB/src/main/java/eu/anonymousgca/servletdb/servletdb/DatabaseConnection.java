package eu.anonymousgca.servletdb.servletdb;

import com.mysql.cj.jdbc.Driver;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DatabaseConnection {
    protected static Connection initializeDatabase()
            throws SQLException, ClassCastException, ClassNotFoundException {
        //String dbDriver = "com.mysql.jdbc.Driver";
        String dbURL = "jdbc:mysql://172.22.28.53:3306/";
        String dbName = "TPS_Servlet1";
        String dbUsername = "caretti";
        String dbPassword = "Cobianchi_5768";

        Class.forName(Driver.class.getName());
        Connection con = DriverManager.getConnection(dbURL + dbName, dbUsername, dbPassword);
        return con;
    }
}
