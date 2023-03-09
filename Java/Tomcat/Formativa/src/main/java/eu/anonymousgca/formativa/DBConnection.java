package eu.anonymousgca.formativa;

import java.sql.*;

public class DBConnection {

    private static final String DB_DRIVER = "com.mysql.cj.jdbc.Driver";
    private static final String DB_CONNECTION = "jdbc:mysql://172.22.201.51:3306/TPS_Verifica_Formativa";


    private static final String DB_USER = "utentedb";
    private static final String DB_PASSWORD = "Cobi_2022_$";
    private Connection dbConnection = null;

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

    public static UtenteBean getUtente(Connection connection, String username, String password) {
        Statement stmt = null;
        UtenteBean utente = new UtenteBean();
        try {
            stmt = connection.createStatement();
            String select = "SELECT * FROM utenti WHERE username='" + username + "' AND password='" + password + "';";
            ResultSet UtentiList = stmt.executeQuery(select);
            while (UtentiList.next()) {
                utente.setId(UtentiList.getInt("id"));
                utente.setUsername(UtentiList.getString("username"));
                utente.setPassword(UtentiList.getString("password"));
                utente.setNome(UtentiList.getString("nome"));
                utente.setCognome(UtentiList.getString("cognome"));
                utente.setNum_conto(UtentiList.getInt("num_conto"));
                utente.setSaldo(UtentiList.getInt("saldo"));
            }
            return utente;
        }
        //gestione errori in Java
        catch(SQLException sqle) {
            System.out.println("SELECT ERROR");
            sqle.printStackTrace();
            return null;
        }
        catch(Exception err) {
            System.out.println("GENERIC ERROR");
            return null;
        }
    }

    public Connection getDbConnection() {
        return dbConnection;
    }

    public static boolean login(Connection conn, String tabella, String username, String password) {
        Statement stmt = null;
        boolean professore=false;
        try {
            stmt = conn.createStatement();
            String select = "SELECT Ruolo FROM " + tabella + " WHERE Username='" + username + "' AND Password='" + password + "';";
            ResultSet UtentiList = stmt.executeQuery(select);
            while (UtentiList.next()) {
                System.out.println(UtentiList.getString("Ruolo"));
                if (UtentiList.getString("Ruolo").equals("professore")) {
                    professore = true;
                }
            }
            return professore;
        }
        //gestione errori in Java
        catch(SQLException sqle) {
            System.out.println("SELECT ERROR");
            sqle.printStackTrace();
            return false;
        }
        catch(Exception err) {
            System.out.println("GENERIC ERROR");
            return false;
        }
    }

    public boolean eseguiQuery(String query) {

        // Eseguo query di insert
        try {
            Statement stmt = dbConnection.createStatement();
            stmt.executeUpdate(query);
            return true;
        } catch (SQLException e) {
            System.out.println("Errore esecuzione query");
            return false;
        }

    }

    /**
     * getConnection
     * */
    public Connection getConnection() {
        return dbConnection;
    }

    /**
     * Select Query
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
}