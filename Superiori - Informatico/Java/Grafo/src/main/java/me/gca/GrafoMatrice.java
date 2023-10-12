package me.gca;

import com.fasterxml.jackson.annotation.JsonIgnore;

import java.io.Serializable;
import java.util.*;

public class GrafoMatrice implements Serializable {

    private List<Nodo> nodi = new ArrayList<>();
    private int[][] adiacenze = new int[0][0];

    public GrafoMatrice() {
    }

    /**
     * Aggiungi un nodo al grafo.
     *
     * @param nodo
     */
    public void addNodo(Nodo nodo) {
        // Ottengo dati necessari (come la precedente dimensione) e creo una matrice temporanea, poi aggiungo il nodo alla lista dei nodi.
        int vecchiaDimensione = adiacenze.length;
        int[][] tempAdiacenze = new int[vecchiaDimensione + 1][vecchiaDimensione + 1];
        nodi.add(nodo);

        // Ciclo nella matrice per aggiungere una riga e una colonna vuoti per il nuovo nodo.
        for (int i = 0; i <= vecchiaDimensione; i++) {
            for (int j = 0; j <= vecchiaDimensione; j++) {
                if (i < vecchiaDimensione && j < vecchiaDimensione) {
                    tempAdiacenze[i][j] = adiacenze[i][j];
                } else {
                    tempAdiacenze[i][j] = 0;
                }
            }
        }

        // Imposto la matrice delle adiacenze a quella temporanea.
        adiacenze = tempAdiacenze;
    }

