public class BubbleSort {

    private int numeroNumeri;
    private int[] numeri;

    public BubbleSort(int numeroNumeri) {
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
        System.out.println("BubbleSort avviato: ");


        boolean scambiati;
        for (int i = 0; i < numeri.length - 1; i++){
            scambiati = false;

            for (int j = 0; j < numeri.length - i - 1; j++){ // Faccio il ciclo dal primo numero fino all'ultimo meno il numero di numeri massimi già trovati meno 1 altrimenti sarebbe più grande della posizione massima del vettore (si conta da 0)
                if (numeri[j] > numeri[j + 1]){ // Se il numero successivo è più piccolo del precedente, lo scambio.
                    int numero = numeri[j]; // Numero attuale (più grande da spostare avanti)
                    numeri[j] = numeri[j + 1]; // Scambio con il numero successivo (più piccolo)
                    numeri[j + 1] = numero; // Metto il numero più grande una posizione avanti (scambio)
                    scambiati = true; // Segnalo che c'è stato uno scambio, altrimenti terminerebbe il ciclo.
                }
            }

            if (!scambiati) break; // Numeri già ordinati, fermo il ciclo.
        }

        System.out.println("BubbleSort Completato!");
    }

    public void print(){
        System.out.println("Vettore dei numeri: ");
        for (int i = 0; i < numeri.length; i++){
            System.out.println((i + 1) + " -> " + numeri[i]);
        }
    }
}
