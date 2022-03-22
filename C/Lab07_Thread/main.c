#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int outA, outB, outC;

void *a(void * x){ // 3 + x
    outA = 3 + *((int*)x);
    printf("\nRisultato di A: %d", outA);
    pthread_exit((void*) &outA);
}

void* b(void* y){ // 2 + y
    outB = 2 + *((int*) y);
    printf("\nRisultato di B: %d", outB);
    pthread_exit((void*) &outB);
}

void* c(void* y){ // 7 * y + 3
    outC = 7 * (*(int*) y) + 3;
    printf("\nRisultato di C: %d", outC);
    pthread_exit((void*) &outC);
}

int main() {
    pthread_t ptidA, ptidB, ptidC;
    int x, y;
    int *risA, *risB, *risC, risultato;

    printf("Inserire x: ");
    scanf("%d", &x);
    printf("\nInserire y: ");
    scanf("%d", &y);

    pthread_create(&ptidA, NULL, &a, (void*) &x);
    pthread_create(&ptidB, NULL, &b, (void*) &y);
    pthread_create(&ptidC, NULL, &c, (void*) &y);

    pthread_join(ptidA, (void*) &risA);
    pthread_join(ptidB, (void*) &risB);
    pthread_join(ptidC, (void*) &risC);

    /*printf("\nptidA -> %d; ptidB -> %d; ptidC -> %d", *risA, *risB, *risC);
    int testA, testB, testC;
    testA = *risA;
    testB = *risB;
    testC = *risC;
    printf("\ntestA -> %d; testB -> %d; testC -> %d; ris %d", testA, testB, testC, testA - testB * testC);*/

    risultato = *risA - *risB * (*risC);
    printf("\nRisultato: %d", risultato);
    return 0;
}
