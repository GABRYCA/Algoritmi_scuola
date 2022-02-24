package me.gca;

import java.io.Serializable;

public class Nodo implements Serializable {

    private String nome;
    private int difficolta;
    private int altitudine;

    public Nodo() {
    }

    public Nodo(String nome, int difficolta) {
        this.nome = nome;
        this.difficolta = difficolta;
    }

    public Nodo(String nome, int difficolta, int altitudine) {
        this.nome = nome;
        this.difficolta = difficolta;
        this.altitudine = altitudine;
    }

    public String getNome() {
        return nome;
    }

    public int getDifficolta() {
        return difficolta;
    }

    public int getAltitudine() {
        return altitudine;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setDifficolta(int difficolta) {
        this.difficolta = difficolta;
    }

    public void setAltitudine(int altitudine) {
        this.altitudine = altitudine;
    }

    @Override
    public String toString() {
        return "Nodo{" +
                "nome='" + nome + '\'' +
                ", difficolta=" + difficolta +
                ", altitudine=" + altitudine +
                '}';
    }
}