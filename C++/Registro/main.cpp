#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <time.h>

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

void inserimentoDati(FILE *cfRegistro);

const int dimensioneVettori = 100;

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           Verifica di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Valore bandiera.
    int scelta = 1;

    // Continua fino a quando l'utente non decide di uscire.
    while (scelta != 0){

        // Legenda
        printf("\n|---------------------------------------"
               "\n| Scegliere una modalita':"
               "\n| 0 -> Esci."
               "\n| 1 -> Registro base."
               "\n| 2 -> Aggiungi qualcosa al registro."
               "\n| 3 -> Leggi registro."
               "\n| 4 -> Esperimenti con i FILE."
               "\n| 5 -> Leggi registro per insegnante."
               "\n| 6 -> Leggi registro per materia."
               "\n| 7 -> Leggi registro per classe."
               "\n| 8 -> Leggi registro per indirizzo."
               "\n| 9 -> Ordinare dati vettore casuale dal più piccolo al più grande."
               "\n| Scelta: ");
        scanf("%d", &scelta);
        printf("|---------------------------------------\n");

        // Switch tra le scelte.
        switch (scelta) {
            case 0:{

                // Uscita.
                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Esci..."
                       "\n| Uscita in corso.");

                break;
            }

            case 1:{

                // Registro nuovo base.
                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Registro base."
                       "\n|---------------------------------------\n");

                // Crea files.
                FILE *cfRegistro;
                cfRegistro = fopen("registro.txt", "w");

                // Verifica se creato con successo e comunica eventualmente l'errore.
                if (cfRegistro == NULL){
                    printf("\n|---------------------------------------"
                           "\n| Errore durante la crezione del file."
                           "\n|---------------------------------------");
                    return 0;
                } else {

                    // Richiama metodo inserimento dati che saranno salvati sul file.
                    inserimentoDati(cfRegistro);

                }
                // Chiude file.
                fclose(cfRegistro);

                // Apre il file in modalità lettura.
                cfRegistro = fopen("registro.txt", "r");

                // Verifica se il file esiste.
                if (cfRegistro == NULL){
                    printf("\n|---------------------------------------"
                           "\n| Errore durante l'apertura del registro!"
                           "\n|---------------------------------------");
                } else {

                    // Lettura file e variabili temporanee.
                    char nomeInsegnate[dimensioneVettori];
                    char materia[dimensioneVettori];
                    int oraInizio;
                    char minutiInizio[dimensioneVettori];
                    int oraFine;
                    char minutiFine[dimensioneVettori];
                    char argomento[dimensioneVettori * 10];
                    char firmato[dimensioneVettori];
                    char classe[dimensioneVettori];
                    char corso[dimensioneVettori];

                    fscanf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", nomeInsegnate, materia, &oraInizio, minutiInizio, &oraFine, minutiFine, argomento, firmato, classe, corso);
                    string argomentoFinale = sostituisciTrattiniConSpazi(argomento);

                    printf("\n\n|---------------------------------------"
                           "\n| Riepilogo: 1"
                           "\n| Nome insegnante: %s"
                           "\n| Nome materia: %s"
                           "\n| Ora di inzio: %d:%s"
                           "\n| Ora di fine: %d:%s"
                           "\n| Argomento: %s"
                           "\n| Firmato: %s"
                           "\n| Classe: %s"
                           "\n| Corso: %s"
                           "\n|---------------------------------------", nomeInsegnate, materia, oraInizio, minutiInizio, oraFine, minutiFine, argomentoFinale.c_str(), firmato, classe, corso);

                    // Chiusura file.
                    fclose(cfRegistro);
                    continua();
                }


                break;
            }

            case 2:{

                // Messaggio d'inizio.
                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Aggiungi qualcosa al registro..."
                       "\n|---------------------------------------\n");

                // Apre file.
                FILE *cfRegistro = fopen("registro.txt", "a");

                // Verifica se non ci sono errori ed eventualmente crea un nuovo file vuoto.
                if (cfRegistro == NULL){
                    fclose(cfRegistro);
                    cfRegistro = fopen("registro.txt", "w");
                } else {
                    // Se esiste manda a capo per creare una nuova riga.
                    fprintf(cfRegistro, "%s", "\n");
                }

                // Inserimento dati nel file e chiusura.
                inserimentoDati(cfRegistro);
                fclose(cfRegistro);

                // Riepilogo lettura.
                letturaFileRegistro();

                // Chiedo all'utente se vuole continuare.
                continua();
                break;
            }

            case 3:{

                // Messaggio d'inizio.
                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Lettura registro..."
                       "\n|---------------------------------------");

                // Richiamo metodo lettura.
                letturaFileRegistro();

                // Chiedo se continuare quindi pausa.
                continua();
                break;
            }

            // COSE VECCHIE, IGNORARE SWITCH 4.
            case 4:{

                // IGNORARE TUTTO QUESTO
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

                // Messaggio d'inizio.
                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Leggi registro per Insegnante..."
                       "\n|---------------------------------------\n");

                // Salvo nome insegnante in input e richiamo funzione per filtrare e mostrare risultati.
                string nomeInsegnanteScelto;
                printf("\n|---------------------------------------"
                       "\n| Scrivere il nome dell'insegnate: ");
                cin >> nomeInsegnanteScelto;
                printf("|---------------------------------------\n");

                // Richiamo metodo.
                filtraPerNomeInsegnante(nomeInsegnanteScelto);

                // Pausa
                continua();

                break;
            }

            case 6:{

                // Messaggio d'inizio.
                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Leggi registro per Materia..."
                       "\n|---------------------------------------\n");

                // Filtro per materia, dati in ingresso e richiamo funzione.
                string nomeMateriaScelta;
                printf("\n|---------------------------------------"
                       "\n| Scrivere il nome della materia: ");
                cin >> nomeMateriaScelta;
                printf("|---------------------------------------\n");

                // Richiamo funzione.
                filtraPerMateria(nomeMateriaScelta);

                // Pausa.
                continua();
                break;
            }

            case 7:{

                // Messaggio d'inizio.
                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Leggi registro per Classe..."
                       "\n|---------------------------------------\n");

                // Filtro per classe e dati in ingresso, richiamo funzione.
                string nomeClasseScelta;
                printf("\n|---------------------------------------"
                       "\n| Scrivere il nome della classe: ");
                cin >> nomeClasseScelta;
                printf("|---------------------------------------\n");

                // Richiamo funzione filtro.
                filtraPerClasse(nomeClasseScelta);

                // Pausa.
                continua();
                break;
            }

            case 8:{

                // Messaggio d'inizio.
                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Leggi registro per Indirizzo..."
                       "\n|---------------------------------------\n");

                // Dati in ingresso e richiamo funzione.
                string indirizzoScelto;
                printf("\n|---------------------------------------"
                       "\n| Inserire il nome dell'indirizzo: ");
                cin >> indirizzoScelto;
                printf("|---------------------------------------\n");

                // Richiamo funzione filtro per indirizzi.
                filtraPerIndirizzo(indirizzoScelto);

                // Pausa.
                continua();
                break;
            }

            case 9:{

                // Messaggio d'inizio.
                printf("\nHai scelto: ordinamento numeri in un vettore casuale dal più piccolo al più grande...");

                int nNumeri, max, min;
                printf("\nInserire numero di valori da generare: ");
                scanf("%d", &nNumeri);

                printf("\nInserire numero massimo possibile: ");
                scanf("%d", &max);

                printf("\nInserire numero minore: ");
                scanf("%d", &min);

                srand(time(0));

                int vettoreConNumeri[nNumeri];
                for (int i = 0; i < nNumeri; i++) {
                    int numeroCasuale = rand() % max;
                    if(numeroCasuale < min){
                        numeroCasuale += min;
                    }
                    vettoreConNumeri[i] = numeroCasuale;
                }

                int numeroMinore;
                for(int i = 0; i < nNumeri; i++){

                    for(int j = i+1; j < nNumeri; j++){

                        if(vettoreConNumeri[i] > vettoreConNumeri[j]){

                            numeroMinore = vettoreConNumeri[i];
                            vettoreConNumeri[i] = vettoreConNumeri[j];
                            vettoreConNumeri[j] = numeroMinore;
                        }
                    }
                }

                for (int i = 0; i < nNumeri; i++) {
                    printf("\n%d -> %d", i + 1, vettoreConNumeri[i]);
                }

                continua();
                break;
            }

            default:{

                // Scelta non valida, richiedo di inserire i dati.
                printf("\n|---------------------------------------"
                       "\n| Scelta non valida, per favore riprovare!"
                       "\n|---------------------------------------");

                break;
            }
        }
    }

    // Messaggio d'uscita.
    printf("\n| Uscito con successo."
           "\n|---------------------------------------");

    return 0;
}

