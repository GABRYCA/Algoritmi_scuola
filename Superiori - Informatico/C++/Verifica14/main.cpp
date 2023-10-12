#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

void moltiplicazione(int m, int n);

int restoDivisione(int m, int n);

bool verificaDispari(int n);

double media(double *V, int pos, double n);

void trovaValore(int n, int *V, int nNumeri);

void pausa();

int main() {

    int scelta;
    printf("\nVerifica di G.C. 4BITI.");

    do {

        printf("\n\nOpzioni:"
               "\n0 -> Esci."
               "\n1 -> Moltiplicazione numeri compresi tra m ed n."
               "\n2 -> Resto divisione tra due numeri interi m ed n."
               "\n3 -> Verifica dispari m."
               "\n4 -> Dato un vettore, calcolane la media (divisione finale non ricorsiva)."
               "\n5 -> Dato un vettore, verificare presenza valore x."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0:{

                printf("\n\nHai scelto: Esci...");

                break;
            }

            case 1:{

                printf("\n\nHai scelto: Moltiplicazione tra m ed n.");

                int m, n;
                printf("\nInserire il primo numero: ");
                scanf("%d", &m);
                printf("\nInserire il secondo numero: ");
                scanf("%d", &n);

                moltiplicazione(m, n);

                pausa();
                break;
            }

            case 2:{

                printf("\n\nHai scelto: Resto divisione di m ed n...");

                int m, n, resto;
                printf("\nInserire il primo numero (numero maggiore): ");
                scanf("%d", &m);
                printf("\nInserire il secondo numero (numero minore): ");
                scanf("%d", &n);

                resto = restoDivisione(m, n);

                printf("\n\nIl resto tra %d e %d e' uguale a %d", m, n, resto);

                pausa();
                break;
            }

            case 3:{

                printf("\n\nHai scelto: Verifica dispari...");

                int n;
                printf("\nInserire il numero: ");
                scanf("%d", &n);

                if (verificaDispari(n)){
                    printf("\n\nIl numero %d e' dispari!", n);
                } else {
                    printf("\n\nIl numero %d e' pari!", n);
                }

                pausa();
                break;
            }

            case 4:{

                printf("\n\nHai scelto: Dato un vettore di numeri, calcolane la media.");

                double dim = 10;
                double vet[] = {15, 12, 17, 5, 2, 5, 3, 33, 22, 11};

                printf("\n\nOperazione in corso, per favore attendere...");

                double mediaRis = media(vet, 0, dim);

                printf("\n\nIl risultato della media e': %f", mediaRis);

                pausa();
                break;
            }

            case 5:{

                printf("\n\nHai scelto: Verifica se numero si trova in vettore...");

                int dim = 10, valDaTrovare;
                int vet[] = {15, 12, 17, 5, 2, 5, 3, 33, 22, 11};

                printf("\n\nInserire il valore da trovare: ");
                scanf("%d", &valDaTrovare);

                trovaValore(valDaTrovare, vet, dim - 1);

                pausa();
                break;
            }

            default:{

                printf("\n\nScelta non valida, per favore riprovare!");

                break;
            }
        }

    } while (scelta != 0);

    return 0;
}

void moltiplicazione(int m, int n){
    int ris = m * n;

    if (m == n){
        printf("\n%d * %d = %d", m, n, ris);
        return;
    }

    if (m > n){
        printf("\n%d * %d = %d", m, n, ris);
        moltiplicazione(m, n + 1);
    } else {
        printf("\n%d * %d = %d", m, n, ris);
        moltiplicazione(m + 1, n);
    }
}

int restoDivisione(int m, int n){

    if (m < n){
        return m;
    }

    return restoDivisione(m - n, n);
}

bool verificaDispari(int n){

    if (n >= 2){
        return verificaDispari(n - 2);
    }

    if (n == 0){
        return false;
    } else {
        return true;
    }
}

double media(double *V, int pos, double n) {

    if (pos == n - 1) {
        return V[pos];
    }

    if (pos == 0) {
        return (V[pos] + media(V, pos + 1, n)) / n;
    }

    return V[pos] + media(V, pos + 1, n);
}


void trovaValore(int n, int *V, int nNumeri){

    if (nNumeri < 0){
        printf("\nIl numero %d non e' presente nel vettore!", n);
        return;
    }

    if (V[nNumeri] == n){
        printf("\nIl numero %d e' presente nel vettore!", n);
        return;
    }

    return trovaValore(n, V, nNumeri - 1);
}


void pausa(){
    printf("\n\nInserire un numero per continuare: ");
    int numero;
    scanf("%d", &numero);
}

