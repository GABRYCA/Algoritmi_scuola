package it.gabryca;

import java.util.concurrent.ThreadLocalRandom;

public class MasterMindNormale extends Util {

    void masterMindNormale(int[] mioVettore, int max, int min, int nCifre, int nCifreGenerate, int nTentativi) {


        // Genero N cifre diverse tra loro e le aggiungo al vettore.
        while (nCifreGenerate < nCifre) {

            // Ottiene un numero casuale
            int numeroRandom = ThreadLocalRandom.current().nextInt(min, max + 1);
            int valorePres = 0;

            // Verifica se il numero casuale è già stato aggiunto tra le cifre.
            for (int i = 0; i < nCifreGenerate; i++) {
                if (mioVettore[i] == numeroRandom || mioVettore[0] == 0) {
                    valorePres++;
                }
            }

            // Se il numero NON era presente tra le cifre generate, lo aggiunge tra le cifre generate.
            if (valorePres == 0) {
                mioVettore[nCifreGenerate] = numeroRandom;
                nCifreGenerate++;
            }
        }

        // Numeri generati con successo, lo comunico e inizio.
        printfn("\nGenerato con successo un numero con " + nCifre + " cifre! Inizia il gioco...");

        int vinto = 0;

        // Continua fino a quando finiscono i tentativi oppure vince
        while (nTentativi != 0 && vinto == 0) {

            int cifreIndovinate = 0, cifreNonInPosCor = 0;

            nTentativi--;

            int numeroProvato;
            int[] numeroProvatoVet = new int[nCifre];

            printf("\nInserisci un numero: ");
            numeroProvato = getScanner().nextInt();

            singoloValVet(nCifre, numeroProvatoVet, numeroProvato);

            for (int i = 0; i < nCifre; i++) {
                for (int j = 0; j < nCifre; j++) {
                    if (mioVettore[i] == numeroProvatoVet[j] && i == j){
                        // printf("[" + mioVettore[i] + "]");
                        cifreIndovinate++;
                    } else if (mioVettore[i] == numeroProvatoVet[j]){
                        // printf("(" + mioVettore[i] + ")");
                        cifreNonInPosCor++;
                    }
                }
            }

            for (int i = 0; i < cifreIndovinate; i++){
                printf("[]");
            }
            for (int i = 0; i < cifreNonInPosCor; i++){
                printf("()");
            }

            if (cifreIndovinate == nCifre){
                printf("\n\nHai vinto! Il numero " + numeroProvato + " è corretto!" +
                        "\nTi rimanevano " + nTentativi + " tentativi!");
                vinto++;
            }

            if (nTentativi == 0 && vinto == 0){
                printf("\n\nHai finito i tentativi, GAME OVER!");
                printf("\nIl numero era: ");
                for (int i = nCifre-1; i >= 0; i--) {
                    printf("" + mioVettore[i]);
                }
            } else if (vinto == 0){
                printf("\nHai ancora " + nTentativi + " tentativi.\n");
            }
        }

        printf("\nFine del gioco...");
    }
}
