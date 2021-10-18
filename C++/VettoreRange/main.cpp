#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <utility>

using namespace std;

void pausa();

void genVetCasuali(int numeri, int max, int min, int *vettore);

void mostraValori(int numeri, const int *vettore, bool mostraValori);

int partition(int *A, int inizio, int nNumeri);

bool debug = false;

int main() {

    printf("\n\nAlgoritmi di G.C. 4BITI.");
    int scelta;

    srand(time(0));

    do {

        printf("\n\nScelte:"
               "\n0 -> Esci."
               "\n1 -> Genera vettore di numeri casuali e sposta i numeri rispetto al valore del primo."
               "\n2 -> Partition del professore."
               "\n3 -> Partition delle partizioni gia' fatte."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0:{

                printf("\nHai scelto: Esci...");

                break;
            }

            case 1:{

                printf("\n\nHai scelto: Sposta valori di un vettore all'inizio o fine rispetto al primo valore.");

                int numeri, max, min;
                printf("\nInserire il numero di numeri: ");
                scanf("%d", &numeri);

                printf("\nInserire il numero massimo: ");
                scanf("%d", &max);

                printf("\nInserire il numero minimo: ");
                scanf("%d", &min);

                printf("\n\nGenerando un vettore con %d numeri casuali tra %d e %d...", numeri, min, max);

                int* vettore = new int[numeri];

                genVetCasuali(numeri, max, min, vettore);

                printf("\n\nVettore con numeri casuali generato con successo!");

                int val;
                int numeroCicli;

                clock_t inizioT = clock();

                val = vettore[0];
                numeroCicli = 0;
                int daFineOrdinati = 0;
                int daInizioOrdinati = 0;
                printf("\n\nOrdinamento dei valori maggiori o minori a %d...", val);
                while ((daInizioOrdinati + daFineOrdinati) < numeri - 2){
                    int inizio = vettore[daInizioOrdinati];
                    int fine = vettore[numeri - (daFineOrdinati + 1)];

                    if (debug) {
                        printf("\nvalInizio %d, valFine %d", inizio, fine);
                    }

                    // Conta i numeri che sono gia' in posizioni corrette alla fine.
                    while (fine >= val){
                        if (debug) {
                            printf("\nvalFine %d (%d) e' gia' giusto.", fine, daFineOrdinati);
                            numeroCicli++;
                        }
                        daFineOrdinati++;
                        fine = vettore[numeri - (daFineOrdinati + 1)];
                    }

                    // Conta i numeri che sono gia' in posizioni corrette alla fine.
                    while (inizio <= val){
                        if (debug) {
                            printf("\nvalInizio %d (%d) e' gia' giusto.", inizio, daInizioOrdinati);
                            numeroCicli++;
                        }
                        daInizioOrdinati++;
                        inizio = vettore[daInizioOrdinati];
                    }

                    if (inizio > val && fine < val){
                        if (debug) {
                            printf("\nScambiati %d (%d) e %d (%d)", vettore[daInizioOrdinati], daInizioOrdinati,
                                   vettore[numeri - (daFineOrdinati + 1)], numeri - (daFineOrdinati + 1));
                        }
                        swap(vettore[daInizioOrdinati], vettore[numeri - (daFineOrdinati + 1)]);
                        daInizioOrdinati++;
                        daFineOrdinati++;
                    }

                    if (debug) {
                        printf("\n\nSomma = %d", daInizioOrdinati + daFineOrdinati);
                        numeroCicli++;
                    }
                }

                clock_t fineT = clock();

                if (debug){
                    printf("\n\nNumero cicli %d.", numeroCicli);
                }

                printf("\n\nValori spostati con successo secondo i criteri specificati (val = %d)!", val);

                // Tempo necessario al riordinamento.
                unsigned long tempoOrdinamento = (fineT - inizioT) / CLOCKS_PER_SEC;

                printf("\nIl tempo impiegato per eseguire l'operazione con %d numeri e' stato di %lu secondi.", numeri, tempoOrdinamento);

                mostraValori(numeri, vettore, debug);

                pausa();
                break;
            }

            case 2:{

                printf("\n\nHai scelto: Partition migliorato e ispirato allo pseudo-codice del professore.");

                int numeri, max, min;
                printf("\nInserire il numero di numeri: ");
                scanf("%d", &numeri);

                printf("\nInserire il numero massimo: ");
                scanf("%d", &max);

                printf("\nInserire il numero minimo: ");
                scanf("%d", &min);

                printf("\n\nGenerando un vettore con %d numeri casuali tra %d e %d...", numeri, min, max);

                int* vettore = new int[numeri];
                genVetCasuali(numeri, max, min, vettore);

                printf("\n\nVettore con numeri casuali generato con successo!");
                printf("\n\nPartition in corso tramite valore %d...", vettore[0]);

                clock_t inizioT = clock();

                partition(vettore, 0, numeri);

                clock_t fineT = clock();

                printf("\n\nOperazione completata con successo!");

                // Tempo necessario al riordinamento.
                unsigned long tempoOrdinamento = (fineT - inizioT) / CLOCKS_PER_SEC;

                printf("\nIl tempo impiegato per eseguire l'operazione con %d numeri e' stato di %lu secondi.", numeri, tempoOrdinamento);

                mostraValori(numeri, vettore, true);

                pausa();
                break;
            }

            case 3:{
                printf("\n\nHai scelto: Partition delle Partition gia' fatte (doppio partition).");

                int numeri, max, min;
                printf("\nInserire il numero di numeri: ");
                scanf("%d", &numeri);

                printf("\nInserire il numero massimo: ");
                scanf("%d", &max);

                printf("\nInserire il numero minimo: ");
                scanf("%d", &min);

                printf("\n\nGenerando un vettore con %d numeri casuali tra %d e %d...", numeri, min, max);

                int* vettore = new int[numeri];
                genVetCasuali(numeri, max, min, vettore);

                printf("\n\nVettore con numeri casuali generato con successo!");
                printf("\n\nPartition in corso tramite valore %d...", vettore[0]);

                clock_t inizioT = clock();

                int incontro = partition(vettore, 0, numeri);

                printf("\nPrima partition completata, inizio seconda (da inizio a punto d'incontro), valore %d...", vettore[0]);

                partition(vettore, 0, incontro);

                printf("\nSeconda partition completata, inizio terza (da punto d'incontro a fine), valore %d...", vettore[incontro]);

                partition(vettore, incontro, numeri);

                clock_t fineT = clock();

                printf("\n\nOperazione completata con successo!");

                // Tempo necessario al riordinamento.
                unsigned long tempoOrdinamento = (fineT - inizioT) / CLOCKS_PER_SEC;

                printf("\nIl tempo impiegato per eseguire l'operazione con %d numeri e' stato di %lu secondi.", numeri, tempoOrdinamento);

                mostraValori(numeri, vettore, true);

                pausa();
                break;
            }

            default:{

                printf("\nHai scelto un valore non valido, per favore riprovare!");

                break;
            }
        }

    } while (scelta != 0);

    printf("\nUscito con successo!");

    return 0;
}

