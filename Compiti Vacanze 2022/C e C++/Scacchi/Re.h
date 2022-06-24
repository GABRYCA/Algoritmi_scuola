//
// Created by gabry on 23/06/2022.
//

#include <string>

using namespace std;

#ifndef SCACCHI_RE_H
#define SCACCHI_RE_H


class Re {
public:
    Re(char colore);
    void stampa();
    char getColore();
    char getID();
    string getIDCompleto();

    bool sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera);

private:
    char id = 'R';
    char colore;
};


#endif //SCACCHI_RE_H
