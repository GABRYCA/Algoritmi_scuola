package me.gca.biciclette;

public class Bicicletta extends MezziDiTrasporto{

    public String materiale;
    public int peso;

    public Bicicletta(String nome, String alimentazione, String materiale, int peso){
        super();
        this.nome = nome;
        this.alimentazione = alimentazione;
        this.materiale = materiale;
        this.peso = peso;
    }

    public String getMateriale() {
        return materiale;
    }

    public int getPeso() {
        return peso;
    }

    public void setMateriale(String materiale) {
        this.materiale = materiale;
    }

    public void setPeso(int peso) {
        this.peso = peso;
    }

    @Override
    public String toString() {
        return "Bicicletta{" +
                "materiale='" + materiale + '\'' +
                ", peso=" + peso +
                '}';
    }
}