void inserimentoDati(FILE *cfRegistro) {

    // Numero corsi.
    int numeroCorsi = 0;

    // Struct corsi.
    struct corsiDati{
        string listaCorsi[dimensioneVettori] = {"0"};
    } corsi;

    // Apro file in lettura.
    FILE *cfConfig;
    cfConfig = fopen("config.txt", "r");
    cfConfig = scritturaNuovoFILE(cfConfig);
    // Lettura corsi
    while (!feof(cfConfig)){
        char nomeCorso[dimensioneVettori];
        fscanf(cfConfig, "%s", nomeCorso);
        corsi.listaCorsi[numeroCorsi++] = nomeCorso;
    }
    // Chiudo file corsi ormai letto e memorizzato e messaggio di successo.
    fclose(cfConfig);
    printf("\n|---------------------------------------"
           "\n| File config.txt caricato con successo."
           "\n|---------------------------------------\n");

    // Struct varie per dati.
    struct ora{
        int ora = 0;
        string minuti = "00";
    };

    struct registroDati {
        string nomeInsegnante;
        string nomeMateria;
        ora oraInizio;
        ora oraFine;
        string nomeArgomento;
        bool firmato = false;
        string classe;
        string corso;
    } registro;

    // Nome.
    printf("\n|---------------------------------------"
           "\n| Inserire il proprio nome: ");
    cin >> registro.nomeInsegnante;
    printf("\n|---------------------------------------");

    bool successo = false;

    // Materia.
    while (!successo) {
        int nMateriaScelta;
        printf("\n\n|---------------------------------------"
               "\n| Scegliere una materia, oppure scegliere 0 per inserire una nuova:"
               "\n| 0 -> Inserisci una materia che vuoi."
               "\n| 1 -> Matematica"
               "\n| 2 -> Informatica"
               "\n| 3 -> Telecomunicazioni"
               "\n| 4 -> TPSIT"
               "\n| 5 -> Sistemi"
               "\n| 6 -> Educazione fisica"
               "\n| 7 -> Italiano"
               "\n| 8 -> Storia"
               "\n| Scelta: ");
        scanf("%d", &nMateriaScelta);
        printf("\n|---------------------------------------");

        switch (nMateriaScelta) {
            case 0: {

                printf("\n|---------------------------------------"
                       "\n| Inserire la materia: ");
                cin >> registro.nomeMateria;
                printf("\n|---------------------------------------");

                successo = true;
                break;
            }

            case 1: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Matematica");
                registro.nomeMateria = "Matematica";
                printf("\n|---------------------------------------");

                successo = true;
                break;
            }

            case 2: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Informatica");
                registro.nomeMateria = "Informatica";
                printf("\n|---------------------------------------");

                successo = true;
                break;
            }

            case 3: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Telecomunicazioni");
                registro.nomeMateria = "Telecomunicazioni";
                printf("\n|---------------------------------------");

                successo = true;
                break;
            }

            case 4: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: TPSIT");
                registro.nomeMateria = "TPSIT";
                printf("\n|---------------------------------------");

                successo = true;
                break;
            }

            case 5: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Sistemi");
                registro.nomeMateria = "Sistemi";
                printf("\n|---------------------------------------");

                successo = true;
                break;
            }

            case 6: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Educazione_Fisica");
                registro.nomeMateria = "Educazione_Fisica";
                printf("\n|---------------------------------------");

                successo = true;
                break;
            }
            case 7: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Italiano");
                registro.nomeMateria = "Italiano";
                printf("\n|---------------------------------------");

                successo = true;
                break;
            }

            case 8: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: Storia");
                registro.nomeMateria = "Storia";
                printf("\n|---------------------------------------");

                successo = true;
                break;
            }

            default: {

                printf("\n|---------------------------------------"
                       "\n| Scelta non valida, riprovare.");
                printf("\n|---------------------------------------");

                break;
            }
        }
    }

    // Ora
    successo = false;
    while (!successo) {
        int nOraScelta;
        printf("\n\n|---------------------------------------"
               "\n| Scegli una delle seguenti opzioni oppure inserisci il tuo: "
               "\n| Numero -> OraInizio -> OraFine"
               "\n| 0 -> Inserisci il tuo orario."
               "\n| 1 -> 8:00 -> 9:00"
               "\n| 2 -> 9:00 -> 10:00"
               "\n| 3 -> 10:00 -> 11:00"
               "\n| 4 -> 11:00 -> 12:00"
               "\n| 5 -> 12:00 -> 13:00"
               "\n| 6 -> 13:00 -> 14:00"
               "\n| Scelta: ");
        scanf("%d", &nOraScelta);
        printf("|---------------------------------------\n");

        switch (nOraScelta) {
            case 0: {

                printf("\n|---------------------------------------"
                       "\n| Inserisci il tuo orario d'inizio: ");
                cin >> registro.oraInizio.ora;
                printf("\n|---------------------------------------");

                printf("\n|---------------------------------------"
                       "\n| Inserisci il tuo orario di fine: ");
                cin >> registro.oraFine.ora;
                printf("\n|---------------------------------------");

                if (registro.oraInizio.ora > 24 || registro.oraFine.ora > 24 ||
                    registro.oraInizio.ora < 0 || registro.oraFine.ora < 0) {
                    printf("\n|---------------------------------------"
                           "\n| Hai inserito un'ora non valida!"
                           "\n|---------------------------------------");
                    successo = false;
                } else {
                    printf("\n|---------------------------------------"
                           "\n| Ora inserita con successo!"
                           "\n|---------------------------------------");
                    successo = true;
                }
                break;
            }

            case 1: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: 8:00 -> 9.00"
                       "\n|---------------------------------------");

                registro.oraInizio.ora = 8;
                registro.oraFine.ora = 9;

                successo = true;
                break;
            }

            case 2: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: 9:00 -> 10:00"
                       "\n|---------------------------------------");

                registro.oraInizio.ora = 9;
                registro.oraFine.ora = 10;

                successo = true;
                break;
            }

            case 3: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: 10:00 -> 11:00"
                       "\n|---------------------------------------");

                registro.oraInizio.ora = 10;
                registro.oraFine.ora = 11;

                successo = true;
                break;
            }

            case 4: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: 11:00 -> 12:00"
                       "\n|---------------------------------------");

                registro.oraInizio.ora = 11;
                registro.oraFine.ora = 12;

                successo = true;
                break;
            }

            case 5: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: 12:00 -> 13:00"
                       "\n|---------------------------------------");

                registro.oraInizio.ora = 12;
                registro.oraFine.ora = 13;

                successo = true;
                break;
            }

            case 6: {

                printf("\n|---------------------------------------"
                       "\n| Hai scelto: 13:00 -> 14:00"
                       "\n|---------------------------------------");

                registro.oraInizio.ora = 13;
                registro.oraFine.ora = 14;

                successo = true;
                break;
            }

            default: {

                printf("\n|---------------------------------------"
                       "\n| Scelta non valida, riprova!"
                       "\n|---------------------------------------");
                successo = false;
                break;
            }
        }
    }

    // Verifico se scelta valida con booleano bandiera e continuo fino a quando non ne viene scelta una.
    bool sceltaValida = false;
    while (!sceltaValida) {

        // Chiedo dati a utente.
        string sceltaMinuti;
        printf("\n\n|---------------------------------------"
               "\n| Vuoi inserire un minuto di inizio?"
               "\n| Formato: XX (esempio 43 minuti)."
               "\n| 0 -> Lascia 00 di default."
               "\n| Qualsiasi valore valido diverso da 0 sara' i minuti di inizio."
               "\n| Valore inserito: ");
        cin >> sceltaMinuti;
        printf("|---------------------------------------\n");

        if (atoi(sceltaMinuti.data()) != 0) {
            if (atoi(sceltaMinuti.data()) > 60) {
                printf("\n|---------------------------------------"
                       "\n| Hai inserito un minuto troppo alto!"
                       "\n|---------------------------------------");
                sceltaValida = false;
            } else if (atoi(sceltaMinuti.data()) < 0) {
                printf("\n|---------------------------------------"
                       "\n| Hai inserito un minuto troppo basso!"
                       "\n|---------------------------------------");
                sceltaValida = false;
            } else {
                registro.oraInizio.minuti = sceltaMinuti;
                sceltaValida = true;
            }
        } else {
            sceltaValida = true;
        }
    }

    // Booleano bandiera che continua fino a quando non viene eseguita una scelta valida.
    sceltaValida = false;
    while (!sceltaValida) {

        // Inserimento dati utente.
        string sceltaMinuti;
        printf("\n\n|---------------------------------------"
               "\n| Vuoi inserire un minuto di fine?"
               "\n| Formato: XX (esempio 43 minuti)."
               "\n| 0 -> Lascia 00 di default."
               "\n| Qualsiasi valore valido diverso da 0 sara' i minuti di fine."
               "\n| Valore inserito: ");
        cin >> sceltaMinuti;
        printf("|---------------------------------------\n");

        if (atoi(sceltaMinuti.data()) != 0) {
            if (atoi(sceltaMinuti.data()) > 60) {
                printf("\n|---------------------------------------"
                       "\n| Hai inserito un minuto troppo alto!"
                       "\n|---------------------------------------");
                sceltaValida = false;
            } else if (atoi(sceltaMinuti.data()) < 0) {
                printf("\n|---------------------------------------"
                       "\n| Hai inserito un minuto troppo basso!"
                       "\n|---------------------------------------");
                sceltaValida = false;
            } else {
                registro.oraFine.minuti = sceltaMinuti;
                sceltaValida = true;
            }
        } else {
            sceltaValida = true;
        }
    }

    // Chiedo dati.
    printf("\n\n|---------------------------------------"
           "\n| Inserire il nome dell'argomento: \n");
    cin.ignore();
    getline(cin, registro.nomeArgomento);
    printf("|---------------------------------------");

    // Richiamo metodo per modificare stringa.
    registro.nomeArgomento = sostituisciSpaziConTrattini(registro.nomeArgomento);

    int numeroConferma = 2;
    while (numeroConferma != 0 && numeroConferma != 1) {
        printf("\n\n|---------------------------------------"
               "\n| Vuoi firmare?"
               "\n| 0 -> No."
               "\n| 1 -> Si."
               "\n| Scelta: ");
        scanf("%d", &numeroConferma);
        printf("|---------------------------------------\n");

        if (numeroConferma == 1) {
            printf("\n|---------------------------------------"
                   "\n| Firmato con successo!"
                   "\n|---------------------------------------\n");
            registro.firmato = true;
        } else if (numeroConferma == 0) {
            printf("\n|---------------------------------------"
                   "\n| Non hai firmato"
                   "\n|---------------------------------------\n");
            registro.firmato = false;
        } else {
            printf("\n|---------------------------------------"
                   "\n| Hai inserito una opzione non valida, riprovare!"
                   "\n|---------------------------------------\n");
        }
    }

    printf("\n|---------------------------------------"
           "\n| Inserire il nome della classe: ");
    cin >> registro.classe;

    printf("| Classe inserita con successo!"
           "\n|---------------------------------------");

    // Scelta corso.
    bool valido = false;
    while (!valido) {
        int sceltaCorso;
        printf("\n\n|---------------------------------------"
               "\n| Inserire l'indirizzo dalla lista: ");
        printf("\n| 0 -> Non scegliere un indirizzo.");
        for (int i = 0; i < numeroCorsi; i++) {
            printf("\n| %d -> %s", i + 1, corsi.listaCorsi[i].c_str());
        }
        printf("\n| Scelta: ");
        scanf("%d", &sceltaCorso);
        if (sceltaCorso <= numeroCorsi) {
            if (sceltaCorso == 0) {
                registro.corso = "Nessuno";
                valido = true;
            } else {
                registro.corso = corsi.listaCorsi[sceltaCorso - 1];
                valido = true;
            }
        }
    }
    printf("\n|---------------------------------------");

    printf("\n\n|---------------------------------------"
           "\n| Salvataggio su file con successo!"
           "\n|---------------------------------------");
    if (registro.firmato) {
        fprintf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", registro.nomeInsegnante.c_str(),
                registro.nomeMateria.c_str(), registro.oraInizio.ora, registro.oraInizio.minuti.c_str(),
                registro.oraFine.ora,
                registro.oraFine.minuti.c_str(), registro.nomeArgomento.c_str(), "Firmato",
                registro.classe.c_str(), registro.corso.c_str());
    } else {
        fprintf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", registro.nomeInsegnante.c_str(),
                registro.nomeMateria.c_str(), registro.oraInizio.ora, registro.oraInizio.minuti.c_str(),
                registro.oraFine.ora,
                registro.oraFine.minuti.c_str(), registro.nomeArgomento.c_str(), "Non_Firmato",
                registro.classe.c_str(), registro.corso.c_str());
    }
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
        printf("\n|---------------------------------------"
               "\n| File config.txt nuovo creato con successo!"
               "\n|---------------------------------------\n");
        fclose(cfConfig);
        cfConfig = fopen("config.txt", "r");
    }
    return cfConfig;
}

