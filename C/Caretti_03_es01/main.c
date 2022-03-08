#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int pid, pid2, pidf1, pidf2, pidff11, pidff12, pidff21, pidff22, status, x;
    srand(time(NULL));
    pidf1 = fork();
    if (pidf1 == 0){
        printf("1 - Primo figlio con pid: %i \n", getpid());
        pidff11 = fork();
        if (pidff11 == 0){
            printf("1 - 1 Figlio del figlio con pid: %i \n", getpid());
            exit(2);
        } else {
            pidff12 = fork();
            if (pidff12 == 0){
                printf("1 - 2 Figlio del figlio con pid: %i\n", getpid());
                exit(3);
            }
        }
        exit(1);
    } else {
        pidf2 = fork();
        if (pidf2 == 0){
            printf("2 - Secondo figlio con pid: %i \n", getpid());
            pidff21 = fork();
            if (pidff21 == 0){
                printf("2 - 1 Figlio del figlio con pid: %i \n", getpid());
                exit(5);
            } else {
                pidff22 = fork();
                if (pidff22 == 0){
                    printf("2 - 2 Figlio del figlio con pid: %i\n", getpid());
                    exit(6);
                }
            }
            exit(4);
        } else {
            printf("Padre in attesa dei figli \n");
            pid = waitpid(pidf1, &status, 0);
            pid2 = waitpid(pidf2, &status, 0);
            printf("\nI figli %d e %d sono terminati!\n", pid, pid2);
            return 0;
        }
    }

    return 0;
}
