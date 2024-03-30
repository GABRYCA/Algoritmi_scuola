import java.util.ArrayList;

public class BucketSort {

    private int numeroNumeri;
    private int numeroBuckets = 10;
    private int[] numeri;

    public BucketSort(int numeroNumeri){
        this.numeroNumeri = numeroNumeri;
        this.numeri = new int[numeroNumeri];

        // Creo numeri casuali per riempire il vettore
        System.out.println("Creazione di " + numeroNumeri + " numeri casuali...");
        for (int i = 0; i < numeroNumeri; i++){
            numeri[i] = (int) (Math.random() * 100); // NB: Decrementato da 1000 a 100 perchè dimostra meglio il funzionamento di questo algoritmo
        }
        System.out.println("Numeri generati con successo!");
    }

    public void sort(){
        // Bucketsort avviato
        System.out.println("BucketSort avviato...");

        // Creo i buckets
        ArrayList<Integer>[] buckets = new ArrayList[numeroBuckets];

        // Inizializzo i buckets con ArrayList vuote;
        for (int i = 0; i < numeroBuckets; i++){
            buckets[i] = new ArrayList<Integer>();
        }

        // Inserisco i numeri nei buckets
        for (int i = 0; i < numeri.length; i++){
            int bucketIndex = numeri[i] / numeroBuckets; // Esempio, il numero 55 sarà nel bucket 5 perchè 50 / numeroBuckets (dove numeroBuckets è 10), fa 5.5 e viene troncato a 5.
            buckets[bucketIndex].add(numeri[i]); // Inserisco il numero
        }

        // Ordino i buckets
        for (int i = 0; i < numeroBuckets; i++){
            buckets[i].sort(null); // Sono pigro quindi uso uno dei sort integrati.
        }

        // Ricostruisco il vettore finale
        int posInserimento = 0;
        for (int i = 0; i < numeroBuckets; i++){ // Per ogni bucket faccio un ciclo
            for (int j = 0; j < buckets[i].size(); j++){ // Per ogni elemento dei bucket.
                numeri[posInserimento++] = buckets[i].get(j); // Reinserisco il numero nel vettore dei numeri iniziale in modo ordinato.
            }
        }

        System.out.println("BucketSort completato!");
    }

    public void print(){
        System.out.println("Vettore dei numeri: ");
        for (int i = 0; i < numeri.length; i++){
            System.out.println((i + 1) + " -> " + numeri[i]);
        }
    }

}
