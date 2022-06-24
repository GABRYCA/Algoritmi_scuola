//
// Created by gabry on 23/06/2022.
//

#include "Cavallo.h"
#include <iostream>
#include <string>

using namespace std;

Cavallo::Cavallo(char colore) {
    this->colore = colore;
}

void Cavallo::stampa() {
    cout << "Cavallo " << getIDCompleto() << endl;
}

char Cavallo::getColore() {
    return colore;
}

char Cavallo::getID() {
    return id;
}

string Cavallo::getIDCompleto() {
    return string() +  colore + id;
}

bool Cavallo::sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera) {
    // Controllo se una delle seguenti condizioni rispetto alla posizione iniziale sia valida:
    // 1. La posizione di destinazione deve essere di due caselle in alto e una a sinistra oppure destra.
    // 2. La posizione di destinazione deve essere di due caselle in basso e una a sinistra oppure destra.
    // 3. La posizione di destinazione deve essere di due caselle a sinistra e una in alto oppure in basso.
    // 4. La posizione di destinazione deve essere di due caselle a destra e una in alto oppure in basso.
    if (rigaDestinazione - riga == 2 && colonnaDestinazione - colonna == 1 || rigaDestinazione - riga == 2 && colonna - colonnaDestinazione == 1){
        // Controllo se la posizione finale è occupata da una pedina alleata.
        if (scacchiera[rigaDestinazione][colonnaDestinazione] != "[  ]"){
            // Controllo se la pedina è di colore uguale o diverso.
            if (scacchiera[rigaDestinazione][colonnaDestinazione][0] == colore){
                printf("\nLa casella di destinazione è già occupata da una pedina alleata.\n");
                return false;
            }
        }
        return true;
    } else if (rigaDestinazione - riga == 1 && colonnaDestinazione - colonna == 2 || rigaDestinazione - riga == 1 && colonna - colonnaDestinazione == 2){
        // Controllo se la posizione finale è occupata da una pedina alleata.
        if (scacchiera[rigaDestinazione][colonnaDestinazione] != "[  ]"){
            // Controllo se la pedina è di colore uguale o diverso.
            if (scacchiera[rigaDestinazione][colonnaDestinazione][0] == colore){
                printf("\nLa casella di destinazione è già occupata da una pedina alleata.\n");
                return false;
            }
        }
        return true;
    } else if (rigaDestinazione - riga == 2 && colonnaDestinazione - colonna == 2 || rigaDestinazione - riga == 2 && colonna - colonnaDestinazione == 2){
        // Controllo se la posizione finale è occupata da una pedina alleata.
        if (scacchiera[rigaDestinazione][colonnaDestinazione] != "[  ]"){
            // Controllo se la pedina è di colore uguale o diverso.
            if (scacchiera[rigaDestinazione][colonnaDestinazione][0] == colore){
                printf("\nLa casella di destinazione è già occupata da una pedina alleata.\n");
                return false;
            }
        }
        return true;
    } else if (rigaDestinazione - riga == 1 && colonnaDestinazione - colonna == 1 || rigaDestinazione - riga == 1 && colonna - colonnaDestinazione == 1){
        // Controllo se la posizione finale è occupata da una pedina alleata.
        if (scacchiera[rigaDestinazione][colonnaDestinazione] != "[  ]"){
            // Controllo se la pedina è di colore uguale o diverso.
            if (scacchiera[rigaDestinazione][colonnaDestinazione][0] == colore){
                printf("\nLa casella di destinazione è già occupata da una pedina alleata.\n");
                return false;
            }
        }
        return true;
    } else {
        printf("\nLa posizione di destinazione non è valida (Devi muoverti a L secondo i limiti con il cavallo).\n");
        return false;
    }
}
