#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int pid;

    pid = fork();
    if (pid == 0){
        printf("\nIo sono Qui!");
        exit(0);
    } else {
        waitpid(pid, NULL, 0);
        pid = fork();
        printf("\nIo sono Quo!");
        if (pid == 0){
            printf("\nIo sono Qua!");
            exit(0);
        }
        exit(pid);
    }

    return 0;
}