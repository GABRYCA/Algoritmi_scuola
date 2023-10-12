#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int pid, status;
    pid = fork();
    if (pid == 0){
        printf("codice eseguito dal figlio \n");
        exit(0);
    } else {
        pid = wait(&status);
        printf("terminato processo figlio n.%d\n", pid);
        if ((char) status == 0) {
            printf("terminazione volontaria con stato %d\n", status);
        } else {
            printf("terrminazione errata con segnale %d\n", (char) status);
        }
    }

    return 0;
}
