//
// Created by gabry on 23/06/2022.
//

#include <string>

using namespace std;

#ifndef SCACCHI_CAVALLO_H
#define SCACCHI_CAVALLO_H


class Cavallo {
public:
    Cavallo(char colore);
    void stampa();
    char getColore();
    char getID();
    string getIDCompleto();

    bool sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera);

private:
    char id = 'C';
    char colore;
};


#endif //SCACCHI_CAVALLO_H
