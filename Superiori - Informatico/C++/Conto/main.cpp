#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void continua();

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//              Conto di G.C. 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Valore bandiera.
    int scelta = 1;

    // Continua fino a messaggio di uscita da parte dell'utente.
    while (scelta != 0) {

        // Legenda.
        printf("\n\nScegli uno:"
               "\n0 -> Esci."
               "\n1 -> Scrivi."
               "\n2 -> Leggi."
               "\n3 -> Generare saldo in base a numero conto corrente con output in file esterno."
               "\n4 -> Aggiungi valore a file già esistente."
               "\n5 -> Rimuovi tutti i valori legati a un numero di conto."
               "\n6 -> Inserisci un dato in una determinata posizione (prima)."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0: {

                // Uscita.
                printf("\nHai scelto: Esci...");
                printf("\nUscita in corso...");

                break;
            }

            case 1: {

                // Messaggio d'inizio
                printf("\n\nHai scelto: Scrivi dati a conto.");

                // Introduzione variabili e FILE.
                int vuoleInserireAltro = 1;
                FILE *cfPtr;
                char capo[3] = "\n";
                cfPtr = fopen("conti.txt", "w");

                // Contatore valori inseriti.
                int valoriInseriti = 0;

                // Loop che continua fino all'input di uscita.
                while (vuoleInserireAltro != 0) {

                    // Legenda.
                    printf("\nAzioni possibili:"
                           "\n0 -> Esci e salva file."
                           "\n1 -> Aggiungi dato."
                           "\nScelta: ");
                    scanf("%d", &vuoleInserireAltro);

                    if (vuoleInserireAltro == 1) {

                        // Variabili
                        int numeroConto;
                        char nome[100];
                        double importo;

                        // Legenda e input
                        printf("\nSeguire la seguente struttura:"
                               "\nNumeroConto NomePersona Importo"
                               "\nEs -> 13 Gabriele 100"
                               "\nScrivi: ");
                        scanf("%d %s %lf", &numeroConto, nome, &importo);

                        // Evita di andare a capo all'inizio
                        if (valoriInseriti != 0) {
                            fprintf(cfPtr, "%s", capo);
                        }

                        // Incrementa numero di valori inseriti per andare a capo.
                        valoriInseriti++;

                        // Scrive nel file il valore.
                        fprintf(cfPtr, "%d %s %lf", numeroConto, nome, importo);

                        // Successo.
                        printf("\nDato scritto con successo!\n");

                    } else {

                        // Chiusura.
                        printf("\nChiusura e salvataggio file.");
                        fclose(cfPtr);
                    }
                }

                break;
            }

            case 2: {

                // Messaggio d'inizio.
                printf("\n\nHai scelto: Leggi");

                // Struttura.
                printf("\nEcco i dati contenuto nel file conti.txt..."
                       "\n\nNumeroConto \tNome \tImporto");

                // Introduce FILE.
                FILE *cfPtr;
                cfPtr = fopen("conti.txt", "r");

                // Verifica che non sia nullo e che quindi esista.
                if (cfPtr == NULL) {
                    printf("\nErrore durante la lettura del file!");
                } else {

                    // Variabili.
                    int numeroConto;
                    char nome[100];
                    double importo;

                    // Evita errore di scrittura doppia ultimo dato e carattere vuoto all'inizio.
                    while (!feof(cfPtr)) {
                        fscanf(cfPtr, "%d %s %lf", &numeroConto, nome, &importo);
                        printf("\n%d \t%s \t%lf", numeroConto, nome, importo);
                    }
                }

                // Chiede se andare avanti, poi chiude il file etc.
                continua();
                fclose(cfPtr);
                printf("\nChiusura file completata.");

                break;
            }

            case 3: {

                // Messaggio d'inizio.
                printf("\n\nHai scelto: Genera saldo in file esterno in base a numero conto...");

                // Introduce FILE.
                FILE *cfPtr;
                cfPtr = fopen("conti.txt", "r");

                // Verifica che il file esista.
                if (cfPtr == NULL) {
                    printf("\nErrore durante la lettura del file!");
                } else {

                    // Comunica struttura.
                    printf("\n\nDati contenuti: "
                           "\nNumero conto \tNome \tImporto");

                    // Variabili
                    int numeroConto;
                    char nome[100];
                    double importo;

                    // Mostra tutti i valori.
                    while (!feof(cfPtr)) {
                        fscanf(cfPtr, "%d %s %lf", &numeroConto, nome, &importo);
                        printf("\n%d \t%s \t%lf", numeroConto, nome, importo);
                    }

                    // Numero conto scelto dall'utente.
                    int numeroContoUtente;
                    double saldo = 0;

                    // Numero conto input.
                    printf("\n\nScegliere un numero di conto da cui estrarre il saldo in un file di nome saldo<Numero>.txt."
                           "\nNumero conto: ");
                    cin >> numeroContoUtente;

                    // Apre file per la lettura.
                    cfPtr = fopen("conti.txt", "r");

                    // Legge tutto il file.
                    while (!feof(cfPtr)) {
                        fscanf(cfPtr, "%d %s %lf", &numeroConto, nome, &importo);
                        if (numeroConto == numeroContoUtente) {
                            saldo += importo;
                        }
                    }

                    // Crea file nuovo.
                    FILE *cfPtr2;
                    string nomeFileSaldo = "saldo.txt";
                    cfPtr2 = fopen(nomeFileSaldo.c_str(), "w");
                    fprintf(cfPtr2, "%d %f", numeroContoUtente, saldo);
                    fclose(cfPtr2);
                }

                // Messaggio di fine.
                printf("\nOperazione svolta con successo!");

                break;
            }

            case 4: {

                // Messaggio d'inizio.
                printf("\nHai scelto: Aggiungi dato a file già esistente.");

                // Introduzione FILE in modalità append.
                FILE *cfPtr;
                cfPtr = fopen("conti.txt", "a");

                // Verifica se il file è nullo.
                if (cfPtr == NULL) {
                    printf("\nErrore durante la lettura del file!");
                } else {

                    // Valore bandiera e parametro.
                    int vuoleInserire = 1;
                    char capo[3] = "\n";

                    // Continua fino a input di uscita da parte dell'utente.
                    while (vuoleInserire != 0) {

                        // Legenda.
                        printf("\n\nFormato input: numeroConto Nome Importo"
                               "\nEsempio -> 13 Gabriele 100"
                               "\nVuoi inserire altri dati? Scegli:"
                               "\n0 -> Esci."
                               "\n1 -> Inserisci."
                               "\nInput: ");
                        scanf("%d", &vuoleInserire);

                        // Verifica input ed esegue azioni.
                        if (vuoleInserire == 1) {

                            // Variabili.
                            int numeroConto;
                            char nome[100];
                            double importo;

                            // Input utente.
                            printf("\n\nStruttura: numeroConto Nome Importo."
                                   "\nInput: ");
                            scanf("%d %s %lf", &numeroConto, nome, &importo);

                            // Manda a capo e scrive.
                            fprintf(cfPtr, "%s", capo);
                            fprintf(cfPtr, "%d %s %lf", numeroConto, nome, importo);
                        } else {

                            // Messaggio di uscita e chiusura file.
                            printf("\nHai scelto: Esci..."
                                   "\nUscito con successo!");
                            fclose(cfPtr);
                        }
                    }
                }

                break;
            }

            case 5:{

                // Messaggio d'inizio.
                printf("\n\nHai scelto: Rimuovi dati in base a numero di conto...");

                // Apri FILE.
                FILE *cfPtr;
                cfPtr = fopen("conti.txt", "r");

                // Verifica che il FILE non sia nullo.
                if (cfPtr == NULL){
                    printf("\nErrore durante l'apertura del file! Forse non esiste.");
                } else {

                    // Variabili
                    int numeroConto;
                    char nome[100];
                    double importo;
                    int nConto;

                    // Mostra tutti i valori.
                    printf("\nNumeroConto \tNome \tImporto");
                    while (!feof(cfPtr)) {
                        fscanf(cfPtr, "%d %s %lf", &numeroConto, nome, &importo);
                        printf("\n%d \t%s \t%lf", numeroConto, nome, importo);
                    }
                    fclose(cfPtr);

                    // Chiede scelta.
                    printf("\n\nInserire numero conto da eliminare: ");
                    scanf("%d", &nConto);

                    //Creazione file di appoggio e operazione in corso.
                    FILE *cfTemp;
                    cfTemp = fopen("temp.txt", "w");
                    cfPtr = fopen("conti.txt", "r");
                    int nScritte = 0;
                    char capo[3] = "\n";

                    // Legge tutto il file e scrive in quello nuovo escludendo il valore da eliminare.
                    if (cfPtr == NULL){
                        printf("\nErrore durante l'apertura del file.");
                    } else {
                        while (!feof(cfPtr)) {
                            fscanf(cfPtr, "%d %s %lf", &numeroConto, nome, &importo);
                            if (numeroConto != nConto) {
                                if (nScritte != 0) {
                                    fprintf(cfTemp, "%s", capo);
                                }
                                fprintf(cfTemp, "%d %s %lf", numeroConto, nome, importo);
                                nScritte++;
                            }
                        }
                        fclose(cfTemp);
                    }
                    fclose(cfPtr);

                    // Vecchio metodo sostituito dal rename.
                    /*cfTemp = fopen("temp.txt", "r");
                    cfPtr = fopen("conti.txt", "w");

                    if (cfTemp == NULL){
                        printf("\nC'è stato un errore durante l'apertura del file.");
                    } else {
                        while (!feof(cfTemp)) {
                            fscanf(cfTemp, "%d %s %lf", &numeroConto, nome, &importo);
                            if (nScritte != 0) {
                                fprintf(cfPtr, "%s", capo);
                            }
                            fprintf(cfPtr, "%d %s %lf", numeroConto, nome, importo);
                            nScritte++;
                        }
                    }
                    fclose(cfTemp);
                    fclose(cfPtr);
                    remove("temp.txt");*/

                    // Cancella il vecchio file dei conti e lo sostituisce con quello temporaneo.
                    remove("conti.txt");
                    rename("temp.txt", "conti.txt");
                }

                // Mesaggio di fine.
                printf("\nFine operazione!");

                break;
            }

            case 6: {

                // Messaggio d'inizio.
                printf("\nHai scelto: Inserisci un dato in un determinata posizione...");

                // Apre file.
                FILE *cfPtr;
                cfPtr = fopen("conti.txt", "r");

                // Verifica se il FILE esiste e non è nullo.
                if (cfPtr == NULL) {
                    printf("\nErrore durante l'apertura del file! Forse non esiste.");
                } else {

                    // Variabili
                    int numeroConto;
                    char nome[100];
                    double importo;
                    int numeroDato = 1;

                    // Mostra i valori e quindi la scelta per posizione.
                    printf("\nPosizione \tNumeroConto \tNome \tImporto");
                    while (!feof(cfPtr)) {
                        fscanf(cfPtr, "%d %s %lf", &numeroConto, nome, &importo);
                        printf("\n%d -> \t%d \t%s \t%lf", numeroDato, numeroConto, nome, importo);
                        numeroDato++;
                    }
                    fclose(cfPtr);

                    // Prende input utente posizione.
                    int numeroPosizione;
                    printf("\n\nInserisc posizione prima di cui inserire il dato: ");
                    scanf("%d", &numeroPosizione);

                    // Verifica che la posizione sia valida.
                    if (numeroPosizione > numeroDato){
                        printf("\nHai scelto una posizione non valida!");
                    } else {

                        // Introduce variabili.
                        int valoreInput;
                        char nomeInput[100];
                        double importoInput;

                        // Chiede all'utente il dato da inserire.
                        printf("\nInserire dato da inserire con il seguente formato: "
                               "\nNumeroConto NomePersona Importo"
                               "\nEs: 13 Gabriele 100"
                               "\nValore inserito: ");
                        scanf("%d %s %lf", &valoreInput, nomeInput, &importoInput);

                        // Decrementa la posizione per renderla valida visto che inizierebbe da 0.
                        numeroPosizione--;

                        // Apre o crea i vari FILEs,
                        FILE *cfTemp;
                        cfPtr = fopen("conti.txt", "r");
                        cfTemp = fopen("temp.txt", "w");

                        // Introduce altre variabili.
                        int numeriIns = 0;
                        char capo[3] = "\n";

                        // Verifica che il file non sia nullo e scrive quello nuovo aggiungendo il valore.
                        if (cfPtr == NULL){
                            printf("\nErrore durante la lettura del file!");
                        } else {
                        while (!feof(cfPtr)) {
                            if (numeriIns != 0){
                                fprintf(cfTemp, "%s", capo);
                            }
                            if (numeriIns == numeroPosizione){
                                fprintf(cfTemp, "%d %s %lf", valoreInput, nomeInput, importoInput);
                                fprintf(cfTemp, "%s", capo);

                                printf("\nValore inserito con successo!");
                            }

                            fscanf(cfPtr, "%d %s %lf", &numeroConto, nome, &importo);
                            fprintf(cfTemp, "%d %s %lf", numeroConto, nome, importo);
                            numeriIns++;
                        }
                        fclose(cfPtr);
                        fclose(cfTemp);

                        // Cancella il vecchio FILE dei conti e lo sostituisce con quello nuovo temporaneo.
                        remove("conti.txt");
                        rename("temp.txt", "conti.txt");

                        }
                    }
                }

                // Messaggio di fine.
                printf("\nOperazione terminata!");

                break;
            }

            default: {

                // Comunica input non valido.
                printf("\nInserito valore non valido!");

                break;
            }
        }
    }

    // Messaggio di uscita.
    printf("\nUscito con successo.");

    return 0;
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}