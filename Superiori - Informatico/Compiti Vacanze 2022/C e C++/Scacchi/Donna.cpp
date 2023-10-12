//
// Created by gabry on 23/06/2022.
//

#include "Donna.h"
#include "Alfiere.h"
#include "Torre.h"
#include <iostream>
#include <string>

using namespace std;

Donna::Donna(char colore) {
    this->colore = colore;
}

void Donna::stampa() {
    cout << "Donna " << getIDCompleto() << endl;
}

char Donna::getColore() {
    return colore;
}

char Donna::getID() {
    return id;
}

string Donna::getIDCompleto() {
    return string() + colore + id;
}

bool Donna::sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera) {
    // Verifico che la posizione iniziale e la destinazione siano in verticale o orizzontale
    if (!((riga == rigaDestinazione || colonna == colonnaDestinazione) || !(rigaDestinazione - riga == colonnaDestinazione - colonna || rigaDestinazione - riga == colonna - colonnaDestinazione))) {
        printf("\nLa donna puo' muoversi solo in diagonale, orizzontale o verticale.\n");
        return false;
    }
    if (riga == rigaDestinazione || colonna == colonnaDestinazione){ // Se mi sto spostando in verticale o orizzontale.
        Torre torre(colore);
        if (!torre.sposta(riga, colonna, rigaDestinazione, colonnaDestinazione, scacchiera)){
            return false;
        }
    } else if (rigaDestinazione - riga == colonnaDestinazione - colonna || rigaDestinazione - riga == colonna - colonnaDestinazione){ // Se mi sto muovendo in diagonale.
        Alfiere alfiere(colore);
        if (!alfiere.sposta(riga, colonna, rigaDestinazione, colonnaDestinazione, scacchiera)){
            return false;
        }
    }
    return true;
}
