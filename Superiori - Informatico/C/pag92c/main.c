#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    // Inizio
    // cobegin
    //   a (2+3)
    //   b (7+3)
    // coend
    // c = a*b
    // c -= 10

    pid_t pidA, pidB;
    int a, b, ris = 0, status;

    pidA = fork();
    if (pidA == 0){
        a = 2 + 4;
        exit(a);
    } else {
        pidB = fork();
        if (pidB == 0){
            b = 7 + 3;
            exit(b);
        } else { // Ho abusato dei wexitstatus per ottenere i valori in modo alternativo.
            waitpid(pidA, &status, 0);
            a = WEXITSTATUS(status);
            waitpid(pidB, &status, 0);
            b = WEXITSTATUS(status);
            printf("a = %d, b = %d\n", a, b);
            ris = a * b;
            ris *= 5;
            ris -= 10;
            printf("Risultato: %d\n", ris);
        }
    }

    return 0;
}
