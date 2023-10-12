#include "Persona.h"

class Sportivo : public Persona{
protected:
    char sport[30];
public:
    Sportivo(){};
    Sportivo(char* nom, char* cog, char* spo) : Persona(nom, cog){
        strcpy_s(sport, spo);
    }
    void stampa(){
        Persona::stampa(); // Metodo del padre.
        cout << "Sport   : " << sport << endl;
    }
};