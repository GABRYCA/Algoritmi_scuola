package eu.anonymousgca.databeans;

public class AnagraficaBean {

    private int idAnagrafica;
    private String nome;
    private String cognome;
    private String indirizzo;
    private int utente_idUtente;

    public AnagraficaBean() {
        idAnagrafica = -1;
        nome = "";
        cognome = "";
        indirizzo = "";
        utente_idUtente = -1;
    }

    public int getIdAnagrafica() {
        return idAnagrafica;
    }

    public void setIdAnagrafica(int idAnagrafica) {
        this.idAnagrafica = idAnagrafica;
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

    public String getIndirizzo() {
        return indirizzo;
    }

    public void setIndirizzo(String indirizzo) {
        this.indirizzo = indirizzo;
    }

    public int getUtente_idUtente() {
        return utente_idUtente;
    }

    public void setUtente_idUtente(int utente_idUtente) {
        this.utente_idUtente = utente_idUtente;
    }
}
