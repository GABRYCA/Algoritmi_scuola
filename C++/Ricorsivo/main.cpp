#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int ricorsivo(int i);

int ricercaNumeroInVettNonOrdinatoRicorsivo(int *vettore, int nNumeri, int numero);

int ricercaBinaria2(int *v, int a, int b, int x);

int ricercaBinaria(int *vettore, int inizio, int fine, int numero);

long fibonacciIterativo(long n);

long fibonacciRicorsivo(long n);

long fibonacciRicorsivo_2(long n);

void pausa();

void getVetOrdinato(int numeri, int *vettoreFinale_B);

void genVetCasuali(int numeri, int max, int min, int *vettore);

int sommaVettoreRicorsivo(int *vet, int n);

void scriviLineaRicorsivo(string stringa);

int globale = 0;


int main() {

    printf("\nAlgoritmo di G.C. 4BITI.");

    int scelta;
    do {

        printf("\n\nScelte:"
               "\n0 -> Esci."
               "\n1 -> Calcola fattoriale."
               "\n2 -> Fibonacci iterativo."
               "\n3 -> Fibonacci ricorsivo."
               "\n4 -> Trova valore in vettore non ordinato iterativo."
               "\n5 -> Trova valore in vettore non ordinato ricorsivo."
               "\n6 -> Trova valore in vettore ordinato iterativo."
               "\n7 -> Trova valore in vettore ordinato ricorsivo (ricerca binaria)."
               "\n8 -> Ricerca binaria (variante professore)."
               "\n9 -> Somma elementi in un vettore (iterativo)."
               "\n10 -> Somma elementi in un vettore (ricorsivo)."
               "\n11 -> Scrivere stringa in modo ricorsivo e al contrario."
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

                printf("\nScelta: Calcolo Fibonacci iterativo.");

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

            case 4:{

                printf("\n\nHai scelto: Trova valore in un vettore non ordinato con metodo iterativo");

                int numeri, nDaTrovare;

                printf("\nInserire il numero di numeri casuali da generare nel vettoreCasuale_A."
                       "\nNumeri:");
                scanf("%d", &numeri);

                printf("\nInserire il numero da trovare: ");
                scanf("%d", &nDaTrovare);

                int* vettoreFinale_B = new int[numeri]();

                getVetOrdinato(numeri, vettoreFinale_B);

                clock_t inizio = clock();

                int posizione = -1;
                for (int i = 0; i < numeri; i++) {
                    if (vettoreFinale_B[i] == nDaTrovare){
                        posizione = i;
                        break;
                    }
                }

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoTrovaNumero = (fine - inizio) / CLOCKS_PER_SEC;

                if (posizione != -1) {
                    printf("\n\nNumero %d trovato in posizione %d", nDaTrovare, posizione + 1);
                } else {
                    printf("\n\nNumero %d non trovato.", nDaTrovare);
                }
                printf("\n\nIl tempo impiegato per trovare il numero %d in un vettore di %d numeri e' stato di %lu secondi.\n", nDaTrovare, numeri, tempoTrovaNumero);

                pausa();
                break;
            }

            case 5:{

                // Dividi a meta' il vettore e cerchi, di nuovo e di nuovo etc.
                printf("\n\nHai scelto: Trova valore in un vettore non ordinato con metodo ricorsivo...");

                int numeri, nDaTrovare;

                printf("\nInserire il numero di numeri casuali da generare nel vettoreCasuale_A."
                       "\nNumeri:");
                scanf("%d", &numeri);

                printf("\nInserire il numero da trovare: ");
                scanf("%d", &nDaTrovare);

                int* vettoreFinale_B = new int[numeri]();

                getVetOrdinato(numeri, vettoreFinale_B);

                clock_t inizio = clock();

                int posizione = ricercaNumeroInVettNonOrdinatoRicorsivo(vettoreFinale_B, numeri, nDaTrovare);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoTrovaNumero = (fine - inizio) / CLOCKS_PER_SEC;

                if (posizione != -1) {
                    printf("\n\nNumero %d trovato in posizione %d", nDaTrovare, posizione + 1);
                } else {
                    printf("\n\nNumero %d non trovato.", nDaTrovare);
                }
                printf("\n\nIl tempo impiegato per trovare il numero %d in un vettore di %d numeri e' stato di %lu secondi.\n", nDaTrovare, numeri, tempoTrovaNumero);

                pausa();
                break;
            }

            case 6:{

                printf("\n\nHai scelto: Trova valore in un vettore ordinato con metodo iterativo");

                int numeri, nDaTrovare;

                printf("\nInserire il numero di numeri casuali da generare nel vettoreCasuale_A."
                       "\nNumeri:");
                scanf("%d", &numeri);

                printf("\nInserire il numero da trovare: ");
                scanf("%d", &nDaTrovare);

                int* vettoreFinale_B = new int[numeri]();

                getVetOrdinato(numeri, vettoreFinale_B);

                clock_t inizio = clock();

                int posizione = nDaTrovare - 1;

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoTrovaNumero = (fine - inizio) / CLOCKS_PER_SEC;

                if (posizione != -1) {
                    printf("\n\nNumero %d trovato in posizione %d", nDaTrovare, posizione + 1);
                } else {
                    printf("\n\nNumero %d non trovato!", nDaTrovare);
                }
                printf("\n\nIl tempo impiegato per trovare il numero %d in un vettore di %d numeri e' stato di %lu secondi.", nDaTrovare, numeri, tempoTrovaNumero);

                pausa();
                break;
            }

            case 7:{

                // Dividi a meta' il vettore e cerchi, di nuovo e di nuovo etc.
                printf("\n\nHai scelto: Ricerca binaria.");

                int numeri, nDaTrovare;

                printf("\nInserire il numero di numeri casuali da generare nel vettore."
                       "\nNumeri:");
                scanf("%d", &numeri);

                printf("\nInserire il numero da trovare: ");
                scanf("%d", &nDaTrovare);

                int* vettoreFinale_B = new int[numeri]();

                getVetOrdinato(numeri, vettoreFinale_B);

                globale = 0;

                clock_t inizio = clock();

                int posizione = ricercaBinaria(vettoreFinale_B, 0, numeri - 1, nDaTrovare);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoTrovaNumero = (fine - inizio) / CLOCKS_PER_SEC;

                if (posizione != -1) {
                    printf("\n\nNumero %d trovato in posizione %d", nDaTrovare, posizione + 1);
                } else {
                    printf("\n\nNumero %d non trovato!", nDaTrovare);
                }
                printf("\n\nNumero di tentativi per trovare il numero: %d", globale);
                printf("\n\nIl tempo impiegato per trovare il numero %d in un vettore di %d numeri e' stato di %lu secondi.", nDaTrovare, numeri, tempoTrovaNumero);

                pausa();
                break;
            }

            case 8:{

                // Dividi a meta' il vettore e cerchi, di nuovo e di nuovo etc.
                printf("\n\nHai scelto: Ricerca binaria (metodo professore).");

                int numeri, nDaTrovare;

                printf("\nInserire il numero di numeri casuali da generare nel vettore."
                       "\nNumeri:");
                scanf("%d", &numeri);

                printf("\nInserire il numero da trovare: ");
                scanf("%d", &nDaTrovare);

                int* vettoreFinale_B = new int[numeri]();

                getVetOrdinato(numeri, vettoreFinale_B);

                globale = 0;

                clock_t inizio = clock();

                int posizione = ricercaBinaria(vettoreFinale_B, 0, numeri - 1, nDaTrovare);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoTrovaNumero = (fine - inizio) / CLOCKS_PER_SEC;

                if (posizione != -1) {
                    printf("\n\nNumero %d trovato in posizione %d", nDaTrovare, posizione + 1);
                } else {
                    printf("\n\nNumero %d non trovato!", nDaTrovare);
                }
                printf("\n\nNumero di tentativi per trovare il numero: %d", globale);
                printf("\n\nIl tempo impiegato per trovare il numero %d in un vettore di %d numeri e' stato di %lu secondi.", nDaTrovare, numeri, tempoTrovaNumero);

                pausa();

                break;
            }

            case 9:{
                printf("\nHai scelto: Somma elementi di un vettore iterativo.");

                int numeri, max, min;
                printf("\nInserire il numero di numeri: ");
                scanf("%d", &numeri);

                printf("\nInserire il numero massimo: ");
                scanf("%d", &max);

                printf("\nInserire il numero minimo: ");
                scanf("%d", &min);

                int* vettore = new int[numeri];

                genVetCasuali(numeri, max, min, vettore);

                printf("\nVettore generato con successo, inizio somma...\n");

                int somma = 0;

                clock_t inizio = clock();

                for (int i = 0; i < numeri; i++) {
                    somma += vettore[i];
                }

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoTrovaNumero = (fine - inizio) / CLOCKS_PER_SEC;

                printf("\nLa somma e': %d", somma);
                printf("\n\nIl tempo impiegato per eseguire la somma dei numeri in un vettore di %d numeri e' stato di %lu secondi.", numeri, tempoTrovaNumero);

                pausa();
                break;
            }

            case 10:{

                printf("\nHai scelto: Somma elementi di un vettore ricorsivo.");

                int numeri, max, min;
                printf("\nInserire il numero di numeri: ");
                scanf("%d", &numeri);

                printf("\nInserire il numero massimo: ");
                scanf("%d", &max);

                printf("\nInserire il numero minimo: ");
                scanf("%d", &min);

                int* vettore = new int[numeri];

                genVetCasuali(numeri, max, min, vettore);

                printf("\nVettore generato con successo, inizio somma...\n");

                clock_t inizio = clock();

                int somma = sommaVettoreRicorsivo(vettore, numeri);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoTrovaNumero = (fine - inizio) / CLOCKS_PER_SEC;

                printf("\nLa somma e': %d", somma);

                printf("\n\nIl tempo impiegato per eseguire la somma dei numeri in un vettore di %d numeri e' stato di %lu secondi.", numeri, tempoTrovaNumero);

                pausa();
                break;
            }

            case 11:{

                printf("\nHai scelto: Scrivi stringa e ripetila al contrario in modo ricorsivo...");

                string stringa;
                printf("\nScrivi linea da scrivere: ");
                cin >> stringa;
                printf("\n");

                scriviLineaRicorsivo(stringa);

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

void scriviLineaRicorsivo(string stringa){
    if (stringa.length() == 0){
        return;
    }

    scriviLineaRicorsivo(stringa.substr(1));
    cout << stringa[0];
}

int sommaVettoreRicorsivo(int *vet, int n){

    if (n <= 0) {
        return 0;
    }

    return sommaVettoreRicorsivo(vet, n - 1) + vet[n - 1];
}

// Ricerca del prof.
int ricercaBinaria2(int *v, int a, int b, int x){

    globale++;

    int c;
    if (b-a == 0){
        if (v[a] == x) return a;
    } else {
        return -1;
    }

    c = (a + b) / 2;

    if (v[c] >= x){
        return ricercaBinaria2(v, a, b, x);
    } else {
        return ricercaBinaria2(v, c + 1, b, x);
    }
}

int ricercaBinaria(int *vettore, int inizio, int fine, int numero){

    globale++;

    if (inizio <= fine){
        int centro = (inizio + fine) / 2;


        // Controlla se il numero si trova al centro.
        if (numero == vettore[centro]){
            return centro;
        // Controlla se il numero si trova prima od oltre il centro (legge il valore al centro e lo confronta).
        } else if (numero < vettore[centro]){

            // Legge fino a massimo la posizione centrale - 1 dall'inizio.
            return ricercaBinaria(vettore, inizio, centro - 1, numero);
        } else {

            // Legge da posizione iniziale + 1 fino a massimo.
            return ricercaBinaria(vettore, centro + 1, fine, numero);
        }
    }

    // Numero non trovato, torno valore bandiera per segnalarlo.
    return -1;
}



int ricercaNumeroInVettNonOrdinatoRicorsivo(int *vettore, int nNumeri, int numero){

    int prova;
    nNumeri--;

    if (nNumeri >= 0){
        if (vettore[nNumeri] == numero){
            return nNumeri;
        } else {
            prova = ricercaNumeroInVettNonOrdinatoRicorsivo(vettore, nNumeri, numero);
        }
    } else {
        return -1;
    }

    return prova;
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

// Fib(1) = 0
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

void getVetOrdinato(int numeri, int *vettoreFinale_B) {// Genera vettore ordinato.
    for (int i = 0; i < numeri; i++) {
        vettoreFinale_B[i] = i + 1;
    }
}

void genVetCasuali(int numeri, int max, int min, int *vettore) {
    for (int i = 0; i < numeri; i++) {
        vettore[i] = rand() % (max-min+1) + min;
    }
}

void pausa(){
    printf("\n\nInserire un numero per continuare: ");
    int numeroIgnorato;
    scanf("%d", &numeroIgnorato);
    printf("\n");
}