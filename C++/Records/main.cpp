#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

void continua();

struct clientData{
    int numeroConto;
    char nomeProprietario[20];
    char nomeEsecutore[20];
    double valore;
};

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           Records di G.C. 3BITI              //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Dichiaro struct.
    struct clientData blankData = {0, "", "", 0.0};
    struct clientData client{};

    // Inizializzo puntatore FILE e variabile scelte.
    int scelta = 1;
    FILE *cfPtr;

    // Ciclo che continua fino ad input = 0.
    while (scelta != 0){

        // Legenda.
        printf("\nScegli cosa fare: "
               "\n0 -> Esci."
               "\n1 -> Inizializza Records."
               "\n2 -> Modifica qualcosa nel Record."
               "\n3 -> Lettura Record."
               "\n4 -> Cancella qualcosa del record."
               "\nScelta: ");
        scanf("%d", &scelta);

        // fopen wb inizializza, wb+ ci scrive anche se inizializzato in precedenza.

        // Switch tra le scelte.
        switch (scelta) {

            case 0:{

                // Messaggio opzione uscita scelta.
                printf("\nHai scelto: Esci..."
                       "\n\nUscita in corso...");

                break;
            }

            case 1:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Inizializza File records...");

                // Apro il FILE nuovo.
                cfPtr = fopen("clienti.txt", "wb");

                // Inizializzo i valori nel FILE.
                for (int i = 0; i < 100; i++) {
                    fseek(cfPtr, i * sizeof(struct clientData), SEEK_SET);
                    fwrite(&blankData, sizeof(struct clientData), 1, cfPtr);
                }

                // Chiudo il FILE e comunico FINE operazione.
                fclose(cfPtr);
                printf("\n\nInizializzato con successo.");

                // Pausa.
                continua();
                break;
            }

            case 2:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Modifica una record...\n");

                // Dichiaro variabile e la chiedo all'utente.
                int numeroRecord;
                printf("\nInserire numero Record/Posizione: ");
                cin >> numeroRecord;

                printf("\nInserire il numero di conto: ");
                cin >> client.numeroConto;

                printf("\nInserire nome proprietario: ");
                cin >> client.nomeProprietario;

                printf("\nInserire nome di chi esegue l'operazione: ");
                cin >> client.nomeEsecutore;

                printf("\nInserire valore: ");
                cin >> client.valore;

                // Verifico che il valore sia valido e non minore del minimo.
                if (numeroRecord != 0){

                    // Apro il file e uno temporaneo.
                    cfPtr = fopen("clienti.txt", "rb+");

                    // Verifico che il FILE esista.
                    if (cfPtr != NULL){

                        // Scrivo il valore.
                        fseek(cfPtr, (numeroRecord - 1) * sizeof(struct clientData), SEEK_SET);
                        fwrite(&client, sizeof(struct clientData), 1, cfPtr);

                        // Messaggio di successo.
                        printf("\nSalvato con successo!");

                    } else {

                        // Errore.
                        printf("\nErrore: FILE inesistente o non trovato!");

                    }

                    // Chiudo il FILE.
                    fclose(cfPtr);

                } else {

                    // Errore di posizione.
                    printf("\nHai inserito una posizione non valida!");

                }

                // Fine operazione.
                printf("\n\nOperazione conclusa.");

                // Pausa.
                continua();
                break;
            }

            case 3:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Lettura Record...");

                // Variabile e richiesta Input utente.
                int numeroLeggere;
                printf("\n\nInserire il numero della struct da leggere da 1 a 100: ");
                cin >> numeroLeggere;

                // Verifica che sia diverso da 0 la posizione.
                if (numeroLeggere != 0){

                    // Apro il FILE.
                    cfPtr = fopen("clienti.txt", "rb");

                    // Verifico che esista e faccio operazioni.
                    if(cfPtr != NULL){

                        // Leggo il valore.
                        fseek(cfPtr, (numeroLeggere - 1) * sizeof(struct clientData), SEEK_SET);
                        fread(&client, sizeof(struct clientData), 1, cfPtr);

                        //fscanf(cfPtr, "%d%s%s%lf", &client.numeroConto, client.nomeProprietario, client.nomeEsecutore, &client.valore);
                        fclose(cfPtr);

                        // Comunico dati letti.
                        printf("\nDati letti:"
                               "\nNumero: %d"
                               "\nProprietario %s"
                               "\nEsecutore Operazione: %s"
                               "\nValore: %lf", client.numeroConto, client.nomeProprietario, client.nomeEsecutore, client.valore);

                    } else {

                        // Errore.
                        printf("\nImpossibile aprire il FILE, forse non esiste.");

                    }


                } else {

                    // Posizione scelta non valida.
                    printf("\nHai inserito un numero di posizione non valido!");

                }


                // Messaggio fine operazione.
                printf("\nOperazione terminata..");


                // PAUSA.
                continua();
                break;
            }

            case 4:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Cancella qualcosa...");

                // Variabile posizione e richiesta input utente.
                int posizione;
                printf("\n\nInserire posizione dato da cancellare: ");
                scanf("%d", &posizione);

                // Verifico che la posizione sia valida.
                if (posizione != 0) {

                    // Apro il FILE.
                    cfPtr = fopen("clienti.txt", "rb+");

                    // Verifico che il FILE esista.
                    if (cfPtr != NULL){

                        // Scrivo il valore.
                        fseek(cfPtr, (posizione - 1) * sizeof(struct clientData), SEEK_SET);
                        fwrite(&blankData, sizeof(struct clientData), 1, cfPtr);

                        // Messaggio di successo.
                        printf("\nSalvato con successo!");

                    } else {

                        // Errore.
                        printf("\nErrore: FILE inesistente o non trovato!");

                    }

                    // Comunico messaggio di successo e chiudo il FILE.
                    printf("\nDato elimato con successo alla posizione %d.", posizione);
                    fclose(cfPtr);

                } else {

                    // Comunico errore posizione.
                    printf("\nPosizione non valida.");

                }

                // Chiedo se continuare, pausa.
                continua();
                break;
            }

            default:{

                // Comunico scelta non valida.
                printf("\n\nHai inserito un valore non valido, riprovare!");

                break;
            }
        }

    }

    // Messaggio di chiusura con successo.
    printf("\n\nUscito con successo!");

    // FINE.
    return 0;
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\n|--------------------------"
           "\n| Inserisci un NUMERO a caso per continuare...");
    scanf("%d", &inusato);
    printf("|--------------------------\n");

}
