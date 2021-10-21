#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <utility>
#include "graphics/graphics.h"

using namespace std;

bool inputBool();

int main() {

    printf("\n\nBenvenuto nell'Haloi di G.C. 4BITI");

    int scelta;

    do{

        printf("\n\nEcco una lista delle scelte disponibili: "
               "\n0 -> Esci."
               "\n1 -> Hanoi."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0:{

                printf("\n\nHai scelto esci...");

                break;
            }

            case 1:{

                printf("\n\nHai scelto: Hanoi...");

                int nCilindri;
                bool pausaClick;
                do {

                    printf("\n\nInserire il numero di cilindri: ");
                    scanf("%d", &nCilindri);

                    if (nCilindri == 0){
                        printf("\nPer favore inserire un valore maggiore di 0.");
                    }

                } while (nCilindri <= 0);

                printf("\nVuoi cliccare per procedere oppure lasciare automatico? "
                       "\nScelta: ");
                pausaClick = inputBool();

                printf("\nNumero cilindri: %d.", nCilindri);

                break;
            }

            default:{

                printf("\n\nHai inserito una scelta non valida, per favore riprovare!");

                break;
            }
        }

    } while (scelta != 0);

    printf("\nUscito con successo!");

    return 0;
}

bool inputBool(){

    while (true){

        int num;
        printf("\n0 -> No."
               "\n1 -> Si.");
        scanf("%d", &num);

        if (num == 1){
            printf("\nHai scelto: Si.");
            return true;
        } else if (num == 0){
            printf("\nHai scelto: No.");
            return false;
        }
        printf("\nScelta non valida, per favore riprovare.");
    }
}