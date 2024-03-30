import java.util.Arrays;

public class SelectionSort {

    private int numeroNumeri;
    private int[] numeri;

    public SelectionSort(int numeroNumeri){
        this.numeroNumeri = numeroNumeri;
        numeri = new int[numeroNumeri];

        // Creo numeri casuali per riempire il vettore
        System.out.println("Creazione di " + numeroNumeri + " numeri casuali...");
        for (int i = 0; i < numeroNumeri; i++){
            numeri[i] = (int) (Math.random() * 1000);
        }
        System.out.println("Numeri generati con successo!");
    }

    public void sort(){
        System.out.println("SelectionSort avviato...");
        // Per ogni elemento
        for (int i = 0; i < numeri.length - 1; i++){
            int minPos = i;
            // Cerco il numero minore
            for (int j = i + 1; j < numeri.length; j++){
                if (numeri[minPos] > numeri[j]){
                    minPos = j;
                }
            }

            int nMin = numeri[minPos]; // Estraggo numero minore trovato
            numeri[minPos] = numeri[i]; // Sposto il numero nella posizione del ciclo in quella del numero trovato
            numeri[i] = nMin; // Completo lo scambio spostando il numero minore all'inizio del vettore ordinato
        }

        System.out.println("SelectionSort completato!");
    }

    public void print(){
        System.out.println("Vettore dei numeri: ");
        for (int i = 0; i < numeri.length; i++){
            System.out.println((i + 1) + " -> " + numeri[i]);
        }
    }
}
