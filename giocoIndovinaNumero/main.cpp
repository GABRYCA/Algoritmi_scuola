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

int main() {

    // Messaggi d'inizio
    printf("Hai scelto: Indovina numero casuale...\n");
    printf("\nIl numero casuale da indovinare è compreso tra -10 e 20, hai 10 solo tentativi!");

    int tentativi = 10, conta = 1, x;
    int numeriInseriti[tentativi];

    // Ottengo x dall'utente
    printf("\nInserisci il numero con cui provare: ");
    scanf("%d", &x);

    // Genero un numero casuale compreso tra 20 e -10
    srand(time(0));
    int numeroCasuale = rand()%(20-(-10) + 1) + (-10);

    // Controllo se l'utente ha trovato il numero al primo tentativo
    if (x == numeroCasuale){

        printf("\nComplimenti, hai indovinato il numero al primo tentativo! Era %d", numeroCasuale);

    // Vado avanti se non l'ha indovinato subito
    } else {

        // Decremento il numero di tentativi rimasti
        tentativi--;

        // Comunico all'utente che il numero che aveva inserito era errato
        printf("\nHai inserito un numero errato, hai ancora %d tentativi!\n", tentativi);
        if (x > numeroCasuale){

            // Consiglio per trovare il numero
            printf("\nConsiglio: il numero inserito è -MAGGIORE- di quello da indovinare!");

        } else if (x < numeroCasuale){

            // Consiglio per trovare il numero
            printf("\nConsiglio: Il numero inserito è -MINORE- di quello da indovinare!");

        }

        // While che va avanti finchè i tentativi non sono uguali a 0
        while (tentativi >= 0){

            // Assegna il valore al vettore e lo incrementa
            numeriInseriti[conta++] = x;

            // L'utente ha finito i tentativi e ha quindi perso
            if (tentativi <= 0){

                // Messaggio della sconfitta
                printf("\nHai finito i tentativi! Hai inserito i seguenti numeri:");

                // Visualizzatore numeri inseriti
                printf("\nI numeri che hai provato sono: \n");
                for (int i = 1; i < conta; i++) {

                    // Scrivo i numeri
                    printf("%d \t", numeriInseriti[i]);

                }
            }

            // Messaggio che invita l'utente a riprovare e quindi inserire un nuovo x
            printf("\nInserisci il nuovo numero con cui provare: ");
            scanf("%d", &x);

            // Se l'utente ha indovinato il numero, finisce
            if (x == numeroCasuale){

                // Messaggio della vittoria e quanti tentativi sono stati usati
                printf("\nHai indovinato il numero al %d° tentativo", conta);

                // Visualizzatore numeri inseriti
                printf("\nI numeri che hai provato sono: \n");
                for (int i = 1; i < conta; i++) {

                    // Scrivo i numeri
                    printf("%d \t", numeriInseriti[i]);

                }

                // Ferma il programma
                return 0;
            } else {

                // Decrementa il numero di tentativi rimasti
                tentativi--;

                // Comunica all'utente che ha un numero errato
                printf("\nHai inserito un numero errato, hai ancora %d tentativi!\n", tentativi);
                if (x > numeroCasuale){

                    // Consiglio
                    printf("\nConsiglio: il numero inserito è -MAGGIORE- di quello da indovinare!");

                } else if (x < numeroCasuale){

                    // Consiglio
                    printf("\nConsiglio: Il numero inserito è -MINORE- di quello da indovinare!");

                }
            }
        }
    }

    return 0;
}

