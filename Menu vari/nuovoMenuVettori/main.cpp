#include <iostream>
#include <stdlib.h>
#include <cmath>

int contaDimezza(int num);

void indovinaNumero();

void continua();

void *valoriManuale(int dimensioni, int *mioVettore, int contatore, int &valore);

void numCasuali(int dimensioni, int *mioVettore, int MAX, int MIN);

void casMaxMin(int dimensioni, int *mioVettore, int max, int min, int contatore1, int maxTrovato, int minTrovato);

void mostraValori(int dimensioni, int *mioVettore);

void raddoppiaValori(int dimensioni, int *mioVettore);

void dimezzaValori(int dimensioni, int *mioVettore);

int divisioneResto(int x, int y);

int converBinADec(int &num, int elevatore, int somma);

int trovaMax(int dimensioni, const int *mioVettore);

int trovaMin(int dimensioni, const int *mioVettore);

void translatoreVettore(int *mioVettore, int posDaSpostare, int posDestinazione, int valDaSpostare,
                        int valDestinazione);

int main() {

    int nValoreScelto = 1, dimensioni, vettoreEsiste = 0;

    printf("\nQuanti valori intendi inserire: ");
    scanf("%d", &dimensioni);
    int mioVettore[dimensioni];

    while (nValoreScelto != 0) {

        printf("\n\nScegli un valore per eseguire l'algoritmo, 0 per uscire.");

        printf("\n0 -> Fine.\n");
        printf("1 -> Memorizzo N numeri in un vettore.\n");
        printf("2 -> Genero N numeri casuali in un range.\n");
        printf("3 -> Gioco dei numeri casuali.\n");
        printf("4 -> Genero X numeri casuali e mostro il maggiore e minore.\n");
        printf("5 -> Dimezza il valore fino all'unità (logaritmo).\n");
        printf("6 -> Converti numero decimale in binario.\n");
        printf("7 -> Converti numero binario in decimale.\n");

        if (vettoreEsiste == 1) {
            printf("\nLe seguenti opzioni saranno disponibili solamente se si ha assegnato dei valori al vettore precedentemente:\n");
            printf("8 -> Visualizza il vettore.\n");
            printf("9 -> Raddoppia il vettore.\n");
            printf("10 -> Dimezza il vettore.\n");
            printf("11 -> Trova maggiore e minore.\n");
            printf("12 -> Traslazione di un valore.\n");
        }

        printf("Valore inserito: ");

        // Ottengo dall'utente l'input
        scanf("%d", &nValoreScelto);

        switch (nValoreScelto) {

            case 0:{

                printf("\nHai scelto: FINE!\n");

                printf("\nChiuso con successo!");

                nValoreScelto = 0;

                break;
            }

            case 1:{

                printf("\nHai scelto: Inserisci valori in un vettore manualmente...\n");

                int contatore = 0, valore = 0;

                valoriManuale(dimensioni, mioVettore, contatore, valore);

                printf("\nInseriti i valori con successo!");

                vettoreEsiste = 1;

                continua();

                break;
            }

            case 2:{

                printf("\nHai scelto: Generatore numeri casuali...\n");

                // Ottengo MAX dall'utente
                int MAX, MIN;
                printf("\nInserire il valore massimo che vuoi possano assumere: ");
                scanf("%d", &MAX);

                printf("\nInserire il valore minimo che vuoi possano assumere: ");
                scanf("%d", &MIN);

                numCasuali(dimensioni, mioVettore, MAX, MIN);

                printf("Generati i valori con successo!\n");

                vettoreEsiste = 1;

                continua();

                break;
            }

            case 3:{

                // Messaggi d'inizio
                printf("\nHai scelto: Indovina numero casuale...\n");
                printf("Il numero casuale da indovinare è compreso tra -10 e 20, hai 10 solo tentativi!");

                // Richiamo la funzione
                indovinaNumero();

                continua();

                break;
            }

            case 4:{

                // Messaggio d'inizio
                printf("\nHai scelto: Genera x numeri casuali compresi in un intervallo e mostra il MAGGIORE e MINORE.\n");

                // Dichiaro parametri e variabili
                int max, min, contatore1 = 0, maxTrovato, minTrovato;

                // Ottengo dall'utente i vari input
                printf("\nInserire numero massimo: ");
                scanf("%d", &max);
                printf("Inserire numero minimo: ");
                scanf("%d", &min);
                casMaxMin(dimensioni, mioVettore, max, min, contatore1, maxTrovato, minTrovato);

                vettoreEsiste = 1;

                continua();

                break;
            }

            case 5:{

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

                continua();

                break;
            }

            case  6:{

                int num, resto;

                printf("\nHai scelto: Converti valore decimale in binario...");

                printf("\nInserisci il numero da convertire e poi leggi i numeri in uscita al contrario, quello è il binario: ");
                scanf("%d", &num);

                while (num != 0) {

                    resto = divisioneResto(num, 2);

                    printf("%d", resto);

                    num = num / 2;

                }

                break;
            }

            case 7:{

                int num, elevatore = 0, somma;

                printf("\nHai scelto: Converti binario in decimale...");

                somma = converBinADec(num, elevatore, somma);

                printf("\nIl risultato è: %d", somma);

                break;
            }

            case 8:{

                printf("\nHai scelto: Mostra valori del vettore...\n");

                mostraValori(dimensioni, mioVettore);

                continua();

                break;
            }

            case 9:{

                printf("\nHai scelto: raddoppia valori vettore...");

                raddoppiaValori(dimensioni, mioVettore);

                printf("\nValori raddoppiati con successo!");

                continua();

                break;
            }

            case 10:{

                printf("\nHai scelto: dimezza valori vettore...");

                dimezzaValori(dimensioni, mioVettore);

                printf("\nValori dimezzati con successo!");

                continua();

                break;
            }

            case 11:{

                printf("\nHai scelto: trova maggiore e minore in un vettore...");

                int max = trovaMax(dimensioni, mioVettore), min = trovaMin(dimensioni, mioVettore);

                printf("\nIl maggiore è: %d", max);
                printf("\nIl minore è: %d", min);

                continua();

                break;
            }

            case 12:{

                // Inizializzo variabili
                int posDaSpostare, posDestinazione, valDaSpostare, valDestinazione;

                // Messaggio d'inizio
                printf("\nHai scelto: translazione di un valore...");

                // Chiamo la funzione per mostrare i valori
                mostraValori(dimensioni, mioVettore);

                // Chiedo all'utente le coordinate del valore da spostare
                printf("\nScegli quale spostare digitando il numero della sua posizione: ");
                scanf("%d", &posDaSpostare);

                // Decremento perchè i valori delle posizioni includono 0
                posDaSpostare--;

                // Chiedo all'utente la posizione della destinazione
                printf("\nInserisci coordinate destinazione: ");
                scanf("%d", &posDestinazione);

                // Decremento perchè i valori delle posizioni includono 0
                posDestinazione--;

                if (posDaSpostare > dimensioni || posDaSpostare < 0 || posDestinazione > dimensioni || posDestinazione < 0){

                    printf("\nErrore: Hai inserito delle coordinate non valide! La posizione e destinazione devono essere uguali!");

                    continua();

                    break;

                } else if (posDestinazione == posDaSpostare){

                    printf("\nErrore: Hai inserito due valori uguali!");

                    continua();

                    break;
                }

                translatoreVettore(mioVettore, posDaSpostare, posDestinazione, valDaSpostare, valDestinazione);

                printf("\nValori translati/scambiati/spostati con successo!");

                continua();

                break;
            }

            default:{

                printf("\n[ERRORE] -> Il valore inserito non è valido!");

                continua();

                break;
            }

        }

    }

    return 0;
}

