#include <iostream>
#include <stdio.h>
#include "Moneta.h"

void pausa();

int main() {

    int scelta;
    do {

        printf("\n\nOpzioni:"
               "\n0 -> Esci."
               "\n1 -> Lancia moneta."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{
                printf("\nHai scelto: Esci...");
                break;
            }

            case 1:{
                printf("\nHai scelto: Lancia moneta...");

                Moneta moneta;

                printf("\nRisultato lancio: %s", moneta.toString().c_str());

                pausa();
            }

            default:{
                printf("\nHai inserito un valore non valido, per favore riprovare.");
                break;
            }
        }

    } while (scelta != 0);

    printf("\nUscito con successo!");

    return 0;
}

void pausa(){
    printf("\n\nInserire un numero per continuare: ");
    scanf("%d");
}
