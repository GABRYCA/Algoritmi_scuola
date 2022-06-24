//
// Created by gabry on 23/06/2022.
//

#include <string>

using namespace std;

#ifndef SCACCHI_SCACCHIERA_H
#define SCACCHI_SCACCHIERA_H

class Scacchiera {
public:
    Scacchiera(int righe, int colonne);
    ~Scacchiera();
    void stampa();
    void posizionaPedina(int riga, int colonna, string idPedina);
    void rimuoviPedina(int riga, int colonna);
    void reset();
    void resetDefault();
    bool spostaPedina(int riga, int colonna, int rigaDestinazione, int colonnaDestinazione);
private:
    string **scacchiera;
    int righe;
    int colonne;
};


#endif //SCACCHI_SCACCHIERA_H
