//
// Created by gabry on 23/06/2022.
//

#include <string>

using namespace std;

#ifndef SCACCHI_ALFIERE_H
#define SCACCHI_ALFIERE_H


class Alfiere {
public:
    Alfiere(char colore);
    void stampa();
    char getColore();
    char getID();
    string getIDCompleto();

    bool sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera);

private:
    char id = 'A';
    char colore;
};


#endif //SCACCHI_ALFIERE_H
