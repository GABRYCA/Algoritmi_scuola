package it.gabryca;

public class Moltiplicazione extends Util {

    public void moltiplicazione(){

        // Messaggio d'inizio
        printfn("Hai scelto: moltiplicazione...");

        // Inizializzo variabili
        int x, y;

        // Chiedo l'input dei valori
        printf("Inserire un numero: ");
        y = getScanner().nextInt();
        printf("Inserire il secondo numero: ");
        x = getScanner().nextInt();

        // Richiama la funzione
        int ris = moltiplicazioneWhile(x, y);

        // Comunico il risultato
        printfn("Il risultato è: " + ris);
    }

    private int moltiplicazioneWhile(int x, int y) {

        // Dichiaro variabile
        int ris = 0;

        // Loop che incrementa ris di x fino a quando y non diventa minore/uguale 0
        while (y > 0){

            ris = ris + x;

            y--;
        }
        return ris;
    }
}
