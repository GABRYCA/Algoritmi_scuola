package me.simo;

public class Bicchiere
{
    private String forma;
    private String materiale;
    private float capacita;
    private float livello;

    public Bicchiere(){}
    public Bicchiere(String forma, String materiale, float capacita, float livello){}
    //public ~Bicchiere(){}
    public void setLivello(float livello) {
        this.livello = livello;
    }
    public void setForma(String forma) {
        this.forma = forma;
    }
    public void setCapacita(float capacita) {
        this.capacita = capacita;
    }
    public void setMateriale(String materiale) {
        this.materiale = materiale;
    }
    public float getCapacita() {
        return capacita;
    }
    public float getLivello() {
        return livello;
    }
    public String getForma() {
        return forma;
    }
    public String getMateriale() {
        return materiale;
    }
    public void riempi(){
        livello=capacita;
    }
    public void svuota(){
        livello=0;
    }
}
