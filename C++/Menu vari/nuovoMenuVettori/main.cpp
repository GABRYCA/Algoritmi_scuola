#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"


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
void contatoreValoreRipetuto(int dimensioni, int mioVettore[]); // Spiegazione errore nel metodo
void contatoreValoreRipetutoAv(int dimensioni, int mioVettore[]); // Spiegazione errore nel metodo
void converDecABin();
void singoloValVet(int dimensioni, int mioVettore[], int numeroGeneratoVar);

void masterMindTheGame(int mioVettore[], int dimensioni, int max, int min);
void nuovoMasterMind(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate, int nTentativi);
void nuovoMasterMindVSPC(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate);
void masterMindPC(int max, int min, int nCifre);
void masterMindPC2(int max, int min, int nCifre);
void masterMindPerVSPC2(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate);
bool valorePresenteInVet(int dimensioni, int numeroDaTrovare , const int vettore[]);

void genValDivInVet1(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate);

int main() {

    printf("\n---------------------------------------"
           "\nBenvenuto nel menu di Gabriele Caretti!"
           "\n---------------------------------------\n");

    // Dichiaro parametri e variabili
    int nValoreScelto = 1, dimensioni, vettoreEsiste = 0;

    // Chiedo all'utente quanti valore vuole inserire e ottengo l'input
    printf("\nQuanti valori intendi inserire (Ignorabile tranne per alcuni algoritmi, inserire pure un numero a caso): ");
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
        printf("23 -> MasterMind semplice (vecchia versione).\n");
        printf("24 -> MasterMind Menu (Nuovo valutabile).\n");

        // Chiedo all'utente di inserire un valore
        printf("Valore inserito: ");
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

                // Dichiaro variabili
                int nVolte, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, sommaTot = 0;

                // Messaggi iniziali
                printf("\nHai scelto: dadi...");

                // Chiedo all'utente un input e lo ottengo
                printf("\nDigitare quante volte lanciare i dadi: ");
                scanf("%d", &nVolte);

                // Sono dadi a 6 facce presumo
                max = 6;
                min = 1;
                dimensioni = nVolte * 2;

                int somma[nVolte];

                // Genero dei numeri casuali
                numCasuali(dimensioni, mioVettore, max, min);

                // Per ogni valore di mioVettore[] eseguo un'operazione.
                for (int i = 0; i < dimensioni; i++) {
                    if (mioVettore[i] == 1) n1++;
                    if (mioVettore[i] == 2) n2++;
                    if (mioVettore[i] == 3) n3++;
                    if (mioVettore[i] == 4) n4++;
                    if (mioVettore[i] == 5) n5++;
                    if (mioVettore[i] == 6) n6++;
                }

                // Comunico i valori generati in coppie da 2, 10 volte i dadi, dado1 = mioVettore[0] e dado2 = mioVettore[10]
                for (int i = 0; i < nVolte; i++) {
                    int dado1 = mioVettore[i];
                    int dado2 = mioVettore[(dimensioni / 2) + i];
                    int som = dado1 + dado2;
                    printf("\nQuesta è la %da volta.", i + 1);
                    printf("\n1° Dado: %d", dado1);
                    printf("\n2° Dado: %d", dado2);
                    printf("\nSomma: %d\n", som);
                    somma[i] = som;
                    sommaTot = sommaTot + som;
                }

                // Statistiche varie
                printf("\n\nRisultati delle somme ogni volta che ho lanciato i dadi: ");
                mostraValori(nVolte, somma);
                printf("\nLa media delle somme è: %d", sommaTot / nVolte);

                printf("\n\nValori trovati:\n");
                printf("1     2     3     4     5     6\n");
                printf("%d     %d     %d     %d     %d     %d", n1, n2, n3, n4, n5, n6);

                continua();

                break;
            }

            case 23:{

                // Messaggio d'inizio
                printf("\nHai scelto: gioco indovina numero di lunghezza 4...");

                clock_t inizio = clock();

                // Richiamo il gioco
                masterMindTheGame(mioVettore, dimensioni, max, min);

                clock_t fine = clock();

                float tempo = ((double)fine-inizio)/CLOCKS_PER_SEC;

                printf("\nPer finire il gioco hai impiegato %.2f secondi.\n", tempo);

                // Fine del gioco
                printf("\nFine del gioco...\n");
                continua();
                break;
            }

            case 24:{

                // Messaggi d'inizio
                printf("\nHai scelto: MasterMind migliorato...\n");

                // Inizializzo variabili e assegno valori di default
                int nCifre = 4, nCifreGenerate = 0, algoritmoScelto = 1, nTentativi = 10;
                max = 9, min = 0;

                // Se si inserisce un numero uguale a 0 esce
                while (algoritmoScelto != 0){

                    // Legenda e input
                    printf("\nChe tipo di MasterMind vuoi: "
                           "\n0 -> Esci."
                           "\n1 -> MasterMind classico (4 cifre e valori da 0 a 9) con numero di tentativi a scelta. "
                           "\n2 -> MasterMind custom con scelta numero cifre da 1 a 9, range valori da 0 a 9 e"
                           "\n     numero di tentativi. "
                           "\n3 -> MasterMind Computer."
                           "\n4 -> MasterMind persona VS computer."
                           "\n5 -> MasterMind computer 2.0."
                           "\n6 -> MasterMind persone VS computer 2.0"
                           "\nModalità scelta: ");
                    scanf("%d", &algoritmoScelto);

                    // Switch tra le varie versioni
                    switch (algoritmoScelto) {

                        case 0: {

                            printf("\nUscendo dal MasterMind...");

                            break;
                        }

                        case 1: {

                            // Messaggio d'inizio e richiesta input
                            printf("\nHai scelto: modalità 1...\n");
                            printf("\nInserire numero tentativi: ");
                            scanf("%d", &nTentativi);

                            // Richiamo MasterMind
                            nuovoMasterMind(mioVettore, max, min, nCifre, nCifreGenerate, nTentativi);

                            continua();
                            break;
                        }

                        case 2: {

                            // Messaggio d'inizio
                            printf("\nHai scelto: modalità 2...\n");

                            // Chiedo input dall'utente
                            printf("\nInserire numero tentativi: ");
                            scanf("%d", &nTentativi);
                            printf("\nInserire numero cifre: ");
                            scanf("%d", &nCifre);
                            printf("\nInserire numero max: ");
                            scanf("%d", &max);
                            printf("\nInserire numero min: ");
                            scanf("%d", &min);

                            // Richiamo MasterMind
                            nuovoMasterMind(mioVettore, max, min, nCifre, nCifreGenerate, nTentativi);

                            continua();
                            break;
                        }

                        case 3:{

                            printf("\nHai scelto: modalità 3...\n");

                            // Chiedo input dall'utente
                            printf("\nInserire numero massimo (es.9): ");
                            scanf("%d", &max);
                            printf("\nInserire numero minimo (es.0): ");
                            scanf("%d", &min);
                            printf("\nInserire numero cifre (es.4): ");
                            scanf("%d", &nCifre);

                            // Richiamo funzione
                            masterMindPC(max, min, nCifre);

                            continua();
                            break;
                        }

                        case 4:{

                            // Messaggio d'inizio
                            printf("\nHai scelto: modalità 4...\n");

                            // Chiedo input dall'utente
                            printf("\nInserire numero massimo (es.9): ");
                            scanf("%d", &max);
                            printf("\nInserire numero minimo (es.0): ");
                            scanf("%d", &min);
                            printf("\nInserire numero cifre (es.4): ");
                            scanf("%d", &nCifre);

                            // Richiamo funzione
                            nuovoMasterMindVSPC(mioVettore, max, min, nCifre, nCifreGenerate);

                            continua();
                            break;
                        }

                        case 5:{

                            // Messaggio d'inizio
                            printf("\nHai scelto: modalità 5 2.0...\n");

                            // Chiedo input dall'utente
                            printf("\nInserire numero massimo (es.9): ");
                            scanf("%d", &max);
                            printf("\nInserire numero minimo (es.0): ");
                            scanf("%d", &min);
                            printf("\nInserire numero cifre (es.4): ");
                            scanf("%d", &nCifre);

                            masterMindPC2(max, min, nCifre);

                            continua();
                            break;
                        }

                        case 6:{

                            // Messaggio d'inizio
                            printf("\nHai scelto: modalità 6 2.0...\n");

                            // Chiedo input dall'utente
                            printf("\nInserire numero massimo (es.9): ");
                            scanf("%d", &max);
                            printf("\nInserire numero minimo (es.0): ");
                            scanf("%d", &min);
                            printf("\nInserire numero cifre (es.4): ");
                            scanf("%d", &nCifre);

                            // Richiamo funzione
                            masterMindPerVSPC2(mioVettore, max, min, nCifre, nCifreGenerate);

                            continua();
                            break;
                        }

                        default: {

                            // Comunico errore
                            printf("\nIl valore inserito non è valido, riprovare!");

                            continua();
                            break;
                        }
                    }
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

void masterMindPerVSPC2(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate) {
    // Dichiaro variabili
    int nPersona, nPersonaVar, nPersonaVet[nCifre];

    // Chiedo input all'utente
    printf("\nInserisci il numero che dovrà indovinare il pc: ");
    scanf("%d", &nPersona);

    // Doppia dichiarazione di un valore perchè ogni tanto veniva modificato o comunque cambiava valore per motivi sconosciuti
    nPersonaVar = nPersona;

    // Divide in singole cifre in un vettore un numero
    singoloValVet(nCifre, nPersonaVet, nPersonaVar);

    // Ottengo srand
    srand(time(0));
    genValDivInVet1(mioVettore, max, min, nCifre, nCifreGenerate);

    // Numeri generati con successo, lo comunico e inizio.
    printf(GREEN "\nGenerato con successo un numero con %d cifre! Inizia il gioco...\n" RESET, nCifre);

    // Inizializzo diverse variabili
    int finito = 0, nNumeriSbagliati = 0, numeriPossibili = (max - min) + 1, vetNumeriPossibili[numeriPossibili], nProvatiPCSbagliati[nNumeriSbagliati], vetPCCorPos[nCifre], nProvatoPCVet[nCifre], nValTrov = 0, vetNValTrov[nValTrov];

    // Inizializza a zero i valori nel vettore
    for (int i = 0; i < nCifre; i++) {
        vetPCCorPos[i] = 0;
    }

    // Continua fino a quando finiscono i tentativi oppure vince
    while (finito == 0) {

        // NECESSARIO PERCHè C++ ha un bug che dopo 2 cicli mi corrompe questo vettore perchè (ipotesi) è vettori vengono sovrascritti da qualcosa
        nPersonaVar = nPersona;
        singoloValVet(nCifre, nPersonaVet, nPersonaVar);

        // Dichiaro variabili
        int cifreIndovinatePersona = 0, cifreIndovinatePC = 0;
        int numeroProvatoPersona, numeroProvatoPersonaVet[nCifre];

        // NECESSARIO PERCHè C++ dopo 2 cicli mi corrompe questo vettore.
        nPersonaVar = nPersona;
        singoloValVet(nCifre, nPersonaVet, nPersonaVar);

        // Variabile bandiera che servirebbe, se non fosse commentato a causa di un problema sconosciuto
        // A verificare se tutti i valori nel vettore dei valori validi trovati, sono presenti nel
        // numero generato che andrà a fare il nuovo tentativo del computer
        int tuttiValPres = 1;
        while (tuttiValPres != 0) {
            tuttiValPres = 0;
            // Variabile bandiera che conta quante cifre valide sono state generate
            int valAgg = 0;
            while (valAgg < nCifre) {
                // Variabile bandiera che rimane 0 fintanto che il valore generato sia valido
                int condBand = 0;

                // Verifica se si sta modificando un numero nel vettore che ha già una posizione corretta, nel
                // caso lo sia, salta questa parte.
                if (vetPCCorPos[valAgg] != 1) {

                    // Metodi sperimentali ma con un ragionamento simile al vecchio
                    nProvatoPCVet[valAgg] = rand() % (max - (min) + 1) + (min);
                    while (valorePresenteInVet(valAgg, nProvatoPCVet[valAgg], nProvatoPCVet)) {
                        nProvatoPCVet[valAgg] = rand() % (max - (min) + 1) + (min);
                    }

                    // Condizioni per un numero valido
                    // Nuovo metodo per verificare che un numero generato casuale è già stato provato ed era sbagliato in precedenza
                    // Nuovo metodo che verifica se un numero è già stato generato in precedenza e aggiunto al vettore (evitare doppioni)
                    if (!(valorePresenteInVet(nNumeriSbagliati, nProvatoPCVet[valAgg], nProvatiPCSbagliati)) &&
                        !(valorePresenteInVet(valAgg, nProvatoPCVet[valAgg], nProvatoPCVet))) {
                        valAgg++;
                    }

                } else {
                    valAgg++;
                }
            }
            // Controlla per ogni valore presente nel vettore dei valori validi trovati, se questo è presente
            // nel vettore del numero che sto per provare come tentativo, se un valore del vettore dei numeri validi
            // non è presente nel numero finale, incrementa il valore bandiera che invaliderà la condizione del while
            // e quindi farà rifare il loop per generare un nuovo numero
            // L'unico problema è che venendo aggiunti spesso anche dei valori non validi per motivi sconosciuti
            // e a volte anche doppi, questo metodo si invalida, quindi l'ho commentato.
            //for (int i = 0; i < nValTrov; i++) {
            //    if (!valorePresenteInVet(nCifre, vetNValTrov[nValTrov], nProvatoPCVet)){
            //        tuttiValPres++;
            //    }
            //}
        }

        // Messaggio che comunica output PC man mano mentre esegue la strategia
        printf(BLUE "\nPC: " RESET);

        // Per ogni cifra nel vettore esegue un ciclo
        for (int i = 0; i < nCifre; i++) {

            // Variabile doppia perchè nProvatoPCVet[i] tende a cambiare valore a caso
            int numeroDaAggiungere = nProvatoPCVet[i];

            // Sperimentale, nuova versione con funzione creata apposta
            if (!valorePresenteInVet(nCifre, numeroDaAggiungere, nPersonaVet) && !valorePresenteInVet(nNumeriSbagliati, numeroDaAggiungere , nProvatiPCSbagliati)){
                // Aggiunge il numero all'insieme
                nProvatiPCSbagliati[nNumeriSbagliati] = numeroDaAggiungere;
                nNumeriSbagliati++;
            }

            // Se il valore è contenuto nel vettore del numero da indovinare della persona, supera la prima condizione
            // Se poi questo NON è contenuto nel vettore dei numeri validi, supera anche la seconda condizione
            // L'unico problema con questo, è che per qualche motivo mi aggiunge anche dei valori non validi, ignorando
            // Totalmente il primo if, e a volte anche il secondo mettendoli quindi doppi
            // Per questo l'ho commentato
            //if (valorePresenteInVet(nCifre, numeroDaAggiungere, nPersonaVet)){
            //    if (!valorePresenteInVet(nValTrov, numeroDaAggiungere, vetNValTrov)){
            //        vetNValTrov[nValTrov] = numeroDaAggiungere;
            //        nValTrov++;
            //    }
            //}

            // Verifica se il valore provato è uguale e nella stessa posizione con quello inserito dall'utente
            if (numeroDaAggiungere == nPersonaVet[i]){
                // Setta a 1 il valore nel vettore per comunicare che in questa posizione il numero è corretto
                // e nella posizione giusta, quindi non è da modificare in futuro
                vetPCCorPos[i] = 1;
                // Incrementa il numero delle cifre indovinate, se questo diventa uguale a nCifre allora il
                // PC ha trovato il numero
                cifreIndovinatePC++;
                // Output
                printf(GREEN "[%d]" RESET, nPersonaVet[i]);
            } else if (valorePresenteInVet(nCifre, numeroDaAggiungere, nPersonaVet)){
                // Carino a livello visivo anche se per ora inutile praticamente, questo verifica
                // se il numero è almeno contenuto nel numero da indovinare, quindi il computer
                // NON conosce la posizione, comunque mette un output visivo per dare pressione
                // all'utente e comunque è parte del gioco.
                printf(YELLOW "(%d)" RESET, numeroDaAggiungere);
            }
        }

        // Chiedo input all'utente per tentare di indovinare il numero
        printf("\nInserisci un numero: ");
        scanf("%d", &numeroProvatoPersona);
        singoloValVet(nCifre, numeroProvatoPersonaVet, numeroProvatoPersona);

        // Inizia verifica dei valori inseriti dall'utente
        printf("\nPersona: ");
        // Persona (uso il vecchio metodo di output che va bene)
        for (int i = 0; i < nCifre; i++) {
            for (int j = 0; j < nCifre; j++) {
                if (mioVettore[i] == numeroProvatoPersonaVet[j] && i == j){
                    printf(GREEN "[%d]" RESET, mioVettore[i]);
                    cifreIndovinatePersona++;
                } else if (mioVettore[i] == numeroProvatoPersonaVet[j]){
                    printf(YELLOW "(%d)" RESET, mioVettore[i]);
                }
            }
        }

        // Qualcuno ha vinto? Oppure hanno vinto entrambi?
        if (cifreIndovinatePC == cifreIndovinatePersona && cifreIndovinatePC == nCifre){
            printf(YELLOW "\n\nComplimenti! Te e il PC avete finito nello stesso turno! Pareggio!"
                   "\nIl tuo numero era: %d"
                   "\nIl numero del PC era: %d" RESET, nPersona, numeroProvatoPersona);
            finito++;
        } else if (cifreIndovinatePC == nCifre){
            printf(RED "\n\nHai perso! Ha vinto il computer!"
                   "\nIl tuo numero era %d" RESET, nPersona);
            finito++;
        } else if (cifreIndovinatePersona == nCifre){
            printf(GREEN "\n\nHai vinto e battuto il computer! Il numero %d è corretto!" RESET, numeroProvatoPersona);
            finito++;
        }
    }

    // Messaggio di fine
    printf(RED "\nFine del gioco..." RESET);
}

void genValDivInVet1(int mioVettore[], int max, int min, int nCifre,
                     int nCifreGenerate) {// Genero N cifre diverse tra loro e le aggiungo al vettore.
    while (nCifreGenerate < nCifre) {

        // Ottiene un numero casuale
        int numeroRandom = rand() % (max - (min) + 1) + (min), valorePres = 0;

        // Verifica se il numero casuale è già stato aggiunto tra le cifre.
        for (int i = 0; i < nCifreGenerate; i++) {
            if (mioVettore[i] == numeroRandom) {
                valorePres++;
            }
        }

        // Se il numero NON era presente tra le cifre generate, lo aggiunge tra le cifre generate.
        if (valorePres == 0) {
            mioVettore[nCifreGenerate] = numeroRandom;
            nCifreGenerate++;
        }
    }
}

bool valorePresenteInVet(int dimensioni, int numeroDaTrovare, const int vettore[]){

    for (int i = 0; i < dimensioni; i++) {
        if (vettore[i] == numeroDaTrovare){
            // Il valore è presente nel vettore
            return true;
        }
    }
    // Non è stato il valore nel vettore, non è presente
    return false;
}

void masterMindPC2(int max, int min, int nCifre) {

    // Dichiaro variabili
    int nPersona, nPersonaVar, nPersonaVet[nCifre], nTentativi = 0;

    // Chiedo in input all'utente il numero da indovinare
    printf("\nInserisci il numero che dovrà indovinare il pc: ");
    scanf("%d", &nPersona);

    // Creo una seconda variabile uguale perchè spesso per motivi sconosciuti e in modo completamente casuale, modificava la variabile
    nPersonaVar = nPersona;

    // Richiamo funzione che divide il numero unico in singoli numeri in un vettore
    singoloValVet(nCifre, nPersonaVet, nPersonaVar);

    // Ottengo srand
    srand(time(0));

    // Numeri generati con successo, lo comunico e inizio.
    printf("\nGenerato con successo un numero con %d cifre! Inizia il gioco...\n", nCifre);

    // Dichiaro ulteriori variabili
    int finito = 0, numeriPossibili = (max - min) + 1, vetPCCorPos[nCifre], nProvatoPCVet[nCifre], nValTrov = 0, vetNValTrov[nValTrov];

    // Variabili commentate parte avanzata
    int nNumeriSbagliati = 0, nProvatiPCSbagliati[numeriPossibili];

    // Inizializza con un valore pari a 0 il vettore che comunica se un numero casuale nel vettore dei tentativi
    // fatti dal computer era corretto, così non viene modificato in futuro.
    for (int i = 0; i < nCifre; i++) {
        vetPCCorPos[i] = 0;
    }

    // Continua fino a quando finiscono i tentativi oppure vince
    while (finito == 0) {

        // Incrementa numero di tentativi
        nTentativi++;

        // NECESSARIO PERCHè C++ dopo 2 cicli mi corrompe questo vettore.
        nPersonaVar = nPersona;
        singoloValVet(nCifre, nPersonaVet, nPersonaVar);

        // Numero di cifre indovinate, quando questo raggiunge un valore pari al numero delle cifre, ferma
        // il ciclo
        int cifreIndovinatePC = 0;

        int tuttiValPres = 1;
        while (tuttiValPres != 0) {
            tuttiValPres = 0;
            // Variabile bandiera che conta quante cifre valide sono state generate
            int valAgg = 0;
            while (valAgg < nCifre) {
                // Variabile bandiera che rimane 0 fintanto che il valore generato sia valido
                int condBand = 0;

                // Verifica se si sta modificando un numero nel vettore che ha già una posizione corretta, nel
                // caso lo sia, salta questa parte.
                if (vetPCCorPos[valAgg] != 1) {

                    // Metodi sperimentali ma con un ragionamento simile al vecchio
                    nProvatoPCVet[valAgg] = rand() % (max - (min) + 1) + (min);
                    while (valorePresenteInVet(valAgg, nProvatoPCVet[valAgg], nProvatoPCVet)) {
                        nProvatoPCVet[valAgg] = rand() % (max - (min) + 1) + (min);
                    }

                    // Condizioni per un numero valido
                    // Nuovo metodo per verificare che un numero generato casuale è già stato provato ed era sbagliato in precedenza
                    // Nuovo metodo che verifica se un numero è già stato generato in precedenza e aggiunto al vettore (evitare doppioni)
                    if (!(valorePresenteInVet(nNumeriSbagliati, nProvatoPCVet[valAgg], nProvatiPCSbagliati)) &&
                        !(valorePresenteInVet(valAgg, nProvatoPCVet[valAgg], nProvatoPCVet))) {
                        valAgg++;
                    }

                } else {
                    valAgg++;
                }
            }
            // Controlla per ogni valore presente nel vettore dei valori validi trovati, se questo è presente
            // nel vettore del numero che sto per provare come tentativo, se un valore del vettore dei numeri validi
            // non è presente nel numero finale, incrementa il valore bandiera che invaliderà la condizione del while
            // e quindi farà rifare il loop per generare un nuovo numero
            // L'unico problema è che venendo aggiunti spesso anche dei valori non validi per motivi sconosciuti
            // e a volte anche doppi, questo metodo si invalida, quindi l'ho commentato.
            //for (int i = 0; i < nValTrov; i++) {
            //    if (!valorePresenteInVet(nCifre, vetNValTrov[nValTrov], nProvatoPCVet)){
            //        tuttiValPres++;
            //    }
            //}
        }

        // Messaggio che comunica output PC man mano mentre esegue la strategia
        printf("\nPC: ");

        // PC
        // Per ogni cifra nel vettore esegue un ciclo
        for (int i = 0; i < nCifre; i++) {

            // Ottengo valore e setto parametro.
            int numeroDaAggiungere = nProvatoPCVet[i];

            // Sperimentale, nuova versione con funzione creata apposta
            if (!valorePresenteInVet(nCifre, numeroDaAggiungere, nPersonaVet) && !valorePresenteInVet(nNumeriSbagliati, numeroDaAggiungere , nProvatiPCSbagliati)){
                // Aggiunge il numero all'insieme
                nProvatiPCSbagliati[nNumeriSbagliati] = numeroDaAggiungere;
                nNumeriSbagliati++;
            }

            // Se il valore è contenuto nel vettore del numero da indovinare della persona, supera la prima condizione
            // Se poi questo NON è contenuto nel vettore dei numeri validi, supera anche la seconda condizione
            // L'unico problema con questo, è che per qualche motivo mi aggiunge anche dei valori non validi, ignorando
            // Totalmente il primo if, e a volte anche il secondo mettendoli quindi doppi
            // Per questo l'ho commentato
            //if (valorePresenteInVet(nCifre, numeroDaAggiungere, nPersonaVet)){
            //    if (!valorePresenteInVet(nValTrov, numeroDaAggiungere, vetNValTrov)){
            //        vetNValTrov[nValTrov] = numeroDaAggiungere;
            //        nValTrov++;
            //    }
            //}

            // Verifica se il valore provato è uguale e nella stessa posizione con quello inserito dall'utente
            if (numeroDaAggiungere == nPersonaVet[i]){
                // Setta a 1 il valore nel vettore per comunicare che in questa posizione il numero è corretto
                // e nella posizione giusta, quindi non è da modificare in futuro
                vetPCCorPos[i] = 1;
                // Incrementa il numero delle cifre indovinate, se questo diventa uguale a nCifre allora il
                // PC ha trovato il numero
                cifreIndovinatePC++;
                // Output
                printf("[%d]", nPersonaVet[i]);
            } else if (valorePresenteInVet(nCifre, numeroDaAggiungere, nPersonaVet)){
                // Carino a livello visivo anche se per ora inutile praticamente, questo verifica
                // se il numero è almeno contenuto nel numero da indovinare, quindi il computer
                // NON conosce la posizione, comunque mette un output visivo per dare pressione
                // all'utente e comunque è parte del gioco.
                printf("(%d)", nProvatoPCVet[i]);
            }
        }

        // Comunico i risultati
        if (cifreIndovinatePC == nCifre){
            printf("\n\nIl computer ha trovato il numero!"
                   "\n- Il tuo numero era %d."
                   "\n- Sono stati necessari %d tentativi.", nPersona, nTentativi);
            finito++;
        }
    }

    // Messaggio di fine
    printf("\nFine del gioco...");
}

void masterMindPC(int max, int min, int nCifre) {

    //-----------------------------------------------//
    // ATTENZIONE: Ho commentato delle parti che
    // Per motivi sconosciuti, mi sono costate giorni
    // Di prove e tantati fix, il ragionamento era corretto
    // Ma uscivano risultati inattesi, come un bug
    // Del linguaggio, comunque cose ridondanti, il
    // Metodo avrebbe dovuto dimezzare il numero di
    // tentativi medio per trovare un numero, specialmente
    // se con molte cifre.
    //
    // Il ragionamento era di aggiungere in un vettore
    // i numeri che non erano contenuti nel numero inserito
    // dall'utente da indovinare, questi infatti venivano
    // inseriti dal computer mano mano e poi scartati
    // finchè non si giungeva solamente a X numeri con cui
    // indovinare il valore finale.
    // Purtroppo si corrompeva e aggiungeva a caso,
    // normalmente al secondo while, anche i numeri validi
    // nonostante le condizioni avrebbero dovuto evitarlo.
    //-----------------------------------------------//

    // Dichiaro variabili
    int nPersona, nPersonaVar, nPersonaVet[nCifre], nTentativi = 0;

    // Chiedo in input all'utente il numero da indovinare
    printf("\nInserisci il numero che dovrà indovinare il pc: ");
    scanf("%d", &nPersona);

    // Creo una seconda variabile uguale perchè spesso per motivi sconosciuti e in modo completamente casuale, modificava la variabile
    nPersonaVar = nPersona;

    // Richiamo funzione che divide il numero unico in singoli numeri in un vettore
    singoloValVet(nCifre, nPersonaVet, nPersonaVar);

    // Ottengo srand
    srand(time(0));

    // Numeri generati con successo, lo comunico e inizio.
    printf("\nGenerato con successo un numero con %d cifre! Inizia il gioco...\n", nCifre);

    // Dichiaro ulteriori variabili
    int finito = 0, numeriPossibili = (max - min) + 1, vetPCCorPos[nCifre], nProvatoPCVet[nCifre];

    // Variabili commentate parte avanzata
    int nNumeriSbagliati = 0, nProvatiPCSbagliati[numeriPossibili];

    // Inizializza con un valore pari a 0 il vettore che comunica se un numero casuale nel vettore dei tentativi
    // fatti dal computer era corretto, così non viene modificato in futuro.
    for (int i = 0; i < nCifre; i++) {
        vetPCCorPos[i] = 0;
    }

    // Continua fino a quando finiscono i tentativi oppure vince
    while (finito == 0) {

        // Incrementa numero di tentativi
        nTentativi++;

        // NECESSARIO PERCHè C++ dopo 2 cicli mi corrompe questo vettore.
        nPersonaVar = nPersona;
        singoloValVet(nCifre, nPersonaVet, nPersonaVar);

        // Numero di cifre indovinate, quando questo raggiunge un valore pari al numero delle cifre, ferma
        // il ciclo
        int cifreIndovinatePC = 0;

        // Variabile bandiera che conta quante cifre valide sono state generate
        int valAgg = 0;
        while (valAgg < nCifre){
            // Variabile bandiera che rimane 0 fintanto che il valore generato sia valido
            int condBand = 0;

            // Verifica se si sta modificando un numero nel vettore che ha già una posizione corretta, nel
            // caso lo sia, salta questa parte.
            if (vetPCCorPos[valAgg] != 1) {
                // Genera numero casuale compreso tra Max e Min
                nProvatoPCVet[valAgg] = rand() % (max - (min) + 1) + (min);

                // Nuovo metodo per verificare che un numero generato casuale è già stato provato ed era sbagliato in precedenza
                if (std::find(nProvatiPCSbagliati, nProvatiPCSbagliati + nNumeriSbagliati, nProvatoPCVet[valAgg]) != nProvatiPCSbagliati + nNumeriSbagliati) {
                    condBand++;
                }

                    //for (int i = 0; i < nNumeriSbagliati; i++) {
                //    if (nProvatiPCSbagliati[i] == nProvatoPCVet[valAgg]) {
                //        condBand++;
                //    }
                //}

                // Verifica se il numero generato è lo stesso generato in precedenza nella stessa posizione
                for (int i = 0; i < valAgg; i++) {
                    if (nProvatoPCVet[i] == nProvatoPCVet[valAgg]) {
                        condBand++;
                    }
                }
            }

            // Incrementa in caso sia stato generato un valore con successo
            if (condBand == 0){
                valAgg++;
            }
        }

        // Messaggio che comunica output PC man mano mentre esegue la strategia
        printf("\nPC: ");

        // PC
        // Per ogni cifra nel vettore esegue un ciclo
        for (int i = 0; i < nCifre; i++) {

            // Sperimentale, ho dovuto informarmi su internet visto che il mio metodo si corrompe
            if (std::find(nPersonaVet, nPersonaVet + nCifre, nProvatoPCVet[i]) == nPersonaVet + nCifre){

                int numeroDaAggiungere = nProvatoPCVet[i];

                // Variabile bandiera
                int trovPrima = 0;

                if (std::find(nProvatiPCSbagliati, nProvatiPCSbagliati + nNumeriSbagliati, numeroDaAggiungere) == nProvatiPCSbagliati + nNumeriSbagliati) {

                    // Se non è presente mi ritrovo qui
                    //for (int j = 0; j < nNumeriSbagliati; j++) {
                    //    if (nProvatiPCSbagliati[j] == nProvatoPCVet[i]){
                    //        trovPrima++;
                    //    }
                    //}

                    // Se è diverso da 0 allora il numero è già presente nell'insieme
                    //if (trovPrima == 0) {
                        nProvatiPCSbagliati[nNumeriSbagliati] = numeroDaAggiungere;
                        nNumeriSbagliati++;
                    //}
                }
            }

            // Variabile bandiera
            // int nCond = 0;
            // Verifica se il valore provato è uguale e nella stessa posizione con quello inserito dall'utente
            if (nProvatoPCVet[i] == nPersonaVet[i]){
                // Setta a 1 il valore nel vettore per comunicare che in questa posizione il numero è corretto
                // e nella posizione giusta, quindi non è da modificare in futuro
                vetPCCorPos[i] = 1;
                // Incrementa il numero delle cifre indovinate, se questo diventa uguale a nCifre allora il
                // PC ha trovato il numero
                cifreIndovinatePC++;
                // Output
                printf("[%d]", nPersonaVet[i]);
                // nCond++;
            } else {
                // Secondo ciclo for che verifica se nel secondo vettore è presente, in 2 posizioni diverse, un numero
                // Questo è praticamente inutile senza la versione avanzata che verificava se un numero era
                // assente, comunque è carino a livello visivo.
                for (int j = 0; j < nCifre; j++) {
                    if (nProvatoPCVet[i] == nPersonaVet[j]) {
                        printf("(%d)", nPersonaVet[j]);
                        // nCond++;
                    }
                }
            }

            //if (nCond == 0){
            //    int cond = 0;
            //
            //    for (int k = 0; k < nNumeriSbagliati; k++) {
            //        if (nProvatiPCSbagliati[k] == nProvatoPCVet[i]){
            //            cond++;
            //        }
            //    }
            //
            //    if (cond == 0) {
            //        nProvatiPCSbagliati[nNumeriSbagliati] = nProvatoPCVet[i];
            //        nNumeriSbagliati++;
            //    }
            //}
        }

        // Comunico i risultati
        if (cifreIndovinatePC == nCifre){
            printf("\n\nIl computer ha trovato il numero!"
                "\n- Il tuo numero era %d."
                "\n- Sono stati necessari %d tentativi.", nPersona, nTentativi);
            finito++;
        }
    }

    // Messaggio di fine
    printf("\nFine del gioco...");
}

void nuovoMasterMindVSPC(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate) {

    // Dichiaro variabili
    int nPersona, nPersonaVar, nPersonaVet[nCifre];

    // Chiedo input all'utente
    printf("\nInserisci il numero che dovrà indovinare il pc: ");
    scanf("%d", &nPersona);

    // Doppia dichiarazione di un valore perchè ogni tanto veniva modificato o comunque cambiava valore per motivi sconosciuti
    nPersonaVar = nPersona;

    // Divide in singole cifre in un vettore un numero
    singoloValVet(nCifre, nPersonaVet, nPersonaVar);

    // Ottengo srand
    srand(time(0));

    // Genero N cifre diverse tra loro e le aggiungo al vettore.
    while (nCifreGenerate < nCifre) {

        // Ottiene un numero casuale
        int numeroRandom = rand() % (max - (min) + 1) + (min), valorePres = 0;

        // Verifica se il numero casuale è già stato aggiunto tra le cifre.
        for (int i = 0; i < nCifreGenerate; i++) {
            if (mioVettore[i] == numeroRandom) {
                valorePres++;
            }
        }

        // Se il numero NON era presente tra le cifre generate, lo aggiunge tra le cifre generate.
        if (valorePres == 0) {
            mioVettore[nCifreGenerate] = numeroRandom;
            nCifreGenerate++;
        }
    }

    // Numeri generati con successo, lo comunico e inizio.
    printf("\nGenerato con successo un numero con %d cifre! Inizia il gioco...\n", nCifre);

    // Inizializzo diverse variabili
    int finito = 0, nNumeriSbagliati = 0, numeriPossibili = (max - min) + 1, vetNumeriPossibili[numeriPossibili], nProvatiPCSbagliati[nNumeriSbagliati], vetPCCorPos[nCifre], nProvatoPCVet[nCifre];

    // Inizializza a zero i valori nel vettore
    for (int i = 0; i < nCifre; ++i) {
        vetPCCorPos[i] = 0;
    }

    // Continua fino a quando finiscono i tentativi oppure vince
    while (finito == 0) {

        // NECESSARIO PERCHè C++ ha un bug che dopo 2 cicli mi corrompe questo vettore perchè qualcuno mi odia
        nPersonaVar = nPersona;
        singoloValVet(nCifre, nPersonaVet, nPersonaVar);

        // Dichiaro variabili
        int cifreIndovinatePersona = 0, cifreIndovinatePC = 0;
        int numeroProvatoPersona, numeroProvatoPersonaVet[nCifre];

        // NECESSARIO PERCHè C++ dopo 2 cicli mi corrompe questo vettore.
        nPersonaVar = nPersona;
        singoloValVet(nCifre, nPersonaVet, nPersonaVar);

        // Variabile bandiera che conta quante cifre valide sono state generate
        int valAgg = 0;
        while (valAgg < nCifre){
            // Variabile bandiera che rimane 0 fintanto che il valore generato sia valido
            int condBand = 0;

            // Verifica se si sta modificando un numero nel vettore che ha già una posizione corretta, nel
            // caso lo sia, salta questa parte.
            if (vetPCCorPos[valAgg] != 1) {
                // Genera numero casuale compreso tra Max e Min
                nProvatoPCVet[valAgg] = rand() % (max - (min) + 1) + (min);

                // Nuovo metodo per verificare che un numero generato casuale è già stato provato ed era sbagliato in precedenza
                if (std::find(nProvatiPCSbagliati, nProvatiPCSbagliati + nNumeriSbagliati, nProvatoPCVet[valAgg]) != nProvatiPCSbagliati + nNumeriSbagliati) {
                    condBand++;
                }

                //for (int i = 0; i < nNumeriSbagliati; i++) {
                //    if (nProvatiPCSbagliati[i] == nProvatoPCVet[valAgg]) {
                //        condBand++;
                //    }
                //}

                // Verifica se il numero generato è lo stesso generato in precedenza nella stessa posizione
                for (int i = 0; i < valAgg; i++) {
                    if (nProvatoPCVet[i] == nProvatoPCVet[valAgg]) {
                        condBand++;
                    }
                }
            }

            // Incrementa in caso sia stato generato un valore con successo
            if (condBand == 0){
                valAgg++;
            }
        }

        // Messaggio che comunica output PC man mano mentre esegue la strategia
        printf("\nPC: ");

        // Per ogni cifra nel vettore esegue un ciclo
        for (int i = 0; i < nCifre; i++) {
            // Variabile bandiera
            int nCond = 0;

            // Sperimentale, ho dovuto informarmi su internet visto che il mio metodo si corrompe
            if (std::find(nPersonaVet, nPersonaVet + nCifre, nProvatoPCVet[i]) == nPersonaVet + nCifre){

                int numeroDaAggiungere = nProvatoPCVet[i];

                // Variabile bandiera
                int trovPrima = 0;

                if (std::find(nProvatiPCSbagliati, nProvatiPCSbagliati + nNumeriSbagliati, numeroDaAggiungere) == nProvatiPCSbagliati + nNumeriSbagliati) {

                    // Se non è presente mi ritrovo qui
                    //for (int j = 0; j < nNumeriSbagliati; j++) {
                    //    if (nProvatiPCSbagliati[j] == nProvatoPCVet[i]){
                    //        trovPrima++;
                    //    }
                    //}

                    // Se è diverso da 0 allora il numero è già presente nell'insieme
                    //if (trovPrima == 0) {
                    nProvatiPCSbagliati[nNumeriSbagliati] = numeroDaAggiungere;
                    nNumeriSbagliati++;
                    //}
                }
            }

            // Verifica se il valore provato è uguale e nella stessa posizione con quello inserito dall'utente
            if (nProvatoPCVet[i] == nPersonaVet[i]){
                // Setta a 1 il valore nel vettore per comunicare che in questa posizione il numero è corretto
                // e nella posizione giusta, quindi non è da modificare in futuro
                vetPCCorPos[i] = 1;
                // Incrementa il numero delle cifre indovinate, se questo diventa uguale a nCifre allora il
                // PC ha trovato il numero
                cifreIndovinatePC++;
                // Output
                printf("[%d]", nPersonaVet[i]);
                // nCond++;
            } else {
                // Secondo ciclo for che verifica se nel secondo vettore è presente, in 2 posizioni diverse, un numero
                // Questo è praticamente inutile senza la versione avanzata che verificava se un numero era
                // assente, comunque è carino a livello visivo.
                for (int j = 0; j < nCifre; j++) {
                    if (nProvatoPCVet[i] == nPersonaVet[j]) {
                        printf("(%d)", nPersonaVet[j]);
                        // nCond++;
                    }
                }
            }
        }

        //int valAgg = 0;
        //while (valAgg < nCifre){
        //    int condBand = 0;
        //    if (vetPCCorPos[valAgg] != 1) {
        //        nProvatoPCVet[valAgg] = rand() % (max - (min) + 1) + (min);
        //        for (int i = 0; i < nNumeriSbagliati; i++) {
        //            if (nProvatiPCSbagliati[i] == nProvatoPCVet[valAgg]) {
        //                condBand++;
        //            }
        //        }

        //        for (int i = 0; i < valAgg; ++i) {
        //            if (nProvatoPCVet[i] == nProvatoPCVet[valAgg]) {
        //                condBand++;
        //            }
        //        }
        //    }

        //    if (condBand == 0){
        //        valAgg++;
        //    }
        //}




        // Vecchio metodo con problemi
        // printf("\nPC: ");
        // PC
        // for (int i = 0; i < nCifre; i++) {
        //    int nCond = 0;
        //    for (int j = 0; j < nCifre; j++) {
        //        if (nProvatoPCVet[i] == nPersonaVet[j] && i == j){
        //            vetPCCorPos[j] = 1;
        //            cifreIndovinatePC++;
        //            printf("[%d]", nPersonaVet[j]);
        //            nCond++;
        //        } else if (nProvatoPCVet[i] == nPersonaVet[j]){
        //            printf("(%d)", nPersonaVet[j]);
        //            nCond++;
        //        }
        //    }

        //    printf("\n%d", nCond);

        //    if (nCond == 0){
        //        int cond = 0;

        //        for (int k = 0; k < nNumeriSbagliati; k++) {
        //            if (nProvatiPCSbagliati[k] == nProvatoPCVet[i]){
        //                cond++;
        //            }
        //        }
        //
        //        if (cond == 0) {
        //            nProvatiPCSbagliati[nNumeriSbagliati] = nProvatoPCVet[i];
        //            nNumeriSbagliati++;
        //        }
        //    }
        //}

        // Chiedo input all'utente per tentare di indovinare il numero
        printf("\nInserisci un numero: ");
        scanf("%d", &numeroProvatoPersona);
        singoloValVet(nCifre, numeroProvatoPersonaVet, numeroProvatoPersona);

        printf("\nPersona: ");
        // Persona
        for (int i = 0; i < nCifre; i++) {
            for (int j = 0; j < nCifre; j++) {
                if (mioVettore[i] == numeroProvatoPersonaVet[j] && i == j){
                    printf("[%d]", mioVettore[i]);
                    cifreIndovinatePersona++;
                } else if (mioVettore[i] == numeroProvatoPersonaVet[j]){
                    printf("(%d)", mioVettore[i]);
                }
            }
        }

        // Uscita, vittoria del computer
        if (cifreIndovinatePC == nCifre){
            printf("\n\nHai perso! Ha vinto il computer!"
                   "\nIl tuo numero era %d", nPersona);
            finito++;
        }

        // Uscita, vittoria dell'utente
        if (cifreIndovinatePersona == nCifre){
            printf("\n\nHai vinto! Il numero %d è corretto!", numeroProvatoPersona);
            finito++;
        }
    }

    // Messaggio di fine
    printf("\nFine del gioco...");
}

void nuovoMasterMind(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate, int nTentativi) {
    // Ottengo srand
    srand(time(0));

    // Genero N cifre diverse tra loro e le aggiungo al vettore.
    while (nCifreGenerate < nCifre) {

        // Ottiene un numero casuale
        int numeroRandom = rand() % (max - (min) + 1) + (min), valorePres = 0;

        // Verifica se il numero casuale è già stato aggiunto tra le cifre.
        for (int i = 0; i < nCifreGenerate; i++) {
            if (mioVettore[i] == numeroRandom || mioVettore[0] == 0) {
                valorePres++;
            }
        }

        // Se il numero NON era presente tra le cifre generate, lo aggiunge tra le cifre generate.
        if (valorePres == 0) {
            mioVettore[nCifreGenerate] = numeroRandom;
            nCifreGenerate++;
        }
    }

    // Numeri generati con successo, lo comunico e inizio.
    printf("\nGenerato con successo un numero con %d cifre! Inizia il gioco...\n", nCifre);

    int vinto = 0;

    // Continua fino a quando finiscono i tentativi oppure vince
    while (nTentativi != 0 && vinto == 0) {

        int cifreIndovinate = 0;

        nTentativi--;

        int numeroProvato, numeroProvatoVet[nCifre];

        printf("\nInserisci un numero: ");
        scanf("%d", &numeroProvato);

        singoloValVet(nCifre, numeroProvatoVet, numeroProvato);

        for (int i = 0; i < nCifre; i++) {
            for (int j = 0; j < nCifre; j++) {
                if (mioVettore[i] == numeroProvatoVet[j] && i == j){
                    printf("[%d]", mioVettore[i]);
                    cifreIndovinate++;
                } else if (mioVettore[i] == numeroProvatoVet[j]){
                    printf("(%d)", mioVettore[i]);
                }
            }
        }

        if (cifreIndovinate == nCifre){
            printf("\n\nHai vinto! Il numero %d è corretto!"
                   "\nTi rimanevano %d tentativi!", numeroProvato, nTentativi);
            vinto++;
        }

        if (nTentativi == 0 && vinto == 0){
            printf("\n\nHai finito i tentativi, GAME OVER!");
            printf("\nIl numero era: ");
            for (int i = nCifre-1; i >= 0; i--) {
                printf("%d", mioVettore[i]);
            }
        } else if (vinto == 0){
            printf("\nHai ancora %d tentativi.\n", nTentativi);
        }
    }

    printf("\nFine del gioco...");
}

void masterMindTheGame(int mioVettore[], int dimensioni, int max, int min) {// Inizializzo variabili e parametri

    int numeroNumeri = 4;
    int nTentativi, numeroGenerato, numeroGeneratoVar, valSingoliInser[numeroNumeri], bandieraGen = 1, nProvato, valSingoliIndPos[4] = {0}, valInd = 0, valSingoliInd[numeroNumeri];

    // Assegno un valore alle variabili globali, le sto riciclando e non è strettamente necessario, ad eccezione delle dimensioni.
    max = 9999, min = 1000, dimensioni = numeroNumeri;

    // Chiedo all'utente in input il numero di tentativi
    printf("\nInserisci un numero di tentativi: ");
    scanf("%d", &nTentativi);

    srand(time(0));
    numeroGenerato = rand() % (max - (min) + 1) + (min);
    numeroGeneratoVar = numeroGenerato;

    // Richiamo funzione per splittare i valori del numero nel vettore in singoli numeri
    singoloValVet(dimensioni, mioVettore, numeroGeneratoVar);

    while (bandieraGen != 0) {

        // Metto a zero il valore bandiera, questo si incrementerà se ci sono valori doppi
        bandieraGen = 0;

        // Per ogni valore del vettore faccio il confronto tranne con se stesso
        for (int i = 0; i < dimensioni; i++) {
            for (int j = 0; j < dimensioni; j++) {
                // Condizione che verifica se il valore del vettore da verificare è uguale e bypass
                // del valore in caso la posizione del vettore in cui si sta verificando sia la stessa
                // Nota: posizione 3 e 3 hanno per forza lo stesso valore quindi sono da saltare.
                if (mioVettore[i] == mioVettore[j] && i != j){
                    // Se il valore coincide allora incremento valore bandiera
                    bandieraGen++;
                }
            }
        }

        // Se il valore bandiera si è incrementato, genero un nuovo numero e ripeto il tutto
        if (bandieraGen != 0){
            // Genero un nuovo numero casuale
            numeroGenerato = rand() % (max - (min) + 1) + (min);
            numeroGeneratoVar = numeroGenerato;
            // Richiamo funzione per splittare i valori del numero nel vettore in singoli numeri
            singoloValVet(dimensioni, mioVettore, numeroGeneratoVar);
        }
    }

    // Numero generato con successo, inizia il gioco
    printf("\nValore generato con successo! Inizia il gioco...\n");


    // Se bandieraGen è diverso da 0, allora l'utente ha trovato il numero e vinto il gioco, oppure ha finito i tentativi...
    while (bandieraGen == 0) {

        if (valInd > 0){
            printf("\nNumeri trovati in ordine sparso: ");
            for (int i = 0; i < valInd; i++) {
                printf("\t[%d]", valSingoliInd[i]);
            }
        }

        printf("\nNumeri trovati in ordine (0 può essere sia nullo che un numero): ");
        for (int i = numeroNumeri - 1; i >= 0; i--) {
            printf("\t[%d]", valSingoliIndPos[i]);
        }

        // Chiedo un input
        printf("\nInserire un numero a [4] cifre da provare: ");
        scanf("%d", &nProvato);

        // Decremento tentativi rimasti
        nTentativi--;

        // Il numero inserito è uguale
        if (nProvato == numeroGenerato){
            printf("\nComplimenti! Hai indovinato il numero intero con ancora [%d] tentativi rimasti!", nTentativi);
            printf("\nIl numero da indovinare era: [%d]\n", numeroGenerato);
            bandieraGen++;
        }

        // Il valore bandiera viene incrementato quando finisce il gioco o i tentativi, quindi
        // Se questo è diverso da zero, finisco l'algoritmo
        if (bandieraGen == 0) {

            // Richiamo funzione per splittare i valori del numero nel vettore in singoli numeri
            singoloValVet(dimensioni, valSingoliInser, nProvato);

            // Simile a quello che verifica se sono stati inseriti 2 numeri uguali ma modificato
            // Eseguo un loop per ogni cifra nel vettore.
            for (int i = 0; i < dimensioni; i++) {
                for (int j = 0; j < dimensioni; j++) {

                    // Variabile bandiera
                    int trovatoPrima = 0;
                    int trovatoPrima2 = 0;

                    // Se i numeri dei due vettori coincidono e anche la loro posizione (i e j) allora
                    // Significa che la posizione è giusta e viene segnalato all'utente.
                    if (mioVettore[i] == valSingoliInser[j] && i == j){

                        // Verifico se il valore trovato è già stato trovato in precedenza, nel caso non lo
                        // sia, sarà necessario aggiungerlo.
                        for (int k = 0; k < valInd; k++) {
                            if (valSingoliInd[k] == valSingoliInser[j] && trovatoPrima < 1){
                                trovatoPrima++;
                            }
                        }
                        // Aggiunge il valore nel vettore se la condizione è rispettata
                        if (trovatoPrima == 0) {
                            valSingoliInd[valInd] = valSingoliInser[j];
                            valInd++;
                        }
                        for (int k = 0; k < numeroNumeri; k++) {
                            if (valSingoliIndPos[k] == valSingoliInser[j] && trovatoPrima < 1){
                                trovatoPrima2++;
                            }
                        }
                        if (trovatoPrima2 == 0){
                            valSingoliIndPos[j] = valSingoliInser[j];
                        }

                        // Comunico all'utente l'indizio
                        printf("\nIl valore [%d] è contenuto nel numero da indovinare"
                               "\nEd [è] nella posizione CORRETTA!\n", valSingoliInser[j]);
                    } else if (mioVettore[i] == valSingoliInser[j]){

                        // Verifico se il valore trovato è già stato trovato in precedenza, nel caso non lo
                        // sia, sarà necessario aggiungerlo.
                        for (int k = 0; k < valInd; k++) {
                            if (valSingoliInd[k] == valSingoliInser[j] && trovatoPrima < 1){
                                trovatoPrima++;
                            }
                        }
                        // Aggiunge il valore nel vettore se la condizione è rispettata
                        if (trovatoPrima == 0) {
                            valSingoliInd[valInd] = valSingoliInser[j];
                            valInd++;
                        }

                        // Comunico all'utente l'indizio
                        printf("\nIl valore [%d] è contenuto nel numero da indovinare"
                               "\nMa [NON è] nella posizione CORRETTA!\n", valSingoliInser[j]);
                    }
                }
            }

            // Finiti i tentativi o meno
            if (nTentativi <= 0) {
                printf("\nHai finito i tentativi! GAME OVER!");
                printf("\nIl numero da indovinare era: [%d]\n", numeroGenerato);
                bandieraGen++;
            } else {
                printf("\nRimangono [%d] tentativi!", nTentativi);
            }
        }
    }
}

void singoloValVet(int dimensioni, int mioVettore[], int numeroGeneratoVar) {
    for (int i = 0; i < dimensioni; ++i) {
        mioVettore[i] = numeroGeneratoVar % 10;
        numeroGeneratoVar = (numeroGeneratoVar - mioVettore[i]) / 10;
    }
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