//
// Created by gabry on 23/06/2022.
//

#include "Torre.h"
#include <iostream>
#include <string>

using namespace std;

Torre::Torre(string colore) {
    this->colore = colore;
}

void Torre::stampa() {
    cout << "Torre " << getIDCompleto() << endl;
}

string Torre::getColore() {
    return colore;
}

string Torre::getID() {
    return id;
}

string Torre::getIDCompleto() {
    return colore + id;
}
