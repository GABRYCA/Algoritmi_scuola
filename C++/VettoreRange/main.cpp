#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

void pausa();

void genVetCasuali(int numeri, int max, int min, int *vettore);

void mostraValori(int numeri, const int *vettore, bool mostraValori);

void rangeValoriVett(int numeri, const int *vettore, int &val, int &numeroCicli);

bool debug = false;

int main() {

    printf("\n\nAlgoritmi di G.C. 4BITI.");
    int scelta;

    srand(time(0));

    do {

        printf("\n\nScelte:"
               "\n0 -> Esci."
               "\n1 -> Genera vettore di numeri casuali e sposta i numeri rispetto al valore del primo."
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

                rangeValoriVett(numeri, vettore, val, numeroCicli);

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

            default:{

                printf("\nHai scelto un valore non valido, per favore riprovare!");

                break;
            }
        }

    } while (scelta != 0);

    printf("\nUscito con successo!");

    return 0;
}

void rangeValoriVett(int numeri, const int *vettore, int &val, int &numeroCicli) {
    val= vettore[0];
    numeroCicli= 0;
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
