#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Bicchiere{
private:
    string materiale;
    string forma;
    float livello;
    float capacita;
public:
    Bicchiere();
    Bicchiere(string iMateriale, string iForma, float iLivello, float iCapacita);
    void setMateriale(string iMateriale);
    void setForma(string iForma);
    void setLivello(float iLivello);
    void setCapacita(float iCapacita);
    string getMateriale();
    string getForma();
    float getLivello();
    float getCapacita();
    void svuota();
    void riempi();
};