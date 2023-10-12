#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int pid;

    pid = fork(); // Creo primo figlio.
    if (pid != 0){ // Controllo se padre o figlio.
        pid = fork(); // Creo secondo figlio.
        if (pid != 0){ // Controllo se padre o figlio.
            pid = fork(); // Creo terzo figlio.
            if (pid == 0){ // Controllo se figlio o padre.
                printf("\nFiglio con pid %d dal padre di pid %d\n", getpid(), getppid());
                exit(pid); // Esco dal figlio.
            }
        } else {
            printf("Figlio con pid %d dal padre di pid %d\n", getpid(), getppid());
            exit(pid); // Esco dal figlio.
        }
    } else {
        printf("Figlio con pid %d dal padre di pid %d\n", getpid(), getppid());
        exit(pid); // Esco dal figlio.
    }

    return 0;
}