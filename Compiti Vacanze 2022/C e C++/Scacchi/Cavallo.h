//
// Created by gabry on 23/06/2022.
//

#include <string>

using namespace std;

#ifndef SCACCHI_CAVALLO_H
#define SCACCHI_CAVALLO_H


class Cavallo {
public:
    Cavallo(string colore);
    void stampa();
    string getColore();
    string getID();
    string getIDCompleto();
private:
    string id = "C";
    string colore;
};


#endif //SCACCHI_CAVALLO_H
