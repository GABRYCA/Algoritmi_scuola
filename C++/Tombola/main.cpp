#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

struct cartella{
    int righe[3][9] = {{0}};
    bool trvRiga1[3][9] = {{false}};
    bool comboFatte[4] = {false}; // 0 = Ambo, 1 = Terna, 2 = Quaterna, 3 = Cinquina.
};

void continua();

int randomMaxMin(int numeroMin, int numeroMax);

void mostraCartella(const cartella *cartelle, int generateSuccesso);

void generatoreCartelle(int numeroGiocatori, cartella *cartelle);

bool controlloNumeroCG(cartella *cartelle, int numeroGenerato, int i);

void leggiCartellaEventiNormali(const cartella *cartelle, int i, int j);

void leggiCartellaTrovati(const cartella *cartelle, int i);

int contaNumeriTrovati(const cartella *cartelle, int i, int numeroVeriTrovatiRiga);

void cambiaStatoProssimoEvento(const bool *tipoEventi, bool &ambo, bool &terna, bool &quaterna, bool &cinquina,
                               bool &tombola);

int ContaTrovatiPerRiga(const cartella *cartelle, int i, int j);

void condizioniProssimoEvento(bool ambo, bool terna, bool quaterna, bool cinquina, string &azioneNome,
                              string &prossimaAzioneNome, int &veriRichiesti, bool &tombolaRichiesta);

void giocoTombola(bool pausaTurni, int numeroGiocatori);

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//          Tombola di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;

    srand(time(0));

    while (scelta != 0){

        printf("\nLegenda:"
               "\n0 -> Esci."
               "\n1 -> Inizio gioco (Conferma ad ognu turno)."
               "\n2 -> Inizio gioco veloce (Mostra solamente un riepilogo)."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Inizio gioco normale...");

                bool pausaTurni = true;
                int numeroGiocatori;
                printf("\n\nInserire numero giocatori: ");
                scanf("%d", &numeroGiocatori);

                giocoTombola(pausaTurni, numeroGiocatori);

                break;
            }

            case 2:{

                printf("\nHai scelto: Inizio gioco veloce...");

                bool pausaTurni = false;
                int numeroGiocatori;
                printf("\n\nInserire numero giocatori: ");
                scanf("%d", &numeroGiocatori);

                giocoTombola(pausaTurni, numeroGiocatori);

                continua();
                break;
            }

            default:{

                printf("\nHai inserito una scelta non valida!");

                break;
            }
        }

    }

    printf("\n\nUscito con successo!");


    return 0;
}

