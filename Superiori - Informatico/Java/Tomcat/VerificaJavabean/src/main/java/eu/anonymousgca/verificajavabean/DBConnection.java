package eu.anonymousgca.verificajavabean;

import java.sql.*;

public class DBConnection {

    private static final String DB_DRIVER = "com.mysql.cj.jdbc.Driver";
    private static final String DB_CONNECTION = "jdbc:mysql://172.22.201.51:3306/TPS_Verifica_Formativa";


    private static final String DB_USER = "utentedb";
    private static final String DB_PASSWORD = "Cobi_2022_$";
    private Connection dbConnection = null;

    /**
     * Connessione al database.
     * */
    public DBConnection() {
        System.out.println("Inizio Connessione...");
        try {
            // The newInstance() call is a work around for some
            // broken Java implementations
            System.out.println("Cerco i driver...");
            Class.forName(DB_DRIVER);
            System.out.println("Driver trovati");
        } catch (Exception ex) {
            // handle the error
            System.out.println("errore JDBC (Ricordati Maven)");
        }
        try {
            Connection dbConnection = null;
            System.out.println("Provo a connettermi al Database...");
            dbConnection = DriverManager.getConnection(DB_CONNECTION, DB_USER,
                    DB_PASSWORD);

            System.out.println("SQL Connection al DB eseguita correttamente!");
            this.dbConnection = dbConnection;
        } catch (SQLException e) {
            System.out.println("Connessione a " + DB_CONNECTION + " database fallita!");
            System.out.println(e.getErrorCode() + ":" + e.getMessage());
            // throw new SQLException(e.getErrorCode() + ":" + e.getMessage());
        }
    }

    /**
     * Esegue la query dalla stringa data e ritorna se è andata a buon fine o meno.
     * */
    public boolean eseguiQuery(String query) {

        // Eseguo query di insert
        try {
            Statement stmt = dbConnection.createStatement();
            stmt.executeUpdate(query);
            return true;
        } catch (SQLException e) {
            System.out.println("Errore esecuzione query");
            e.printStackTrace();
            return false;
        }
    }

    /**
     * Autenticazione username e password.
     * */
    public boolean autenticazioneUtente(String username, String password){
        ResultSet rs = null;
        try {
            Statement stmt = dbConnection.createStatement();
            String select = "SELECT * FROM utenti WHERE username='" + username + "' AND password='" + password + "';";
            rs = stmt.executeQuery(select);
        } catch (SQLException e) {
            System.out.println("Errore esecuzione query");
            return false;
        }

        // Verifico non sia nullo.
        if (rs == null) return false;

        // Prendo il primo elemento, se disponibile, e ritorno true, altrimenti false.
        try {
            if (rs.next()){
                // Trovato, ritorno true.
                System.out.println("Utente trovato con username: " + username + " e password: " + password);
                return true;
            }
        } catch (SQLException ignored) {}

        return false;
    }

    /**
     * Esegue la query di select e ritorna il ResultSet (null se non va a buon fine).
     *
     * @param query
     * @return ResultSet
     * */
    public ResultSet eseguiSelect(String query) {
        ResultSet rs = null;
        try {
            Statement stmt = dbConnection.createStatement();
            rs = stmt.executeQuery(query);
        } catch (SQLException e) {
            System.out.println("Errore esecuzione query");
        }
        return rs;
    }

    /**
     * getConnection
     * */
    public Connection getConnection() {
        return dbConnection;
    }


}