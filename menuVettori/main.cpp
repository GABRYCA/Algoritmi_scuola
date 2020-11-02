#include <iostream>
#include <stdio.h>

using namespace std;


// Dichiaro i prototipi
int moltiplicazione(int x, int y);

int divisione(int x, int y);

int divisioneResto(int x, int y);

void indovinaNumero();

int contaDimezza(int num);

void numeriGenMaxMin(int max, int min, int nNum, int contatore1, int maxTrovato, int minTrovato);

void secondoMenu(int *mioVettore, int dimensione);

int main() {

    // Dichiaro parametri
    int nAlgoritmoScelto = 1;

    while (nAlgoritmoScelto != 0){

        printf("\nScegli un numero per avviare un programma o algoritmo, ti basterà digitarlo e premere invio, eccone la lista: \n");

        printf("1 -> Fine.\n");
        printf("2 -> Memorizzo N numero e li mostro.\n");
        printf("3 -> Genero N numeri casuali in un range.\n");
        printf("4 -> Gioco dei numeri casuali.\n");
        printf("5 -> Genero X numeri casuali e mostro il maggiore e minore.\n");

        printf("Valore inserito: ");

        // Ottengo dall'utente l'input
        scanf("%d", &nAlgoritmoScelto);

        // Switch degli algoritmi in base a quello scelto
        switch (nAlgoritmoScelto) {

            case 1:{

                printf("\nHai scelto: FINE!");

                nAlgoritmoScelto = 0;

                break;
            }

            case 2: {

                printf("\nHai scelto: Inserisci valori in un vettore manualmente...\n");

                int valori = 0, contatore = 0, valore = 0;

                printf("\nQuanti valori vuoi inserire: ");
                scanf("%d", &valori);

                int mioVettore[valori];

                while (contatore != valori){

                    printf("\nInserire il valore:");
                    scanf("%d", &valore);

                    mioVettore[contatore] = valore;

                    contatore++;
                }

                // Chiedo all'utente se vuole continuare
                printf("\nVuoi continuare? Inserire 0 per uscire e 1 per continuare: ");
                scanf("%d", &nAlgoritmoScelto);

                secondoMenu(mioVettore, contatore);

                break;
            }

            case 3: {

                printf("Hai scelto: Generatore numeri casuali...\n");

                // Ottengo TANTI dall'utente
                int TANTI;
                printf("\nInserire quanti numeri CASUALI vuoi trovare: ");
                scanf("%d", &TANTI);

                // Ottengo MAX dall'utente
                int MAX;
                printf("Inserire il valore massimo che vuoi possano assumere: ");
                scanf("%d", &MAX);

                int mioVettore[TANTI];
                srand(time(0));

                // Generatore numeri casuali
                for (int conta = 0; conta < TANTI; conta++) {
                    // Ottengo un valore casuale compreso tra 0 e MAX
                    mioVettore[conta] = (rand() % MAX);
                }

                // Chiedo all'utente se vuole continuare
                printf("\nVuoi continuare? Inserire 0 per uscire e 1 per continuare: ");
                scanf("%d", &nAlgoritmoScelto);

                secondoMenu(mioVettore, TANTI);

                break;
            }

            case 4: {

                // Messaggi d'inizio
                printf("Hai scelto: Indovina numero casuale...\n");
                printf("\nIl numero casuale da indovinare è compreso tra -10 e 20, hai 10 solo tentativi!");

                // Richiamo la funzione
                indovinaNumero();

                // Chiedo all'utente se vuole continuare
                printf("\nVuoi continuare? Inserire 0 per uscire e 1 per continuare: ");
                scanf("%d", &nAlgoritmoScelto);

                break;
            }

            case 5: {

                // Messaggio d'inizio
                printf("\nHai scelto: Generea x numeri casuali compresi in un intervallo e mostra il MAGGIORE e MINORE.");

                // Dichiaro parametri e variabili
                int max, min, nNum, contatore1 = 0, maxTrovato, minTrovato;

                // Ottengo dall'utente i vari input
                printf("\nInserire numero massimo: ");
                scanf("%d", &max);
                printf("\nInserire numero minimo: ");
                scanf("%d", &min);
                printf("\nInserire QUANTI NUMERI generare: ");
                scanf("%d", &nNum);

                // Dichiaro il vettore
                int mioVettore[nNum];

                // Assegno un valore al vettore
                mioVettore[contatore1] = rand() % (max - (min) + 1) + (min);

                // Dichiaro le variabili con il loro valore iniziale
                maxTrovato = mioVettore[contatore1];
                minTrovato = mioVettore[contatore1];

                // Ripeto il loop finchè il contatore non diventa maggiore di nNum
                while (contatore1 < nNum){

                    // Incremento il contatore
                    contatore1++;

                    // Assegno un nuovo valore al vettore
                    mioVettore[contatore1] = rand() % (max - (min) + 1) + (min);

                    // Controllo se è maggiore o minore e nel caso di una condizione soddisfatta, assegno un nuovo valore
                    if (mioVettore[contatore1] > maxTrovato){
                        maxTrovato = mioVettore[contatore1];
                    } else if (mioVettore[contatore1] < minTrovato){
                        minTrovato = mioVettore[contatore1];
                    }
                }

                // Comunico il numero maggiore e minore casuale generato
                printf("Il numero maggiore trovato è %d e il minore %d", maxTrovato, minTrovato);

                // Chiedo all'utente se vuole continuare
                printf("\nVuoi continuare? Inserire 0 per uscire e 1 per continuare: ");
                scanf("%d", &nAlgoritmoScelto);

                secondoMenu(mioVettore, contatore1);

                break;
            }

            default: {

                // Comunico all'utente che non ha un valore valido
                printf("\n[ERRORE] -> Il valore inserito non � valido!");

                // Chiedo all'utente se vuole continuare
                printf("\nVuoi continuare? Inserire 0 per uscire e 1 per continuare: ");
                scanf("%d", &nAlgoritmoScelto);

                break;
            }
        }
    }

    return 0;
}

