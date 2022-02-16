package me.gca;

import java.io.Serializable;
import java.util.*;

public class GrafoListeAdiacenza implements Serializable {

    private List<NodoLista> nodi = new ArrayList<>();

    public List<NodoLista> getNodi() {
        return nodi;
    }

    public void setNodi(List<NodoLista> nodi) {
        this.nodi = nodi;
    }

    public boolean addNodo(NodoLista nodo){
        nodi.add(nodo);
        return true;
    }

    public boolean removeNodo(NodoLista nodo){
        if (!nodi.contains(nodo)){
            return false;
        }

        nodi.remove(nodo);
        return true;
    }

    public boolean addArco(int nNodoA, int nNodoB){
        // Non si puo' creare arco tra nodi che non esistono.
        if (nodi.size() < nNodoA || nodi.size() < nNodoB){
            return false;
        }

        NodoLista nodoA;
        try {
            nodoA = nodi.get(nNodoA);
        } catch (ArrayIndexOutOfBoundsException ignored){
            return false;
        }
        return nodoA.addAdiacenza(nNodoB);
    }

    public boolean removeArco(int nNodoA, int nNodoB){
        // Non si puo' creare arco tra nodi che non esistono.
        if (nodi.size() < nNodoA || nodi.size() < nNodoB){
            return false;
        }

        NodoLista nodoA = nodi.get(nNodoA);
        return nodoA.removeAdiacenza(nNodoB);
    }

    /**
     * Stampa i nodi.
     */
    public void stampaNodi(){
        int pos = 0;
        for (NodoLista nodo : nodi){
            Util.printfn(pos + " -> " + nodo.stampaNodo());
            pos++;
        }
    }

    /**
     * Stampa le adiacenze.
     */
    public void stampaAdiacenze(){
        int pos = 0;
        for (NodoLista nodo : nodi){
            Util.printf("" + pos + " " + nodo.stampaAdiacenzeNodo());
            pos++;
            Util.printf("\n");
        }
    }

    public NodoLista getNodoPos(int pos){
        if (pos > nodi.size()){
            return null;
        }

        return nodi.get(pos);
    }

    public boolean adiacenti(int nodoA, int nodoB){
        if (nodoA > nodi.size() || nodoB > nodi.size()){
            return false;
        }

        return nodi.get(nodoA).getAdiacenze().contains(nodoB);
    }

    public boolean isAdiacenti(int nodoA, int nodoB){
        if (nodoA > nodi.size() || nodoB > nodi.size()){
            return false;
        }

        // Numero totale dei nodi.
        int n = nodi.size();

        // Inizializzo dati.
        boolean[] visitato = new boolean[n];
        Queue<Integer> daVisitare = new ArrayDeque<>();
        visitato[nodoA] = true;
        daVisitare.add(nodoA);

        // Continua fino a quando non ci sono nodi da visitare.
        while (!daVisitare.isEmpty()) {

            // Rimuovo il nodo da quelli da visitare.
            int x = daVisitare.poll();
            if (x == nodoB) {
                return true;
            }

            // Per ogni adiacenza verifica se visitata, nel caso non lo sia la aggiunge alla lista di quelle da visitare.
            // Il sistema e' simile a quello della visita in ampiezza.
            for (int i : nodi.get(x).getAdiacenze()) {
                if (!visitato[i]) {
                    visitato[i] = true;
                    daVisitare.add(i);
                }
            }
        }

        return false;
    }

    public Stack<Integer> percorso(int nodoA, int nodoB){
        Stack<Integer> percorso = new Stack<>();
        percorso(nodoA, nodoB, new ArrayList<>(), percorso);
        return percorso;
    }

    public boolean percorso(int nodoA, int nodoB, List<Integer> visitato, Stack<Integer> percorso) {
        visitato.add(nodoA);
        percorso.add(nodoA);

        // Trovato
        if (nodoA == nodoB) {
            return true;
        }

        for (int i : nodi.get(nodoA).getAdiacenze()) {
            if (!visitato.contains(i)) {
                if (percorso(i, nodoB, visitato, percorso)) {
                    return true;
                }
            }
        }

        percorso.pop();

        // Ritorno false perche' nodo non raggiungibile.
        return false;
    }

    @Override
    public String toString() {
        return "GrafoListeAdiacenza{" +
                "nodi=" + nodi +
                '}';
    }
}
