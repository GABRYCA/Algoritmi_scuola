//
// Created by gabry on 23/06/2022.
//

#include <string>

using namespace std;

#ifndef SCACCHI_PEDONE_H
#define SCACCHI_PEDONE_H


class Pedone {
public:
    Pedone(char colore);
    void stampa();
    char getColore();
    char getID();
    string getIDCompleto();

    bool sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera);

private:
    char id = 'P';
    char colore;
};


#endif //SCACCHI_PEDONE_H
