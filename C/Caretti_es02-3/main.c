#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#define NRFIGLI 4

int main() {
    int status, pid;
    for (int x = 0; x < NRFIGLI; x++){
        pid = fork();
        if (pid == 0){
            printf( "Sono il figlio, il mio pid e': %d. ", getpid());
            printf(" Il mio papi ha pid: %d\n", getppid());
            exit(0);
        } else {
            printf("Sono il padre, il mio pid e': %d. ", getpid());
            printf("Il pid del figlio corrente e': %d. ", pid);
            printf("L'exit di mio figlio (%d) e': %d\n\n", wait(&status), status);
        }
    }
    return 0;
}