void filtraPerIndirizzo(string &indirizzoScelto) {
    FILE *cfRegistro;
    cfRegistro = fopen("registro.txt", "r");

    if (cfRegistro == NULL){
        printf("\n| Il file non esiste e nemmeno un registro!");
    } else {

        int numeroRiepilogo = 1;
        printf("\n|---------------------------------------------------------|"
               "\n| Riepilogo registro per indirizzo %s:", indirizzoScelto.c_str());
        while (!feof(cfRegistro)) {

            char nomeInsegnante[dimensioneVettori];
            char materia[dimensioneVettori];
            int oraInizio;
            char minutiInizio[dimensioneVettori];
            int oraFine;
            char minutiFine[dimensioneVettori];
            char argomento[dimensioneVettori * 10];
            char firmato[dimensioneVettori];
            char classe[dimensioneVettori];
            char corso[dimensioneVettori];

            fscanf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", nomeInsegnante, materia, &oraInizio, minutiInizio,
                   &oraFine, minutiFine, argomento, firmato, classe, corso);

            if (corso == indirizzoScelto) {

                string argomentoFinale = sostituisciTrattiniConSpazi(argomento);

                printf("\n\n| Riepilogo: %d"
                       "\n| Nome insegnante: %s"
                       "\n| Nome materia: %s"
                       "\n| Ora di inzio: %d:%s"
                       "\n| Ora di fine: %d:%s"
                       "\n| Argomento: %s"
                       "\n| Firmato: %s"
                       "\n| Classe: %s"
                       "\n| Corso: %s", numeroRiepilogo++, nomeInsegnante, materia, oraInizio, minutiInizio, oraFine,
                       minutiFine, argomentoFinale.c_str(), firmato, classe, corso);

            }
        }
        if (numeroRiepilogo == 1) {
            printf("\n| Nessun indirizzo con quel nome trovato!"
                   "\n|---------------------------------------------------------|");
        }
    }
}

