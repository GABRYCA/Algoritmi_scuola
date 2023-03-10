package eu.anonymousgca.formativa;

import java.sql.ResultSet;
import java.sql.SQLException;

public class UtenteBean {

    int id;
    String username;
    String password;
    String nome;
    String cognome;
    int num_conto;
    int saldo;

    public UtenteBean() {
        id = -1;
        username = "";
        password = "";
        nome = "";
        cognome = "";
        num_conto = -1;
        saldo = -1;
    }

    public boolean selectUtente() {
        DBConnection con = new DBConnection();
        String query = "SELECT * FROM utenti WHERE id=" + id + ";";
        ResultSet rs = con.eseguiSelect(query);

        try {
            while (rs.next()) {
                id = rs.getInt("id");
                username = rs.getString("username");
                password = rs.getString("password");
                nome = rs.getString("nome");
                cognome = rs.getString("cognome");
                num_conto = rs.getInt("num_conto");
                saldo = rs.getInt("saldo");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return true;
    }

    public boolean updateUtente(){
        DBConnection con = new DBConnection();
        String query = "UPDATE utenti SET username='" + username + "', password='" + password + "', nome='" + nome + "', cognome='" + cognome + "', num_conto=" + num_conto + ", saldo=" + saldo + " WHERE id=" + id + ";";
        return con.eseguiQuery(query);
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
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

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public int getNum_conto() {
        return num_conto;
    }

    public void setNum_conto(int num_conto) {
        this.num_conto = num_conto;
    }

    public int getSaldo() {
        return saldo;
    }

    public void setSaldo(int saldo) {
        this.saldo = saldo;
    }
}
