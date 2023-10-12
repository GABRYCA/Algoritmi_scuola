#include <iostream>
#include <stdio.h>

void continua();

bool compare(int lunghezzaMassima, char stringa[], char stringa2[]);
int dimensioni(char stringa[]);
void unisci(char stringa[], char stringa2[]);
void inverti(int lunghezzaMassima, char stringa[]);
void subString(char stringa[], int numeroSub);
void replace(char stringa[], int posMod, char stringaDaIns[]);

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//            Stringhe di G.C. 3BITI            //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Variabili e parametri globali.
    int scelta = 1;
    int lunghezzaMassima = 100;
    char stringa[lunghezzaMassima];
    char stringa2[lunghezzaMassima];

    // Ciclo programma e menu.
    while (scelta != 0){

        // Legenda e richiesta input.
        printf("\n\nLegenda:"
               "\n 0 -> Esci."
               "\n 1 -> Inserisci/Modifica stringa 1."
               "\n 2 -> Inserisci/Modifica stringa 2."
               "\n 3 -> Confronta stringa 1 a 2."
               "\n 4 -> Mostra stringa 1."
               "\n 5 -> Mostra stringa 2."
               "\n 6 -> Lunghezza stringa."
               "\n 7 -> Unisci stringa 1 e 2 in Stringa 1."
               "\n 8 -> Inverti valori stringa."
               "\n 9 -> Inserisci caratteri a stringa."
               "\n 10 -> Substring."
               "\n 11 -> Sostituisci caratteri a una certa posizione."
               "\nScelta: ");
        scanf("%d", &scelta);

        // Scelte possibili in base all'input dell'utente.
        switch (scelta) {

            case 0:{

                // Esci dal programma e dal while.
                printf("\n\nHai scelto: Esci...");

                break;
            }

            case 1:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Inserisci stringa 1...");

                // Chiedo stringa in input.
                printf("\nInserire stringa: ");
                scanf("%s", stringa);

                // Messaggio di successo.
                printf("\nStringa 1 inserita con successo!");

                continua();
                break;
            }

            case 2:{

                // Messaggio d'inizio.
                printf("\n\nHai scelto: Inserisci stringa 2...");

                // Richiedo input.
                printf("\nInserire stringa: ");
                scanf("%s", stringa2);

                // Messaggio di successo.
                printf("\nStringa 2 inserita con successo!");

                continua();
                break;
            }

            case 3:{

                // Messaggio d'inizio.
                printf("\n\nHai scelto: Confronta stringhe...");

                // Uso il compare e verifico output del metodo per dare un messaggio valido.
                if (compare(lunghezzaMassima, stringa, stringa2)){
                    printf("\nLe stringhe %s e %s sono uguali!", stringa, stringa2);
                } else {
                    printf("\nLe stringhe %s e %s sono diverse!", stringa, stringa2);
                }

                continua();
                break;
            }

            case 4:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Mostra stringa 1...");

                // Comunico output con valore stringa.w
                printf("\nValore stringa 1: %s", stringa);

                continua();
                break;
            }

            case 5:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Mostra stringa 2...");

                // Comunico valroe stringa.
                printf("\nValore stringa 2: %s", stringa2);

                continua();
                break;
            }

            case 6:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Lunghezza stringa...");

                // Variabile scelta ciclo while.
                int nStringa = 1;

                // Legenda e input utente.
                while (nStringa != 0) {
                    printf("\nScegli una delle stringhe: "
                           "\n 0 -> Esci."
                           "\n 1 -> Stringa 1."
                           "\n 2 -> Stringa 2."
                           "\nScelta: ");
                    scanf("%d", &nStringa);

                    // Menu.
                    switch (nStringa) {

                        case 0:{

                            // Esci dal menu.
                            printf("\nHai scelto: Esci...");

                            break;
                        }

                        case 1:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Stringa 1");

                            // Comunico output.
                            printf("\nLa stringa 1 ha dimensioni: %d.", dimensioni(stringa));

                            continua();
                            break;
                        }

                        case 2:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Stringa 2");

                            // Comunico output.
                            printf("\nLa stringa 2 ha dimensioni: %d", dimensioni(stringa2));

                            continua();
                            break;
                        }

                        default:{

                            // Scelta non valida.
                            printf("\nHai inserito una scelta non valida!");

                            continua();
                            break;
                        }
                    }
                }

                break;
            }

            case 7:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Unisci stringhe 1 e 2 in Stringa 1...");

                // Funzione che unisce le stringhe.
                unisci(stringa, stringa2);

                // Mostro valore nuova stringa unita.
                printf("\nUniti con successo stringa 1 e 2 in Stringa 1 -> %s", stringa);

                continua();
                break;
            }

            case 8:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Inverti valori stringa...");

                // Scelta per ciclo while.
                int nStringa = 1;

                // Ciclo while menu.
                while (nStringa != 0) {

                    // Richiedo valori in input.
                    printf("\nScegli una delle stringhe: "
                           "\n 0 -> Esci."
                           "\n 1 -> Stringa 1."
                           "\n 2 -> Stringa 2."
                           "\nScelta: ");
                    scanf("%d", &nStringa);

                    // Menu.
                    switch (nStringa) {

                        case 0:{

                            // Esci dal menu.
                            printf("\nHai scelto: Esci...");

                            break;
                        }

                        case 1:{

                            // Messaggi d'inizio.
                            printf("\nHai scelto: Stringa 1");

                            // Richiamo funzione.
                            inverti(lunghezzaMassima, stringa);

                            // Comunico output.
                            printf("\nStringa 1 invertita con successo! Valore: %s", stringa);
                            continua();
                            break;
                        }

                        case 2:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Stringa 2");

                            // Richiamo funzione.
                            inverti(lunghezzaMassima, stringa2);

                            // Comunico output.
                            printf("\nStringa 2 invertita con successo! Valore: %s", stringa2);
                            continua();
                            break;
                        }

                        default:{

                            // Comunico errore e scelta non valida.
                            printf("\nHai inserito una scelta non valida!");

                            continua();
                            break;
                        }
                    }
                }

                break;
            }

            case 9:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Inserisci caratteri...");

                // Variabile per menu.
                int nStringa = 1;

                // Ciclo while per menu.
                while (nStringa != 0) {

                    // Legenda e input menu.
                    printf("\nScegli una delle stringhe: "
                           "\n 0 -> Esci."
                           "\n 1 -> Stringa 1."
                           "\n 2 -> Stringa 2."
                           "\nScelta: ");
                    scanf("%d", &nStringa);

                    // Menu.
                    switch (nStringa) {

                        case 0:{

                            // Esci dal menu.
                            printf("\nHai scelto: Esci...");

                            break;
                        }

                        case 1:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Stringa 1");

                            // Variabile temporanea.
                            char stringaTmp[100];

                            // Chiedo input valroe da unire.
                            printf("\nInserisci qualcosa: ");
                            scanf("%s", stringaTmp);

                            // Richiamo funzione.
                            unisci(stringa, stringaTmp);

                            // Comunico nuova stringa.
                            printf("\nStringa 1 unita con i nuovi caratteri con successo! Valore: %s", stringa);
                            continua();
                            break;
                        }

                        case 2:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Stringa 2");

                            // Variabile temporanea.
                            char stringaTmp[100];

                            // Richiedo valore da unire in ingresso.
                            printf("\nInserisci qualcosa: ");
                            scanf("%s", stringaTmp);

                            // Richiamo funzione.
                            unisci(stringa2, stringaTmp);

                            // Comunico nuova stringa.
                            printf("\nStringa 2 unita con i nuovi caratteri con successo! Valore: %s", stringa2);
                            continua();
                            break;
                        }

                        default:{

                            // Comunico errore scelta non valida.
                            printf("\nHai inserito una scelta non valida!");

                            continua();
                            break;
                        }
                    }
                }

                break;
            }

            case 10:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Substring...");

                // Variabile per menu.
                int nStringa = 1;

                // Ciclo per menu.
                while (nStringa != 0) {

                    // Legenda menu e input.
                    printf("\nScegli una delle stringhe: "
                           "\n 0 -> Esci."
                           "\n 1 -> Stringa 1."
                           "\n 2 -> Stringa 2."
                           "\nScelta: ");
                    scanf("%d", &nStringa);

                    // Menu.
                    switch (nStringa) {

                        case 0:{

                            // Esco dal menu.
                            printf("\nHai scelto: Esci...");

                            break;
                        }

                        case 1:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Stringa 1");

                            // Inizializzo variabile.
                            int numeroSub;

                            // Richiedo valore numero caratteri subString.
                            printf("\nInserire numero caratteri: ");
                            scanf("%d", &numeroSub);

                            // Comunico output in preparazione.
                            printf("\nStringa 1 con Substring di %d -> ", numeroSub);

                            // Richiamo funzione.
                            subString(stringa, numeroSub);

                            // Comunico valore stringa con substring.
                            printf("%s", stringa);

                            continua();
                            break;
                        }

                        case 2:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Stringa 2");

                            // Inizializzo variabile.
                            int numeroSub;

                            // Chiedo in input numero caratteri SubString.
                            printf("\nInserire numero caratteri: ");
                            scanf("%d", &numeroSub);

                            // Inizio a comunicare valore in uscita e preparazione.
                            printf("\nStringa 2 con Substring di %d -> ", numeroSub);

                            // Richiamo funzione.
                            subString(stringa2, numeroSub);

                            // Comunico valore stringa con subString.
                            printf("%s", stringa2);

                            continua();
                            break;
                        }

                        default:{

                            // Comunico errore valore scelta non valido.
                            printf("\nHai inserito una scelta non valida!");

                            continua();
                            break;
                        }
                    }
                }

                break;
            }

            case 11:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Inserisci a una certa posizione/replace.");

                // Variabile per menu.
                int nStringa = 1;

                // Ciclo menu.
                while (nStringa != 0) {

                    // Legenda e chiedo input.
                    printf("\nScegli una delle stringhe: "
                           "\n 0 -> Esci."
                           "\n 1 -> Stringa 1."
                           "\n 2 -> Stringa 2."
                           "\nScelta: ");
                    scanf("%d", &nStringa);

                    // Menu.
                    switch (nStringa) {

                        case 0:{

                            // Esci dal menu.
                            printf("\nHai scelto: Esci...");

                            break;
                        }

                        case 1:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Stringa 1");

                            // Inizializzo variabile.
                            int posMod;

                            // Chiedo input utente.
                            printf("\nInserire posizione dopo il cui modificare: ");
                            scanf("%d", &posMod);

                            // Stringa in entrata, variabile.
                            char stringaDaIns[100];

                            // Chiedo valore da sostituire.
                            printf("\nInserire parte da inserire: ");
                            scanf("%s", stringaDaIns);

                            // Richiamo funzione.
                            replace(stringa, posMod, stringaDaIns);

                            // Comunico nuovo valore in output.
                            printf("\nStringa 1 modificata con successo! Valore: %s", stringa);
                            continua();
                            break;
                        }

                        case 2:{

                            // Messaggio d'inizio.
                            printf("\nHai scelto: Stringa 2");

                            // Inizializzo variabile.
                            int posMod;

                            // Chiedo input.
                            printf("\nInserire posizione dopo il cui modificare: ");
                            scanf("%d", &posMod);

                            // Inzializzo variabile.
                            char stringaDaIns[100];

                            // Chiedo input.
                            printf("\nInserire parte da inserire: ");
                            scanf("%s", stringaDaIns);

                            // Richiamo funzione.
                            replace(stringa2, posMod, stringaDaIns);

                            // Messaggio di output con nuovo valore stringa.
                            printf("\nStringa 2 modificata con successo! Valore: %s", stringa2);
                            continua();
                            break;
                        }

                        default:{

                            // Errore scelta non valida.
                            printf("\nHai inserito una scelta non valida!");

                            continua();
                            break;
                        }
                    }
                }

                break;
            }

            default:{

                // Errore scelta non valida.
                printf("\nHai inserito una scelta non valida.");

                continua();
                break;
            }
        }
    }

    // Comunico chiusura con successo.
    printf("\nEsercizio chiuso con successo!");

    return 0;
}

