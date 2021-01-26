#include <iostream>
#include <stdio.h>

void continua();

bool compare(int lunghezzaMassima, char stringa[], char stringa2[]);

int dimensioni(int lunghezzaMassima, char stringa[]);

void unisci(int lunghezzaMassima, char stringa[], char stringa2[]);

void inverti(int lunghezzaMassima, char stringa[]);

int main() {

    // Messaggio del creatore
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//            Stringhe di Gabriele Caretti 3BITI              //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;
    int lunghezzaMassima = 100;
    char stringa[lunghezzaMassima];
    char stringa2[lunghezzaMassima];

    while (scelta != 0){

        printf("\nLegenda:"
               "\n 0 -> Esci."
               "\n 1 -> Inserisci/Modifica stringa 1."
               "\n 2 -> Inserisci/Modifica stringa 2."
               "\n 3 -> Confronta stringa 1 a 2."
               "\n 4 -> Mostra stringa 1."
               "\n 5 -> Mostra stringa 2."
               "\n 6 -> Lunghezza stringa."
               "\n 7 -> Unisci stringa 1 e 2 in Stringa 1."
               "\n 8 -> Inverti valori stringa."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\n\nHai scelto: Esci...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Inserisci stringa 1...");

                printf("\nInserire stringa: ");
                scanf("%s", stringa);

                printf("\nStringa 1 inserita con successo!");

                continua();
                break;
            }

            case 2:{

                printf("\n\nHai scelto: Inserisci stringa 2...");

                printf("\nInserire stringa: ");
                scanf("%s", stringa2);

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

            case 6:{

                printf("\nHai scelto: Lunghezza stringa...");

                int nStringa = 1;

                while (nStringa != 0) {
                    printf("\nScegli una delle stringhe: "
                           "\n 0 -> Esci."
                           "\n 1 -> Stringa 1."
                           "\n 2 -> Stringa 2."
                           "\nScelta: ");
                    scanf("%d", &nStringa);

                    switch (nStringa) {

                        case 0:{

                            printf("\nHai scelto: Esci...");

                            break;
                        }

                        case 1:{

                            printf("\nHai scelto: Stringa 1");

                            printf("\nLa stringa 1 ha dimensioni: %d.", dimensioni(lunghezzaMassima, stringa));

                            continua();
                            break;
                        }

                        case 2:{

                            printf("\nHai scelto: Stringa 2");

                            printf("\nLa stringa 2 ha dimensioni: %d", dimensioni(lunghezzaMassima, stringa2));

                            continua();
                            break;
                        }

                        default:{

                            printf("\nHai inserito una scelta non valida!");

                            continua();
                            break;
                        }
                    }
                }

                continua();
                break;
            }

            case 7:{

                printf("\nHai scelto: Unisci stringhe 1 e 2 in Stringa 1...");

                unisci(lunghezzaMassima, stringa, stringa2);

                printf("\nUniti con successo stringa 1 e 2 in Stringa 1 -> %s", stringa);

                continua();
                break;
            }

            case 8:{

                printf("\nHai scelto: Inverti valori stringa...");

                int nStringa = 1;

                while (nStringa != 0) {
                    printf("\nScegli una delle stringhe: "
                           "\n 0 -> Esci."
                           "\n 1 -> Stringa 1."
                           "\n 2 -> Stringa 2."
                           "\nScelta: ");
                    scanf("%d", &nStringa);

                    switch (nStringa) {

                        case 0:{

                            printf("\nHai scelto: Esci...");

                            break;
                        }

                        case 1:{

                            printf("\nHai scelto: Stringa 1");

                            inverti(lunghezzaMassima, stringa);

                            printf("\nStringa 1 invertita con successo! Valore: %s", stringa);
                            continua();
                            break;
                        }

                        case 2:{

                            printf("\nHai scelto: Stringa 2");

                            inverti(lunghezzaMassima, stringa2);

                            printf("\nStringa 2 invertita con successo! Valore: %s", stringa2);
                            continua();
                            break;
                        }

                        default:{

                            printf("\nHai inserito una scelta non valida!");

                            continua();
                            break;
                        }
                    }
                }

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

void inverti(int lunghezzaMassima, char stringa[]) {
    char temp[lunghezzaMassima];
    int j = 0, dimensioniS = dimensioni(lunghezzaMassima, stringa);
    for (int i = dimensioniS; i > 0; i--) {
        temp[j] = stringa[i-1];
        j++;
    }
    for (int i = 0; i < dimensioniS; i++) {
        stringa[i] = temp[i];
    }
}

void unisci(int lunghezzaMassima, char stringa[], char stringa2[]) {

    int lungStr1 = dimensioni(lunghezzaMassima, stringa);
    int lungStr2 = dimensioni(lunghezzaMassima, stringa2);

    for (int i = 0; i < lungStr2; i++) {
        stringa[lungStr1 + i] = stringa2[i];
    }

}

int dimensioni(int lunghezzaMassima, char stringa[]) {

    int dimensioni = 0;
    char nullo[2] = "\0";

    for (int i = 0; i < lunghezzaMassima; i++) {
        if (stringa[i] == nullo[1]){
            return dimensioni;
        } else {
            dimensioni = i + 1;
        }
    }

    return dimensioni;
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