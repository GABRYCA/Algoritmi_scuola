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

bool Alfiere::sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera) {
    // Verifico che la posizione iniziale e quella di destinazione siano in diagonale.
    if (!(rigaDestinazione - riga == colonnaDestinazione - colonna || rigaDestinazione - riga == colonna - colonnaDestinazione)){
        printf("\nL'alfiere può muoversi solo in diagonale.\n");
        return false;
    }
    // Verifico se tra la posizione iniziale e la destinazione ci sono pedine.
    if (riga < rigaDestinazione && colonna < colonnaDestinazione){ // Mi sto spostando in basso a destra.
        // Verifico se in diagonale in basso a destra tra la riga e colonna iniziale e la destinazione ci sono pedine.
        for (int i = riga + 1, j = colonna + 1; i < rigaDestinazione && j < colonnaDestinazione; i++, j++){
            if (scacchiera[i][j] != "[  ]"){
                // Controllo colore pedina.
                if (scacchiera[i][j].substr(1, 1) == colore){
                    printf("\nNon puo muoversi in diagonale se ci sono pedine alleate tra la posizione iniziale e la destinazione.\n");
                } else {
                    printf("\nTrovata pedina avversaria in diagonale, devi eleminarla per andare alla destinazione inserita.\n");
                }
                return false;
            }
        }
    } else if (riga < rigaDestinazione && colonna > colonnaDestinazione){ // Mi sto spostando in basso a sinistra.
        // Verifico se in diagonale in basso a sinistra tra la riga e colonna iniziale e la destinazione ci sono pedine.
        for (int i = riga + 1, j = colonna - 1; i < rigaDestinazione && j > colonnaDestinazione; i++, j--){
            if (scacchiera[i][j] != "[  ]"){
                // Controllo colore pedina.
                if (scacchiera[i][j].substr(1, 1) == colore){
                    printf("\nNon puo muoversi in diagonale se ci sono pedine alleate tra la posizione iniziale e la destinazione.\n");
                } else {
                    printf("\nTrovata pedina avversaria in diagonale, devi eleminarla per andare alla destinazione inserita.\n");
                }
                return false;
            }
        }
    } else if (riga > rigaDestinazione && colonna < colonnaDestinazione){ // Mi sto spostando in alto a destra.
        // Verifico se in diagonale in alto a destra tra la riga e colonna iniziale e la destinazione ci sono pedine.
        for (int i = riga - 1, j = colonna + 1; i > rigaDestinazione && j < colonnaDestinazione; i--, j++){
            if (scacchiera[i][j] != "[  ]"){
                // Controllo colore pedina.
                if (scacchiera[i][j].substr(1, 1) == colore){
                    printf("\nNon puo muoversi in diagonale se ci sono pedine alleate tra la posizione iniziale e la destinazione.\n");
                } else {
                    printf("\nTrovata pedina avversaria in diagonale, devi eleminarla per andare alla destinazione inserita.\n");
                }
                return false;
            }
        }
    } else if (riga > rigaDestinazione && colonna > colonnaDestinazione){ // Mi sto spostando in alto a sinistra.
        // Verifico se in diagonale in alto a sinistra tra la riga e colonna iniziale e la destinazione ci sono pedine.
        for (int i = riga - 1, j = colonna - 1; i > rigaDestinazione && j > colonnaDestinazione; i--, j--){
            if (scacchiera[i][j] != "[  ]"){
                // Controllo colore pedina.
                if (scacchiera[i][j].substr(1, 1) == colore){
                    printf("\nNon puo muoversi in diagonale se ci sono pedine alleate tra la posizione iniziale e la destinazione.\n");
                } else {
                    printf("\nTrovata pedina avversaria in diagonale, devi eleminarla per andare alla destinazione inserita.\n");
                }
                return false;
            }
        }
    }
    return true;
}
