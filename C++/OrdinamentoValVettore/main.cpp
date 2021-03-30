#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

void continua();

long random(long min, long max);
long posizioneAlfabeto(const string &stringaParola, long lettera);
void genSuFileValCasuali(long nNumeri, long max, long min);
unsigned long generatoreParole();

void rimuoviValorePerPosizione(FILE *cfFile, FILE *cfTemp2, long posizione);

unsigned long ordinaVettore1(long nNumeri, long vettoreConNumeri[]);
unsigned long ordinaVettore2(long nNumeri, long vettoreConNumeri[]);

unsigned long ordinaFileNumeri1();
unsigned long ordinaFileNumeri2();
unsigned long ordinamentoFILEParole();


void leggiVettoreConNumeri(long nNumeri, const long *vettoreConNumeri);

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           Ord.Vet. di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Variabili globali e scelta utente.
    int scelta = 1;
    long nNumeri = 100001;
    long vettoreConNumeri[100000];
    bool vettoreGenerato = false;
    long nGenerazioni = 0, nRiordinamenti = 0;
    unsigned long tempiRiordinamento[10000], tempiGenerazioni[10000];

    while (scelta != 0){

        printf("\nLegenda scelte:"
               "\n0 -> Esci."
               "\n1 -> Vettori."
               "\n2 -> Files."
               "\n3 -> Riepilogo."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0:{

                // Messaggio d'uscita.
                printf("\nHai scelto: Esci..."
                       "\n\nUscita in corso...");

                break;
            }

            case 1:{

                // SottoScelta sottomenu.
                int sceltaVettore = 1;

                // Continua fino a quando non viene inserito il valore di uscita.
                while (sceltaVettore != 0){

                    printf("\n\nLegenda vettori: "
                           "\n0 -> Torna indietro."
                           "\n1 -> Generatore vettore di numeri tra Max e Min."
                           "\n2 -> Ordinamento vettore numeri casuali con scambio (piu' efficiente con pochi numeri)."
                           "\n3 -> Ordinamento vettore numeri casuali in base al valore massimo (piu' efficiente con numeri massimi bassi)."
                           "\n4 -> Leggi vettore."
                           "\nScelta: ");
                    scanf("%d", &sceltaVettore);

                    switch (sceltaVettore) {

                        case 0: {

                            // Messaggio di uscita.
                            printf("\nHai scelto: Torna indietro...");

                            break;
                        }

                        case 1:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Genera vettore con numeri...");

                            // Dichiaro variabili e le chiedo in input all'utente.
                            long max, min;
                            printf("\nInserire numero massimo: ");
                            scanf("%ld", &max);

                            printf("\nInserire numero minimo: ");
                            scanf("%ld", &min);

                            while (nNumeri > 100000) {
                                printf("\nInserire numero di numeri da generare (max 100k): ");
                                scanf("%ld", &nNumeri);

                                if (nNumeri > 100000){
                                    printf("\nHai inserito un numero di numeri troppo alto.");
                                } else {
                                    printf("\nNumero di numeri inserito con successo, inizio generazione...");
                                }
                            }

                            // Inizio tempo.
                            clock_t inizio = clock();

                            // Genero valori casuali tra max e min per tutto il vettore.
                            for (long i = 0; i < nNumeri; i++) {
                                vettoreConNumeri[i] = random(min, max);
                            }

                            // Fine tempo.
                            clock_t fine = clock();

                            // Matematica tempo generazione.
                            unsigned long tempoGenerazione = (fine - inizio)/CLOCKS_PER_SEC;

                            // Variabile bandiera per gli altri algoritmi.
                            vettoreGenerato = true;

                            tempiGenerazioni[nGenerazioni] = tempoGenerazione;
                            nGenerazioni++;

                            // Messaggio di esito.
                            printf("\nVettore con numeri casuali generato con successo!"
                                   "\nIl tempo necessario è stato: %ld secondi.", tempoGenerazione);

                            // Pausa.
                            continua();
                            break;
                        }

                        case 2:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: ordinamento numeri in un vettore casuale con scambio...");

                            // Verifico se è stato generato il vettore in precedenza.
                            if (vettoreGenerato) {
                                // Richiamo metodo.
                                tempiRiordinamento[nRiordinamenti] = ordinaVettore1(nNumeri, vettoreConNumeri);
                                nRiordinamenti++;
                            } else {
                                printf("\n\nATTENZIONE! Non puoi eseguire questo algoritmo senza aver generato prima un vettore con i"
                                       "\nNumeri, vedi opzione 7 del menu.");
                            }

                            // Pausa.
                            continua();
                            break;
                        }

                        case 3:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: ordinamento numeri in un vettore casuale in base a numeri massimo...");

                            // Verifico se è stato generato il vettore in precedenza.
                            if (vettoreGenerato) {
                                // Richiamo metodo.
                                tempiRiordinamento[nRiordinamenti] = ordinaVettore2(nNumeri, vettoreConNumeri);
                                nRiordinamenti++;
                            } else {
                                printf("\n\nATTENZIONE! Non puoi eseguire questo algoritmo senza aver generato prima un vettore con i"
                                       "\nNumeri, vedi opzione 7 del menu.");
                            }

                            // Pausa.
                            continua();
                            break;
                        }

                        case 4:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Leggi vettore con numeri...");

                            if (vettoreGenerato) {
                                // Richiamo funzione.
                                printf("\nNumeri: ");
                                leggiVettoreConNumeri(nNumeri, vettoreConNumeri);
                            } else {
                                printf("\nATTENZIONE! Non puoi eseguire questo algoritmo senza aver generato prima un vettore con i"
                                       "\nNumeri, vedi opzione 7 del menu.");
                            }

                            // Pausa.
                            continua();
                            break;
                        }

                        default:{

                            // Messaggio di scelta invalida.
                            printf("\nScelta non valida, per favore riprovare!\n");

                            break;
                        }

                    }

                }

                printf("\n\nTornando indietro..."
                       "\n\nTornato indietro con successo!\n");

                break;
            }

            case 2:{

                // Variabile scelta utente.
                int sceltaFile = 1;

                // Ciclo che continua fino a quando l'input non è quello di uscita.
                while (sceltaFile != 0){

                    // Legenda.
                    printf("\n\nLegenda scelta FILE:"
                           "\n0 -> Torna indietro."
                           "\n1 -> Generazione di un FILE di numeri."
                           "\n2 -> Generazione di un FILE di parole."
                           "\n3 -> Riordinamento FILE di numeri scambiando (piu' efficiente se pochi numeri)."
                           "\n4 -> Riordinamento FILE di numeri in base al valore massimo (piu' efficiente se il numero massimo e' basso)."
                           "\n5 -> Riordinamento FILE di parole in ordine alfabetico."
                           "\n6 -> Lettura FILE di numeri."
                           "\n7 -> Lettura FILE di stringhe."
                           "\nScelta: ");
                    scanf("%d", &sceltaFile);

                    // Switch tra le possibili scelte.
                    switch (sceltaFile) {

                        case 0:{

                            // Messaggio di uscita.
                            printf("\nHai scelto: Torna indietro...");

                            break;
                        }

                        case 1:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Genera FILE con numeri...");

                            // Dichiaro variabili e le chiedo in input all'utente.
                            long max, min, nNumeriFile;
                            printf("\nInserire numero massimo: ");
                            scanf("%ld", &max);

                            printf("\nInserire numero minimo: ");
                            scanf("%ld", &min);

                            printf("\nInserire numero di numeri da generare (max 100k): ");
                            scanf("%ld", &nNumeriFile);

                            // Inizio tempo.
                            clock_t inizio = clock();

                            // Richiamo funzione generazione su FILE.
                            genSuFileValCasuali(nNumeriFile, max, min);

                            // Fine tempo.
                            clock_t fine = clock();

                            // Matematica tempo generazione.
                            unsigned long tempoGenerazione = (fine - inizio)/CLOCKS_PER_SEC;

                            // Messaggio di esito.
                            printf("\nFILE con numeri casuali generato con successo!"
                                   "\nIl tempo necessario e' stato: %ld secondi.", tempoGenerazione);

                            // Aggiungo il tempo al vettore.
                            tempiGenerazioni[nGenerazioni] = tempoGenerazione;
                            nGenerazioni++;

                            // Pausa.
                            continua();
                            break;
                        }

                        case 2:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Generatore FILE di parole.");

                            // Aggiungo il tempo al vettore.
                            tempiGenerazioni[nGenerazioni] = generatoreParole();
                            nGenerazioni++;

                            // Pausa.
                            continua();
                            break;
                        }

                        case 3:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Ordinamento numeri su FILE inefficiente scambiando.");

                            // 404 = Errore lettura FILE, ottiene il tempo che e' stato necessario per riordinare.
                            unsigned long tempoOrdinamento = ordinaFileNumeri2();
                            if (tempoOrdinamento != 404) {
                                tempiRiordinamento[nRiordinamenti] = tempoOrdinamento;
                                nRiordinamenti++;
                            }

                            // Pausa.
                            continua();
                            break;
                        }

                        case 4:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Riordinamento FILE inefficiente per numero massimo.");

                            // 404 = Errore lettura FILE, ottiene il tempo che e' stato necessario per riordinare.
                            unsigned long tempoOrdinamento = ordinaFileNumeri1();
                            if (tempoOrdinamento != 404) {
                                tempiRiordinamento[nRiordinamenti] = tempoOrdinamento;
                                nRiordinamenti++;
                            }

                            // Pausa.
                            continua();
                            break;
                        }

                        case 5:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Ordinamento FILE di parole in ordine alfabetico."
                                   "\n\nAttendere...");

                            // 404 = Errore lettura FILE, ottiene il tempo che e' stato necessario per riordinare.
                            unsigned long tempoOrdinamento = ordinamentoFILEParole();
                            if (tempoOrdinamento != 404) {
                                tempiRiordinamento[nRiordinamenti] = tempoOrdinamento;
                                nRiordinamenti++;
                            }

                            // Pausa.
                            continua();
                            break;
                        }

                        case 6:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Leggi FILE di numeri....");

                            // Apre il file.
                            FILE *cfFile = fopen("file.txt", "r");

                            // Verifica se il FILE esiste.
                            if (cfFile == NULL){
                                printf("\n\nFILE file.txt con numeri non trovato, per favore crearne uno prima di chiamare"
                                       "\nQuesta opzione, puoi farlo sia manualmente che con le opzioni del menu!");
                            } else {
                                // Lettura righe del FILE presumibilmente con numeri.
                                printf("\nNumeri: ");
                                while (!feof(cfFile)) {
                                    long numero;
                                    fscanf(cfFile, "%ld", &numero);
                                    printf("\n%ld", numero);
                                }
                            }

                            // Chiude il FILE.
                            fclose(cfFile);

                            // Pausa.
                            continua();
                            break;
                        }

                        case 7:{

                            printf("\nHai scelto: Leggi FILE di stringhe...");

                            // Apre il file.
                            FILE *cfFile = fopen("fileParole.txt", "r");

                            // Verifica se il FILE esiste.
                            if (cfFile == NULL){
                                printf("\n\nFILE fileParole.txt con numeri non trovato, per favore crearne uno prima di chiamare"
                                       "\nQuesta opzione, puoi farlo sia manualmente che con le opzioni del menu!");
                            } else {
                                // Lettura righe del FILE presumibilmente con numeri.
                                printf("\nParole: ");
                                while (!feof(cfFile)) {
                                    char parola[1000];
                                    fscanf(cfFile, "%s", parola);
                                    printf("\n%s", parola);
                                }
                            }

                            // Chiude il FILE.
                            fclose(cfFile);

                            // Pausa.
                            continua();
                            break;
                        }

                        default:{

                            // Messaggio di scelta invalida.
                            printf("\nScelta non valida, per favore riprovare!\n");

                            break;
                        }

                    }
                }

                // Messaggio azione indietro.
                printf("\n\nTornando indietro..."
                       "\n\nTornato indietro con successo!\n");

            }

            case 3:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Riepilogo tempi...");
                printf("\n\n|--------------------------"
                       "\n| Riepilogo: ");

                // Verifica se ci sono riepiloghi di generazione.
                if (nGenerazioni == 0){
                    printf("\n|\n| Non ci sono tempi di generazione da mostrare.");
                } else {

                    // Mostra i valori memorizzati e ne fa anche una media.
                    unsigned long tempoTotale = 0;
                    printf("\n|\n| Tempi di generazione (in secondi): ");
                    for (long i = 0; i < nGenerazioni; i++) {
                        printf("\n| Generazione n.%ld -> %ld", i + 1, tempiGenerazioni[i]);
                        tempoTotale += tempiGenerazioni[i];
                    }
                    printf("\n| Media del tempo di generazione: %ld", tempoTotale / nGenerazioni);

                }

                // Verifica se ci sono tempi di riordinamento salvati.
                if (nRiordinamenti == 0){
                    printf("\n|\n| Non ci sono rempi di riordinamento da mostrare.");
                } else {

                    // Mostra tutti i valori e ne fa anche una media.
                    unsigned long tempoTotale = 0;
                    printf("\n|\n| Tempi di riordinamento: ");
                    for (long i = 0; i < nRiordinamenti; i++) {
                        printf("\n| Riordinamento n.%ld -> %ld", i + 1, tempiRiordinamento[i]);
                        tempoTotale += tempiRiordinamento[i];
                    }
                    printf("\n| Media del tempo di riordinamento: %ld", tempoTotale / nRiordinamenti);

                }

                // Messaggio di fine operazione.
                printf("\n|\n| FINE STATISTICHE/RIEPILOGO!"
                       "\n|--------------------------");

                // Pausa.
                continua();
                break;
            }

            default:{

                // Messaggio di scelta invalida.
                printf("\nScelta non valida, per favore riprovare!\n");

                break;
            }
        }
    }

    // Messaggio d'uscita.
    printf("\nUscito con successo!");
    return 0;
}

