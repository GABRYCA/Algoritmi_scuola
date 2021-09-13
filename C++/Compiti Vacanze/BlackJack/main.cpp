#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

void continua();

int randomMaxMin(int numeroMin, int numeroMax);

void nomiCarte(int numero, int tipo);


struct carteGiocatore{
    // Numero Carta, Tipo, Punti (valore della carta).
    int mano[5][3];
    int numeroCarte = 0;
};

void daiCartaGiocatore(carteGiocatore *giocatori, int numeroGiocatore);

int puntiTotaliGiocatore(const carteGiocatore *giocatori, int i);

int puntiTotaliBanco(const carteGiocatore *banco);

void daiCartaBanco(carteGiocatore *giocatori);

int carte[52][4] = {
        {1,1,0},
        {1,2,0},
        {1,3,0},
        {1,4,0},
        {1,5,0},
        {1,6,0},
        {1,7,0},
        {1,8,0},
        {1,9,0},
        {1,10,0},
        {1,11,0},
        {1,12,0},
        {1,13,0},
        {2,1,0},
        {2,2,0},
        {2,3,0},
        {2,4,0},
        {2,5,0},
        {2,6,0},
        {2,7,0},
        {2,8,0},
        {2,9,0},
        {2,10,0},
        {2,11,0},
        {2,12,0},
        {2,13,0},
        {3,1,0},
        {3,2,0},
        {3,3,0},
        {3,4,0},
        {3,5,0},
        {3,6,0},
        {3,7,0},
        {3,8,0},
        {3,9,0},
        {3,10,0},
        {3,11,0},
        {3,12,0},
        {3,13,0},
        {4,1,0},
        {4,2,0},
        {4,3,0},
        {4,4,0},
        {4,5,0},
        {4,6,0},
        {4,7,0},
        {4,8,0},
        {4,9,0},
        {4,10,0},
        {4,11,0},
        {4,12,0},
        {4,13,0},
};

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//           BlackJack di Gabriele Caretti 3BITI            //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;
    while (scelta != 0){

        printf("\n\nLegenda:"
               "\n0 -> Esci."
               "\n1 -> Blackjack."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");

                break;
            }

            case 1:{

                // Aggiungere opzione soldi in totale di riserva del giocatore, che aumenteranno o scenderanno quando vince
                // O perde.

                printf("\nHai scelto: Blackjack...");

                // Struttura: Puntata, totale, puo'Giocare (0 no, 1 si).
                int puntataGiocatori[1][3];
                // Inizializzo valori del puo' giocare giocatore:
                puntataGiocatori[0][2] = 1;

                // Ottiene dati necessari dal gioco con l'input dell'utente.
                bool puntataValida = false;
                while (!puntataValida){
                    printf("\nInserire quanto vuoi scommettere giocatore N.%d: ", 0 + 1);
                    scanf("%d", &puntataGiocatori[0][0]);
                    if (puntataGiocatori[0][0] > 0){
                        puntataValida = true;
                        printf("\nGiocatore %d ha puntato %d.\n", 0 + 1, puntataGiocatori[0][0]);

                        bool puntataTotaleValida = false;
                        while (!puntataTotaleValida) {
                            printf("\n\nQuanto vuoi investire per giocare?"
                                   "\nContinuerai a giocare fino a quando lo vuoi te oppure non avrai abbastanza soldi."
                                   "\nValore inserito: ");
                            scanf("%d", &puntataGiocatori[0][1]);
                            if (puntataGiocatori[0][1] >= puntataGiocatori[0][0]){
                                puntataTotaleValida = true;
                                printf("\nIl giocatore ha investito %d Euro per giocare!", puntataGiocatori[0][1]);
                            } else {
                                printf("\nPuntata non valida! Inserire un valore diverso!");
                            }
                        }

                    } else {
                        printf("\nHai scommesso una cifra non valida, per favore riprovare!");
                    }
                }

                // Inizializza random con il tempo.
                srand(time(0));

                // Continua a giocare fino a quando il giocatore si stufa o non ha piu' abbastanza soldi.
                bool vuoleGiocatoreEHaDenaro = true;
                while (vuoleGiocatoreEHaDenaro) {

                    // Carte da 1 a re e da fiori a picche, struttura: TipoCarta, Numero, inUso (0 se no, 1 se si).
                    // Reset carte utilizzate.
                    for (int i = 0; i < 52; i++) {
                        carte[i][2] = 0;
                    }

                    // Mischia le carte.
                    printf("\n\nInizia il gioco, mischiando le carte...");
                    // Mischio le carte per la prima volta
                    for (int i=0; i<52; i++){
                        int numeroACaso = randomMaxMin(0, 51);
                        for (int j = 0; j < 2; j++){
                            int valCarta1 = carte[i][j];
                            carte[i][j] = carte[numeroACaso][j];
                            carte[numeroACaso][j] = valCarta1;
                        }
                    }
                    printf("\n\nCarte mischiate con successo!");

                    // Struct dei giocatori (il banco funziona in modo simile).
                    carteGiocatore giocatori[1];
                    carteGiocatore banco[1];

                    // Aggiungo carte a giocatore.
                    printf("\n\nDando le prime 2 carte ai giocatori");

                    // Dare 2 carte ad ogni giocatore all'inizio.
                    for (int j = 0; j < 2; j++) {
                        // Struct giocatori, numero.
                        daiCartaGiocatore(giocatori, 0);
                    }

                    printf("\n\nDando le prime 2 carte al banco.");
                    // Dare 2 carte al banco.
                    for (int i = 0; i < 2; i++) {
                        daiCartaBanco(banco);
                    }

                    // Messaggio che comunica che le carte sono state date con successo.
                    printf("\nLe prime 2 carte sono state date a tutti, banco compreso! Inizio Blackjack...");


                    // Partita.
                    bool condizioneFinePartita = false;
                    while (!condizioneFinePartita) {

                        // Calcola punti banco.
                        int puntiBanco = puntiTotaliBanco(banco);

                        // Comunica numero di carte del banco.
                        printf("\n\nIl banco ha %d carte.", banco[0].numeroCarte);

                        // Calcola punti del giocatore.
                        int puntiGiocatore = puntiTotaliGiocatore(giocatori, 0);

                        // Inizio turno e opzioni possibili.
                        printf("\n\nInizio turno giocatore %d.", 1);
                        printf("\nGiocatore %d hai %d carte per un valore di %d punti.", 0 + 1,
                               giocatori[0].numeroCarte, puntiGiocatore);

                        if (giocatori[0].numeroCarte < 5 && puntataGiocatori[0][2] == 1) {

                            bool sceltaPescaValida = false;
                            while (!sceltaPescaValida) {

                                int pesca;
                                printf("\n\nVuoi pescare una carta oppure stare?"
                                       "\n0 -> Non pescare (Stai)."
                                       "\n1 -> Pesca."
                                       "\nScelta: ");
                                scanf("%d", &pesca);

                                if (pesca == 1) {
                                    printf("\nHai deciso di pescare una carta, attendere...");
                                    daiCartaGiocatore(giocatori, 0);
                                    sceltaPescaValida = true;
                                } else if (pesca == 0) {
                                    printf("\nHai deciso di NON pescare una carta, attesa risultati.");
                                    puntataGiocatori[0][2] = 0;
                                    condizioneFinePartita = true;
                                    sceltaPescaValida = true;
                                } else {
                                    printf("\nScelta non valida, per favore riprovare!");
                                }
                            }

                        } else {

                            puntataGiocatori[0][2] = 0;
                            printf("\nNon puoi piu' giocare perche' hai troppe carte, passando ai risultati...");
                            condizioneFinePartita = true;

                        }

                        puntiGiocatore = puntiTotaliGiocatore(giocatori, 0);

                        // Verifica se qualcuno ha sballato.
                        if (puntiBanco > 21) {

                            printf("\nIl banco ha sballato!");
                            condizioneFinePartita = true;

                        }
                        if (puntiGiocatore > 21) {

                            printf("\nIl giocatore ha sballato!");
                            condizioneFinePartita = true;

                        }

                        // Aggiunge una carta al mazzo del banco.
                        if (!condizioneFinePartita) {
                            if (puntiBanco < 17 && banco[0].numeroCarte < 5) {
                                daiCartaBanco(banco);
                                printf("\n\nIl banco ha pescato una carta!");
                            } else {
                                printf("\n\nIl banco non ha pescato una carta!");
                            }
                            puntiBanco = puntiTotaliBanco(banco);
                            if (puntiBanco > 21) {
                                printf("\n\nIl banco ha sballato!");
                                condizioneFinePartita = true;
                            }
                        }
                    }

                    // Calcola punti giocatore.
                    int puntiGiocatore = puntiTotaliGiocatore(giocatori, 0), puntiBanco = puntiTotaliBanco(banco);

                    // Comunica le carte pescate da banco e giocatore.
                    printf("\n\nFine fase di pesca delle carte, il banco ha %d punti e il giocatore %d", puntiBanco, puntiGiocatore);
                    printf("\n\nLe carte del giocatore sono:");
                    for (int i = 0; i < giocatori[0].numeroCarte; i++) {
                        printf("\n%d: \t", i + 1);
                        nomiCarte(giocatori[0].mano[i][1], giocatori[0].mano[i][0]);
                    }

                    // Comunica un riepilogo delle carte del banco.
                    printf("\n\nE le carte del banco invece: ");
                    for (int i = 0; i < banco[0].numeroCarte; i++) {
                        printf("\n%d: \t", i + 1);
                        nomiCarte(banco[0].mano[i][1], banco[0].mano[i][0]);
                    }
                    printf("\n");

                    if (puntiGiocatore > 21 && puntiBanco > 21) {

                        puntataGiocatori[0][1] -= puntataGiocatori[0][0];

                        // Verifica se sia il banco che il giocatore hanno sballato e lo comunica.
                        printf("\nIl giocatore e il banco hanno sballato! \nIl giocatore ha perso una cifra pari ai soldi scommessi!");

                    } else if (puntiBanco > 21 && puntiGiocatore <= 21) {

                        // Verifica se avvenuto blackjack.
                        if (puntiGiocatore == 21) {

                            // Calcola soldi vinti.
                            int soldiVinti = puntataGiocatori[0][0] + (puntataGiocatori[0][0] / 2 * 3);

                            // Incrementa soldi vinti.
                            puntataGiocatori[0][1] += soldiVinti;

                            // Messaggio di riepilogo.
                            printf("\nAvendo fatto un blackjack il giocatore e vinto (il banco ha sballato), guadagnerà una quantita' di denaro"
                                   "\npari a 3:2 della sua scommessa, ossia %d."
                                   "\nIl giocatore in totale ha %d soldi!", soldiVinti, puntataGiocatori[0][1]);

                        } else {

                            // Incrementa totale giocatore.
                            puntataGiocatori[0][1] += puntataGiocatori[0][0] * 2;

                            // Messaggio di riepilogo.
                            printf("\nIl banco ha sballato quindi ha vinto il giocatore il valore"
                                   "\nscommesso, ossia %d e ora ha in totale %d.", puntataGiocatori[0][0],
                                   puntataGiocatori[0][1]);

                        }
                    } else if ((puntiGiocatore == puntiBanco) || (puntiGiocatore > 21 && puntiBanco > 21)) {

                        puntataGiocatori[0][1] -= puntataGiocatori[0][0];

                        // Messaggio di riepilogo e pareggio banco con giocatore.
                        printf("\nE' un pareggio! Il giocatore ha perso una cifra pari ai soldi scommessi.");

                    } else if (puntiBanco <= 21 && puntiGiocatore > 21) {

                        // Verifica se avvenuto blackjack.
                        if (puntiBanco == 21) {

                            // Calcola soldi persi.
                            int soldiPersi = puntataGiocatori[0][0] + (puntataGiocatori[0][0] / 2 * 3);

                            // Decrementa soldi totali.
                            puntataGiocatori[0][1] -= soldiPersi;

                            // Messaggio di riepilogo.
                            printf("\nHai sballato e il banco ha fatto blackjack, hai perso una scommessa pari"
                                   "\na 3:2 di quello che avevi fatto, ossia %d e ora hai in totale %d.",
                                   soldiPersi, puntataGiocatori[0][1]);

                        } else {

                            // Decrementa soldi totali.
                            puntataGiocatori[0][1] -= puntataGiocatori[0][0];

                            // Messaggio di riepilogo.
                            printf("\nHai sballato e perso la scommessa, ossia %d e ora hai in totale %d!",
                                   puntataGiocatori[0][0], puntataGiocatori[0][1]);

                        }
                    } else if (puntiGiocatore > puntiBanco) {

                        // Verifica se e' avvenuto anche il blackjack.
                        if (puntiGiocatore <= 21) {

                            // Calcola soldi vinti.
                            int soldiVinti = puntataGiocatori[0][0] + (puntataGiocatori[0][0] / 2 * 3);

                            // Incrementa soldi totali.
                            puntataGiocatori[0][1] += soldiVinti;

                            // Messaggio di riepilogo.
                            printf("\nHai vinto e fatto anche blackjack, quindi vinci una cifra pari a"
                                   "\n3:2 di quello che hai scommesso, ossia %d e hai in totale %d.",
                                   soldiVinti,
                                   puntataGiocatori[0][1]);

                        } else {

                            // Incrementa soldi totali.
                            puntataGiocatori[0][1] += puntataGiocatori[0][0];

                            // Messaggio di riepilogo.
                            printf("\nHai fatto %d punti mentre il banco %d, quindi hai vinto un valore"
                                   "\npari alla scommessa, ossia %d e hai ora in totale %d.", puntiGiocatore,
                                   puntiBanco, puntataGiocatori[0][0], puntataGiocatori[0][1]);

                        }

                    } else if (puntiGiocatore < puntiBanco) {

                        // Verifica se avvenuto anche blackjack.
                        if (puntiBanco <= 21) {

                            // Calcola soldi persi.
                            int soldiPersi = puntataGiocatori[0][0] + (puntataGiocatori[0][0] / 2 * 3);

                            // Diminuisce soldi totali.
                            puntataGiocatori[0][1] -= soldiPersi;

                            // Messaggio di riepilogo.
                            printf("\nIl banco ha fatto blackjack e te hai perso, hai perso una cifra pari a 3:2 di "
                                   "\nquella scommessa, ossia %d e hai in totale %d.", soldiPersi,
                                   puntataGiocatori[0][1]);

                        } else {

                            // Diminuisce soldi totali.
                            puntataGiocatori[0][1] -= puntataGiocatori[0][0];

                            // Messaggio risultati.
                            printf("\nHai perso contro il banco e perso la cifra scommessa, ossia %d e ora hai in totale %d",
                                   puntataGiocatori[0][0], puntataGiocatori[0][1]);

                        }

                    } else {

                        // E' successo qualcosa di strano che non doveva succedere oppure e' stato dimenticato.
                        printf("\nAvvenuta una situazione non prevista, i punti del banco sono %d e quelli del giocatore %d.",
                               puntiBanco, puntiGiocatore);

                    }

                    // Se il giocatore ha abbastanza soldi allora viene chiesto se vuole continuare a giocare.
                    if (puntataGiocatori[0][1] >= puntataGiocatori[0][0]){
                        int vuoleContinuare;
                        printf("\n\nIn totale hai %d soldi e quindi puoi continuare a giocare, vuoi continuare?"
                               "\n1 -> Si."
                               "\nNumero a caso -> No."
                               "\nScelta: ");
                        scanf("%d", &vuoleContinuare);

                        // Inizializzo valori del puo' giocare giocatore:
                        puntataGiocatori[0][2] = 1;

                        // Opzione in base all'input del giocatore.
                        if (vuoleContinuare != 1){

                            vuoleGiocatoreEHaDenaro = false;

                            // Elimino giocatore dal gioco.
                            puntataGiocatori[0][2] = 1;

                            printf("\nHai deciso di smettere di giocare...");
                        }

                    } else {

                        // Mancano soldi al giocatore e non puo' piu' continuare.
                        printf("\nNon hai abbastanza soldi per continuare a giocare, fine partita!");
                        vuoleGiocatoreEHaDenaro = false;

                        // Lo elimino dal gioco.
                        puntataGiocatori[0][2] = 0;

                    }
                }


                printf("\nUscito dal gioco con successo!");
                continua();
                break;
            }

            default:{

                printf("\nScelta non valida, per favore riprovare.");

                break;
            }


        }

    }

    printf("\n\nUscito con successo!");

    return 0;
}

