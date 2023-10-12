package eu.anonymousgca.verificajavabean;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class ListaCorsi {

    private ArrayList<Corso> listaCorsi;

    public ListaCorsi() {
        listaCorsi = new ArrayList<Corso>();
    }

    // Carica i percorsi dal database.
    public boolean loadCorsi() {
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String query = "SELECT * FROM corsi;";

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
                Corso corso = new Corso();
                corso.setId(rs.getInt("id"));
                corso.setDescrizione(rs.getString("descrizione"));
                corso.setNumeroIscritti(rs.getInt("numeroIscritti"));
                corso.setPostiTotali(rs.getInt("postiTotali"));
                corso.setId_Palestra(rs.getInt("id_Palestra"));
                listaCorsi.add(corso);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    public boolean loadCorsiPalestra(int id_Palestra) {
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String query = "SELECT * FROM corsi WHERE id_Palestra = " + id_Palestra + ";";

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
                Corso corso = new Corso();
                corso.setId(rs.getInt("id"));
                corso.setDescrizione(rs.getString("descrizione"));
                corso.setNumeroIscritti(rs.getInt("numeroIscritti"));
                corso.setPostiTotali(rs.getInt("postiTotali"));
                corso.setId_Palestra(rs.getInt("id_Palestra"));
                listaCorsi.add(corso);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    // Ritorna la lista dei corsi.
    public ArrayList<Corso> getListaCorsi() {
        return listaCorsi;
    }

    public String getTotaleIscritti() {
        int totaleIscritti = 0;
        for (Corso corso : listaCorsi) {
            totaleIscritti += corso.getNumeroIscritti();
        }
        return String.valueOf(totaleIscritti);
    }

    public String getTotalePosti() {
        int totalePosti = 0;
        for (Corso corso : listaCorsi) {
            totalePosti += corso.getPostiTotali();
        }
        return String.valueOf(totalePosti);
    }
}
