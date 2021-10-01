#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ricorsivo(int i);

long fibonacciIterativo(long n);

long fibonacciRicorsivo(long n);

long fibonacciRicorsivo_2(long n);

void pausa();

int main() {

    printf("\nAlgoritmo di G.C. 4BITI.");

    int scelta;
    do {

        printf("\n\nScelte:"
               "\n0 -> Esci."
               "\n1 -> Calcola fattoriale."
               "\n2 -> Fibonacci iterativo."
               "\n3 -> Fibonacci ricorsivo."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci...");

                break;
            }

            case 1:{

                printf("\nScelta: Calcolo fattoriale.");

                int numero;
                printf("\nInserire il numero fattoriale da calcolare: ");
                scanf("%d", &numero);

                printf("\nIl fattoriale e' %d", ricorsivo(numero));

                pausa();
                break;
            }

            case 2:{

                printf("\nScelta: Calcolo Fibonacci non ricorsivo.");

                long n, ris;
                printf("\nInserire N da calcolare con Fibonacci: ");
                scanf("%ld", &n);

                clock_t inizio = clock();

                ris = fibonacciIterativo(n);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato e' stato di %lu secondi.\n", tempoRiordinamento);

                printf("\nRisultato: %ld", ris);

                pausa();
                break;
            }

            case 3:{

                printf("\nScelta: Calcolo Fibonacci ricorsivo.");

                long n, ris;
                printf("\nInserire N da calcolare con Fibonacci: ");
                scanf("%ld", &n);

                clock_t inizio = clock();

                ris = fibonacciRicorsivo(n);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato e' stato di %lu secondi.\n", tempoRiordinamento);

                printf("\nRisultato: %ld", ris);

                pausa();
                break;
            }

            default:{

                printf("\n\nScelta non valida, per favore riprovare.");

                break;
            }

        }

    } while (scelta != 0);

    printf("\n\nUscito con successo!");

    return 0;
}

// Nelle funzioni ricorsive, ci sono 2 caratteristiche principali:
// Chiama se stessa
// OPPURE
// Chiama una funzione che chiamera' di nuovo se stesso in modo indiretto.
// Un algoritmo ricorsivo si dice tale se si basa su procedure ricorsive.
int ricorsivo(int i){
    if(i > 1){
        return i * ricorsivo(i - 1);
    } else {
        return 1;
    }
}

// Fib(1) = 1
// Fib(2) = 1
// Fib(n+2) = Fib(n+1) + Fib(n)
long fibonacciIterativo(long n){

    /*if (n <= 1){
        return n;
    }*/

    long fib = 0, f1 = 1, f2 = 0;
    for(long i = 2; i <= n; i++){
        fib = f1 + f2;
        f2 = f1;
        f1 = fib;
    }

    return fib;
}

long fibonacciRicorsivo(long n){
    if(n <= 1) {
        return n;
    } else {
        return fibonacciRicorsivo(n-1) + fibonacciRicorsivo(n-2);
    }
}

long fibonacciRicorsivo_2(long n){
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacciRicorsivo_2(n - 1) + fibonacciRicorsivo_2(n - 2);
}

void pausa(){
    printf("\n\nInserire un numero per continuare: ");
    int numeroIgnorato;
    scanf("%d", &numeroIgnorato);
    printf("\n");
}