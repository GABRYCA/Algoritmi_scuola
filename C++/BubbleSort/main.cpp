#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void mostraValori(int numeri, const int *vettore, bool mostraValori);
void pausa();

void ordinaMagMin(int numeri, int *vettore);

void bubblesort3(int numeri, int *vettore);

void bubblesort1(int numeri, int *vettore);

void ordinaMag(int numeri, int *vettore);

void bubblesort2(int numeri, int *vettore);

void genVetCasuali(int numeri, int max, int min, int *vettore);

void ord2Vet1(int numeri, int *vettore, int *vettore2);

void ord2Vet2(int numeri, int *vettore, int *vettore2);

void ord2Vet3(int numeri, int *vettore, int *vettore2);

using namespace std;

int main() {

    printf("\nAlgoritmo di G.C. 4BITI.");

    int scelta;
    srand(time(0));

    do {

        printf("\n\nOpzioni:"
               "\n0 -> Esci."
               "\n1 -> Bubblesort 1."
               "\n2 -> Bubblesort 2."
               "\n3 -> Bubblesort 3."
               "\n4 -> Insertion 1."
               "\n5 -> Insertion 2."
               "\n7 -> Selection 1."
               "\n8 -> Selection 2."
               "\n9 -> Selection 3."
               "\n10 -> Lineare 1."
               "\n11 -> Lineare 2."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Bubblesort 1.\n");

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

                genVetCasuali(numeri, max, min, vettore);

                printf("\n%d valori generati con successo!", numeri);

                clock_t inizio = clock();

                bubblesort1(numeri, vettore);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                mostraValori(numeri, vettore, false);

                pausa();
                break;
            }

            case 2:{

                // Senza ottimizzazione cicli.
                printf("\nHai scelto: Bubblesort 2.\n");

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

                genVetCasuali(numeri, max, min, vettore);

                printf("\n%d valori generati con successo!", numeri);

                clock_t inizio = clock();

                bubblesort2(numeri, vettore);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                mostraValori(numeri, vettore, false);

                pausa();
                break;
            }

            case 3:{

                // Ottimizzazione cicli e altro (Come if in meno).
                printf("\nHai scelto: Bubblesort 3.\n");

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

                genVetCasuali(numeri, max, min, vettore);

                printf("\n%d valori generati con successo!"
                       "\n\nOrdinamento in corso...", numeri);

                clock_t inizio = clock();

                bubblesort3(numeri, vettore);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                mostraValori(numeri, vettore, false);

                pausa();
                break;
            }

            case 4:{

                printf("\nHai scelto: Insertion 1.");

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

                genVetCasuali(numeri, max, min, vettore);

                printf("\n%d valori generati con successo!"
                       "\n\nRiordinamento in corso...", numeri);

                clock_t inizio = clock();

                // Riordinamento.

                ordinaMag(numeri, vettore);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                mostraValori(numeri, vettore, false);

                pausa();
                break;
            }

            case 5:{

                printf("\nHai scelto: Insertion 2.\n");

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

                genVetCasuali(numeri, max, min, vettore);

                printf("\n%d valori generati con successo!"
                       "\n\nOrdinamento in corso...", numeri);

                clock_t inizio = clock();

                // Riordinamento.

                ordinaMagMin(numeri, vettore);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                mostraValori(numeri, vettore, false);

                pausa();
                break;
            }

            case 6:{

                printf("\nHai scelto: Insertion 3.\n");

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

                genVetCasuali(numeri, max, min, vettore);

                printf("\n%d valori generati con successo!"
                       "\n\nOrdinamento in corso...", numeri);

                clock_t inizio = clock();

                // Riordinamento.

                ordinaMagMin(numeri, vettore);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                mostraValori(numeri, vettore, false);

                pausa();
                break;
            }

            case 7:{

                printf("\nHai scelto: Selection 1.\n");

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
                int* vettore2 = new int[numeri];

                genVetCasuali(numeri, max, min, vettore);

                printf("\n%d valori generati con successo!"
                       "\n\nOrdinamento in corso...", numeri);

                clock_t inizio = clock();

                // Riordinamento.

                ord2Vet1(numeri, vettore, vettore2);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                mostraValori(numeri, vettore2, false);

                pausa();
                break;
            }

            case 8:{

                printf("\nHai scelto: Selection 2.\n");

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
                int* vettore2 = new int[numeri];

                genVetCasuali(numeri, max, min, vettore);

                printf("\n%d valori generati con successo!"
                       "\n\nOrdinamento in corso...", numeri);

                clock_t inizio = clock();

                // Riordinamento.

                ord2Vet2(numeri, vettore, vettore2);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                mostraValori(numeri, vettore2, false);

                pausa();
                break;
            }

            case 9:{

                printf("\nHai scelto: Selection 3.\n");

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
                int* vettore2 = new int[numeri];

                genVetCasuali(numeri, max, min, vettore);

                printf("\n%d valori generati con successo!"
                       "\n\nOrdinamento in corso...", numeri);

                // Clono vettore1 in 2;
                for (int i = 0; i < numeri; i++) {
                    vettore2[i] = vettore[i];
                }

                clock_t inizio = clock();

                // Riordinamento.

                ord2Vet3(numeri, vettore, vettore2);

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                mostraValori(numeri, vettore2, false);

                pausa();
                break;
            }

            case 10:{

                printf("\nHai scelto: Lineare 1.");

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
                // Le () inizializzano a 0 i valori di default.
                int* vettore = new int[numeri];
                int* vettoreFinale = new int[numeri]();
                int* indice = new int[max]();

                genVetCasuali(numeri, max, min, vettore);

                printf("\n%d valori generati con successo!"
                       "\n\nOrdinamento in corso...", numeri);

                clock_t inizio = clock();

                // Conto numeri e incremento indice.
                for (int i = 0; i < numeri; i++) {
                    indice[vettore[i] - 1]++;
                }

                // Ricreo vettore finale in base all'indice.
                int numeriInseriti = 0;
                for (int i = 0; i < max; i++) {
                    for (int j = 0; j < indice[i]; j++) {
                        vettoreFinale[numeriInseriti] = i + min;
                        numeriInseriti++;
                    }
                }

                clock_t fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nIl tempo impiegato per riordinare %d numeri e' stato di %d secondi.\n", numeri, tempoRiordinamento);

                // Scrivo valori nel vettore riordinato:
                mostraValori(numeri, vettoreFinale, false);

                pausa();
                break;
            }

            case 11:{

                printf("\nHai scelto: Lineare 2...");

                pausa();
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

void ord2Vet3(int numeri, int *vettore, int *vettore2) {
    for (int j = 0; j < numeri; j++) {
        int numeroMaggiore = 0;
        int posizioneMaggiore;
        int numeroMinore = 10000;
        int posizioneMinore;

        for (int i = j; i < numeri - j; i++) {
            if (numeroMaggiore < vettore[i]){
                numeroMaggiore = vettore[i];
                posizioneMaggiore = i;
            } else if (numeroMinore > vettore[i]){
                numeroMinore = vettore[i];
                posizioneMinore = i;
            }
        }

        if (numeroMaggiore < numeroMinore){
            break;
        }

        // Trasla valori.
        /*int numeriTraslati = 0;
        for (int i = 0; i < numeri - 1; i++) {
            if (posizioneMinore != i && posizioneMaggiore != i){
                vettore[numeriTraslati] = vettore[i];
                numeriTraslati++;
            }
        }
         */


        vettore[posizioneMaggiore] = vettore[numeri - (j + 1)];
        vettore[numeri - (j + 1)] = numeroMaggiore;
        vettore[posizioneMinore] = vettore[j];
        vettore[j] = numeroMinore;

        vettore2[posizioneMaggiore] = vettore2[numeri - (j + 1)];
        vettore2[posizioneMinore] = vettore2[j];
        vettore2[numeri - (j + 1)] = numeroMaggiore;
        vettore2[j] = numeroMinore;
    }
}

void ord2Vet2(int numeri, int *vettore, int *vettore2) {
    for (int i = 0; i < numeri; i++) {
        int numeroMinore = 10000;
        int posizioneMinore;
        for (int j = 0; j < numeri - i; j++) {
            if (vettore[j] < numeroMinore){
                numeroMinore = vettore[j];
                posizioneMinore = j;
            }
        }

        // Trasla tutti i valori e "compatta" il vettore;

        for (int j = posizioneMinore; j < numeri - 1; j++) {
            vettore[j] = vettore[j + 1];
        }

        vettore2[i] = numeroMinore;
    }
}

void ord2Vet1(int numeri, int *vettore, int *vettore2) {
    for (int i = 0; i < numeri; i++) {
        int numeroMinore = 10000;
        int posizioneMinore;
        for (int j = 0; j < numeri; j++) {
            if (vettore[j] != -1){
                if (vettore[j] < numeroMinore){
                    numeroMinore = vettore[j];
                    posizioneMinore = j;
                }
            }
        }
        vettore[posizioneMinore] = -1;
        vettore2[i] = numeroMinore;
    }
}

void genVetCasuali(int numeri, int max, int min, int *vettore) {
    for (int i = 0; i < numeri; i++) {
        vettore[i] = rand() % (max-min+1) + min;
    }
}

void ordinaMag(int numeri, int *vettore) {
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
}

void bubblesort1(int numeri, int *vettore) {
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
}

void bubblesort2(int numeri, int *vettore) {
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
}

void bubblesort3(int numeri, int *vettore) {
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
}

void ordinaMagMin(int numeri, int *vettore) {
    for (int j = 0; j < numeri; j++) {
        int numeroMaggiore = 0;
        int posizioneMaggiore;
        int numeroMinore = 10000;
        int posizioneMinore;

        for (int i = j; i < numeri - j; i++) {
            if (numeroMaggiore < vettore[i]){
                numeroMaggiore = vettore[i];
                posizioneMaggiore = i;
            } else if (numeroMinore > vettore[i]){
                numeroMinore = vettore[i];
                posizioneMinore = i;
            }
        }

        if (numeroMaggiore < numeroMinore){
            break;
        }

        vettore[posizioneMinore] = vettore[j];
        vettore[j] = numeroMinore;

        vettore[posizioneMaggiore] = vettore[numeri - (j + 1)];
        vettore[numeri - (j + 1)] = numeroMaggiore;
    }
}

void mostraValori(int numeri, const int *vettore, bool mostraValori) {
    if (mostraValori){
        for (int i = 0; i < numeri; i++) {
            printf("\n%d -> %d", i + 1, vettore[i]);
        }
    }
}

void pausa(){
    printf("\n\nInserire un numero per continuare: ");
    int numeroIgnorato;
    scanf("%d", &numeroIgnorato);
    printf("\n");
}