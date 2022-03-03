#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int figlio1(int n){
    int k;
    printf("Calcolo figlio 2: (%d - 3) * 2...\n", n);
    k = (n - 3) * 2;
    printf("Valore attuale figlio 2: %d\n", k);
    return k;
}

int figlio2(int n){
    int k;
    printf("Calcolo figlio 1: %d * 3 - 3...\n", n);
    k = n * 3 - 3;
    printf("Valore attuale figlio 1: %d\n", k);
    return k;
}

int figlio3(int n){
    int k;
    printf("Calcolo figlio 3: %d * 2 - 3...\n", n);
    k = n * 2 - 3;
    printf("Valore attuale figlio 3: %d\n", k);
    return k;
}

int main() {

    int nInput = -1;
    if (nInput == -1){
        printf("\nInserire il numero iniziale: ");
        scanf("%d", &nInput);
    }

    int z, retv;

    pid_t pid;
    pid = fork();
    if (pid == 0){
        nInput = figlio1(nInput);
        exit(nInput);
    } else {
        nInput = figlio2(nInput);
    }
    wait(&retv);
    nInput = WEXITSTATUS(retv);
    z = figlio3(nInput);
    printf("\nRisultato finale: %d\n", z);
    return 0;
}
