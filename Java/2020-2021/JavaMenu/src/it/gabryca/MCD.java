package it.gabryca;

public class MCD extends Util {

    public void MCDAlg(){

        // Messaggio d'inizio
        printfn("Hai scelto: M.C.D....");

        // Inizializzo variabili
        int x, y, ris;

        // Chiedo valori in input
        printf("Inserire il primo valore: ");
        x = getScanner().nextInt();
        printf("Inserire il secondo valore: ");
        y = getScanner().nextInt();

        // Ottiene Ris e lo comunica all'utente
        ris = mcd(x,y);
        printf("L'M.C.D è: " + ris);
    }


    private int mcd(int x, int y){

        int resto;

        if (x > y){

            // Ripeti il loop finch� y non diventa uguale a 0
            while (y != 0){

                resto = x % y;

                x = y;

                y = resto;

                if (resto == 0){

                    return x;

                }

            }

            return x;

            // Bastava -else- ma ho deciso di mettere la condizione comunque
        } else if (x < y){

            while (x != 0){

                resto = y % x;

                y = x;

                x = resto;

                if (resto == 0){

                    return y;

                }

            }

            return y;

        }
        return 0;
    }
}
