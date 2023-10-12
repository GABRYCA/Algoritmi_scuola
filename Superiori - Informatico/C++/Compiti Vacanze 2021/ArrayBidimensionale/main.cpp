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
           "\n//        Array bidimensionale di G.C. 3BITI           //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;
    while (scelta != 0){

        printf("\n\nLegenda:"
               "\n0 -> Esci."
               "\n1 -> Array bidimensionale."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Array bidimensionale...");

                srand(time(0));

                int array[10][10];

                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        array[i][j] = randomMaxMin(2, 10) * randomMaxMin(2, 10);
                    }
                }

                int max = 0, min = 25000, sommaTraMaxMin = 0;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        int numeroArrayLetto = array[i][j];
                        if (numeroArrayLetto > max){
                            max = numeroArrayLetto;
                        } else if (numeroArrayLetto < min){
                            min = numeroArrayLetto;
                        }
                    }
                }

                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        int numeroArrayLetto = array[i][j];
                        if (numeroArrayLetto < max && numeroArrayLetto > min){
                            sommaTraMaxMin += numeroArrayLetto;
                        }
                    }
                }

                printf("\n\nIl MAX generato e': %d"
                       "\nIl MIN generato: %d"
                       "\nSomma compreso tra MAX e MIN: %d", max, min, sommaTraMaxMin);

                continua();
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

int randomMaxMin(int numeroMin, int numeroMax) {
    return rand() % (numeroMax - numeroMin + 1) + numeroMin;
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}
