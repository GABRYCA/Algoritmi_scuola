#ifndef PAG407_CELLULARE_ELETTRODOMESTICI_H
#define PAG407_CELLULARE_ELETTRODOMESTICI_H


#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Elettrodomestici{
protected:
    string tipo;
    string nome;
    string marca;
    double prezzo;
public:
    void setTipo(string ti);
    void setNome(string no);
    void setMarca(string ma);
    void setPrezzo(double pre);

    string getTipo();
    string getNome();
    string getMarca();
    double getPrezzo();
};

#endif //PAG407_CELLULARE_ELETTRODOMESTICI_H
