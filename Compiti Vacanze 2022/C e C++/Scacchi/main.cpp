#include <iostream>
#include <string>
#include "Scacchiera.h"
#include "Pedone.h"
#include "Cavallo.h"
#include "Alfiere.h"
#include "Torre.h"
#include "Donna.h"
#include "Re.h"

void riepilogoPedine(Scacchiera &scacchiera);

using namespace std;

// Gioco della scacchiera con tutte le classi e tipi di pedine sotto forma di oggetti
int main() {
    printf("///////////////////"
           "\nLavoro di G.C. 4BITI"
           "\n///////////////////\n");

    // Creo una scacchiera
    //Scacchiera scacchiera(8, 8);
    //Pedone pedone('B');

    // Posiziono le pedine
    //scacchiera.posizionaPedina(0, 0, pedone.getIDCompleto());
    //scacchiera.stampa();

    int scelta;
    Scacchiera scacchiera(8, 8);
    do {
        printf("\n\nOpzioni Principali: "
               "\n0 -> Esci."
               "\n1 -> Resetta scacchi vuota."
               "\n2 -> Resetta scacchi con pedine."
               "\n3 -> Stampa scacchiera."
               "\n4 -> Posiziona pedine prima dell'inizio della partita."
               "\n5 -> Gioca."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0: {
                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");
                break;
            }
            case 1: {

                printf("\nHai scelto: Resetta scacchi...\n"
                       "\nReset in corso...");

                scacchiera.reset();

                printf("\nReset completato.");
                break;
            }
            case 2: {

                printf("\nHai scelto: Resetta scacchi con pedine...\n"
                       "\nReset in corso...");

                scacchiera.resetDefault();

                printf("\nReset completato.");

                break;
            }

            case 3: {

                printf("\nHai scelto: Stampa scacchiera...\n");
                scacchiera.stampa();

                break;
            }

            case 4: {

                printf("\nHai scelto: Posiziona pedine prima dell'inizio della partita...\n");

                riepilogoPedine(scacchiera);
                // Sub-menu con le scelte e posizione delle pedine.
                int scelta2;
                do {
                    printf("\n\nOpzioni Posizione:"
                           "\n0 -> Esci."
                           "\n1 -> Posiziona Pedina nera"
                           "\n2 -> Posiziona Pedina bianca."
                           "\n3 -> Rimuovi pedina."
                           "\n4 -> Riepilogo pedine."
                           "\n5 -> Stampa scacchiera."
                           "\nScelta: ");
                    scanf("%d", &scelta2);

                    switch (scelta2) {

                        case 0: {
                            printf("\nHai scelto: Esci..."
                                   "\nUscita in corso...");
                            break;
                        }

                        case 1: {
                            printf("\nHai scelto: Posiziona Pedina nera...");

                            char colore = 'N';
                            scacchiera.stampa();

                            // Inserire coordinate pedina
                            int x, y;
                            printf("\nInserisci coordinate pedina (prima riga e poi colonna) [es: 1 2]: ");
                            scanf("%d %d", &x, &y);

                            if (!(x > 0 && x < 9 && y > 0 && y < 9)) {
                                printf("\nCoordinate non valide.");
                                break;
                            }

                            printf("\nCoordinate inserite con successo!");

                            // Coordinate valide per una matrice includendo lo 0.
                            x--;
                            y--;

                            // Menu pedine nere.
                            int scelta3;
                            do {
                                printf("\n\nOpzioni Pedine:"
                                       "\n0 -> Esci."
                                       "\n1 -> Pedone."
                                       "\n2 -> Cavallo."
                                       "\n3 -> Alfiere."
                                       "\n4 -> Torre."
                                       "\n5 -> Donna."
                                       "\n6 -> Re."
                                       "\nScelta: ");
                                scanf("%d", &scelta3);

                                switch (scelta3) {
                                    case 0: {
                                        printf("\nHai scelto: Esci..."
                                               "\nUscita in corso...");
                                        break;
                                    }
                                    case 1: {
                                        printf("\nHai scelto: Pedone...");
                                        Pedone pedone(colore);
                                        if (scacchiera.getNumeroPedoniNeri() < 8) {
                                            scacchiera.posizionaPedina(x, y, pedone.getIDCompleto());
                                            printf("\nPosizionato con successo!");
                                        } else {
                                            printf("\nNumero pedine nere massimo raggiunto.");
                                        }
                                        break;
                                    }
                                    case 2: {
                                        printf("\nHai scelto: Cavallo...");
                                        Cavallo cavallo(colore);
                                        if (scacchiera.getNumeroCavalliNeri() < 2) {
                                            scacchiera.posizionaPedina(x, y, cavallo.getIDCompleto());
                                            printf("\nPosizionato con successo!");
                                        } else {
                                            printf("\nNumero cavalli neri massimo raggiunto.");
                                        }
                                        break;
                                    }
                                    case 3: {
                                        printf("\nHai scelto: Alfiere...");
                                        Alfiere alfiere(colore);
                                        if (scacchiera.getNumeroAlfieriNeri() < 2) {
                                            scacchiera.posizionaPedina(x, y, alfiere.getIDCompleto());
                                            printf("\nPosizionato con successo!");
                                        } else {
                                            printf("\nNumero alfieri neri massimo raggiunto.");
                                        }
                                        break;
                                    }
                                    case 4: {
                                        printf("\nHai scelto: Torre...");
                                        Torre torre(colore);
                                        if (scacchiera.getNumeroTorriNere() < 2) {
                                            scacchiera.posizionaPedina(x, y, torre.getIDCompleto());
                                            printf("\nPosizionato con successo!");
                                        } else {
                                            printf("\nNumero torri nere massimo raggiunto.");
                                        }
                                        break;
                                    }
                                    case 5: {
                                        printf("\nHai scelto: Donna...");
                                        Donna donna(colore);
                                        if (scacchiera.getNumeroDonneNere() < 1) {
                                            scacchiera.posizionaPedina(x, y, donna.getIDCompleto());
                                            printf("\nPosizionato con successo!");
                                        } else {
                                            printf("\nNumero donne nere massimo raggiunto.");
                                        }
                                        break;
                                    }
                                    case 6: {
                                        printf("\nHai scelto: Re...");
                                        Re re(colore);
                                        if (scacchiera.getNumeroReNeri() < 1) {
                                            scacchiera.posizionaPedina(x, y, re.getIDCompleto());
                                            printf("\nPosizionato con successo!");
                                        } else {
                                            printf("\nNumero re neri massimo raggiunto.");
                                        }
                                        break;
                                    }
                                    default: {
                                        printf("\nOpzione non valida, per favore riprovare!");
                                        break;
                                    }
                                }
                            } while (scelta3 != 0);
                            break;
                        }

                        case 2: {
                            printf("\nHai scelto: Posiziona Pedina bianca...");

                            char colore = 'B';
                            scacchiera.stampa();

                            // Inserire coordinate pedina
                            int x, y;
                            printf("\nInserisci coordinate pedina (prima riga e poi colonna) [es: 1 2]: ");
                            scanf("%d %d", &x, &y);

                            if (!(x > 0 && x < 9 && y > 0 && y < 9)) {
                                printf("\nCoordinate non valide.");
                                break;
                            }

                            printf("\nCoordinate inserite con successo!");

                            // Coordinate valide per una matrice includendo lo 0.
                            x--;
                            y--;

                            // Menu pedine bianche.
                            int scelta3;
                            do {
                                printf("\n\nOpzioni Pedine:"
                                       "\n0 -> Esci."
                                       "\n1 -> Pedone."
                                       "\n2 -> Cavallo."
                                       "\n3 -> Alfiere."
                                       "\n4 -> Torre."
                                       "\n5 -> Donna."
                                       "\n6 -> Re."
                                       "\nScelta: ");
                                scanf("%d", &scelta3);

                                switch (scelta3) {
                                    case 0: {
                                        printf("\nHai scelto: Esci..."
                                               "\nUscita in corso...");
                                        break;
                                    }
                                    case 1: {
                                        printf("\nHai scelto: Pedone...");
                                        Pedone pedone(colore);
                                        if (scacchiera.getNumeroPedoniBianchi() < 8) {
                                            scacchiera.posizionaPedina(x, y, pedone.getIDCompleto());
                                            printf("\nPosizionato con successo!");
                                        } else {
                                            printf("\nNumero pedine bianche massimo raggiunto.");
                                        }
                                        break;
                                    }
                                    case 2: {
                                        printf("\nHai scelto: Cavallo...");
                                        Cavallo cavallo(colore);
                                        if (scacchiera.getNumeroCavalliBianchi() < 2) {
                                            scacchiera.posizionaPedina(x, y, cavallo.getIDCompleto());
                                            printf("\nPosizionato con successo!");
                                        } else {
                                            printf("\nNumero cavalli bianchi massimo raggiunto.");
                                        }
                                        break;
                                    }
                                    case 3: {
                                        printf("\nHai scelto: Alfiere...");
                                        Alfiere alfiere(colore);
                                        if (scacchiera.getNumeroAlfieriBianchi() < 2) {
                                            scacchiera.posizionaPedina(x, y, alfiere.getIDCompleto());
                                            printf("\nPosizionato con successo!");
                                        } else {
                                            printf("\nNumero alfieri bianchi massimo raggiunto.");
                                        }
                                        break;
                                    }
                                    case 4: {
                                        printf("\nHai scelto: Torre...");
                                        Torre torre(colore);
                                        if (scacchiera.getNumeroTorriBianche() < 2) {
                                            scacchiera.posizionaPedina(x, y, torre.getIDCompleto());
                                            printf("\nPosizionato con successo!");
                                        } else {
                                            printf("\nNumero torri bianche massimo raggiunto.");
                                        }
                                        break;
                                    }
                                    case 5: {
                                        printf("\nHai scelto: Donna...");
                                        Donna donna(colore);
                                        if (scacchiera.getNumeroDonneBianche() < 1) {
                                            scacchiera.posizionaPedina(x, y, donna.getIDCompleto());
                                            printf("\nPosizionato con successo!");
                                        } else {
                                            printf("\nNumero donne bianche massimo raggiunto.");
                                        }
                                        break;
                                    }
                                    case 6: {
                                        printf("\nHai scelto: Re...");
                                        Re re(colore);
                                        if (scacchiera.getNumeroReBianchi() < 1) {
                                            scacchiera.posizionaPedina(x, y, re.getIDCompleto());
                                            printf("\nPosizionato con successo!");
                                        } else {
                                            printf("\nNumero re bianchi massimo raggiunto.");
                                        }
                                        break;
                                    }
                                    default: {
                                        printf("\nOpzione non valida, per favore riprovare!");
                                        break;
                                    }
                                }
                            } while (scelta3 != 0);
                            break;
                        }

                        case 3:{

                            printf("\nHai scelto: Rimuovi pedina...");

                            scacchiera.stampa();

                            // Coordinate
                            int x, y;
                            printf("\nInserisci coordinate pedina (prima riga e poi colonna) [es: 1 2]: ");
                            scanf("%d %d", &x, &y);

                            if (!(x > 0 && x < 9 && y > 0 && y < 9)) {
                                printf("\nCoordinate non valide.");
                                break;
                            }

                            // Coordinate valide per una matrice includendo lo 0.
                            x--;
                            y--;

                            // Rimozione pedina
                            scacchiera.rimuoviPedina(x, y);

                            printf("\nPedina rimossa con successo!");
                            break;
                        }

                        case 4:{
                            printf("\nHai scelto: Stampa riepilogo...");
                            riepilogoPedine(scacchiera);
                            break;
                        }

                        case 5:{
                            printf("\nHai scelto: Stampa scacchiera...");
                            scacchiera.stampa();
                            break;
                        }

                        default: {
                            printf("\nOpzione non valida, per favore riprovare!");
                            break;
                        }
                    }

                } while (scelta2 != 0);

                break;
            }
            default: {
                printf("\nOpzione non valida, per favore riprovare!\n");
                break;
            }
        }
    } while (scelta != 0);

    return 0;
}

