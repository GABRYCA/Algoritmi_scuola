package it.gabryca;

public class ElevamentoPot extends Util{

    public void elevamentoAPot(){

        int x, y, ris;

        printf("Inserire un numero da elevare: ");
        x = getScanner().nextInt();
        printf("Inserire la potenza: ");
        y = getScanner().nextInt();

        ris = elevamentoPotenzaCalc(x,y);

        printfn("Il risultato di " + x + " elevato alla " + y + " è " + ris + ".");
    }

    private int elevamentoPotenzaCalc(int x, int y){

        int contatore = 1, ris = x;

        while (contatore < y){

            ris = ris * x;

            contatore++;
        }

        return ris;

    }
}
