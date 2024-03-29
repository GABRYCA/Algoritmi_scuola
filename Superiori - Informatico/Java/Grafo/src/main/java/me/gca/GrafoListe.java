package me.gca;

import com.fasterxml.jackson.annotation.JsonFilter;
import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonProperty;

import java.io.Serializable;
import java.util.*;

public class GrafoListe implements Serializable {

    private List<NodoLista> nodi = new ArrayList<>();

    /**
     * Ritorno lista dei nodi se richiesta.
     *
     * @return
     */
    public List<NodoLista> getNodi() {
        return nodi;
    }

    /**
     * Setto i nodi da una lista precedente.
     *
     * @param nodi
     */
    public void setNodi(List<NodoLista> nodi) {
        this.nodi = nodi;
    }

    /**
     * Aggiungo un nodo.
     *
     * @param nodo
     * @return
     */
    public boolean addNodo(NodoLista nodo) {
        nodi.add(nodo);
        return true;
    }

    /**
     * Rimuovo un nodo.
     *
     * @param nodo
     * @return
     */
    public boolean removeNodo(NodoLista nodo) {
        // Verifico se presente.
        if (!nodi.contains(nodo)) {
            return false;
        }

        // Rimuovo.
        nodi.remove(nodo);
        return true;
    }

    /**
     * Rimuovo un nodo in base al numero.
     *
     * @param nNodo
     * @return
     */
    public boolean removeNodo(int nNodo) {
        // Verifico se alla posizione data sia presente un nodo.
        if (getNodoPos(nNodo) == null) {
            return false;
        }

        for (NodoLista nodo : nodi){
            if (nodo.contieneNodo(nNodo)){
                nodo.removeAdiacenza(nNodo);
            }
        }

        // Rimuovo il nodo.
        nodi.remove(getNodoPos(nNodo));
        return true;
    }

    /**
     * Aggiungi arco tra due nodi.
     *
     * @param nNodoA
     * @param nNodoB
     * @return
     */
    public boolean addArco(int nNodoA, int nNodoB, int tempo) {
        // Non si puo' creare arco tra nodi che non esistono.
        if (nodi.size() < nNodoA || nodi.size() < nNodoB) {
            return false;
        }

        // Aggiungo l'arco se la pozione e' valida.
        NodoLista nodoA;
        try {
            nodoA = nodi.get(nNodoA);
        } catch (ArrayIndexOutOfBoundsException ignored) {
            return false;
        }
        return nodoA.addAdiacenza(nNodoB, tempo);
    }

    /**
     * Rimuovo arco tra due nodi.
     *
     * @param nNodoA
     * @param nNodoB
     * @return
     */
    public boolean removeArco(int nNodoA, int nNodoB) {
        // Non si puo' creare arco tra nodi che non esistono.
        if (nodi.size() < nNodoA || nodi.size() < nNodoB) {
            return false;
        }

        // Rimuovo arco dopo aver ottenuto il nodo.
        NodoLista nodoA = nodi.get(nNodoA);
        return nodoA.removeAdiacenza(nNodoB);
    }

    /**
     * Stampa i nodi.
     */
    public void stampaNodi() {
        int pos = 0;
        for (NodoLista nodo : nodi) {
            Util.printfn(pos + " -> " + nodo.stampaNodo());
            pos++;
        }
    }

    /**
     * Stampa le adiacenze.
     */
    public void stampaAdiacenze() {
        int pos = 0;
        for (NodoLista nodo : nodi) {
            Util.printf("" + pos + " " + nodo.stampaAdiacenzeNodo());
            pos++;
            Util.printf("\n");
        }
    }

    /**
     * Ritorno il nodo presente alla posizione data.
     *
     * @param pos
     * @return
     */
    public NodoLista getNodoPos(int pos) {
        if (pos > nodi.size()) {
            return null;
        }

        return nodi.get(pos);
    }

    /**
     * Verifico se due nodi sono adiacenti direttamente partendo dalla posizione.
     *
     * @param nodoA
     * @param nodoB
     * @return
     */
    public boolean adiacenti(int nodoA, int nodoB) {
        if (nodoA > nodi.size() || nodoB > nodi.size()) {
            return false;
        }

        return nodi.get(nodoA).contieneNodo(nodoB);
    }

    /**
     * Verifico se due nodi hanno un percorso possibile.
     *
     * @param nodoA
     * @param nodoB
     * @return
     */
    public boolean isAdiacenti(int nodoA, int nodoB) {
        if (nodoA > nodi.size() || nodoB > nodi.size()) {
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
            for (Arco i : nodi.get(x).getAdiacenze()) {
                if (!visitato[i.getNodo()]) {
                    visitato[i.getNodo()] = true;
                    daVisitare.add(i.getNodo());
                }
            }
        }

        return false;
    }

    /**
     * Ottengo il percorso tra due nodi se presente.
     *
     * @param nodoA
     * @param nodoB
     * @return
     */
    public Stack<Integer> percorso(int nodoA, int nodoB) {
        Stack<Integer> percorso = new Stack<>();
        percorso(nodoA, nodoB, new ArrayList<>(), percorso);
        return percorso;
    }

    /**
     * Percorso tra due nodi ricorsivo.
     *
     * @param nodoA
     * @param nodoB
     * @param visitato
     * @param percorso
     * @return
     */
    public boolean percorso(int nodoA, int nodoB, List<Integer> visitato, Stack<Integer> percorso) {
        visitato.add(nodoA);
        percorso.add(nodoA);

        // Trovato
        if (nodoA == nodoB) {
            return true;
        }

        // Per ogni nodo adiacente.
        for (Arco i : nodi.get(nodoA).getAdiacenze()) {
            if (!visitato.contains(i.getNodo())) {
                if (percorso(i.getNodo(), nodoB, visitato, percorso)) {
                    return true;
                }
            }
        }

        percorso.pop();

        // Ritorno false perche' nodo non raggiungibile.
        return false;
    }