void giocoTombola(bool pausaTurni, int numeroGiocatori) {
    bool ambo = false, terna = false, quaterna = false, cinquina = false, vittoria = false;

    // Struttura con tutte le cartelle dei giocatori.
    cartella cartelle[numeroGiocatori];

    // Generazione cartelle.
    generatoreCartelle(numeroGiocatori, cartelle);

    // Inizio del gioco.
    printf("\n\nLe cartelle sono state generate, ecco un riepilogo: ");

    for (int i = 0; i < numeroGiocatori; i++) {
        printf("\n\n-------------------------------------------------------------------"
               "\n| Cartella giocatore %d: "
               "\n-------------------------------------------------------------------\n", i + 1);
        mostraCartella(cartelle, i);
        printf("-------------------------------------------------------------------");
    }

    continua();

    printf("\n\n-------------------------------------------------------------------"
           "\n| Inizio del gioco, inserire un carattere per continuare ad ogni turno!"
           "\n-------------------------------------------------------------------");

    // Gioco effettivo.
    bool numeriGenerati[90] = {false};
    int numeroRound = 0;
    bool tombola = false;
    while (!vittoria && numeroRound < 90){
        numeroRound++;

        // Cerca un numero che non sia gia' stato estratto.
        int numeroGenerato = randomMaxMin(1, 89);
        while (numeriGenerati[numeroGenerato]){
            numeroGenerato = randomMaxMin(1, 89);
        }

        // Aggiunge il numero a quelli estratti in modo che non si ripeta.
        numeriGenerati[numeroGenerato] = true;

        printf("\n\n-------------------------------------------------------------------"
               "\n| Numero estratto: %d"
               "\n-------------------------------------------------------------------", numeroGenerato);

        // Controlla cartelle.
        bool tipoEventi[5] = {false}; // 0 = Ambo, 1 = Terna, 2 = Quaterna, 3 = Cinquina, 4 = Tombola.
        int quantiEventi = 0;
        string azioneNome;
        string prossimaAzioneNome;
        for (int i = 0; i < numeroGiocatori; i++) {

            bool trovatoNumero, tombolaRichiesta = false;
            int veriRichiesti;
            // Controlla singolo giocatore, partendo dalle righe.
            trovatoNumero = controlloNumeroCG(cartelle, numeroGenerato, i);


            // Controllare se qualcuno ha fatto qualcosa di valido sulla sua cartella.
            condizioniProssimoEvento(ambo, terna, quaterna, cinquina, azioneNome, prossimaAzioneNome,
                                     veriRichiesti, tombolaRichiesta);

            if (trovatoNumero){

                // Controllo gli eventi già avvenuti
                bool lettoScheda = false;
                condizioniProssimoEvento(ambo, terna, quaterna, cinquina, azioneNome, prossimaAzioneNome,
                                         veriRichiesti, tombolaRichiesta);

                // Verifico se è richiesta la tombola ossia una condizione speciale.
                if (!tombolaRichiesta){

                    // Controllo riga e conto quanti numeri sono stati trovati in essa.
                    for (int j = 0; j < 3; j++) {

                        // Controllo colonna.
                        int numeroVeriTrovatiRiga = ContaTrovatiPerRiga(cartelle, i, j);

                        // Se sono stati trovati valori veri quanti quelli richiesti per il prossimo evento, proseguo e mostro la
                        // Cartella con i valori afflitti dall'evento.
                        if (numeroVeriTrovatiRiga == veriRichiesti){

                            printf("\n\n***-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-***"
                                   "\n| Complimenti giocatore N.%d..."
                                   "\n| Hai fatto %s!", i + 1, azioneNome.c_str());
                            printf("\n| Ecco la cartella con i valori evidenziati nei {x} (per l'evento) "
                                   "\n| e -x- per quelli trovati:");
                            tipoEventi[veriRichiesti-2] = true;
                            quantiEventi++;

                            // Leggo righe.
                            printf("\n-------------------------------------------------------------------\n");
                            leggiCartellaEventiNormali(cartelle, i, j);
                            printf("-------------------------------------------------------------------");
                            lettoScheda = true;

                        }
                    }

                    if (!lettoScheda){

                        printf("\n\n-------------------------------------------------------------------"
                               "\n| Giocatore N.%d..."
                               "\n| Hai trovato un numero, ecco un riepilogo della tua scheda con"
                               "\n| I numeri trovati circondati da -x-:", i + 1);
                        printf("\n-------------------------------------------------------------------\n");
                        leggiCartellaTrovati(cartelle, i);
                        printf("-------------------------------------------------------------------");

                    }
                } else {

                    int numeroVeriTrovatiRiga = 0;
                    numeroVeriTrovatiRiga = contaNumeriTrovati(cartelle, i, numeroVeriTrovatiRiga);

                    if (numeroVeriTrovatiRiga == 15){

                        printf("\n\n*******************************************************************"
                               "\n| Congratulazioni giocatore N.%d! Hai fatto tombola!"
                               "\n*******************************************************************", i + 1);
                        tipoEventi[4] = true;
                        quantiEventi++;

                        printf("\n-------------------------------------------------------------------\n");
                        leggiCartellaTrovati(cartelle, i);
                        printf("-------------------------------------------------------------------");

                    } else {

                        printf("\n\n-------------------------------------------------------------------"
                               "\n| Giocatore N.%d..."
                               "\n| Hai trovato un numero, ecco un riepilogo della tua scheda con"
                               "\n| I numeri trovati circondati da -x-:", i + 1);
                        printf("\n-------------------------------------------------------------------\n");
                        leggiCartellaTrovati(cartelle, i);
                        printf("-------------------------------------------------------------------");
                    }
                }
            }

        }

        if (quantiEventi != 0) {

            if (!tipoEventi[4]) {

                printf("\nSono state trovate %d %s! Ora si punta a %s!", quantiEventi, azioneNome.c_str(), prossimaAzioneNome.c_str());

                cambiaStatoProssimoEvento(tipoEventi, ambo, terna, quaterna, cinquina, tombola);
            } else {

                printf("\n\nE' stata fatta tombola! Fine partita!");
                vittoria = true;

            }
        } else {
            printf("\n\nNessuno ha fatto %s, per favore procedere!", azioneNome.c_str());

        }

        if (pausaTurni) {
            continua();
        }
    }
    if (numeroRound > 90){
        printf("\n\nNessuno ha vinto in qualche modo, tutti i numeri sono stati estratti!");
    }
}

