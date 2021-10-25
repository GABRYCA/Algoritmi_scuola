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

void ordinaCilindriGrafico(int num, int A, int B, int C);

void graficaVettoriAttuale();

void resetVett();

void setColonnaABase(int nCilindri);

int posCilCimaVet(int nVet);

bool pausaClick;
int delay = 100, nCilindriG = 0;
int vet[100][3] = {0};

int main() {

    printf("\n\nBenvenuto nell'Haloi di G.C. 4BITI");

    int scelta;

    do{

        printf("\n\nEcco una lista delle scelte disponibili: "
               "\n0 -> Esci."
               "\n1 -> Hanoi."
               "\n2 -> Hanoi grafico."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0:{

                printf("\n\nHai scelto esci...");

                break;
            }

            case 1:{

                printf("\n\nHai scelto: Hanoi numerico...");

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

                printf("\nCompletato con successo.");
                break;
            }

            case 2:{

                printf("\n\nHai scelto: Hanoi grafico...");

                int nCilindri;
                do {

                    printf("\n\nInserire il numero di cilindri: ");
                    scanf("%d", &nCilindri);

                    if (nCilindri == 0){
                        printf("\nPer favore inserire un valore maggiore di 0.");
                    }

                } while (nCilindri <= 0);

                nCilindriG = nCilindri;

                // Resetta il vettore e setta la variabile globale del numero di cilindri a quella inserita dall'utente.
                resetVett();

                setColonnaABase(nCilindri);

                printf("\nposCimaCil VET A %d", posCilCimaVet(0));
                printf("\nposCimaCil VET B %d", posCilCimaVet(1));
                printf("\nposCimaCil VET C %d", posCilCimaVet(2));

                graficaVettoriAttuale();

                printf("\nVuoi un delay oppure una pausa sul click (no per delay, si per pausa)? "
                       "\nScelta: ");
                pausaClick = inputBool();

                if (!pausaClick){
                    printf("\nInserire un delay in millisecondi (default 100ms): ");
                    scanf("%d", &delay);
                }

                printf("\nNumero cilindri: %d.", nCilindri);

                ordinaCilindriGrafico(nCilindri, 0, 1, 2);

                printf("\nFine.");
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

void ordinaCilindriGrafico(int num, int A, int B, int C){
    if (num == 1){
        // Sposta cilindro in cima.
        vet[posCilCimaVet(A)][A] = 0;
        vet[posCilCimaVet(B) + 1][B] = 1;
        printf("\nSpostato disco 1 dalla colonna %d alla colonna %d.", A, B);
        if (!pausaClick) {
            Sleep(delay);
        }
        // Mostrare qui grafica.
        graficaVettoriAttuale();
        return;
    }
    ordinaCilindriGrafico(num - 1, A, C, B);
    // Sposta cilindro in cima.
    vet[posCilCimaVet(A)][A] = 0;
    vet[posCilCimaVet(B) + 1][B] = num;
    printf("\nSpostato disco %d dalla colonna %d alla colonna %d.", num, A, B);
    if (!pausaClick) {
        Sleep(delay);
    }
    // Mostrare qui grafica.
    graficaVettoriAttuale();
    ordinaCilindriGrafico(num - 1, C, B, A);
}

void ordinaCilindri(int num, int A, int B, int C){
    if (num == 1){
        printf("\n Spostato disco 1 dalla colonna %d alla colonna %d", A, B);
        if (!pausaClick) {
            Sleep(delay);
        }
        return;
    }
    ordinaCilindri(num - 1, A, C, B);
    printf("\n Spostato disco %d dalla colonna %d alla colonna %d", num, A, B);
    if (!pausaClick) {
        Sleep(delay);
    }
    ordinaCilindri(num - 1, C, B, A);
}

int posCilCimaVet(int nVet){
    int nVal = -1;
    while (true){
        if (vet[nVal + 1][nVet] != 0){
            nVal++;
        } else {
            return nVal;
        }
    }
}

void graficaVettoriAttuale(){
    for (int i = 0; i < 3; i++) {
        printf("\n\nVet %d: ", i);
        for (int j = 0; j < nCilindriG; j++) {
            if (vet[j][i] != 0) {
                printf("\n%d -> %d", j, vet[j][i]);
            }
        }
    }

    printf("\n");
}

void setColonnaABase(int nCilindri){
    // Imposta i valori del vettore base per la grafica in modo ordinato.
    for (int i = 0; i < nCilindri; i++) {
        vet[i][0] = nCilindri - i;
    }
}

void resetVett(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 100; j++) {
            vet[j][i] = 0;
        }
    }
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