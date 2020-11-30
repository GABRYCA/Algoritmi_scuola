package it.gabryca;

public class Moltiplicazione extends Util {

    public void moltiplicazione(){

        // Messaggio d'inizio
        printfn("Hai scelto: moltiplicazione...");

        // Inizializzo variabili
        int x, y, ris = 0;

        // Chiedo l'input dei valori
        printf("Inserire un numero: ");
        y = getScanner().nextInt();
        printf("Inserire il secondo numero: ");
        x = getScanner().nextInt();

        // Richiama la funzione
        ris = moltiplicazioneWhile(x, y, ris);

        // Comunico il risultato
        printfn("Il risultato è: " + ris);
    }

    private int moltiplicazioneWhile(int x, int y, int ris) {
        // Loop che incrementa ris di x fino a quando y non diventa minore/uguale 0
        while (y > 0){

            ris = ris + x;

            y--;
        }
        return ris;
    }
}