unsigned long generatoreParole() {

    // Chiedo dati in ingresso all'utente.
    long numeroLettere;
    printf("\nInserire numero lettere: ");
    scanf("%ld", &numeroLettere);

    long numeroParole;
    printf("\nInserire numero parole: ");
    scanf("%ld", &numeroParole);

    // Creo FILE.
    FILE *fileParole = fopen("fileParole.txt", "w");
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    string alfabetoMaiuscolo = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Casualita'.
    srand(time(0));

    // Inzio tempo.
    clock_t inizio = clock();

    // Genero le parole, lettera per lettera.
    for (long i = 0; i < numeroParole; i++) {

        string parola;
        for (long j = 0; j < numeroLettere; ++j) {
            int maiuscoloOMinuscolo = random(0,1);
            int numeroAlfabeto = random(0, 25);

            // 1 Minuscolo, 0 Maiuscolo.
            if (maiuscoloOMinuscolo == 1){

                parola += alfabeto[numeroAlfabeto];

            } else if (maiuscoloOMinuscolo == 0){

                parola += alfabetoMaiuscolo[numeroAlfabeto];

            }
        }

        // Salvo parola su FILE.
        if (i != 0){
            fprintf(fileParole, "%s", "\n");
        }
        fprintf(fileParole, "%s", parola.c_str());
    }
    fclose(fileParole);

    // Fine tempo.
    clock_t fine = clock();

    // Tempo necessario al riordinamento.
    unsigned long tempoGenerazione = (fine - inizio)/CLOCKS_PER_SEC;

    // Messaggio di risultato.
    printf("\nGenerato FILE con successo in %ld! Nome: fileParole.txt..."
           "\nUsalo per l'algoritmo 5 dell'ordinamento alfabetico per esempio.\n", tempoGenerazione);

    return tempoGenerazione;
}

