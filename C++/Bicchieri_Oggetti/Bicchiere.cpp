#include "Bicchiere.h"
#include <string>

using namespace std;

Bicchiere::Bicchiere() {

}

Bicchiere::Bicchiere(string iMateriale, string iForma, float iLivello, float iCapacita) {
    materiale = iMateriale;
    forma = iForma;
    livello = iLivello;
    capacita = iCapacita;
}

void Bicchiere::setMateriale(string iMateriale) {
    materiale = iMateriale;
}

void Bicchiere::setForma(string iForma) {
    forma = iForma;
}

void Bicchiere::setLivello(float iLivello) {
    livello = iLivello;
}

void Bicchiere::setCapacita(float iCapacita) {
    capacita = iCapacita;
}

string Bicchiere::getMateriale() {
    return materiale;
}

string Bicchiere::getForma() {
    return forma;
}

float Bicchiere::getLivello() {
    return livello;
}

float Bicchiere::getCapacita() {
    return capacita;
}

void Bicchiere::svuota() {
    livello = 0;
}

void Bicchiere::riempi() {
    livello = capacita;
}
