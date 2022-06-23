//
// Created by gabry on 23/06/2022.
//

#include <string>

using namespace std;

#ifndef SCACCHI_PEDONE_H
#define SCACCHI_PEDONE_H


class Pedone {
public:
    Pedone(string colore);
    void stampa();
    string getColore();
    string getID();
    string getIDCompleto();
private:
    string id = "P";
    string colore;
};


#endif //SCACCHI_PEDONE_H