    /**
     * Aggiungi un arco, se non presente ritorna vero, se gia' presente ritorna falso.
     *
     * @param nodo
     * @param nodo2
     * @return
     */
    public boolean addArco(Nodo nodo, Nodo nodo2) {
        int pos1 = 0;
        int pos2 = 0;

        // Posizione del primo nodo.
        for (Nodo nodoLetto : nodi) {
            if (nodoLetto == nodo) {
                break;
            } else {
                pos1++;
            }
        }

        // Posizione del secondo nodo.
        for (Nodo nodoLetto : nodi) {
            if (nodoLetto == nodo2) {
                break;
            } else {
                pos2++;
            }
        }

        // Se una adiacenza e' gia' disponibile, non cambiarla.
        if (adiacenze[pos1][pos2] == 1) {
            return false;
        }

        // Imposta adiacenza a 1.
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
    public boolean addArco(Nodo nodo, Nodo nodo2, int peso) {
        int pos1 = 0;
        int pos2 = 0;

        // Posizione del primo nodo.
        for (Nodo nodoLetto : nodi) {
            if (nodoLetto == nodo) {
                break;
            } else {
                pos1++;
            }
        }

        // Posizione del secondo nodo.
        for (Nodo nodoLetto : nodi) {
            if (nodoLetto == nodo2) {
                break;
            } else {
                pos2++;
            }
        }

        // Imposto il peso dell'adiacenza.
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
    public boolean addArco(int nodoA, int nodoB, int peso) {
        try {
            adiacenze[nodoA][nodoB] = peso;
        } catch (ArrayIndexOutOfBoundsException ignored) {
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
    public boolean rimuoviArco(Nodo nodo, Nodo nodo2) {
        int pos1 = 0;
        int pos2 = 0;

        // Ciclo per trovare la posizione del nodo 1.
        for (Nodo nodoLetto : nodi) {
            if (nodoLetto == nodo) {
                break;
            } else {
                pos1++;
            }
        }

        // Ciclo per trovare la posizione del nodo 2.
        for (Nodo nodoLetto : nodi) {
            if (nodoLetto == nodo2) {
                break;
            } else {
                pos2++;
            }
        }
        if (adiacenze[pos1][pos2] == 0) { // Se nessuna adiacenza e' disponibile.
            return false;
        }

        // Imposto l'adiacenza a nulla perche' rimuovo l'arco.
        adiacenze[pos1][pos2] = 0;
        return true;
    }

    /**
     * Stampa i nodi.
     */
    public void stampaNodi() {
        int pos = 0;
        for (Nodo nodo : nodi) {
            Util.printfn(pos + " -> " + nodo);
            pos++;
        }
    }

    /**
     * Stampa le adiacenze.
     */
    public void stampaAdiacenze() {
        Util.printf("\n");
        for (int i = 0; i < adiacenze.length; i++){
            Util.printf("\t" + i);
        }
        Util.printf("\n");
        for (int i = 0; i < adiacenze.length; i++){
            Util.printf("\t_");
        }
        for (int i = 0; i < adiacenze.length; i++) {
            Util.printfn("\n");
            Util.printf(i + " |\t");
            for (int j = 0; j < adiacenze.length; j++) {
                Util.printf(adiacenze[i][j] + "\t");
            }
        }
    }

    /**
     * @param posNodo
     * @return
     */
    public boolean isPosValida(int posNodo) {
        return posNodo >= 0 && posNodo < nodi.size();
    }

    /**
     * Ottengo la posizione del nodo, ma ritorna nullo se non valida.
     *
     * @param posNodo
     * @return
     */
    public Nodo getNodoPos(int posNodo) {
        if (!isPosValida(posNodo)) {
            return null;
        }
        return nodi.get(posNodo);
    }

    /**
     * @return
     */
    public int[][] getAdiacenze() {
        return adiacenze;
    }

    /**
     * @return
     */
    public List<Nodo> getNodi() {
        return nodi;
    }

    /**
     * @param adiacenze
     */
    public void setAdiacenze(int[][] adiacenze) {
        this.adiacenze = adiacenze;
    }

    /**
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
    public int numeroNodi() {
        return nodi.size();
    }

    public int getPesoPos(int nodoA, int nodoB) {
        return adiacenze[nodoA][nodoB];
    }

    /**
     * Ritorna true se due nodi hanno un possibile percorso.
     *
     * @param nodoA
     * @param nodoB
     * @return
     */
    public boolean isAdiacente(int nodoA, int nodoB) {
        // Lista vuota dei nodi visitati inizializzata, e inizio verifica tra i nodi.
        List<Integer> visitati = new ArrayList<>();
        return isAdiacente(nodoA, nodoB, visitati);
    }

    public boolean isAdiacente(int nodoA, int nodoB, List<Integer> visitati) {
        try {
            // Se il valore dell'adiacenza e' diverso da zero, ho trovato il nodo di destinazione.
            if (adiacenze[nodoA][nodoB] != 0) return true;
            // Se gia' presente tra i nodi visitati, ritorna falso per non ripetere cicli ricorsivi nei sottonodi.
            if (visitati.contains(nodoA)) {
                return false;
            } else {
                // Aggiungo il nodo alla lista dei visitati.
                visitati.add(nodoA);
            }
            // Per ogni nodo adiacente (nella riga sono quelli diversi da 0).
            for (int i = 0; i < adiacenze.length; i++) {
                // Se diverso da 0 quindi adiacente.
                if (adiacenze[nodoA][i] != 0 /*&& !visitati.contains(nodoA)*/) {
                    // visitati.add(nodoA);
                    // Richiamo in modo ricorsivo.
                    return isAdiacente(i, nodoB, visitati);
                }
            }
            return false;
        } catch (ArrayIndexOutOfBoundsException ignored) { // In caso di posizioni non valide, ritorno falso perche' il percorso non risulta possibile.
            return false;
        }
    }

    /**
     * Stesso funzionamento del isAdiacente, solamente che salva in un vettore il percorso svolto per raggiungere il nodo
     * di destinazione.
     *
     * @param nodoA
     * @param nodoB
     * @return
     */
    public List<Integer> percorso(int nodoA, int nodoB) {
        List<Integer> percorso = new ArrayList<>();
        return percorso(nodoA, nodoB, percorso);
    }

    public List<Integer> percorso(int nodoA, int nodoB, List<Integer> percorso) {
        try {
            if (adiacenze[nodoA][nodoB] != 0) {
                percorso.add(nodoA);
                return percorso;
            }
            if (percorso.contains(nodoA)) {
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
        } catch (ArrayIndexOutOfBoundsException ignored) {
            return percorso;
        }
    }

    /**
     * Simile al percorso ma ne ritorna solamente il tempo da A a B.
     *
     * @param nodoA
     * @param nodoB
     * @return
     */
    public int percorsoTempo(int nodoA, int nodoB) {
        return percorsoTempo(nodoA, nodoB, new ArrayList<>(), 0);
    }

    public int percorsoTempo(int nodoA, int nodoB, List<Integer> percorso, int tempo) {
        try {
            if (adiacenze[nodoA][nodoB] != 0) {
                percorso.add(nodoA);
                tempo += adiacenze[nodoA][nodoB];
                return tempo;
            }
            if (percorso.contains(nodoA)) {
                return tempo;
            } else {
                percorso.add(nodoA);
                tempo += adiacenze[nodoA][nodoB];
            }
            for (int i = 0; i < adiacenze.length; i++) {
                if (adiacenze[nodoA][i] != 0 /*&& !percorso.contains(nodoA)*/) {
                    //percorso.add(nodoA);
                    return percorsoTempo(i, nodoB, percorso, tempo);
                }
            }
            return tempo;
        } catch (ArrayIndexOutOfBoundsException ignored) {
            return tempo;
        }
    }

    /**
     * Rimuovo il nodo copiando la vecchia matrice senza la riga e la colonna del nodo da rimuovere, e rimuovo il nodo
     * dalla lista dei nodi.
     *
     * @param nNodo
     * @return
     */
    public boolean rimuoviNodo(int nNodo) {

        // Se posizione oltre il limite, ritorno falso ossia errore/non successo.
        if (nNodo >= adiacenze.length) {
            return false;
        }

        // Vettore temporaneo piu' piccolo.
        int[][] tempVettore = new int[adiacenze.length - 1][adiacenze.length - 1];

        // Ciclo nella matrice per copiare i valori tranne quelli da rimuovere.
        int conta = 0;
        for (int i = 0; i < adiacenze.length; i++) {
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

        // Setto la matrice con quella temporanea e rimuovo il vettore dalla lista dei nodi.
        adiacenze = tempVettore;
        nodi.remove(nNodo);
        return true;
    }

    /**
     * BFS -> Breadth First Search
     */
    public void visitaBFS(int inizio) {

        // Inizializzo vettore delle celle visitate e la LinkedList dei valori da visitare.
        boolean[] visitato = new boolean[adiacenze.length];
        LinkedList<Integer> daVisitare = new LinkedList<>();
        visitato[inizio] = true;
        daVisitare.add(inizio);

        // Ripeto il ciclo fino a quando la lista dei valori da visitare e' vuota.
        while (daVisitare.size() != 0) {
            // Prendo il valore letto e lo rimuovo dalla lista, cosi' lo stampo.
            int x = daVisitare.remove();
            Nodo nodo = getNodoPos(x);
            Util.printf("[" + nodo.getNome() + "] ");
            // Util.printf(x + " ");
            // Ripeto l'operazione per tutti gli adiacenti.
            for (int i = 0; i < adiacenze[0].length; i++) { // Avevo messo i = 1 inizialmente e un for che si ripeteva per una grandezza errata.
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
    public void visitaDFS(int inizio) {
        boolean[] visitato = new boolean[adiacenze.length];
        visitaDFS(inizio, visitato);
    }

    /**
     * DFS -> Depth First Search
     *
     * @param inizio
     * @param visitato
     */
    private void visitaDFS(int inizio, boolean[] visitato) {

        // Stampo il valore visitato.
        Nodo nodo = getNodoPos(inizio);
        Util.printf("[" + nodo.getNome() + "] ");
        visitato[inizio] = true;

        // Leggo in profondita' i valori.
        for (int i = 0; i < adiacenze[inizio].length; i++) {
            // Ripeto l'operazione per i sottonodi se non gia' visitato.
            if (adiacenze[inizio][i] != 0 && !visitato[i]) {
                visitaDFS(i, visitato);
            }
        }
    }

    /**
     * Ritorna una lista dei nodi isolati.
     *
     * @return
     */
    public List<Nodo> nodiIsolati(){
        List<Nodo> nodiIsolati = new ArrayList<>(); // Lista nodi isolati.
        int[] contaArchiNodi = new int[nodi.size()]; // Vettore contatore.

        for (int i = 0; i < nodi.size(); i ++) { // Per ogni nodo, creo vettore di int per prossimo for.
            for (int j = 0; j < adiacenze[i].length; j++) { // Per ogni adiacenza.
                if (adiacenze[i][j] != 0) {
                    contaArchiNodi[j]++; // Incremento contatore archi per l'adiacenza.
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
        return "GrafoMatrice{" +
                "nodi=" + nodi +
                ", adiacenze=" + Arrays.toString(adiacenze) +
                '}';
    }
}