void filtraPerClasse(string &nomeClasseScelta) {

    FILE *cfRegistro;
    cfRegistro = fopen("registro.txt", "r");

    if (cfRegistro == NULL){
        printf("\n| Il file non esiste e nemmeno un registro!");
    } else {

        int numeroRiepilogo = 1;
        printf("\n|---------------------------------------------------------|"
               "\n| Riepilogo registro per classe %s:", nomeClasseScelta.c_str());
        while (!feof(cfRegistro)) {

            char nomeInsegnante[dimensioneVettori];
            char materia[dimensioneVettori];
            int oraInizio;
            char minutiInizio[dimensioneVettori];
            int oraFine;
            char minutiFine[dimensioneVettori];
            char argomento[dimensioneVettori * 10];
            char firmato[dimensioneVettori];
            char classe[dimensioneVettori];
            char corso[dimensioneVettori];

            fscanf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", nomeInsegnante, materia, &oraInizio, minutiInizio,
                   &oraFine, minutiFine, argomento, firmato, classe, corso);

            if (classe == nomeClasseScelta) {

                string argomentoFinale = sostituisciTrattiniConSpazi(argomento);

                printf("\n\n| Riepilogo: %d"
                       "\n| Nome insegnante: %s"
                       "\n| Nome materia: %s"
                       "\n| Ora di inzio: %d:%s"
                       "\n| Ora di fine: %d:%s"
                       "\n| Argomento: %s"
                       "\n| Firmato: %s"
                       "\n| Classe: %s"
                       "\n| Corso: %s", numeroRiepilogo++, nomeInsegnante, materia, oraInizio, minutiInizio, oraFine,
                       minutiFine, argomentoFinale.c_str(), firmato, classe, corso);

            }
        }
        if (numeroRiepilogo == 1) {
            printf("\n| Nessuna classe con quel nome trovata!"
                   "\n|---------------------------------------------------------|");
        }
    }
}

