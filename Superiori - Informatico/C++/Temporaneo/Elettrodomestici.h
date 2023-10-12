#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Elettrodomestici{
private:
    string tipo;
    string nome;
    string marca;
    double prezzo;
public:
    Elettrodomestici();
    Elettrodomestici(string ti, string no, string ma, double pre){
        tipo = ti;
        nome = no;
        marca = ma;
        prezzo = pre;
    }
    void setTipo(string ti){
        tipo = ti;
    }
    void setNome(string no){
        nome = no;
    }
    void setMarca(string ma){
        marca = ma;
    }
    void setPrezzo(double pre){
        prezzo = pre;
    }

    string getTipo(){
        return tipo;
    }
    string getNome(){
        return nome;
    }
    string getMarca(){
        return marca;
    }
    double getPrezzo(){
        return prezzo;
    }
};
