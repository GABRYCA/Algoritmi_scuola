#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

    printf("\nAlgoritmo di G.C. 4BITI.");

    int scelta;
    srand(time(0));

    do {

        printf("\n\nOpzioni:"
               "\n0 -> Esci."
               "\n1 -> Genera e ordina numeri in un vettore con Bubblesort 2."
               "\n2 -> Genera e ordina numeri in un vettore con trova e ordina maggiore."
               "\n3 -> Genera e ordina numeri in un vettore con Bubblesort 1."
               "\n4 -> Genera e ordina numeri in un vettore con Bubblesort 3."
               "\n5 -> Genera e ordina numeri in un vettore con trova e ordina maggiore e minore."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci...");

                break;
            }

            case 1:{

                // Senza ottimizzazione cicli.
                printf("\nHai scelto: Genera vettore di numeri casuali e riordinalo con Bubblesort 1.\n");

                long int numeri;
                int max;
                int min;

                printf("\nInserire il numero di numeri casuali da generare nel vettore."
                       "\nNumeri:");
                scanf("%d", &numeri);

                printf("\nInserire il numero massimo: ");
                scanf("%d", &max);

                printf("\nInserire il numero minimo: ");
                scanf("%d", &min);

                // Generatore di numeri casuali nel vettore compreso tra 2 estremi.
                int* vettore = new int[numeri];

                for (int i = 0; i < numeri; i++) {
                    vettore[i] = (rand() % max) + min;
                }

                printf("\n%d valori generati con successo!", numeri);

                clock_t inizio = clock();

                for (int i = 0; i < numeri; i++) {
                    for (int j = 0; j < numeri - i; j++) {
                        // Evita overflow.
                        if (j + 1 < numeri){
                            int numero1 = vettore[j];
                            int numero2 = vettore[j + 1];

                            if (numero2 < numero1){
                                vettore[j] = numero2;
                                vettore[j + 1] = numero1;
                            }
                        }
                    }
                }

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                bool mostraValori = false;
                if (mostraValori){
                    for (int i = 0; i < numeri; i++) {
                        printf("\n%d -> %d", i + 1, vettore[i]);
                    }
                }

                break;
            }

            case 2:{

                printf("\nHai scelto: Genera vettore di numeri casuali e ordinali con metodo 2.");

                int numeri;
                int max;
                int min;

                printf("\nInserire il numero di numeri casuali da generare nel vettore."
                       "\nNumeri:");
                scanf("%d", &numeri);

                printf("\nInserire il numero massimo: ");
                scanf("%d", &max);

                printf("\nInserire il numero minimo: ");
                scanf("%d", &min);

                // Generatore di numeri casuali nel vettore compreso tra 2 estremi.
                int* vettore = new int[numeri];

                for (int i = 0; i < numeri; i++) {
                    vettore[i] = (rand() % max) + min;
                }

                printf("\n%d valori generati con successo!"
                       "\n\nRiordinamento in corso...", numeri);

                clock_t inizio = clock();

                // Riordinamento.

                for (int j = 0; j < numeri; j++) {
                    int numeroMaggiore = 0;
                    int posizioneMaggiore;
                    for (int i = 0; i < numeri - j; i++) {
                        if (vettore[i] > numeroMaggiore){
                            numeroMaggiore = vettore[i];
                            posizioneMaggiore = i;
                        }
                    }
                    vettore[posizioneMaggiore] = vettore[numeri - (j + 1)];
                    vettore[numeri - (j + 1)] = numeroMaggiore;
                }

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                bool mostraValori = false;
                if (mostraValori){
                    for (int i = 0; i < numeri; i++) {
                        printf("\n%d -> %d", i + 1, vettore[i]);
                    }
                }

                break;
            }

            case 3:{

                printf("\nHai scelto: Genera valori in un vettore di numeri casuali e ordina con Bubblesort 1.\n");

                long int numeri;
                int max;
                int min;

                printf("\nInserire il numero di numeri casuali da generare nel vettore."
                       "\nNumeri:");
                scanf("%d", &numeri);

                printf("\nInserire il numero massimo: ");
                scanf("%d", &max);

                printf("\nInserire il numero minimo: ");
                scanf("%d", &min);

                // Generatore di numeri casuali nel vettore compreso tra 2 estremi.
                int* vettore = new int[numeri];

                for (int i = 0; i < numeri; i++) {
                    vettore[i] = (rand() % max) + min;
                }

                printf("\n%d valori generati con successo!", numeri);

                clock_t inizio = clock();

                for (int i = 0; i < numeri; i++) {
                    for (int j = 0; j < numeri; j++) {
                        // Evita overflow.
                        if (j + 1 < numeri){
                            int numero1 = vettore[j];
                            int numero2 = vettore[j + 1];

                            if (numero2 < numero1){
                                vettore[j] = numero2;
                                vettore[j + 1] = numero1;
                            }
                        }
                    }
                }

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                bool mostraValori = false;
                if (mostraValori){
                    for (int i = 0; i < numeri; i++) {
                        printf("\n%d -> %d", i + 1, vettore[i]);
                    }
                }

                break;
            }

            case 4:{

                // Ottimizzazione cicli e altro (Come if in meno).
                printf("\nHai scelto: Genera e ordina numeri in un vettore con Bubblesort 3.\n");

                long int numeri;
                int max;
                int min;

                printf("\nInserire il numero di numeri casuali da generare nel vettore."
                       "\nNumeri:");
                scanf("%d", &numeri);

                printf("\nInserire il numero massimo: ");
                scanf("%d", &max);

                printf("\nInserire il numero minimo: ");
                scanf("%d", &min);

                // Generatore di numeri casuali nel vettore compreso tra 2 estremi.
                int* vettore = new int[numeri];

                for (int i = 0; i < numeri; i++) {
                    vettore[i] = (rand() % max) + min;
                }

                printf("\n%d valori generati con successo!"
                       "\n\nOrdinamento in corso...", numeri);

                clock_t inizio = clock();

                bool ordinato = false;
                for (int i = 0; i < numeri; i++) {
                    if (!ordinato) {
                        for (int j = 0; j < numeri - i - 1; j++) {
                            int numero1 = vettore[j];
                            int numero2 = vettore[j + 1];

                            if (numero2 < numero1) {
                                vettore[j] = numero2;
                                vettore[j + 1] = numero1;
                            }
                        }
                    } else {
                        break;
                    }
                    ordinato = true;
                    for (int k = 0; (k < numeri - 1) && ordinato; k++) {
                        if (vettore[k] > vettore[k + 1]){
                            ordinato = false;
                        }
                    }
                }

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                bool mostraValori = false;
                if (mostraValori){
                    for (int i = 0; i < numeri; i++) {
                        printf("\n%d -> %d", i + 1, vettore[i]);
                    }
                }

                break;
            }

            case 5:{

                printf("\nHai scelto: Genera un vettore di numeri casuali e ordinali cercando maggiore e minore.\n");

                long int numeri;
                int max;
                int min;

                printf("\nInserire il numero di numeri casuali da generare nel vettore."
                       "\nNumeri:");
                scanf("%d", &numeri);

                printf("\nInserire il numero massimo: ");
                scanf("%d", &max);

                printf("\nInserire il numero minimo: ");
                scanf("%d", &min);

                // Generatore di numeri casuali nel vettore compreso tra 2 estremi.
                int* vettore = new int[numeri];

                for (int i = 0; i < numeri; i++) {
                    vettore[i] = (rand() % max) + min;
                }

                printf("\n%d valori generati con successo!"
                       "\n\nOrdinamento in corso...", numeri);

                clock_t inizio = clock();

                // Riordinamento.

                int numeriMaggioreEMinori = 0;
                for (int j = 0; j < numeri / 2; j++) {
                    int numeroMaggiore = 0;
                    int posizioneMaggiore;
                    int numeroMinore = 10000;
                    int posizioneMinore;

                    for (int i = numeriMaggioreEMinori; i < numeri - numeriMaggioreEMinori; i++) {
                        if (numeroMaggiore < vettore[i]){
                            numeroMaggiore = vettore[i];
                            posizioneMaggiore = i;
                        } else if (numeroMinore > vettore[i]){
                            numeroMinore = vettore[i];
                            posizioneMinore = i;
                        }
                    }

                    vettore[posizioneMaggiore] = vettore[numeri - numeriMaggioreEMinori];
                    vettore[numeri - numeriMaggioreEMinori] = numeroMaggiore;

                    vettore[posizioneMinore] = vettore[numeriMaggioreEMinori];
                    vettore[numeriMaggioreEMinori] = numeroMinore;

                    numeriMaggioreEMinori++;
                }

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                bool mostraValori = false;
                if (mostraValori){
                    for (int i = 0; i < numeri; i++) {
                        printf("\n%d -> %d", i + 1, vettore[i]);
                    }
                }

                break;
            }

            default:{

                printf("\nHai scelto un'opzione non valida, per favore riprovare.");

                break;
            }

        }

    } while (scelta != 0);

    printf("\nUscito con successo.");

    return 0;
}
