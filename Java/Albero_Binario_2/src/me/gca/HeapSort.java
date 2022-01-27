package me.gca;

public class HeapSort {
    public void sort(int[] vettore) {
        int dimensione = vettore.length;

        // Heap.
        for (int i = dimensione / 2 - 1; i >= 0; i--) {
            heapify(vettore, dimensione, i);
        }

        // Ottieni dal vettore di "heap" i valori.
        for (int i = dimensione - 1; i > 0; i--) {
            // Scambio
            int temp = vettore[0];
            vettore[0] = vettore[i];
            vettore[i] = temp;

            heapify(vettore, i, 0);
        }
    }

    private void heapify(int[] vettore, int val, int dim) {
        Main.numeroAzioni++;
        int grande = dim;
        int sinistra = 2 * dim + 1;
        int destra = 2 * dim + 2;

        // Se il figlio a sinistra è maggiore del padre.
        if (sinistra < val && vettore[sinistra] > vettore[grande]) {
            grande = sinistra;
        }

        // Se il figlio a destra è il numero maggiore trovato (grande).
        if (destra < val && vettore[destra] > vettore[grande]) {
            grande = destra;
        }

        // Se grande non è il padre di tutti (radice).
        if (grande != dim) {
            // Scambia i valori.
            int temp = vettore[dim];
            vettore[dim] = vettore[grande];
            vettore[grande] = temp;

            // Esegui heapify ricorsivamente sotto-albero.
            heapify(vettore, val, grande);
        }
    }

    // Costruire un max heap da albero.
    public void buildHeap(int[] vettore, int val) {
        // Posizione ultimo nodo.
        int ultimo = (val / 2) - 1;

        // Ordine inverso.
        for (int i = ultimo; i >= 0; i--) {
            heapify(vettore, val, i);
        }
    }
}