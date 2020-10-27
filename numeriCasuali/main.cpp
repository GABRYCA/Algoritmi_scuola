#include <iostream>
#include <stdio.h>
#include <time.h>

int main() {

    printf("Hai scelto: Algoritmo dei numeri casuali...\n");

    // Ottengo TANTI dall'utente
    int TANTI;
    printf("\nInserire quanti numeri CASUALI vuoi trovare: ");
    scanf("%d", &TANTI);

    // Ottengo MAX dall'utente
    int MAX;
    printf("Inserire il valore massimo che vuoi possano assumere: ");
    scanf("%d", &MAX);

    int mioVettore[TANTI];
    srand(time(0));

    // Generatore numeri casuali
    for (int conta = 0; conta < TANTI; conta++) {
        // Ottengo un valore casuale compreso tra 0 e MAX
        mioVettore[conta] = (rand() % MAX);
    }

    // Visualizzatore risultati
    printf("\nI numeri generati sono: \n");
    for (int conta = 0; conta < TANTI; conta++) {

        // Scrivo il risultato
        printf("%d \t", mioVettore[conta]);

    }
    return 0;
}
