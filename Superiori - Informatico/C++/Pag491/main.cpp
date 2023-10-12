#include <iostream>
#include <stdio.h>
#include <list>
#include <iterator>

using namespace std;

int somma(_List_iterator<int> fronte);

int main() {

    printf("/////////////////////////////////////////"
           "\n   Esercizi Pag.491* di G.C. 4BITI"
           "\n/////////////////////////////////////////\n");

    printf("\nPag 491 A N.1");
    // Vettore.
    list<int> lista;
    int nElementi = 10;
    for (int i = 0; i < nElementi; i++) {
        lista.push_back(i);
    }
    auto fronte = lista.begin();
    printf("\n%d", somma(fronte));

    return 0;
}

int somma(_List_iterator<int> fronte){
    advance(fronte, 1);
    if (*fronte != NULL) {
        return 0;
    }
    return (somma(fronte) + *fronte);
}
