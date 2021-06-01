#include <iostream>
#include <string>
#include <time.h>

using namespace std;

struct cartella{
    int riga1[9] = {0};
    int riga2[9] = {0};
    int riga3[9] = {0};
    bool trvRiga1[9] = {false};
    bool trvRiga2[9] = {false};
    bool trvRiga3[9] = {false};
    bool comboFatte[4] = {false}; // 0 = Ambo, 1 = Terna, 2 = Quaterna, 3 = Cinquina.
};


void continua();

int randomMaxMin(int numeroMin, int numeroMax);

void mostraCartella(const cartella *cartelle, int generateSuccesso);

void generatoreCartelle(int numeroGiocatori, const cartella *cartelle);

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
               "\n1 -> Inizio gioco."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Inizio gioco...");

                bool ambo = false, terna = false, quaterna = false, cinquina = false;
                int numeroGiocatori;
                printf("\n\nInserire numero giocatori: ");
                scanf("%d", &numeroGiocatori);

                cartella cartelle[numeroGiocatori];

                // Generazione cartelle.
                generatoreCartelle(numeroGiocatori, cartelle);

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

void generatoreCartelle(int numeroGiocatori, const cartella *cartelle) {
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
                cartelle[generateSuccesso].riga1[colonnaInLavorazione] = randomMaxMin(numeroMin, numeroMax);
                cartelle[generateSuccesso].riga2[colonnaInLavorazione] = randomMaxMin(numeroMin, numeroMax);
                cartelle[generateSuccesso].riga3[colonnaInLavorazione] = randomMaxMin(numeroMin, numeroMax);
                if (cartelle[generateSuccesso].riga1[colonnaInLavorazione] != cartelle[generateSuccesso].riga2[colonnaInLavorazione] && cartelle[generateSuccesso].riga1[colonnaInLavorazione] != cartelle[generateSuccesso].riga3[colonnaInLavorazione] && cartelle[generateSuccesso].riga2[colonnaInLavorazione] != cartelle[generateSuccesso].riga3[colonnaInLavorazione]){
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
                if (i == 0){

                    if (cartelle[generateSuccesso].riga1[posizioneVuoto] != 0){
                        cartelle[generateSuccesso].riga1[posizioneVuoto] = 0;
                        nSpaziVuotiValidi++;
                    }

                } else if (i == 1){

                    if (cartelle[generateSuccesso].riga2[posizioneVuoto] != 0){
                        cartelle[generateSuccesso].riga2[posizioneVuoto] = 0;
                        nSpaziVuotiValidi++;
                    }

                } else if (i == 2){

                    if (cartelle[generateSuccesso].riga3[posizioneVuoto] != 0){
                        cartelle[generateSuccesso].riga3[posizioneVuoto] = 0;
                        nSpaziVuotiValidi++;
                    }

                }
            }
        }

        bool trovataColonnaVuota = false;
        for (int i = 0; i < 9; i++) {
            if (cartelle[generateSuccesso].riga1[i] == 0 && cartelle[generateSuccesso].riga2[i] == 0 && cartelle[generateSuccesso].riga3[i] == 0){
                trovataColonnaVuota = true;
            }
        }

        if (!trovataColonnaVuota){
            int conferma;
            printf("\n\nGiocatore n.%d"
                   "\nEcco la tua cartella: \n", generateSuccesso + 1);

            // Mostro la cartella
            mostraCartella(cartelle, generateSuccesso);

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
    for (int i = 0; i < 9; i++) {
        int numeroLetto = cartelle[generateSuccesso].riga1[i];
        if (numeroLetto != 0) {
            printf("%d\t", numeroLetto);
        } else {
            printf("[]\t");
        }
    }

    printf("\n");

    for (int i = 0; i < 9; i++) {
        int numeroLetto = cartelle[generateSuccesso].riga2[i];
        if (numeroLetto != 0) {
            printf("%d\t", numeroLetto);
        } else {
            printf("[]\t");
        }
    }

    printf("\n");

    for (int i = 0; i < 9; i++) {
        int numeroLetto = cartelle[generateSuccesso].riga3[i];
        if (numeroLetto != 0) {
            printf("%d\t", numeroLetto);
        } else {
            printf("[]\t");
        }
    }
}

int randomMaxMin(int numeroMin, int numeroMax) { return rand() % (numeroMax - numeroMin + 1) + numeroMin; }

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}