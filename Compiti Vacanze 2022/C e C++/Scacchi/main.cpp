#include <iostream>
#include <string>
#include "Scacchiera.h"
#include "Pedone.h"
#include "Cavallo.h"
#include "Alfiere.h"
#include "Torre.h"
#include "Donna.h"
#include "Re.h"

using namespace std;

// Gioco della scacchiera con tutte le classi e tipi di pedine sotto forma di oggetti
int main() {
    printf("///////////////////"
           "\nLavoro di G.C. 4BITI"
           "\n///////////////////\n");

    // Creo una scacchiera
    //Scacchiera scacchiera(8, 8);
    //Pedone pedone('B');

    // Posiziono le pedine
    //scacchiera.posizionaPedina(0, 0, pedone.getIDCompleto());
    //scacchiera.stampa();

    int scelta;
    Scacchiera scacchiera(8, 8);
    do {
        printf("\n\nOpzioni: "
               "\n0 -> Esci."
               "\n1 -> Resetta scacchi vuota."
               "\n2 -> Resetta scacchi con pedine."
               "\n3 -> Stampa scacchiera."
               "\n4 -> Posiziona pedina prima dell'inizio della partita."
               "\n5 -> Gioca."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0:{
                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");
                break;
            }
            case 1:{

                printf("\nHai scelto: Resetta scacchi..."
                       "\nReset in corso...");

                scacchiera.reset();

                scacchiera.stampa();

                printf("\nReset completato.");
                break;
            }
            case 2:{

                printf("\nHai scelto: Resetta scacchi con pedine..."
                       "\nReset in corso...");

                scacchiera.resetDefault();
                scacchiera.stampa();

                printf("\nReset completato.");

                break;
            }

            case 3:{

                printf("\nHai scelto: Stampa scacchiera...\n");
                scacchiera.stampa();

                break;
            }
            default:{
                printf("\nOpzione non valida, per favore riprovare!");
                break;
            }
        }
    } while (scelta != 0);

    return 0;
}
