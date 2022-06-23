//
// Created by gabry on 23/06/2022.
//

#include "Re.h"
#include <iostream>
#include <string>

using namespace std;

Re::Re(string colore) {
    this->colore = colore;
}

void Re::stampa() {
    cout << "Re " << getIDCompleto() << endl;
}

string Re::getColore() {
    return colore;
}

string Re::getID() {
    return id;
}

string Re::getIDCompleto() {
    return colore + id;
}