unsigned long ordinamentoFILEParole() {

    // Variabili e inizio tempo.
    clock_t inizio = clock();
    long numeroParole = 0;

    // Apre file con le parole da riordinare.
    FILE *fileParole = fopen("fileParole.txt", "r");

    // Verifica se il file esiste prima di eseguire l'algorimto.
    if (fileParole == NULL){
        printf("\nErrore durante la lettura del FILE."
               "\nSe non esiste, crearne uno con il nome:"
               "\n - fileTesto.txt "
               "\ne inserire una parola per riga.");
    } else {

        // Trova parola piu' corta per evitare errori.
        long lunghezzaParolaCorta = 1000;
        while (!feof(fileParole)) {
            char parolaLetta[100];
            fscanf(fileParole, "%s", parolaLetta);
            string parolaLettaFin = parolaLetta;
            if (parolaLettaFin.size() < lunghezzaParolaCorta) {
                lunghezzaParolaCorta = parolaLettaFin.size();
            }
            numeroParole++;
        }
        fclose(fileParole);

        // Ripete il ciclo dall'ultima lettera per riordinare non solo secondo la prima.
        long n = 0;
        printf("\n\nLunghezza parola piu' corta: %ld"
               "\nSara' usata come riferimento per la"
               "\nprecisione dell'ordine alfabetico", lunghezzaParolaCorta);

        // Commentare il ciclo FOR in caso di problemi, il valore n = 0 di default sara' usato.
        for (n = lunghezzaParolaCorta - 1; n >= 0; n--) {
            // Conto quante righe sono contenute nel file.
            fileParole = fopen("fileParole.txt", "r");
            long numeroRighe = 0;
            while (!feof(fileParole)) {
                numeroRighe++;
                char parolaProva[100];
                fscanf(fileParole, "%s", parolaProva);
            }
            fclose(fileParole);

            // Apro il file e creo un ciclo.
            FILE *fileTemp = fopen("fileTemp.txt", "w");
            long numeroRigheScritte = 0;
            for (int i = 0; i < numeroRighe; i++) {
                fileParole = fopen("fileParole.txt", "r");

                long parolaMinoreFin = 100000000; // Valore minore globale.
                long posizioneRiga = 0; // NON USARE.
                long posizioneRigaFinale; // USARE PER ELIMINARE.
                string stringaParolaFinale;

                // Trova parola minore.
                while (!feof(fileParole)) {
                    string stringaParola;
                    posizioneRiga++;

                    // Leggi dal FILE la stringa.
                    char parola[100];
                    fscanf(fileParole, "%s", parola);
                    stringaParola = parola;

                    // Trovo posizione nell'alfabeto.
                    long parolaMinorePos = posizioneAlfabeto(stringaParola, n);

                    // Se e' minore di quelle trovate in precedenza sostituisce i dati.
                    if (parolaMinorePos < parolaMinoreFin) {
                        parolaMinoreFin = parolaMinorePos;
                        posizioneRigaFinale = posizioneRiga;
                        stringaParolaFinale = stringaParola;
                    }
                }

                // Scrivi parola minore nel file temporaneo che alla fine sara' rinominato con il nome
                // Originale.
                if (numeroRigheScritte != 0) {
                    fprintf(fileTemp, "%s", "\n");
                }
                fprintf(fileTemp, "%s", stringaParolaFinale.c_str());
                numeroRigheScritte++;
                fclose(fileParole);

                // Ricopio il file senza il valore minore.
                fileParole = fopen("fileParole.txt", "r");
                FILE *cfTemp2 = fopen("fileTemp2.txt", "w");
                long rigaArrivato = 0;
                while (!feof(fileParole)) {
                    rigaArrivato++;
                    char riga[100];
                    fscanf(fileParole, "%s", riga);
                    if (rigaArrivato != posizioneRigaFinale) {
                        if (rigaArrivato != 1) {
                            fprintf(cfTemp2, "%s", "\n");
                        }
                        fprintf(cfTemp2, "%s", riga);
                    }
                }
                fclose(fileParole);
                fclose(cfTemp2);
                remove("fileParole.txt");
                rename("fileTemp2.txt", "fileParole.txt");
            }
            fclose(fileTemp);
            remove("fileParole.txt");
            rename("fileTemp.txt", "fileParole.txt");
        }
    }

    clock_t fine = clock();

    // Tempo necessario al riordinamento.
    unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

    // Messaggio di fine e risultati.
    printf("\n\nCompletato con successo!"
           "\nTempo necessario per riordinare le parole su FILE: %ld secondi."
           "\nSono state ordinate %ld parole!", tempoRiordinamento, numeroParole);

    return tempoRiordinamento;
}

