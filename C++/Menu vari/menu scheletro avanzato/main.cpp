#include <iostream>

void continua();

int main() {

    // Dichiaro parametri e variabili
    int nValoreScelto = 1;

    // While che si annulla se si mette 0
    while (nValoreScelto != 0) {

        // Legenda
        printf("\n\nScegli un valore per eseguire l'algoritmo, 0 per uscire.");

        printf("\n0 -> Fine.\n");
        printf("1 -> .\n");
        printf("2 -> .\n");
        printf("3 -> .\n");
        printf("4 -> .\n");
        printf("5 -> .\n");
        printf("6 -> .\n");
        printf("7 -> .\n");

        // Chiedo all'utente di inserire un valore
        printf("Valore inserito: ");

        // Ottengo dall'utente l'input
        scanf("%d", &nValoreScelto);

        // Swicth tra i valori scelti
        switch (nValoreScelto) {

            case 0:{

                // Messaggi d'inizio
                printf("\nHai scelto: FINE!\n");

                // Comunico che si sta chiudendo tutto con successo
                printf("\nChiuso con successo!");

                // 0 significa di uscire da tutto
                nValoreScelto = 0;

                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case 1:{



                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case 2:{



                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case 3:{



                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case 4:{



                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case 5:{



                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case  6:{



                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            case 7:{



                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

            default:{

                // Comunico all'utente che il valore inserito non è valido o compreso nella lista
                printf("\n[ERRORE] -> Il valore inserito non è valido!");

                // Chiedo all'utente se vuole continuare
                continua();

                break;
            }

        }

    }

    return 0;
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}