#include "Elettrodomestici.h"

class Cellulari : Elettrodomestici {
private:
    string processore;
    string sistema_operativo;
    int numero_core;
    float memoria_interna_GB;
    float RAM_GB;
public:
    Cellulari(string ti, string no, string mar, double pre, string pro, string sis, int num_c, float mem_int, float RAM){
        setTipo(ti);
        setNome(no);
        setMarca(mar);
        setPrezzo(pre);
        processore = pro;
        sistema_operativo = sis;
        numero_core = num_c;
        memoria_interna_GB = mem_int;
        RAM_GB = RAM;
    }

    void setTipo(string ti){
        setTipo(ti);
    }
    void setNome(string no){
        setNome(no);
    }
    void setMarca(string mar){
        setMarca(mar);
    }
    void setPrezzo(double pre){
        setPrezzo(pre);
    }
    void setProcessore(string pro){
        processore = pro;
    }
    void setSistema_operativo(string sis){
        sistema_operativo = sis;
    }
    void setNumero_core(int num){
        numero_core = num;
    }
    void setMemoria_interna_GB(float mem_int){
        memoria_interna_GB = mem_int;
    }
    void setRAM_GB(float RAM){
        RAM_GB = RAM;
    }

    string getTipo(){
        return getTipo();
    }
    string getNome(){
        return getNome();
    }
    string getMarca(){
        return getMarca();
    }
    double getPrezzo(){
        return getPrezzo();
    }
    string getProcessore(){
        return processore;
    }
    string getSistema_operativo(){
        return sistema_operativo;
    }
    int getNumero_core(){
        return numero_core;
    }
    float getMemoria_interna_GB(){
        return memoria_interna_GB;
    }
    float getRAM_GB(){
        return RAM_GB;
    }
    void stampa(){
        printf("\nNome: %s."
               "\nMarca: %s."
               "\nPrezzo: %.2f."
               "\nProcessore: %s."
               "\nSistema operativo: %s."
               "\nNumero core: %d."
               "\nMemoria interna: %dGB"
               "\nRAM: %dGB", getNome().c_str(), getMarca().c_str(), getPrezzo(), processore.c_str(), sistema_operativo.c_str(), numero_core, memoria_interna_GB, RAM_GB);
    }
};