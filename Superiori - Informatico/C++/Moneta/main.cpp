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
               "\n2 -> Gioco."
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
                break;
            }

            case 2:{
                printf("\nHai scelto: Gioca...");

                int sceltaGiocatore;
                int lanciTesta = 0;
                Moneta miaMoneta;
                printf("\nGioco testa o croce - 5 lanci.");
                printf("\nScegli testa (0) oppure croce (1): ");
                scanf("%d", &sceltaGiocatore);
                for (int i = 0; i < 5; i++) {
                    miaMoneta.lancia();
                    printf("%s\n", miaMoneta.toString().c_str());
                    if (miaMoneta.isTesta()){
                        lanciTesta++;
                    }
                }
                if (sceltaGiocatore == 0 && lanciTesta > 2){
                    printf(" -> Hai vinto ! \n");
                } else {
                    printf(" -> Ha vinto il PC! \n");
                }

                pausa();
                break;
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
