#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>

using namespace std;

void continua();

void letturaFileRegistro();

string sostituisciSpaziConTrattini(string stringa);

string sostituisciTrattiniConSpazi(string stringa);

void filtraPerNomeInsegnante(string &nomeInsegnanteScelto);

void filtraPerMateria(string &nomeMateriaScelta);

void filtraPerClasse(string &nomeClasseScelta);

FILE *scritturaNuovoFILE(FILE *cfConfig);

void filtraPerIndirizzo(string &indirizzoScelto);

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           Verifica di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Valore bandiera.
    int scelta = 1;
    int numeroCorsi = 0;

    while (scelta != 0){

        struct ora{
            int ora = 0;
            string minuti = "00";
        };

        struct registroDati{
            string nomeInsegnante;
            string nomeMateria;
            ora oraInizio;
            ora oraFine;
            string nomeArgomento;
            bool firmato = false;
            string classe;
            string corso;
        } registro;

        struct corsiDati{
            string listaCorsi[100] = {"0"};
        } corsi;

        FILE *cfConfig;
        cfConfig = fopen("config.txt", "r");
        cfConfig = scritturaNuovoFILE(cfConfig);
        // Lettura corsi
        while (!feof(cfConfig)){
            char nomeCorso[100];
            fscanf(cfConfig, "%s", nomeCorso);
            corsi.listaCorsi[numeroCorsi++] = nomeCorso;
        }
        fclose(cfConfig);
        printf("\nFile config.txt caricato con successo.");

        printf("\nScegliere una modalita':"
               "\n0 -> Esci."
               "\n1 -> Registro base."
               "\n2 -> Aggiungi qualcosa al registro."
               "\n3 -> Leggi registro."
               "\n4 -> Esperimenti con i FILE."
               "\n5 -> Leggi registro per insegnante."
               "\n6 -> Leggi registro per materia."
               "\n7 -> Leggi registro per classe."
               "\n8 -> Leggi registro per indirizzo."
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

                        string sceltaMinuti;
                        printf("\nVuoi inserire un minuto di inizio?"
                               "\nFormato: XX (esempio 43 minuti)."
                               "\n0 -> Lascia 00 di default."
                               "\nQualsiasi valore valido diverso da 0 sara' i minuti di inizio."
                               "\nValore inserito: ");
                        cin >> sceltaMinuti;

                        if (atoi(sceltaMinuti.data()) != 0){
                            if (atoi(sceltaMinuti.data()) > 60){
                                printf("\nHai inserito un minuto troppo alto!");
                                sceltaValida = false;
                            } else if (atoi(sceltaMinuti.data()) < 0){
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

                        string sceltaMinuti;
                        printf("\nVuoi inserire un minuto di fine?"
                               "\nFormato: XX (esempio 43 minuti)."
                               "\n0 -> Lascia 00 di default."
                               "\nQualsiasi valore valido diverso da 0 sara' i minuti di fine."
                               "\nValore inserito: ");
                        cin >> sceltaMinuti;

                        if (atoi(sceltaMinuti.data()) != 0){
                            if (atoi(sceltaMinuti.data()) > 60){
                                printf("\nHai inserito un minuto troppo alto!");
                                sceltaValida = false;
                            } else if (atoi(sceltaMinuti.data()) < 0){
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

                    printf("\n\nInserire il nome dell'argomento: \n");
                    cin.ignore();
                    getline(cin, registro.nomeArgomento);

                    registro.nomeArgomento = sostituisciSpaziConTrattini(registro.nomeArgomento);

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

                // Scelta corso.
                bool valido = false;
                while (!valido) {
                    int sceltaCorso;
                    printf("\n\nInserire l'indirizzo dalla lista: ");
                    printf("\n0 -> Non scegliere un indirizzo.");
                    for (int i = 0; i < numeroCorsi; i++) {
                        printf("\n%d -> %s", i + 1, corsi.listaCorsi[i].c_str());
                    }
                    printf("\nScelta: ");
                    scanf("%d", &sceltaCorso);
                    if (sceltaCorso <= numeroCorsi){
                        if (sceltaCorso == 0){
                            registro.corso = "Nessuno";
                            valido = true;
                        } else {
                            registro.corso = corsi.listaCorsi[sceltaCorso - 1];
                            valido = true;
                        }
                    }
                }

                printf("\n\nSalvataggio su file con successo!");
                if (registro.firmato) {
                    fprintf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", registro.nomeInsegnante.c_str(),
                            registro.nomeMateria.c_str(), registro.oraInizio.ora, registro.oraInizio.minuti.c_str(), registro.oraFine.ora,
                            registro.oraFine.minuti.c_str(), registro.nomeArgomento.c_str(), "Firmato", registro.classe.c_str(), registro.corso.c_str());
                } else {
                    fprintf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", registro.nomeInsegnante.c_str(),
                            registro.nomeMateria.c_str(), registro.oraInizio.ora, registro.oraInizio.minuti.c_str(), registro.oraFine.ora,
                            registro.oraFine.minuti.c_str(), registro.nomeArgomento.c_str(), "Non_Firmato", registro.classe.c_str(), registro.corso.c_str());
                }
                fclose(cfRegistro);

                cfRegistro = fopen("registro.txt", "r");

                if (cfRegistro == NULL){
                    printf("\nErrore durante l'apertura del registro!");
                } else {

                    char nomeInsegnate[100];
                    char materia[100];
                    int oraInizio;
                    char minutiInizio[100];
                    int oraFine;
                    char minutiFine[100];
                    char argomento[100];
                    char firmato[100];
                    char classe[100];
                    char corso[100];

                    fscanf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", nomeInsegnate, materia, &oraInizio, minutiInizio, &oraFine, minutiFine, argomento, firmato, classe, corso);
                    string argomentoFinale = sostituisciTrattiniConSpazi(argomento);

                    printf("\n\nRiepilogo: "
                           "\nNome insegnante: %s"
                           "\nNome materia: %s"
                           "\nOra di inzio: %d:%s"
                           "\nOra di fine: %d:%s"
                           "\nArgomento: %s"
                           "\nFirmato: %s"
                           "\nClasse: %s"
                           "\nCorso: %s", nomeInsegnate, materia, oraInizio, minutiInizio, oraFine, minutiFine, argomentoFinale.c_str(), firmato, classe, corso);

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

                    string sceltaMinuti;
                    printf("\nVuoi inserire un minuto di inizio?"
                           "\nFormato: XX (esempio 43 minuti)."
                           "\n0 -> Lascia 00 di default."
                           "\nQualsiasi valore valido diverso da 0 sara' i minuti di inizio."
                           "\nValore inserito: ");
                    cin >> sceltaMinuti;

                    if (atoi(sceltaMinuti.data()) != 0){
                        if (atoi(sceltaMinuti.data()) > 60){
                            printf("\nHai inserito un minuto troppo alto!");
                            sceltaValida = false;
                        } else if (atoi(sceltaMinuti.data()) < 0){
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

                    string sceltaMinuti;
                    printf("\nVuoi inserire un minuto di fine?"
                           "\nFormato: XX (esempio 43 minuti)."
                           "\n0 -> Lascia 00 di default."
                           "\nQualsiasi valore valido diverso da 0 sara' i minuti di fine."
                           "\nValore inserito: ");
                    cin >> sceltaMinuti;

                    if (atoi(sceltaMinuti.data()) != 0){
                        if (atoi(sceltaMinuti.data()) > 60){
                            printf("\nHai inserito un minuto troppo alto!");
                            sceltaValida = false;
                        } else if (atoi(sceltaMinuti.data()) < 0){
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

                printf("\n\nInserire il nome dell'argomento: \n");
                cin.ignore();
                getline(cin, registro.nomeArgomento);

                registro.nomeArgomento = sostituisciSpaziConTrattini(registro.nomeArgomento);

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

                bool valido = false;
                while (!valido) {
                    int sceltaCorso;
                    printf("\n\nInserire l'indirizzo dalla lista: ");
                    printf("\n0 -> Non scegliere un indirizzo.");
                    for (int i = 0; i < numeroCorsi; i++) {
                        printf("\n%d -> %s", i + 1, corsi.listaCorsi[i].c_str());
                    }
                    printf("\nScelta: ");
                    scanf("%d", &sceltaCorso);
                    if (sceltaCorso <= numeroCorsi){
                        if (sceltaCorso == 0){
                            registro.corso = "Nessuno";
                            valido = true;
                        } else {
                            registro.corso = corsi.listaCorsi[sceltaCorso - 1];
                            valido = true;
                        }
                    }
                }

                printf("\n\nSalvataggio su file con successo!");
                if (registro.firmato) {
                    fprintf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", registro.nomeInsegnante.c_str(),
                            registro.nomeMateria.c_str(), registro.oraInizio.ora, registro.oraInizio.minuti.c_str(), registro.oraFine.ora,
                            registro.oraFine.minuti.c_str(), registro.nomeArgomento.c_str(), "Firmato", registro.classe.c_str(), registro.corso.c_str());
                } else {
                    fprintf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", registro.nomeInsegnante.c_str(),
                            registro.nomeMateria.c_str(), registro.oraInizio.ora, registro.oraInizio.minuti.c_str(), registro.oraFine.ora,
                            registro.oraFine.minuti.c_str(), registro.nomeArgomento.c_str(), "Non_Firmato", registro.classe.c_str(), registro.corso.c_str());
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

                string nomeInsegnanteScelto;
                printf("\nScrivere il nome dell'insegnate: ");
                cin >> nomeInsegnanteScelto;

                filtraPerNomeInsegnante(nomeInsegnanteScelto);

                continua();

                break;
            }

            case 6:{

                printf("\nHai scelto: Leggi registro per Materia...");

                string nomeMateriaScelta;
                printf("\nScrivere il nome della materia: ");
                cin >> nomeMateriaScelta;

                filtraPerMateria(nomeMateriaScelta);

                continua();

                break;
            }

            case 7:{

                printf("\nHai scelto: Leggi registro per Classe...");

                string nomeClasseScelta;
                printf("\nScrivere il nome della classe: ");
                cin >> nomeClasseScelta;

                filtraPerClasse(nomeClasseScelta);

                continua();

                break;
            }

            case 8:{

                printf("\nHai scelto: Leggi registro per Indirizzo...");

                string indirizzoScelto;
                printf("\nInserire il nome dell'indirizzo: ");
                cin >> indirizzoScelto;

                filtraPerIndirizzo(indirizzoScelto);

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

FILE *scritturaNuovoFILE(FILE *cfConfig) {
    string indirizziBase[9] = {"Informatica", "Telecomunicazioni", "Chimico", "Biologico", "Elettronica", "Elettrotecnica", "Robotica", "Meccanica", "Meccatronica"};
    if (cfConfig == NULL){
        fclose(cfConfig);
        cfConfig = fopen("config.txt", "w");

        for (int i = 0; i < 9; i++) {
            if (i != 0){
                fprintf(cfConfig, "%s", "\n");
            }
            fprintf(cfConfig, "%s", indirizziBase[i].c_str());
        }
        printf("\nFile config.txt nuovo creato con successo!");
        fclose(cfConfig);
        cfConfig = fopen("config.txt", "r");
    }
    return cfConfig;
}

void filtraPerIndirizzo(string &indirizzoScelto) {
    FILE *cfRegistro;
    cfRegistro = fopen("registro.txt", "r");

    if (cfRegistro == NULL){
        printf("\nIl file non esiste e nemmeno un registro!");
    } else {

        int numeroRiepilogo = 1;
        printf("\nRiepilogo registro per indirizzo %s:", indirizzoScelto.c_str());
        while (!feof(cfRegistro)) {

            char nomeInsegnante[100];
            char materia[100];
            int oraInizio;
            char minutiInizio[100];
            int oraFine;
            char minutiFine[100];
            char argomento[100];
            char firmato[100];
            char classe[100];
            char corso[100];

            fscanf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", nomeInsegnante, materia, &oraInizio, minutiInizio,
                   &oraFine, minutiFine, argomento, firmato, classe, corso);

            if (corso == indirizzoScelto) {

                string argomentoFinale = sostituisciTrattiniConSpazi(argomento);

                printf("\n\nRiepilogo: %d"
                       "\nNome insegnante: %s"
                       "\nNome materia: %s"
                       "\nOra di inzio: %d:%s"
                       "\nOra di fine: %d:%s"
                       "\nArgomento: %s"
                       "\nFirmato: %s"
                       "\nClasse: %s"
                       "\nCorso: %s", numeroRiepilogo++, nomeInsegnante, materia, oraInizio, minutiInizio, oraFine,
                       minutiFine, argomentoFinale.c_str(), firmato, classe, corso);

            }
        }
        if (numeroRiepilogo == 0) {
            printf("\nNessun indirizzo con quel nome trovato!");
        }
    }
}

void filtraPerClasse(string &nomeClasseScelta) {

    FILE *cfRegistro;
    cfRegistro = fopen("registro.txt", "r");

    if (cfRegistro == NULL){
        printf("\nIl file non esiste e nemmeno un registro!");
    } else {

        int numeroRiepilogo = 1;
        printf("\nRiepilogo registro per classe %s:", nomeClasseScelta.c_str());
        while (!feof(cfRegistro)) {

            char nomeInsegnante[100];
            char materia[100];
            int oraInizio;
            char minutiInizio[100];
            int oraFine;
            char minutiFine[100];
            char argomento[100];
            char firmato[100];
            char classe[100];
            char corso[100];

            fscanf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", nomeInsegnante, materia, &oraInizio, minutiInizio,
                   &oraFine, minutiFine, argomento, firmato, classe, corso);

            if (classe == nomeClasseScelta) {

                string argomentoFinale = sostituisciTrattiniConSpazi(argomento);

                printf("\n\nRiepilogo: %d"
                       "\nNome insegnante: %s"
                       "\nNome materia: %s"
                       "\nOra di inzio: %d:%s"
                       "\nOra di fine: %d:%s"
                       "\nArgomento: %s"
                       "\nFirmato: %s"
                       "\nClasse: %s"
                       "\nCorso: %s", numeroRiepilogo++, nomeInsegnante, materia, oraInizio, minutiInizio, oraFine,
                       minutiFine, argomentoFinale.c_str(), firmato, classe, corso);

            }
        }
        if (numeroRiepilogo == 0) {
            printf("\nNessuna classe con quel nome trovata!");
        }
    }
}

void filtraPerMateria(string &nomeMateriaScelta) {

    FILE *cfRegistro;
    cfRegistro = fopen("registro.txt", "r");

    if (cfRegistro == NULL){
        printf("\nIl file non esiste e nemmeno un registro!");
    } else {
        int numeroRiepilogo = 1;
        printf("\nRiepilogo registro per materia %s:", nomeMateriaScelta.c_str());
        while (!feof(cfRegistro)) {

            char nomeInsegnante[100];
            char materia[100];
            int oraInizio;
            char minutiInizio[100];
            int oraFine;
            char minutiFine[100];
            char argomento[100];
            char firmato[100];
            char classe[100];
            char corso[100];

            fscanf(cfRegistro, "%s %s %d %s %d %s %s %s %s", nomeInsegnante, materia, &oraInizio, minutiInizio,
                   &oraFine, minutiFine, argomento, firmato, classe, corso);

            if (materia == nomeMateriaScelta) {

                string argomentoFinale = sostituisciTrattiniConSpazi(argomento);

                printf("\n\nRiepilogo: %d"
                       "\nNome insegnante: %s"
                       "\nNome materia: %s"
                       "\nOra di inzio: %d:%s"
                       "\nOra di fine: %d:%s"
                       "\nArgomento: %s"
                       "\nFirmato: %s"
                       "\nClasse: %s"
                       "\nCorso %s", numeroRiepilogo++, nomeInsegnante, materia, oraInizio, minutiInizio, oraFine,
                       minutiFine, argomentoFinale.c_str(), firmato, classe, corso);


            }
        }
        if (numeroRiepilogo == 0) {
            printf("\nNessuna materia con quel nome trovata!");
        }
    }
}

void filtraPerNomeInsegnante(string &nomeInsegnanteScelto) {

    FILE *cfRegistro;
    cfRegistro = fopen("registro.txt", "r");

    if (cfRegistro == NULL){
        printf("\nIl file non esiste e nemmeno un registro!");
    } else {

        int numeroRiepilogo = 1;
        printf("\nRiepilogo registro per insegnante %s:", nomeInsegnanteScelto.c_str());
        while (!feof(cfRegistro)) {

            char nomeInsegnante[100];
            char materia[100];
            int oraInizio;
            char minutiInizio[100];
            int oraFine;
            char minutiFine[100];
            char argomento[100];
            char firmato[100];
            char classe[100];
            char corso[100];

            fscanf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", nomeInsegnante, materia, &oraInizio, minutiInizio,
                   &oraFine, minutiFine, argomento, firmato, classe, corso);

            if (nomeInsegnante == nomeInsegnanteScelto) {

                string argomentoFinale = sostituisciTrattiniConSpazi(argomento);

                printf("\n\nRiepilogo: %d"
                       "\nNome insegnante: %s"
                       "\nNome materia: %s"
                       "\nOra di inzio: %d:%s"
                       "\nOra di fine: %d:%s"
                       "\nArgomento: %s"
                       "\nFirmato: %s"
                       "\nClasse: %s"
                       "\nCorso: %s", numeroRiepilogo++, nomeInsegnante, materia, oraInizio, minutiInizio, oraFine,
                       minutiFine, argomentoFinale.c_str(), firmato, classe, corso);


            }
        }
        if (numeroRiepilogo == 0) {
            printf("\nNessun insegnante con quel nome trovato!");
        }
    }
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
            char minutiInizio[100];
            int oraFine;
            char minutiFine[100];
            char argomento[1000];
            char firmato[100];
            char classe[100];
            char corso[100];

            fscanf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", nomeInsegnate, materia, &oraInizio, minutiInizio, &oraFine, minutiFine, argomento, firmato, classe, corso);

            string argomentoFinale = sostituisciTrattiniConSpazi(argomento);

            printf("\n\nRiepilogo: %d"
                   "\nNome insegnante: %s"
                   "\nNome materia: %s"
                   "\nOra di inzio: %d:%s"
                   "\nOra di fine: %d:%s"
                   "\nArgomento: %s"
                   "\nFirmato: %s"
                   "\nClasse: %s"
                   "\nCorso: %s", numeroRiepilogo, nomeInsegnate, materia, oraInizio, minutiInizio, oraFine, minutiFine, argomentoFinale.c_str(), firmato, classe, corso);

        }

        printf("\n|---------------------------------------------------------|");
    }
    fclose(cfRegistro);
}

string sostituisciSpaziConTrattini(string stringa){

    for (int i = 0; i < stringa.length(); i++) {
        if (isspace(stringa[i])){
            stringa[i] = '_';
        }
    }

    /*(for(char & i : stringa) {
        if (isspace(i))
            i = '_';
    }*/
    return stringa;
}

string sostituisciTrattiniConSpazi(string stringa){

    for (int i = 0; i < stringa.length(); i++) {
        if (stringa[i] == '_'){
            stringa[i] = ' ';
        }
    }

    /*for(char & i : stringa) {
        if (i == '_')
            i = ' ';
    }*/
    return stringa;
}

void continua(){

    // Variabile inutile per evitare errori.
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}