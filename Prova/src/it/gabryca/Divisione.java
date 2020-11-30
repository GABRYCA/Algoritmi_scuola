package it.gabryca;

public class Divisione extends Util {

    public void divisione(){

        // Messaggio d'inizio
        System.out.println("Hai scelto: Divisione...");

        // Inizializzo variabili
        int x, y, ris = 0;

        // Chiedo valori in input
        System.out.print("Inserire il dividendo: ");
        x = getScanner().nextInt();
        System.out.print("Inserire il divisore: ");
        y = getScanner().nextInt();

        // Loop che decrementa x di y e aumenta un contatore che è ris
        while (x >= y){

            x = x - y;

            ris++;
        }

        // Comunico il risultato all'utente
        System.out.println("Il risultato è: " + ris);
    }
}
