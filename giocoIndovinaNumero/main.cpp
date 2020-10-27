#include <iostream>
#include <stdio.h>
#include <time.h>

// Analisi:

// Dati in ingresso: x
// Dati in uscita: Errore, Maggiore o Minore, Indovinato, Numero tentativi, Tentativi rimasti.

// Idea risolutiva:
// All'avvio del programma si generà un numero compreso in un intervallo stabilito dal programma ma NON dall'utente.
// Successivamente si comunicherà all'utente di inserire un numero e quanti tentativi avrà.
// Si prenderà il numero dell'utente, aggiungerà al vettore Tentativi poi si confronterà con quello casuale,
// Se questo è uguale, allora si comunicherà all'utente che ha indovinato e quanti tentativi ha usato, in caso
// Contrario si chiederà un altro numero, si decrementerà il numero di tentativi rimasti finchè non arriva a 0, se
// arrivasse a zero, allora l'utente perde e il programma finisce, in caso contrario si ripete il loop e si verifica
// Ogni volta se il numero inserito dall'utente è maggiore o minore di quello casuale, come consiglio.
// Alla fine del programma si comunicheranno anche tutti i numeri inseriti e quello corretto casuale.

void numeriProvati(int conta, const int *numeriInseriti);

int main() {

    // Messaggi d'inizio
    printf("Hai scelto: Indovina numero casuale...\n");
    printf("\nIl numero casuale da indovinare è compreso tra -10 e 20. Hai solo 10 tentativi!");

    int tentativi = 10, conta = 0, x;
    int numeriInseriti[tentativi];


    // Ottengo x dall'utente
    printf("\nInserisci il numero con cui provare: ");
    scanf("%d", &x);

    // Genero un numero casuale compreso tra 20 e -10
    srand(time(0));
    int numeroCasuale = rand() % (20 - (-10) + 1) + (-10);

    // While che va avanti finchè i tentativi non sono uguali a 0
    while (tentativi >= 0) {

        // Assegna il valore al vettore e lo incrementa
        numeriInseriti[conta++] = x;

        // Se l'utente ha indovinato il numero, finisce
        if (x == numeroCasuale) {

            // Messaggio della vittoria e quanti tentativi sono stati usati
            printf("\nHai indovinato il numero al %d° tentativo", conta);
            numeriProvati(conta, numeriInseriti);

            // Ferma il programma
            return 0;
        } else {

            // Decrementa il numero di tentativi rimasti
            tentativi--;

            // L'utente ha finito i tentativi e ha quindi perso
            if (tentativi <= 0) {

                // Messaggio della sconfitta
                printf("\nHai finito i tentativi! Hai inserito i seguenti numeri:");
                numeriProvati(conta, numeriInseriti);

                return 0;
            }

            // Comunica all'utente che ha un numero errato
            printf("\nHai inserito un numero errato, hai ancora %d tentativi!\n", tentativi);
            if (x > numeroCasuale) {

                // Consiglio
                printf("\nConsiglio: il numero inserito è -MAGGIORE- di quello da indovinare!");

            } else if (x < numeroCasuale) {

                // Consiglio
                printf("\nConsiglio: Il numero inserito è -MINORE- di quello da indovinare!");

            }
        }

        // Messaggio che invita l'utente a riprovare e quindi inserire un nuovo x
        printf("\nInserisci il nuovo numero con cui provare: ");
        scanf("%d", &x);

    }
    return 0;
}

void numeriProvati(int conta, const int *numeriInseriti) {// Visualizzatore numeri inseriti

    printf("\nI numeri che hai provato sono: \n");
    for (int i = 0; i < conta; i++) {

        // Scrivo i numeri
        printf("%d \t", numeriInseriti[i]);

    }
}

