#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <utility>
#include <conio.h>
#include <windows.h>
#include "graphics/graphics.h"

using namespace std;

bool inputBool();
void ordinaCilindri(int num, int A, int B, int C);
void ordinaCilindriGrafico(int num, int A, int B, int C);
void ordinaCilindriGrafico2(int num, int A, int B, int C);
void graficaVettoriAttuale();
void graficaVettoriAttuale2();
void resetVett();
void setColonnaABase(int nCilindri);
int posCilCimaVet(int nVet);

bool pausaClick = false;
int delay = 100, nCilindriG = 0;
int vet[100][3] = {0};

// Coordinate dinamiche:
int unita = 40;

// Coordinate fisse:
int xSinRet = 2 * unita, ySinRet = 11 * unita, xDesRet = 16 * unita, yDesRet = 9 * unita; // Rettangolo.
int xBasAst1 = 4 * unita, yBasAst1 = 9 * unita, xCimAst1 = 4 * unita, yCimAst1 = 1 * unita; // Asta 1.
int xBasAst2 = 9 * unita, yBasAst2 = 9 * unita, xCimAst2 = 9 * unita, yCimAst2 = 1 * unita; // Asta 2.
int xBasAst3 = 14 * unita, yBasAst3 = 9 * unita, xCimAst3 = 14 * unita, yCimAst3 = 1 * unita; // Asta 3.

int main() {

    printf("\n\nBenvenuto nell'Haloi di G.C. 4BITI");

    int scelta;

    do{

        printf("\n\nEcco una lista delle scelte disponibili: "
               "\n0 -> Esci."
               "\n1 -> Hanoi."
               "\n2 -> Hanoi grafico."
               "\n3 -> Hanoi grafics.h"
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

            case 3:{

                printf("\n\nHai scelto: Hanoi graphics.h...");

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

                if (!pausaClick){
                    printf("\nInserire un delay in millisecondi (default 100ms): ");
                    scanf("%d", &delay);
                }

                printf("\nNumero cilindri: %d. "
                       "\nInizio...", nCilindri);

                Sleep(delay);
                graficaVettoriAttuale2();
                ordinaCilindriGrafico2(nCilindri, 0, 1, 2);

                printf("\nFine.");
                Sleep(delay * 5);

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

void ordinaCilindriGrafico2(int num, int A, int B, int C){
    if (num == 1){
        // Sposta cilindro in cima.
        vet[posCilCimaVet(A)][A] = 0;
        vet[posCilCimaVet(B) + 1][B] = 1;
        if (!pausaClick) {
            Sleep(delay);
        }
        // Mostrare qui grafica.
        graficaVettoriAttuale2();
        return;
    }
    ordinaCilindriGrafico2(num - 1, A, C, B);
    // Sposta cilindro in cima.
    vet[posCilCimaVet(A)][A] = 0;
    vet[posCilCimaVet(B) + 1][B] = num;
    if (!pausaClick) {
        Sleep(delay);
    }
    // Mostrare qui grafica.
    graficaVettoriAttuale2();
    ordinaCilindriGrafico2(num - 1, C, B, A);
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

void graficaVettoriAttuale2(){

    system("CLS");

    // Rettangolo alla base
    rettangolo(xSinRet, ySinRet, xDesRet, yDesRet, bianco, true);

    // Aste
    linea(xBasAst1, yBasAst1, xCimAst1, yCimAst1, rosso);
    linea(xBasAst2, yBasAst2, xCimAst2, yCimAst2, rosso);
    linea(xBasAst3, yBasAst3, xCimAst3, yCimAst3, rosso);

    int dimUnitaCilOriz = (xDesRet - xSinRet) / (nCilindriG * 1.5);
    int dimUnitaCilVert = (yBasAst1 - yCimAst1) / (nCilindriG * 1);

    for (int i = 0; i < 3; i++) {

        int yCil = yBasAst1;
        int xCilCentro;
        if (i == 0){
            xCilCentro = xBasAst1;
        } else if (i == 1){
            xCilCentro = xBasAst2;
        } else if (i == 2){
            xCilCentro = xBasAst3;
        }

        for (int j = 0; j < nCilindriG; j++) {
            if (vet[j][i] != 0) {
                int xDestraSinistraOffset = (vet[j][i] * dimUnitaCilOriz) / 5;
                rettangolo(xCilCentro - xDestraSinistraOffset, yCil, xCilCentro + xDestraSinistraOffset, yCil - dimUnitaCilVert, arancione, false);
            }
            yCil -= dimUnitaCilVert;
        }
    }
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