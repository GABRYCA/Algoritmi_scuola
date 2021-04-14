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
           "\n//           Records di Gabriele Caretti 3BITI              //"
           "\n//////////////////////////////////////////////////////////////\n");

    struct clientData blankData = {0, "", "", 0.0};
    struct clientData client{};

    int scelta = 1;
    FILE *cfPtr;

    while (scelta != 0){

        printf("\nScegli cosa fare: "
               "\n0 -> Esci."
               "\n1 -> Inizializza Records."
               "\n2 -> Modifica qualcosa nel Record."
               "\n3 -> Lettura Record."
               "\nScelta: ");
        scanf("%d", &scelta);

        // fopen wb inizializza, wb+ ci scrive anche se inizializzato in precedenza.

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\n\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Inizializza File records...");

                cfPtr = fopen("clienti.txt", "wb");

                for (int i = 0; i < 100; i++) {
                    fseek(cfPtr, i * sizeof(struct clientData), SEEK_SET);
                    fwrite(&blankData, sizeof(struct clientData), 1, cfPtr);
                }

                fclose(cfPtr);
                printf("\n\nInizializzato con successo.");

                continua();
                break;
            }

            case 2:{

                printf("\nHai scelto: Modifica una record...\n");

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

                if (numeroRecord != 0){

                    FILE *cfTempR = fopen("clienti.txt", "rb+");
                    cfPtr = fopen("clienti2.txt", "wb+");

                    struct clientData temporaneo{};

                    if (cfTempR != NULL && cfPtr != NULL){

                        // Copio i valori precedenti.
                        /*
                        for (int i = 0; i < numeroRecord-1; i++) {

                            // Imposto posizioni in cui leggere o scrivere per la copia.
                            fseek(cfTempR, i * sizeof(struct clientData), SEEK_SET);
                            fseek(cfPtr, i * sizeof(struct clientData), SEEK_SET);

                            // Leggo dal file iniziali il valore e lo salvo nel file nuovo.
                            fread(&temporaneo, sizeof(struct clientData), 1, cfTempR);
                            fwrite(&temporaneo, sizeof(struct clientData), 1, cfPtr);
                        }*/

                        // Per ogni possibile posizione faccio un ciclo.
                        for (int i = 0; i < 100; i++) {

                            // Se la posizione non è quella da modificare, allora copio i valori.
                            if (i != numeroRecord - 1){

                                // Imposto posizioni in cui leggere o scrivere per la copia.
                                fseek(cfTempR, i * sizeof(struct clientData), SEEK_SET);
                                fseek(cfPtr, i * sizeof(struct clientData), SEEK_SET);

                                // Leggo dal file iniziali il valore e lo salvo nel file nuovo.
                                fread(&temporaneo, sizeof(struct clientData), 1, cfTempR);
                                fwrite(&temporaneo, sizeof(struct clientData), 1, cfPtr);

                            // Se è quella da modificare, scrivo il nuovo valore.
                            } else {

                                // Scrivo nel file temporaneo il valore da aggiungere o modificare alla posizione data.
                                fseek(cfPtr, (numeroRecord - 1) * sizeof(struct clientData), SEEK_SET);
                                fwrite(&client, sizeof(struct clientData), 1, cfPtr);

                            }
                        }

                        // Scrivo nel file temporaneo il valore da aggiungere o modificare alla posizione data.

                        /*fseek(cfPtr, (numeroRecord - 1) * sizeof(struct clientData), SEEK_SET);
                        fwrite(&client, sizeof(struct clientData), 1, cfPtr);

                        // Scrivo tutti i valori successivi, essenzialmente copio quelli esistenti.
                        for (int i = numeroRecord; i < 100; i++) {

                            // Imposto le posizioni da leggere.
                            fseek(cfTempR, i * sizeof(struct clientData), SEEK_SET);
                            fseek(cfPtr, i * sizeof(struct clientData), SEEK_SET);

                            // Leggo dal file vecchio il valore e lo scrivo in quello temporaneo.
                            fread(&temporaneo, sizeof(struct clientData), 1, cfTempR);
                            fwrite(&temporaneo, sizeof(struct clientData), 1, cfPtr);
                        }*/
                    }

                    /*if (cfPtr != NULL){

                        // Prima dell'fseek dovrei mettere una parta che copia la parte precedente per non perderla.

                        fseek(cfPtr, (numeroRecord - 1) * sizeof(struct clientData), SEEK_SET);

                        fwrite(&client, sizeof(struct clientData), 1, cfPtr);

                        // L'idea sarà di copiare tutto il contenuto successivo e riscriverlo per non perderlo.
                        for (int i = numeroRecord; i < 100; i++) {
                            fseek(cfPtr, i * sizeof(struct clientData), SEEK_SET);
                            fwrite(&blankData, sizeof(struct clientData), 1, cfPtr);
                        }
                    }*/

                    // Chiudo i FILEs.
                    fclose(cfPtr);
                    fclose(cfTempR);

                    // Cancello il vecchio FILE e rinomino quello temporaneo per sostituirlo.
                    remove("clienti.txt");
                    rename("clienti2.txt", "clienti.txt");

                    printf("\nSalvato con successo!");

                } else {

                    printf("\nHai inserito una posizione non valida!");

                }

                printf("\n\nOperazione conclusa.");


                continua();
                break;
            }

            case 3:{

                printf("\nHai scelto: Lettura Record...");

                int numeroLeggere;

                printf("\n\nInserire il numero della struct da leggere da 1 a 100: ");
                cin >> numeroLeggere;

                if (numeroLeggere != 0){

                    cfPtr = fopen("clienti.txt", "rb+");

                    if(cfPtr != NULL){

                        fseek(cfPtr, (numeroLeggere - 1) * sizeof(struct clientData), SEEK_SET);

                        fread(&client, sizeof(struct clientData), 1, cfPtr);

                        //fscanf(cfPtr, "%d%s%s%lf", &client.numeroConto, client.nomeProprietario, client.nomeEsecutore, &client.valore);
                        fclose(cfPtr);

                        printf("\nDati letti:"
                               "\nNumero: %d"
                               "\nProprietario %s"
                               "\nEsecutore Operazione: %s"
                               "\nValore: %lf", client.numeroConto, client.nomeProprietario, client.nomeEsecutore, client.valore);

                    } else {

                        printf("\nImpossibile aprire il FILE, forse non esiste.");

                    }


                } else {

                    printf("\nHai inserito un numero di posizione non valido!");

                }


                printf("\nOperazione terminata..");

                continua();
                break;
            }

            default:{

                printf("\n\nHai inserito un valore non valido, riprovare!");

                break;
            }
        }

    }

    printf("\n\nUscito con successo!");


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