void filtraPerMateria(string &nomeMateriaScelta) {

    FILE *cfRegistro;
    cfRegistro = fopen("registro.txt", "r");

    if (cfRegistro == NULL){
        printf("\n| Il file non esiste e nemmeno un registro!");
    } else {
        int numeroRiepilogo = 1;
        printf("\n|---------------------------------------------------------|"
               "\n| Riepilogo registro per materia %s:", nomeMateriaScelta.c_str());
        while (!feof(cfRegistro)) {

            char nomeInsegnante[dimensioneVettori];
            char materia[dimensioneVettori];
            int oraInizio;
            char minutiInizio[dimensioneVettori];
            int oraFine;
            char minutiFine[dimensioneVettori];
            char argomento[dimensioneVettori * 10];
            char firmato[dimensioneVettori];
            char classe[dimensioneVettori];
            char corso[dimensioneVettori];

            fscanf(cfRegistro, "%s %s %d %s %d %s %s %s %s", nomeInsegnante, materia, &oraInizio, minutiInizio,
                   &oraFine, minutiFine, argomento, firmato, classe, corso);

            if (materia == nomeMateriaScelta) {

                string argomentoFinale = sostituisciTrattiniConSpazi(argomento);

                printf("\n\n| Riepilogo: %d"
                       "\n| Nome insegnante: %s"
                       "\n| Nome materia: %s"
                       "\n| Ora di inzio: %d:%s"
                       "\n| Ora di fine: %d:%s"
                       "\n| Argomento: %s"
                       "\n| Firmato: %s"
                       "\n| Classe: %s"
                       "\n| Corso %s", numeroRiepilogo++, nomeInsegnante, materia, oraInizio, minutiInizio, oraFine,
                       minutiFine, argomentoFinale.c_str(), firmato, classe, corso);


            }
        }
        if (numeroRiepilogo == 1) {
            printf("\n| Nessuna materia con quel nome trovata!"
                   "\n|---------------------------------------------------------|");
        }
    }
}

