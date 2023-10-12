package eu.anonymousgca.formativa;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class MovimentiUtenteBean {

    int id_utente;
    ArrayList<MovimentoBean> movimenti;

    public MovimentiUtenteBean() {
        id_utente = -1;
        movimenti = new ArrayList<MovimentoBean>();
    }

    public boolean selectMovimenti() {
        DBConnection con = new DBConnection();
        String query = "SELECT * FROM movimenti WHERE id_utente=" + id_utente + ";";
        ResultSet rs = con.eseguiSelect(query);

        try {
            while (rs.next()) {
                MovimentoBean movimento = new MovimentoBean();
                movimento.setId(rs.getInt("id"));
                movimento.setDescrizione(rs.getString("descrizione"));
                movimento.setEuro(rs.getInt("euro"));
                movimento.setId_utente(rs.getInt("id_utente"));
                movimenti.add(movimento);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    public void setId_utente(int id_utente) {
        this.id_utente = id_utente;
    }

    public int getId_utente() {
        return id_utente;
    }

    public void setMovimenti(ArrayList<MovimentoBean> movimenti) {
        this.movimenti = movimenti;
    }

    public ArrayList<MovimentoBean> getMovimenti() {
        return movimenti;
    }

    public int size() {
        return movimenti.size();
    }
}
