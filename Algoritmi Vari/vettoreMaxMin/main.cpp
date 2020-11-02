#include <iostream>
#include <stdio.h>

int main() {

    printf("\nHai scelto: Generea x numeri casuali compresi in un intervallo e mostra il MAGGIORE e MINORE.");

    int max, min, nNum, contatore1 = 0, maxTrovato, minTrovato;

    printf("\nInserire numero massimo: ");
    scanf("%d", &max);
    printf("\nInserire numero minimo: ");
    scanf("%d", &min);
    printf("\nInserire QUANTI NUMERI generare: ");
    scanf("%d", &nNum);

    int numeriGenerati[nNum];

    numeriGenerati[contatore1] = rand() % (max - (min) + 1) + (min);

    maxTrovato = numeriGenerati[contatore1];
    minTrovato = numeriGenerati[contatore1];

    while (contatore1 < nNum){

        contatore1++;

        numeriGenerati[contatore1] = rand() % (max - (min) + 1) + (min);

        if (numeriGenerati[contatore1] > maxTrovato){
            maxTrovato = numeriGenerati[contatore1];
        } else if (numeriGenerati[contatore1] < minTrovato){
            minTrovato = numeriGenerati[contatore1];
        }
    }

    printf("Il numero maggiore trovato è %d e il minore %d", maxTrovato, minTrovato);

    return 0;
}
