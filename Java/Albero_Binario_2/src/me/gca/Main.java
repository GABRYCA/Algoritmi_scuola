package me.gca;

public class Main {

    public static long numeroAzioni = 0;

    public static void main(String[] args) {

        int[] numeri = {10,8,-9,9,15,6,3};
        boolean numeriCasuali = true, letturaAlbero = false, heapSortAttivo = true, mostraVettore = false;
        int nNumeriCasuali = 1000, min = 1, max = 10001;
        if (numeriCasuali){
            numeri = new int[nNumeriCasuali];
            for (int i = 0; i < nNumeriCasuali; i++){
                numeri[i] = getRandomNumber(min, max);
            }
            System.out.println("\nNumeri generati con successo! [" + nNumeriCasuali + "]\n");
        }

        AlberoBin alberoBin = new AlberoBin();

        alberoBin.creaDaVettore(numeri, 0, numeri.length);

        if (letturaAlbero) {
        // radice, sinistra, destro etc.
        alberoBin.preorder1();
        // sinistra, destro, radice etc.
        alberoBin.postorder1();
        // sinistra, radice, destro etc.
        alberoBin.inorder1();

        System.out.println("\n\n" + alberoBin);
        }

        if (heapSortAttivo) {
            HeapSort heapSort = new HeapSort();
            long inizio = System.currentTimeMillis();
            heapSort.sort(numeri);
            long fine = System.currentTimeMillis();

            if (mostraVettore) {
                System.out.println("Vettore ordinato: ");
                stampaVettore(numeri);
            }
            System.out.println("Tempo impiegato in secondi: "+ ((fine-inizio) / 1000));
            System.out.println("Numero azioni: " + numeroAzioni);

            // Scambia ultimi con primi.
            numeri = reverse(numeri, numeri.length);

            if (isHeap(numeri)){
                System.out.println("\nSi, è un heap valido.");
            } else {
                System.out.println("\nNo, non è un heap valido!");
            }
        }
    }

    public static int getRandomNumber(int min, int max) {
        return (int) ((Math.random() * (max - min)) + min);
    }

    public static void stampaVettore(int[] arr) {
        for (int j : arr) {
            System.out.print(j + " ");
        }
        System.out.println();
    }

    public static int[] reverse(int[] vettore, int n) {
        int[] temp = new int[n];
        int j = n;
        for (int i = 0; i < n; i++) {
            temp[j - 1] = vettore[i];
            j = j - 1;
        }
        return temp;
    }

    public static boolean isHeap(int[] vettore){
        for (int i = 0; i < vettore.length - 1; i++){
            if (vettore[i] < vettore[i+1]){
                return false;
            }
        }
        return true;
    }
}