unsigned long ordinaFileNumeri2() {

    // Apre il FILE.
    FILE *cfFile = fopen("file.txt", "r");

    // Verifica se il FILE esiste.
    if (cfFile == NULL){
        printf("\nIl file file.txt non esiste, per favore crearne uno prima di eseguire questa opzione, puoi"
               "\nfarlo anche con le opzioni del menu!");
        return 404;
    }

    // Trova numero maggiore e minore nel FILE.
    long max = 0, min = 999999, nNumeri = 0;
    while (!feof(cfFile)){

        // Legge il numero dal FILE.
        long numero;
        fscanf(cfFile, "%ld", &numero);

        // Trova il numero maggiore.
        if (numero > max){
            max = numero;
        }

        // Trova il numero minore.
        if (numero < min){
            min = numero;
        }

        nNumeri++;
    }
    fclose(cfFile);

    clock_t inizio = clock();
    // Creo file temporanei vuoti.
    FILE *cfTemp = fopen("fileTemp.txt", "w");
    FILE *cfTemp2 = fopen("fileTemp2.txt", "w");
    fclose(cfTemp);
    fclose(cfTemp2);
    for (long i = 0; i < nNumeri; i++) {

        // Apro il file in modalita' lettura.
        cfFile = fopen("file.txt", "r");
        // Inizializzo variabili per numero minore trovato e posizione.
        long numeroMinore = max;
        long posizione = 0;
        long posTemp = 0;
        // Cerco valore minore nel FILE.
        while (!feof(cfFile)){
            posTemp++;
            long numeroTemp;
            fscanf(cfFile, "%ld", &numeroTemp);
            if (numeroTemp < numeroMinore){
                posizione = posTemp;
                numeroMinore = numeroTemp;
            }
        }
        fclose(cfFile);

        // Aggiungo valore.
        cfTemp = fopen("fileTemp.txt", "a");
        if (i != 0){
            fprintf(cfTemp, "%s", "\n");
        }
        fprintf(cfTemp, "%ld", numeroMinore);
        fclose(cfTemp);

        // Ricopio il file senza il valore minore.
        cfFile = fopen("file.txt", "r");
        cfTemp2 = fopen("fileTemp2.txt", "w");
        rimuoviValorePerPosizione(cfFile, cfTemp2, posizione);
    }

    // Cancella vecchio file e rinomino temporaneo in finale.
    remove("file.txt");
    rename("fileTemp.txt", "file.txt");
    clock_t fine = clock();

    // Lettura FILE finale.
    cfFile = fopen("file.txt", "r");

    // Tempo necessario al riordinamento.
    unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

    // Messaggi di esito.
    printf("\n\nTempo necessario per riordinare i numeri su FILE: %ld secondi.", tempoRiordinamento);

    return tempoRiordinamento;
}

