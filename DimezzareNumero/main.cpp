#include <stdio.h>

int divisione(int x, int y);

int contaDimezza(int num);

int main() {

    printf("\nHai scelto: Quante volte Dimezzare un numero fino ad arrivare all'unità...");
    printf("\nInserire il numero da dimezzare: ");

    int num;

    scanf("%d", &num);

    int nVolte = contaDimezza(num);

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