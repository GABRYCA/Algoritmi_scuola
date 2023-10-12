#include "Elettrodomestici.h"

void Elettrodomestici::setTipo(string ti){
    tipo = ti;
}
void Elettrodomestici::setNome(string no){
    nome = no;
}
void Elettrodomestici::setMarca(string ma){
    marca = ma;
}
void Elettrodomestici::setPrezzo(double pre){
    prezzo = pre;
}

string Elettrodomestici::getTipo(){
    return tipo;
}
string Elettrodomestici::getNome(){
    return nome;
}
string Elettrodomestici::getMarca(){
    return marca;
}
double Elettrodomestici::getPrezzo(){
    return prezzo;
}