#include <iostream>
#include <stdio.h>

void continua();

bool compare(int lunghezzaMassima, char stringa[], char stringa2[]);

int main() {

    // Messaggio del creatore
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//            Stringhe di Gabriele Caretti 3BITI              //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;
    int lunghezzaMassima = 100;
    char stringa[100] = {"n"};
    char stringa2[100] = {"n"};

    while (scelta != 0){

        printf("\nLegenda:"
               "\n 0 -> Esci."
               "\n 1 -> Inserisci stringa 1."
               "\n 2 -> Inserisci stringa 2."
               "\n 3 -> Confronta stringa 1 a 2."
               "\n 4 -> Mostra stringa 1."
               "\n 5 -> Mostra stringa 2."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\n\nHai scelto: Esci...");

                continua();
                break;
            }

            case 1:{

                printf("\nHai scelto: Inserisci stringa 1...");

                printf("\nInserire stringa: ");
                scanf(" %s", stringa);

                printf("\nStringa 1 inserita con successo!");

                continua();
                break;
            }

            case 2:{

                printf("\n\nHai scelto: Inserisci stringa 2...");

                printf("\nInserire stringa: ");
                scanf(" %s", stringa2);

                printf("\nStringa 2 inserita con successo!");

                continua();
                break;
            }

            case 3:{

                printf("\n\nHai scelto: Confronta stringhe...");

                if (compare(lunghezzaMassima, stringa, stringa2)){
                    printf("\nLe stringhe %s e %s sono uguali!", stringa, stringa2);
                } else {
                    printf("\nLe stringhe %s e %s sono diverse!", stringa, stringa2);
                }

                continua();
                break;
            }

            case 4:{

                printf("\nHai scelto: Mostra stringa 1...");

                printf("\nValore stringa 1: %s", stringa);

                continua();
                break;
            }

            case 5:{

                printf("\nHai scelto: Mostra stringa 2...");

                printf("\nValore stringa 2: %s", stringa2);

                continua();
                break;
            }

            default:{

                printf("\nHai inserito una scelta non valida.");

                continua();
                break;
            }
        }
    }

    printf("\nEsercizio chiuso con successo!");

    return 0;
}

// Ritorna true se sono uguali.
bool compare(int lunghezzaMassima, char stringa[], char stringa2[]) {

    for (int i = 0; i < lunghezzaMassima; i++) {
        if (stringa[i] != stringa2[i]){
            return false;
        }
    }

    return true;
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}