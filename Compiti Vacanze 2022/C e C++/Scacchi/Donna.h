//
// Created by gabry on 23/06/2022.
//

#include <string>

using namespace std;

#ifndef SCACCHI_DONNA_H
#define SCACCHI_DONNA_H


class Donna {
public:
    Donna(string colore);
    void stampa();
    string getColore();
    string getID();
    string getIDCompleto();

    bool sposta(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione, string **scacchiera);

private:
    string id = "D";
    string colore;
};


#endif //SCACCHI_DONNA_H
