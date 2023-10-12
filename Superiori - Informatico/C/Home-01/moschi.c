#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

void  faiFiglio();

int main() {
    int Figliric;

    printf("Quanti figli vuoi che vengano generati nel programma? \n"); //chiedo quanti figli si vuole nel programma
    scanf("%d" , &Figliric);

    for (int a = 0 ; a < Figliric; ++a) {
        faiFiglio(); //genero i figli richiesti dall utente
    }

    for (int a = 0 ; a < Figliric; a++) wait(NULL);

    return 0;
}

void faiFiglio(){
    int pid;
    pid = fork();
    if(pid == 0){
        printf("il Figlio ha  pid %d e il padre ha pid %d \n ", getpid(), getppid());
        exit(0);
    }
}