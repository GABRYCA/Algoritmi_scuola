#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    // start
    // cobegin
    //    a (3+2)
    //    b (5-2)
    //    c (8-3)
    // coend
    // fine

    pid_t pidA, pidB, pidC;
    int a, b, c, ris, status;

    pidA = fork();
    if (pidA == 0){
        a = 3+2;
        exit(a);
    } else {
        pidB = fork();
        if (pidB == 0){
            b = 5-2;
            exit(b);
        } else {
            pidC = fork();
            if (pidC == 0){
                c = 8-3;
                exit(c);
            } else {
                waitpid(pidA, &status, 0);
                a = WEXITSTATUS(status);
                waitpid(pidB, &status, 0);
                b = WEXITSTATUS(status); // Notare il "-" davanti per bypassare in modo scorretto il problema dell'exit.
                waitpid(pidC, &status, 0);
                c = WEXITSTATUS(status);
                printf("a = %d, b = %d, c = %d\n", a, b, c);
                ris = a * b;
                ris *= c;
                printf("Risultato: %d", ris);
            }
        }
    }

    return 0;
}
