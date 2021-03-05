#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>

using namespace std;

void continua();

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           Verifica di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Valore bandiera.
    int scelta = 1;

    while (scelta != 0){

        struct registroDati{
            string nomeInsegnante;
            string nomeMateria;
            int oraInizio = 0;
            int oraFine = 0;
            string nomeArgomento;
            bool firmato = false;
        } registro;

        printf("\nScegliere una modalità:"
               "\n0 -> Esci."
               "\n1 -> Registro base."
               "\n2 -> Aggiungi qualcosa al registro."
               "\n3 -> Leggi registro."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscita in corso.");

                break;
            }

            case 1:{

                printf("\nHai scelto: Registro base.");

                FILE *cfRegistro;
                cfRegistro = fopen("registro.txt", "w");

                if (cfRegistro == NULL){
                    printf("\nErrore durante la crezione del file");
                    return 0;
                } else {

                    // Nome.
                    printf("\nInserire il proprio nome: ");
                    cin >> registro.nomeInsegnante;

                    bool successo = false;

                    // Materia.
                    while (!successo){
                        int nMateriaScelta;
                        printf("\n\nScegliere una materia, oppure scegliere 0 per inserire una nuova:"
                               "\n0 -> Inserisci una materia che vuoi."
                               "\n1 -> Matematica"
                               "\n2 -> Informatica"
                               "\n3 -> Telecomunicazioni"
                               "\n4 -> TPSIT"
                               "\n5 -> Sistemi"
                               "\n6 -> Educazione fisica"
                               "\n7 -> Italiano"
                               "\n8 -> Storia"
                               "\nScelta: ");
                        scanf("%d", &nMateriaScelta);

                        switch (nMateriaScelta) {
                            case 0:{

                                printf("\nInserire la materia: ");
                                cin >> registro.nomeMateria;

                                successo = true;
                                break;
                            }

                            case 1:{

                                printf("\nHai scelto: Matematica");
                                registro.nomeMateria = "Matematica";

                                successo = true;
                                break;
                            }

                            case 2:{

                                printf("\nHai scelto: Informatica");
                                registro.nomeMateria = "Informatica";

                                successo = true;
                                break;
                            }

                            case 3:{

                                printf("\nHai scelto: Telecomunicazioni");
                                registro.nomeMateria = "Telecomunicazioni";

                                successo = true;
                                break;
                            }

                            case 4:{

                                printf("\nHai scelto: TPSIT");
                                registro.nomeMateria = "TPSIT";

                                successo = true;
                                break;
                            }

                            case 5:{

                                printf("\nHai scelto: Sistemi");
                                registro.nomeMateria = "Sistemi";

                                successo = true;
                                break;
                            }

                            case 6:{

                                printf("\nHai scelto: Educazione_Fisica");
                                registro.nomeMateria = "Educazione_Fisica";

                                successo = true;
                                break;
                            }
                            case 7:{

                                printf("\nHai scelto: Italiano");
                                registro.nomeMateria = "Italiano";

                                successo = true;
                                break;
                            }

                            case 8:{

                                printf("\nHai scelto: Storia");
                                registro.nomeMateria = "Storia";

                                successo = true;
                                break;
                            }

                            default:{

                                printf("\nScelta non valida, riprovare.");

                                break;
                            }
                        }
                    }


                    // Ora

                    successo = false;
                    while (!successo) {
                        int nOraScelta;
                        printf("\n\nScegli una delle seguenti opzioni oppure inserisci il tuo: "
                               "\nNumero -> OraInizio -> OraFine"
                               "\n0 -> Inserisci il tuo orario."
                               "\n1 -> 8:00 -> 9:00"
                               "\n2 -> 9:00 -> 10:00"
                               "\n3 -> 10:00 -> 11:00"
                               "\n4 -> 11:00 -> 12:00"
                               "\n5 -> 12:00 -> 13:00"
                               "\n6 -> 13:00 -> 14:00"
                               "\nScelta: ");
                        scanf("%d", &nOraScelta);

                        switch (nOraScelta) {
                            case 0:{

                                printf("\nInserisci il tuo orario d'inizio: ");
                                cin >> registro.oraInizio;

                                printf("\nInserisci il tuo orario di fine: ");
                                cin >> registro.oraFine;

                                successo = true;
                                break;
                            }

                            case 1:{

                                printf("\nHai scelto: 8:00 -> 9.00");

                                registro.oraInizio = 8;
                                registro.oraFine = 9;

                                successo = true;
                                break;
                            }

                            case 2:{

                                printf("\nHai scelto: 9:00 -> 10:00");

                                registro.oraInizio = 9;
                                registro.oraFine = 10;

                                successo = true;
                                break;
                            }

                            case 3:{

                                printf("\nHai scelto: 10:00 -> 11:00");

                                registro.oraInizio = 10;
                                registro.oraFine = 11;

                                successo = true;
                                break;
                            }

                            case 4:{

                                printf("\nHai scelto: 11:00 -> 12:00");

                                registro.oraInizio = 11;
                                registro.oraFine = 12;

                                successo = true;
                                break;
                            }

                            case 5:{

                                printf("\nHai scelto: 12:00 -> 13:00");

                                registro.oraInizio = 12;
                                registro.oraFine = 13;

                                successo = true;
                                break;
                            }

                            case 6:{

                                printf("\nHai scelto: 13:00 -> 14:00");

                                registro.oraInizio = 13;
                                registro.oraFine = 14;

                                successo = true;
                                break;
                            }

                            default:{

                                printf("\nScelta non valida, riprova!");

                                break;
                            }
                        }
                    }

                    printf("\n\nInserire il nome dell'argomento: ");
                    cin >> registro.nomeArgomento;

                    int numeroConferma = 2;
                    while (numeroConferma != 0 && numeroConferma != 1) {
                        printf("\nVuoi firmare?"
                               "\n0 -> No."
                               "\n1 -> Si."
                               "\nScelta: ");
                        scanf("%d", &numeroConferma);

                        if (numeroConferma == 1) {
                            printf("\nFirmato con successo!");
                            registro.firmato = true;
                        } else if (numeroConferma == 0){
                            printf("\nNon hai firmato");
                            registro.firmato = false;
                        } else {
                            printf("\nHai inserito una opzione non valida, riprovare!");
                        }
                    }

                }

                printf("\nSalvataggio su file con successo!");
                if (registro.firmato) {
                    fprintf(cfRegistro, "%s %s %d %d %s %s", registro.nomeInsegnante.c_str(),
                            registro.nomeMateria.c_str(), registro.oraInizio, registro.oraFine,
                            registro.nomeArgomento.c_str(), "Firmato");
                } else {
                    fprintf(cfRegistro, "%s %s %d %d %s %s", registro.nomeInsegnante.c_str(),
                            registro.nomeMateria.c_str(), registro.oraInizio, registro.oraFine,
                            registro.nomeArgomento.c_str(), "Non_Firmato");
                }
                fclose(cfRegistro);

                cfRegistro = fopen("registro.txt", "r");

                if (cfRegistro == NULL){
                    printf("\nErrore durante l'apertura del registro!");
                } else {

                    char nomeInsegnate[100];
                    char materia[100];
                    int oraInizio;
                    int oraFine;
                    char argomento[100];
                    char firmato[100];

                    fscanf(cfRegistro, "%s %s %d %d %s %s", nomeInsegnate, materia, &oraInizio, &oraFine, argomento, firmato);

                    printf("\n\nRiepilogo: "
                           "\nNome insegnante: %s"
                           "\nNome materia: %s"
                           "\nOra di inzio: %d:00"
                           "\nOra di fine: %d:00"
                           "\nArgomento: %s"
                           "\nFirmato: %s", nomeInsegnate, materia, oraInizio, oraFine, argomento, firmato);

                    continua();
                }


                break;
            }

            case 2:{

                printf("\nHai scelto: Aggiungi qualcosa al registro...");

                FILE *cfRegistro = fopen("registro.txt", "a");

                if (cfRegistro == NULL){
                    fclose(cfRegistro);
                    cfRegistro = fopen("registro.txt", "w");
                } else {
                    fprintf(cfRegistro, "%s", "\n");
                }

                // Nome.
                printf("\nInserire il proprio nome: ");
                cin >> registro.nomeInsegnante;

                bool successo = false;

                // Materia.
                while (!successo){
                    int nMateriaScelta;
                    printf("\n\nScegliere una materia, oppure scegliere 0 per inserire una nuova:"
                           "\n0 -> Inserisci una materia che vuoi."
                           "\n1 -> Matematica"
                           "\n2 -> Informatica"
                           "\n3 -> Telecomunicazioni"
                           "\n4 -> TPSIT"
                           "\n5 -> Sistemi"
                           "\n6 -> Educazione fisica"
                           "\n7 -> Italiano"
                           "\n8 -> Storia"
                           "\nScelta: ");
                    scanf("%d", &nMateriaScelta);

                    switch (nMateriaScelta) {
                        case 0:{

                            printf("\nInserire la materia: ");
                            cin >> registro.nomeMateria;

                            successo = true;
                            break;
                        }

                        case 1:{

                            printf("\nHai scelto: Matematica");
                            registro.nomeMateria = "Matematica";

                            successo = true;
                            break;
                        }

                        case 2:{

                            printf("\nHai scelto: Informatica");
                            registro.nomeMateria = "Informatica";

                            successo = true;
                            break;
                        }

                        case 3:{

                            printf("\nHai scelto: Telecomunicazioni");
                            registro.nomeMateria = "Telecomunicazioni";

                            successo = true;
                            break;
                        }

                        case 4:{

                            printf("\nHai scelto: TPSIT");
                            registro.nomeMateria = "TPSIT";

                            successo = true;
                            break;
                        }

                        case 5:{

                            printf("\nHai scelto: Sistemi");
                            registro.nomeMateria = "Sistemi";

                            successo = true;
                            break;
                        }

                        case 6:{

                            printf("\nHai scelto: Educazione_Fisica");
                            registro.nomeMateria = "Educazione_Fisica";

                            successo = true;
                            break;
                        }
                        case 7:{

                            printf("\nHai scelto: Italiano");
                            registro.nomeMateria = "Italiano";

                            successo = true;
                            break;
                        }

                        case 8:{

                            printf("\nHai scelto: Storia");
                            registro.nomeMateria = "Storia";

                            successo = true;
                            break;
                        }

                        default:{

                            printf("\nScelta non valida, riprovare.");

                            break;
                        }
                    }
                }


                // Ora

                successo = false;
                while (!successo) {
                    int nOraScelta;
                    printf("\n\nScegli una delle seguenti opzioni oppure inserisci il tuo: "
                           "\nNumero -> OraInizio -> OraFine"
                           "\n0 -> Inserisci il tuo orario."
                           "\n1 -> 8:00 -> 9:00"
                           "\n2 -> 9:00 -> 10:00"
                           "\n3 -> 10:00 -> 11:00"
                           "\n4 -> 11:00 -> 12:00"
                           "\n5 -> 12:00 -> 13:00"
                           "\n6 -> 13:00 -> 14:00"
                           "\nScelta: ");
                    scanf("%d", &nOraScelta);

                    switch (nOraScelta) {
                        case 0:{

                            printf("\nInserisci il tuo orario d'inizio: ");
                            cin >> registro.oraInizio;

                            printf("\nInserisci il tuo orario di fine: ");
                            cin >> registro.oraFine;

                            successo = true;
                            break;
                        }

                        case 1:{

                            printf("\nHai scelto: 8:00 -> 9.00");

                            registro.oraInizio = 8;
                            registro.oraFine = 9;

                            successo = true;
                            break;
                        }

                        case 2:{

                            printf("\nHai scelto: 9:00 -> 10:00");

                            registro.oraInizio = 9;
                            registro.oraFine = 10;

                            successo = true;
                            break;
                        }

                        case 3:{

                            printf("\nHai scelto: 10:00 -> 11:00");

                            registro.oraInizio = 10;
                            registro.oraFine = 11;

                            successo = true;
                            break;
                        }

                        case 4:{

                            printf("\nHai scelto: 11:00 -> 12:00");

                            registro.oraInizio = 11;
                            registro.oraFine = 12;

                            successo = true;
                            break;
                        }

                        case 5:{

                            printf("\nHai scelto: 12:00 -> 13:00");

                            registro.oraInizio = 12;
                            registro.oraFine = 13;

                            successo = true;
                            break;
                        }

                        case 6:{

                            printf("\nHai scelto: 13:00 -> 14:00");

                            registro.oraInizio = 13;
                            registro.oraFine = 14;

                            successo = true;
                            break;
                        }

                        default:{

                            printf("\nScelta non valida, riprova!");

                            break;
                        }
                    }
                }

                printf("\n\nInserire il nome dell'argomento: ");
                cin >> registro.nomeArgomento;

                int numeroConferma = 2;
                while (numeroConferma != 0 && numeroConferma != 1) {
                    printf("\nVuoi firmare?"
                           "\n0 -> No."
                           "\n1 -> Si."
                           "\nScelta: ");
                    scanf("%d", &numeroConferma);

                    if (numeroConferma == 1) {
                        printf("\nFirmato con successo!");
                        registro.firmato = true;
                    } else if (numeroConferma == 0){
                        printf("\nNon hai firmato");
                        registro.firmato = false;
                    } else {
                        printf("\nHai inserito una opzione non valida, riprovare!");
                    }
                }

                printf("\nSalvataggio su file con successo!");
                if (registro.firmato) {
                    fprintf(cfRegistro, "%s %s %d %d %s %s", registro.nomeInsegnante.c_str(),
                            registro.nomeMateria.c_str(), registro.oraInizio, registro.oraFine,
                            registro.nomeArgomento.c_str(), "Firmato");
                } else {
                    fprintf(cfRegistro, "%s %s %d %d %s %s", registro.nomeInsegnante.c_str(),
                            registro.nomeMateria.c_str(), registro.oraInizio, registro.oraFine,
                            registro.nomeArgomento.c_str(), "Non_Firmato");
                }
                fclose(cfRegistro);

                cfRegistro = fopen("registro.txt", "r");

                if (cfRegistro == NULL){
                    printf("\nErrore durante l'apertura del file.");
                } else {

                    int numeroRiepilogo = 0;

                    printf("\n\n|---------------------------------------------------------|"
                           "\nRiepilogo generale: ");
                    while (!feof(cfRegistro)){

                        numeroRiepilogo++;

                        char nomeInsegnate[100];
                        char materia[100];
                        int oraInizio;
                        int oraFine;
                        char argomento[100];
                        char firmato[100];

                        fscanf(cfRegistro, "%s %s %d %d %s %s", nomeInsegnate, materia, &oraInizio, &oraFine, argomento, firmato);

                        printf("\n\nRiepilogo %d: "
                               "\nNome insegnante: %s"
                               "\nNome materia: %s"
                               "\nOra di inzio: %d:00"
                               "\nOra di fine: %d:00"
                               "\nArgomento: %s"
                               "\nFirmato: %s", numeroRiepilogo, nomeInsegnate, materia, oraInizio, oraFine, argomento, firmato);

                    }

                    printf("\n|---------------------------------------------------------|");
                }

                continua();
                break;
            }

            case 3:{

                printf("\nHai scelto: Lettura registro...");

                FILE *cfRegistro;
                cfRegistro = fopen("registro.txt", "r");

                if (cfRegistro == NULL){
                    printf("\nErrore durante l'apertura del file.");
                } else {

                    int numeroRiepilogo = 0;

                    printf("\n\n|---------------------------------------------------------|"
                           "\nRiepilogo generale: ");
                    while (!feof(cfRegistro)){

                        numeroRiepilogo++;

                        char nomeInsegnate[100];
                        char materia[100];
                        int oraInizio;
                        int oraFine;
                        char argomento[100];
                        char firmato[100];

                        fscanf(cfRegistro, "%s %s %d %d %s %s", nomeInsegnate, materia, &oraInizio, &oraFine, argomento, firmato);

                        printf("\n\nRiepilogo %d: "
                               "\nNome insegnante: %s"
                               "\nNome materia: %s"
                               "\nOra di inzio: %d:00"
                               "\nOra di fine: %d:00"
                               "\nArgomento: %s"
                               "\nFirmato: %s", numeroRiepilogo, nomeInsegnate, materia, oraInizio, oraFine, argomento, firmato);

                    }

                    printf("\n|---------------------------------------------------------|");
                }

                continua();
                break;
            }

            default:{

                printf("\nScelta non valida, per favore riprovare!");

                break;
            }
        }

    }

    printf("\nUscito con successo.");

    return 0;
}

void continua(){

    // Variabile inutile per evitare errori.
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}


