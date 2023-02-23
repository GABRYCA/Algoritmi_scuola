package eu.anonymousgca.databeans;

import java.sql.ResultSet;
import java.sql.SQLException;

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

    public String getQuerySelect() throws SQLException {

        DBConnection con = new DBConnection();
        String query = "SELECT * FROM Anagrafica WHERE IDAnagrafica = "+idAnagrafica;

        ResultSet letto = con.eseguiSelect(query);
        String risultato = letto.toString();

        idAnagrafica = letto.getInt("IDAnagrafica");
        nome = letto.getString("Nome");
        cognome = letto.getString("Cognome");
        indirizzo = letto.getString("Indirizzo");
        utente_idUtente = letto.getInt("Utente");

        return risultato;
    }

    public String getQueryInsert(){

        DBConnection con = new DBConnection();
        String query = "INSERT INTO Anagrafica (Nome, Cognome, Indirizzo, Utente) VALUES ('"+nome+"', '"+cognome+"', '"+indirizzo+"'," + utente_idUtente + ")";
        String risultato = con.eseguiQuery(query);

        return risultato;
    }

    public String getQueryUpdate(){

        DBConnection con = new DBConnection();
        String query = "UPDATE Anagrafica SET Nome = '"+nome+"', Cognome = '"+cognome+"', Indirizzo = '"+indirizzo+"', Utente = "+utente_idUtente+" WHERE IDAnagrafica = "+idAnagrafica;
        String risultato = con.eseguiQuery(query);

        return risultato;
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
}