int puntiTotaliBanco(const carteGiocatore *banco) {
    int numeroTotalePuntiBanco = 0;
    for (int j = 0; j < banco[0].numeroCarte; j++) {
        numeroTotalePuntiBanco += banco[0].mano[j][2];
    }
    return numeroTotalePuntiBanco;
}

int puntiTotaliGiocatore(const carteGiocatore *giocatori, int i) {
    int numeroTotalePuntiGiocatore = 0;
    for (int j = 0; j < giocatori[i].numeroCarte; j++) {
        numeroTotalePuntiGiocatore += giocatori[i].mano[j][2];
    }
    return numeroTotalePuntiGiocatore;
}

void daiCartaGiocatore(carteGiocatore *giocatori, int numeroGiocatore) {

    if (giocatori[numeroGiocatore].numeroCarte < 5) {
        bool cartaValidaAggiunta = false;
        while (!cartaValidaAggiunta) {
            int tipoCarta = randomMaxMin(0, 51);
            if (carte[tipoCarta][2] == 0) {
                cartaValidaAggiunta = true;
                carte[tipoCarta][2] = 1;
                giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte][0] = carte[tipoCarta][0];
                giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte][1] = carte[tipoCarta][1];
                if (carte[tipoCarta][1] == 1){
                    bool sceltaPuntiValida = false;
                    while (!sceltaPuntiValida) {
                        int sceltaPunti;
                        printf("\nQuesta carta puo' valere sia 1 che 11 (Asso), scegliere"
                               "\n0 -> 1."
                               "\n1 -> 11."
                               "\nScelta: ");
                        scanf("%d", &sceltaPunti);
                        if (sceltaPunti == 1 || sceltaPunti == 0){
                            if (sceltaPunti == 1) {
                                giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte][2] = 11;
                            } else {
                                giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte][2] = 1;
                            }
                            sceltaPuntiValida = true;
                        } else {
                            printf("\nScelta non valida, per favore riprovare.");
                        }
                    }
                } else if (carte[tipoCarta][1] > 10){
                    giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte][2] = 10;
                } else {
                    giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte][2] = carte[tipoCarta][1];
                }
                giocatori[numeroGiocatore].numeroCarte++;
            }
        }
        printf("\n\nHai ricevuto una carta giocatore N.%d,"
               "\nLa carta vale %d punti."
               "\nLa carta e' una: ", numeroGiocatore + 1, giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte - 1][2]);
        nomiCarte(giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte - 1][1], giocatori[numeroGiocatore].mano[giocatori[numeroGiocatore].numeroCarte - 1][0]);
    } else {
        printf("\nIl giocatore ha gia' raggiunto il numero massimo di carte.");
    }
}