unsigned long ordinaFileNumeri1() {

    // Apre il FILE.
    FILE *cfFile = fopen("file.txt", "r");

    // Verifica se il FILE esiste.
    if (cfFile == NULL){
        printf("\nIl file file.txt non esiste, per favore crearne uno prima di eseguire questa opzione, puoi"
               "\nfarlo anche con le opzioni del menu!");
        return 404;
    }

    // Trova numero maggiore e minore nel FILE.
    long max = 0, min = 999999;
    while (!feof(cfFile)){

        // Legge il numero dal FILE.
        long numero;
        fscanf(cfFile, "%ld", &numero);

        // Trova il numero maggiore.
        if (numero > max){
            max = numero;
        }

        // Trova il numero minore.
        if (numero < min){
            min = numero;
        }
    }
    fclose(cfFile);

    // Scrittura.
    FILE *cfTemp;
    cfTemp = fopen("fileTemp.txt", "w");

    // Inizio tempo.
    clock_t inizio = clock();

    // Riordinamento.
    long contatore = 0;
    for(long i = min; i <= max; i++){

        // Letttura.
        // rewind(cfFile);
        cfFile = fopen("file.txt", "r");
        while (!feof(cfFile)){

            long numero;
            fscanf(cfFile, "%ld", &numero);
            if(numero == i){
                if (contatore != 0){
                    fprintf(cfTemp, "%s", "\n");
                }
                fprintf(cfTemp, "%ld", numero);
                contatore++;
            }
        }
        fclose(cfFile);
    }
    fclose(cfTemp);

    // Fine tempo.
    clock_t fine = clock();

    // Tempo necessario al riordinamento.
    unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

    // Cancella vecchio FILE e rinomina quello nuovo per sostituirlo.
    remove("file.txt");
    rename("fileTemp.txt", "file.txt");

    printf("\nOrdinamento su FILE temporaneo effettuato con successo!");
    printf("\n\nTempo necessario per riordinare i numeri su FILE: %ld secondi.", tempoRiordinamento);
    printf("\nFine programma...");

    return tempoRiordinamento;
}

