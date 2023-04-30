package eu.anonymousgca.webservicesglassfish;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Date;

public class UtenteBean {
    private int id_utente;
    private String email;
    private String password;
    private String nome;
    private String stato;
    private Date ultimo_accesso;

    public UtenteBean(){};

    /**
     * Get usando l'id_utente
     *
     * @return boolean
     * */
    public boolean getUtente() {
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String sql = "SELECT * FROM Utente WHERE id_utente = ?;";

        // Statement
        PreparedStatement ps = null;
        try {
            ps = connection.prepareStatement(sql);
            ps.setInt(1, this.id_utente);

            // Esegui
            ResultSet letto = ps.executeQuery();

            // Ottengo risultati
            if (letto.next()) {
                this.id_utente = letto.getInt("id_utente");
                this.email = letto.getString("email");
                this.password = letto.getString("password");
                this.nome = letto.getString("nome");
                this.stato = letto.getString("stato");
                this.ultimo_accesso = letto.getDate("ultimo_accesso");
            } else {
                return false;
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    /**
     * Get usando l'email
     *
     * @return boolean
     * */
    public boolean getUtentePerEmail() {
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String sql = "SELECT * FROM Utente WHERE email = ?;";

        // Statement
        PreparedStatement ps = null;
        try {
            ps = connection.prepareStatement(sql);
            ps.setString(1, this.email);

            // Esegui
            ResultSet letto = ps.executeQuery();

            // Ottengo risultati
            if (letto.next()) {
                this.id_utente = letto.getInt("id_utente");
                this.email = letto.getString("email");
                this.password = letto.getString("password");
                this.nome = letto.getString("nome");
                this.stato = letto.getString("stato");
                this.ultimo_accesso = letto.getDate("ultimo_accesso");
            } else {
                return false;
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    /**
     * MessaggioBean ArrayList dei messaggi inviati.
     *
     * @return ArrayList<MessaggioBean>
     * */
    public ArrayList<MessaggioBean> getMessaggiInviati() {
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String sql = "SELECT * FROM Messaggio WHERE id_mittente = ?;";

        // Statement
        return leggiMessaggi(connection, sql);
    }

    /**
     * MessaggioBean ArrayList dei messaggi ricevuti.
     *
     * @return ArrayList<MessaggioBean>
     * */
    public ArrayList<MessaggioBean> getMessaggiRicevuti() {
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String sql = "SELECT * FROM Messaggio WHERE id_destinatario = ?;";

        // Statement
        return leggiMessaggi(connection, sql);
    }

    /**
     * MessaggioBean Arraylist dei messaggi inviati e ricevuti, ordinati per data (dal più vecchio al più recente).
     *
     * @return ArrayList<MessaggioBean>
     * */
    public ArrayList<MessaggioBean> getMessaggiInviatiERicevuti() {
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String sql = "SELECT * FROM Messaggio WHERE id_mittente = ? OR id_destinatario = ? ORDER BY data_invio ASC;";

        // Statement
        PreparedStatement ps = null;
        try {
            ps = connection.prepareStatement(sql);
            ps.setInt(1, this.id_utente);
            ps.setInt(2, this.id_utente);

            // Esegui
            ResultSet letto = ps.executeQuery();

            // Ottengo risultati
            ArrayList<MessaggioBean> messaggi = new ArrayList<MessaggioBean>();
            while (letto.next()) {
                MessaggioBean messaggio = new MessaggioBean();
                messaggio.setId_messaggio(letto.getInt("id_messaggio"));
                messaggio.setId_mittente(letto.getInt("id_mittente"));
                messaggio.setId_destinatario(letto.getInt("id_destinatario"));
                messaggio.setTipo_messaggio(letto.getString("tipo_messaggio"));
                messaggio.setTesto(letto.getString("testo"));
                messaggio.setUrl_immagine(letto.getString("url_immagine"));
                messaggio.setData_invio(letto.getObject("data_invio", LocalDateTime.class));
                messaggio.setLetto(letto.getBoolean("letto"));
                messaggio.setCancellato(letto.getBoolean("cancellato"));
                messaggi.add(messaggio);
            }

            return messaggi;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private ArrayList<MessaggioBean> leggiMessaggi(Connection connection, String sql) {
        PreparedStatement ps = null;
        try {
            ps = connection.prepareStatement(sql);
            ps.setInt(1, this.id_utente);

            // Esegui
            ResultSet letto = ps.executeQuery();

            // Ottengo risultati
            ArrayList<MessaggioBean> messaggi = new ArrayList<MessaggioBean>();
            while (letto.next()) {
                MessaggioBean messaggio = new MessaggioBean();
                messaggio.setId_messaggio(letto.getInt("id_messaggio"));
                messaggio.setId_mittente(letto.getInt("id_mittente"));
                messaggio.setId_destinatario(letto.getInt("id_destinatario"));
                messaggio.setTipo_messaggio(letto.getString("tipo_messaggio"));
                messaggio.setTesto(letto.getString("testo"));
                messaggio.setUrl_immagine(letto.getString("url_immagine"));
                messaggio.setData_invio(letto.getObject("data_invio", LocalDateTime.class));
                messaggio.setLetto(letto.getBoolean("letto"));
                messaggio.setCancellato(letto.getBoolean("cancellato"));
                messaggi.add(messaggio);
            }

            return messaggi;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * Ritorna lista Utenti che hanno scritto almeno un messaggio all'utente.
     * @return vettore associativo UtenteBean e String messaggio
     * */
    public ArrayList<UtenteBean> getListaUtentiContattati() {
        DBConnection dbConnection = new DBConnection();
        Connection connection = dbConnection.getConnection();

        // Query
        String sql = "SELECT * FROM Utente WHERE id_utente IN (SELECT id_mittente FROM Messaggio WHERE id_destinatario = ?) OR id_utente IN (SELECT id_destinatario FROM Messaggio WHERE id_mittente = ?);";

        // Statement
        PreparedStatement ps = null;
        try {
            ps = connection.prepareStatement(sql);
            ps.setInt(1, this.id_utente);
            ps.setInt(2, this.id_utente);

            // Esegui
            ResultSet letto = ps.executeQuery();

            // Ottengo risultati
            ArrayList<UtenteBean> utenti = new ArrayList<UtenteBean>();
            while (letto.next()) {
                UtenteBean utente = new UtenteBean();
                utente.setId_utente(letto.getInt("id_utente"));
                utente.setEmail(letto.getString("email"));
                utente.setPassword(letto.getString("password"));
                utente.setNome(letto.getString("nome"));
                utente.setStato(letto.getString("stato"));
                utente.setUltimo_accesso(letto.getDate("ultimo_accesso"));
                utenti.add(utente);
            }

            return utenti;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public int getId_utente() {
        return this.id_utente;
    }

    public void setId_utente(int id_utente) {
        this.id_utente = id_utente;
    }

    public String getEmail() {
        return this.email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getStato() {
        return this.stato;
    }

    public void setStato(String stato) {
        this.stato = stato;
    }

    public Date getUltimo_accesso() {
        return this.ultimo_accesso;
    }

    public void setUltimo_accesso(Date ultimo_accesso) {
        this.ultimo_accesso = ultimo_accesso;
    }
}
