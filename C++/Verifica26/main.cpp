#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <cstdlib>


using namespace std;

void continua();

bool vittoria(int n);

bool sconfitta(int n);

void giocoDadi();

void frequenza12Facce();

void frequenza2Dadi6Facce();

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           Verifica di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Valore bandiera.
    int scelta = 1;

    // Continua fino a messaggio di uscita da parte dell'utente.
    while (scelta != 0) {

        // Legenda.
        printf("\n\nScegli uno:"
               "\n0 -> Esci."
               "\n1 -> Gioca con i dadi."
               "\n2 -> Frequenza dadi a 12 facce."
               "\n3 -> Frequenza 2 dadi a 6 facce."
               "\nScelta: ");
        scanf("%d", &scelta);

        // Switch tra le varie scelte.
        switch(scelta){

            case 0:{

                // Messaggio di uscita.
                printf("\nHai scelto: Esci...");

                break;
            }

            case 1:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Gioco di dadi...");

                giocoDadi();

                continua();
                break;
            }

            case 2:{

                printf("\nHai scelto: Frequenza lancio dadi a 12 facce.");

                frequenza12Facce();

                break;
            }

            case 3:{

                printf("\nHai scelto: Frequenza lancio dadi a 6 facce.");

                frequenza2Dadi6Facce();

                break;
            }

            default:{

                // Messaggio di errore, scelta non valida.
                printf("\nScelta non valida!");

                // Richiamo la pausa per input utente.
                continua();
                break;
            }

        }
    }

    // Messaggio di uscita con successo.
    printf("\nUscito con successo!");

    return 0;
}

void frequenza2Dadi6Facce() {

    int nLanci;
    int nFacce = 6;
    int valori[12] = {0};
    printf("\n\nInserire quante volte lanciare i dadi: ");
    scanf("%d", &nLanci);

    srand(time(0));

    for (int i = 0; i < nLanci; i++) {

        int dado1 = (rand() % nFacce) + 1;
        int dado2 = (rand() % nFacce) + 1;
        int numeroCasuale = dado1 + dado2;

        valori[numeroCasuale - 2] = valori[numeroCasuale - 2] + 1;

    }

    printf("\nLa frequenza risulta: ");

    for (int i = 0; i < (nFacce * 2 - 1); i++) {
        printf("\n%d -> %.2f", i + 2, (double) valori[i] / nLanci * 100);
    }
}

void frequenza12Facce() {

    int valori[12] = {0};
    int nFacce = 12;
    int numeroVolte;
    printf("\n\nInserire numero volte lancio dadi a 12 facce: ");
    scanf("%d", &numeroVolte);

    srand(time(0));

    for (int i = 0; i < numeroVolte; i++) {

        int numeroCasuale = (rand() % nFacce) + 1;

        valori[numeroCasuale - 1] = valori[numeroCasuale - 1] + 1;

    }

    printf("\nLa frequenza risulta: ");

    for (int i = 0; i < nFacce; i++) {
        printf("\n%d -> %.2f", i + 1, (double) valori[i] / numeroVolte * 100);
    }
}

