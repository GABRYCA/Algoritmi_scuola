package eu.anonymousgca.verificajavabean;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Corso {

    private int id;
    private String descrizione;
    private int numeroIscritti;
    private int postiTotali;
    private int id_Palestra;

    // Costruttore Javabean vuoto.
    public Corso() {}

    // select da database usando l'id.
    public boolean selectCorso(){
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String query = "SELECT * FROM corsi WHERE id = " + id + ";";

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

        // Altrimenti, setto i valori e ritorno true
        try {
            this.id = rs.getInt("id");
            this.descrizione = rs.getString("descrizione");
            this.numeroIscritti = rs.getInt("numeroIscritti");
            this.postiTotali = rs.getInt("postiTotali");
            this.id_Palestra = rs.getInt("id_Palestra");
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    // Update del percorso.
    public boolean updateCorsi(){
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String query = "UPDATE corsi SET descrizione = '" + descrizione + "', numeroIscritti = " + numeroIscritti + ", postiTotali = " + postiTotali + ", id_Palestra = " + id_Palestra + " WHERE id = " + id + ";";

        try {
            connection.createStatement().executeUpdate(query);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    // Insert del percorso.
    public boolean insertCorso(){
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query insert
        String query = "INSERT INTO corsi (descrizione, numeroIscritti, postiTotali, id_Palestra) VALUES ('" + descrizione + "', " + numeroIscritti + ", " + postiTotali + ", " + id_Palestra + ");";

        try {
            connection.createStatement().executeUpdate(query);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        // Altrimenti, ritorno true.
        return true;
    }

    // Getter e setter.
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

    public int getNumeroIscritti() {
        return numeroIscritti;
    }

    public void setNumeroIscritti(int numeroIscritti) {
        this.numeroIscritti = numeroIscritti;
    }

    public int getPostiTotali() {
        return postiTotali;
    }

    public void setPostiTotali(int postiTotali) {
        this.postiTotali = postiTotali;
    }

    public int getId_Palestra() {
        return id_Palestra;
    }

    public void setId_Palestra(int id_Palestra) {
        this.id_Palestra = id_Palestra;
    }

    public boolean deleteCorso() {
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String query = "DELETE FROM corsi WHERE id = " + id + ";";

        try {
            connection.createStatement().executeUpdate(query);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }
}
