package me.gca;

public class Arco {

    private int nodo;
    private int tempo;

    /**
     * Costruttore arco vuoto.
     */
    public Arco(){}

    /**
     * Costruttore arco con nodo e tempo.
     *
     * @param nodo
     * @param tempo
     */
    public Arco(int nodo, int tempo){
        this.nodo = nodo;
        this.tempo = tempo;
    }

    public int getNodo() {
        return nodo;
    }

    public void setNodo(int nodo) {
        this.nodo = nodo;
    }

    public int getTempo() {
        return tempo;
    }

    public void setTempo(int tempo) {
        this.tempo = tempo;
    }

    @Override
    public String toString() {
        return "Arco{" +
                "nodo=" + nodo +
                ", tempo=" + tempo +
                '}';
    }
}