unsigned long ordinaVettore2(long nNumeri, long vettoreConNumeri[]) {

    // Trova numero maggiore e minore nel vettore.
    long max = 0, min = 999999;
    for (int i = 0; i < nNumeri; i++) {

        // Trova maggiore
        if (max < vettoreConNumeri[i]){
            max = vettoreConNumeri[i];
        }

        // Trova minore.
        if (min > vettoreConNumeri[i]){
            min = vettoreConNumeri[i];
        }
    }

    // Inizio tempo.
    clock_t inizio = clock();

    // Vettore temporaneo di appoggio e variabili, ordinamento valori.
    long vettoreNuovo[nNumeri];
    long contatore = 0;
    for(long i = min; i <= max; i++){

        for(long j = 0; j < nNumeri; j++){

            if(vettoreConNumeri[j] == i){

                // Assegna il valore al vettore di appoggio.
                vettoreNuovo[contatore] = vettoreConNumeri[j];
                contatore++;
            }
        }
    }

    // Ricopio i numeri del vettore di appoggio nell'originale
    for (long i = 0; i < nNumeri; i++) {
        vettoreConNumeri[i] = vettoreNuovo[i];
    }

    // Fine tempo.
    clock_t fine = clock();

    // Tempo di fine.
    unsigned long risultatoOrdinamentoNumeri = (fine - inizio)/CLOCKS_PER_SEC;

    // leggiVettoreConNumeri(nNumeri, vettoreConNumeri);

    // Messaggio di esito.
    cout << "\n\nCompletato con successo!"
            "\nSono stati necessari: " << risultatoOrdinamentoNumeri << " secondi per riordinare i numeri!"
         << endl;

    return risultatoOrdinamentoNumeri;
}

