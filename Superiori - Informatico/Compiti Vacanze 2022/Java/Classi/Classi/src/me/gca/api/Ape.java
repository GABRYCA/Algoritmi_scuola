package me.gca.api;

public class Ape extends Insetto {

    public String ruolo;

    public Ape(){

    }

    public String getRuolo() {
        return ruolo;
    }

    public void setRuolo(String ruolo) {
        this.ruolo = ruolo;
    }

    @Override
    public String toString() {
        return "Ape{" +
                "ruolo='" + ruolo + '\'' +
                '}';
    }
}