void translatoreVettore(int *mioVettore, int posDaSpostare, int posDestinazione, int valDaSpostare,
                        int valDestinazione) {// Ottengo valori vari
    valDaSpostare = mioVettore[posDaSpostare];
    valDestinazione = mioVettore[posDestinazione];
    mioVettore[posDestinazione] = valDaSpostare;
    mioVettore[posDaSpostare] = valDestinazione;
}

int trovaMin(int dimensioni, const int *mioVettore) {

    int contatore1 = 0, minTrovato, maxTrovato;

    minTrovato = mioVettore[contatore1];
    maxTrovato = mioVettore[contatore1];


    // Ripeto il loop finchè il contatore non diventa maggiore di nNum
    while (contatore1 < dimensioni){

        // Incremento il contatore
        contatore1++;

        // Controllo se è maggiore o minore e nel caso di una condizione soddisfatta, assegno un nuovo valore
        if (mioVettore[contatore1] > maxTrovato){

        } else if (mioVettore[contatore1] < minTrovato){
            minTrovato = mioVettore[contatore1];
        }
    }

    return minTrovato;
}

int trovaMax(int dimensioni, const int *mioVettore) {

    int contatore1 = 0, maxTrovato;

    maxTrovato = mioVettore[contatore1];

    // Ripeto il loop finchè il contatore non diventa maggiore di nNum
    while (contatore1 < dimensioni){

        // Incremento il contatore
        contatore1++;

        // Controllo se è maggiore o minore e nel caso di una condizione soddisfatta, assegno un nuovo valore
        if (mioVettore[contatore1] > maxTrovato){
            maxTrovato = mioVettore[contatore1];
        }
    }

    return maxTrovato;
}

