package me.gca;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class NodoLista implements Serializable {

    private String nome;
    private int difficolta;
    private int altitudine;
    private List<Integer> adiacenze = new ArrayList<>();

    public NodoLista() {
    }

    public NodoLista(String nome, int difficolta) {
        this.nome = nome;
        this.difficolta = difficolta;
    }

    public NodoLista(String nome, int difficolta, int altitudine) {
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

    public boolean addAdiacenza(int nNodo) {
        if (adiacenze.contains(nNodo)) {
            return false;
        }

        adiacenze.add(nNodo);
        return true;
    }

    public boolean removeAdiacenza(int nNodo) {
        if (!adiacenze.contains(nNodo)) {
            return false;
        }

        adiacenze.remove(nNodo);
        return true;
    }

    public List<Integer> getAdiacenze() {
        return adiacenze;
    }

    public void setAdiacenze(List<Integer> adiacenze) {
        this.adiacenze = adiacenze;
    }

    public String stampaNodo() {
        return "NodoLista{" +
                "nome='" + nome + '\'' +
                ", difficolta=" + difficolta +
                ", altitudine=" + altitudine +
                '}';
    }

    public String stampaAdiacenzeNodo() {
        return String.valueOf(adiacenze);
    }

    @Override
    public String toString() {
        return "NodoLista{" +
                "nome='" + nome + '\'' +
                ", difficolta=" + difficolta +
                ", altitudine=" + altitudine +
                ", adiacenze=" + adiacenze +
                '}';
    }
}