void riepilogoPedine(Scacchiera &scacchiera) {
    printf("\nSono posizionati del team Nero: "
           "\nPedone Nero: %d/8"
           "\nCavallo Nero: %d/2"
           "\nAlfiere Nero: %d/2"
           "\nTorre Nero: %d/2"
           "\nDonna Nero: %d/1"
           "\nRe Nero: %d/1"
           "\n\nSono posizionati del team Bianco: "
           "\nPedone Bianco: %d/8"
           "\nCavallo Bianco: %d/2"
           "\nAlfiere Bianco: %d/2"
           "\nTorre Bianco: %d/2"
           "\nDonna Bianco: %d/1"
           "\nRe Bianco: %d/1",
           scacchiera.getNumeroPedoniNeri(),
           scacchiera.getNumeroCavalliNeri(),
           scacchiera.getNumeroAlfieriNeri(),
           scacchiera.getNumeroTorriNere(),
           scacchiera.getNumeroDonneNere(),
           scacchiera.getNumeroReNeri(),
           scacchiera.getNumeroPedoniBianchi(),
           scacchiera.getNumeroCavalliBianchi(),
           scacchiera.getNumeroAlfieriBianchi(),
           scacchiera.getNumeroTorriBianche(),
           scacchiera.getNumeroDonneBianche(),
           scacchiera.getNumeroReBianchi());
}
