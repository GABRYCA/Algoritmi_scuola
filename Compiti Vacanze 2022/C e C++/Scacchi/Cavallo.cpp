//
// Created by gabry on 23/06/2022.
//

#include "Cavallo.h"
#include <iostream>
#include <string>

using namespace std;

Cavallo::Cavallo(string colore) {
    this->colore = colore;
}

void Cavallo::stampa() {
    cout << "Cavallo " << getIDCompleto() << endl;
}

string Cavallo::getColore() {
    return colore;
}

string Cavallo::getID() {
    return id;
}

string Cavallo::getIDCompleto() {
    return colore + id;
}
