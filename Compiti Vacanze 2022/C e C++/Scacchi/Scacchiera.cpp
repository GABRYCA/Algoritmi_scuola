//
// Created by gabry on 23/06/2022.
//

#include "Scacchiera.h"
#include <iostream>
#include <string>

using namespace std;

Scacchiera::Scacchiera(int righe, int colonne) {
    this->righe = righe;
    this->colonne = colonne;
    scacchiera = new string *[righe];
    for (int i = 0; i < righe; i++) {
        scacchiera[i] = new string[colonne];
        for (int j = 0; j < colonne; j++) {
            scacchiera[i][j] = "[  ]";
        }
    }
}

void Scacchiera::stampa() {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            cout << scacchiera[i][j] << " ";
        }
        cout << endl;
    }
}

void Scacchiera::posizionaPedina(int riga, int colonna, string idPedina) {
    scacchiera[riga][colonna] = "[" + idPedina + "]";
}

void Scacchiera::rimuoviPedina(int riga, int colonna) {
    scacchiera[riga][colonna] = "[  ]";
}