void leggiVettoreConNumeri(long nNumeri, const long *vettoreConNumeri) {

    // Leggo tutti i valori in ordine del nuovo vettore.
    for (long i = 0; i < nNumeri; i++) {
        printf("\n%ld -> %ld", i + 1, vettoreConNumeri[i]);
    }
}

unsigned long ordinaVettore1(long nNumeri, long vettoreConNumeri[]) {

    clock_t inizio = clock();

    // Faccio un ciclo per l'intero vettore, ogni valore sara' spostato nella nuova posizione.
    long vecchioNumero;
    for (long i = 0; i < nNumeri; i++) {

        // Faccio un ciclo per tutto il vettore a partire dal valore successivo alla posizione di assegnamento.
        for (long j = i + 1; j < nNumeri; j++) {

            // Verifico se il numero che sto verificando e' maggiore di quello attualmente presente.
            if (vettoreConNumeri[i] > vettoreConNumeri[j]) {

                // Scambio i valori appoggiandomi ad una variabile temporanea.
                vecchioNumero = vettoreConNumeri[i];
                vettoreConNumeri[i] = vettoreConNumeri[j];
                vettoreConNumeri[j] = vecchioNumero;
            }
        }
    }

    clock_t fine = clock();

    // Tempo di fine.
    unsigned long risultatoOrdinamentoNumeri = (fine - inizio)/CLOCKS_PER_SEC;

    // Messaggio con i risultati di fine.
    cout << "\n\nCompletato con successo!"
            "\nSono stati necessari: " << risultatoOrdinamentoNumeri << " secondi per riordinare i numeri!"
         << endl;

    return risultatoOrdinamentoNumeri;
}