void condizioniProssimoEvento(bool ambo, bool terna, bool quaterna, bool cinquina, string &azioneNome,
                              string &prossimaAzioneNome, int &veriRichiesti, bool &tombolaRichiesta) {
    if (!ambo){
        veriRichiesti = 2;
        azioneNome = "Ambo";
        prossimaAzioneNome = "Terna";
    } else if (!terna){
        veriRichiesti = 3;
        azioneNome = "Terna";
        prossimaAzioneNome = "Quaterna";
    } else if (!quaterna){
        veriRichiesti = 4;
        azioneNome = "Quaterna";
        prossimaAzioneNome = "Cinquina";
    } else if (!cinquina){
        veriRichiesti = 5;
        azioneNome = "Cinquina";
        prossimaAzioneNome = "Tombola";
    } else {
        tombolaRichiesta = true;
        azioneNome = "Tombola";
        prossimaAzioneNome = "Fine partita!";
    }
}

int ContaTrovatiPerRiga(const cartella *cartelle, int i, int j) {
    int numeriVeriTrovatiRiga = 0;
    for (int k = 0; k < 9; k++) {
        if (cartelle[i].trvRiga1[j][k]){
            numeriVeriTrovatiRiga++;
        }
    }
    return numeriVeriTrovatiRiga;
}

void cambiaStatoProssimoEvento(const bool *tipoEventi, bool &ambo, bool &terna, bool &quaterna, bool &cinquina,
                               bool &tombola) {
    for (int i = 0; i < 5; i++) {
        if (tipoEventi[i]) {
            switch (i) {
                case 0: {

                    ambo = true;

                    break;
                }

                case 1: {

                    terna = true;

                    break;
                }

                case 2: {

                    quaterna = true;

                    break;
                }


                case 3: {

                    cinquina = true;

                    break;
                }

                case 4: {

                    tombola = true;

                    break;
                }

                default: {

                    printf("\n\nNon doveva succedere, errore ignorabile!");

                    break;
                }
            }
        }
    }
}

int contaNumeriTrovati(const cartella *cartelle, int i, int numeroVeriTrovatiRiga) {
    for (int j = 0; j < 3; j++) {

        // Controllo colonna.
        for (int k = 0; k < 9; k++) {
            if (cartelle[i].trvRiga1[j][k]){
                numeroVeriTrovatiRiga++;
            }
        }
    }
    return numeroVeriTrovatiRiga;
}

void leggiCartellaTrovati(const cartella *cartelle, int i) {// Leggo righe.
    for (int k = 0; k < 3; k++) {

        for (int l = 0; l < 9; l++) {
            int valoreLetto = cartelle[i].righe[k][l];
            if (valoreLetto == 0){

                printf("[]\t");

            } else {

                if (cartelle[i].trvRiga1[k][l]){

                    printf("-%d-\t", valoreLetto);

                } else {

                    printf("%d\t", valoreLetto);

                }

            }
        }

        printf("\n");
    }
}

void leggiCartellaEventiNormali(const cartella *cartelle, int i, int j) {
    for (int k = 0; k < 3; k++) {

        // La riga in lettura corrisponde con quella in cui sono stati trovati gli elementi.
        if (k == j){

            // Leggo colonne.
            for (int l = 0; l < 9; l++) {

                int valoreLetto = cartelle[i].righe[k][l];

                if (valoreLetto == 0){

                    printf("[]\t");

                } else {

                    if (cartelle[i].trvRiga1[k][l]) {
                        printf("{%d}\t", valoreLetto);
                    } else {
                        printf("%d\t", valoreLetto);
                    }

                }

            }

        } else {
            // Leggo colonne.
            for (int l = 0; l < 9; l++) {

                int valoreLetto = cartelle[i].righe[k][l];

                if (valoreLetto == 0){

                    printf("[]\t");

                } else {

                    if (cartelle[i].trvRiga1[k][l]){
                        printf("-%d-\t", valoreLetto);

                    } else {
                        printf("%d\t", valoreLetto);
                    }
                }

            }
        }

        printf("\n");
    }
}

