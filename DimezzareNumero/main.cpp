#include <stdio.h>

// Analisi:
// Dati in ingresso: num
// Dati in uscita: nVolte, nVolte*2
//
// Idea risolutiva:
// Dimezzo il numero in entrata per un dimezzatore, in questo caso 2, in modo da ottenere sempre la metà
// Di esso, una volta eseguita questa operazione aggiungo uno ad un contatore ossia quante volte è stato diviso per
// il dimezzatore, quando questo diventa MINORE del dimezzatore, si finisce l'algoritmo e comunica il risultato del
// numero di volte diviso all'utente, e anche il doppio del numero di tentativi più consoni necessari per indovinare
// Un numero compreso in quell'intervallo.

int divisione(int x, int y);

int contaDimezza(int num);

int main() {

    printf("\nHai scelto: Quante volte Dimezzare un numero fino ad arrivare all'unità...");
    printf("\nInserire il numero da dimezzare: ");

    int num, nVolte;

    scanf("%d", &num);

    nVolte = contaDimezza(num);

    printf("Il numero è stato dimezzato -%d- volte. Significa che per trovare un numero compreso servirebbero circa %d tentativi.", nVolte, nVolte * 2);

    return 0;
}

int contaDimezza(int num) {
    int nVolte = 0, dimezzatore = 2;

    while (num >= 2){

        num = divisione(num, dimezzatore);

        nVolte++;

    }
    return nVolte;
}

int divisione(int x, int y){

    int ris = 0;

    // Loop fino a quando x non diventa minore a y
    while (x >= y){

        x -= y;

        ris++;

    }

    return ris;
}