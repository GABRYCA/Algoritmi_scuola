package eu.anonymousgca.webservicesglassfish;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDateTime;

public class MessaggioBean {

    private int id_messaggio;
    private int id_mittente;
    private int id_destinatario;
    private String tipo_messaggio;
    private String testo;
    private String url_immagine;
    private LocalDateTime data_invio;
    private boolean letto;
    private boolean cancellato;

    public MessaggioBean(){};

    /**
     * Get usando l'id_messaggio
     *
     * @return boolean
     * */
    public boolean getMessaggio() {
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String sql = "SELECT * FROM Messaggio WHERE id_messaggio = ?;";

        // Statement
        PreparedStatement ps = null;
        try {
            ps = connection.prepareStatement(sql);
            ps.setInt(1, this.id_messaggio);

            // Esegui
            ResultSet letto = ps.executeQuery();

            // Ottengo risultati
            if (letto.next()) {
                this.id_messaggio = letto.getInt("id_messaggio");
                this.id_mittente = letto.getInt("id_mittente");
                this.id_destinatario = letto.getInt("id_destinatario");
                this.tipo_messaggio = letto.getString("tipo_messaggio");
                this.testo = letto.getString("testo");
                this.url_immagine = letto.getString("url_immagine");
                this.data_invio = letto.getObject("data_invio", LocalDateTime.class);
                this.letto = letto.getBoolean("letto");
                this.cancellato = letto.getBoolean("cancellato");
            } else {
                return false;
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    /**
     * Usando id_mittente e id_destinatario e il testo del messaggio
     * inserisce un nuovo messaggio nel database
     * @return boolean
     * */
    public void inserisciMessaggio() {
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String sql = "INSERT INTO Messaggio (id_mittente, id_destinatario, tipo_messaggio, testo, url_immagine, letto, cancellato) VALUES (?, ?, ?, ?, ?, ?, ?);";

        // Statement
        PreparedStatement ps = null;
        try {
            ps = connection.prepareStatement(sql);
            ps.setInt(1, this.id_mittente);
            ps.setInt(2, this.id_destinatario);
            ps.setString(3, this.tipo_messaggio);
            ps.setString(4, this.testo);
            ps.setString(5, this.url_immagine);
            ps.setBoolean(6, this.letto);
            ps.setBoolean(7, this.cancellato);

            // Esegui
            ps.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public int getId_messaggio() {
        return id_messaggio;
    }

    public void setId_messaggio(int id_messaggio) {
        this.id_messaggio = id_messaggio;
    }

    public int getId_mittente() {
        return id_mittente;
    }

    public void setId_mittente(int id_mittente) {
        this.id_mittente = id_mittente;
    }

    public int getId_destinatario() {
        return id_destinatario;
    }

    public void setId_destinatario(int id_destinatario) {
        this.id_destinatario = id_destinatario;
    }

    public String getTipo_messaggio() {
        return tipo_messaggio;
    }

    public void setTipo_messaggio(String tipo_messaggio) {
        this.tipo_messaggio = tipo_messaggio;
    }

    public String getTesto() {
        return testo;
    }

    public void setTesto(String testo) {
        this.testo = testo;
    }

    public String getUrl_immagine() {
        return url_immagine;
    }

    public void setUrl_immagine(String url_immagine) {
        this.url_immagine = url_immagine;
    }

    public LocalDateTime getData_invio() {
        return data_invio;
    }

    public void setData_invio(LocalDateTime data_invio) {
        this.data_invio = data_invio;
    }

    public boolean isLetto() {
        return letto;
    }

    public void setLetto(boolean letto) {
        this.letto = letto;
    }

    public boolean isCancellato() {
        return cancellato;
    }

    public void setCancellato(boolean cancellato) {
        this.cancellato = cancellato;
    }

    public boolean salvaImmagine(InputStream immagine, String nomeImmagine) {
        ImgUtility imgUtility = new ImgUtility();
        try {
            return imgUtility.salvaImmagine(immagine.readAllBytes(), nomeImmagine);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
