#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

void continua();

int randomMaxMin(int numeroMin, int numeroMax);

void nomiCarte(int numero, int tipo);


struct carteGiocatore{
    // Numero Carta, Tipo, Punti (valore della carta).
    int mano[5][3];
    int numeroCarte = 0;
};

void daiCartaGiocatore(carteGiocatore *giocatori, int numeroGiocatore);

int carte[52][4] = {
        {1,1,0},
        {1,2,0},
        {1,3,0},
        {1,4,0},
        {1,5,0},
        {1,6,0},
        {1,7,0},
        {1,8,0},
        {1,9,0},
        {1,10,0},
        {1,11,0},
        {1,12,0},
        {1,13,0},
        {2,1,0},
        {2,2,0},
        {2,3,0},
        {2,4,0},
        {2,5,0},
        {2,6,0},
        {2,7,0},
        {2,8,0},
        {2,9,0},
        {2,10,0},
        {2,11,0},
        {2,12,0},
        {2,13,0},
        {3,1,0},
        {3,2,0},
        {3,3,0},
        {3,4,0},
        {3,5,0},
        {3,6,0},
        {3,7,0},
        {3,8,0},
        {3,9,0},
        {3,10,0},
        {3,11,0},
        {3,12,0},
        {3,13,0},
        {4,1,0},
        {4,2,0},
        {4,3,0},
        {4,4,0},
        {4,5,0},
        {4,6,0},
        {4,7,0},
        {4,8,0},
        {4,9,0},
        {4,10,0},
        {4,11,0},
        {4,12,0},
        {4,13,0},
};

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           BlackJack di Gabriele Caretti 3BITI            //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;
    while (scelta != 0){

        printf("\n\nLegenda:"
               "\n0 -> Esci."
               "\n1 -> Blackjack."
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

                int puntata, numeroGiocatori;
                printf("\nNumero giocatori: ");
                scanf("%d", &numeroGiocatori);

                int puntataGiocatori[numeroGiocatori];

                for (int i = 0; i < numeroGiocatori; i++) {
                    bool puntataValida = false;
                    while (!puntataValida){
                        printf("\nInserire quanto vuoi scommettere giocatore N.%d: ", i + 1);
                        scanf("%d", &puntataGiocatori[i]);
                        if (puntataGiocatori[i] > 0){
                            puntataValida = true;
                            printf("\nGiocatore %d ha puntato %d.\n", i + 1, puntataGiocatori[i]);
                        } else {
                            printf("\nHai scommesso una cifra non valida, per favore riprovare!");
                        }
                    }
                }

                srand(time(0));

                // Carte da 1 a re e da fiori a picche, struttura: TipoCarta, Numero, inUso (0 se no, 1 se si).
                // Reset carte utilizzate.
                for (int i = 0; i < 52; i++) {
                    carte[i][2] = 0;
                }

                printf("\n\nInizia il gioco, mischiando le carte...");
                // Mischio le carte per la prima volta
                for (int i=0; i<52; i++){
                    int numeroACaso = randomMaxMin(0, 51);
                    for (int j = 0; j < 2; j++){
                        int valCarta1 = carte[i][j];
                        carte[i][j] = carte[numeroACaso][j];
                        carte[numeroACaso][j] = valCarta1;
                    }
                }
                printf("\n\nCarte mischiate con successo!");

                carteGiocatore giocatori[numeroGiocatori];
                carteGiocatore banco;

                // Aggiungo carta a giocatore.

                for (int i = 0; i < numeroGiocatori; i++) {
                    daiCartaGiocatore(giocatori, i);
                }


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

void daiCartaGiocatore(carteGiocatore *giocatori, int numeroGiocatore) {

    // Manca assegnazione punti delle carte senza valori particolari.

    if (giocatori[numeroGiocatore].numeroCarte < 5) {
        bool cartaValidaAggiunta = false;
        while (!cartaValidaAggiunta) {
            int tipoCarta = randomMaxMin(0, 51);
            if (carte[tipoCarta][2] == 0) {
                cartaValidaAggiunta = true;
                carte[tipoCarta][2] = 1;
                giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte][0] = carte[tipoCarta][0];
                giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte][1] = carte[tipoCarta][1];
                if (carte[tipoCarta][1] == 1){
                    bool sceltaPuntiValida = false;
                    while (!sceltaPuntiValida) {
                        int sceltaPunti;
                        printf("\nQuesta carta puo' valere sia 1 che 11 (Asso), scegliere"
                               "\n0 -> 1."
                               "\n1 -> 11."
                               "\nScelta: ");
                        scanf("%d", &sceltaPunti);
                        if (sceltaPunti == 1 || sceltaPunti == 0){
                            if (sceltaPunti == 1) {
                                giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte][2] = 11;
                            } else {
                                giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte][2] = 1;
                            }
                            sceltaPuntiValida = true;
                        } else {
                            printf("\nScelta non valida, per favore riprovare.");
                        }
                    }
                } else if (carte[tipoCarta][1] > 10){
                    giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte][2] = 10;
                } else {
                    giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte][2] = carte[tipoCarta][1];
                }
                giocatori[numeroGiocatore].numeroCarte++;
            }
        }
        printf("\n\nHai ricevuto uan carta giocatore N.%d,"
               "\nLa carta vale %d punti."
               "\nLa carta e' una: ", numeroGiocatore + 1, giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte - 1][2]);
        nomiCarte(giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte - 1][1], giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte - 1][0]);
    } else {
        printf("\nIl giocatore ha gia' raggiunto il numero massimo di carte.");
    }
}

int randomMaxMin(int numeroMin, int numeroMax) {
    return rand() % (numeroMax - numeroMin + 1) + numeroMin;
}

void nomiCarte(int numero, int tipo) {

    string carta;

    if (numero == 1){

        carta = "Asso";

    } else if (numero == 11){

        carta = "Jack";

    } else if (numero == 12){

        carta = "Regina";

    } else if (numero == 13){

        carta = "Re";

    } else {

        carta = to_string(numero);

    }

    carta = carta + " di ";

    switch (tipo) {
        case 1:{

            carta = carta + "Fiori";

            break;
        }
        case 2:{

            carta = carta + "Quadri";

            break;
        }
        case 3:{

            carta = carta + "Cuori";

            break;
        }
        case 4:{

            carta = carta + "Picche";

            break;
        }
        default:{

            carta = carta + "Sconosciuto";

            break;
        }
    }
    printf("%s", carta.c_str());
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}
