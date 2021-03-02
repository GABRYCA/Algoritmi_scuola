#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <cstdlib>


using namespace std;

void continua();

bool vittoria(int n);

bool sconfitta(int n);

void giocoDadiFinale(int mode);

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
               "\n4 -> Gioco di dadi senza conferme."
               "\n5 -> Gioco di dadi senza messaggi durante i round."
               "\n6 -> Gioco di dadi con meno statistiche ma lette da FILE."
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

                giocoDadiFinale(0);

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

            case 4:{

                printf("\nHai scelto: Gioco dadi senza conferma per turno.");

                giocoDadiFinale(1);

                break;
            }

            case 5:{

                printf("\nHai scelto: Gioco dadi senza messaggi nei round.");

                giocoDadiFinale(2);

                break;
            }

            case 6:{

                printf("\nHai scelto: Meno statistiche ma lette da FILE.");

                giocoDadiFinale(3);

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

/**
 * mode = 0 chiede conferma ad ogni turno e mostra i messaggi.
 * mode = 1 non chiede conferma ad ogni turno e mostra i messaggi.
 * mode = 2 non chiede conferma ad ogni turno e non mostra i messaggi.
 * mode = 3 non chiede conferma ad ogni turno e non mostra i messaggi, ottiene le statistiche leggendole dal file.
 * */
void giocoDadiFinale(int mode){

    int nPartite;
    int scommessaVal;
    int nLanciFinale = 0;
    int punti = 0;
    int soldiFinali = 0;
    int nPartiteFatte = 0;
    bool vinto;
    int valSomme[12] = {0};
    int valSingoliDadi[6] = {0};
    char vintoTesto[6] = "vinto";
    char perso[6] = "perso";
    int nLanciAPartitaVet[1000] = {0};
    int valMaxLanciVit = 0;

    // Chiedo input numero partite.
    printf("\n\n|---------------------------------------------------------------------|"
           "\n| Scrivere il numero di partite: ");
    scanf("%d", &nPartite);
    printf("|---------------------------------------------------------------------|");

    FILE *cfPartita;
    cfPartita = fopen("partite.txt", "w");

    if (cfPartita == NULL){
        printf("\n\n| C'è stato un errore durante la creazione del file delle partite.");
        return;
    }

    // Chiedo scommessa.
    printf("\n\n|---------------------------------------------------------------------|"
           "\n| Quanto vuoi scommettere per ogni partita?"
           "\n| Le condizioni sono le seguenti: "
           "\n| Vittoria -> Ottieni il doppio del valore che hai scommesso."
           "\n| Sconfitta -> Perdi il valore che hai scommesso."
           "\n| Valore: ");
    scanf("%d", &scommessaVal);
    printf("|---------------------------------------------------------------------|");


    printf("\n\n|---------------------------------------------------------------------|"
           "\n| Inizializzo Dadi..."
           "\n|---------------------------------------------------------------------|");

    srand(time(0));

    while (nPartite > 0){

        int qualcosaDiFineAvvenuto = 0;
        int nLanci = 0;
        int puntiPrima = punti;
        if (mode == 0) {
            int valConferma;
            printf("\n\n|---------------------------------------------------------------------|"
                   "\n| Round %d"
                   "\n| Digita un numero per lanciare i dadi: ", nPartiteFatte + 1);
            scanf("%d", &valConferma);
            printf("|---------------------------------------------------------------------|");
        }

        int dado1 = (rand() % 6) + 1;
        int dado2 = (rand() % 6) + 1;
        int numeroCasuale = dado1 + dado2;
        valSomme[numeroCasuale - 2] = valSomme[numeroCasuale - 2] + 1;
        valSingoliDadi[dado1 - 1] = valSingoliDadi[dado1 - 1] + 1;
        valSingoliDadi[dado2 - 1] = valSingoliDadi[dado2 - 1] + 1;
        nLanci++;

        if (vittoria(numeroCasuale)){
            if (mode != 2 && mode != 3) {
                printf("\n\n|---------------------------------------------------------------------|"
                       "\n| Complimenti hai vinto questo round!"
                       "\n| Il numero era %d."
                       "\n| Rimangono %d partite."
                       "\n| E' stato necessario un solo lancio!"
                       "\n|---------------------------------------------------------------------|", numeroCasuale,
                       nPartite - 1);
            }
            nPartite--;
            punti++;
            qualcosaDiFineAvvenuto++;
        }

        if (qualcosaDiFineAvvenuto == 0 && sconfitta(numeroCasuale)){
            if (mode != 2 && mode != 3) {
                printf("\n\n|---------------------------------------------------------------------|"
                       "\n| Hai perso questo round!"
                       "\n| Il tuo numero era %d."
                       "\n| Rimangono %d partite."
                       "\n| Sono stati necessari %d lanci."
                       "\n|---------------------------------------------------------------------|", numeroCasuale,
                       nPartite - 1, nLanci);
            }
            nPartite--;
            qualcosaDiFineAvvenuto++;
        }

        if (qualcosaDiFineAvvenuto == 0){

            if (mode != 2 && mode != 3) {
                printf("\n\n|-------------------------------------------------------------------------------------|"
                       "\n| Non hai trovato 7-11 per vincere e nemmeno 2-3-12 per perdere! Hai trovato %d..."
                       "\n| Per passare al prossimo turno deve avvenire una delle seguenti condizioni:"
                       "\n| 1 -> Trovare un valore uguale a quello dei tuoi dadi (%d) per -vincere-."
                       "\n| 2 -> Trovare 7 e -perdere-."
                       "\n| Questo significa che saranno lanciati i dadi in automatico"
                       "\n| fino a quando una delle due condizioni non si avvera."
                       "\n|-------------------------------------------------------------------------------------|"
                       "\n"
                       "\n|-------------------------------------------------------------------------------------|"
                       "\n| Valori trovati: ", numeroCasuale, numeroCasuale);
            }

            int nuovoNumeroCasuale = 0;
            while (nuovoNumeroCasuale != numeroCasuale && qualcosaDiFineAvvenuto == 0){

                dado1 = (rand() % 6) + 1;
                dado2 = (rand() % 6) + 1;
                nuovoNumeroCasuale = dado1 + dado2;
                valSomme[nuovoNumeroCasuale - 2] = valSomme[nuovoNumeroCasuale - 2] + 1;
                valSingoliDadi[dado1 - 1] = valSingoliDadi[dado1 - 1] + 1;
                valSingoliDadi[dado2 - 1] = valSingoliDadi[dado2 - 1] + 1;
                nLanci++;

                if (nuovoNumeroCasuale == 7){
                    qualcosaDiFineAvvenuto++;
                }

                if (nuovoNumeroCasuale != 0 && mode != 2 && mode != 3){
                    printf("%d\t", nuovoNumeroCasuale);
                }
            }

            if (qualcosaDiFineAvvenuto == 0) {

                if (mode != 2 && mode != 3) {
                    printf("\n| Hai vinto questo round!"
                           "\n| Il numero da trovare era %d e hai trovato %d."
                           "\n| Sono stati necessari %d lanci."
                           "\n|-------------------------------------------------------------------------------------|",
                           numeroCasuale, nuovoNumeroCasuale, nLanci - 1);
                }
                punti++;
            } else if (mode != 2 && mode != 3){
                 printf("\n| Hai perso questo round..."
                        "\n| Il numero da trovare era %d e hai trovato %d ossia il valore di sconfitta -7-."
                        "\n| Sono stati necessari %d lanci."
                        "\n|-------------------------------------------------------------------------------------|",
                        numeroCasuale, nuovoNumeroCasuale, nLanci - 1);
            }
            nPartite--;
        }

        // Aggiunge o rimuove soldi.
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

        // Formato: nPartita, nlanciDadiInCoppia, soldiAlTurno, puntiAlTurno, vintoOPerso.
        if (vinto) {
            fprintf(cfPartita, "%d %d %d %d %s", nPartiteFatte++, nLanci, soldiFinali, punti, vintoTesto);
        } else {
            fprintf(cfPartita, "%d %d %d %d %s", nPartiteFatte++, nLanci, soldiFinali, punti, perso);
        }

        if (valMaxLanciVit < nLanci){
            valMaxLanciVit = nLanci;
        }

        nLanciAPartitaVet[nLanci-1] = nLanciAPartitaVet[nLanci-1] + 1;

        // Fine scrittura su file.
        nLanciFinale += nLanci;
    }

    if (mode != 3) {
        printf("\n\n|---------------------------------------------------------------------|"
               "\n| Fine del gioco, hai fatto: "
               "\n| %d lanci"
               "\n| %d punti"
               "\n| I tuoi soldi sono -> %d"
               "\n| Percentuale vittorie: %.2f"
               "\n|---------------------------------------------------------------------|", nLanciFinale, punti,
               soldiFinali, (double) punti / nPartiteFatte * 100);


        printf("\n\n|---------------------------------------------------------------------|"
               "\n| Frequenza lancio dadi a round..."
               "\n| nLanci -> VolteUscito");
        for (int i = 0; i < valMaxLanciVit; i++) {
            if (nLanciAPartitaVet[i] != 0) {
                printf("\n| %d -> %d", i + 1, nLanciAPartitaVet[i]);
            }
        }
        printf("\n|---------------------------------------------------------------------|");


        printf("\n\n|---------------------------------------------------------------------|"
               "\n| La frequenza delle somme risulta... "
               "\n| Numero -> Percentuale:");
        for (int i = 0; i < 11; i++) {
            printf("\n| %d -> %.2f", i + 2, (double) valSomme[i] / nLanciFinale * 100);
        }

        int conferma;
        printf("\n|---------------------------------------------------------------------|"
               "\n"
               "\n|---------------------------------------------------------------------|"
               "\n| Vuoi vedere la frequenza dei singoli dadi?"
               "\n| 0 -> No."
               "\n| 1 -> Si (qualsiasi valore diverso da 0 va bene)."
               "\n| Scelta: ");
        scanf("%d", &conferma);

        if (conferma != 0) {
            printf("| La frequenza dei singoli dadi risulta... "
                   "\n| Numero -> nVolte:");
            for (int i = 0; i < 6; i++) {
                printf("\n| %d -> %.2f", i + 1, (double) valSingoliDadi[i] / (nLanciFinale * 2) * 100);
            }
            printf("\n|---------------------------------------------------------------------|");
        } else {
            printf("|---------------------------------------------------------------------|");
        }
    }

    fclose(cfPartita);

    printf("\n\n|---------------------------------------------------------------------|"
           "\n| L'esito dei turni e' stato salvato nel file partite.txt!"
           "\n|---------------------------------------------------------------------|");

    if (mode == 3) {
        cfPartita = fopen("partite.txt", "r");

        if (cfPartita == NULL) {
            printf("\nErrore durante la lettura del file...");
        } else {

            int nLanci = 0;
            nLanciFinale = 0;
            punti = 0;
            soldiFinali = 0;
            nPartiteFatte = 0;
            int nLanciAPartitaVetNuovo[1000] = {0};
            valMaxLanciVit = 0;
            char ignorato[1000];

            while (!feof(cfPartita)){
                fscanf(cfPartita, "%d %d %d %d %s", &nPartiteFatte + 1, &nLanci, &soldiFinali, &punti, ignorato);

                nLanciFinale += nLanci;

                nLanciAPartitaVetNuovo[nLanci-1] = nLanciAPartitaVetNuovo[nLanci-1] + 1;

                if (nLanci > valMaxLanciVit){
                    valMaxLanciVit = nLanci;
                }

            }

            printf("\n\n|---------------------------------------------------------------------|"
                   "\n| Fine del gioco, hai fatto: "
                   "\n| %d lanci"
                   "\n| %d punti"
                   "\n| I tuoi soldi sono -> %d"
                   "\n| Percentuale vittorie: %.2f"
                   "\n|---------------------------------------------------------------------|", nLanciFinale, punti,
                   soldiFinali, (double) punti / nPartiteFatte * 100);

            printf("\n\n|---------------------------------------------------------------------|"
                   "\n| Frequenza lancio dadi a round..."
                   "\n| nLanci -> VolteUscito");
            for (int i = 0; i < valMaxLanciVit; i++) {
                if (nLanciAPartitaVetNuovo[i] != 0) {
                    printf("\n| %d -> %d", i + 1, nLanciAPartitaVetNuovo[i]);
                }
            }
            printf("\n|---------------------------------------------------------------------|");
        }
    }



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
