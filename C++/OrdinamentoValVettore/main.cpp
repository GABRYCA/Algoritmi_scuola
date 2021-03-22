#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

void continua();

long random(int min, int max);

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           Ord.Vet. di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;
    while (scelta != 0) {

        printf("\nLegenda scelte:"
               "\n0 -> Esci."
               "\n1 -> Ordinamento vettore numeri casuali."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nUscita in corso...");

                break;
            }

            case 1: {
                // Messaggio d'inizio.
                printf("\nHai scelto: ordinamento numeri in un vettore casuale dal più piccolo al più grande...");

                // Inserimento dati per variabili dell'utente.
                long nNumeri;
                int max, min;
                printf("\nInserire numero di valori da generare: ");
                scanf("%ld", &nNumeri);
                printf("\nInserire numero massimo possibile: ");
                scanf("%d", &max);
                printf("\nInserire numero minore: ");
                scanf("%d", &min);

                srand(time(0));

                clock_t inizio = clock();

                // Genero valori casuali tra max e min per tutto il vettore.
                long vettoreConNumeri[nNumeri];
                for (long i = 0; i < nNumeri; i++) {
                    vettoreConNumeri[i] = random(min, max);
                }

                clock_t fine = clock();

                // Tempo di fine.
                unsigned long risultatoGenNumeri = (fine - inizio)/CLOCKS_PER_SEC;

                inizio = clock();

                // Faccio un ciclo per l'intero vettore, ogni valore sarà spostato nella nuova posizione.
                long vecchioNumero;
                for (long i = 0; i < nNumeri; i++) {

                    // Faccio un ciclo per tutto il vettore a partire dal valore successivo alla posizione di assegnamento.
                    for (long j = i + 1; j < nNumeri; j++) {

                        // Verifico se il numero che sto verificando è maggiore di quello attualmente presente.
                        if (vettoreConNumeri[i] > vettoreConNumeri[j]) {

                            // Scambio i valori appoggiandomi ad una variabile temporanea.
                            vecchioNumero = vettoreConNumeri[i];
                            vettoreConNumeri[i] = vettoreConNumeri[j];
                            vettoreConNumeri[j] = vecchioNumero;
                        }
                    }
                }

                fine = clock();

                // Tempo di fine.
                unsigned long risultatoOrdinamentoNumeri = (fine - inizio)/CLOCKS_PER_SEC;

                // Leggo tutti i valori in ordine del nuovo vettore.
                for (long i = 0; i < nNumeri; i++) {
                    printf("\n%ld -> %ld", i + 1, vettoreConNumeri[i]);
                }

                cout << "\n\nSono stati necessari: " << risultatoGenNumeri << " secondi per generare i numeri!" << endl;
                cout << "Sono stati necessari: " << risultatoOrdinamentoNumeri << " secondi per riordinare i numeri!"
                     << endl;

                continua();
                break;
            }

            default:{

                printf("\nScelta non valida, per favore riprovare!");

                break;
            }
        }
    }

    printf("\nUscito con successo!");
    return 0;
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}

long random(int min, int max){
    int randomMN1 = max - min + 1 ;
    return ((int) rand() % randomMN1 + min);
}