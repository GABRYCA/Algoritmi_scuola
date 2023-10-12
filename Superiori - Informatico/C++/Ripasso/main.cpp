#include <iostream>

using namespace std;

void conta(int n);
void contaDec(int n);
int somma(int vet[], int pos);

int main() {

    int n;
    //printf("Inserire il numero da cui iniziare la conta: ");
    //scanf("%d", &n);

    int vet[3] = {3,2,1};
    printf("Somma: %d\n", somma(vet, 2));
    //contaDec(n);

    return 0;
}

void conta(int n){
    if (n > 0){
        conta(n-1);
    }
    printf("%d\n", n);
    return;
}

void contaDec(int n){
    printf("%d\n", n);
    if (n <= 0){
        return;
    }
    contaDec(n - 1);
    return;
}

int somma(int *vet, int pos){
    if (pos < 0){
        return 0;
    }
    return somma(vet, pos - 1) +  vet[pos];
}

