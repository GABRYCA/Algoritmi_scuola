#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

void continua();

long random(long min, long max);

void genSuFileValCasuali(long nNumeri, long max, long min, FILE *cfFile);

long posizioneAlfabeto(const string &stringaParola, long lettera);

void rimuoviValorePerPosizione(FILE *cfFile, FILE *cfTemp2, long posizione);

void leggiNumeriFile(FILE *cfFile);

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           Ord.Vet. di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;
    while (scelta != 0) {

        // Algoritmo 5 non finito per mancanza di tempo e consegna non capita la scorsa volta.
        printf("\nLegenda scelte:"
               "\n0 -> Esci."
               "\n1 -> Ordinamento vettore numeri casuali."
               "\n2 -> Ordinamento vettore numeri casuali 2."
               "\n3 -> Ordinamento FILE inefficiente senza vettori."
               "\n4 -> Ordinamento FILE inefficiente tipo 2."
               "\n5 -> Ordinamento FILE di parole in ordine alfabetico."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nUscita in corso...");

                break;
            }

            case 1: {
                // Messaggio d'inizio.
                printf("\nHai scelto: ordinamento numeri in un vettore casuale dal più piccolo al più grande...");

                // Inserimento dati per variabili dell'utente.
                long nNumeri;
                long max, min;
                printf("\nInserire numero di valori da generare: ");
                scanf("%ld", &nNumeri);
                printf("\nInserire numero massimo possibile: ");
                scanf("%ld", &max);
                printf("\nInserire numero minore: ");
                scanf("%ld", &min);

                srand(time(0));

                clock_t inizio = clock();

                // Genero valori casuali tra max e min per tutto il vettore.
                long vettoreConNumeri[nNumeri];
                for (long i = 0; i < nNumeri; i++) {
                    vettoreConNumeri[i] = random(min, max);
                }

                clock_t fine = clock();

                // Tempo di fine.
                unsigned long risultatoGenNumeri = (fine - inizio)/CLOCKS_PER_SEC;

                inizio = clock();

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

                fine = clock();

                // Tempo di fine.
                unsigned long risultatoOrdinamentoNumeri = (fine - inizio)/CLOCKS_PER_SEC;

                // Leggo tutti i valori in ordine del nuovo vettore.
                for (long i = 0; i < nNumeri; i++) {
                    printf("\n%ld -> %ld", i + 1, vettoreConNumeri[i]);
                }

                cout << "\n\nSono stati necessari: " << risultatoGenNumeri << " secondi per generare i numeri!" << endl;
                cout << "Sono stati necessari: " << risultatoOrdinamentoNumeri << " secondi per riordinare i numeri!"
                     << endl;

                continua();
                break;
            }

            case 2:{

                // Messaggio d'inizio.
                printf("\nHai scelto: ordinamento numeri in un vettore casuale dal piu' piccolo al piu' grande...");

                // Inserimento dati per variabili dell'utente.
                long nNumeri;
                long max, min;
                printf("\nInserire numero di valori da generare: ");
                scanf("%ld", &nNumeri);
                printf("\nInserire numero massimo possibile: ");
                scanf("%ld", &max);
                printf("\nInserire numero minore: ");
                scanf("%ld", &min);

                srand(time(0));

                clock_t inizio = clock();

                // Genero valori casuali tra max e min per tutto il vettore.
                long vettoreConNumeri[nNumeri];
                for (long i = 0; i < nNumeri; i++) {
                    vettoreConNumeri[i] = random(min, max);
                }

                clock_t fine = clock();

                // Tempo di fine.
                unsigned long risultatoGenNumeri = (fine - inizio)/CLOCKS_PER_SEC;

                inizio = clock();

                long vettoreNuovo[nNumeri];
                long contatore = 0;
                for(long i = min; i <= max; i++){

                    for(long j = 0; j < nNumeri; j++){

                        if(vettoreConNumeri[j] == i){

                            vettoreNuovo[contatore] = vettoreConNumeri[j];
                            contatore++;
                        }
                    }
                }

                // Ricopio i numeri del vettore di appoggio nell'originale
                for (long i = 0; i < nNumeri; i++) {
                    vettoreConNumeri[i] = vettoreNuovo[i];
                }

                fine = clock();

                // Tempo di fine.
                unsigned long risultatoOrdinamentoNumeri = (fine - inizio)/CLOCKS_PER_SEC;

                // Leggo tutti i valori in ordine del nuovo vettore.
                for (long i = 0; i < nNumeri; i++) {
                    printf("\n%ld -> %ld", i + 1, vettoreConNumeri[i]);
                }

                cout << "\n\nSono stati necessari: " << risultatoGenNumeri << " secondi per generare i numeri!" << endl;
                cout << "Sono stati necessari: " << risultatoOrdinamentoNumeri << " secondi per riordinare i numeri!"
                     << endl;

                continua();
                break;
            }

            case 3:{

                printf("\nHai scelto: Riordinamento FILE inefficiente.");

                // Inserimento dati per variabili dell'utente.
                long nNumeri, max, min;
                printf("\nInserire numero di valori da generare: ");
                scanf("%ld", &nNumeri);
                printf("\nInserire numero massimo possibile: ");
                scanf("%ld", &max);
                printf("\nInserire numero minore: ");
                scanf("%ld", &min);

                printf("\nAttendere...");

                srand(time(0));

                // Genero valori casuali tra max e min per tutto il FILE scrivendoli.
                FILE *cfFile;
                cfFile = fopen("file.txt", "w");
                clock_t inizio = clock();
                genSuFileValCasuali(nNumeri, max, min, cfFile);
                clock_t fine = clock();
                fclose(cfFile);

                // Tempo necessario alla generazione.
                unsigned long tempoGenerazione = (fine - inizio)/CLOCKS_PER_SEC;

                // Scrittura.
                FILE *cfTemp;
                cfTemp = fopen("fileTemp.txt", "w");

                inizio = clock();

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

                fine = clock();

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                // Cancella vecchio FILE e rinomina quello nuovo per sostituirlo.
                remove("file.txt");
                rename("fileTemp.txt", "file.txt");

                printf("\nOrdinamento su FILE temporaneo effettuato con successo!");

                // Lettura FILE finale.
                cfFile = fopen("file.txt", "r");
                if (cfFile == NULL){
                    printf("\nErrore durante la lettura del FILE.");
                } else {
                    printf("\nLettura FILE ordinato:");
                    while (!feof(cfFile)){
                        long numero;
                        fscanf(cfFile, "%ld", &numero);
                        printf("\n%ld", numero);
                    }
                    fclose(cfFile);
                }

                printf("\n\nTempo necessario per generare e scrivere numeri su FILE: %ld secondi.", tempoGenerazione);
                printf("\nTempo necessario per riordinare i numeri su FILE: %ld secondi.", tempoRiordinamento);

                printf("\nFine programma...");
                continua();
                break;
            }

            case 4:{

                printf("\nHai scelto: Ordinamento numeri su FILE inefficiente tipo 2.");

                // Inserimento dati per variabili dell'utente.
                long nNumeri, max, min;
                printf("\nInserire numero di valori da generare: ");
                scanf("%ld", &nNumeri);
                printf("\nInserire numero massimo possibile: ");
                scanf("%ld", &max);
                printf("\nInserire numero minore: ");
                scanf("%ld", &min);

                printf("\nAttendere...");

                // Genero valori casuali tra max e min per tutto il FILE scrivendoli.
                FILE *cfFile;
                cfFile = fopen("file.txt", "w");
                clock_t inizio = clock();
                genSuFileValCasuali(nNumeri, max, min, cfFile);
                clock_t fine = clock();
                fclose(cfFile);

                // Tempo necessario alla generazione.
                unsigned long tempoGenerazione = (fine - inizio)/CLOCKS_PER_SEC;

                inizio = clock();
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
                fine = clock();

                // Lettura FILE finale.
                cfFile = fopen("file.txt", "r");
                leggiNumeriFile(cfFile);

                // Tempo necessario al riordinamento.
                unsigned long tempoRiordinamento = (fine - inizio)/CLOCKS_PER_SEC;

                printf("\n\nTempo necessario per generare e scrivere numeri su FILE: %ld secondi.", tempoGenerazione);
                printf("\nTempo necessario per riordinare i numeri su FILE: %ld secondi.", tempoRiordinamento);

                continua();
                break;
            }

            case 5: {

                // Messaggio d'inizio.
                printf("\nHai scelto: Ordinamento FILE di parole in ordine alfabetico."
                       "\nAttendere...");

                clock_t inizio = clock();

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
                       "\nTempo necessario per riordinare le parole su FILE: %ld secondi.", tempoRiordinamento);

                continua();
                break;
            }

            default:{

                printf("\nScelta non valida, per favore riprovare!");

                break;
            }
        }
    }

    printf("\nUscito con successo!");
    return 0;
}

void leggiNumeriFile(FILE *cfFile) {
    if (cfFile == NULL){
        printf("\nErrore durante la lettura del FILE.");
    } else {
        printf("\nLettura FILE ordinato:");
        while (!feof(cfFile)){
            long numero;
            fscanf(cfFile, "%ld", &numero);
            printf("\n%ld", numero);
        }
        fclose(cfFile);
    }
}

void rimuoviValorePerPosizione(FILE *cfFile, FILE *cfTemp2, long posizione) {
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

void genSuFileValCasuali(long nNumeri, long max, long min, FILE *cfFile) {
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