//
// Created by gabry on 23/06/2022.
//

#include <string>

using namespace std;

#ifndef SCACCHI_TORRE_H
#define SCACCHI_TORRE_H


class Torre {
public:
    Torre(char colore);
    void stampa();
    char getColore();
    char getID();
    string getIDCompleto();

    bool sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera);

private:
    char id = 'T';
    char colore;
};


#endif //SCACCHI_TORRE_H
