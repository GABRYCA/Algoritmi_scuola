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
        printf("\nLa posizione iniziale non e' valida. [%d %d]\n", riga, colonna);
        return false;
    }
    if (rigaDestinazione < 0 || rigaDestinazione >= righe || colonnaDestinazione < 0 || colonnaDestinazione >= colonne) {
        printf("\nLa posizione finale non e' valida. [%d %d]\n", rigaDestinazione, colonnaDestinazione);
        return false;
    }
    if (riga == rigaDestinazione && colonna == colonnaDestinazione) {
        printf("\nLa posizione iniziale e' uguale a quella finale. [%d %d, %d %d]\n", riga, colonna, rigaDestinazione, colonnaDestinazione);
        return false;
    }
    if (scacchiera[riga][colonna] == "[  ]") {
        printf("\nNon c'è nessuna pedina in questa posizione. [%d %d]\n", riga, colonna);
        return false;
    }
    char colorePedina = scacchiera[riga][colonna][1];
    char idPedina = scacchiera[riga][colonna][2];
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
        char colorePedinaDestinazione = scacchiera[rigaDestinazione][colonnaDestinazione][1];
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

void Scacchiera::reset() {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            scacchiera[i][j] = "[  ]";
        }
    }
}

void Scacchiera::resetDefault() {
    reset();
    Pedone pedoneNero('N');
    Cavallo cavalloNero('N');
    Alfiere alfiereNero('N');
    Torre torreNera('N');
    Donna donnaNera('N');
    Re reNero('N');
    Pedone pedoneBianco('B');
    Cavallo cavalloBianco('B');
    Alfiere alfiereBianco('B');
    Torre torreBianca('B');
    Donna donnaBianca('B');
    Re reBianco('B');
    posizionaPedina(1, 0, pedoneNero.getIDCompleto());
    posizionaPedina(1, 1, pedoneNero.getIDCompleto());
    posizionaPedina(1, 2, pedoneNero.getIDCompleto());
    posizionaPedina(1, 3, pedoneNero.getIDCompleto());
    posizionaPedina(1, 4, pedoneNero.getIDCompleto());
    posizionaPedina(1, 5, pedoneNero.getIDCompleto());
    posizionaPedina(1, 6, pedoneNero.getIDCompleto());
    posizionaPedina(1, 7, pedoneNero.getIDCompleto());
    posizionaPedina(0,0, torreNera.getIDCompleto());
    posizionaPedina(0,1, cavalloNero.getIDCompleto());
    posizionaPedina(0,2, alfiereNero.getIDCompleto());
    posizionaPedina(0,3, donnaNera.getIDCompleto());
    posizionaPedina(0,4, reNero.getIDCompleto());
    posizionaPedina(0,5, alfiereNero.getIDCompleto());
    posizionaPedina(0,6, cavalloNero.getIDCompleto());
    posizionaPedina(0,7, torreNera.getIDCompleto());

    posizionaPedina(6, 0, pedoneBianco.getIDCompleto());
    posizionaPedina(6, 1, pedoneBianco.getIDCompleto());
    posizionaPedina(6, 2, pedoneBianco.getIDCompleto());
    posizionaPedina(6, 3, pedoneBianco.getIDCompleto());
    posizionaPedina(6, 4, pedoneBianco.getIDCompleto());
    posizionaPedina(6, 5, pedoneBianco.getIDCompleto());
    posizionaPedina(6, 6, pedoneBianco.getIDCompleto());
    posizionaPedina(6, 7, pedoneBianco.getIDCompleto());
    posizionaPedina(7,0, torreBianca.getIDCompleto());
    posizionaPedina(7,1, cavalloBianco.getIDCompleto());
    posizionaPedina(7,2, alfiereBianco.getIDCompleto());
    posizionaPedina(7,3, donnaBianca.getIDCompleto());
    posizionaPedina(7,4, reBianco.getIDCompleto());
    posizionaPedina(7,5, alfiereBianco.getIDCompleto());
    posizionaPedina(7,6, cavalloBianco.getIDCompleto());
    posizionaPedina(7,7, torreBianca.getIDCompleto());
}

