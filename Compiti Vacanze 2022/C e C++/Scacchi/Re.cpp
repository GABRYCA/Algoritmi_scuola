//
// Created by gabry on 23/06/2022.
//

#include "Re.h"
#include <iostream>
#include <string>

using namespace std;

Re::Re(char colore) {
    this->colore = colore;
}

void Re::stampa() {
    cout << "Re " << getIDCompleto() << endl;
}

char Re::getColore() {
    return colore;
}

char Re::getID() {
    return id;
}

string Re::getIDCompleto() {
    return string() + colore + id;
}

bool Re::sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera) {
    // Verifico che la destinazione non sia distante più di una casella dalla posizione iniziale
    if (rigaDestinazione - riga > 1 || colonnaDestinazione - colonna > 1 || riga - rigaDestinazione > 1 || colonna - colonnaDestinazione > 1){
        printf("\nIl re può muoversi solo di una casella in ogni direzione.\n");
        return false;
    }
    // Verifico che la destinazione non sia occupata da una pedina alleata o avversaria
    if (scacchiera[rigaDestinazione][colonnaDestinazione] != "[  ]"){
        // Verifico se dello stesso colore o meno
        if (scacchiera[rigaDestinazione][colonnaDestinazione][0] == colore){
            printf("\nLa casella di destinazione è già occupata da una pedina alleata.\n");
            return false;
        } else {
            printf("\nLa casella di destinazione è occupata da una pedina avversaria.\n");
        }
    }

    return true;
}
