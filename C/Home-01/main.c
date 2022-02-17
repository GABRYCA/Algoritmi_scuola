#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void faiFiglio();

int main() {
    int nFigli;

    printf("Quanti figli vuoi creare?"
           "\nNumero: ");
    scanf("%d", &nFigli);

    for (int i = 0; i < nFigli; ++i) {
        faiFiglio();
    }
    for(int i=0;i<5;i++) wait(NULL);

    return 0;
}

void faiFiglio(){
    int pid;
    pid = fork();
    if (pid == 0){
        printf("Figlio con pid %d dal padre di pid %d\n",getpid(),getppid());
        exit(0);
    }
}
