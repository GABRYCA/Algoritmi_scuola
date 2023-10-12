#include <iostream>
#include "Persona.h"
#include "Sportivo.h"
#include "Calciatore.h"

int main(){
    // Istanza di Persona.
    Persona p("Alberto", "Sordi");
    cout << endl << "Persona" << endl << "-------" << endl;
    p.stampa();

    // Istanza di Sportivo.
    cout << endl << "Sportivo" << endl << "------" << endl;
    Sportivo s("Rossi", "Valentino", "motociclismo");
    s.stampa();

    // Istanza di Calciatore.
    cout << endl << "Calciatore" << endl << "----" << endl;
    Calciatore c("Diego", "Maradona", "calcio", "Napoli");
    c.Sportivo::stampa();
    c.stampaSquadra();

    return 0;
}
