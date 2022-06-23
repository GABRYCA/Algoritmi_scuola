//
// Created by gabry on 23/06/2022.
//

#include "Donna.h"
#include <iostream>
#include <string>

using namespace std;

Donna::Donna(string colore) {
    this->colore = colore;
}

void Donna::stampa() {
    cout << "Donna " << getIDCompleto() << endl;
}

string Donna::getColore() {
    return colore;
}

string Donna::getID() {
    return id;
}

string Donna::getIDCompleto() {
    return colore + id;
}
