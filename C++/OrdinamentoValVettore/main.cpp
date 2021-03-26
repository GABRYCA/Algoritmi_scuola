#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

void continua();

long random(long min, long max);

void genSuFileValCasuali(long nNumeri, long max, long min, FILE *cfFile);

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           Ord.Vet. di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;
    while (scelta != 0) {

        printf("\nLegenda scelte:"
               "\n0 -> Esci."
               "\n1 -> Ordinamento vettore numeri casuali."
               "\n2 -> Ordinamento vettore numeri casuali 2."
               "\n3 -> Ordinamento FILE inefficiente senza vettori."
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

                // Faccio un ciclo per l'intero vettore, ogni valore sarà spostato nella nuova posizione.
                long vecchioNumero;
                for (long i = 0; i < nNumeri; i++) {

                    // Faccio un ciclo per tutto il vettore a partire dal valore successivo alla posizione di assegnamento.
                    for (long j = i + 1; j < nNumeri; j++) {

                        // Verifico se il numero che sto verificando è maggiore di quello attualmente presente.
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
                long nNumeri;
                long max, min;
                printf("\nInserire numero di valori da generare: ");
                scanf("%ld", &nNumeri);
                printf("\nInserire numero massimo possibile: ");
                scanf("%ld", &max);
                printf("\nInserire numero minore: ");
                scanf("%ld", &min);

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

            default:{

                printf("\nScelta non valida, per favore riprovare!");

                break;
            }
        }
    }

    printf("\nUscito con successo!");
    return 0;
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