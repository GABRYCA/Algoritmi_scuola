public class HeapSort {

    int numeroNumeri;
    int[] numeri;

    public HeapSort(int numeroNumeri){
        this.numeroNumeri = numeroNumeri;
        this.numeri = new int[numeroNumeri];

        // Creo numeri casuali per riempire il vettore
        System.out.println("Creazione di " + numeroNumeri + " numeri casuali...");
        for (int i = 0; i < numeroNumeri; i++){
            numeri[i] = (int) (Math.random() * 1000);
        }
        System.out.println("Numeri generati con successo!");
    }

    public void sort(){
        System.out.println("HeapSort avviato...");
        heapSort(numeri);
        System.out.println("HeapSort completato!");
    }

    private void heapSort(int[] numeri){
        int n = numeri.length;

        // Costruisco l'heap
        for (int i = n / 2 - 1; i >= 0; i--){
            heapify(numeri, n, i);
        }

        // Estraggo gli elementi dall'heap
        for (int i = n - 1; i > 0; i--){
            // Scambio il primo elemento con l'ultimo
            int temp = numeri[0];
            numeri[0] = numeri[i];
            numeri[i] = temp;

            // Ricostruisco l'heap
            heapify(numeri, i, 0);
        }
    }

    private void heapify(int[] numeri, int n, int i){
        int largest = i; // Inizializzo il più grande come radice
        int left = 2 * i + 1; // Sinistra = 2 * i + 1
        int right = 2 * i + 2; // Destra = 2 * i + 2

        // Se il figlio sinistro è più grande della radice
        if (left < n && numeri[left] > numeri[largest]){
            largest = left;
        }

        // Se il figlio destro è più grande della radice
        if (right < n && numeri[right] > numeri[largest]){
            largest = right;
        }

        // Se il più grande non è la radice
        if (largest != i){
            int swap = numeri[i];
            numeri[i] = numeri[largest];
            numeri[largest] = swap;

            // Ricorsivamente heapify il sottoalbero interessato
            heapify(numeri, n, largest);
        }
    }

    public void print(){
        System.out.println("Vettore dei numeri: ");
        for (int i = 0; i < numeri.length; i++){
            System.out.println((i + 1) + " -> " + numeri[i]);
        }
    }
}
