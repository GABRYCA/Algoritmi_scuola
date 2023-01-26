package eu.anonymousgca.videoteca;

public class DVD {

    private String codice;
    private String titolo;
    private String descrizione = "Descrizione di base";
    private String statoNoleggio;
    private String nominativo;

    public DVD(String codice, String titolo){
        this.codice = codice;
        this.titolo = titolo;
        this.statoNoleggio = "Disponibile";
    }

    public void noleggia(){
        statoNoleggio = "Noleggiato";
    }

    public void restituisci(){
        statoNoleggio = "Disponibile";
    }

    public boolean isNoleggiato(){
        return statoNoleggio.equals("Noleggiato");
    }

    public String getStatoNoleggio(){
        return statoNoleggio;
    }

    public String getNominativo(){
        return nominativo;
    }

    public void setNominativo(String nominativo){
        this.nominativo = nominativo;
    }

    public String getCodice(){
        return codice;
    }

    public String getTitolo(){
        return titolo;
    }

    public String getDescrizione(){
        return descrizione;
    }

    public void setDescrizione(String descrizione) {
        this.descrizione = descrizione;
    }
}
