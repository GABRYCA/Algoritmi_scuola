#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ricorsivo(int i);

int main() {

    printf("\nAlgoritmo di G.C. 4BITI.");

    int scelta;
    do {

        printf("\n\nScelte:"
               "\n0 -> Esci."
               "\n1 -> Calcola fattoriale."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci...");

                break;
            }

            case 1:{

                printf("\nScelta: Calcolo fattoriale.");

                int numero;
                printf("\nInserire il numero fattoriale da calcolare: ");
                scanf("%d", &numero);

                printf("\nIl fattoriale e' %d", ricorsivo(numero));

                break;
            }

            default:{

                printf("\n\nScelta non valida, per favore riprovare.");

                break;
            }

        }

    } while (scelta != 0);

    printf("\n\nUscito con successo!");

    return 0;
}

int ricorsivo(int i){
    if(i > 1){
        return i * ricorsivo(i - 1);
    } else {
        return 1;
    }
}
