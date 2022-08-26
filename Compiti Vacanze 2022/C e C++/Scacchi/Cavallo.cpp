//
// Created by gabry on 23/06/2022.
//

#include "Cavallo.h"
#include <iostream>
#include <string>

using namespace std;

Cavallo::Cavallo(char colore) {
    this->colore = colore;
}

void Cavallo::stampa() {
    cout << "Cavallo " << getIDCompleto() << endl;
}

char Cavallo::getColore() {
    return colore;
}

char Cavallo::getID() {
    return id;
}

string Cavallo::getIDCompleto() {
    return string() +  colore + id;
}

bool Cavallo::sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera) {
    // Controllo se la differenza di X e' pari a 2 e quella di Y pari a 1 oppure la Y e' pari a 2 e X e' 1.
    if ((abs(rigaDestinazione - riga) == 2 && abs(colonnaDestinazione - colonna) == 1) || (abs(rigaDestinazione - riga) == 1 && abs(colonnaDestinazione - colonna) == 2)){
        if (scacchiera[rigaDestinazione][colonnaDestinazione][1] == colore){
            printf("\nLa casella di destinazione e' già occupata da una pedina alleata.\n");
            return false;
        }
        return true;
    } else {
        printf("\nLa posizione di destinazione non e' valida (Devi muoverti a L secondo i limiti con il cavallo).\n");
        return false;
    }
}
