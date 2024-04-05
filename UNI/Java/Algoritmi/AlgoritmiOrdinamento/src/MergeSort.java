import java.util.Arrays;

public class MergeSort {
    private int numeroNumeri;
    private int[] numeri;

    boolean debugVisivo = false;

    public MergeSort(int numeroNumeri){
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
        System.out.println("MergeSort avviato...");

        sortAlgo(this.numeri, 0, this.numeri.length - 1);

        System.out.println("MergeSort completato!");
    }

    private void merge(int[] vettore, int inizio, int centro, int fine) {
        int[] vetSinistro = new int[centro - inizio + 1];
        int[] vetDestro = new int[fine - centro];

        for (int i = 0; i < vetSinistro.length; ++i) vetSinistro[i] = vettore[inizio + i]; // Creo vettore sinistro
        for (int j = 0; j < vetDestro.length; ++j) vetDestro[j] = vettore[centro + 1 + j]; // Creo vettore vetDestro

        if (debugVisivo) {
            System.out.println("Vettore sinistro: " + Arrays.toString(vetSinistro));
            System.out.println("Vettore destro: " + Arrays.toString(vetDestro));
        }

        int posizioneSinistra = 0, posizioneDestra = 0;

        int puntoDiFusione = inizio;
        while (posizioneSinistra < vetSinistro.length && posizioneDestra < vetDestro.length) {
            if (vetSinistro[posizioneSinistra] <= vetDestro[posizioneDestra]) {
                vettore[puntoDiFusione] = vetSinistro[posizioneSinistra];
                posizioneSinistra++;
            } else {
                vettore[puntoDiFusione] = vetDestro[posizioneDestra];
                posizioneDestra++;
            }
            puntoDiFusione++;
        }

        while (posizioneSinistra < vetSinistro.length) { // Inserisco elementi rimanenti nel vettore sinistro
            vettore[puntoDiFusione] = vetSinistro[posizioneSinistra];
            posizioneSinistra++;
            puntoDiFusione++;
        }

        while (posizioneDestra < vetDestro.length) { // Inserisco elementi rimanenti nel vettoe destro
            vettore[puntoDiFusione] = vetDestro[posizioneDestra];
            posizioneDestra++;
            puntoDiFusione++;
        }

        if (debugVisivo) {
            System.out.println("Vettore dopo la fusione: " + Arrays.toString(vettore));
        }
    }
    private void sortAlgo(int[] vettore, int inizio, int fine) {
        if (fine <= inizio) return;

        // esempio con vettore con 8 elementi: inizio = 0, fine = 7 -> centro = 3
        int centro = inizio + (fine - inizio) / 2;

        if (debugVisivo) {
            System.out.println("Divido il vettore: " + Arrays.toString(Arrays.copyOfRange(vettore, inizio, fine + 1)));
        }

        sortAlgo(vettore, inizio, centro); // divide e sort vettore sinistro
        sortAlgo(vettore, centro + 1, fine); // divide e sort vettore destro

        merge(vettore, inizio, centro, fine); // fusione
    }

    public void print(){
        System.out.println("Vettore dei numeri: ");
        for (int i = 0; i < numeri.length; i++){
            System.out.println((i + 1) + " -> " + numeri[i]);
        }
    }
}
