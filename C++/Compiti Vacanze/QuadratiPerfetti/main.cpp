#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void continua();

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//        Quadrati Perfetti di Gabriele Caretti 3BITI           //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;
    while (scelta != 0){

        printf("\n\nLegenda:"
               "\n0 -> Esci."
               "\n1 -> Quadrati perfetti compresi tra 2 numeri."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Quadrati perfetti compresi tra 2 numeri");

                int n1, n2;
                printf("\n\nInserire il primo numero: ");
                scanf("%d", &n1);

                printf("\nInserire il secondo numero: ");
                scanf("%d", &n2);

                int maggiore, minore;

                if (n1 > n2){

                    maggiore = n1;
                    minore = n2;

                } else {

                    maggiore = n2;
                    minore = n1;

                }

                printf("\nI quadrati perfetti compresi tra i 2 numeri sono: \n");

                int ris = 0, nCons = 1;
                while (ris < maggiore){


                    ris = nCons * nCons;

                    if (ris > minore && nCons != maggiore && ris < maggiore){
                        printf("\t%d", ris);
                    }

                    nCons++;
                }


                break;
            }

            default:{

                printf("\nScelta non valida, per favore riprovare.");

                break;
            }


        }

    }

    printf("\n\nUscito con successo!");

    return 0;
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}
