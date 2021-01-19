#include <iostream>
#include <stdlib.h>
#include <ctime>

void continua();
void mostraValori(int dimensioni, int mioVettore[]);
void singoloValVet(int dimensioni, int mioVettore[], int numeroGeneratoVar);
bool valorePresenteInVet(int dimensioni, int numeroDaTrovare , const int vettore[]);
void genValDivInVet1(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate);
int trovaValori(int dimensioni, int mioVettore[]);
void rimuoviPerPos(int dimensioni, int mioVettore[], int valore);

void nuovoMasterMind(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate, int nTentativi);
void masterMindPerVSPC2(int mioVettore[], int max, int min, int nCifre, int nCifreGenerate);
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
               "\n     numero di tentativi."
               "\n3 -> MasterMind persone VS computer 2.0."
               "\n4 -> Generatore valori diversi."
               "\n5 -> MasterMind computer 3.0."
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

                // Messaggio d'inizio
                printf("\nHai scelto: modalità 3 2.0...\n");

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
            case 4:{

                printf("\nHai scelto: genera valori in un vettore che non si ripetano...\n");

                // Richiama funzione nuovo algoritmo migliorato
                trovaValori(dimensioni, mioVettore);

                continua();
                break;
            }
            case 5:{

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
    }
    return 0;
}

void MasterMindPCV3(int max, int min, int dimensioni, int mioVettore[], int nCifre, int nTentativi) {

    // Dichiaro variabili
    int nValSbagliati = 0, vetValSbagliati[6] = {10}, vinto = 0, nPersona, nPersonaVar, nPersonaVet[4] = {10}, nUniciProvati = 0, vetUniciProvati[100], vuoleListaVal = 0;
    nTentativi = 0;

    // Chiedo se vuole vedere i valori possibili aggiornati.
    printf("\nVuoi vedere i valori aggiornati possibili (una lista)..."
           "\nNOTA: Può creare problemi con alcuni valori, modifica l'algoritmo per indovinare il numero:"
           "\n0 -> No."
           "\n1 -> Si."
           "\nScelta: ");
    scanf("%d", &vuoleListaVal);

    // Chiedo in input all'utente il numero da indovinare
    printf("\n\nInserisci il numero che dovrà indovinare il pc: ");
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

        printf("\n\n\nPer favore attendere...");

        // Rimuove dalla lista dei valori possibili quelli non possibili
        if (vuoleListaVal == 1) {
            for (int i = 0; i < dimensioni; i++) {

                int singoliValVetDim[nCifre];
                singoloValVet(nCifre, singoliValVetDim, mioVettore[i]);

                for (int j = 0; j < nValSbagliati; j++) {
                    if (valorePresenteInVet(nCifre, vetValSbagliati[nValSbagliati], singoliValVetDim)) {
                        rimuoviPerPos(dimensioni, mioVettore, i);
                        dimensioni--;
                    }
                }
            }

            // Messaggio e richiamo funzioni per mostrare i valori
            printf("\n\nLe possibilità si sono ridotte alle seguenti: ");
            mostraValori(dimensioni, mioVettore);
        }

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
                if (vuoleListaVal == 1) {
                    for (int i = 0; i < dimensioni; i++) {
                        if (valUnico == mioVettore[i] && contenuto == 0) {
                            contenuto++;
                        }
                    }
                }

                // Se entrambi le variabili sono uguali a 0, allora incrementa valValido che fa ripetere il while
                if ((contenuto == 0 && vuoleListaVal == 1) && valValido == 0) {
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
        printf("\n\nNumeri PC:");
        for (int i = 0; i < numeriTrovati; i++) {
            printf("[]");
        }
        for (int i = 0; i < numeriTrovatiNoPos; ++i) {
            printf("()");
        }

        // Se sono stati trovati 4 numeri validi nella posizione corretta, incrementa vinto ed esce dal while, finendo il gioco.
        if (numeriTrovati == 4){
            vinto++;
        }
    }

    // Fine
    printf("\n\nAlgoritmo finito, il numero dell'utente era %d."
           "\nSono stati necessari %d tentativi!", nPersona, nTentativi);
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
    printf("\nSono stati generati i valori con successo!\n");

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
    printf("\nGenerato con successo un numero con %d cifre! Inizia il gioco...\n", nCifre);

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
        }

        // Incremento il numero dei turni passati
        nTurno++;

        // Comunica il numero del turno
        printf("\n///////////////////////////// \n"
               "\nQuesto è il %d° turno...\n", nTurno);

        // Messaggio che comunica output PC man mano mentre esegue la strategia
        printf("\nPC: ");

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

            // Strategia del computer
            // Verifica se il valore provato è uguale e nella stessa posizione, quindi quadrato in output di solito
            if (numeroDaAggiungere == nPersonaVet[i]){
                // Setta a 1 il valore nel vettore per comunicare che in questa posizione il numero è corretto
                // e nella posizione giusta, quindi non è da modificare in futuro.
                vetPCCorPos[i] = 1;
                cifreIndovinatePC++;
            } else if (valorePresenteInVet(nCifre, numeroDaAggiungere, nPersonaVet)){
                cifrePCNoPos++;
            }
        }

        for (int i = 0; i < cifreIndovinatePC; i++) {
            printf("[]");
        }

        for (int i = 0; i < cifrePCNoPos; i++) {
            printf("[]");
        }

        // Chiedo input all'utente per tentare di indovinare il numero
        printf("\n\nInserisci un numero: ");
        scanf("%d", &numeroProvatoPersona);
        singoloValVet(nCifre, numeroProvatoPersonaVet, numeroProvatoPersona);

        // Inizia verifica dei valori inseriti dall'utente
        printf("Persona: ");
        // Persona (uso il vecchio metodo di output che va bene)
        for (int i = 0; i < nCifre; i++) {
            for (int j = 0; j < nCifre; j++) {
                if (mioVettore[i] == numeroProvatoPersonaVet[j] && i == j){
                    cifreIndovinatePersona++;
                } else if (mioVettore[i] == numeroProvatoPersonaVet[j]){
                    cifrePersonaNoPos++;
                }
            }
        }

        for (int i = 0; i < cifreIndovinatePersona; i++) {
            printf("[]");
        }

        for (int i = 0; i < cifrePersonaNoPos; i++) {
            printf("()");
        }

        // Qualcuno ha vinto? Oppure hanno vinto entrambi?
        if (cifreIndovinatePC == cifreIndovinatePersona && cifreIndovinatePC == nCifre){
            printf("\n\nComplimenti! Te e il PC avete finito nello stesso turno! Pareggio!"
                   "\nIl tuo numero era: %d"
                   "\nIl numero del PC era: %d", nPersona, numeroProvatoPersona);
            finito++;
        } else if (cifreIndovinatePC == nCifre){
            printf("\n\nHai perso! Ha vinto il computer!"
                   "\nIl tuo numero era %d", nPersona);
            finito++;
        } else if (cifreIndovinatePersona == nCifre){
            printf("\n\nHai vinto e battuto il computer! Il numero %d è corretto!" , numeroProvatoPersona);
            finito++;
        }

        // Giusto a livello di interfaccia
        printf("\n");
    }

    printf("\n/////////////////////////////");

    // Messaggio di fine
    printf("\n\nFine del gioco...");
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

