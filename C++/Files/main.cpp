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

    while (scelta != 0) {

        printf("\n\nLegenda:"
               "\n 0 -> Esci."
               "\n 1 -> Scrittura Files."
               "\n 2 -> Lettura Files."
               "\n 3 -> Aggiungi Stringa a File."
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
                           "\nStringa/Input 1"
                           "\nStringa/Input 2..."
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
                           "\nStringa/Output 1"
                           "\nStringa/Output 2..."
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

                printf("\nHai scelto: Append...");

                string nomeFile;

                printf("\nInserire nome file: ");
                cin >> nomeFile;

                FILE *cfPrt;

                cfPrt = fopen(nomeFile.c_str(), "a");

                if (cfPrt == NULL){
                    printf("\nErrore durante la lettura del file!");
                } else {

                    string valore = "ok";

                    while (valore != "esci"){

                        printf("\n\nInserire -esci- per uscire"
                               "\nOppure il valore da aggiungere"
                               "\nInput: ");
                        cin >> valore;

                        char tipoFile[3] = "%s";

                        int datiScritti = 0;

                        string capo = "\n";

                        if (valore != "esci"){

                            // Scrive a capo.
                            scrittura(cfPrt, tipoFile, capo);

                            scrittura(cfPrt, tipoFile, valore);

                            printf("\nAppend eseguito con successo!");
                            datiScritti++;
                        }
                    }

                    printf("\nUscito con successo!");

                }

                break;
            }

            default:{

                printf("\nHai inserito un valore non valido...");

                continua();
                break;
            }
        }
    }

    return 0;
}

void scrittura(FILE *cfPrt, char tipoFile[2], string &datoDaScrivere){

    fprintf(cfPrt, tipoFile, datoDaScrivere.c_str());

}

void lettura(string &nomeFile, char tipoFile[2]){

    FILE *cfPtr;
    cfPtr = fopen(nomeFile.c_str(), "r");
    char datoLetto[100];

    if (cfPtr == NULL){
        printf("\nErrore durante la lettura del file.");
    } else {

        // Evita errore di scrittura doppia ultimo dato e carattere vuoto all'inizio.
        while (!feof(cfPtr)) {
            fscanf(cfPtr, tipoFile, datoLetto);
            cout << "\n" << datoLetto;
        }

    }
    fclose(cfPtr);
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}