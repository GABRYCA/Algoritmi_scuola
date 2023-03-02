package eu.anonymousgca.databeans;

import javax.swing.plaf.nimbus.State;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class ValutazioneTPSBean {

    private int idValutazioniTPS;
    private String descrizione;
    private String data;
    private int voto;
    private int utente_idUtente;

    public ValutazioneTPSBean() {
        idValutazioniTPS = -1;
        descrizione = "";
        data = null;
        voto = -1;
        utente_idUtente = -1;
    }

    public boolean getQuerySelect() throws SQLException {

        DBConnection con = new DBConnection();
        // Prendo tutti i dati dalla tabella ValutazioneTPS con l'id passato
        String query = "SELECT * FROM ValutazioneTPS WHERE IDValutazione = "+idValutazioniTPS;
        Statement stmt = con.getConnection().createStatement();
        stmt.executeQuery(query);

        ResultSet letto = stmt.getResultSet();

        if (letto.next()){
            descrizione = letto.getString("Descrizione");
            data = letto.getString("Data");
            voto = letto.getInt("Voto");
            utente_idUtente = letto.getInt("Utente");
            return true;
        }

        return false;
    }

    public boolean getQueryInsert(){

        DBConnection con = new DBConnection();
        String query = "INSERT INTO ValutazioneTPS (Descrizione, Data, Voto, Utente) VALUES ('"+descrizione+"', '"+data+"', "+voto+", "+utente_idUtente+")";
        try {
            Statement stmt = con.getConnection().createStatement();
            stmt.executeUpdate(query);
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }

        return true;
    }

    public boolean getQueryUpdate(){

        DBConnection con = new DBConnection();
        String query = "UPDATE ValutazioneTPS SET Descrizione = '"+descrizione+"', Data = '"+data+"', Voto = "+voto+", Utente = "+utente_idUtente+" WHERE IDValutazione = "+idValutazioniTPS;
        try {
            Statement stmt = con.getConnection().createStatement();
            stmt.executeUpdate(query);
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }

        return true;
    }

    public int getIdValutazioniTPS() {
        return idValutazioniTPS;
    }

    public void setId(int idValutazioniTPS) {
        this.idValutazioniTPS = idValutazioniTPS;
    }

    public String getDescrizione() {
        return descrizione;
    }

    public void setDescrizione(String descrizione) {
        this.descrizione = descrizione;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public int getVoto() {
        return voto;
    }

    public void setVoto(int voto) {
        this.voto = voto;
    }

    public int getUtente_idUtente() {
        return utente_idUtente;
    }

    public void setUtente_idUtente(int utente_idUtente) {
        this.utente_idUtente = utente_idUtente;
    }
}