void replace(char stringa[], int posMod, char stringaDaIns[]) {
    // Ciclo for con logica per il replace.
    for (int i = 0; i < dimensioni(stringaDaIns); i++) {
        stringa[posMod + i] = stringaDaIns[i];
    }
}

void subString(char stringa[], int numeroSub) {

    // Variabili temporanee.
    char stringaSub[100];
    int posSub = 0;

    // Ciclo for con logica.
    for (int i = numeroSub; i < dimensioni(stringa); ++i) {
        stringaSub[posSub] = stringa[i];
        posSub++;
    }

    // Assegno alla stringa iniziale il valore di quella temporanea.
    for (int i = 0; i < dimensioni(stringa); i++) {
        stringa[i] = stringaSub[i];
    }
}

void inverti(int lunghezzaMassima, char stringa[]) {

    // Inizializzo variabili temporanee.
    char temp[lunghezzaMassima];
    int j = 0, dimensioniS = dimensioni(stringa);

    // Ciclo for con logica.
    for (int i = dimensioniS; i > 0; i--) {
        temp[j] = stringa[i-1];
        j++;
    }

    // Assegno valore alla stringa di temp.
    for (int i = 0; i < dimensioniS; i++) {
        stringa[i] = temp[i];
    }
}

void unisci(char stringa[], char stringa2[]) {

    // Inizializzo varibili temporanee.
    int lungStr1 = dimensioni(stringa);
    int lungStr2 = dimensioni(stringa2);

    // Ciclo for con logica.
    for (int i = 0; i < lungStr2; ++i) {
        stringa[lungStr1 + i] = stringa2[i];
    }

}

int dimensioni(char stringa[]) {

    // Variabile temporanea.
    char nullo[2] = "\0";

    int i = 0;
    // Ciclo con logica.
    while (stringa[i] != nullo[1]){
        i++;
    }
    return i;
}

// Ritorna true se sono uguali.
bool compare(int lunghezzaMassima, char stringa[], char stringa2[]) {

    // Ciclo for con logica.
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