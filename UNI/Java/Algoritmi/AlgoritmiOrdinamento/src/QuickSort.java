public class QuickSort {
    private int numeroNumeri;
    private int[] numeri;

    public QuickSort(int numeroNumeri){
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
        System.out.println("QuickSort avviato...");
        quickSort(numeri, 0, numeri.length - 1);
        System.out.println("QuickSort completato!");
    }

    private void quickSort(int[] numeri, int inizio, int fine){
        if (inizio < fine){
            System.out.println("Inizio: " + inizio + " Fine: " + fine);
            int centroPartizione = partition(numeri, inizio, fine);
            quickSort(numeri, inizio, centroPartizione - 1);
            quickSort(numeri, centroPartizione + 1, fine);
        }
    }

    private int partition(int[] numeri, int inizio, int fine){
        int pivot = numeri[fine]; // prendo il pivot come ultimo elemento
        int i = inizio - 1; // indice del più piccolo elemento

        // Scorro tutti gli elementi e faccio lo swap con i numeri più piccoli
        for (int j = inizio; j < fine; j++){
            if (numeri[j] < pivot){
                i++;
                int numeroTmp = numeri[i];
                numeri[i] = numeri[j];
                numeri[j] = numeroTmp;
            }
        }

        // Scambio numeri[i + 1] e numeri[fine] (o il pivot)
        int numero = numeri[i + 1];
        numeri[i + 1] = numeri[fine];
        numeri[fine] = numero;

        return i + 1;
    }

    public void print(){
        System.out.println("Vettore dei numeri: ");
        for (int i = 0; i < numeri.length; i++){
            System.out.println((i + 1) + " -> " + numeri[i]);
        }
    }

}
