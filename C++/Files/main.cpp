#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void continua();
void scrittura(FILE *cfPrt, char tipoFile[2] , string &datoDaScrivere);
void lettura(string &nomeFile, char tipoFile[2]);

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//              Files di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;

    // Per conto scrivere numero conto, singoli importi e saldo somma importi.

    while (scelta != 0) {

        // Legenda
        printf("\n\nLegenda:"
               "\n 0 -> Esci."
               "\n 1 -> Scrittura Files."
               "\n 2 -> Lettura Files."
               "\n 3 -> Aggiungi Stringa a File."
               "\n 4 -> Conto."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nUscendo dal programma.");

                break;
            }

            case 1:{

                printf("\nHai scelto: Files...");

                FILE *cfPtr;

                string nomeFile;
                printf("\nInserire nome file + estensione (esempio: ilMioFile.txt): ");
                cin >> nomeFile;

                // w -> write, r -> read.
                cfPtr = fopen(nomeFile.c_str(), "w");
                // Non veramente necessario durante operazioni di scrittura ma più per lettura.
                if (cfPtr == NULL){
                    printf("\nErrore durante l'apertura File!");
                }

                int datiScritti = 0;

                string input = "ok";
                while (input != "esci"){

                    printf("\n\nInserire qualcosa da scrivere!"
                           "\nStruttura file finale:"
                           "\nScrivere -esci- per uscire."
                           "\nScrivi: ");
                    cin >> input;

                    if (input != "esci"){

                        printf("\nSalvataggio input in corso...");

                        char tipoDato[3] = "%s";
                        string capo = "\n";

                        if (datiScritti >= 1){
                            scrittura(cfPtr, tipoDato, capo);
                        }

                        // Scrittura e nuova linea.
                        scrittura(cfPtr, tipoDato,  input);

                        datiScritti++;
                        printf("\nSalvato con successo!");

                    } else {

                        printf("\nUscendo e salvando...");
                        fclose(cfPtr);
                    }
                }

                printf("\nUscito con successo!");

                break;
            }

            case 2:{

                printf("\nHai scelto: Lettura...");

                string dato = "1";

                while (dato != "esci"){

                    printf("\n\nInserire -esci- se vuoi uscire."
                           "\n -> oppure il nome file da leggere (es: Prova.txt)."
                           "\nL'Output sarà di questo tipo:"
                           "\nInput: ");
                    cin >> dato;

                    // Leggiamo qualcosa
                    if (dato != "esci"){

                        char tipoFile[3] = "%s";

                        lettura(dato, tipoFile);

                    } else {

                        // Uscita
                        printf("\nUscita in corso,,,");
                    }
                }

                // Uscita
                printf("\nUscito con successo!");

                break;
            }

            case 3:{

                // Messaggio d'inizio
                printf("\nHai scelto: Append...");

                // Variabile nomeFile.
                string nomeFile;

                // Input nomeFile.
                printf("\nInserire nome file: ");
                cin >> nomeFile;

                // Introduzione FILE e assegnazione append.
                FILE *cfPrt;
                cfPrt = fopen(nomeFile.c_str(), "a");

                // Verifica se il file esiste oppure è nullo.
                if (cfPrt == NULL){
                    printf("\nErrore durante la lettura del file!");
                } else {

                    // Valore bandiera.
                    string valore = "ok";

                    // Ciclo che continua fino a input uscita utente.
                    while (valore != "esci"){

                        // Legenda.
                        printf("\n\nInserire -esci- per uscire"
                               "\nOppure il valore da aggiungere"
                               "\nInput: ");
                        cin >> valore;

                        // Variabili.
                        char tipoFile[3] = "%s";
                        string capo = "\n";

                        // Controlla se il valore è diverso da esci.
                        if (valore != "esci"){

                            // Scrive a capo e dato.
                            scrittura(cfPrt, tipoFile, capo);
                            scrittura(cfPrt, tipoFile, valore);

                            printf("\nAppend eseguito con successo!");
                        }
                    }

                    // Uscita.
                    printf("\nUscito con successo!");

                }

                break;
            }

            case 4:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Conto...");

                // Variabile bandiera.
                int vuoleUsareConto = 1;

                // Continua fino a input di fine dell'utente.
                while (vuoleUsareConto != 0){

                    // Legenda.
                    printf("\n\nScegli uno:"
                           "\n0 -> Esci."
                           "\n1 -> Scrivi."
                           "\n2 -> Leggi."
                           "\n3 -> Generare saldo in base a numero conto corrente con output in file esterno."
                           "\n4 -> Aggiungi valore a file già esistente."
                           "\nScelta: ");
                    scanf("%d", &vuoleUsareConto);

                    // Scelte.
                    switch (vuoleUsareConto) {

                        case 0:{

                            // Uscita.
                            printf("\nHai scelto: Esci...");
                            printf("\nUscita in corso...");

                            break;
                        }

                        case 1:{

                            // Messaggio d'inizio
                            printf("\n\nHai scelto: Scrivi dati a conto.");

                            // Variabili e parametri.
                            int vuoleInserireAltro = 1;
                            FILE *cfPtr;
                            char capo[3] = "\n";
                            cfPtr = fopen("conti.txt", "w");

                            // Contatore valori inseriti.
                            int valoriInseriti = 0;

                            // Loop che continua fino all'input di uscita.
                            while (vuoleInserireAltro != 0) {

                                printf("\nAzioni possibili:"
                                       "\n0 -> Esci e salva file."
                                       "\n1 -> Aggiungi dato."
                                       "\nScelta: ");
                                scanf("%d", &vuoleInserireAltro);

                                // Esegue azioni in base a input.
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
                                    if (valoriInseriti != 0){
                                        fprintf(cfPtr, "%s", capo);
                                    }

                                    // Incrementa numero di valori inseriti per andare a capo.
                                    valoriInseriti++;

                                    // Scrive nel file il valore.
                                    fprintf(cfPtr, "%d %s %lf", numeroConto, nome, importo);

                                    // Successo.
                                    printf("\nDato scritto con successo");

                                } else {

                                    // Chiusura.
                                    printf("\nChiusura e salvataggio file.");
                                    fclose(cfPtr);
                                }
                            }

                            break;
                        }

                        case 2:{

                            // Messaggio d'inizio.
                            printf("\n\nHai scelto: Leggi");

                            // Struttura.
                            printf("\nEcco i dati contenuto nel file conti.txt..."
                                   "\nNumeroConto \tNome \tImporto");

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

                        case 3:{

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

                                // Apre file in modalità lettura.
                                cfPtr = fopen("conti.txt", "r");

                                // Legge tutto il file.
                                while (!feof(cfPtr)){
                                    fscanf(cfPtr, "%d %s %lf", &numeroConto, nome, &importo);
                                    printf("numeroConto = %d, numeroContoUtenteInt = %d, importo = %lf, saldo = %lf", numeroConto, numeroContoUtente, importo, saldo);
                                    if (numeroConto == numeroContoUtente){
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

                            printf("\nOperazione eseguita con successo!");

                            break;
                        }

                        case 4:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Aggiungi dato a file già esistente.");

                            // Valore bandiera.
                            int vuoleInserire = 1;

                            // Introduzione file in modalità append.
                            FILE *cfPtr;
                            cfPtr = fopen("conti.txt", "a");
                            char capo[3] = "\n";

                            // Verifica se il file è nullo.
                            if (cfPtr == NULL){
                                printf("\nErrore durante la lettura del file!");
                            } else {

                                // Continua fino a input di uscita dell'utente.
                                while (vuoleInserire != 0) {

                                    // Legenda.
                                    printf("\nFormato input: numeroConto Nome Importo"
                                           "\nEsempio -> 13 Gabriele 100"
                                           "\nVuoi inserire altri dati? Scegli:"
                                           "\n0 -> Esci."
                                           "\n1 -> Inserisci."
                                           "\nInput: ");
                                    scanf("%d", &vuoleInserire);

                                    // Esegue azioni in base a input.
                                    if (vuoleInserire == 1) {

                                        // Variabili.
                                        int numeroConto;
                                        char nome[100];
                                        double importo;

                                        // Input utente.
                                        printf("\n\nStruttura: numeroConto Nome Importo."
                                               "\nInput: ");
                                        scanf("%d %s %lf", &numeroConto, nome, &importo);

                                        // Scrittura su file.
                                        fprintf(cfPtr, "%s", capo);
                                        fprintf(cfPtr, "%d %s %lf", numeroConto, nome, importo);
                                    } else {

                                        // Messaggio d'uscita e chiusura FILE.
                                        printf("\nHai scelto: Esci..."
                                               "\nUscito con successo!");
                                        fclose(cfPtr);
                                    }
                                }
                            }

                            break;
                        }

                        default:{

                            // Messaggio di input non valido.
                            printf("\nInserito valore non valido!");

                            break;
                        }
                    }
                }
            }

            default:{

                // Messaggio di input non valido.
                printf("\nHai inserito un valore non valido...");

                continua();
                break;
            }
        }
    }

    return 0;
}

void scrittura(FILE *cfPrt, char tipoFile[2], string &datoDaScrivere){

    // Scrive su file.
    fprintf(cfPrt, tipoFile, datoDaScrivere.c_str());

}

void lettura(string &nomeFile, char tipoFile[2]){

    // Introduce file in modalità lettura.
    FILE *cfPtr;
    cfPtr = fopen(nomeFile.c_str(), "r");
    char datoLetto[100];

    // Verifica se esiste.
    if (cfPtr == NULL){
        printf("\nErrore durante la lettura del file.");
    } else {

        // Evita errore di scrittura doppia ultimo dato e carattere vuoto all'inizio.
        while (!feof(cfPtr)) {
            fscanf(cfPtr, tipoFile, datoLetto);
            cout << "\n" << datoLetto;
        }
    }

    // Chiusura FILE.
    fclose(cfPtr);
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}