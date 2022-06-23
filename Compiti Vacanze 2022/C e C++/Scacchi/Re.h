//
// Created by gabry on 23/06/2022.
//

#include <string>

using namespace std;

#ifndef SCACCHI_RE_H
#define SCACCHI_RE_H


class Re {
public:
    Re(string colore);
    void stampa();
    string getColore();
    string getID();
    string getIDCompleto();
private:
    string id = "R";
    string colore;
};


#endif //SCACCHI_RE_H
