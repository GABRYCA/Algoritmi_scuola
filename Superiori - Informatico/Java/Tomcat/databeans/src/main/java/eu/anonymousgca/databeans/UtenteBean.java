package eu.anonymousgca.databeans;

import java.sql.ResultSet;
import java.sql.SQLException;

public class UtenteBean {

    private int idUtente;
    private String username;
    private String password;
    private String ruolo;
    /**
     * Prima di usare i get, impostare username e password (setUsername e setPassword).
     * */
    public UtenteBean() {
        idUtente = -1;
        username = "";
        password = "";
    }

    public String getQuerySelect() throws SQLException {

        DBConnection con = new DBConnection();
        String query = "SELECT * FROM Utente WHERE Username = '"+username+"' AND Password = '"+password+"'";
        ResultSet letto = con.eseguiSelect(query);

        String risultato = letto.toString();

        idUtente = letto.getInt("IDUtente");

        return risultato;
    }

    public String getQueryInsert(){

        DBConnection con = new DBConnection();
        String query = "INSERT INTO Utente (Username, Password) VALUES ('"+username+"', '"+password+"')";
        String risultato = con.eseguiQuery(query);

        return risultato;
    }

    public String getQueryUpdate(){

        DBConnection con = new DBConnection();
        String query = "UPDATE Utente SET Username = '"+username+"', Password = '"+password+"' WHERE IDUtente = "+idUtente;
        String risultato = con.eseguiQuery(query);

        return risultato;
    }

    public int getIdUtente() {
        return idUtente;
    }

    public void setIdUtente(int idUtente) {
        this.idUtente = idUtente;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    @Override
    public String toString() {
        return "UtenteBean{" + "idUtente=" + idUtente + ", username=" + username + ", password=" + password + '}';
    }

    public AnagraficaBean getAnagrafica() throws SQLException {
        AnagraficaBean anagrafica = new AnagraficaBean();
        anagrafica.setId(idUtente);
        anagrafica.getQuerySelect();
        return anagrafica;
    }

    public void setRuolo(String ruolo) {
        this.ruolo = ruolo;
    }

    public String getRuolo() {
        return ruolo;
    }
}
