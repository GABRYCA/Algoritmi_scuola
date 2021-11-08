package it.gabryca;

public class ElevamentoPot extends Util{

    public void elevamentoAPot(){

        // Messaggio d'inizio
        printfn("Hai scelto: elevamento a potenza...");

        // Dichiaro variabili
        int x, y, ris;

        // Chiedo valori di input
        printf("Inserire un numero da elevare: ");
        x = getScanner().nextInt();
        printf("Inserire la potenza: ");
        y = getScanner().nextInt();

        // Ottengo ris
        ris = elevamentoPotenzaCalc(x,y);

        // Comunico output
        printfn("Il risultato di " + x + " elevato alla " + y + " è " + ris + ".");
    }

    private int elevamentoPotenzaCalc(int x, int y){

        // Dichiaro variabili interne
        int contatore = 1, ris = x;

        // Inizio il ciclo
        while (contatore < y){

            ris = ris * x;

            contatore++;
        }

        // Ritorno risultato
        return ris;
    }
}
