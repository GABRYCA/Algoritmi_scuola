package me.gca;

public class Bicchiere {

    private String materiale;
    private String forma;
    private float livello;
    private float capacita;

    public Bicchiere(){}

    public Bicchiere(String materiale, String forma, float livello, float capacita) {
        this.materiale = materiale;
        this.forma = forma;
        this.livello = livello;
        this.capacita = capacita;
    }

    public String getMateriale() {
        return materiale;
    }

    public String getForma() {
        return forma;
    }

    public float getLivello() {
        return livello;
    }

    public float getCapacita() {
        return capacita;
    }

    public void setMateriale(String materiale) {
        this.materiale = materiale;
    }

    public void setForma(String forma) {
        this.forma = forma;
    }

    public void setLivello(float livello) {
        this.livello = livello;
    }

    public void setCapacita(float capacita) {
        this.capacita = capacita;
    }

    public void riempi(){
        livello = capacita;
    }

    public void svuota(){
        livello = 0;
    }
}