void filtraPerNomeInsegnante(string &nomeInsegnanteScelto) {

    FILE *cfRegistro;
    cfRegistro = fopen("registro.txt", "r");

    if (cfRegistro == NULL){
        printf("\n| Il file non esiste e nemmeno un registro!");
    } else {

        int numeroRiepilogo = 1;
        printf("\n|---------------------------------------------------------|"
               "\n| Riepilogo registro per insegnante %s:", nomeInsegnanteScelto.c_str());
        while (!feof(cfRegistro)) {

            char nomeInsegnante[dimensioneVettori];
            char materia[dimensioneVettori];
            int oraInizio;
            char minutiInizio[dimensioneVettori];
            int oraFine;
            char minutiFine[dimensioneVettori];
            char argomento[dimensioneVettori * 10];
            char firmato[dimensioneVettori];
            char classe[dimensioneVettori];
            char corso[dimensioneVettori];

            fscanf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", nomeInsegnante, materia, &oraInizio, minutiInizio,
                   &oraFine, minutiFine, argomento, firmato, classe, corso);

            if (nomeInsegnante == nomeInsegnanteScelto) {

                string argomentoFinale = sostituisciTrattiniConSpazi(argomento);

                printf("\n\n| Riepilogo: %d"
                       "\n| Nome insegnante: %s"
                       "\n| Nome materia: %s"
                       "\n| Ora di inzio: %d:%s"
                       "\n| Ora di fine: %d:%s"
                       "\n| Argomento: %s"
                       "\n| Firmato: %s"
                       "\n| Classe: %s"
                       "\n| Corso: %s", numeroRiepilogo++, nomeInsegnante, materia, oraInizio, minutiInizio, oraFine,
                       minutiFine, argomentoFinale.c_str(), firmato, classe, corso);


            }
        }
        if (numeroRiepilogo == 1) {
            printf("\n| Nessun insegnante con quel nome trovato!"
                   "\n|---------------------------------------------------------|");
        }
    }
}

