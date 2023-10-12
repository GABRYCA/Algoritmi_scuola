#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int pid;
    printf( "1) prima della fork \n" );
    pid = fork();                                // creo processo figlio
    printf( " 2) dopo della fork \n" );
    if (pid == 0){
        printf( " 3) sono il processo figlio\n" );
        exit(1) ;                                  // termina il processo figlio
    }
    else{
        printf( " 3) sono il processo padre\n");
        exit(0) ;                                  // non necessaria
    }
}