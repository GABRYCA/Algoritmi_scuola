package eu.anonymousgca.databeans;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

public class AnagraficaListaBean {

    ArrayList<AnagraficaBean> anagrafica;

    public AnagraficaListaBean() {
        anagrafica = new ArrayList<>();
    }

    public ArrayList<AnagraficaBean> getAnagrafica() {
        return anagrafica;
    }

    public void setAnagrafica(ArrayList<AnagraficaBean> anagrafica) {
        this.anagrafica = anagrafica;
    }

    public void addUtente(AnagraficaBean utente) {
        anagrafica.add(utente);
    }

    public void removeUtente(AnagraficaBean utente) {
        anagrafica.remove(utente);
    }

    public void removeUtente(int index) {
        anagrafica.remove(index);
    }

    public AnagraficaBean getUtente(int index) {
        return anagrafica.get(index);
    }

    public int size() {
        return anagrafica.size();
    }

    public boolean selectAnagrafica(){
        DBConnection con = new DBConnection();
        String query = "SELECT * FROM Anagrafica";
        ResultSet letto = con.eseguiSelect(query);
        try {
            while(letto.next()){
                AnagraficaBean utente = new AnagraficaBean();
                utente.setIdAnagrafica(letto.getInt("IDAnagrafica"));
                utente.setNome(letto.getString("Nome"));
                utente.setCognome(letto.getString("Cognome"));
                utente.setIndirizzo(letto.getString("Indirizzo"));
                utente.setUtente_idUtente(letto.getInt("Utente"));
                anagrafica.add(utente);
            }
            return true;
        } catch (SQLException ex) {
            // Stampo errore.
            ex.printStackTrace();
            return false;
        }
    }

}
