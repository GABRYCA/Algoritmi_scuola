package me.gca;

import java.io.Serializable;

public class Nodo implements Serializable {

    String nome;
    int difficolta;

    public Nodo(){}

    public Nodo(String nome, int difficolta){
        this.nome = nome;
        this.difficolta = difficolta;
    }

    public String getNome() {
        return nome;
    }

    public int getDifficolta() {
        return difficolta;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setDifficolta(int difficolta) {
        this.difficolta = difficolta;
    }

    @Override
    public String toString() {
        return "Nodo{" +
                "nome='" + nome + '\'' +
                ", difficolta=" + difficolta +
                '}';
    }
}
