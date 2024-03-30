public class DistributionCountingSort {

    private int numeroNumeri;
    private int[] numeri;

    public DistributionCountingSort(int numeroNumeri){
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
        System.out.println("DistributionCountingSort avviato...");

        int max = numeri[0], min = numeri[0];

        // Cerco massimo e minimo
        for (int i = 0; i < numeri.length; i++){
            if (numeri[i] > max) max = numeri[i];
            else if (numeri[i] < min) min = numeri[i];
        }

        // Creo un vettore che conta per ogni numero quante volte si ripete
        int[] ripetizioni = new int[max - min + 1];

        // Non serve il ciclo che setta a 0 i valori nel vettore, sono già 0 di default
        // Conto il numero di volte che ogni elemento si ripete.
        for (int i = 0; i < numeri.length; i++){
            ripetizioni[numeri[i]]++; // Incremento contatore usando la posizione, per esempio: se in numeri[0] è contenuto il numero 1, ripetizioni[1] sarà incrementato.
        }

        // Ricostruisco il vettore finale
        int[] finale = new int[numeri.length];
        int posInserimento = 0;
        for (int i = 0; i < ripetizioni.length; i++){
            while (ripetizioni[i] != 0){ // Fintanto ci siano elementi in questa posizione [i] da inserire nel vettore finale, continuo il ciclo di inserimento.
                ripetizioni[i]--; // Decremento, ho inserito nel vettore finale.
                finale[posInserimento++] = i + min; // sommo il minimo, perchè se prima il range era da 10 a 100 (per esempio), in ripetizioni[0] ci dovrebbe essere la conta di 10.
            }
        }

        numeri = finale;
        System.out.println("DistributionCountingSort completato!");
    }

    public void print(){
        System.out.println("Vettore dei numeri: ");
        for (int i = 0; i < numeri.length; i++){
            System.out.println((i + 1) + " -> " + numeri[i]);
        }
    }
}
