package me.gca;

import java.io.Serializable;
import java.util.*;

public class GrafoMatrice implements Serializable {

    private List<Nodo> nodi = new ArrayList<>();
    private int[][] adiacenze = new int[0][0];

    public GrafoMatrice(){}

    public void addNodo(Nodo nodo){
        int vecchiaDimensione = adiacenze.length;
        int[][] tempAdiacenze = new int[vecchiaDimensione+1][vecchiaDimensione+1];
        nodi.add(nodo);

        for (int i = 0; i <= vecchiaDimensione; i++){
            for (int j = 0; j <= vecchiaDimensione; j++) {
                if (i < vecchiaDimensione && j < vecchiaDimensione) {
                    tempAdiacenze[i][j] = adiacenze[i][j];
                } else {
                    tempAdiacenze[i][j] = 0;
                }
            }
        }

        adiacenze = tempAdiacenze;
    }

    /**
     * Aggiungi un arco, se non presente ritorna vero, se gia' presente ritorna falso.
     *
     * @param nodo
     * @param nodo2
     * @return
     */
    public boolean addArco(Nodo nodo, Nodo nodo2){
        int pos1 = 0;
        int pos2 = 0;
        for (Nodo nodoLetto : nodi){
            if (nodoLetto == nodo){
                break;
            } else {
                pos1++;
            }
        }

        for (Nodo nodoLetto : nodi){
            if (nodoLetto == nodo2){
                break;
            } else {
                pos2++;
            }
        }

        if (adiacenze[pos1][pos2] == 1){
            return false;
        }

        adiacenze[pos1][pos2] = 1;
        return true;
    }

    /**
     * Aggiungi arco tra due nodi.
     *
     * @param nodo
     * @param nodo2
     * @param peso
     * @return
     */
    public boolean addArco(Nodo nodo, Nodo nodo2, int peso){
        int pos1 = 0;
        int pos2 = 0;
        for (Nodo nodoLetto : nodi){
            if (nodoLetto == nodo){
                break;
            } else {
                pos1++;
            }
        }

        for (Nodo nodoLetto : nodi){
            if (nodoLetto == nodo2){
                break;
            } else {
                pos2++;
            }
        }

        adiacenze[pos1][pos2] = peso;
        return true;
    }

    /**
     * Aggiunge un arco alle posizioni specificate tra i nodi, ritorna false se posizione non valida.
     *
     * @param nodoA
     * @param nodoB
     * @param peso
     * @return
     */
    public boolean addArco(int nodoA, int nodoB, int peso){
        try {
            adiacenze[nodoA][nodoB] = peso;
        } catch (ArrayIndexOutOfBoundsException ignored){
            return false;
        }
        return true;
    }

    /**
     * Ritorna vero se rimosso con successo, false se non rimosso perche' gia' zero.
     *
     * @param nodo
     * @param nodo2
     * @return
     */
    public boolean rimuoviArco(Nodo nodo, Nodo nodo2){
        int pos1 = 0;
        int pos2 = 0;
        for (Nodo nodoLetto : nodi){
            if (nodoLetto == nodo){
                break;
            } else {
                pos1++;
            }
        }

        for (Nodo nodoLetto: nodi){
            if (nodoLetto == nodo2){
                break;
            } else {
                pos2++;
            }
        }
        if (adiacenze[pos1][pos2] == 0){
            return false;
        }

        adiacenze[pos1][pos2] = 0;
        return true;
    }

    public void stampaNodi(){
        int pos = 0;
        for (Nodo nodo : nodi){
            Util.printfn(pos + " -> " + nodo);
            pos++;
        }
    }

    public void stampaAdiacenze(){
        for (int i = 0; i < adiacenze.length; i++){
            Util.printfn("\n");
            for (int j = 0; j < adiacenze.length; j++){
                Util.printf(adiacenze[i][j] + "\t");
            }
        }
    }

    /**
     *
     * @param posNodo
     * @return
     */
    public boolean isPosValida(int posNodo){
        return posNodo >= 0 && posNodo < nodi.size();
    }

    /**
     *
     * @param posNodo
     * @return
     */
    public Nodo getNodoPos(int posNodo){
        if (!isPosValida(posNodo)){
            return null;
        }
        return nodi.get(posNodo);
    }

    /**
     *
     * @return
     */
    public int[][] getAdiacenze() {
        return adiacenze;
    }

    /**
     *
     * @return
     */
    public List<Nodo> getNodi() {
        return nodi;
    }

