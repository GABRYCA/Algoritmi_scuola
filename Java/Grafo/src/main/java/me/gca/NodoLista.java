package me.gca;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class NodoLista implements Serializable {

    // Variabili
    private String nome;
    private int difficolta;
    private int altitudine;
    private List<Arco> adiacenze = new ArrayList<>();

    /**
     * Costruttore.
     */
    public NodoLista() {
    }

    /**
     * Costruttore.
     *
     * @param nome
     * @param difficolta
     */
    public NodoLista(String nome, int difficolta) {
        this.nome = nome;
        this.difficolta = difficolta;
    }

    /**
     * Costruttore.
     *
     * @param nome
     * @param difficolta
     * @param altitudine
     */
    public NodoLista(String nome, int difficolta, int altitudine) {
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
     * Ritorna la difficolta' del nodo.
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
     * Setta il nome del nodo.
     *
     * @param nome
     */
    public void setNome(String nome) {
        this.nome = nome;
    }

    /**
     * Setta la difficolta' del nodo.
     *
     * @param difficolta
     */
    public void setDifficolta(int difficolta) {
        this.difficolta = difficolta;
    }

    /**
     * Setta l'altitudine del nodo.
     *
     * @param altitudine
     */
    public void setAltitudine(int altitudine) {
        this.altitudine = altitudine;
    }

    /**
     * Aggiungi adiacenza alla lista del nodo.
     *
     * @param nNodo
     * @return
     */
    public boolean addAdiacenza(int nNodo, int tempo) {

        if (contieneNodo(nNodo)) {
            return false;
        }

        adiacenze.add(new Arco(nNodo, tempo));
        return true;
    }

    public boolean contieneNodo(int nNodo) {
        boolean contiene = false;
        for (Arco i : adiacenze){
            if (i.getNodo() == nNodo){
                contiene = true;
                break;
            }
        }
        return contiene;
    }

    /**
     * Rimuovi adiacenza alla lista del nodo.
     *
     * @param nNodo
     * @return
     */
    public boolean removeAdiacenza(int nNodo) {
        boolean contiene = false;
        int pos = 0;
        for (Arco i : adiacenze){
            if (i.getNodo() == nNodo){
                contiene = true;
                break;
            }
            pos++;
        }

        if (!contiene){
            return false;
        }

        adiacenze.remove(pos);
        return true;
    }

    /**
     * Ritorna lista delle adiacenze.
     *
     * @return
     */
    public List<Arco> getAdiacenze() {
        return adiacenze;
    }

    /**
     * Setta adiacenze da lista.
     *
     * @param adiacenze
     */
    public void setAdiacenze(List<Arco> adiacenze) {
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
