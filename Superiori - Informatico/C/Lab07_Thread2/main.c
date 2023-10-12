#include <stdio.h>
#include <pthread.h>

int outA, outB, outC;

void* a(void* x){ // 2 + x
    outA = 2 + *((int*) x);
    printf("\nRisultato A: %d", outA);
    pthread_exit((void *) &outA);
}

void* b(void* x){ // 3 + x
    outB = 3 + *((int*) x);
    printf("\nRisultato B: %d", outB);
    pthread_exit((void *) &outB);
}

void* c(void* y){ // 7 * y + 4
    outC = 7 * (*(int*) y) + 4;
    printf("\nRisultato C: %d", outC);
    pthread_exit((void *) &outC);

}

int main() {
    pthread_t ptidA, ptidB, ptidC;
    int *risA, *risB, *risC;
    int x, y, risultato;

    printf("Inserire x: ");
    scanf("%d", &x);
    printf("\nInserire y: ");
    scanf("%d", &y);

    pthread_create(&ptidA, NULL, &a, (void*) &x);
    pthread_create(&ptidB, NULL, &b, (void*) &x);
    pthread_create(&ptidC, NULL, &c, (void*) &y);

    pthread_join(ptidA, (void*) &risA);
    pthread_join(ptidB, (void*) &risB);
    pthread_join(ptidC, (void*) &risC);

    risultato = *risA * (*risB) * (*risC) - 10;
    printf("\n\nRisultato: %d", risultato);
    return 0;
}
