#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

void continua();

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           FILE V. di G.C. 3BITI              //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;

    FILE *cfPtr;

    while (scelta != 0){

        printf("\nLegenda: "
               "\n0 -> Esci."
               "\n1 -> Leggi numeri nel FILE voti.txt."
               "\n2 -> Calcola media dei numeri."
               "\n3 -> Media e numero di numeri in range 10 per cento."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\n\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Lettura FILE voti.txt");

                cfPtr = fopen("voti.txt", "r");

                if (cfPtr != NULL){

                    printf("\nLettura FILE: ");

                    int numeroLetto;
                    while (!feof(cfPtr)){

                        fscanf(cfPtr, "%d", &numeroLetto);
                        printf("\n- %d", numeroLetto);

                    }

                    printf("\nFINE LETTURA!");

                } else {

                    printf("\nIl FILE non esiste!");

                }
                fclose(cfPtr);

                continua();
                break;
            }

            case 2:{

                printf("\nHai scelto: Lettura media dei numeri nel FILE.");

                cfPtr = fopen("voti.txt", "r");

                if (cfPtr != NULL){

                    printf("\nLettura FILE in corso...\n");

                    int numeroLetto, totale = 0, nNumeriLetti = 0;
                    while (!feof(cfPtr)){
                        fscanf(cfPtr, "%d", &numeroLetto);
                        totale = numeroLetto + totale;
                        nNumeriLetti++;
                    }

                    printf("\nMEDIA: %d", totale / nNumeriLetti);
                    printf("\nFINE LETTURA!");

                } else {

                    printf("\nIl FILE non esiste!");

                }
                fclose(cfPtr);

                continua();
                break;
            }

            case 3:{

                printf("\nHai scelto: Media e 10 per cento RANGE numero numeri...");

                cfPtr = fopen("voti.txt", "r");

                int media;
                if (cfPtr != NULL){

                    printf("\nLettura FILE in corso...\n");

                    int numeroLetto, totale = 0, nNumeriLetti = 0;
                    while (!feof(cfPtr)){
                        fscanf(cfPtr, "%d", &numeroLetto);
                        totale = numeroLetto + totale;
                        nNumeriLetti++;
                    }

                    media = totale / nNumeriLetti;
                    printf("\nMEDIA: %d", media);
                    fclose(cfPtr);

                    cfPtr = fopen("voti.txt", "r");
                    int rangeMax = (media / 100) * 10 + media, rangeMin = media - (media / 100) * 10, nNumeriInRange = 0;
                    while (!feof(cfPtr)){
                        fscanf(cfPtr, "%d", &numeroLetto);
                        if (numeroLetto > rangeMin && numeroLetto < rangeMax){
                            nNumeriInRange++;
                        }
                    }

                    printf("\nI numeri in range sono: %d", nNumeriInRange);

                } else {

                    printf("\nIl FILE non esiste!");

                }
                fclose(cfPtr);


                continua();
                break;
            }

            default:{

                printf("\nScelta non valida, riprovare!");

                continua();
                break;
            }
        }

    }

    printf("\nUscito con successo!");

    return 0;
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\n|--------------------------"
           "\n| Inserisci un NUMERO a caso per continuare...");
    scanf("%d", &inusato);
    printf("|--------------------------\n");

}