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
           "\n//           Ord.Vet. di G.C. 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Variabili globali e scelta utente.
    int scelta = 1;
    long nNumeri = 100001;
    long vettoreConNumeri[100000];
    bool vettoreGenerato = false;
    long nGenerazioni = 0, nRiordinamenti = 0;
    unsigned long tempiRiordinamento[10000], tempiGenerazioni[10000];

    while (scelta != 0){

        printf("\n|--------------------------"
               "\n| Legenda scelte:"
               "\n| 0 -> Esci."
               "\n| 1 -> Vettori."
               "\n| 2 -> Files."
               "\n| 3 -> Riepilogo."
               "\n| Scelta: ");
        scanf("%d", &scelta);
        printf("|--------------------------\n");

        switch (scelta) {
            case 0:{

                // Messaggio d'uscita.
                printf("\n|--------------------------"
                       "\n| Hai scelto: Esci..."
                       "\n|--------------------------"
                       "\n\n|--------------------------"
                       "\n| Uscita in corso...");

                break;
            }

            case 1:{

                // SottoScelta sottomenu.
                int sceltaVettore = 1;

                // Continua fino a quando non viene inserito il valore di uscita.
                while (sceltaVettore != 0){

                    printf("\n\n|--------------------------"
                           "\n| Legenda vettori: "
                           "\n| 0 -> Torna indietro."
                           "\n| 1 -> Generatore vettore di numeri tra Max e Min."
                           "\n| 2 -> Ordinamento vettore numeri casuali con scambio (piu' efficiente con pochi numeri)."
                           "\n| 3 -> Ordinamento vettore numeri casuali in base al valore massimo (piu' efficiente con numeri massimi bassi)."
                           "\n| 4 -> Leggi vettore."
                           "\n| Scelta: ");
                    scanf("%d", &sceltaVettore);
                    printf("|--------------------------\n");

                    switch (sceltaVettore) {

                        case 0: {

                            // Messaggio di uscita.
                            printf("\n|--------------------------"
                                   "\n| Hai scelto: Torna indietro..."
                                   "\n|--------------------------");

                            break;
                        }

                        case 1:{

                            // Messaggio d'inizio.
                            printf("\n|--------------------------"
                                   "\n| Hai scelto: Genera vettore con numeri..."
                                   "\n|--------------------------");

                            // Dichiaro variabili e le chiedo in input all'utente.
                            long max, min;
                            printf("\n| Inserire numero massimo: ");
                            scanf("%ld", &max);

                            printf("| Inserire numero minimo: ");
                            scanf("%ld", &min);

                            nNumeri = 100001;
                            while (nNumeri > 100000) {
                                printf("| Inserire numero di numeri da generare (max 100k): ");
                                scanf("%ld", &nNumeri);

                                if (nNumeri > 100000){
                                    printf("| Hai inserito un numero di numeri troppo alto.");
                                } else {
                                    printf("| Numero di numeri inserito con successo, inizio generazione/attendere...");
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
                            printf("\n| Vettore con numeri casuali generato con successo!"
                                   "\n| Il tempo necessario e' stato: %ld secondi."
                                   "\n|--------------------------", tempoGenerazione);

                            // Pausa.
                            continua();
                            break;
                        }

                        case 2:{

                            // Messaggio d'inizio.
                            printf("\n|--------------------------"
                                   "\n| Hai scelto: ordinamento numeri in un vettore casuale con scambio..."
                                   "\n|--------------------------");

                            // Verifico se e' stato generato il vettore in precedenza.
                            if (vettoreGenerato) {
                                // Richiamo metodo.
                                tempiRiordinamento[nRiordinamenti] = ordinaVettore1(nNumeri, vettoreConNumeri);
                                nRiordinamenti++;
                            } else {
                                printf("\n|\n| ATTENZIONE! Non puoi eseguire questo algoritmo senza aver generato prima un vettore con i"
                                       "\n| Numeri, vedi opzione 1 del menu."
                                       "\n|--------------------------");
                            }

                            // Pausa.
                            continua();
                            break;
                        }

                        case 3:{

                            // Messaggio d'inizio.
                            printf("\n|--------------------------"
                                   "\n| Hai scelto: ordinamento numeri in un vettore casuale in base a numeri massimo..."
                                   "\n|--------------------------");

                            // Verifico se e' stato generato il vettore in precedenza.
                            if (vettoreGenerato) {
                                // Richiamo metodo.
                                tempiRiordinamento[nRiordinamenti] = ordinaVettore2(nNumeri, vettoreConNumeri);
                                nRiordinamenti++;
                            } else {
                                printf("\n| \n| ATTENZIONE! Non puoi eseguire questo algoritmo senza aver generato prima un vettore con i"
                                       "\n| Numeri, vedi opzione 1 del menu."
                                       "\n|--------------------------");
                            }

                            // Pausa.
                            continua();
                            break;
                        }

                        case 4:{

                            // Messaggio d'inizio.
                            printf("\n|--------------------------"
                                   "\n| Hai scelto: Leggi vettore con numeri..."
                                   "\n|--------------------------");

                            if (vettoreGenerato) {
                                // Richiamo funzione.
                                printf("\n| Numeri: ");
                                leggiVettoreConNumeri(nNumeri, vettoreConNumeri);
                            } else {
                                printf("\n| ATTENZIONE! Non puoi eseguire questo algoritmo senza aver generato prima un vettore con i"
                                       "\n| Numeri, vedi opzione 1 del menu."
                                       "\n|--------------------------");
                            }

                            // Pausa.
                            continua();
                            break;
                        }

                        default:{

                            // Messaggio di scelta invalida.
                            printf("\n| Scelta non valida, per favore riprovare!"
                                   "\n|--------------------------\n");

                            break;
                        }

                    }

                }

                printf("\n\n|--------------------------"
                       "\n| Tornando indietro..."
                       "\n| \n| Tornato indietro con successo!"
                       "\n|--------------------------\n");

                break;
            }

            case 2:{

                // Variabile scelta utente.
                int sceltaFile = 1;

                // Ciclo che continua fino a quando l'input non e' quello di uscita.
                while (sceltaFile != 0){

                    // Legenda.
                    printf("\n\n|--------------------------"
                           "\n| Legenda scelta FILE:"
                           "\n| 0 -> Torna indietro."
                           "\n| 1 -> Generazione di un FILE di numeri."
                           "\n| 2 -> Generazione di un FILE di parole."
                           "\n| 3 -> Riordinamento FILE di numeri scambiando (piu' efficiente se pochi numeri)."
                           "\n| 4 -> Riordinamento FILE di numeri in base al valore massimo (piu' efficiente se il numero massimo e' basso)."
                           "\n| 5 -> Riordinamento FILE di parole in ordine alfabetico."
                           "\n| 6 -> Lettura FILE di numeri."
                           "\n| 7 -> Lettura FILE di stringhe."
                           "\n| Scelta: ");
                    scanf("%d", &sceltaFile);
                    printf("|--------------------------\n");

                    // Switch tra le possibili scelte.
                    switch (sceltaFile) {

                        case 0:{

                            // Messaggio di uscita.
                            printf("\n|--------------------------"
                                   "\n| Hai scelto: Torna indietro..."
                                   "\n|--------------------------");

                            break;
                        }

                        case 1:{

                            // Messaggio d'inizio.
                            printf("\n|--------------------------"
                                   "\n| Hai scelto: Genera FILE con numeri..."
                                   "\n|--------------------------");

                            // Dichiaro variabili e le chiedo in input all'utente.
                            long max, min, nNumeriFile;
                            printf("\n| Inserire numero massimo: ");
                            scanf("%ld", &max);

                            printf("| Inserire numero minimo: ");
                            scanf("%ld", &min);

                            printf("| Inserire numero di numeri da generare (max 100k): ");
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
                            printf("\n\n|--------------------------"
                                   "\n| FILE con numeri casuali generato con successo!"
                                   "\n| Il tempo necessario e' stato: %ld secondi."
                                   "\n|--------------------------", tempoGenerazione);

                            // Aggiungo il tempo al vettore.
                            tempiGenerazioni[nGenerazioni] = tempoGenerazione;
                            nGenerazioni++;

                            // Pausa.
                            continua();
                            break;
                        }

                        case 2:{

                            // Messaggio d'inizio.
                            printf("\n|--------------------------"
                                   "\n| Hai scelto: Generatore FILE di parole..."
                                   "\n|--------------------------");

                            // Aggiungo il tempo al vettore.
                            tempiGenerazioni[nGenerazioni] = generatoreParole();
                            nGenerazioni++;

                            // Pausa.
                            continua();
                            break;
                        }

                        case 3:{

                            // Messaggio d'inizio.
                            printf("\n|--------------------------"
                                   "\n| Hai scelto: Ordinamento numeri su FILE inefficiente scambiando..."
                                   "\n|--------------------------");

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
                            printf("\n|--------------------------"
                                   "\n| Hai scelto: Riordinamento FILE inefficiente per numero massimo..."
                                   "\n|--------------------------");

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
                            printf("\n|--------------------------"
                                   "\n| Hai scelto: Ordinamento FILE di parole in ordine alfabetico."
                                   "\n|--------------------------"
                                   "\n| \n| Attendere...");

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
                            printf("\n|--------------------------"
                                   "\n| Hai scelto: Leggi FILE di numeri..."
                                   "\n|--------------------------");

                            // Apre il file.
                            FILE *cfFile = fopen("file.txt", "r");

                            // Verifica se il FILE esiste.
                            if (cfFile == NULL){
                                printf("\n| \n| FILE file.txt con numeri non trovato, per favore crearne uno prima di chiamare"
                                       "\n| Questa opzione, puoi farlo sia manualmente che con le opzioni del menu!"
                                       "\n|--------------------------");
                            } else {
                                // Lettura righe del FILE presumibilmente con numeri.
                                printf("\n| Numeri: ");
                                while (!feof(cfFile)) {
                                    long numero;
                                    fscanf(cfFile, "%ld", &numero);
                                    printf("\n| - %ld", numero);
                                }
                            }
                            printf("\n|--------------------------");

                            // Chiude il FILE.
                            fclose(cfFile);

                            // Pausa.
                            continua();
                            break;
                        }

                        case 7:{

                            printf("\n|--------------------------"
                                   "\n| Hai scelto: Leggi FILE di stringhe..."
                                   "\n|--------------------------");

                            // Apre il file.
                            FILE *cfFile = fopen("fileParole.txt", "r");

                            // Verifica se il FILE esiste.
                            if (cfFile == NULL){
                                printf("\n\n| FILE fileParole.txt con numeri non trovato, per favore crearne uno prima di chiamare"
                                       "\n| Questa opzione, puoi farlo sia manualmente che con le opzioni del menu!"
                                       "\n|--------------------------");
                            } else {
                                // Lettura righe del FILE presumibilmente con numeri.
                                printf("\n| Parole: ");
                                while (!feof(cfFile)) {
                                    char parola[250];
                                    fscanf(cfFile, "%s", parola);
                                    printf("\n| - %s", parola);
                                }
                            }

                            printf("\n|--------------------------");

                            // Chiude il FILE.
                            fclose(cfFile);

                            // Pausa.
                            continua();
                            break;
                        }

                        default:{

                            // Messaggio di scelta invalida.
                            printf("\n|--------------------------"
                                   "\n| Scelta non valida, per favore riprovare!"
                                   "\n|--------------------------\n");

                            break;
                        }

                    }
                }

                // Messaggio azione indietro.
                printf("\n\n|--------------------------"
                       "\n| Tornando indietro..."
                       "\n| \n| Tornato indietro con successo!"
                       "\n|--------------------------\n");

                break;
            }

            case 3:{

                // Messaggio d'inizio.
                printf("\n|--------------------------"
                       "\n| Hai scelto: Riepilogo tempi...");
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
                printf("\n|--------------------------"
                       "\n| Scelta non valida, per favore riprovare!"
                       "\n|--------------------------\n");

                break;
            }
        }
    }

    // Messaggio d'uscita.
    printf("\n| Uscito con successo!"
           "\n|--------------------------");
    return 0;
}

unsigned long generatoreParole() {

    // Chiedo dati in ingresso all'utente.
    long numeroLettere;
    printf("\n| Inserire numero lettere: ");
    scanf("%ld", &numeroLettere);

    long numeroParole;
    printf("| Inserire numero parole: ");
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
    printf("| Generato FILE con successo in %ld secondi! Nome: fileParole.txt..."
           "\n| Usalo per l'algoritmo 5 dell'ordinamento alfabetico per esempio."
           "\n|--------------------------\n", tempoGenerazione);

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
        printf("\n| Errore durante la lettura del FILE."
               "\n| Se non esiste, crearne uno con il nome:"
               "\n| - fileParole.txt "
               "\n| e inserire una parola per riga."
               "\n| Puoi generare anche un FILE con"
               "\n| parole casuali usando le Opzioni"
               "\n| del menu."
               "\n|--------------------------");
        return 404;
    } else {

        // Trova parola piu' corta per evitare errori.
        long lunghezzaParolaCorta = 100000;
        while (!feof(fileParole)) {
            char parolaLetta[250];
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
        printf("\n| \n| Lunghezza parola piu' corta: %ld"
               "\n| Sara' usata come riferimento per la"
               "\n| precisione dell'ordine alfabetico."
               "\n| ATTENDERE...", lunghezzaParolaCorta);

        // Commentare il ciclo FOR in caso di problemi, il valore n = 0 di default sara' usato.
        for (n = lunghezzaParolaCorta - 1; n >= 0; n--) {
            // Conto quante righe sono contenute nel file.
            fileParole = fopen("fileParole.txt", "r");
            long numeroRighe = 0;
            while (!feof(fileParole)) {
                numeroRighe++;
                char parolaProva[250];
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
                    char parola[250];
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
                    char riga[250];
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
    printf("\n| \n| Completato con successo!"
           "\n| Tempo necessario per riordinare le parole su FILE: %ld secondi."
           "\n| Sono state ordinate %ld parole!"
           "\n|--------------------------", tempoRiordinamento, numeroParole);

    return tempoRiordinamento;
}

unsigned long ordinaFileNumeri2() {

    // Apre il FILE.
    FILE *cfFile = fopen("file.txt", "r");

    // Verifica se il FILE esiste.
    if (cfFile == NULL){
        printf("\n| Il file file.txt non esiste, per favore crearne uno prima di eseguire questa opzione, puoi"
               "\n| farlo anche con le opzioni del menu!");
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
    printf("\n| \n| Tempo necessario per riordinare i numeri su FILE: %ld secondi."
           "\n|--------------------------", tempoRiordinamento);

    return tempoRiordinamento;
}

unsigned long ordinaFileNumeri1() {

    // Apre il FILE.
    FILE *cfFile = fopen("file.txt", "r");

    // Verifica se il FILE esiste.
    if (cfFile == NULL){
        printf("\n| Il file file.txt non esiste, per favore crearne uno prima di eseguire questa opzione, puoi"
               "\n| farlo anche con le opzioni del menu!"
               "\n|--------------------------");
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

    printf("\n| Ordinamento su FILE temporaneo effettuato con successo!");
    printf("\n| \n| Tempo necessario per riordinare i numeri su FILE: %ld secondi.", tempoRiordinamento);
    printf("\n| Fine programma..."
           "\n|--------------------------");

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
    cout << "\n| \n| Completato con successo!"
            "\n| Sono stati necessari: " << risultatoOrdinamentoNumeri << " secondi per riordinare i numeri!\n|--------------------------"
         << endl;

    return risultatoOrdinamentoNumeri;
}

void leggiVettoreConNumeri(long nNumeri, const long *vettoreConNumeri) {

    // Leggo tutti i valori in ordine del nuovo vettore.
    for (long i = 0; i < nNumeri; i++) {
        printf("\n| %ld -> %ld", i + 1, vettoreConNumeri[i]);
    }
    printf("\n|--------------------------");
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
    cout << "\n| \n| Completato con successo!"
            "\n| Sono stati necessari: " << risultatoOrdinamentoNumeri << " secondi per riordinare i numeri!\n|--------------------------"
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
        printf("\n| Errore durante la creazione del file!"
               "\n|--------------------------");
    } else {
        for (long i = 0; i < nNumeri; i++) {
            if (i != 0){
                fprintf(cfFile, "%s", "\n");
            }
            long numeroCasuale = random(min, max);
            fprintf(cfFile, "%ld", numeroCasuale);
        }
        printf("| Creazione FILE Con valori casuali effettuata con successo!"
               "\n|--------------------------");
    }

    fclose(cfFile);
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\n|--------------------------"
           "\n| Inserisci un NUMERO a caso per continuare...");
    scanf("%d", &inusato);
    printf("|--------------------------\n");

}

long random(long min, long max){
    long randomMN1 = max - min + 1 ;
    return ((long) rand() % randomMN1 + min);
}