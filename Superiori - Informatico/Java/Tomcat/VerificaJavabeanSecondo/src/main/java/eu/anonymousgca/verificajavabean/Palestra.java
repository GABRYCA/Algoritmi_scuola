package eu.anonymousgca.verificajavabean;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class Palestra {

    private int id;
    private String nomePalestra;
    private String password;
    private String imgUrl;
    private String descrizione;
    private String via;
    private String citta;

    private ListaCorsi listaCorsi;

    // Costruttore Javabean vuoto.
    public Palestra() {}

    // select da database usando l'id.
    public boolean selectPalestra() {
        // DBConnection
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String query = "SELECT * FROM palestre WHERE id = " + this.id + ";";

        // ResultSet
        ResultSet rs = null;
        try {
            rs = connection.createStatement().executeQuery(query);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        // Se il ResultSet è vuoto, ritorno false.
        if (rs == null) {
            return false;
        }

        // Altrimenti, setto i valori e ritorno true.
        try {
            while (rs.next()) {
                this.id = rs.getInt("id");
                this.nomePalestra = rs.getString("nomePalestra");
                this.password = rs.getString("password");
                this.imgUrl = rs.getString("imgUrl");
                this.descrizione = rs.getString("descrizione");
                this.via = rs.getString("via");
                this.citta = rs.getString("citta");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    // Update della stazione.
    public boolean updatePalestra(){
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query update palestre con i dati della javabean.
        String query = "UPDATE palestre SET nomePalestra = '" + this.nomePalestra + "', password = '" + this.password + "', imgUrl = '" + this.imgUrl + "', descrizione = '" + this.descrizione + "', via = '" + this.via + "', citta = '" + this.citta + "' WHERE id = " + this.id + ";";

        // Eseguo la query.
        try {
            connection.createStatement().executeUpdate(query);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    // Insert della stazione.
    public boolean insertPalestra(){
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query insert palestre con i dati della javabean.
        String query = "INSERT INTO palestre (nomePalestra, password, imgUrl, descrizione, via, citta) VALUES ('" + this.nomePalestra + "', '" + this.password + "', '" + this.imgUrl + "', '" + this.descrizione + "', '" + this.via + "', '" + this.citta + "');";

        // Eseguo la query.
        try {
            connection.createStatement().executeUpdate(query);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    // Setter e getter.
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNomePalestra() {
        return nomePalestra;
    }

    public void setNomePalestra(String nomePalestra) {
        this.nomePalestra = nomePalestra;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getImgUrl() {
        return imgUrl;
    }

    public void setImgUrl(String imgUrl) {
        this.imgUrl = imgUrl;
    }

    public String getDescrizione() {
        return descrizione;
    }

    public void setDescrizione(String descrizione) {
        this.descrizione = descrizione;
    }

    public String getVia() {
        return via;
    }

    public void setVia(String via) {
        this.via = via;
    }

    public String getCitta() {
        return citta;
    }

    public void setCitta(String citta) {
        this.citta = citta;
    }

    public void loadListaCorsi() {
        this.listaCorsi = new ListaCorsi();
        this.listaCorsi.loadCorsiPalestra(this.id);
    }

    public ListaCorsi getCorsi() {
        return listaCorsi;
    }
}
