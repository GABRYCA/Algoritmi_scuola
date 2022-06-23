//
// Created by gabry on 23/06/2022.
//

#include "Pedone.h"
#include <iostream>
#include <string>

using namespace std;

Pedone::Pedone(string colore) {
    this->colore = colore;
}

void Pedone::stampa() {
    cout << "Pedone " << getIDCompleto() << endl;
}

string Pedone::getColore() {
    return colore;
}

string Pedone::getID() {
    return id;
}

string Pedone::getIDCompleto() {
    return colore + id;
}
