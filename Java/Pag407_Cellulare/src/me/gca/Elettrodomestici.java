package me.gca;

public class Elettrodomestici {

    private String tipo;
    private String nome;
    private String marca;
    private double prezzo;

    public Elettrodomestici(){}

    public Elettrodomestici(String tipo, String nome, String marca, double prezzo){
        this.tipo = tipo;
        this.nome = nome;
        this.marca = marca;
        this.prezzo = prezzo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public void setPrezzo(double prezzo) {
        this.prezzo = prezzo;
    }

    public String getTipo() {
        return tipo;
    }

    public String getNome() {
        return nome;
    }

    public String getMarca() {
        return marca;
    }

    public double getPrezzo() {
        return prezzo;
    }
}
