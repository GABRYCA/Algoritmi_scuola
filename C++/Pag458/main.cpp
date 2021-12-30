#include <iostream>
#include <cstdio>

void insInVet(int nNumeri, int *vet);

using namespace std;

int main() {

    printf("/////////////////////////////////////////"
            "\n   Gerarchia Cellulare di G.C. 4BITI"
            "\n/////////////////////////////////////////\n");

    int nNumeri;

    printf("\nInserire il numero di numeri da memorizzare: ");
    scanf("%d", &nNumeri);

    int *vet = new int(nNumeri);

    printf("\nInserire %d numeri:\n");
    insInVet(nNumeri, vet);

    printf("\nI valori inseriti sono:\n");
    for (int i = 0; i < nNumeri; i++) {
        printf("%d: %d", i + 1, vet[i]);
    }

    return 0;
}

void insInVet(int nNumeri, int *vet) {
    for (int i = 0; i < nNumeri; i++) {
        printf("\n%d: ", i + 1);
        cin >> vet[i];
    }
}
