#include <iostream>
#include "FB1.h"
#include "FB2.h"

int main() {
    FB1 fb1;
    FB2 fb2;

    fb1.i1 = 0; // Privato e rimane privato.
    fb1.i2 = 0; // Protected ma diventa privato essendo protected e anche ereditato come private.
    fb1.i3 = 0; // Public ma diventa private essendo ereditata la classe come private.
    fb1.fbi1 = 0; // Private.
    fb1.fbi2 = 0; // Protected (il main non e' una sua estensione quindi non funziona).
    fb1.fbi3 = 0; // Public.

    fb2.i1 = 0; // Privato e rimane privato.
    fb2.i2 = 0; // Protected ma diventa privato essendo protected.
    fb2.i3 = 0; // Pubblico.
    fb2.fb2i1 = 0; // Private.
    fb2.fb2i2 = 0; // Protected (il main non è una sua estensione quindi non funziona).
    fb2.fb2i3 = 0; // Public.
    return 0;
}
