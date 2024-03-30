public class InsertionSort {

    private int numeroNumeri;
    private int[] numeri;

    public InsertionSort(int numeroNumeri){
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
        System.out.println("InsertionSort avviato...");

        for (int i = 0; i < numeroNumeri; i++){
            int numero = numeri[i];
            int precedentePos = i - 1;

            while (precedentePos >= 0 && numeri[precedentePos] > numero){
                numeri[precedentePos + 1] = numeri[precedentePos]; // Scambio con il successivo
                precedentePos--; // Ottengo posizione numero precedente
            }
            numeri[precedentePos + 1] = numero; // Posiziono alla posizione corretta il numero
        }

        System.out.println("InsertionSort completato!");
    }

    public void print(){
        System.out.println("Vettore dei numeri: ");
        for (int i = 0; i < numeri.length; i++){
            System.out.println((i + 1) + " -> " + numeri[i]);
        }
    }
}
