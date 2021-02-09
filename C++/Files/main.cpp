#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

void continua();

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//              Files di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;

    while (scelta != 0) {

        printf("\n\nLegenda:"
               "\n 0 -> Esci."
               "\n 1 -> Prima esperienza Files."
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

                string input = "ok";
                while (input != "esci"){

                    printf("\n\nInserire qualcosa da scrivere!"
                           "\nScrivere -esci- per uscire."
                           "\nScrivi: ");
                    cin >> input;

                    if (input != "esci"){

                        printf("\nSalvataggio input in corso...");

                        // Scrittura e nuova linea.
                        fprintf(cfPtr, "%s" , input.c_str());
                        fprintf(cfPtr, "%s", "\n");

                        printf("\nSalvato con successo!");

                    } else {

                        printf("\nUscendo e salvando...");
                        fclose(cfPtr);
                    }
                }

                printf("\nUscito con successo!");

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

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}