    /**
     *
     * @param adiacenze
     */
    public void setAdiacenze(int[][] adiacenze) {
        this.adiacenze = adiacenze;
    }

    /**
     *
     * @param nodi
     */
    public void setNodi(List<Nodo> nodi) {
        this.nodi = nodi;
    }


    /**
     * Ritorna il numero di nodi.
     *
     * @return
     */
    public int numeroNodi(){
        return nodi.size();
    }

    public int getPesoPos(int nodoA, int nodoB){
        return adiacenze[nodoA][nodoB];
    }

    public boolean isAdiacente(int nodoA, int nodoB){
        List<Integer> visitati = new ArrayList<>();
        return isAdiacente(nodoA, nodoB, visitati);
    }

    public boolean isAdiacente(int nodoA, int nodoB, List<Integer> visitati){
        try {
            if (adiacenze[nodoA][nodoB] != 0) return true;
            if (visitati.contains(nodoA)){
                return false;
            } else {
                visitati.add(nodoA);
            }
            for (int i = 0; i < adiacenze.length; i++) {
                if (adiacenze[nodoA][i] != 0 /*&& !visitati.contains(nodoA)*/) {
                    // visitati.add(nodoA);
                    return isAdiacente(i, nodoB, visitati);
                }
            }
            return false;
        } catch (ArrayIndexOutOfBoundsException ignored){
            return false;
        }
    }

    public List<Integer> percorso(int nodoA, int nodoB){
        List<Integer> percorso = new ArrayList<>();
        return percorso(nodoA, nodoB, percorso);
    }

    public List<Integer> percorso(int nodoA, int nodoB, List<Integer> percorso){
        try {
            if (adiacenze[nodoA][nodoB] != 0) {
                percorso.add(nodoA);
                return percorso;
            }
            if (percorso.contains(nodoA)){
                return percorso;
            } else {
                percorso.add(nodoA);
            }
            for (int i = 0; i < adiacenze.length; i++) {
                if (adiacenze[nodoA][i] != 0 /*&& !percorso.contains(nodoA)*/) {
                    //percorso.add(nodoA);
                    return percorso(i, nodoB, percorso);
                }
            }
            return percorso;
        } catch (ArrayIndexOutOfBoundsException ignored){
            return percorso;
        }
    }

    public boolean rimuoviNodo(int nNodo){

        if (nNodo >= adiacenze.length){
            return false;
        }

        int[][] tempVettore = new int[adiacenze.length - 1][adiacenze.length - 1];

        int conta = 0;
        for(int i = 0; i < adiacenze.length; i++) {
            if (i != nNodo) {
                int conta2 = 0;
                for (int j = 0; j < adiacenze.length; j++) {
                    if (j != nNodo) {

                        tempVettore[conta][conta2] = adiacenze[i][j];
                        conta2++;
                    }
                }
                conta++;
            }
        }

        adiacenze = tempVettore;
        return true;
    }

    /**
     * BFS -> Breadth First Search
     */
    public void visitaBFS(int inizio){

        boolean[] visitato = new boolean[adiacenze.length];
        LinkedList<Integer> daVisitare = new LinkedList<>();
        visitato[inizio] = true;
        daVisitare.add(inizio);

        while(daVisitare.size() != 0) {
            int x = daVisitare.remove();
            Util.printf(x + " ");
            for (int i = 0; i < adiacenze.length; i++) { // Avevo messo i = 1 inizialmente.
                if (adiacenze[x][i] != 0 && !visitato[i]) {
                    daVisitare.add(i);
                    visitato[i] = true;
                }
            }
        }
    }

    /**
     * DFS -> Depth First Search
     *
     * @param inizio
     */
    public void visitaDFS(int inizio){
        boolean[] visitato = new boolean[adiacenze.length];
        visitaDFS(inizio, visitato);
    }

    /**
     * DFS -> Depth First Search
     *
     * @param inizio
     * @param visitato
     */
    private void visitaDFS(int inizio, boolean[] visitato){

        Util.printf(inizio + " ");
        visitato[inizio] = true;

        for (int i = 0; i < adiacenze[inizio].length; i++) {
            if (adiacenze[inizio][i] != 0 && (!visitato[i])) {
                visitaDFS(i, visitato);
            }
        }
    }

    @Override
    public String toString() {
        return "GrafoMatrice{" +
                "nodi=" + nodi +
                ", adiacenze=" + Arrays.toString(adiacenze) +
                '}';
    }
}