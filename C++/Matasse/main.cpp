#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct matassa{
    int costo;
    int prodStd;
    int prodSpc;
};

void variante1(const matassa *matasse, int nRichiestiStd, int nRichiestiSpc, int &nProdottoStd, int &nProdottoSpc,
               int &costoTot);

void variante2(const matassa *matasse, int nRichiestiStd, int nRichiestiSpc, int &nProdottoStd, int &nProdottoSpc,
               int &costoTot);

void variante3(const matassa *matasse, int nRichiestiStd, int nRichiestiSpc, int &costoTot, int &nProdottoStd,
               int &nProdottoSpc);

int main() {

    struct matassa matasse[3];

    matasse[0] = {
        900,
        3,
        1};

    matasse[1] = {
        800,
        2,
        2
    };

    matasse[2] = {
        600,
        2,
        1
    };

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//          Puntatori di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;

    while (scelta != 0){

        printf("\n\nLegenda:"
               "\n0 -> Esci."
               "\n1 -> Versione 1."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Max prod. giornaliera costo minimo...");

                int nOreMax = 24;
                int nVarianti = 2;

                int nRichiestiStd = 60;
                int nRichiestiSpc = 40;
                int costoMigliore = 999999;
                int stdMigliore;
                int spcMigliore;
                int nOreMigliore;
                int varianteMigliore;

                for (int i = 0; i < nVarianti; i++) {

                    int nOreTot = 0;
                    int costoTot = 0;
                    int nProdottoStd = 0;
                    int nProdottoSpc = 0;

                    while ((nProdottoSpc < nRichiestiSpc) || (nProdottoStd < nRichiestiStd)){

                        nOreTot++;

                        switch (i) {
                            case 0:{

                                // Standard.
                                variante1(matasse, nRichiestiStd, nRichiestiSpc, nProdottoStd, nProdottoSpc, costoTot);

                                break;
                            }

                            case 1:{

                                // Delta.
                                variante2(matasse, nRichiestiStd, nRichiestiSpc, nProdottoStd, nProdottoSpc, costoTot);

                                break;
                            }

                            case 2:{

                                // Delta e piu' economica (Uguale al 2 ma dinamico se cambiano i costi delle macchine e combinazioni).
                                variante3(matasse, nRichiestiStd, nRichiestiSpc, costoTot, nProdottoStd, nProdottoSpc);

                                break;
                            }

                            default:{

                                printf("\nERRORE! Non dovrebbe uscire un numero maggiore del numero di varianti possibili!");

                                break;
                            }
                        }
                    }

                    if (costoMigliore > costoTot){

                        stdMigliore = nProdottoStd;
                        spcMigliore = nProdottoSpc;
                        costoMigliore = costoTot;
                        nOreMigliore = nOreTot;
                        varianteMigliore = i + 1;

                    }

                }

                printf("\n\nRiepilogo: "
                       "\nCostoTot: %d"
                       "\nnMatStandard: %d"
                       "\nnMatSpc: %d"
                       "\nnOreTot: %d"
                       "\nVariante Algoritmo migliore: %d", costoMigliore, stdMigliore, spcMigliore, nOreMigliore, varianteMigliore);


                break;
            }

            default:{

                printf("\nHai fatto una scelta non valida, per favore riprovare!");

                break;
            }

        }


    }

    printf("\nUscito con successo!");

    return 0;
}

void variante3(const matassa *matasse, int nRichiestiStd, int nRichiestiSpc, int &costoTot, int &nProdottoStd,
               int &nProdottoSpc) {
    int costMatMinStdSingolo = 999;
    int nMacMatStd;
    int costMatMinSpcSingolo = 999;
    int nMacMatSpc;
    int nMacchine = 3;

    // Cerca macchine più economiche per singola matassa variante.
    for (int j = 0; j < nMacchine; j++) {
        int costStdSing;
        int costSpcSing;

        costStdSing = matasse[j].costo / matasse[j].prodStd;
        costSpcSing = matasse[j].costo / matasse[j].prodSpc;

        if (costMatMinStdSingolo > costStdSing){

            costMatMinStdSingolo = costStdSing;
            nMacMatStd = j;

        } else if (costMatMinSpcSingolo > costSpcSing){

            costMatMinSpcSingolo = costSpcSing;
            nMacMatSpc = j;

        }
    }


    int deltaStd = nRichiestiStd - nProdottoStd;
    int deltaSpd = nRichiestiSpc - nProdottoSpc;

    if (deltaStd > deltaSpd){

        costoTot += matasse[nMacMatStd].costo;
        nProdottoStd += matasse[nMacMatStd].prodStd;
        nProdottoSpc += matasse[nMacMatStd].prodSpc;

    } else if (deltaStd == deltaSpd){

        costoTot += matasse[1].costo;
        nProdottoStd += matasse[1].prodStd;
        nProdottoSpc += matasse[1].prodSpc;

    } else if (deltaSpd > deltaStd){

        costoTot += matasse[nMacMatSpc].costo;
        nProdottoStd += matasse[nMacMatSpc].prodStd;
        nProdottoSpc += matasse[nMacMatSpc].prodSpc;

    }
}

void variante2(const matassa *matasse, int nRichiestiStd, int nRichiestiSpc, int &nProdottoStd, int &nProdottoSpc,
               int &costoTot) {
    int deltaStd = nRichiestiStd - nProdottoStd;
    int deltaSpd = nRichiestiSpc - nProdottoSpc;

    if (deltaStd > deltaSpd){

        costoTot += matasse[0].costo;
        nProdottoStd += matasse[0].prodStd;
        nProdottoSpc += matasse[0].prodSpc;

    } else if (deltaStd == deltaSpd){

        costoTot += matasse[1].costo;
        nProdottoStd += matasse[1].prodStd;
        nProdottoSpc += matasse[1].prodSpc;

    } else if (deltaSpd > deltaStd){

        costoTot += matasse[2].costo;
        nProdottoStd += matasse[2].prodStd;
        nProdottoSpc += matasse[2].prodSpc;

    }
}

void variante1(const matassa *matasse, int nRichiestiStd, int nRichiestiSpc, int &nProdottoStd, int &nProdottoSpc,
               int &costoTot) {// Richiama macchina che produce più standard e speciali.
    if ((nProdottoStd < nRichiestiStd) && (nProdottoSpc < nRichiestiSpc)){

        costoTot += matasse[2].costo;
        nProdottoSpc += matasse[2].prodSpc;
        nProdottoStd += matasse[2].prodStd;

        // Macchina che produce più standard.
    } else if (nProdottoStd < nRichiestiStd){

        costoTot += matasse[0].costo;
        nProdottoSpc += matasse[0].prodSpc;
        nProdottoStd += matasse[0].prodStd;

        // Macchina che produce più speciali.
    } else if (nProdottoSpc < nRichiestiSpc){

        costoTot += matasse[1].costo;
        nProdottoSpc += matasse[1].prodSpc;
        nProdottoStd += matasse[1].prodStd;

    }
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}