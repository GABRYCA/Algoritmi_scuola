#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int status;
    int pid = fork();
    if (pid == 0){
        printf("Sono il figlio, il mio pid e': %d ", getpid());
        printf("Il mio papi ha pid: %d\n", getppid());
        exit(69);
    } else {
        printf("Sono il padre, il mio e': %d. ", getpid());
        printf("L'exit di mio figlio (%d) e': %d\n", wait(&status), status);
        return 0;
    }
    return 0;
}