/**
 * A e' il vettore.
 * inizio e' la posizione iniziale o fin dove e' ordinato.
 * nNumeri e' il numero di numeri, ossia la fine o fin dove ordinare.
 *
 * La condizione di fine resta nel fatto che quando questi due si incontrano (diventano uguali), allora si ha finito
 * e si ritorna il valore della posizione in cui si incontrano.
 * */
int partition(int *A, int inizio, int nNumeri){

    int val = A[inizio];
    int inizioPos = inizio;
    int fine = nNumeri - 1;
    while (true) {

        while (A[fine] >= val){
            fine--;
        }

        if (inizioPos == inizio){
            swap(A[inizioPos], A[fine]);
            inizioPos++;
            fine--;
        }

        while (A[inizioPos] <= val){
            inizioPos++;
        }

        if (inizioPos < fine){
            swap(A[inizioPos], A[fine]);
        } else {
            return fine;
        }
    }
}

void mostraValori(int numeri, const int *vettore, bool mostraValori) {
    if (mostraValori){
        for (int i = 0; i < numeri; i++) {
            printf("\n%d -> %d", i + 1, vettore[i]);
        }
    }
}

void genVetCasuali(int numeri, int max, int min, int *vettore) {
    for (int i = 0; i < numeri; i++) {
        vettore[i] = rand() % (max-min+1) + min;
    }
}

void pausa(){
    printf("\n\nInserire un numero per continuare: ");
    int numero;
    scanf("%d", &numero);
}