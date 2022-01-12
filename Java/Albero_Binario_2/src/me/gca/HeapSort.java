package me.gca;

public class HeapSort {
    public void sort(int[] vettore) {
        int n = vettore.length;

        // Crea heap per la prima volta.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(vettore, n, i);
        }

        // Ottieni dall'heap i valori
        for (int i = n - 1; i > 0; i--) {
            // Scambio
            int temp = vettore[0];
            vettore[0] = vettore[i];
            vettore[i] = temp;

            heapify(vettore, i, 0);
        }
    }

    void heapify(int[] vettore, int n, int i) {
        Main.numeroAzioni++;
        int grande = i;
        int sinistra = 2 * i + 1;
        int destra = 2 * i + 2;

        // Se il figlio a sinistra è maggiore del padre.
        if (sinistra < n && vettore[sinistra] > vettore[grande]) {
            grande = sinistra;
        }

        // Se il figlio a destra è il numero maggiore trovato (grande).
        if (destra < n && vettore[destra] > vettore[grande]) {
            grande = destra;
        }

        // Se grande non è il padre di tutti (radice).
        if (grande != i) {
            // Scambia i valori.
            int temp = vettore[i];
            vettore[i] = vettore[grande];
            vettore[grande] = temp;

            // Esegui heapify ricorsivamente sotto-albero.
            heapify(vettore, n, grande);
        }
    }
}
