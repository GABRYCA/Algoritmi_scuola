#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    pid_t F1;
    pid_t F2;
    pid_t G1;
    pid_t H1;
    pid_t G2;
    pid_t H2;
    int status;

    F1 = fork();
    if (F1 == 0){
        printf("Sono F1\n");
        G1 = fork();
        sleep(1);
        if (G1 == 0) {
            printf("Sono G1\n");
            exit(0);
        } else {
            H1 = fork();
            if (H1 == 0) {
                waitpid(G1, &status, 0);
                printf("Sono H1\n");
                exit(0);
            }
        }
        waitpid(H1, &status, 0);
        exit(0);
    } else {
        F2 = fork();
        if (F2 == 0){
            printf("Sono F2\n");
            G2 = fork();
            if (G2 == 0){
                printf("Sono G2\n");
                exit(0);
            } else {
                H2 = fork();
                if (H2 == 0){
                    waitpid(G2, &status, 0);
                    printf("Sono H2\n");
                    exit(0);
                }
            }
            waitpid(H2, &status, 0);
            exit(0);
        } else {
            waitpid(F2, &status, 0);
            printf("Fine F2, status: %i\n", status);
            waitpid(F1, &status, 0);
            printf("Fine F1, status: %i\n", status);
            return 0;
        }
    }
}
