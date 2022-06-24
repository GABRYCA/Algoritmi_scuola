#include <iostream>
#include <string>
#include "Scacchiera.h"
#include "Pedone.h"

using namespace std;

// Gioco della scacchiera con tutte le classi e tipi di pedine sotto forma di oggetti
int main() {
    printf("///////////////////"
           "\nLavoro di G.C. 4BITI"
           "\n///////////////////\n");

    // Creo una scacchiera
    Scacchiera scacchiera(8, 8);
    Pedone pedone('B');

    // Posiziono le pedine
    scacchiera.posizionaPedina(0, 0, pedone.getIDCompleto());
    scacchiera.stampa();
    return 0;
}