void giocoDadi() {

    int nPartite;
    int scommessaVal;

    // Chiedo input numero partite.
    printf("\nScrivere il numero di partite: ");
    scanf("%d", &nPartite);

    FILE *cfPartita;
    cfPartita = fopen("partite.txt", "w");

    if (cfPartita == NULL){
        printf("\nC'è stato un errore durante la creazione del file delle partite.");
    }

    // Chiedo scommessa.
    printf("\nQuanto vuoi scommettere per ogni partita?"
           "\nSe vinci vincerai il doppio per round di quello che hai scommesso"
           "\nMentre se perdi perderai il valore di scommessa."
           "\nValore: ");
    scanf("%d", &scommessaVal);

    int nLanciFinale = 0;
    int punti = 0;
    int soldiFinali = 0;
    int nPartiteFatte = 0;
    bool vinto;
    int val[12] = {0};

    while (nPartite > 0){

        int valConferma;
        int qualcosaDiFineAvvenuto = 0;
        int nLanci = 0;
        int puntiPrima = punti;
        printf("\n\nDigita un numero per lanciare i dadi: ");
        scanf("%d", &valConferma);

        srand(time(0));

        int dado1 = (rand() % 6) + 1;
        int dado2 = (rand() % 6) + 1;
        int numeroCasuale = dado1 + dado2;
        val[numeroCasuale - 2] = val[numeroCasuale - 2] + 1;
        nLanci++;

        if (vittoria(numeroCasuale)){
            printf("\n\nComplimenti hai vinto questo round!"
                   "\nIl numero dei dadi era %d."
                   "\nRimangono %d partite."
                   "\nSono stati necessari %d lanci.", numeroCasuale, nPartite - 1, nLanci);
            nPartite--;
            punti++;
            qualcosaDiFineAvvenuto++;
        }

        if (qualcosaDiFineAvvenuto == 0 && sconfitta(numeroCasuale)){
            printf("\n\nHai perso questo round!"
                   "\nIl tuo numero era %d."
                   "\nRimangono %d partite."
                   "\nSono stati necessari %d lanci.", numeroCasuale, nPartite - 1, nLanci);
            nPartite--;
            qualcosaDiFineAvvenuto++;
        }

        if (qualcosaDiFineAvvenuto == 0){

            printf("\n\nNon hai trovato 7-11 per vincere e nemmeno 2-3-12 per perdere! Hai trovato %d...", numeroCasuale);

            int nuovoNumeroCasuale = 0;
            while (nuovoNumeroCasuale != numeroCasuale && qualcosaDiFineAvvenuto == 0){

                if (nuovoNumeroCasuale != 0){
                    printf("\n\nHai trovato %d e dovevi trovare %d... non hai ancora vinto!", nuovoNumeroCasuale, numeroCasuale);
                }

                int valoreInutile;
                printf("\n\nDigitare un numero per ri-lanciare i dadi: ");
                scanf("%d", &valoreInutile);

                dado1 = (rand() % 6) + 1;
                dado2 = (rand() % 6) + 1;
                nuovoNumeroCasuale = dado1 + dado2;
                val[nuovoNumeroCasuale - 2] = val[nuovoNumeroCasuale - 2] + 1;
                nLanci++;

                if (nuovoNumeroCasuale == 7){
                    qualcosaDiFineAvvenuto++;
                }
            }

            if (qualcosaDiFineAvvenuto == 0) {

                printf("\n\nHai finalmente trovato due numero uguali! Il numero da trovare era %d e hai trovato %d"
                       "\nSono stati necessari %d lanci.", numeroCasuale, nuovoNumeroCasuale, nLanci);
                punti++;
            } else {

                printf("\nHai perso questo round, il numero da trovare era %d e hai trovato %d che è uguale a 7 ossia sconfitta.", numeroCasuale, nuovoNumeroCasuale);

            }
            nPartite--;
        }

        if (puntiPrima == punti){
            soldiFinali -= scommessaVal;
            vinto = false;
        } else {
            soldiFinali += scommessaVal * 2;
            vinto = true;
        }

        // Scrittura su file esito...

        char capo[2] = "\n";

        if (nPartiteFatte != 0){
            fprintf(cfPartita, "%s", capo);
        }

        char vintoTesto[6] = "vinto";
        char perso[6] = "perso";

        // Formato: nPartita, nlanci, soldiAlTurno, puntiAlTurno, vintoOPerso.
        if (vinto) {
            fprintf(cfPartita, "%d %d %d %d %s", nPartiteFatte++, nLanci, soldiFinali, punti, vintoTesto);
        } else {
            fprintf(cfPartita, "%d %d %d %d %s", nPartiteFatte++, nLanci, soldiFinali, punti, perso);
        }

        // Fine scrittura su file.
        nLanciFinale += nLanci;
    }

    printf("\n\nFine del gioco, hai fatto %d lanci e %d punti, i tuoi soldi sono -> %d", nLanciFinale, punti, soldiFinali);

    printf("\n\nLa frequenza dei numeri risulta: ");
    for (int i = 0; i < 11; i++) {
        printf("\n%d -> %d", i + 2, val[i]);
    }

    fclose(cfPartita);

    printf("\nL'esito dei turni è stato salvato nel file partite.txt!");
}

bool sconfitta(int n){

    if(n == 2 || n == 3 || n == 12){
        return true;
    } else {
        return false;
    }

}

bool vittoria(int n){

    if(n == 7 || n == 11){
        return true;
    } else {
        return false;
    }

}

void continua(){

    // Variabile inutile per evitare errori.
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}
