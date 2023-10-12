package eu.anonymousgca.formativa;

import java.sql.ResultSet;
import java.sql.SQLException;

public class MovimentoBean {

    int id;
    String descrizione;
    int euro;
    int id_utente;

    public MovimentoBean() {
        id = -1;
        descrizione = "";
        euro = -1;
        id_utente = -1;
    }

    public boolean selectMovimento() {
        DBConnection con = new DBConnection();
        String query = "SELECT * FROM movimenti WHERE id=" + id + ";";
        ResultSet rs = con.eseguiSelect(query);

        try {
            while (rs.next()) {
                id = rs.getInt("id");
                descrizione = rs.getString("descrizione");
                euro = rs.getInt("euro");
                id_utente = rs.getInt("id_utente");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getDescrizione() {
        return descrizione;
    }

    public void setDescrizione(String descrizione) {
        this.descrizione = descrizione;
    }

    public int getEuro() {
        return euro;
    }

    public void setEuro(int euro) {
        this.euro = euro;
    }

    public int getId_utente() {
        return id_utente;
    }

    public void setId_utente(int id_utente) {
        this.id_utente = id_utente;
    }

    public boolean insert() {
        DBConnection con = new DBConnection();
        String query = "INSERT INTO movimenti (descrizione, euro, id_utente) VALUES ('" + descrizione + "', " + euro + ", " + id_utente + ");";
        return con.eseguiQuery(query);
    }
}
