#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int din(){
    printf("DIN\n");
    return 1;
}

int don(){
    printf("DON\n");
    return 2;
}

int dan(){
    printf("DAN\n");
    return 3;
}

int main() {

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

    if (scelta == 3) {
        int x, y, z, retv;

        pid_t pid;
        pid = fork();
        if (pid == 0) {
            x = din();
            exit(x);
        } else {
            y = don();
        }

        wait(&retv);
        x = WEXITSTATUS(retv);
        z = dan();
    } else if (scelta == 4){

        int x, y, z, retv;

        pid_t pid;
        pid = fork();
        if (pid == 0) {
            x = din();
            exit(x);
        } else {
            y = dan();
        }

        wait(&retv);
        x = WEXITSTATUS(retv);
        z = don();

    } else if (scelta == 1){

        int x, y, z, retv;

        pid_t pid;
        pid = fork();
        if (pid == 0) {
            x = don();
            exit(x);
        } else {
            y = din();
        }

        wait(&retv);
        x = WEXITSTATUS(retv);
        z = dan();

    } else if (scelta == 2){
        int x, y, z, retv;

        pid_t pid;
        pid = fork();
        if (pid == 0) {
            x = dan();
            exit(x);
        } else {
            y = din();
        }

        wait(&retv);
        x = WEXITSTATUS(retv);
        z = don();
    }
    return 0;
}