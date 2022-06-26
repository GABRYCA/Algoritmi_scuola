//
// Created by gabry on 23/06/2022.
//

#include "Pedone.h"
#include <iostream>
#include <string>

using namespace std;

Pedone::Pedone(char colore) {
    this->colore = colore;
}

void Pedone::stampa() {
    cout << "Pedone " << getIDCompleto() << endl;
}

char Pedone::getColore() {
    return colore;
}

char Pedone::getID() {
    return id;
}

string Pedone::getIDCompleto() {
    return string() + colore + id;
}

bool Pedone::sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera) {
    // Verifico che la destinazione non sia distante più di una casella dalla posizione iniziale
    if (rigaDestinazione - riga > 1 || colonnaDestinazione - colonna > 1 || riga - rigaDestinazione > 1 || colonna - colonnaDestinazione > 1){
        printf("\nIl pedone puo' muoversi solo di una casella in ogni direzione.\n");
        return false;
    }

    // Controllo se la destinazione in diagonale è occupata da una pedina avversaria
    if (rigaDestinazione - riga == 1 && colonnaDestinazione - colonna == 1){
        if (scacchiera[rigaDestinazione][colonnaDestinazione] != "[  ]"){
            if (scacchiera[rigaDestinazione][colonnaDestinazione][1] != colore){
                printf("\nLa casella di destinazione è occupata da una pedina avversaria.\n");
                return true;
            } else {
                printf("\nLa casella di destinazione è già occupata da una pedina alleata.\n");
                return false;
            }
        } else {
            printf("\nIl pedone puo' muoversi in diagonale solo per eliminare pedine avversarie.\n");
            return false;
        }
    }

    // Controllo se la destinazione in orizzontale o verticale è occupata da una pedina avversaria
    if (rigaDestinazione == riga || colonnaDestinazione == colonna){
        if (scacchiera[rigaDestinazione][colonnaDestinazione] != "[  ]"){
            if (scacchiera[rigaDestinazione][colonnaDestinazione][1] != colore){
                printf("\nLa casella di destinazione è occupata da una pedina avversaria e puoi eliminarla solo in diagonale.\n");
                return false;
            } else {
                printf("\nLa casella di destinazione è già occupata da una pedina alleata.\n");
                return false;
            }
        }
    }
    return true;
}
