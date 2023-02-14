package eu.anonymousgca.databeans;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class UtenteBean {

    private int idUtente;
    private int idAnagrafica;
    private String username;
    private String password;
    private String nome;
    private String cognome;
    private String indirizzo;
    /**
     * Prima di usare i get, impostare username e password (setUsername e setPassword).
     * */
    public UtenteBean() {
        idUtente = -1;
        username = "";
        password = "";
        nome = "";
        cognome = "";
        indirizzo = "";
    }

    public UtenteBean(String username, String password) {
        this.username = username;
        this.password = password;
    }

    // Inserisci un nuovo utente nel database
    /*public void insert() throws SQLException, ClassNotFoundException {

        if (username.equals("") || password.equals("")) {
            throw new IllegalArgumentException("Username e password non possono essere vuoti.");
        }

        Connection connection = DBMS.initializeDatabase();

        // Controllo se idUtente è diverso da -1
        if (idUtente != -1) {
            throw new IllegalArgumentException("Utente già presente nel database.");
        }

        Statement statement = connection.createStatement();
        String query = "INSERT INTO Utente (username, password) VALUES ('" + username + "', '" + password + "');";
        statement.executeUpdate(query);
        statement.close();

        // Ottengo idUtente
        statement = connection.createStatement();
        query = "SELECT idUtente FROM Utente WHERE username = '" + username + "' AND password = '" + password + "';";
        ResultSet resultSet = statement.executeQuery(query);
        resultSet.next();
        idUtente = resultSet.getInt("idUtente");
        statement.close();

        // Inserisco anagrafica se i dati sono stati inseriti
        if (!(nome.equals("") || cognome.equals("") || indirizzo.equals(""))) {
            statement = connection.createStatement();
            query = "INSERT INTO Anagrafica (nome, cognome, indirizzo, utente) VALUES ('" + nome + "', '" + cognome + "', '" + indirizzo + "', " + idUtente + ");";
            statement.executeUpdate(query);
            statement.close();

            // Ottengo idAnagrafica
            statement = connection.createStatement();
            query = "SELECT idAnagrafica FROM Anagrafica WHERE utente = " + idUtente + ";";
            resultSet = statement.executeQuery(query);
            resultSet.next();
        }
    }

    public void update() throws SQLException, ClassNotFoundException {
        Connection connection = DBMS.initializeDatabase();

        if (username.equals("") || password.equals("")) {
            throw new IllegalArgumentException("Username e password non possono essere vuoti.");
        }

        // Controllo se idUtente è diverso da -1
        if (idUtente == -1) {
            throw new IllegalArgumentException("Utente non presente nel database.");
        }

        Statement statement = connection.createStatement();
        String query = "UPDATE Utente SET username = '" + username + "', password = '" + password + "' WHERE idUtente = " + idUtente + ";";
        statement.executeUpdate(query);
        statement.close();
        connection.close();

        // Inserisco anagrafica se i dati sono stati inseriti
        aggiornaAnagrafica();
    }

    public void aggiornaAnagrafica() throws SQLException, ClassNotFoundException {
        Connection connection = DBMS.initializeDatabase();

        if (nome.equals("") || cognome.equals("") || indirizzo.equals("")) {
            throw new IllegalArgumentException("Nome, cognome e indirizzo non possono essere vuoti.");
        }

        // Verifico se in anagrafica c'è già un record con idUtente
        Statement statement = connection.createStatement();
        String query = "SELECT * FROM Anagrafica WHERE utente = " + idUtente + ";";
        ResultSet resultSet = statement.executeQuery(query);
        if (resultSet.next()) {
            // Se c'è già un record, lo aggiorno
            statement = connection.createStatement();
            query = "UPDATE Anagrafica SET nome = '" + nome + "', cognome = '" + cognome + "', indirizzo = '" + indirizzo + "' WHERE idAnagrafica = " + idAnagrafica + ";";
            statement.executeUpdate(query);
            statement.close();
        } else {
            // Se non c'è un record, lo inserisco
            statement = connection.createStatement();
            query = "INSERT INTO Anagrafica (nome, cognome, indirizzo, utente) VALUES ('" + nome + "', '" + cognome + "', '" + indirizzo + "', " + idUtente + ");";
            statement.executeUpdate(query);
            statement.close();
        }

        // Ottengo idAnagrafica
        statement = connection.createStatement();
        query = "SELECT idAnagrafica FROM Anagrafica WHERE utente = " + idUtente + ";";
        resultSet = statement.executeQuery(query);
        resultSet.next();
        idAnagrafica = resultSet.getInt("idAnagrafica");
        statement.close();
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) throws SQLException, ClassNotFoundException {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public int getIdUtente() {
        return idUtente;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public String getIndirizzo() {
        return indirizzo;
    }*/

    @Override
    public String toString() {
        return "UtenteBean{" + "idUtente=" + idUtente + ", username=" + username + ", password=" + password + '}';
    }
}