void rimuoviValorePerPosizione(FILE *cfFile, FILE *cfTemp2, long posizione) {

    // Cerca la stringa per posizione e la cancella.
    long rigaArrivato = 0;
    while (!feof(cfFile)){
        rigaArrivato++;
        long numero;
        fscanf(cfFile, "%ld", &numero);
        if (rigaArrivato != posizione){
            if (rigaArrivato != 1){
                fprintf(cfTemp2, "%s", "\n");
            }
            fprintf(cfTemp2, "%ld", numero);
        }
    }
    fclose(cfFile);
    fclose(cfTemp2);
    remove("file.txt");
    rename("fileTemp2.txt", "file.txt");
}

long posizioneAlfabeto(const string &stringaParola, long lettera) {

    // Dichiaro alfabeto maiuscolo e miniscolo.
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    string alfabetoMaiuscolo = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    long parolaMinorePos;
    long numeroPosizione = 0;
    for (long k = 0; k < alfabeto.size(); k++) {
        if ((stringaParola[lettera] == alfabeto[k]) || (stringaParola[lettera] == alfabetoMaiuscolo[k])){
            parolaMinorePos = numeroPosizione;
        }
        numeroPosizione++;
    }
    return parolaMinorePos;
}

void genSuFileValCasuali(long nNumeri, long max, long min) {

    FILE *cfFile = fopen("file.txt", "w");

    if (cfFile == NULL){
        printf("\nErrore durante la creazione del file!");
    } else {
        for (long i = 0; i < nNumeri; i++) {
            if (i != 0){
                fprintf(cfFile, "%s", "\n");
            }
            long numeroCasuale = random(min, max);
            fprintf(cfFile, "%ld", numeroCasuale);
        }
        printf("\nCreazione FILE Con valori casuali effettuata con successo!");
    }

    fclose(cfFile);
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}

long random(long min, long max){
    long randomMN1 = max - min + 1 ;
    return ((long) rand() % randomMN1 + min);
}