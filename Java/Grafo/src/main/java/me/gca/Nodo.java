package me.gca;

import java.io.Serializable;

public class Nodo implements Serializable {

    private String nome;
    private int difficolta;
    private int altitudine;

    /**
     * Costruttore
     */
    public Nodo() {
    }

    /**
     * Costruttore nodo.
     *
     * @param nome
     * @param difficolta
     */
    public Nodo(String nome, int difficolta) {
        this.nome = nome;
        this.difficolta = difficolta;
    }

    /**
     * Costruttore nodo.
     *
     * @param nome
     * @param difficolta
     * @param altitudine
     */
    public Nodo(String nome, int difficolta, int altitudine) {
        this.nome = nome;
        this.difficolta = difficolta;
        this.altitudine = altitudine;
    }

    /**
     * Ritorna il nome del nodo.
     *
     * @return
     */
    public String getNome() {
        return nome;
    }

    /**
     * Ritorna il numero della difficolta' del nodo.
     *
     * @return
     */
    public int getDifficolta() {
        return difficolta;
    }

    /**
     * Ritorna l'altitudine del nodo.
     *
     * @return
     */
    public int getAltitudine() {
        return altitudine;
    }

    /**
     * Setta il nome del nodo con quello specificato.
     *
     * @param nome
     */
    public void setNome(String nome) {
        this.nome = nome;
    }

    /**
     * Setta la difficolta' con quella specificata.
     *
     * @param difficolta
     */
    public void setDifficolta(int difficolta) {
        this.difficolta = difficolta;
    }

    /**
     * Setta l'altitudine con quella specificata.
     *
     * @param altitudine
     */
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