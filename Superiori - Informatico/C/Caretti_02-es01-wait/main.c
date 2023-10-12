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

    if (scelta == 3) { // DON DIN DAN
        int piddin, pid_don, pid_dan, retv;

        // Fork
        pid_t pid_din = fork();
        if (pid_din == 0) {
            piddin = din();
            exit(piddin);
        } else {
            pid_don = don();
        }

        // Wait
        wait(&retv);
        piddin = WEXITSTATUS(retv);
        pid_dan = dan();
    } else if (scelta == 4){ // DAN DIN DON

        int piddin, pid_dan, pid_don, retv;

        // Fork
        pid_t pid_din = fork();
        if (pid_din == 0) {
            piddin = din();
            exit(piddin);
        } else {
            pid_dan = dan();
        }

        // Wait
        wait(&retv);
        piddin = WEXITSTATUS(retv);
        pid_don = don();
    } else if (scelta == 1){ // DIN DON DAN

        int piddon, pid_din, pid_dan, retv;

        // Fork
        pid_t pid_don = fork();
        if (pid_don == 0) {
            piddon = don();
            exit(piddon);
        } else {
            pid_din = din();
        }

        // Wait
        wait(&retv);
        piddon = WEXITSTATUS(retv);
        pid_dan = dan();

    } else if (scelta == 2){ // DIN DAN DON
        int piddan, pid_din, pid_don, retv;

        // Fork
        pid_t pid_dan = fork();
        if (pid_dan == 0) {
            piddan = dan();
            exit(piddan);
        } else {
            pid_din = din();
        }

        // Wait
        wait(&retv);
        piddan = WEXITSTATUS(retv);
        pid_don = don();
    }
    return 0;
}
