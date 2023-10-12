package eu.anonymousgca.databeans;

import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Backup {

    private static final String DB_DRIVER = "com.mysql.cj.jdbc.Driver";
    //private static final String DB_CONNECTION = "jdbc:mysql://172.22.201.51:3306/Caretti_TPS";
    private static final String DB_CONNECTION = "jdbc:mysql://129.152.17.38:3306/Caretti_TPS";


    //private static final String DB_USER = "utentedb";
    private static final String DB_USER = "anonymous_scuola";
    //private static final String DB_PASSWORD = "Cobi_2022_$";
    private static final String DB_PASSWORD = "anonymous_tps_1";

    private Connection dbConnection = null;
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