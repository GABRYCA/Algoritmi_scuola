//
// Created by gabry on 23/06/2022.
//

#include "Torre.h"
#include <iostream>
#include <string>

using namespace std;

Torre::Torre(char colore) {
    this->colore = colore;
}

void Torre::stampa() {
    cout << "Torre " << getIDCompleto() << endl;
}

char Torre::getColore() {
    return colore;
}

char Torre::getID() {
    return id;
}

string Torre::getIDCompleto() {
    return string() + colore + id;
}

bool Torre::sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera) {
    // Verifico che la posizione iniziale e la destinazione siano in verticale o orizzontale
    if (!(riga == rigaDestinazione || colonna == colonnaDestinazione)) {
        printf("\nLa torre può muoversi solo in verticale o orizzontale.\n");
        return false;
    }
    // Verifico se tra la posizione iniziale e la destinazione ci sono pedine.
    if (riga == rigaDestinazione) { // Mi sto spostando in verticale.
        // Verifico se muovendomi verso sinistra in verticale ci sono pedine
        if (colonna < colonnaDestinazione) {
            for (int i = colonna + 1; i < colonnaDestinazione; i++) {
                if (scacchiera[riga][i] != "[  ]") {
                    // Controllo colore pedina.
                    if (scacchiera[riga][i][0] == colore) {
                        printf("\nNon puo muoversi in verticale se ci sono pedine alleate tra la posizione iniziale e la destinazione.\n");
                    } else {
                        printf("\nTrovata pedina avversaria in verticale, devi eleminarla per andare alla destinazione inserita.\n");
                    }
                    return false;
                }
            }
        } else { // Mi sto spostando in verticale verso destra.
            for (int i = colonna - 1; i > colonnaDestinazione; i--) {
                if (scacchiera[riga][i] != "[  ]") {
                    // Controllo colore pedina.
                    if (scacchiera[riga][i][0] == colore) {
                        printf("\nNon puo muoversi in verticale se ci sono pedine alleate tra la posizione iniziale e la destinazione.\n");
                    } else {
                        printf("\nTrovata pedina avversaria in verticale, devi eleminarla per andare alla destinazione inserita.\n");
                    }
                    return false;
                }
            }
        }
    } else if (colonna == colonnaDestinazione) { // Mi sto spostando in orizzontale.
        // Verifico se muovendomi in basso in verticale ci sono pedine
        if (riga < rigaDestinazione) {
            for (int i = riga + 1; i < rigaDestinazione; i++) {
                if (scacchiera[i][colonna] != "[  ]") {
                    // Controllo colore pedina.
                    if (scacchiera[i][colonna][0] == colore) {
                        printf("\nNon puo muoversi in orizzontale se ci sono pedine alleate tra la posizione iniziale e la destinazione.\n");
                    } else {
                        printf("\nTrovata pedina avversaria in orizzontale, devi eleminarla per andare alla destinazione inserita.\n");
                    }
                    return false;
                }
            }
        } else { // Mi sto spostando in alto in verticale.
            for (int i = riga - 1; i > rigaDestinazione; i--) {
                if (scacchiera[i][colonna] != "[  ]") {
                    // Controllo colore pedina.
                    if (scacchiera[i][colonna][0] == colore) {
                        printf("\nNon puo muoversi in orizzontale se ci sono pedine alleate tra la posizione iniziale e la destinazione.\n");
                    } else {
                        printf("\nTrovata pedina avversaria in orizzontale, devi eleminarla per andare alla destinazione inserita.\n");
                    }
                    return false;
                }
            }
        }
    }

    return true;
}
