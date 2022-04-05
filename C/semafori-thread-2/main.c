#include <stdio.h>
#include <pthread.h>
pthread_mutex_t semaforo;

struct Test{
    int a;
    int b;
} test;

void *somma1(void *arg){
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&semaforo);
        test.a++;
        test.b++;
        pthread_mutex_unlock(&semaforo);
    }
}

void *somma2(void *arg){
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&semaforo);
        test.a++;
        test.b++;
        pthread_mutex_unlock(&semaforo);
    }
}

int main() {
    printf("Thread 'semafori' di Gabriele Caretti.\n");

    pthread_t t1, t2;

    pthread_create(&t1, NULL, somma1, NULL);
    pthread_create(&t2, NULL, somma2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\ntest.a: %d", test.a);
    printf("\ntest.b: %d", test.b);
    return 0;
}
