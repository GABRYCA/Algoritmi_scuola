#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Funzione Din.
int din(){
    printf("DIN\n");
    return 1;
}

// Funzione Don.
int don(){
    printf("DON\n");
    return 2;
}

// Funzione Dan.
int dan(){
    printf("DAN\n");
    return 3;
}

void faiFiglio(int tipo, int n){
    pid_t pid = fork();
    if (pid == 0){
        if (n > 0){
            if (tipo == 1){
                if (n == 3){
                    printf("DIN ");
                } else if (n == 2){
                    printf("DON ");
                } else if (n == 1){
                    printf("DAN ");
                }
            } else if (tipo == 2){
                if (n == 3){
                    printf("DIN ");
                } else if (n == 2){
                    printf("DAN ");
                } else if (n == 1){
                    printf("DON ");
                }
            } else if (tipo == 3){
                if (n == 3){
                    printf("DON ");
                } else if (n == 2){
                    printf("DIN ");
                } else if (n == 1){
                    printf("DAN ");
                }
            } else if (tipo == 4){
                if (n == 3){
                    printf("DAN ");
                } else if (n == 2){
                    printf("DIN ");
                } else if (n == 1){
                    printf("DON ");
                }
            }
            faiFiglio(tipo, n-1);
        } else {
            exit(0);
        }
    }
}

int main() {

    // Legenda e scelta utente.
    int scelta = 0;
    if (scelta == 0) {
        printf("\nOpzioni:"
               "\n1) DIN DON DAN"
               "\n2) DIN DAN DON"
               "\n3) DON DIN DAN"
               "\n4) DAN DIN DON"
               "\nScelta: ");
        scanf("%d", &scelta);
    }

    // Parte commentata esperimento.
    /*int status, pid_din, pid_don, pid_dan;

    pid_din = fork();
    if (pid_din == 0){
        printf("DIN\n");
        exit(1);
    } else {
        pid_don = fork();
        if (pid_don == 0){
            printf("DON\n");
            sleep(1);
            exit(2);
        } else {
            pid_dan = fork();
            if (pid_dan == 0){
                printf("DAN\n");
                sleep(2);
                exit(3);
            } else {
                return 0;
            }
        }
    }*/

    if (scelta == 4) { // DAN DIN DON
        int piddin;

        // Fork
        pid_t pid_din = fork();
        if (pid_din == 0) {
            piddin = don();
            exit(piddin);
        } else {
            dan();
        }

        din();
    } else if (scelta == 3){ // DON DIN DAN

        int piddin;

        // Fork
        pid_t pid_din = fork();
        if (pid_din == 0) {
            piddin = dan();
            exit(piddin);
        } else {
            don();
        }

        din();
    } else if (scelta == 2){ // DIN DAN DON

        int piddon;

        // Fork
        pid_t pid_don = fork();
        if (pid_don == 0) {
            piddon = don();
            exit(piddon);
        } else {
            din();
        }

        dan();
    } else if (scelta == 1){ // DIN DAN DON
        int piddan;

        // Fork
        pid_t pid_dan = fork();
        if (pid_dan == 0) {
            piddan = dan();
            exit(piddan);
        } else {
            din();
        }
        don();
    }
    return 0;
}
