#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void continua();

int randomMaxMin(int numeroMin, int numeroMax);

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//          nCasuale di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    srand(time(0));

    int scelta = 1;
    while (scelta != 0){

        printf("\n\nLegenda:"
               "\n0 -> Esci."
               "\n1 -> Numero casuale."
               "\nScelta: ");
        scanf("%d", &scelta);

        srand(time(0));

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Esegui numero casuale...");

                int nCoppieDaFare;
                printf("\n\nQuante coppie di numeri validi vuoi siano generati?"
                       "\nNumero: ");
                scanf("%d", &nCoppieDaFare);

                for (int i = 0; i < nCoppieDaFare; i++) {

                    int pari = 3, dispari = 4;

                    while ((pari % dispari) != 0){

                        // Genera numero pari.
                        pari = 2 * randomMaxMin(1, 100);

                        // Genera numero dispari.
                        dispari = 2 * randomMaxMin(1, 100) + 1;


                    }
                    printf("\n%d -> %d e %d", i + 1, pari, dispari);
                }




                break;
            }

            default:{

                printf("\n\nScelta non valida, per favore riprovare!");

                break;
            }

        }

    }

    printf("\n\nUscito con successo!");

    return 0;
}

int randomMaxMin(int numeroMin, int numeroMax) {
    return rand() % (numeroMax - numeroMin + 1) + numeroMin;
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}