int converBinADec(int &num, int elevatore, int somma) {
    printf("\nInserisci le singole cifre dalla meno significativo (destra verso sinistra), inserisci un numero diverso da 1 o 0 per uscire e vedere il risultato: ");

    scanf("%d", &num);

    while (num == 0 || num == 1){

        somma += num * pow(2, elevatore);

        printf("\nInserisci un numero compreso tra 0 o 1: ");
        scanf("%d", &num);

        elevatore++;
    }
    return somma;
}

void dimezzaValori(int dimensioni, int *mioVettore) {
    for (int i = 0; i < dimensioni; i++) {

        // Dimezzo
        mioVettore[i] = mioVettore[i] * 2;

    }
}

void raddoppiaValori(int dimensioni, int *mioVettore) {
    for (int i = 0; i < dimensioni; i++) {

        // Raddoppio
        mioVettore[i] = mioVettore[i] * 2;

    }
}

void mostraValori(int dimensioni, int *mioVettore) {
    printf("\nI valori sono: \n");
    for (int i = 0; i < dimensioni; i++) {

        // Scrivo i numeri
        printf("%d-->%d \t",i+1, mioVettore[i]);

    }
}

void casMaxMin(int dimensioni, int *mioVettore, int max, int min, int contatore1, int maxTrovato,
               int minTrovato) {// Assegno un valore al vettore
    mioVettore[contatore1] = rand() % (max - (min) + 1) + (min);

    // Dichiaro le variabili con il loro valore iniziale
    maxTrovato = mioVettore[contatore1];
    minTrovato = mioVettore[contatore1];

    // Ripeto il loop finchè il contatore non diventa maggiore di nNum
    while (contatore1 < dimensioni){

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
}

void numCasuali(int dimensioni, int *mioVettore, int MAX, int MIN) {
    srand(time(0));

    // Generatore numeri casuali
    for (int conta = 0; conta < dimensioni; conta++) {
        // Ottengo un valore casuale compreso tra 0 e MAX
        mioVettore[conta] = rand()%(MAX-(MIN) + 1) + (MIN);
    }
}

void *valoriManuale(int dimensioni, int *mioVettore, int contatore, int &valore) {
    while (contatore != dimensioni){

        printf("Inserire il valore: ");
        scanf("%d", &valore);

        mioVettore[contatore] = valore;

        contatore++;
    }
}

void continua(){

    int inusato;

    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}

int contaDimezza(int num) {

    // Dichiaro parametri e variabili
    int nVolte = 0, dimezzatore = 2;

    while (num >= 2){

        num = num / dimezzatore;

        nVolte++;

    }
    return nVolte;
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

int divisioneResto(int x, int y){

    int ris = 0;

    // Loop fino a quando x non diventa minore a y
    while (x >= y){

        x -= y;

        ris++;

    }

    return x;

}