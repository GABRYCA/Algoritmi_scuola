package eu.anonymousgca.pagina1;

public class Studente {

    /**
     * Oggetto studente con:
     * private String nome
     * private String cognome
     * private double media
     *
     * public getNome();
     * public getCognome();
     * public getMedia();
     * */

    private String nome;
    private String cognome;
    private double media;

    public Studente(String nome, String cognome, double media) {
        this.nome = nome;
        this.cognome = cognome;
        this.media = media;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public double getMedia() {
        return media;
    }

    /**
     * getInfo
     * */
    public String getInfo() {
        return "Il nome è: " + nome + ", il cognome è: " + cognome + " e la sua media è: " + media;
    }
}
