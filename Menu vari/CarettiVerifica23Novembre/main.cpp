#include <iostream>
#include <stdlib.h>

void genMaxMinCas(int SIZE, int MAX, int MIN, int mioVettore[]);

void chiudiTutto();

void mostraValori(int SIZE,  int mioVettore[]);

int sommaVal(int SIZE, int mioVettore[], int somma);

int menu(int SIZE, int numeroScelto, int MAX, int MIN, int mioVettore[]);

int main() {

    // Dichiaro variabili
    int SIZE = 0, numeroScelto = 1, MAX, MIN;
    int mioVettore[0];

    printf("\nBenvenuto nel menu di Caretti Gabriele...\n");

    while (numeroScelto != 0){

        printf("\n\nLegenda:");
        printf("\n0 -> Esci.");
        printf("\n1 -> Genera numeri casuali nel vettore.");
        printf("\n2 -> Mostra valori nel vettore.");
        printf("\n3 -> Mostra somma valori maggiori di 10 nel vettore.");
        printf("\n4 -> Trova posizione di un certo valore nel vettore.");

        printf("\n\nNumero scelto: ");
        scanf("%d", &numeroScelto);

        // Se il numeroScelto == 0 allora chiudi tutto
        if (numeroScelto == 0) {
            chiudiTutto();
            return 0;
        }

        numeroScelto = menu(SIZE, numeroScelto, MAX, MIN, mioVettore);
    }

    return 0;
}

int menu(int SIZE, int numeroScelto, int MAX, int MIN, int mioVettore[]) {
    switch (numeroScelto) {

        case 0: {

            numeroScelto = 0;
            break;
        }

        case 1:{

            // Messaggio
            printf("\nHai scelto: genera numeri casuali in un vettore...\n");

            // Chiedo input
            printf("\nInserisci il numero di valori che vuoi siano generati: ");
            scanf("%d", &SIZE);

            // Chiedo all'utente l'input e lo ottengo
            printf("\nInserire il valore massimo che vuoi possano assumere: ");
            scanf("%d", &MAX);

            // Chiedo all'utente l'input e l'ottengo
            printf("\nInserire il valore minimo che vuoi possano assumere: ");
            scanf("%d", &MIN);

            // Richiamo funzione
            genMaxMinCas(SIZE, MAX, MIN, mioVettore);

            // Successo
            printf("\nValori generati con successo!");

            break;
        }

        case 2:{

            // Messaggio
            printf("\nHai scelto: visualizza valori del vettore...");

            // Per ogni valore presente invio in output il valore
            printf("\nI valori sono: \n");

            // Mostro i valori
            mostraValori(SIZE, mioVettore);

            break;
        }

        case 3:{

            // Messaggio
            printf("\nHai scelto: somma dei valori maggiori di 10 presenti nel vettore...\n");

            // Dichiaro variabile
            int somma = 0;

            // Richiamo la funzione
            somma = sommaVal(SIZE, mioVettore, somma);

            // Comunico la somma
            printf("\nLa somma è %d", somma);

            break;
        }

        case 4:{

            // Dichiaro variabili
            int valore, bandiera = 0;

            // Messaggio
            printf("\nHai scelto: trova posizione di un valore nel vettore...");

            // Chiedo input
            printf("\n\nInserisci che valore cercare nel vettore: ");
            scanf("%d", &valore);

            // Provo per tutti i valori
            for (int i = 0; i < SIZE; i++) {

                // Condizione
                if (mioVettore[i] == valore){

                    // Comunico la posizione del valore, NOTA: I valori nel vettore sono da 0 a SIZE ma all'utente
                    // lo comunico da 1 a SIZE se presente
                    printf("\nIl valore %d si trova a %d.", valore, i + 1);

                    // Incremento valore bandiera
                    bandiera++;
                    break;
                }
            }

            // A causa del break il valore bandiera potrebbe non essere necessario ma è una sicurezza in più
            if (bandiera != 0) {
                printf("\nValore non trovato!");
            }

            break;
        }

        default:{

            // Valore non valido
            printf("\nHai inserito un valore non valido!");
            break;
        }
    }
    return numeroScelto;
}

int sommaVal(int SIZE, int mioVettore[], int somma) {

    // Per ogni valore verifico se è maggiore di 10, nel caso lo sia allora incremento somma di quel valore
    for (int i = 0; i < SIZE; i++) {

        if (mioVettore[i] >= 10){
            somma += mioVettore[i];
        }
    }
    return somma;
}

void mostraValori(int SIZE, int mioVettore[]) {

    // Per ogni valore eseguo l'azione
    for (int i = 0; i < SIZE; i++) {

        // Scrivo i numeri
        printf("%d \t", mioVettore[i]);
    }
}

void chiudiTutto() {

    // Messaggi d'uscita
    printf("\nHai scelto: esci e chiudi il Menu...\n");
    printf("\nChiudendo il menu...");
    printf("\n\nMenu chiuso con successo!");

}

void genMaxMinCas(int SIZE, int MAX, int MIN, int mioVettore[]) {
    srand(time(0));
    // Genero X numeri casuali con Max e Min
    for (int i = 0; i < SIZE; i++) {
        // Valore casuale compreso tra MIN e MAX
        mioVettore[i] = rand()%(MAX-(MIN) + 1) + (MIN);
    }
}
