package eu.anonymousgca.databeans;

public class UtenteBean {

    private int idUtente;
    private String username;
    private String password;
    /**
     * Prima di usare i get, impostare username e password (setUsername e setPassword).
     * */
    public UtenteBean() {
        idUtente = -1;
        username = "";
        password = "";
    }

    public UtenteBean(String username, String password) {
        this.username = username;
        this.password = password;
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
}
