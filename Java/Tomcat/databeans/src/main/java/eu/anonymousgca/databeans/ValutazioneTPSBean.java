package eu.anonymousgca.databeans;

import java.sql.ResultSet;
import java.sql.SQLException;

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

    public String getQuerySelect() throws SQLException {

        DBConnection con = new DBConnection();
        String query = "SELECT * FROM ValutazioniTPS WHERE IDValutazioniTPS = "+idValutazioniTPS;
        ResultSet letto = con.eseguiSelect(query);
        String risultato = letto.toString();

        idValutazioniTPS = letto.getInt("IDValutazioniTPS");
        descrizione = letto.getString("Descrizione");
        data = letto.getString("Data");
        voto = letto.getInt("Voto");
        utente_idUtente = letto.getInt("Utente");

        return risultato;
    }

    public String getQueryInsert(){

        DBConnection con = new DBConnection();
        String query = "INSERT INTO ValutazioniTPS (Descrizione, Data, Voto, Utente) VALUES ('"+descrizione+"', '"+data+"', "+voto+", "+utente_idUtente+")";
        String risultato = con.eseguiQuery(query);

        return risultato;
    }

    public String getQueryUpdate(){

        DBConnection con = new DBConnection();
        String query = "UPDATE ValutazioniTPS SET Descrizione = '"+descrizione+"', Data = '"+data+"', Voto = "+voto+", Utente = "+utente_idUtente+" WHERE IDValutazioniTPS = "+idValutazioniTPS;
        String risultato = con.eseguiQuery(query);

        return risultato;
    }

    public int getIdValutazioniTPS() {
        return idValutazioniTPS;
    }

    public void setIdValutazioniTPS(int idValutazioniTPS) {
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
