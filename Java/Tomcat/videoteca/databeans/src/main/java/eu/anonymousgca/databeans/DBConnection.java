package eu.anonymousgca.databeans;

import java.sql.*;

public class DBConnection {

    private static final String DB_DRIVER = "com.mysql.cj.jdbc.Driver";
    private static final String DB_CONNECTION = "jdbc:mysql://172.22.201.51:3306/Caretti_TPS";

    private static final String DB_USER = "utentedb";
    private static final String DB_PASSWORD = "Cobi_2022_$";

    private Connection dbConnection = null;

    public DBConnection() {
        String url;
        Connection con = null;
        System.out.println("Inizio Connessione...");
        try {
            // The newInstance() call is a work around for some
            // broken Java implementations
            System.out.println("Cerco i driver...");
            Class.forName(DB_DRIVER);
            System.out.println("Driver trovati");
        } catch (Exception ex) {
            // handle the error
            System.out.println("errore JDBC");
        }
        try {
            Connection dbConnection = null;
            System.out.println("Provo a connettermi al Database...");
            dbConnection = DriverManager.getConnection(DB_CONNECTION, DB_USER,
                    DB_PASSWORD);

            System.out.println("SQL Connection to DB eseguita correttamente!");
            this.dbConnection = dbConnection;
        } catch (SQLException e) {
            System.out.println("Connection to dbmio database failed");
            System.out.println(e.getErrorCode() + ":" + e.getMessage());
            // throw new SQLException(e.getErrorCode() + ":" + e.getMessage());
        }
    }

    public Connection getDbConnection() {
        return dbConnection;
    }

    public static boolean QuerySelect(Connection conn, String tabella, String username, String password) {
        Statement stmt = null;
        boolean trovato=false;
        try {
            stmt = conn.createStatement();
            String select = "SELECT * FROM " + tabella + " WHERE Username='" + username + "' AND Password='" + password + "';";
            ResultSet UtentiList = stmt.executeQuery(select);
            while (UtentiList.next()) {
                System.out.println(UtentiList.getString("id"));
                System.out.println(UtentiList.getString("Username"));
                System.out.println(UtentiList.getString("Password"));
                trovato=true;
            }
            return trovato;
        }
        //gestione errori in Java
        catch(SQLException sqle) {
            System.out.println("SELECT ERROR");
            return false;
        }
        catch(Exception err) {
            System.out.println("GENERIC ERROR");
            return false;
        }
    }
}
