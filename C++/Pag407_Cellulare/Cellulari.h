#ifndef PAG407_CELLULARE_CELLULARI_H
#define PAG407_CELLULARE_CELLULARI_H


#include "Elettrodomestici.h"

class Cellulari : public Elettrodomestici {
private:
    string processore;
    string sistema_operativo;
    int numero_core;
    float memoria_interna_GB;
    float RAM_GB;
public:
    void setProcessore(string pro);
    void setSistema_operativo(string sis);
    void setNumero_core(int num);
    void setMemoria_interna_GB(float mem_int);
    void setRAM_GB(float RAM);

    string getProcessore();
    string getSistema_operativo();
    int getNumero_core();
    float getMemoria_interna_GB();
    float getRAM_GB();
    void stampa();
};


#endif //PAG407_CELLULARE_CELLULARI_H
