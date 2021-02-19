#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void continua();

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//              Conto di Gabriele Caretti 3BITI             //"
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