void secondoMenu(int *mioVettore, int dimensione){

    // Dichiaro parametri
    int nAlgoritmoScelto = 1;

    while (nAlgoritmoScelto != 0){

        printf("1 -> FINE!\n");
        printf("2 -> Visualizza il vettore.\n");
        printf("3 -> Raddoppia il vettore.\n");
        printf("4 -> Dimezza il vettore fino all'unità.\n");
        printf("5 -> Dimezza il vettore.\n");

        printf("Valore inserito: ");

        // Ottengo dall'utente l'input
        scanf("%d", &nAlgoritmoScelto);

        // Switch degli algoritmi in base a quello scelto
        switch (nAlgoritmoScelto) {

            case 1:{

                printf("Hai scelto: FINE!");

                nAlgoritmoScelto = 0;

                break;
            }

            case 2:{

                printf("Hai scelto: Visualizza il vettore.\n");

                printf("I valori sono: \n");
                for (int i = 0; i < dimensione; i++) {

                    // Scrivo i numeri
                    printf("%d \t", mioVettore[i]);

                }

                // Chiedo all'utente se vuole continuare
                printf("\nVuoi continuare? Inserire 0 per uscire e 1 per continuare: ");
                scanf("%d", &nAlgoritmoScelto);

                break;
            }

            case 3:{

                printf("Hai scelto: Raddoppia il vettore.\n");

                for (int i = 0; i < dimensione; i++) {

                    // Raddoppio
                    mioVettore[i] = mioVettore[i] * 2;

                }

                printf("Raddoppiati i valori con successo!\n");

                // Chiedo all'utente se vuole continuare
                printf("\nVuoi continuare? Inserire 0 per uscire e 1 per continuare: ");
                scanf("%d", &nAlgoritmoScelto);

                break;
            }

            case 4:{

                // Messaggio d'inizio
                printf("\nHai scelto: Quante volte Dimezzare un numero fino ad arrivare all'unità...");
                printf("\nInserire il numero da dimezzare: ");

                // Dichiaro le variabili e i parametri
                int num, nVolte;

                // Ottengo l'input dell'utente
                scanf("%d", &num);

                // Richiamo la funzione
                nVolte = contaDimezza(num);

                // Comunico il risultato all'utente
                printf("Il numero è stato dimezzato -%d- volte. Significa che per trovare un numero compreso servirebbero circa %d tentativi.",
                       nVolte, nVolte * 2);

                // Chiedo all'utente se vuole continuare
                printf("\nVuoi continuare? Inserire 0 per uscire e 1 per continuare: ");
                scanf("%d", &nAlgoritmoScelto);

                break;
            }

            case 5:{

                printf("Hai scelto: Dimezza vettore.\n");

                for (int i = 0; i < dimensione; i++) {

                    // Raddoppio
                    mioVettore[i] = mioVettore[i] / 2;

                }

                printf("Dimezzati i valori con successo!\n");

                // Chiedo all'utente se vuole continuare
                printf("\nVuoi continuare? Inserire 0 per uscire e 1 per continuare: ");
                scanf("%d", &nAlgoritmoScelto);

                break;
            }

            default: {

                // Comunico all'utente che non ha un valore valido
                printf("\n[ERRORE] -> Il valore inserito non � valido!");

                // Chiedo all'utente se vuole continuare
                printf("\nVuoi continuare? Inserire 0 per uscire e 1 per continuare: ");
                scanf("%d", &nAlgoritmoScelto);

                break;
            }
        }

    }
}


int contaDimezza(int num) {

    // Dichiaro parametri e variabili
    int nVolte = 0, dimezzatore = 2;

    while (num >= 2){

        num = divisione(num, dimezzatore);

        nVolte++;

    }
    return nVolte;
}


int moltiplicazione(int x, int y){

    int ris = 0;

    // Ripeti il loop fino a quando la condizione diventa falsa

    while (y > 0) {

        ris += x;

        y--;

    }

    return ris;

}

int divisione(int x, int y){

    int ris = 0;

    // Loop fino a quando x non diventa minore a y
    while (x >= y){

        x -= y;

        ris++;

    }

    return ris;
}

int divisioneResto(int x, int y){

    int ris = 0;

    // Loop fino a quando x non diventa minore a y
    while (x >= y){

        x -= y;

        ris++;

    }

    return x;

}

void indovinaNumero() {
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
                break;
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
}