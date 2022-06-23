//
// Created by gabry on 23/06/2022.
//

#include "Scacchiera.h"
#include "Alfiere.h"
#include "Pedone.h"
#include "Cavallo.h"
#include "Torre.h"
#include "Donna.h"
#include "Re.h"
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
    printf("\n");
    for (int i = 0; i < colonne; i++){
        cout << "    " << i + 1;
    }
    printf("\n _");
    for (int i = 0; i < colonne; ++i) {
        cout << "_____";
    }
    printf("\n");
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (j == 0) {
                cout << i + 1 << "| ";
            }
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

bool Scacchiera::spostaPedina(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione) {
    if (riga < 0 || riga >= righe || colonna < 0 || colonna >= colonne) {
        printf("\nLa posizione iniziale non e' valida.\n");
        return false;
    }
    if (rigaDestinazione < 0 || rigaDestinazione >= righe || colonnaDestinazione < 0 || colonnaDestinazione >= colonne) {
        printf("\nLa posizione finale non e' valida.\n");
        return false;
    }
    if (riga == rigaDestinazione && colonna == colonnaDestinazione) {
        printf("\nLa posizione iniziale e' uguale a quella finale.\n");
        return false;
    }
    if (scacchiera[riga][colonna] == "[  ]") {
        printf("\nNon c'è nessuna pedina in questa posizione.\n");
        return false;
    }
    string colorePedina = scacchiera[riga][colonna].substr(1, 1);
    string idPedina = scacchiera[riga][colonna].substr(1, 2);

    switch (idPedina[0]) {
        case 'P':{
            Pedone pedone(colorePedina);
            break;
        }
        case 'C':{
            Cavallo cavallo(colorePedina);
            break;
        }
        case 'A':{
            Alfiere alfiere(colorePedina);
            if (!alfiere.sposta(riga, colonna, rigaDestinazione, colonnaDestinazione, scacchiera)) {
                return false;
            }
            break;
        }
        case 'T':{
            Torre torre(colorePedina);
            break;
        }
        case 'D':{
            Donna donna(colorePedina);
            break;
        }
        case 'R':{
            Re re(colorePedina);
            break;
        }
    }
    // Controlla se destinazione occupata da pedina di colore diverso
    if (scacchiera[rigaDestinazione][colonnaDestinazione] != "[  ]") {
        string colorePedinaDestinazione = scacchiera[rigaDestinazione][colonnaDestinazione].substr(1, 1);
        if (colorePedinaDestinazione != colorePedina) {
            printf("\nPedina avversaria eliminata: %s\n", scacchiera[rigaDestinazione][colonnaDestinazione].c_str());
        }
    }
    rimuoviPedina(riga, colonna);
    posizionaPedina(rigaDestinazione, colonnaDestinazione, colorePedina + idPedina);
    return true;
}
