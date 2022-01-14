package me.gca;

public class AlberoHeap {

    private int[] heap;
    private int dimensione;
    private int max;

    /**
     * Costruttore per creare un Heap vuoto dalla sua dimensione massima.
     * */
    public AlberoHeap(int max) {
        this.max = max;
        this.dimensione = 0;
        heap = new int[this.max];
    }

    /**
     * Creo albero da vettore.
     * */
    public void daVettore(int[] vettore){

        int nuovaDimensione = vettore.length;
        if (max != nuovaDimensione) {
            max = vettore.length;
        }

        for (int i : vettore){
            insert(i);
        }
    }

    /**
     * Ottengo la posizione del padre dell'elemento specificato.
     * */
    private int padre(int pos) {
        return (pos - 1) / 2;
    }

    /**
     * Ritorno il figlio a sinistra.
     * */
    private int sinistraFiglio(int pos) {
        return (2 * pos);
    }

    /**
     * Ritorno il figlio a destra.
     * */
    private int destraFiglio(int pos) {
        return (2 * pos) + 1;
    }

    /**
     * Verifico se la posizione esiste ed e' una foglia valida.
     * */
    private boolean isFoglia(int pos) {
        return pos > (dimensione / 2) && pos <= dimensione;
    }

    /**
     * Scambio di valori in base alla posizione f (figlio) e superiore.
     * */
    private void scambio(int fpos, int spos) {
        int tmp;
        tmp = heap[fpos];
        heap[fpos] = heap[spos];
        heap[spos] = tmp;
    }

    /**
     * Heapify dell'albero.
     * */
    private void heapify(int pos) {
        Main.numeroAzioni++;
        if (isFoglia(pos)) {
            return;
        }

        if (heap[pos] < heap[sinistraFiglio(pos)] || heap[pos] < heap[destraFiglio(pos)]) {
            if (heap[sinistraFiglio(pos)] > heap[destraFiglio(pos)]) {
                scambio(pos, sinistraFiglio(pos));
                heapify(sinistraFiglio(pos));
            } else {
                scambio(pos, destraFiglio(pos));
                heapify(destraFiglio(pos));
            }
        }
    }

    /**
     * Inserisco elemento.
     * */
    public void insert(int val) {
        heap[dimensione] = val;

        // Verifica valore con padre e sposta fino a quando nella posizione corretta che rispetta l'heap.
        int pos = dimensione;
        while (heap[pos] > heap[padre(pos)]) {
            scambio(pos, padre(pos));
            pos = padre(pos);
        }
        dimensione++;
    }

    /**
     * Stampa Heap.
     * */
    public void stampa() {

        for(int i = 0; i< dimensione /2; i++){

            // Padre
            System.out.print("Padre : " + heap[i] );

            // Il figlio sinistro non deve essere oltre la dimensione massima.
            if(sinistraFiglio(i)< dimensione) {
                // Figlio di sinistra.
                System.out.print(" Figlio di sinistra: " + heap[sinistraFiglio(i)]);
            }

            // Il figlio destro non deve essere oltre la dimensione massima.
            if(destraFiglio(i)< dimensione) {
                // Figlio di destra.
                System.out.print(" Figlio di destra: " + heap[destraFiglio(i)]);
            }

            System.out.println();
        }

    }

    /**
     * Ritorna il massimo.
     * */
    public int maximum() {
        return heap[dimensione - 1];
    }

    /**
     * Rimuovi valore massimo.
     * */
    public void extractMax(){
        heap[1] = heap[dimensione - 1];
        dimensione--;
        heapify(1);
    }
}
