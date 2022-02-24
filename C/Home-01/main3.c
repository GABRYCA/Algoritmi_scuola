#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int pid;

    printf("\nCiao, io sono Qui!");

    pid = fork(); // Creo primo figlio.
    if (pid == 0) { // Controllo se padre o figlio.
        printf("Ciao, io sono Quo!");
        exit(0);
    } else {
        waitpid(pid, NULL, 0);
        pid = fork();
        if (pid == 0) {
            printf("Ciao, io sono Qua!");
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}