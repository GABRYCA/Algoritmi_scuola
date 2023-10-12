//
// Created by gabry on 23/06/2022.
//

#include <string>

using namespace std;

#ifndef SCACCHI_DONNA_H
#define SCACCHI_DONNA_H


class Donna {
public:
    Donna(char colore);
    void stampa();
    char getColore();
    char getID();
    string getIDCompleto();

    bool sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera);

private:
    char id = 'D';
    char colore;
};


#endif //SCACCHI_DONNA_H
