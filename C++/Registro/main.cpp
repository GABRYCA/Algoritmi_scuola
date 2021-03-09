#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>

using namespace std;

void continua();

void letturaFileRegistro();

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           Verifica di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Valore bandiera.
    int scelta = 1;

    while (scelta != 0){

        struct ora{
            int ora = 0, minuti = 00;
        };

        struct registroDati{
            string nomeInsegnante;
            string nomeMateria;
            ora oraInizio;
            ora oraFine;
            string nomeArgomento;
            bool firmato = false;
            string classe;
        } registro;

        printf("\nScegliere una modalità:"
               "\n0 -> Esci."
               "\n1 -> Registro base."
               "\n2 -> Aggiungi qualcosa al registro."
               "\n3 -> Leggi registro."
               "\n4 -> Esperimenti con i FILE."
               "\n5 -> Leggi registro per insegnante."
               "\n6 -> Leggi registro per materia."
               "\n7 -> Leggi registro per classe."
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
                                cin >> registro.oraInizio.ora;

                                printf("\nInserisci il tuo orario di fine: ");
                                cin >> registro.oraFine.ora;

                                if (registro.oraInizio.ora > 24 || registro.oraFine.ora > 24 || registro.oraInizio.ora < 0 || registro.oraFine.ora < 0){
                                    printf("\nHai inserito un'ora non valida!");
                                    successo = false;
                                } else {
                                    printf("\nOra inserita con successo!");
                                    successo = true;
                                }
                                break;
                            }

                            case 1:{

                                printf("\nHai scelto: 8:00 -> 9.00");

                                registro.oraInizio.ora = 8;
                                registro.oraFine.ora = 9;

                                successo = true;
                                break;
                            }

                            case 2:{

                                printf("\nHai scelto: 9:00 -> 10:00");

                                registro.oraInizio.ora = 9;
                                registro.oraFine.ora = 10;

                                successo = true;
                                break;
                            }

                            case 3:{

                                printf("\nHai scelto: 10:00 -> 11:00");

                                registro.oraInizio.ora = 10;
                                registro.oraFine.ora = 11;

                                successo = true;
                                break;
                            }

                            case 4:{

                                printf("\nHai scelto: 11:00 -> 12:00");

                                registro.oraInizio.ora = 11;
                                registro.oraFine.ora = 12;

                                successo = true;
                                break;
                            }

                            case 5:{

                                printf("\nHai scelto: 12:00 -> 13:00");

                                registro.oraInizio.ora = 12;
                                registro.oraFine.ora = 13;

                                successo = true;
                                break;
                            }

                            case 6:{

                                printf("\nHai scelto: 13:00 -> 14:00");

                                registro.oraInizio.ora = 13;
                                registro.oraFine.ora = 14;

                                successo = true;
                                break;
                            }

                            default:{

                                printf("\nScelta non valida, riprova!");
                                successo = false;
                                break;
                            }
                        }
                    }

                    bool sceltaValida = false;
                    while (!sceltaValida){

                        int sceltaMinuti;
                        printf("\nVuoi inserire un minuto di inizio?"
                               "\nFormato: XX (esempio 43 minuti)."
                               "\n0 -> Lascia 00 di default."
                               "\nQualsiasi valore valido diverso da 0 sara' i minuti di inizio."
                               "\nValore inserito: ");
                        scanf("%d", &sceltaMinuti);

                        if (sceltaMinuti != 0){
                            if (sceltaMinuti > 60){
                                printf("\nHai inserito un minuto troppo alto!");
                                sceltaValida = false;
                            } else if (sceltaMinuti < 0){
                                printf("\nHai inserito un minuto troppo basso!");
                                sceltaValida = false;
                            } else {
                                registro.oraInizio.minuti = sceltaMinuti;
                                sceltaValida = true;
                            }
                        } else {
                            sceltaValida = true;
                        }
                    }

                    sceltaValida = false;
                    while (!sceltaValida){

                        int sceltaMinuti;
                        printf("\nVuoi inserire un minuto di fine?"
                               "\nFormato: XX (esempio 43 minuti)."
                               "\n0 -> Lascia 00 di default."
                               "\nQualsiasi valore valido diverso da 0 sara' i minuti di fine."
                               "\nValore inserito: ");
                        scanf("%d", &sceltaMinuti);

                        if (sceltaMinuti != 0){
                            if (sceltaMinuti > 60){
                                printf("\nHai inserito un minuto troppo alto!");
                                sceltaValida = false;
                            } else if (sceltaMinuti < 0){
                                printf("\nHai inserito un minuto troppo basso!");
                                sceltaValida = false;
                            } else {
                                registro.oraFine.minuti = sceltaMinuti;
                                sceltaValida = true;
                            }
                        } else {
                            sceltaValida = true;
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

                printf("\nInserire il nome della classe: ");
                cin >> registro.classe;

                printf("\nClasse inserita con successo!");

                printf("\n\nSalvataggio su file con successo!");
                if (registro.firmato) {
                    fprintf(cfRegistro, "%s %s %d %d %d %d %s %s %s", registro.nomeInsegnante.c_str(),
                            registro.nomeMateria.c_str(), registro.oraInizio.ora, registro.oraInizio.minuti, registro.oraFine.ora,
                            registro.oraFine.minuti, registro.nomeArgomento.c_str(), "Firmato", registro.classe.c_str());
                } else {
                    fprintf(cfRegistro, "%s %s %d %d %d %d %s %s %s", registro.nomeInsegnante.c_str(),
                            registro.nomeMateria.c_str(), registro.oraInizio.ora, registro.oraInizio.minuti, registro.oraFine.ora, registro.oraFine.minuti,
                            registro.nomeArgomento.c_str(), "Non_Firmato", registro.classe.c_str());
                }
                fclose(cfRegistro);

                cfRegistro = fopen("registro.txt", "r");

                if (cfRegistro == NULL){
                    printf("\nErrore durante l'apertura del registro!");
                } else {

                    char nomeInsegnate[100];
                    char materia[100];
                    int oraInizio;
                    int minutiInizio;
                    int oraFine;
                    int minutiFine;
                    char argomento[100];
                    char firmato[100];
                    char classe[100];

                    fscanf(cfRegistro, "%s %s %d %d %d %d %s %s %s", nomeInsegnate, materia, &oraInizio, &minutiInizio, &oraFine, &minutiFine, argomento, firmato, classe);

                    printf("\n\nRiepilogo: "
                           "\nNome insegnante: %s"
                           "\nNome materia: %s"
                           "\nOra di inzio: %d:%d"
                           "\nOra di fine: %d:%d"
                           "\nArgomento: %s"
                           "\nFirmato: %s"
                           "\nClasse %s", nomeInsegnate, materia, oraInizio, minutiInizio, oraFine, minutiFine, argomento, firmato, classe);

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
                            cin >> registro.oraInizio.ora;

                            printf("\nInserisci il tuo orario di fine: ");
                            cin >> registro.oraFine.ora;

                            if (registro.oraInizio.ora > 24 || registro.oraFine.ora > 24 || registro.oraInizio.ora < 0 || registro.oraFine.ora < 0){
                                printf("\nHai inserito un'ora non valida!");
                                successo = false;
                            } else {
                                printf("\nOra inserita con successo!");
                                successo = true;
                            }
                            break;
                        }

                        case 1:{

                            printf("\nHai scelto: 8:00 -> 9.00");

                            registro.oraInizio.ora = 8;
                            registro.oraFine.ora = 9;

                            successo = true;
                            break;
                        }

                        case 2:{

                            printf("\nHai scelto: 9:00 -> 10:00");

                            registro.oraInizio.ora = 9;
                            registro.oraFine.ora = 10;

                            successo = true;
                            break;
                        }

                        case 3:{

                            printf("\nHai scelto: 10:00 -> 11:00");

                            registro.oraInizio.ora = 10;
                            registro.oraFine.ora = 11;

                            successo = true;
                            break;
                        }

                        case 4:{

                            printf("\nHai scelto: 11:00 -> 12:00");

                            registro.oraInizio.ora = 11;
                            registro.oraFine.ora = 12;

                            successo = true;
                            break;
                        }

                        case 5:{

                            printf("\nHai scelto: 12:00 -> 13:00");

                            registro.oraInizio.ora = 12;
                            registro.oraFine.ora = 13;

                            successo = true;
                            break;
                        }

                        case 6:{

                            printf("\nHai scelto: 13:00 -> 14:00");

                            registro.oraInizio.ora = 13;
                            registro.oraFine.ora = 14;

                            successo = true;
                            break;
                        }

                        default:{

                            printf("\nScelta non valida, riprova!");
                            successo = false;
                            break;
                        }
                    }
                }

                bool sceltaValida = false;
                while (!sceltaValida){

                    int sceltaMinuti;
                    printf("\nVuoi inserire un minuto di inizio?"
                           "\nFormato: XX (esempio 43 minuti)."
                           "\n0 -> Lascia 00 di default."
                           "\nQualsiasi valore valido diverso da 0 sara' i minuti di inizio."
                           "\nValore inserito: ");
                    scanf("%d", &sceltaMinuti);

                    if (sceltaMinuti != 0){
                        if (sceltaMinuti > 60){
                            printf("\nHai inserito un minuto troppo alto!");
                            sceltaValida = false;
                        } else if (sceltaMinuti < 0){
                            printf("\nHai inserito un minuto troppo basso!");
                            sceltaValida = false;
                        } else {
                            registro.oraInizio.minuti = sceltaMinuti;
                            sceltaValida = true;
                        }
                    } else {
                        sceltaValida = true;
                    }
                }

                sceltaValida = false;
                while (!sceltaValida){

                    int sceltaMinuti;
                    printf("\nVuoi inserire un minuto di fine?"
                           "\nFormato: XX (esempio 43 minuti)."
                           "\n0 -> Lascia 00 di default."
                           "\nQualsiasi valore valido diverso da 0 sara' i minuti di fine."
                           "\nValore inserito: ");
                    scanf("%d", &sceltaMinuti);

                    if (sceltaMinuti != 0){
                        if (sceltaMinuti > 60){
                            printf("\nHai inserito un minuto troppo alto!");
                            sceltaValida = false;
                        } else if (sceltaMinuti < 0){
                            printf("\nHai inserito un minuto troppo basso!");
                            sceltaValida = false;
                        } else {
                            registro.oraFine.minuti = sceltaMinuti;
                            sceltaValida = true;
                        }
                    } else {
                        sceltaValida = true;
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

                printf("\nInserire il nome della classe: ");
                cin >> registro.classe;

                printf("\nClasse inserita con successo!");

                printf("\n\nSalvataggio su file con successo!");
                if (registro.firmato) {
                    fprintf(cfRegistro, "%s %s %d %d %d %d %s %s %s", registro.nomeInsegnante.c_str(),
                            registro.nomeMateria.c_str(), registro.oraInizio.ora, registro.oraInizio.minuti, registro.oraFine.ora,
                            registro.oraFine.minuti, registro.nomeArgomento.c_str(), "Firmato", registro.classe.c_str());
                } else {
                    fprintf(cfRegistro, "%s %s %d %d %d %d %s %s %s", registro.nomeInsegnante.c_str(),
                            registro.nomeMateria.c_str(), registro.oraInizio.ora, registro.oraInizio.minuti, registro.oraFine.ora, registro.oraFine.minuti,
                            registro.nomeArgomento.c_str(), "Non_Firmato", registro.classe.c_str());
                }
                fclose(cfRegistro);

                // Riepilogo
                letturaFileRegistro();

                continua();
                break;
            }

            case 3:{

                printf("\nHai scelto: Lettura registro...");

                letturaFileRegistro();

                continua();
                break;
            }

            case 4:{

                printf("\nHai scelto: Esperimento su FILEs...");

                int sceltaEsperimento = 1;
                while (sceltaEsperimento != 0) {
                    printf("\n\nScegli una delle opzioni: "
                           "\n0 -> Esci."
                           "\n1 -> Crea un FILE vuoto."
                           "\n2 -> Aggiungi una linea di testo al file da un altro file."
                           "\n3 -> Leggi il FILE con fgetc."
                           "\nScelta: ");
                    scanf("%d", &sceltaEsperimento);

                    switch (sceltaEsperimento) {

                        case 0:{

                            printf("\nHai scelto: Esci..."
                                   "\nUscita in corso...");

                            break;
                        }

                        case 1:{

                            printf("\nHai scelto: crea un FILE vuoto.");

                            string nomeFile;
                            printf("\nInserire il nome file (Esempio: prova.txt): ");
                            cin >> nomeFile;

                            FILE *cfFile;
                            cfFile = fopen(nomeFile.c_str(), "w");

                            fclose(cfFile);

                            printf("\nFile vuoto creato con successo!");
                            break;
                        }

                        case 2:{

                            printf("\nHai scelto: Aggiungi una linea di testo al file.");

                            // Variabili
                            string nomeFile;
                            string nomeFileOrigine;
                            char lineaDaScrivere;

                            printf("\nInserire il nome del file su cui scrivere: ");
                            cin >> nomeFile;

                            printf("\nInserire il nome del file di origine: ");
                            cin >> nomeFileOrigine;

                            FILE *cfFile;
                            FILE *cfFileOrigine;
                            cfFileOrigine = fopen(nomeFileOrigine.c_str(), "r");
                            cfFile = fopen(nomeFile.c_str(), "a");

                            // Verifico se il file esiste, nel caso non esista ne creo uno nuovo.
                            if (cfFile == NULL || cfFileOrigine == NULL){
                                fclose(cfFile);
                                fclose(cfFileOrigine);
                                printf("\nUno dei due file non è stato trovato!\n");
                            } else {

                                while (!feof(cfFileOrigine)) {
                                    lineaDaScrivere = fgetc(cfFileOrigine);
                                    fputc(lineaDaScrivere, cfFile);
                                }

                                int error = ferror(cfFile);
                                fclose(cfFile);

                                if (error == 1){
                                    printf("\nC'e' stato qualche errore durante la scrittura del FILE!");
                                } else {
                                    printf("\nLinea scritta con successo senza errori!");
                                }
                            }

                            break;
                        }

                        case 3:{

                            printf("\nHai scelto: Leggi file...");

                            string nomeFile;

                            printf("\nInserire il nome del file: ");
                            cin >> nomeFile;

                            FILE *cfFile;
                            cfFile = fopen(nomeFile.c_str(), "r");

                            if (cfFile == NULL){
                                printf("\nErrore durante la lettura del file, magari non esiste, crealo prima di leggerlo!");
                            } else {

                                int numeroRigheTrovate = 0;
                                printf("\nLinee nel file: ");
                                while (!feof(cfFile)){
                                    char lineaLetta;
                                    lineaLetta = fgetc(cfFile);
                                    printf("\n");
                                    cout << lineaLetta;
                                    numeroRigheTrovate++;
                                }

                                if (numeroRigheTrovate == 0){
                                    printf("\nNon sono state trovate righe, il file è vuoto forse.");
                                } else {
                                    printf("\n\nFile letto con successo!");
                                }
                            }
                            fclose(cfFile);

                            break;
                        }

                        default:{

                            printf("\nHai inserito un valore non valido, riprova!");

                            break;
                        }

                    }

                }
                break;
            }

            case 5:{

                printf("\nHai scelto: Leggi registro per Insegnante...");

                FILE *cfRegistro;
                cfRegistro = fopen("registro.txt", "r");

                if (cfRegistro == NULL){
                    printf("\nIl file non esiste e nemmeno un registro!");
                } else {

                    string nomeInsegnanteScelto;
                    printf("\nScrivere il nome dell'insegnate: ");
                    cin >> nomeInsegnanteScelto;

                    int numeroRiepilogo = 1;
                    printf("\nRiepilogo registro per insegnante %s:", nomeInsegnanteScelto.c_str());
                    while (!feof(cfRegistro)){

                        char nomeInsegnante[100];
                        char materia[100];
                        int oraInizio;
                        int minutiInizio;
                        int oraFine;
                        int minutiFine;
                        char argomento[100];
                        char firmato[100];
                        char classe[100];

                        fscanf(cfRegistro, "%s %s %d %d %d %d %s %s %s", nomeInsegnante, materia, &oraInizio, &minutiInizio, &oraFine, &minutiFine, argomento, firmato, classe);

                        if(nomeInsegnante == nomeInsegnanteScelto){

                            printf("\n\nRiepilogo: %d"
                                   "\nNome insegnante: %s"
                                   "\nNome materia: %s"
                                   "\nOra di inzio: %d:%d"
                                   "\nOra di fine: %d:%d"
                                   "\nArgomento: %s"
                                   "\nFirmato: %s"
                                   "\nClasse: %s", numeroRiepilogo++, nomeInsegnante, materia, oraInizio, minutiInizio, oraFine, minutiFine, argomento, firmato, classe);


                        }
                    }
                    if (numeroRiepilogo == 0){
                        printf("\nNessun insegnante con quel nome trovato!");
                    }

                    continua();
                }

                break;
            }

            case 6:{

                printf("\nHai scelto: Leggi registro per Materia...");

                FILE *cfRegistro;
                cfRegistro = fopen("registro.txt", "r");

                if (cfRegistro == NULL){
                    printf("\nIl file non esiste e nemmeno un registro!");
                } else {

                    string nomeMateriaScelta;
                    printf("\nScrivere il nome della materia: ");
                    cin >> nomeMateriaScelta;

                    int numeroRiepilogo = 1;
                    printf("\nRiepilogo registro per materia %s:", nomeMateriaScelta.c_str());
                    while (!feof(cfRegistro)){

                        char nomeInsegnante[100];
                        char materia[100];
                        int oraInizio;
                        int minutiInizio;
                        int oraFine;
                        int minutiFine;
                        char argomento[100];
                        char firmato[100];
                        char classe[100];

                        fscanf(cfRegistro, "%s %s %d %d %d %d %s %s %s", nomeInsegnante, materia, &oraInizio, &minutiInizio, &oraFine, &minutiFine, argomento, firmato, classe);

                        if(materia == nomeMateriaScelta){

                            printf("\n\nRiepilogo: %d"
                                   "\nNome insegnante: %s"
                                   "\nNome materia: %s"
                                   "\nOra di inzio: %d:%d"
                                   "\nOra di fine: %d:%d"
                                   "\nArgomento: %s"
                                   "\nFirmato: %s"
                                   "\nClasse: %s", numeroRiepilogo++, nomeInsegnante, materia, oraInizio, minutiInizio, oraFine, minutiFine, argomento, firmato, classe);


                        }
                    }
                    if (numeroRiepilogo == 0){
                        printf("\nNessuna materia con quel nome trovata!");
                    }

                    continua();
                }

                break;
            }

            case 7:{

                printf("\nHai scelto: Leggi registro per Classe,..");

                FILE *cfRegistro;
                cfRegistro = fopen("registro.txt", "r");

                if (cfRegistro == NULL){
                    printf("\nIl file non esiste e nemmeno un registro!");
                } else {

                    string nomeClasseScelta;
                    printf("\nScrivere il nome della classe: ");
                    cin >> nomeClasseScelta;

                    int numeroRiepilogo = 1;
                    printf("\nRiepilogo registro per classe %s:", nomeClasseScelta.c_str());
                    while (!feof(cfRegistro)){

                        char nomeInsegnante[100];
                        char materia[100];
                        int oraInizio;
                        int minutiInizio;
                        int oraFine;
                        int minutiFine;
                        char argomento[100];
                        char firmato[100];
                        char classe[100];

                        fscanf(cfRegistro, "%s %s %d %d %d %d %s %s %s", nomeInsegnante, materia, &oraInizio, &minutiInizio, &oraFine, &minutiFine, argomento, firmato, classe);

                        if(classe == nomeClasseScelta){

                            printf("\n\nRiepilogo: %d"
                                   "\nNome insegnante: %s"
                                   "\nNome materia: %s"
                                   "\nOra di inzio: %d:%d"
                                   "\nOra di fine: %d:%d"
                                   "\nArgomento: %s"
                                   "\nFirmato: %s"
                                   "\nClasse: %s", numeroRiepilogo++, nomeInsegnante, materia, oraInizio, minutiInizio, oraFine, minutiFine, argomento, firmato, classe);


                        }
                    }
                    if (numeroRiepilogo == 0){
                        printf("\nNessuna classe con quel nome trovata!");
                    }

                    continua();
                }

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

void letturaFileRegistro() {
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
            int minutiInizio;
            int oraFine;
            int minutiFine;
            char argomento[100];
            char firmato[100];
            char classe[100];

            fscanf(cfRegistro, "%s %s %d %d %d %d %s %s %s", nomeInsegnate, materia, &oraInizio, &minutiInizio, &oraFine, &minutiFine, argomento, firmato, classe);

            printf("\n\nRiepilogo: %d"
                   "\nNome insegnante: %s"
                   "\nNome materia: %s"
                   "\nOra di inzio: %d:%d"
                   "\nOra di fine: %d:%d"
                   "\nArgomento: %s"
                   "\nFirmato: %s"
                   "\nClasse: %s", numeroRiepilogo, nomeInsegnate, materia, oraInizio, minutiInizio, oraFine, minutiFine, argomento, firmato, classe);

        }

        printf("\n|---------------------------------------------------------|");
    }
    fclose(cfRegistro);
}

void continua(){

    // Variabile inutile per evitare errori.
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}


