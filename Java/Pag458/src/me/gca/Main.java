package me.gca;

public class Main {

    public static void main(String[] args) {

        // Messaggio di benvenuto.
        Util.printfn("\n/////////////////////////////////////" +
                "\n// Compito Bicchiere di G.C. 4BITI //" +
                "\n/////////////////////////////////////");

        int nNumeri;
        Util.printf("\nNumero numeri da inserire: ");
        nNumeri = Util.getScanner().nextInt();

        int[] vet = new int[nNumeri];

        Util.printfn("\nInserire i numeri: ");
        vetNumeri(nNumeri, vet);

        Util.printfn("\nI numeri inseriti sono: ");
        for (int i = 0; i < nNumeri; i++){
            Util.printfn((i + 1) + ": " + vet[i]);
        }
    }

    private static void vetNumeri(int nNumeri, int[] vet) {
        for (int i = 0; i < nNumeri; i++){
            Util.printf((i + 1) + ": ");
            vet[i] = Util.getScanner().nextInt();
        }
    }
}
