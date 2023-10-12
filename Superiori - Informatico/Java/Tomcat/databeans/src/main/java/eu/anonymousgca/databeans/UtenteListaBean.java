package eu.anonymousgca.databeans;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class UtenteListaBean {

    ArrayList<UtenteBean> utenti;

    public UtenteListaBean() {
        utenti = new ArrayList<>();
    }

    public boolean selectUtenti(){
        DBConnection con = new DBConnection();
        String query = "SELECT * FROM Utente";
        ResultSet letto = con.eseguiSelect(query);
        try {
            while(letto.next()){
                UtenteBean utente = new UtenteBean();
                utente.setIdUtente(letto.getInt("IDUtente"));
                utente.setPassword(letto.getString("Password"));
                utente.setUsername(letto.getString("Username"));
                utente.setRuolo(letto.getString("Ruolo"));
                utenti.add(utente);
            }
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
        }
        return true;
    }

    public int getSize(){
        return utenti.size();
    }

    public UtenteBean getUtente(int i){
        return utenti.get(i);
    }

    public ArrayList<UtenteBean> getUtenti() {
        return utenti;
    }

}
