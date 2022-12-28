package eu.anonymousgca.studente;

import java.util.ArrayList;

public class Studente {

    private String nome;
    private String cognome;
    private String password;
    private ArrayList<String> messaggi;
    private String dataNascita;
    private String indirizzo;
    private String fotoProfilo;

    public Studente(String nome, String cognome, String password, ArrayList<String> messaggi, String dataNascita, String indirizzo, String fotoProfilo) {
        this.nome = nome;
        this.cognome = cognome;
        this.password = password;
        this.messaggi = messaggi;
        this.dataNascita = dataNascita;
        this.indirizzo = indirizzo;
        this.fotoProfilo = fotoProfilo;
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

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public ArrayList<String> getMessaggi() {
        return messaggi;
    }

    public void setMessaggi(ArrayList<String> messaggi) {
        this.messaggi = messaggi;
    }

    public String getDataNascita() {
        return dataNascita;
    }

    public void setDataNascita(String dataNascita) {
        this.dataNascita = dataNascita;
    }

    public String getIndirizzo() {
        return indirizzo;
    }

    public void setIndirizzo(String indirizzo) {
        this.indirizzo = indirizzo;
    }

    public String getFotoProfilo() {
        return fotoProfilo;
    }

    public void setFotoProfilo(String fotoProfilo) {
        this.fotoProfilo = fotoProfilo;
    }

    public void aggiungiMessaggio(String messaggio) {
        messaggi.add(messaggio);
    }

    public void rimuoviMessaggio(String messaggio) {
        messaggi.remove(messaggio);
    }

    public void modificaMessaggio(String messaggio, String nuovoMessaggio) {
        messaggi.set(messaggi.indexOf(messaggio), nuovoMessaggio);
    }
}
