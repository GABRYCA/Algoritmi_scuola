#include <iostream>
#include <stdlib.h>
#include <cmath>

int contaDimezza(int num);

void indovinaNumero();

void continua();

void valoriManuale(int dimensioni, int mioVettore[], int contatore, int &valore);

void numCasuali(int dimensioni, int mioVettore[], int MAX, int MIN);

void casMaxMin(int dimensioni, int mioVettore[], int max, int min, int contatore1, int maxTrovato, int minTrovato);

void mostraValori(int dimensioni, int mioVettore[]);

void raddoppiaValori(int dimensioni, int mioVettore[]);

void dimezzaValori(int dimensioni, int mioVettore[]);

int divisioneResto(int x, int y);

int converBinADec(int &num, int elevatore, int somma);

int trovaMax(int dimensioni, const int mioVettore[]);

int trovaMin(int dimensioni, const int mioVettore[]);

void translatoreVettore(int mioVettore[], int posDaSpostare, int posDestinazione, int valDaSpostare,
                        int valDestinazione);

void rimuoviPerPos(int dimensioni, int mioVettore[], int valore);

int rimuoviPerVal(int dimensioni, int mioVettore[], int valore, int verifica);

void modificaValore(int dimensioni, int mioVettore[], int posizione);

void spostaValoriUnoPiu(int dimensioni, int mioVettore[]);

void spostaValoriUnoMeno(int dimensioni, int mioVettore[]);

void contatoreValoreRipetuto(int dimensioni, int mioVettore[]);

void contatoreValoreRipetutoAv(int dimensioni, int mioVettore[]);

void converDecABin();

