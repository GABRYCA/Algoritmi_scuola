package eu.anonymousgca.databeans;

public class ValutazioneTPSBean {

    private int idValutazioniTPS;
    private String descrizione;
    private String data;
    private int voto;
    private int utente_idUtente;

    public ValutazioneTPSBean() {
        idValutazioniTPS = -1;
        descrizione = "";
        data = null;
        voto = -1;
        utente_idUtente = -1;
    }

    public int getIdValutazioniTPS() {
        return idValutazioniTPS;
    }

    public void setIdValutazioniTPS(int idValutazioniTPS) {
        this.idValutazioniTPS = idValutazioniTPS;
    }

    public String getDescrizione() {
        return descrizione;
    }

    public void setDescrizione(String descrizione) {
        this.descrizione = descrizione;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public int getVoto() {
        return voto;
    }

    public void setVoto(int voto) {
        this.voto = voto;
    }

    public int getUtente_idUtente() {
        return utente_idUtente;
    }

    public void setUtente_idUtente(int utente_idUtente) {
        this.utente_idUtente = utente_idUtente;
    }
}
