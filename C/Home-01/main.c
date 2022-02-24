#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void faiFiglio();

int main() {
    int nFigli;

    // Chiedo quanti figli si vogliano creare.
    printf("Quanti figli vuoi creare?"
           "\nNumero: ");
    scanf("%d", &nFigli);

    // Tramite un ciclo creo ogni singolo figlio chiamando la funzione appropriata.
    for (int i = 0; i < nFigli; ++i) {
        faiFiglio();
    }

    // Attesa per la fine dei figli.
    for(int i = 0;i < nFigli; i++) wait(NULL);

    return 0;
}

/**
 * Funzione per creare i figli.
 */
void faiFiglio(){
    int pid;
    pid = fork();
    if (pid == 0){
        printf("Figlio con pid %d dal padre di pid %d\n", getpid(), getppid());
        exit(0);
    }
}