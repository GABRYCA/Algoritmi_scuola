//
// Created by gabry on 23/06/2022.
//

#include "Alfiere.h"
#include <iostream>
#include <string>

using namespace std;

Alfiere::Alfiere(string colore) {
    this->colore = colore;
}

void Alfiere::stampa() {
    cout << "Alfiere " << getIDCompleto() << endl;
}

string Alfiere::getColore() {
    return colore;
}

string Alfiere::getID() {
    return id;
}

string Alfiere::getIDCompleto() {
    return colore + id;
}
