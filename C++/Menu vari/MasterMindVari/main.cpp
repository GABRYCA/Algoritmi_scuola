#include <iostream>
#include <stdlib.h>
#include <ctime>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

void continua();
void mostraValori(int dimensioni, int mioVettore[]);
void singoloValVet(int dimensioni, int mioVettore[], int numeroGeneratoVar);

void nuovoMasterMind(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate, int nTentativi);
void nuovoMasterMindVSPC(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate);
void masterMindPC(int max, int min, int nCifre);
void masterMindPC2(int max, int min, int nCifre);
void masterMindPerVSPC2(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate);

bool valorePresenteInVet(int dimensioni, int numeroDaTrovare , const int vettore[]);
void genValDivInVet1(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate);
int trovaValori(int dimensioni, int mioVettore[]);
void rimuoviPerPos(int dimensioni, int mioVettore[], int valore);

void MasterMindPCV3(int max, int min, int dimensioni, int mioVettore[], int nCifre, int nTentativi);

int main() {

    // Messaggi d'inizio
    printf("\nHai scelto: MasterMind migliorato...\n");

    // Inizializzo variabili e assegno valori di default
    int  algoritmoScelto = 1;

    // Se si inserisce un numero uguale a 0 esce
    while (algoritmoScelto != 0) {

        int max = 9, min = 0, dimensioni = 0, mioVettore[10000], nCifre = 4, nCifreGenerate = 0, nTentativi = 10;

        // Legenda e input
        printf("\nChe tipo di MasterMind vuoi: "
               "\n0 -> Esci."
               "\n1 -> MasterMind classico (4 cifre e valori da 0 a 9) con numero di tentativi a scelta. "
               "\n2 -> MasterMind custom con scelta numero cifre da 1 a 9, range valori da 0 a 9 e"
               "\n     numero di tentativi. "
               "\n3 -> (Deprecato) MasterMind Computer."
               "\n4 -> MasterMind persona VS computer."
               "\n5 -> (Deprecato) MasterMind computer 2.0."
               "\n6 -> MasterMind persone VS computer 2.0."
               "\n7 -> Generatore valori diversi."
               "\n8 -> MasterMind computer 3.0."
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

            case 3: {

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

            case 4: {

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

            case 5: {

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

            case 6: {

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
            case 7:{

                printf("\nHai scelto: genera valori in un vettore che non si ripetano...\n");

                // Algoritmo grezzo che non funziona molto bene, sostituito da quello nuovo successivo
                // migliorato
                // int nGenerato = 1234, nGeneratoVar, nCifre = 4, singoliValVetGen[nCifre];
                // dimensioni = 0;

                // while (nGenerato <= 9876){

                //    nGeneratoVar = nGenerato;

                //    singoloValVet(nCifre, singoliValVetGen, nGeneratoVar);

                // Verifica che il numero generato non abbia valori doppi
                //    int valPres = 0;
                //    for (int i = 0; i < nCifre; i++) {
                //        for (int j = 0; j < nCifre; j++) {
                //            if (singoliValVetGen[i] == singoliValVetGen[j] && i != j){
                //                valPres++;
                //            }
                //        }
                //    }

                //    if (valPres == 0) {

                // Verifico che dei vettori generati non ci siano doppi
                //        int doppi = 0;
                //        int singoliValMioVet[nCifre];
                //        for (int i = 0; i < dimensioni; i++) {
                //            singoloValVet(nCifre, singoliValMioVet, mioVettore[i]);
                //            for (int j = 0; j < nCifre; j++) {
                //                for (int k = 0; k < nCifre; k++) {
                //                    if (singoliValVetGen[j] == singoliValMioVet[k] && j != k){
                //                        doppi++;
                //                    }
                //                }
                //            }
                //        }

                //        if (!valorePresenteInVet(dimensioni, nGenerato, mioVettore) && valPres == 0) {
                //            mioVettore[dimensioni] = nGenerato;
                //            dimensioni++;
                //        }
                //    }
                //    nGenerato++;
                //}

                // Richiama funzione nuovo algoritmo migliorato
                trovaValori(dimensioni, mioVettore);

                continua();
                break;
            }
            case 8:{

                // Messaggioi d'inizio
                printf("\n\nHai scelto: MasterMind PC 3.0...");

                // Richiamo MasterMind 3.0
                MasterMindPCV3(max, min, dimensioni, mioVettore, nCifre, nTentativi);

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

        return 0;
    }
}

void MasterMindPCV3(int max, int min, int dimensioni, int mioVettore[], int nCifre, int nTentativi) {

    // Dichiaro variabili
    int nValSbagliati = 0, vetValSbagliati[6] = {10}, vinto = 0, nPersona, nPersonaVar, nPersonaVet[4] = {10}, nUniciProvati = 0, vetUniciProvati[100];
    nTentativi = 0;

    // Chiedo in input all'utente il numero da indovinare
    printf("\nInserisci il numero che dovrà indovinare il pc: ");
    scanf("%d", &nPersona);

    // Creo una seconda variabile uguale perchè spesso per motivi sconosciuti e in modo completamente casuale, modificava la variabile
    nPersonaVar = nPersona;

    // Genera tutti i valori possibili
    dimensioni = trovaValori(dimensioni, mioVettore);

    // Richiamo funzione che divide il numero unico in singoli numeri in un vettore
    singoloValVet(nCifre, nPersonaVet, nPersonaVar);

    while (vinto == 0){

        nTentativi++;

        // Richiamo funzione che divide il numero unico in singoli numeri in un vettore
        singoloValVet(nCifre, nPersonaVet, nPersonaVar);

        int numeriTrovati = 0, numeriTrovatiNoPos = 0, vetNumGenPC[4] = {10};

        printf(RED "\n\n\nPer favore attendere..." RESET);

        // Rimuove dalla lista dei valori possibili quelli non possibili
        for (int i = 0; i < dimensioni; i++) {

            int singoliValVetDim[nCifre];
            singoloValVet(nCifre, singoliValVetDim, mioVettore[i]);

            for (int j = 0; j < nValSbagliati; j++) {
                if (valorePresenteInVet(nCifre, vetValSbagliati[nValSbagliati], singoliValVetDim)){
                    rimuoviPerPos(dimensioni, mioVettore, i);
                    dimensioni--;
                }
            }
        }

        printf(YELLOW "\n\nLe possibilità si sono ridotte alle seguenti: ");

        mostraValori(dimensioni, mioVettore);

        printf(RESET);

        // Valore bandiera
        int valValido = 1, valUnico = 0;
        while (valValido != 0) {
            valValido = 0;
            int contenuto = 0, numeriGenPC = 0;
            // Crea un nuovo valore da provare senza i valori non validi e condizioni varie
            while (numeriGenPC != nCifre) {
                vetNumGenPC[numeriGenPC] = rand() % (max - (min) + 1) + (min);
                if (!valorePresenteInVet(nValSbagliati, vetNumGenPC[numeriGenPC], vetValSbagliati) &&
                    !valorePresenteInVet(numeriGenPC, vetNumGenPC[numeriGenPC], vetNumGenPC)) {
                    numeriGenPC++;
                }
            }

            // Ulteriori condizioni
            if (nPersonaVet[3] != 0 && vetNumGenPC[3] != 0) {

                // Valore unico completo
                valUnico = ((10 * vetNumGenPC[3] + vetNumGenPC[2]) * 10 + vetNumGenPC[1]) * 10 +
                               vetNumGenPC[0];

                // Verifica se il valore è già stato provato in precedenza per non ripeterlo ancora
                for (int i = 0; i < nUniciProvati; i++) {
                    if (vetUniciProvati[i] == valUnico){
                        valValido++;
                    }
                }

                // Verifica se il valore è contenuto tra quelli possibili
                for (int i = 0; i < dimensioni; i++) {
                    if (valUnico == mioVettore[i] && contenuto == 0) {
                        contenuto++;
                    }
                }

                // Se entrambi le variabili sono uguali a 0, allora incrementa valValido che fa ripetere il while
                if (contenuto == 0 && valValido == 0) {
                    valValido++;
                }
            }
        }

        // Aggiunge il valore unico generato al vettore dei valori provati
        if (valUnico != 0){
            vetUniciProvati[nUniciProvati] = valUnico;
            nUniciProvati++;
        }

        // Verifica [] o () per il computer in modo virtuale, salvando i dati utili per
        // Trovare il valore in un turno successivo
        for (int i = 0; i < nCifre; i++) {

            // La cifra che sta provando
            int valInTentativo = vetNumGenPC[i];

            // La prima condizione verifica se la cifra è nella stessa posizione della cifra
            // Del numero inserito dall'utente da indovinare.
            // La seconda verifica se questo è solamente contenuto.
            // La terza, aggiunge il valore (se sbagliato e non già presente in precedenza) al vettore
            // dei valori non validi.
            if (valInTentativo == nPersonaVet[i]){
                numeriTrovati++;
            } else if (valorePresenteInVet(nCifre, valInTentativo, nPersonaVet)){
                numeriTrovatiNoPos++;
            } else if (!valorePresenteInVet(nValSbagliati, valInTentativo, vetValSbagliati)) {
                vetValSbagliati[nValSbagliati] = valInTentativo;
                nValSbagliati++;
            }
        }

        // Stampa [] o (), dove [] sono i valori trovati sia per posizione che per valore esatto
        // Mentre i () sono quelli solamente presenti
        printf(BLUE "\n\nNumeri PC:" RESET);
        for (int i = 0; i < numeriTrovati; i++) {
            printf(GREEN "[]" RESET);
        }
        for (int i = 0; i < numeriTrovatiNoPos; ++i) {
            printf(YELLOW "()" RESET);
        }

        // Se sono stati trovati 4 numeri validi nella posizione corretta, incrementa vinto ed esce dal while, finendo il gioco.
        if (numeriTrovati == 4){
            vinto++;
        }
    }

    // Fine
    printf(GREEN "\n\nAlgoritmo finito, il numero dell'utente era %d."
                 "\nSono stati necessari %d tentativi!" RESET, nPersona, nTentativi);
}

int trovaValori(int dimensioni, int mioVettore[]) {

    // Prima cifra
    for (int i = 0; i < 10 ; i++){

        // Seconda cifra.
        for (int j = 0; j < 10 ; j++) {

            // Se il valore è diverso va avanti
            if (j != i) {

                // Terza cifra.
                for (int k = 0; k < 10; k++) {

                    // Se i valori sono diversi allora va avanti
                    if (!(k == j || k == i)) {

                        // Quarta cifra.
                        for (int l = 0; l < 10; l++) {

                            // Se i valori sono tutti diversi, allora va avanti
                            if (!(l == k || l == j || l == i)) {

                                // Ottengo valore finale e lo aggiungo, poi incremento le dimensioni.
                                mioVettore[dimensioni] = ((10 * i + j) * 10 + k) * 10 + l;
                                dimensioni++;
                            }
                        }
                    }
                }
            }
        }
    }

    // Comunica che i valori sono stati generati con successo e quanti sono.
    printf(GREEN "\nSono stati generati i valori con successo!\n" RESET);

    return dimensioni;
}

void rimuoviPerPos(int dimensioni, int mioVettore[],
                   int valore) {

    // Loop per eliminare "valore" e spostare tutti i valori
    for (int i = valore; i < dimensioni - 1; i++) {

        mioVettore[i] = mioVettore[i + 1];

    }
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
    int finito = 0, nNumeriSbagliati = 0, numeriPossibili = (max - min) + 1, vetNumeriPossibili[numeriPossibili], nProvatiPCSbagliati[nNumeriSbagliati], vetPCCorPos[nCifre], nProvatoPCVet[nCifre], nValTrov = 0, vetNValTrov[nValTrov], nTurno = 0;

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
        int cifreIndovinatePersona = 0, cifreIndovinatePC = 0, cifrePersonaNoPos = 0, cifrePCNoPos = 0;
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

        // Incremento il numero dei turni passati
        nTurno++;

        // Comunica il numero del turno
        printf( YELLOW "\n///////////////////////////// \n"
        BLUE "\nQuesto è il %d° turno...\n" RESET, nTurno);

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

            // Strategia del computer
            // Verifica se il valore provato è uguale e nella stessa posizione, quindi quadrato in output di solito
            if (numeroDaAggiungere == nPersonaVet[i]){
                // Setta a 1 il valore nel vettore per comunicare che in questa posizione il numero è corretto
                // e nella posizione giusta, quindi non è da modificare in futuro
                vetPCCorPos[i] = 1;
                // Incrementa il numero delle cifre indovinate, se questo diventa uguale a nCifre allora il
                // PC ha trovato il numero
                cifreIndovinatePC++;
                // Output
                // printf(GREEN "[%d]" RESET, nPersonaVet[i]);
            } else if (valorePresenteInVet(nCifre, numeroDaAggiungere, nPersonaVet)){
                // Carino a livello visivo anche se per ora inutile praticamente, questo verifica
                // se il numero è almeno contenuto nel numero da indovinare, quindi il computer
                // NON conosce la posizione, comunque mette un output visivo per dare pressione
                // all'utente e comunque è parte del gioco.
                // printf(YELLOW "(%d)" RESET, numeroDaAggiungere);
                cifrePCNoPos++;
            }
        }

        for (int i = 0; i < cifreIndovinatePC; i++) {
            printf(GREEN "[]" RESET);
        }

        for (int i = 0; i < cifrePCNoPos; i++) {
            printf(YELLOW "[]" RESET);
        }

        // Chiedo input all'utente per tentare di indovinare il numero
        printf(CYAN "\n\nInserisci un numero: ");
        scanf("%d", &numeroProvatoPersona);
        singoloValVet(nCifre, numeroProvatoPersonaVet, numeroProvatoPersona);

        // Inizia verifica dei valori inseriti dall'utente
        printf("Persona: ");
        // Persona (uso il vecchio metodo di output che va bene)
        for (int i = 0; i < nCifre; i++) {
            for (int j = 0; j < nCifre; j++) {
                if (mioVettore[i] == numeroProvatoPersonaVet[j] && i == j){
                    // printf(GREEN "[%d]" RESET, mioVettore[i]);
                    cifreIndovinatePersona++;
                } else if (mioVettore[i] == numeroProvatoPersonaVet[j]){
                    // printf(YELLOW "(%d)" RESET, mioVettore[i]);
                    cifrePersonaNoPos++;
                }
            }
        }

        for (int i = 0; i < cifreIndovinatePersona; i++) {
            printf(GREEN "[]" RESET);
        }

        for (int i = 0; i < cifrePersonaNoPos; i++) {
            printf(YELLOW "()" RESET);
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

        // Giusto a livello di interfaccia
        printf("\n");
    }

    printf(YELLOW "\n/////////////////////////////" RESET);

    // Messaggio di fine
    printf(RED "\n\nFine del gioco..." RESET);
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

void mostraValori(int dimensioni, int mioVettore[]) {

    // Messaggio d'inizio
    printf("\nI valori sono: \n");

    // Ottengo tutti i valori dell'array in base alle dimensioni dichiarate, si noti che 0 è incluso all'inizio
    for (int i = 0; i < dimensioni; i++) {

        // Scrivo i numeri
        printf("%d-->%d \t",i+1, mioVettore[i]);

    }
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}