void letturaFileRegistro() {
    FILE *cfRegistro;
    cfRegistro = fopen("registro.txt", "r");

    if (cfRegistro == NULL){
        printf("\n| Errore durante l'apertura del file, non esistente.");
    } else {

        int numeroRiepilogo = 1;

        printf("\n\n|---------------------------------------------------------|"
               "\n| Riepilogo generale: ");
        while (!feof(cfRegistro)){

            char nomeInsegnate[dimensioneVettori];
            char materia[dimensioneVettori];
            int oraInizio;
            char minutiInizio[dimensioneVettori];
            int oraFine;
            char minutiFine[dimensioneVettori];
            char argomento[dimensioneVettori * 10];
            char firmato[dimensioneVettori];
            char classe[dimensioneVettori];
            char corso[dimensioneVettori];

            fscanf(cfRegistro, "%s %s %d %s %d %s %s %s %s %s", nomeInsegnate, materia, &oraInizio, minutiInizio, &oraFine, minutiFine, argomento, firmato, classe, corso);

            string argomentoFinale = sostituisciTrattiniConSpazi(argomento);

            printf("\n| \n| Riepilogo: %d"
                   "\n| Nome insegnante: %s"
                   "\n| Nome materia: %s"
                   "\n| Ora di inzio: %d:%s"
                   "\n| Ora di fine: %d:%s"
                   "\n| Argomento: %s"
                   "\n| Firmato: %s"
                   "\n| Classe: %s"
                   "\n| Corso: %s", numeroRiepilogo++, nomeInsegnate, materia, oraInizio, minutiInizio, oraFine, minutiFine, argomentoFinale.c_str(), firmato, classe, corso);

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