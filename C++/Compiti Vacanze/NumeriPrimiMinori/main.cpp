#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void continua();

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//        Numeri primi di Gabriele Caretti 3BITI           //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;
    while (scelta != 0){

        printf("\n\nLegenda:"
               "\n0 -> Esci."
               "\n1 -> Vettore numeri primi minori di un numero."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Vettore numeri primi minori di un numero...");

                int numeroIng;
                printf("\n\nInserire numero sotto il cui trovare i numeri primi: ");
                scanf("%d", &numeroIng);

                int nNumeriPrimi = 0, vettoreNumeriPrimi[250];

                printf("\nNumeri primi: ");

                for (int i = 0; i < numeroIng; i++) {

                    int nNumeriDivisibile = 0;
                    int numeriDivisioneTest = 1;
                    while (numeriDivisioneTest <= i){
                        if (i % numeriDivisioneTest == 0){
                            nNumeriDivisibile++;
                        }
                        numeriDivisioneTest++;
                    }

                    if (nNumeriDivisibile == 2){
                        vettoreNumeriPrimi[nNumeriPrimi] = i;
                        nNumeriPrimi++;
                    }

                }

                for (int i = 0; i < nNumeriPrimi; i++) {
                    printf("\t%d", vettoreNumeriPrimi[i]);
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
