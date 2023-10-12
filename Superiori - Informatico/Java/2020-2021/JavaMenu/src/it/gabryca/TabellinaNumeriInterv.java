package it.gabryca;

public class TabellinaNumeriInterv extends Util {

    public void TabellinaNumeriAlg(){

        int x, y;

        printfn("Hai scelto: Tabellina Numeri in un intervallo...");

        printf("Inserire Inizio intervallo: ");
        x = getScanner().nextInt();

        printf("Inserire Fine intervallo: ");
        y = getScanner().nextInt();

        tabellinaIntervallo(x,y);

    }

    private void tabellinaIntervallo(int x, int y){

        int ris = 0;

        // Ripeto il loop finch� x non diventa maggiore di x
        while (x <= y){

            printf("\n\nTabellina del: " + x);

            for (int i = 1; i <= 10 ; i++) {

                ris = x * i;

                printf("\nTabellina " + x +  " Ris: " + ris);

            }

            x++;
        }
    }
}
