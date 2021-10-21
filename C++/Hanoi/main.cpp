#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <utility>
#include <conio.h>
#include <windows.h>

using namespace std;

bool inputBool();

void ordinaCilindri(int num, int A, int B, int C);

bool pausaClick;
int delay = 100;

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
                do {

                    printf("\n\nInserire il numero di cilindri: ");
                    scanf("%d", &nCilindri);

                    if (nCilindri == 0){
                        printf("\nPer favore inserire un valore maggiore di 0.");
                    }

                } while (nCilindri <= 0);

                printf("\nVuoi un delay oppure una pausa sul click (no per delay, si per pausa)? "
                       "\nScelta: ");
                pausaClick = inputBool();

                if (!pausaClick){
                    printf("\nInserire un delay in millisecondi (default 100ms): ");
                    scanf("%d", &delay);
                }

                printf("\nNumero cilindri: %d.", nCilindri);

                ordinaCilindri(nCilindri, 1, 2, 3);

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

void ordinaCilindri(int num, int A, int B, int C){
    if (num == 1){
        printf("\n Spostato disco 1 dalla colonna %d alla colonna %d", A, B);
        if (!pausaClick) {
            Sleep(100);
        }
        return;
    }
    ordinaCilindri(num - 1, A, C, B);
    printf("\n Spostato disco %d dalla colonna %d alla colonna %d", num, A, B);
    if (!pausaClick) {
        Sleep(100);
    }
    ordinaCilindri(num - 1, C, B, A);
}

bool inputBool(){

    while (true){

        int num;
        printf("\n0 -> No."
               "\n1 -> Si."
               "\nScelta: ");
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