bool controlloNumeroCG(cartella *cartelle, int numeroGenerato, int i) {
    bool trovatoNumero = false;
    for (int j = 0; j < 3; j++) {

        // E poi numero colonna.
        for (int k = 0; k < 9; k++) {

            if (numeroGenerato == cartelle[i].righe[j][k]){
                cartelle[i].trvRiga1[j][k] = true;
                trovatoNumero = true;
            }
        }
    }
    return trovatoNumero;
}

void generatoreCartelle(int numeroGiocatori, cartella *cartelle) {
    int generateSuccesso = 0;
    // Continua a generare fino a quando non l'ha fatto per tutti i giocatori.
    while (generateSuccesso < numeroGiocatori){

        // Generazione singola cartella.
        int colonnaInLavorazione = 0;
        int numeroMin = 1, numeroMax = 9;
        while(colonnaInLavorazione < 9){

            // Genera colonna
            int numeriValidiFatti = 0;
            while (numeriValidiFatti < 3) {
                cartelle[generateSuccesso].righe[0][colonnaInLavorazione] = randomMaxMin(numeroMin, numeroMax);
                cartelle[generateSuccesso].righe[1][colonnaInLavorazione] = randomMaxMin(numeroMin, numeroMax);
                cartelle[generateSuccesso].righe[2][colonnaInLavorazione] = randomMaxMin(numeroMin, numeroMax);
                if (cartelle[generateSuccesso].righe[0][colonnaInLavorazione] != cartelle[generateSuccesso].righe[1][colonnaInLavorazione] && cartelle[generateSuccesso].righe[0][colonnaInLavorazione] != cartelle[generateSuccesso].righe[2][colonnaInLavorazione] && cartelle[generateSuccesso].righe[1][colonnaInLavorazione] != cartelle[generateSuccesso].righe[2][colonnaInLavorazione]){
                    numeriValidiFatti++;
                }
            }

            // Verifica condizioni colonna
            if (colonnaInLavorazione == 0){
                numeroMin += 9;
            } else {
                numeroMin += 10;
            }
            numeroMax += 10;
            colonnaInLavorazione++;
        }

        // Inserisci spazi vuoti nelle righe
        for (int i = 0; i < 3; i++) {

            int nSpaziVuotiValidi = 0;
            while (nSpaziVuotiValidi < 4){
                int posizioneVuoto = rand() % 9;
                if (cartelle[generateSuccesso].righe[i][posizioneVuoto] != 0){
                    cartelle[generateSuccesso].righe[i][posizioneVuoto] = 0;
                    nSpaziVuotiValidi++;
                }
            }
        }

        bool trovataColonnaVuota = false;
        for (int i = 0; i < 9; i++) {
            if (cartelle[generateSuccesso].righe[0][i] == 0 && cartelle[generateSuccesso].righe[1][i] == 0 && cartelle[generateSuccesso].righe[2][i] == 0){
                trovataColonnaVuota = true;
            }
        }

        if (!trovataColonnaVuota){
            int conferma;
            printf("\n\nGiocatore n.%d"
                   "\nEcco la tua cartella: ", generateSuccesso + 1);

            // Mostro la cartella
            printf("\n-------------------------------------------------------------------\n");
            mostraCartella(cartelle, generateSuccesso);
            printf("-------------------------------------------------------------------");

            printf("\n\nVuoi tenerla o crearne una nuova?"
                   "\n0 -> Crea una nuova."
                   "\n1 -> Tieni questa."
                   "\nPS: Qualsiasi numero per crearne una nuova."
                   "\nScelta: ");
            scanf("%d", &conferma);

            if (conferma == 1) {
                generateSuccesso++;
            }
        }

    }
}

void mostraCartella(const cartella *cartelle, int generateSuccesso) {
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 9; j++) {
            int numeroLetto = cartelle[generateSuccesso].righe[i][j];
            if (numeroLetto == 0){
                printf("[]\t");
            } else {
                printf("%d\t", numeroLetto);
            }
        }

        printf("\n");
    }
}

int randomMaxMin(int numeroMin, int numeroMax) { return rand() % (numeroMax - numeroMin + 1) + numeroMin; }

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}