int main() {

    // Vedere se lanciando i dati, la casualità fatta al computer è uguale a quella statistica, i dadi sono 2

    // Dichiaro parametri e variabili
    int nValoreScelto = 1, dimensioni, vettoreEsiste = 0;

    // Chiedo all'utente quanti valore vuole inserire e ottengo l'input
    printf("\nQuanti valori intendi inserire: ");
    scanf("%d", &dimensioni);
    int mioVettore[dimensioni], max, min;

    // While che si annulla se si mette 0
    while (nValoreScelto != 0) {

        // Legenda
        printf("\n\nScegli un valore per eseguire l'algoritmo, 0 per uscire.");

        printf("\n0 -> Fine.\n");
        printf("1 -> Memorizzo N numeri in un vettore.\n");
        printf("2 -> Genero N numeri casuali in un range.\n");
        printf("3 -> Gioco dei numeri casuali.\n");
        printf("4 -> Genero X numeri casuali e mostro il maggiore e minore.\n");
        printf("5 -> Dimezza il valore fino all'unità (logaritmo).\n");
        printf("6 -> Converti numero decimale in binario.\n");
        printf("7 -> Converti numero binario in decimale.\n");

        // Se un vettore è stato dichiarato o generato con successo, la variabile bandiera avrà un valore uguale a 1
        if (vettoreEsiste == 1) {
            printf("\nLe seguenti opzioni saranno disponibili solamente se si ha assegnato dei valori al vettore precedentemente:\n");
            printf("8 -> Visualizza il vettore.\n");
            printf("9 -> Raddoppia il vettore.\n");
            printf("10 -> Dimezza il vettore.\n");
            printf("11 -> Trova maggiore e minore.\n");
            printf("12 -> Traslazione di un valore.\n");
            printf("13 -> Cancella valore per posizione o valore e riordina.\n");
            printf("14 -> Modifica un valore del vettore.\n");
            printf("15 -> Incrementa di uno la posizione di tutti i valori del vettore con effetto pacman.\n");
            printf("16 -> Sposta di 1 indietro la posizione di tutti i valori del vettore con effetto pacman.\n");
            printf("17 -> Inserisci un valore in una posizione voluta del vettore e traslare tutti i valori.\n");
            printf("18 -> Quante volte è ripetuto ogni valore.\n");
            printf("19 -> Quante volte è ripetuto un numero con incluse statistiche.\n");
            // Un'idea per l'ultimo algoritmo è eliminare il valore e decrementare la posizione di tutti di uno e la dimensione.
        }

        printf("20 -> Verifica se numero è primo.\n");
        printf("21 -> Esperimento.\n");
        printf("22 -> Lancio di 2 dadi tra 1 e 6.\n");

        // Chiedo all'utente di inserire un valore
        printf("Valore inserito: ");

        // Ottengo dall'utente l'input
        scanf("%d", &nValoreScelto);

        // Swicth tra i valori scelti
        switch (nValoreScelto) {

            case 0:{

                // Messaggi d'inizio
                printf("\nHai scelto: FINE!\n");
                printf("\nChiuso con successo!");

                // 0 significa di uscire da tutto
                nValoreScelto = 0;

                break;
            }

            case 1:{

                // Messaggi d'inzio
                printf("\nHai scelto: Inserisci valori in un vettore manualmente...\n");

                // Dichiaro le variabili
                int contatore = 0, valore = 0;

                // Richiamo la funzione
                valoriManuale(dimensioni, mioVettore, contatore, valore);

                // Comunico all'utente che i valori sono stati inseriti con successo
                printf("\nInseriti i valori con successo!");

                // Metto a 1 il valore bandiera
                vettoreEsiste = 1;

                // Chiedo all'utente se continuare
                continua();

                break;
            }

            case 2:{

                // Messaggi d'inizio
                printf("\nHai scelto: Generatore numeri casuali...\n");

                // Chiedo all'utente l'input e lo ottengo
                printf("\nInserire il valore massimo che vuoi possano assumere: ");
                scanf("%d", &max);

                // Chiedo all'utente l'input e l'ottengo
                printf("\nInserire il valore minimo che vuoi possano assumere: ");
                scanf("%d", &min);

                // Richiamo la funzione
                numCasuali(dimensioni, mioVettore, max, min);

                // Comunico che i valori sono stati generati con successo
                printf("Generati i valori con successo!\n");

                // Metto a uno la variabile bandiera
                vettoreEsiste = 1;

                // Chiedo all'utente se continuare
                continua();

                break;
            }

            case 3:{

                // Messaggi d'inizio
                printf("\nHai scelto: Indovina numero casuale...\n");
                printf("Il numero casuale da indovinare è compreso tra -10 e 20, hai 10 solo tentativi!");

                // Richiamo la funzione
                indovinaNumero();

                // Chiedo all'utente se continuare
                continua();

                break;
            }

            case 4:{

                // Messaggio d'inizio
                printf("\nHai scelto: Genera x numeri casuali compresi in un intervallo e mostra il MAGGIORE e MINORE.\n");

                // Dichiaro parametri e variabili
                int contatore1 = 0, maxTrovato, minTrovato;

                // Ottengo dall'utente i vari input
                printf("\nInserire numero massimo: ");
                scanf("%d", &max);
                printf("Inserire numero minimo: ");
                scanf("%d", &min);

                // Richiamo la funzione
                casMaxMin(dimensioni, mioVettore, max, min, contatore1, maxTrovato, minTrovato);

                // Il vettore è stato generato quindi uso questo numero bandiera per dichiararlo
                vettoreEsiste = 1;

                // Chiedo all'utente se vuole continuare
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

                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case  6:{

                // Dichiaro variabili
                int num, resto;

                // Messaggi d'inizio
                printf("\nHai scelto: Converti valore decimale in binario...");

                // Richiamo la funzione
               converDecABin();

                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case 7:{

                // Dichiaro parametri e variabili
                int num, elevatore = 0, somma;

                // Messaggi d'inizio
                printf("\nHai scelto: Converti binario in decimale...");

                // Richiamo la funzione
                somma = converBinADec(num, elevatore, somma);

                // Comunico il risultato all'utente
                printf("\nIl risultato è: %d", somma);

                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case 8:{

                // Messaggi d'inizio
                printf("\nHai scelto: Mostra valori del vettore...\n");

                // Richiamo funzione
                mostraValori(dimensioni, mioVettore);

                // Chiedo all'utente se continuare
                continua();

                break;
            }

            case 9:{

                // Messaggi d'inizio
                printf("\nHai scelto: raddoppia valori vettore...");

                // Richiamo funzione
                raddoppiaValori(dimensioni, mioVettore);

                // Comunico con successo
                printf("\nValori raddoppiati con successo!");

                // Chiedo all'utente se continuare
                continua();

                break;
            }

            case 10:{

                // Messaggi d'inizio
                printf("\nHai scelto: dimezza valori vettore...");

                // Richiamo la funzione
                dimezzaValori(dimensioni, mioVettore);

                // Comunico che l'azione è stata eseguita con successo
                printf("\nValori dimezzati con successo!");

                // Chiedo se continuare
                continua();

                break;
            }

            case 11:{

                // Messaggio d'inizio
                printf("\nHai scelto: trova maggiore e minore in un vettore...");

                // Ottengo max richiamando la funzione
                int max = trovaMax(dimensioni, mioVettore), min = trovaMin(dimensioni, mioVettore);

                // Comunico i risultati
                printf("\nIl maggiore è: %d", max);
                printf("\nIl minore è: %d", min);

                // Chiedo se continuare
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

                // Condizioni importanti per evitare errori successivamente
                if (posDaSpostare > dimensioni || posDaSpostare < 0 || posDestinazione > dimensioni || posDestinazione < 0){

                    // Errore
                    printf("\nErrore: Hai inserito delle coordinate non valide! La posizione e destinazione devono essere uguali!");

                    // Chiedo se continuare
                    continua();

                    break;

                } else if (posDestinazione == posDaSpostare){

                    // Errore
                    printf("\nErrore: Hai inserito due valori uguali!");

                    // Chiedo se continuare
                    continua();

                    break;
                }

                // Richiamo la funzione
                translatoreVettore(mioVettore, posDaSpostare, posDestinazione, valDaSpostare, valDestinazione);

                // Comunico all'utente che la translazione è avvenuta con successo
                printf("\nValori translati/scambiati/spostati con successo!");

                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case 13: {

                // Dichiaro le variabili
                int scelta, valore;

                // Messaggi d'inizio
                printf("\nHai scelto: elimina valore per posizione o valore scelto...");
                printf("\nScegli un tipo di eliminazione:");
                printf("\n1 -> Elimina per posizione");
                printf("\n2 -> Elimina per valore");
                printf("\nValore inserito: ");
                scanf("%d", &scelta);

                // Richiamo la funzione per mostrare i valori
                mostraValori(dimensioni, mioVettore);

                if (scelta == 1){

                    // Chiedo all'utente l'input e lo ottengo
                    printf("\nInserire la posizione: ");
                    scanf("%d", &valore);

                    // Decremento il valore perchè il vettore include 0
                    valore--;

                    // Condizioni importanti
                    if (valore > dimensioni || valore < 0){

                        // Errore
                        printf("\nErrore: hai scelto una posizione non valida!");

                        // Chiedo all'utente se vuole continuare
                        continua();

                        break;
                    }

                    // Richiamo la posizione
                    rimuoviPerPos(dimensioni, mioVettore, valore);

                    // Decremento dimensioni
                    dimensioni--;

                } else if (scelta == 2){

                    // Dichiaro variabile bandiera
                    int verifica = 0;

                    // Chiedo all'utente l'input e lo ottengo
                    printf("\nInserire il valore da eliminare: ");
                    scanf("%d", &valore);

                    verifica = rimuoviPerVal(dimensioni, mioVettore, valore, verifica);

                    // Condizione che se vera significa che il valore non è stato trovato
                    if(verifica==0){

                        // Errore
                        printf("\nErrore: valore non trovato!");

                        // Chiede all'utente se vuole continuare
                        continua();

                        break;

                    }

                    // Rimosso con successo
                    printf("\nElemento rimosso con successo!");

                    // Decrementa le dimensioni globali
                    dimensioni--;

                } else {

                    // Comunico che il valore non è valido
                    printf("\nErrore: hai inserito una scelta non valida!");

                }

                // Chiede all'utente se vuole continuare
                continua();

                break;
            }

            case 14:{

                // Inizializzo variabili
                int posizione;

                // Messaggi d'inizio
                printf("\nHai scelto: Modifica un valore del vettore...\n");

                // Richiamo funzione
                mostraValori(dimensioni,mioVettore);

                // Chiedo all'utente l'input e lo ottengo
                printf("\nScegli quale valore cambiare inserendone la posizione: ");
                scanf("%d", &posizione);

                // Richiamo la funzione
                modificaValore(dimensioni, mioVettore, posizione);

                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }
            case 15:{

                // Messaggi d'inizio
                printf("\nHai scelto: incrementa di uno la posizione di tutti i valori ed effetto pacman...\n");

                // Richiamo funzione
                spostaValoriUnoPiu(dimensioni, mioVettore);

                // Comunico all'utente che l'operazione è avvenuta con successo
                printf("\nValori spostati in avanti con successo!");

                // Chiedo all'utente se continuare
                continua();

                break;
            }

            case 16:{

                // Messaggi d'inizio
                printf("\nHai scelto: sposta i valori del vettore di uno indietro con effetto pacman...\n");

                // Richiamo funzione
                spostaValoriUnoMeno(dimensioni, mioVettore);

                // Comunico all'utente che l'operazione è avvenuta con successo
                printf("\nValori spostati in indietro con successo!");

                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case 17:{

                // Inizializzo variabili
                int posizione, valore;

                // Messaggi d'inizio
                printf("\nHai scelto: inserire valore in base alla posizione al vettore traslando tutti gli altri...\n");

                // Richiamo funzione
                mostraValori(dimensioni, mioVettore);

                // Chiedo all'utente l'input della posizione
                printf("\n\nInserire la posizione: ");
                scanf("%d", &posizione);

                // Chiedo all'utente l'input del valore
                printf("\nInserire il valore: ");
                scanf("%d", &valore);

                // Controllo che l'input della posizione sia possibile
                if (posizione > dimensioni){

                    // Errore
                 printf("\nHai inserito un valore troppo grande come posizione!");

                } else if (posizione < 0){

                    // Errore
                    printf("\nHai inserito una posizione troppo piccola");

                } else {

                    // Sposto tutti i valori
                    for(int contatore = dimensioni; contatore > posizione - 1; contatore--){

                        // Nuova posizione del valore
                        mioVettore[contatore] = mioVettore[contatore - 1];

                    }

                    // Aggiungo il valore
                    mioVettore[posizione - 1] = valore;

                    // Incremento dimensioni vettore
                    dimensioni++;

                    // Comunico all'utente che è stato effettuato con successo
                    printf("\nValore aggiunto con successo!");

                }

                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case 18:{

                printf("\nHai scelto: quante volte sono ripetuti i valori...");

                int dimensioniVer = 0;

                // Valori verificati.
                int verificati[dimensioniVer];

                // Per ogni valore di mioVettore[] eseguo un'operazione.
                for (int i = 0; i < dimensioni; ++i) {

                    // Valore bandiera, 0 se falso, 1 se vero.
                    int condizione = 0;

                    // Lo esegue solo dalla seconda volta in poi.
                    if (dimensioniVer != 0) {
                        // Per ogni valore nel vettore dei valori verificati, esegue l'operazione.
                        for (int j = 0; j < dimensioniVer; ++j) {

                            // Se il valore provato è uguale a quello che si sta testando, allora la condizione è vera
                            if (verificati[j] == mioVettore[i]) {

                                condizione = 1;

                            }
                        }
                    }

                    // Se la condizione è falsa allora va avanti
                    if (condizione != 1) {

                        // Contatore
                        int quanteVolte = 0;

                        // Per ogni valore del vettore, verifica se è uguale a quello che si sta provando
                        for (int j = 0; j < dimensioni; ++j) {

                            // Se la condizione è vera incrementa il vettore
                            if (mioVettore[i] == mioVettore[j]){

                                quanteVolte++;

                            }
                        }

                        // Comunica quante volte è stato trovato il valore
                        printf("\nIl valore %d è stato trovato %d volte!\n", mioVettore[i], quanteVolte);

                        // Aggiunge il valore a quelli verificati
                        verificati[dimensioniVer] = mioVettore[i];

                        // Incrementa le dimensioni
                        dimensioniVer++;
                    }
                }

                continua();

                break;
            }

            case 19: {

                int numeroFasce, distanzaTraFasce, vettoreFasce[0], numeroFasceIni, vuoleInfo = 0;

                printf("\nHai scelto: quante volte un valore è ripetuto nel vettore AVANZATO...");

                printf("\n\nIn quante fasce vuoi dividere i valori (uguali): ");
                scanf("%d", &numeroFasce);

                printf("\n\nVuoi vedere delle statistiche come conta per ogni singolo numero? \n0 -> No \n1 -> Si \nScelta: ");
                scanf("%d", &vuoleInfo);

                numeroFasceIni = numeroFasce;

                distanzaTraFasce = max / numeroFasce;

                int dimensioniVer = 0, sufficienti = 0, insufficienti = 0;

                // Valori verificati.
                int verificati[dimensioniVer];

                // Per ogni valore di mioVettore[] eseguo un'operazione.
                for (int i = 0; i < dimensioni; ++i) {

                    // Valore bandiera, 0 se falso, 1 se vero.
                    int condizione = 0;

                    // Lo esegue solo dalla seconda volta in poi.
                    if (dimensioniVer != 0) {
                        // Per ogni valore nel vettore dei valori verificati, esegue l'operazione.
                        for (int j = 0; j < dimensioniVer; ++j) {

                            // Se il valore provato è uguale a quello che si sta testando, allora la condizione è vera.
                            if (verificati[j] == mioVettore[i]) {

                                condizione = 1;

                            }
                        }
                    }

                    int valMin = min, valMax = min;

                    for (int j = 0; j < numeroFasce; j++) {
                        valMax = valMax + distanzaTraFasce;
                        if (mioVettore[i] <= valMax && mioVettore[i] >= valMin){
                            vettoreFasce[j]++;
                        }
                        valMin = valMax;
                    }

                    if (mioVettore[i] >= 60) {
                        sufficienti++;
                    } else {
                        insufficienti++;
                    }

                    // Se la condizione è falsa allora va avanti.
                    if (condizione != 1) {

                        // Contatore.
                        int quanteVolte = 0;

                        // Per ogni valore del vettore, verifica se è uguale a quello che si sta provando.
                        for (int j = 0; j < dimensioni; ++j) {

                            // Se la condizione è vera incrementa il vettore.
                            if (mioVettore[i] == mioVettore[j]) {

                                quanteVolte++;

                            }
                        }

                        if (vuoleInfo == 1) {
                            // Comunica quante volte è stato trovato il valore.
                            printf("\nIl valore %d è stato trovato %d volte.", mioVettore[i], quanteVolte);

                            // Eseguo il calcolo
                            float suTot = (float) quanteVolte / (float) dimensioni * 100;

                            // Comunico il risultato
                            printf("\nIl valore compone %.2f percento sul totale di tutti i valori del vettore.\n",
                                   suTot);
                        }

                        // Aggiunge il valore a quelli verificati.
                        verificati[dimensioniVer] = mioVettore[i];

                        // Incrementa le dimensioni, questo include anche 0 usualmente
                        dimensioniVer++;
                    }
                }

                int scelta;

                printf("\nStatische: ");
                printf("\n1 -> Semplice");
                printf("\n2 -> Grafica");

                printf("\nScegli che tipo di statistica vedere: ");
                scanf("%d", &scelta);

                switch (scelta) {

                    case 1: {
                        // Comunico i valori trovati singolarmente, senza ripeterli.
                        mostraValori(dimensioniVer, verificati);

                        int totale = 0;
                        int totaleAssoluto = 0;

                        // Per ogni valore incremento il totale
                        for (int i = 0; i < dimensioniVer; ++i) {

                            // Sommo al totale i valori
                            totale += verificati[i];
                        }

                        for (int i = 0; i < dimensioni; ++i) {
                            totaleAssoluto += mioVettore[i];
                        }

                        // Eseguo il calcolo della media
                        int media = totale / dimensioniVer;
                        int mediaTot = totaleAssoluto / dimensioni;

                        // Stile nuovo
                        printf("\n\nMediaVer  MediaTot  ValTot  Sufficienze  Insufficienze\n");
                        printf("   %d        %d       %d       %d           %d", media, mediaTot, dimensioniVer,
                               sufficienti,
                               insufficienti);

                        break;
                    }

                    case 2: {

                        double valMin = min, valMax = min;

                        if (distanzaTraFasce != 0){

                            for (int i = 0; i < numeroFasceIni; i++) {

                                valMax = valMax + (double) distanzaTraFasce;

                                printf("\n\nPercentuale compreso tra %.0f-%.0f:", valMin, valMax);
                                printf("\n|");
                                for (int j = 0; j < (((double) vettoreFasce[i] / dimensioni) * 100); j++) {
                                    printf("*");
                                }
                                for (int j = 0; j < 100 - (((double) vettoreFasce[i] / dimensioni) * 100); j++) {
                                    printf("-");
                                }
                                printf("|");
                                valMin = valMax;
                            }

                        } else {

                            printf("\nHai inserito un numero di fasce troppo grande");

                            continua();
                        }

                        break;
                    }
                }

                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case 20:{


                int numeroDaVerificare;
                double tempo;

                printf("\nHai scelto: verifica se il numero inserito è primo.\n");

                printf("\nInserire il numero: ");
                scanf("%d", &numeroDaVerificare);

                clock_t inizio = clock();

                for(int div = 1; div <= numeroDaVerificare / 2; div++) {

                    if(numeroDaVerificare % div == 0 && div != 1 && div != numeroDaVerificare){

                        printf("\nIl numero NON è primo");

                        clock_t fine = clock();

                        tempo = ((double)fine-inizio)/CLOCKS_PER_SEC;

                        printf("\nPer eseguire il calcolo sono stati necessari %.15f secondi.", tempo);

                        continua();
                        break;
                    }
                }

                printf("\nIl numero è primo.");

                clock_t fine = clock();

                tempo = ((double)fine-inizio)/CLOCKS_PER_SEC;

                printf("\nPer eseguire il calcolo sono stati necessari %.15f secondi.", tempo);

                continua();

                break;
            }

            case 21:{

                printf("\nHai scelto: esperimento...\n");

                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j <= 10; j++) {
                        printf("%d\t", i*j);

                    }
                    printf("\n");
                }

                continua();

                break;
            }

            case 22:{

                // Mettere statistiche, promemoria!

                int nVolte;

                printf("\nHai scelto: dadi...");

                printf("\nDigitare quante volte eseguire la statistica: ");
                scanf("%d", &nVolte);

                max = 6;
                min = 1;
                dimensioni = nVolte * 2;

                numCasuali(dimensioni, mioVettore, max, min);

                for (int i = 1; i <= nVolte; i++) {

                    int dado1 = mioVettore[i];
                    int dado2 = mioVettore[(dimensioni / 2) + i - 1];

                    printf("\nQuesta è la %d volta.", i);
                    printf("\n1° Dado: %d", dado1);
                    printf("\n2° Dado: %d", dado2);
                    printf("\nSomma: %d\n", dado1 + dado2);

                }

                continua();

                break;
            }

            default:{

                // Comunico all'utente che il valore inserito non è valido o compreso nella lista
                printf("\n[ERRORE] -> Il valore inserito non è valido!");

                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

        }

    }

    return 0;
}

// ATTENZIONE! Ho estratto la funzione ma per colpa di qualche problema o limitazione di cui non ho la conoscenza a riguardo
// Non funziona l'algoritmo con la funzione estratta, se si copia il codice nel case invece funzionerà!
void contatoreValoreRipetutoAv(int dimensioni, int mioVettore[]) {

    // Vuoto perchè in forma di funzione succedono cose senza senso

}

// ATTENZIONE! Ho estratto la funzione ma per colpa di qualche problema o limitazione di cui non ho la conoscenza a riguardo
// Non funziona l'algoritmo con la funzione estratta, se si copia il codice nel case invece funzionerà!
void contatoreValoreRipetuto(int dimensioni, int mioVettore[]) {

    // Vuoto perchè in forma di funzione succedono cose senza senso

}

void spostaValoriUnoMeno(int dimensioni, int mioVettore[]) {

    // Inizializzo variabili
    int primoValore = mioVettore[0];

    // Sposto tutti i valori
    for(int contatore = 0; contatore < dimensioni; contatore++){

        // Nuova posizione del valore
        mioVettore[contatore] = mioVettore[contatore + 1];

    }
    // 0 1 2 -> 1 2 0
    mioVettore[dimensioni] = primoValore;
}

void spostaValoriUnoPiu(int dimensioni, int mioVettore[]) {

    // Inizializzo le variabili
    int ultimoValore = mioVettore[dimensioni - 1];

    // Sposto tutti i valori
    for(int contatore = dimensioni; contatore > 0; contatore--){

        // Nuova posizione del valore
        mioVettore[contatore] = mioVettore[contatore - 1];

    }
    // 0 1 2 -> 2 0 1
    mioVettore[0] = ultimoValore;
}

void modificaValore(int dimensioni, int mioVettore[], int posizione) {

    // Condizioni importanti
    if (posizione > dimensioni){

        // Comunico l'errore e come risolverlo
        printf("\nErrore: hai inserito una posizione troppo grande e inesistente!");


    } else if (posizione < 0){

        // Comunico l'errore e come risolverlo
        printf("\nErrore: hai inserito una posizione sotto 0!");

    } else {

        // Inizializzo variabili
        int nuovoValore;

        // Chiedo all'utente l'input
        printf("\nInserire il nuovo valore: ");
        scanf("%d", &nuovoValore);

        // Assegno nuovo valore
        mioVettore[posizione] = nuovoValore;
    }
}

int rimuoviPerVal(int dimensioni, int mioVettore[], int valore, int verifica) {

    // Loop per rimuovere il valore se trovato
    for(int i=0; i < dimensioni; ++i){

        if(mioVettore[i] == valore){

            // Loop per spostare tutti i valori
            for(int x=i; x < dimensioni-1; x++){
                // Sposta tutti i valori di 1 a sinistra
                mioVettore[x] = mioVettore[x+1];
            }

            // Incremento variabile bandiera
            verifica++;

            break;
        }
    }

    return verifica;
}

void rimuoviPerPos(int dimensioni, int mioVettore[],
                   int valore) {

    // Loop per eliminare "valore" e spostare tutti i valori
    for (int i = valore; i < dimensioni - 1; ++i) {

        mioVettore[i] = mioVettore[i + 1];

    }
}

void translatoreVettore(int mioVettore[], int posDaSpostare, int posDestinazione, int valDaSpostare,
                        int valDestinazione) {

    // Ottengo valori vari
    valDaSpostare = mioVettore[posDaSpostare];
    valDestinazione = mioVettore[posDestinazione];

    // Assegno la nuova posizione
    mioVettore[posDestinazione] = valDaSpostare;
    mioVettore[posDaSpostare] = valDestinazione;

}

int trovaMin(int dimensioni, const int mioVettore[]) {

    // Dichiaro le variabili
    int contatore1 = 0, minTrovato, maxTrovato;

    // Ottengo max e min per anche evitare un errore
    minTrovato = mioVettore[contatore1];
    maxTrovato = mioVettore[contatore1];

    // Ripeto il loop finchè il contatore non diventa maggiore di nNum
    while (contatore1 < dimensioni){

        // Incremento il contatore
        contatore1++;

        // Controllo se è maggiore o minore e nel caso di una condizione soddisfatta, assegno un nuovo valore
        if (mioVettore[contatore1] > maxTrovato){

        } else if (mioVettore[contatore1] < minTrovato){
            // Assegno nuovo valore di min
            minTrovato = mioVettore[contatore1];
        }
    }

    // Ritorno il risultato della funzione
    return minTrovato;
}

int trovaMax(int dimensioni, const int mioVettore[]) {

    // Inizializzo le variabili
    int contatore1 = 0, maxTrovato;

    // Assegno il valore iniziale a max
    maxTrovato = mioVettore[contatore1];

    // Ripeto il loop finchè il contatore non diventa maggiore di nNum
    while (contatore1 < dimensioni){

        // Incremento il contatore
        contatore1++;

        // Controllo se è maggiore o minore e nel caso di una condizione soddisfatta, assegno un nuovo valore
        if (mioVettore[contatore1] > maxTrovato){
            // Assegno il nuovo valore a max
            maxTrovato = mioVettore[contatore1];
        }
    }

    // Ritorno il risultato della funzione
    return maxTrovato;
}

void converDecABin(){

    // Dichiaro variabili
    int vettore[10], num, contatore = 0;

    // Chiedo l'input
    printf("\nInserisci il numero da convertire in binario: ");
    scanf("%d", &num);

    // Ripeto il loop fintanto che num sia diverso da 0
    while (num != 0) {

        // Ottengo resto richiamando la funzione
        vettore[contatore] = divisioneResto(num, 2);

        // Dimezzo num
        num = num / 2;

        contatore++;
    }

    printf("\nValore binario del valore: ");
    for(contatore = contatore - 1; contatore >= 0; contatore--){

    int valoreDaScrivere = vettore[contatore];

    // Scrivo il valore
    printf("%d", valoreDaScrivere);
    }
}

int converBinADec(int &num, int elevatore, int somma) {

    // Messaggio d'inizio
    printf("\nInserisci le singole cifre dalla meno significativo (destra verso sinistra), inserisci un numero diverso da 1 o 0 per uscire e vedere il risultato: ");

    // Ottengo l'input dell'utente
    scanf("%d", &num);

    // Loop che funziona solamente se l'utente inserisce 0 o 1, altrimenti esce e comunica il risultato
    while (num == 0 || num == 1){

        somma += num * pow(2, elevatore);

        // Chiedo all'utente di inserire un numero compreso tra 0 e 1 perchè binario e ottengo l'input
        printf("\nInserisci un numero compreso tra 0 o 1: ");
        scanf("%d", &num);

        // Incremento l'elevatore
        elevatore++;
    }
    return somma;
}

void dimezzaValori(int dimensioni, int mioVettore[]) {

    // Ottiene tutti i valori del vettore in base alle dimensioni dichiarate
    for (int i = 0; i < dimensioni; i++) {

        // Dimezzo
        mioVettore[i] = mioVettore[i] * 2;

    }
}

void raddoppiaValori(int dimensioni, int mioVettore[]) {

    // Ottiene tutti i valori del vettore in base alle dimensioni dichiarate
    for (int i = 0; i < dimensioni; i++) {

        // Raddoppio
        mioVettore[i] = mioVettore[i] * 2;

    }
}

void mostraValori(int dimensioni, int mioVettore[]) {

    // Messaggio d'inizio
    printf("\nI valori sono: \n");

    // Ottengo tutti i valori dell'array in base alle dimensioni dichiarate, si noti che 0 è incluso all'inizio
    for (int i = 0; i < dimensioni; i++) {

        // Scrivo i numeri
        printf("%d-->%d \t",i+1, mioVettore[i]);

    }
}

void casMaxMin(int dimensioni, int mioVettore[], int max, int min, int contatore1, int maxTrovato,
               int minTrovato) {

    // Assegno un valore al vettore
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

            // Assegno il nuovo valore a max
            maxTrovato = mioVettore[contatore1];

        } else if (mioVettore[contatore1] < minTrovato){

            // Assegno il nuovo valore a min
            minTrovato = mioVettore[contatore1];

        }
    }

    // Comunico il numero maggiore e minore casuale generato
    printf("Il numero maggiore trovato è %d e il minore %d", maxTrovato, minTrovato);
}

void numCasuali(int dimensioni, int mioVettore[], int MAX, int MIN) {
    srand(time(0));

    // Generatore numeri casuali
    for (int conta = 0; conta < dimensioni; conta++) {
        // Ottengo un valore casuale compreso tra 0 e MAX
        mioVettore[conta] = rand()%(MAX-(MIN) + 1) + (MIN);
    }
}

void valoriManuale(int dimensioni, int mioVettore[], int contatore, int &valore) {

    // Loop con condizione, il contatore deve essere diverso dalle dimensioni
    while (contatore != dimensioni){

        // Chiedo all'utente l'input e l'ottengo
        printf("Inserire il valore: ");
        scanf("%d", &valore);

        // Aggiungo il valore al vettore
        mioVettore[contatore] = valore;

        // Incremento il contatore
        contatore++;
    }
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}

int contaDimezza(int num) {

    // Dichiaro parametri e variabili
    int nVolte = 0, dimezzatore = 2;

    // Ripeto il loop fintanto che il valore sia maggiore o uguale a 2
    while (num >= 2){

        // Eseguo dei calcoli
        num = num / dimezzatore;

        // Incremento un contatore
        nVolte++;

    }

    // Ritorno il contatore
    return nVolte;
}

void indovinaNumero() {

    // Dichiaro variabili e parametri
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

        // Decremento dividendo
        x -= y;

        // Incremento il risultato
        ris++;

    }

    // Ritorno il valore ottenuto
    return x;
}