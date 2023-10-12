package eu.anonymousgca.databeans;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class ValutazioniBean {

    private ArrayList<ValutazioneTPSBean> valutazioniTPS;
    private int idUtente;

    public ValutazioniBean() {
        valutazioniTPS = new ArrayList<>();
        idUtente = -1;
    }

    public boolean selectValutazioni(){
        DBConnection con = new DBConnection();
        String query = "SELECT * FROM ValutazioneTPS WHERE Utente = "+idUtente;
        ResultSet letto = con.eseguiSelect(query);
        try {
            while(letto.next()){
                ValutazioneTPSBean valutazioneTPS = new ValutazioneTPSBean();
                valutazioneTPS.setId(letto.getInt("IDValutazione"));
                valutazioneTPS.setDescrizione(letto.getString("Descrizione"));
                valutazioneTPS.setData(letto.getString("Data"));
                valutazioneTPS.setVoto(letto.getInt("Voto"));
                valutazioneTPS.setUtente_idUtente(letto.getInt("Utente"));
                valutazioniTPS.add(valutazioneTPS);
            }
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
        }
        return true;
    }

    public void setId(int idUtente) {
        this.idUtente = idUtente;
    }

    public int getIdUtente() {
        return idUtente;
    }

    public ArrayList<ValutazioneTPSBean> getValutazioniTPS() {
        return valutazioniTPS;
    }

    public void setValutazioniTPS(ArrayList<ValutazioneTPSBean> valutazioniTPS) {
        this.valutazioniTPS = valutazioniTPS;
    }

    public void addValutazioneTPS(ValutazioneTPSBean valutazioneTPS) {
        valutazioniTPS.add(valutazioneTPS);
    }

    public void removeValutazioneTPS(ValutazioneTPSBean valutazioneTPS) {
        valutazioniTPS.remove(valutazioneTPS);
    }

    public void removeValutazioneTPS(int index) {
        valutazioniTPS.remove(index);
    }

    public ValutazioneTPSBean getValutazioneTPS(int index) {
        return valutazioniTPS.get(index);
    }

    public int size() {
        return valutazioniTPS.size();
    }
}
