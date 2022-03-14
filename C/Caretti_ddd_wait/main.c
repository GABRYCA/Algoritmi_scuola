#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int scelta;
    printf("\nOpzioni:"
           "\n1) DIN DON DAN"
           "\n2) DIN DAN DON"
           "\n3) DON DIN DAN"
           "\n4) DAN DIN DON"
           "\nScelta: ");
    scanf("%d", &scelta);

    pid_t pid_din;
    pid_t pid_don;
    pid_t pid_dan;
    int status;

    if (scelta == 1){
        pid_din = fork();
        if (pid_din == 0){
            printf("DIN\n");
            exit(0);
        } else {
            wait(&status);
            pid_don = fork();
            if (pid_don == 0){
                printf("DON\n");
                exit(0);
            } else {
                wait(&status);
                pid_dan = fork();
                if (pid_dan == 0){
                    printf("DAN\n");
                    exit(0);
                }
            }
        }
    } else if (scelta == 2){
        pid_din = fork();
        if (pid_din == 0){
            printf("DIN\n");
            exit(0);
        } else {
            wait(&status);
            pid_dan = fork();
            if (pid_dan == 0){
                printf("DAN\n");
                exit(0);
            } else {
                wait(&status);
                pid_don = fork();
                if (pid_don == 0){
                    printf("DON\n");
                    exit(0);
                }
            }
        }
    } else if (scelta == 3){
        pid_don = fork();
        if (pid_don == 0){
            printf("DON\n");
            exit(0);
        } else {
            wait(&status);
            pid_din = fork();
            if (pid_din == 0){
                printf("DIN\n");
                exit(0);
            } else {
                wait(&status);
                pid_dan = fork();
                if (pid_dan == 0){
                    printf("DAN\n");
                    exit(0);
                }
            }
        }
    } else if (scelta == 4){
        pid_dan = fork();
        if (pid_dan == 0){
            printf("DAN\n");
            exit(0);
        } else {
            wait(&status);
            pid_din = fork();
            if (pid_din == 0){
                printf("DIN\n");
                exit(0);
            } else {
                wait(&status);
                pid_don = fork();
                if (pid_don == 0){
                    printf("DON\n");
                    exit(0);
                }
            }
        }
    } else {
        printf("\nScelta non valida!");
    }
    return 0;
}
