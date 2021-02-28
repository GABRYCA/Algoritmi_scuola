#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <cstdlib>


using namespace std;

void continua();

bool vittoria(int n);

bool sconfitta(int n);

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

                int nPartite;
                int scommessaVal;
                int nLanciFinale = 0;

                FILE *cfPartita;
                cfPartita = fopen("partite.txt", "w");

                if (cfPartita == NULL){
                    printf("\nC'è stato un errore durante la creazione del file delle partite.");
                }

                // Chiedo input numero partite.
                printf("\nScrivere il numero di partite: ");
                scanf("%d", &nPartite);

                // Chiedo scommessa.
                printf("\nQuanto vuoi scommettere per ogni partita?"
                       "\nSe vinci vincerai il doppio per round di quello che hai scommesso"
                       "\nMentre se perdi perderai il valore di scommessa."
                       "\nValore: ");
                scanf("%d", &scommessaVal);

                int numeriFatti[1000];
                int nNumeriFatti = 0;
                int punti = 0;
                int soldiFinali = 0;
                int nPartiteFatte = 0;
                bool vinto;

                while (nPartite > 0){

                    int valConferma;
                    int qualcosaDiFineAvvenuto = 0;
                    int nLanci = 0;
                    int puntiPrima = punti;
                    printf("\n\nDigita un numero per lanciare i dadi: ");
                    scanf("%d", &valConferma);

                    srand(time(0));

                    int numeroCasuale = rand() % 12;
                    nLanci++;
                    numeriFatti[nNumeriFatti] = numeroCasuale;
                    nNumeriFatti++;

                    if(numeroCasuale <= 1){
                        numeroCasuale++;
                    }

                    if (vittoria(numeroCasuale)){
                        printf("\n\nComplimenti hai vinto questo round!"
                               "\nRimangono %d"
                               "\nIl numero dei dadi era %d."
                               "\nSono stati necessari %d lanci.", nPartite, numeroCasuale, nLanci);
                        nPartite--;
                        punti++;
                        qualcosaDiFineAvvenuto++;
                    }

                    if (qualcosaDiFineAvvenuto == 0 && sconfitta(numeroCasuale)){
                        printf("\n\nHai perso questo round!"
                               "\nRimangono %d"
                               "\nIl tuo numero era %d."
                               "\nSono stati necessari %d lanci.", nPartite, numeroCasuale, nLanci);
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

                            nuovoNumeroCasuale = rand() % 12;
                            nLanci++;
                            numeriFatti[nNumeriFatti] = nuovoNumeroCasuale;
                            nNumeriFatti++;

                            if(nuovoNumeroCasuale <= 1){
                                nuovoNumeroCasuale++;
                            }

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
                        qualcosaDiFineAvvenuto++;
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

                int val2 = 0;
                int val3 = 0;
                int val4 = 0;
                int val5 = 0;
                int val6 = 0;
                int val7 = 0;
                int val8 = 0;
                int val9 = 0;
                int val10 = 0;
                int val11 = 0;
                int val12 = 0;

                for (int i = 0; i < nNumeriFatti; i++) {

                    switch (numeriFatti[i]) {

                        case 2:{

                            val2++;

                            break;
                        }

                        case 3:{

                            val3++;

                            break;
                        }

                        case 4:{

                            val4++;

                            break;
                        }

                        case 5:{

                            val5++;

                            break;
                        }

                        case 6:{

                            val6++;

                            break;
                        }

                        case 7:{

                            val7++;

                            break;
                        }

                        case 8:{

                            val8++;

                            break;
                        }

                        case 9:{

                            val9++;

                            break;
                        }

                        case 10:{

                            val10++;

                            break;
                        }

                        case 11:{

                            val11++;

                            break;
                        }

                        case 12: {

                            val12++;

                            break;
                        }

                        default:{

                            printf("\nUn errore è successo durante il calcolo della frequenza!");

                            break;
                        }

                    }



                }

                printf("\nLa frequenza dei valori risulta: "
                       "\n2 -> %d"
                       "\n3 -> %d"
                       "\n4 -> %d"
                       "\n5 -> %d"
                       "\n6 -> %d"
                       "\n7 -> %d"
                       "\n8 -> %d"
                       "\n9 -> %d"
                       "\n10 -> %d"
                       "\n11 -> %d"
                       "\n12 -> %d", val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12);

                fclose(cfPartita);

                printf("\nL'esito dei turni è stato salvato nel file partite.txt!");

                continua();
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

bool sconfitta(int n){

    if(n == 2){
        return true;
    } else if(n == 3){
        return true;
    } else if(n == 12){
        return true;
    } else {
        return false;
    }

}

bool vittoria(int n){

    if(n == 7){
        return true;
    } else if (n == 11){
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
