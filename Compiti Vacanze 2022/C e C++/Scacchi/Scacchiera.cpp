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
    char colorePedina = scacchiera[riga][colonna][0];
    char idPedina = scacchiera[riga][colonna][1];
    switch (idPedina) {
        case 'P':{
            Pedone pedone(colorePedina);
            if (!pedone.sposta(riga, colonna, rigaDestinazione, colonnaDestinazione, scacchiera)) {
                return false;
            }
            break;
        }
        case 'C':{
            Cavallo cavallo(colorePedina);
            if (!cavallo.sposta(riga, colonna, rigaDestinazione, colonnaDestinazione, scacchiera)) {
                return false;
            }
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
            if (!torre.sposta(riga, colonna, rigaDestinazione, colonnaDestinazione, scacchiera)) {
                return false;
            }
            break;
        }
        case 'D':{
            Donna donna(colorePedina);
            if (!donna.sposta(riga, colonna, rigaDestinazione, colonnaDestinazione, scacchiera)) {
                return false;
            }
            break;
        }
        case 'R':{
            Re re(colorePedina);
            if (!re.sposta(riga, colonna, rigaDestinazione, colonnaDestinazione, scacchiera)) {
                return false;
            }
            break;
        }
        default: {
            printf("\nLa pedina non e' valida.\n");
            return false;
        }
    }
    // Controlla se destinazione occupata da pedina di colore diverso
    if (scacchiera[rigaDestinazione][colonnaDestinazione] != "[  ]") {
        char colorePedinaDestinazione = scacchiera[rigaDestinazione][colonnaDestinazione][0];
        if (colorePedinaDestinazione != colorePedina) {
            printf("\nPedina avversaria eliminata: %s\n", scacchiera[rigaDestinazione][colonnaDestinazione].c_str());
        }
    }
    string idCompletoFinale;
    idCompletoFinale += colorePedina;
    idCompletoFinale += idPedina;
    rimuoviPedina(riga, colonna);
    posizionaPedina(rigaDestinazione, colonnaDestinazione, idCompletoFinale);
    return true;
}