void daiCartaBanco(carteGiocatore *giocatori) {

    if (giocatori[0].numeroCarte < 5) {
        bool cartaValidaAggiunta = false;
        while (!cartaValidaAggiunta) {
            int tipoCarta = randomMaxMin(0, 51);
            if (carte[tipoCarta][2] == 0) {
                cartaValidaAggiunta = true;
                carte[tipoCarta][2] = 1;
                giocatori[0].mano[giocatori[0].numeroCarte][0] = carte[tipoCarta][0];
                giocatori[0].mano[giocatori[0].numeroCarte][1] = carte[tipoCarta][1];
                if (carte[tipoCarta][1] == 1){
                    int puntiBanco = puntiTotaliBanco(giocatori);
                    if (puntiBanco + 11 < 21) {
                        giocatori[0].mano[giocatori[0].numeroCarte][2] = 11;
                    } else {
                        giocatori[0].mano[giocatori[0].numeroCarte][2] = 1;
                    }
                } else if (carte[tipoCarta][1] > 10){
                    giocatori[0].mano[giocatori[0].numeroCarte][2] = 10;
                } else {
                    giocatori[0].mano[giocatori[0].numeroCarte][2] = carte[tipoCarta][1];
                }
                giocatori[0].numeroCarte++;
            }
        }
    } else {
        printf("\nIl giocatore ha gia' raggiunto il numero massimo di carte.");
    }
}

int randomMaxMin(int numeroMin, int numeroMax) {
    return rand() % (numeroMax - numeroMin + 1) + numeroMin;
}

void nomiCarte(int numero, int tipo) {

    string carta;

    if (numero == 1){

        carta = "Asso";

    } else if (numero == 11){

        carta = "Jack";

    } else if (numero == 12){

        carta = "Regina";

    } else if (numero == 13){

        carta = "Re";

    } else {

        carta = to_string(numero);

    }

    carta = carta + " di ";

    switch (tipo) {
        case 1:{

            carta = carta + "Fiori";

            break;
        }
        case 2:{

            carta = carta + "Quadri";

            break;
        }
        case 3:{

            carta = carta + "Cuori";

            break;
        }
        case 4:{

            carta = carta + "Picche";

            break;
        }
        default:{

            carta = carta + "Sconosciuto";

            break;
        }
    }
    printf("%s", carta.c_str());
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}