    /**
     * Tempo tra due nodi.
     *
     * @param nodoA
     * @param nodoB
     * @return
     */
    public int percorsoTempo(int nodoA, int nodoB) {
        int[] tempo = new int[1];
        percorsoTempo(nodoA, nodoB, new ArrayList<>(), tempo);
        return tempo[0];
    }

    /**
     * Tempo tra due nodi.
     *
     * @param nodoA
     * @param nodoB
     * @param visitato
     * @param tempo
     * @return
     */
    public boolean percorsoTempo(int nodoA, int nodoB, List<Integer> visitato, int[] tempo) {
        visitato.add(nodoA);
        boolean contiene = false;
        int pos = 0;
        for (Arco i : nodi.get(nodoA).getAdiacenze()){
            if (i.getNodo() == nodoB){
                contiene = true;
                break;
            }
            pos++;
        }
        if (contiene){
            tempo[0] += nodi.get(nodoA).getAdiacenze().get(pos).getTempo();
        }


        // Trovato
        if (nodoA == nodoB) {
            return true;
        }

        // Per ogni nodo adiacente.
        for (Arco i : nodi.get(nodoA).getAdiacenze()) {
            if (!visitato.contains(i.getNodo())) {
                if (percorsoTempo(i.getNodo(), nodoB, visitato, tempo)) {
                    return true;
                }
            }
        }

        tempo[0] = 0;

        // Ritorno false perche' nodo non raggiungibile.
        return false;
    }

    /**
     * Visita per ampiezza.
     *
     * @param nodo
     */
    public void visitaBFS(int nodo) {

        // Inizialmente inizializza come falsi i visitati.
        boolean[] visitato = new boolean[nodi.size()];

        // Coda dei nodi da visitare.
        LinkedList<Integer> daVisitare = new LinkedList<>();

        // Il nodo iniziale viene visitato e aggiunto.
        visitato[nodo] = true;
        daVisitare.add(nodo);

        while (daVisitare.size() != 0) {

            // Elimino un nodo dalla coda e lo stampo.
            nodo = daVisitare.poll();
            NodoLista nodoConDati = getNodoPos(nodo);
            Util.printf("[" + nodoConDati.getNome() + "] ");

            // Visito i vertici adiacenti se non gia' visitati, e gli aggiungo alla coda.
            for (Arco i : nodi.get(nodo).getAdiacenze()) {
                if (!visitato[i.getNodo()]) {
                    visitato[i.getNodo()] = true;
                    daVisitare.add(i.getNodo());
                }
            }
        }
    }

    /**
     * Visita in profondita' DFS.
     *
     * @param nodo
     */
    public void visitaDFS(int nodo) {

        // Inizializzo vettore dei nodi visitati.
        boolean[] visitato = new boolean[nodi.size()];

        visitaDFS(nodo, visitato);
    }

    /**
     * Visita in profondita' DFS ricorsiva.
     *
     * @param nodo
     * @param visitato
     */
    public void visitaDFS(int nodo, boolean[] visitato) {
        visitato[nodo] = true;

        NodoLista nodoConDati = getNodoPos(nodo);
        Util.printf("[" + nodoConDati.getNome() + "] ");

        // Eseguo l'azione per tutti i nodi adiacenti.
        for (Arco i : nodi.get(nodo).getAdiacenze()) {
            if (!visitato[i.getNodo()]) {
                visitaDFS(i.getNodo(), visitato);
            }
        }
    }

    /**
     * Ritorna una lista dei nodi isolati.
     *
     * @return
     */
    public List<NodoLista> nodiIsolati(){
        List<NodoLista> nodiIsolati = new ArrayList<>(); // Lista nodi isolati.
        int[] contaArchiNodi = new int[nodi.size()]; // Vettore contatore.

        for (NodoLista nodo : nodi){ // Per ogni nodo.
            if (nodo != null){ // Verifico che non sia nullo per sicurezza.
                for (Arco adiacenza : nodo.getAdiacenze()){ // Per ogni adiacenza.
                    contaArchiNodi[adiacenza.getNodo()]++; // Incremento contatore archi per l'adiacenza.
                }
            }
        }

        for (int i = 0; i < contaArchiNodi.length; i++){ // Per ogni contatore degli archi.
            if (contaArchiNodi[i] == 0){ // Se e' 0.
                nodiIsolati.add(nodi.get(i)); // Aggiungo il nodo alla lista degli isolati.
            }
        }
        return nodiIsolati; // Ritorno la lista dei nodi isolati.
    }

    /**
     * Verifica se e' una foresta.
     *
     * @return
     */

    @JsonIgnore
    public boolean isForesta(){
        if (nodi.isEmpty()){ // Se non ci sono nodi non puo' essere niente, quindi ritorno falso.
            return false; // Non e' una foresta.
        }

        // Inizializzo vettore dei nodi visitati.
        boolean[] visitato = new boolean[nodi.size()];

        visitaDFS(0, visitato); // Eseguo visita DFS.

        for (boolean bool : visitato){ // Per ogni nodo visitato.
            if (!bool){ // Verifico se visitato sia falso.
                return true; // Non e' stato visitato, e' una foresta.
            }
        }

        return false; // Non e' una foresta.
    }

    @Override
    public String toString() {
        return "GrafoListe{" +
                "nodi=" + nodi +
                '}';
    }
}
