package eu.anonymousgca.databeans;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class AnagraficaBean {

    private int idAnagrafica;
    private String nome;
    private String cognome;
    private String indirizzo;
    private int utente_idUtente;

    public AnagraficaBean() {
        idAnagrafica = -1;
        nome = "";
        cognome = "";
        indirizzo = "";
        utente_idUtente = -1;
    }

    /**
     * Ottiene i dati dell'anagrafica dal database e li inserisce nelle variabili della classe
     * Bisogna prima usare setId(int id) per settare l'id dell'anagrafica da cercare.
     * @return true se l'operazione è andata a buon fine, false altrimenti
     * @throws SQLException
     * */
    public boolean getQuerySelect() throws SQLException {

        DBConnection con = new DBConnection();
        // Query alla tabella Anagrafica con IDAnagrafica della classe
        String query = "SELECT * FROM Anagrafica WHERE IDAnagrafica = " + idAnagrafica;
        Statement stmt = con.getConnection().createStatement();
        stmt.executeQuery(query);

        ResultSet letto = stmt.getResultSet();

        if (letto.next()){
            nome = letto.getString("Nome");
            cognome = letto.getString("Cognome");
            indirizzo = letto.getString("Indirizzo");
            utente_idUtente = letto.getInt("Utente");
            return true;
        }
        return false;
    }

    public boolean getQueryInsert() {

        DBConnection con = new DBConnection();
        String query = "INSERT INTO Anagrafica (Nome, Cognome, Indirizzo, Utente) VALUES (?, ?, ?, ?)";
        try {
            PreparedStatement stmt = con.getConnection().prepareStatement(query);
            stmt.setString(1, nome);
            stmt.setString(2, cognome);
            stmt.setString(3, indirizzo);
            stmt.setInt(4, utente_idUtente);
            stmt.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    /**
     * Aggiorna i dati dell'anagrafica nel database
     * @return true se l'operazione è andata a buon fine, false altrimenti
     * */
    public boolean getQueryUpdate() {

        DBConnection con = new DBConnection();
        String query = "UPDATE Anagrafica SET Nome = '" + nome + "', Cognome = '" + cognome + "', Indirizzo = '" + indirizzo + "', Utente = " + utente_idUtente + " WHERE IDAnagrafica = " + idAnagrafica;
        try {
            Statement stmt = con.getConnection().createStatement();
            stmt.executeUpdate(query);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    public boolean getQueryDelete() {

            DBConnection con = new DBConnection();
            String query = "DELETE FROM Anagrafica WHERE IDAnagrafica = " + idAnagrafica;
            try {
                Statement stmt = con.getConnection().createStatement();
                stmt.executeUpdate(query);
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }

            return true;
    }

    public int getIdAnagrafica() {
        return idAnagrafica;
    }

    public void setIdAnagrafica(int idAnagrafica) {
        this.idAnagrafica = idAnagrafica;
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
    }

    public void setIndirizzo(String indirizzo) {
        this.indirizzo = indirizzo;
    }

    public int getUtente_idUtente() {
        return utente_idUtente;
    }

    public void setUtente_idUtente(int utente_idUtente) {
        this.utente_idUtente = utente_idUtente;
    }

    public String getId() {
        return String.valueOf(idAnagrafica);
    }

    public void setId(int id) {
        idAnagrafica = id;
    }
}
