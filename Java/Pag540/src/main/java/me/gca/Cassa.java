package me.gca;

import java.util.LinkedList;
import java.util.Queue;

public class Cassa {

    private int maxLista = 100;
    private Queue<Integer> coda = new LinkedList<>();
    private int eta = 70;
    private boolean etaMinima = false;
    private boolean attiva = false;
    private String nome;

    public Cassa(String nome, int eta, boolean attiva, int maxPersone) {
        this.nome = nome;
        this.eta = eta;
        this.attiva = attiva;
        this.maxLista = maxPersone;
    }

    private void inizializza() {
        coda = new LinkedList<>();
    }

    public Cassa(String nome) {
        inizializza();
        this.nome = nome;
    }

    public Cassa(boolean etaMinima, String nome) {
        inizializza();
        this.etaMinima = etaMinima;
        this.nome = nome;
    }

    public boolean isEtaMinima() {
        return etaMinima;
    }

    public int getMaxLista() {
        return maxLista;
    }

    public Queue<Integer> getCoda() {
        return coda;
    }

    public void setEtaMinima(boolean etaMinima) {
        this.etaMinima = etaMinima;
    }

    public void setCoda(Queue<Integer> coda) {
        this.coda = coda;
    }

    public void setMaxLista(int maxLista) {
        this.maxLista = maxLista;
    }

    /**
     * Aggiunge una persona alla coda.
     *
     * @param persona
     */
    public void addElemento(int persona) {
        if (coda.size() >= maxLista) {
            Util.printfn("\nLa coda '" + nome + "' e' piena!");
            return;
        }
        coda.add(persona);
        Util.printfn("\nAggiunto utente di eta' " + persona + " alla coda '" + nome + "'.");
    }

    /**
     * Elimina persona dalla coda.
     *
     * @param persona
     */
    public void removeElemento(int persona) {
        coda.remove(persona);
    }

    public void removePrimoElemento() {
        if (numeroPersone() == 0) {
            Util.printfn("\nNon sono presenti persone in coda!");
            return;
        }
        int rimosso = coda.remove();
        Util.printfn("\nRimosso primo utente di eta' " + rimosso + " dalla coda '" + nome + "'.");
    }

    /**
     *
     * @return
     */
    public boolean isAttiva() {
        return attiva;
    }

    /**
     *
     * @param attiva
     */
    public void setAttiva(boolean attiva) {
        this.attiva = attiva;
    }

    /**
     *
     * @return
     */
    public int getEta() {
        return eta;
    }

    /**
     *
     * @param eta
     */
    public void setEta(int eta) {
        this.eta = eta;
    }

    /**
     *
     * @return
     */
    public int numeroPersone() {
        return coda.size();
    }

    /**
     *
     * @return
     */
    public String getNomeLista() {
        return nome;
    }

    /**
     *
     * @param nomeLista
     */
    public void setNomeCassa(String nomeLista) {
        this.nome = nomeLista;
    }

    /**
     *
     * @param posizione
     * @return
     */
    public int get(int posizione) {
        if (coda == null) {
            return -1;
        }

        int size = coda.size();
        if (posizione < 0 || size < posizione + 1) {
            return -1;
        }

        int element = -1;
        for (int i = 0; i < size; i++) {
            if (i == posizione) {
                element = coda.remove();
            } else {
                coda.add(coda.remove());
            }
        }

        return element;
    }

    /**
     *
     * @param posizione
     */
    public void remove(int posizione) {

        Queue<Integer> temp = new LinkedList<>();
        int dimensioni = coda.size();
        int contatore = 0;

        while (!coda.isEmpty() && coda.peek() != posizione) {
            temp.add(coda.peek());
            coda.remove();
            contatore++;
        }

        if (coda.isEmpty()) {
            System.out.print("element not found!!" + "\n");
            while (!temp.isEmpty()) {

                // Pushing all the elements back into q
                coda.add(temp.peek());
                temp.remove();
            }
        } else {
            coda.remove();
            while (!temp.isEmpty()) {
                coda.add(temp.peek());
                temp.remove();
            }
            int tempContatore = dimensioni - contatore - 1;
            while (tempContatore-- > 0) {
                int p = coda.peek();
                coda.remove();
                coda.add(p);
            }
        }
    }

    @Override
    public String toString() {
        return "Cassa{" +
                "maxLista=" + maxLista +
                ", coda=" + coda +
                ", eta=" + eta +
                ", etaMinima=" + etaMinima +
                ", attiva=" + attiva +
                ", nome='" + nome + '\'' +
                '}';
    }
}
