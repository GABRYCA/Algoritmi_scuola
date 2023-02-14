package eu.anonymousgca.databeans;

import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBMS {

    protected static Connection initializeDatabase()
            throws SQLException, ClassCastException, ClassNotFoundException {
        String dbDriver = "com.mysql.cj.jdbc.Driver";
        Class.forName(dbDriver);
        String dbURL = "jdbc:mysql://129.152.17.38:3306/";
        String dbName = "Caretti_TPS";
        String dbUsername = "anonymous_scuola";
        String dbPassword = "anonymous_tps_1";

        Class.forName(Driver.class.getName());
        return DriverManager.getConnection(dbURL + dbName, dbUsername, dbPassword);
    }
}