Scacchiera::~Scacchiera(){
    //printf("\nAzionato distruttore!");
    delete[] scacchiera;
}

int Scacchiera::getNumeroPedoniBianchi() {
    int numeroPedoni = 0;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[BP]") {
                numeroPedoni++;
            }
        }
    }
    return numeroPedoni;
}

int Scacchiera::getNumeroCavalliBianchi() {
    int numeroCavalli = 0;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[BC]") {
                numeroCavalli++;
            }
        }
    }
    return numeroCavalli;
}

int Scacchiera::getNumeroAlfieriBianchi() {
    int numeroAlfieri = 0;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[BA]") {
                numeroAlfieri++;
            }
        }
    }
    return numeroAlfieri;
}

int Scacchiera::getNumeroTorriBianche() {
    int numeroTorri = 0;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[BT]") {
                numeroTorri++;
            }
        }
    }
    return numeroTorri;
}

int Scacchiera::getNumeroDonneBianche() {
int numeroDonne = 0;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[BD]") {
                numeroDonne++;
            }
        }
    }
    return numeroDonne;
}

int Scacchiera::getNumeroReBianchi() {
    int numeroRe = 0;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[BR]") {
                numeroRe++;
            }
        }
    }
    return numeroRe;
}

int Scacchiera::getNumeroPedoniNeri() {
    int numeroPedoni = 0;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[NP]") {
                numeroPedoni++;
            }
        }
    }
    return numeroPedoni;
}

int Scacchiera::getNumeroCavalliNeri() {
    int numeroCavalli = 0;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[NC]") {
                numeroCavalli++;
            }
        }
    }
    return numeroCavalli;
}

int Scacchiera::getNumeroAlfieriNeri() {
    int numeroAlfieri = 0;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[NA]") {
                numeroAlfieri++;
            }
        }
    }
    return numeroAlfieri;
}

int Scacchiera::getNumeroTorriNere() {
    int numeroTorri = 0;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[NT]") {
                numeroTorri++;
            }
        }
    }
    return numeroTorri;
}

int Scacchiera::getNumeroDonneNere() {
    int numeroDonne = 0;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[ND]") {
                numeroDonne++;
            }
        }
    }
    return numeroDonne;
}

int Scacchiera::getNumeroReNeri() {
    int numeroRe = 0;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[NR]") {
                numeroRe++;
            }
        }
    }
    return numeroRe;
}

string Scacchiera::getPedina(int riga, int colonna) {
    return scacchiera[riga][colonna];
}

bool Scacchiera::sottoScaccoReBianco() {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[BR]") {
                if (scaccoReBianco(i, j)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Scacchiera::sottoScaccoReNero() {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (scacchiera[i][j] == "[NR]") {
                if (scaccoReNero(i, j)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Scacchiera::scaccoReBianco(int riga, int colonna) {
    if (scacchiera[riga][colonna] == "[BR]") {
        // Controllo se accanto al re sopra a destra, sinistra, in basso a destra, sinistra c'è un pedone nero o il re nero.
        if (riga - 1 >= 0 && colonna + 1 < colonne && (scacchiera[riga - 1][colonna + 1] == "[NP]" || scacchiera[riga - 1][colonna + 1] == "[NR]")) {
            return true;
        }
    }
    return false;
}

bool Scacchiera::scaccoReNero(int riga, int colonna) {
    if (scacchiera[riga][colonna] == "[NR]") {
        // Controllo se accanto al re sopra a destra, sinistra, in basso a destra, sinistra c'è un pedone bianco o il re bianco.
        if (riga - 1 >= 0 && colonna + 1 < colonne && (scacchiera[riga - 1][colonna + 1] == "[BP]" || scacchiera[riga - 1][colonna + 1] == "[BR]")) {
            return true;
        }
    }
    return false;
}
