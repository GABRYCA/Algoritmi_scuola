#include "Cellulari.h"

void Cellulari::setProcessore(string pro){
    processore = pro;
}
void Cellulari::setSistema_operativo(string sis){
    sistema_operativo = sis;
}
void Cellulari::setNumero_core(int num){
    numero_core = num;
}
void Cellulari::setMemoria_interna_GB(float mem_int){
    memoria_interna_GB = mem_int;
}
void Cellulari::setRAM_GB(float RAM){
    RAM_GB = RAM;
}

string Cellulari::getProcessore(){
    return processore;
}
string Cellulari::getSistema_operativo(){
    return sistema_operativo;
}
int Cellulari::getNumero_core(){
    return numero_core;
}
float Cellulari::getMemoria_interna_GB(){
    return memoria_interna_GB;
}
float Cellulari::getRAM_GB(){
    return RAM_GB;
}
void Cellulari::stampa(){
    printf("\nNome: %s."
           "\nMarca: %s."
           "\nPrezzo: %.2f."
           "\nProcessore: %s."
           "\nSistema operativo: %s."
           "\nNumero core: %d."
           "\nMemoria interna: %dGB"
           "\nRAM: %dGB", nome.c_str(), marca.c_str(), prezzo, processore.c_str(), sistema_operativo.c_str(), numero_core, memoria_interna_GB, RAM_GB);
}
