package it.gabryca;

public class Moltiplicazione extends Util {

    public void moltiplicazione(){

        // Messaggio d'inizio
        System.out.println("Hai scelto: moltiplicazione...");

        // Inizializzo variabili
        int x, y, ris = 0;

        // Chiedo l'input dei valori
        System.out.print("Inserire un numero: ");
        y = getScanner().nextInt();
        System.out.print("Inserire il secondo numero: ");
        x = getScanner().nextInt();

        // Loop che incrementa ris di x fino a quando y non diventa minore/uguale 0
        while (y > 0){

            ris = ris + x;

            y--;
        }

        // Comunico il risultato
        System.out.println("Il risultato è: " + ris);
    }
}
