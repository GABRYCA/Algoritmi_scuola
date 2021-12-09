#include "Sportivo.h"

class Calciatore : public Sportivo {
protected:
    char squadra[30];
    char ruolo[20];
public:
    Calciatore(char* no, char* co, char* sp, char* sq) : Sportivo(no, co , sp){
        strcpy_s(squadra, sq);
    }
    void stampa(){
        Sportivo::stampa();
        cout << "Squadra  : " << squadra << endl;
    }
    void stampaSquadra(){
        cout << "Squadra  :" << squadra << endl;
    }
};