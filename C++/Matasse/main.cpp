#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct matassa{
    int costo;
    int prodStd;
    int prodSpc;
    int maxUtilizzi;
}matasse[3];

void variante1(int nRichiestiStd, int nRichiestiSpc, int &nProdottoStd, int &nProdottoSpc,
               int &costoTot);

void variante2(int nRichiestiStd, int nRichiestiSpc, int &nProdottoStd, int &nProdottoSpc,
               int &costoTot);

void variante3(int nRichiestiStd, int nRichiestiSpc, int &costoTot, int &nProdottoStd,
               int &nProdottoSpc);

bool fileMatEsiste();

int main() {

    int nMatasseMac = 3;
    int nRichiestiStd = 60;
    int nRichiestiSpc = 40;

    matasse[0] = {
            900,
            3,
            1,
            10};

    matasse[1] = {
            800,
            2,
            2,
            10
    };

    matasse[2] = {
            600,
            2,
            1,
            10
    };

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//          Lanificio di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    FILE *fileMat;
    // Verifico se esiste il FILE delle matasse e nel caso non esista ne creo uno nuovo con i valori di default, nel
    // caso esista invece lo leggo e inserisco nelle struct delle matasse.
    if (!fileMatEsiste()){
        printf("\n\nIl FILE matasse.txt non esiste, creandone uno nuovo...");
        fileMat = fopen("matasse.txt", "w");

        for (int i = 0; i < nMatasseMac; i++) {
            if (i != 0){
                fprintf(fileMat, "%s", "\n");
            }
            fprintf(fileMat, "%d %d %d %d", matasse[i].costo, matasse[i].prodStd, matasse[i].prodSpc, matasse[i].maxUtilizzi);
        }
        fclose(fileMat);

        printf("\nFile matasse.txt di default creato con successo!");
    } else {
        printf("\n\nCaricamento in corso FILE matasse esistente...");

        fileMat = fopen("matasse.txt", "r");

        int numeroMat = 0;
        while (!feof(fileMat)){
            fscanf(fileMat, "%d %d %d %d", &matasse[numeroMat].costo, &matasse[numeroMat].prodStd, &matasse[numeroMat].prodSpc, &matasse[numeroMat].maxUtilizzi);
            numeroMat++;
        }
        fclose(fileMat);

        printf("\nCaricamento effettuato con successo!");
    }

    int scelta = 1;

    while (scelta != 0){

        printf("\n\nLegenda:"
               "\n0 -> Esci."
               "\n1 -> Elabora risultato."
               "\n2 -> Modifica FILE config."
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
                int nVarianti = 3;
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
                                variante1(nRichiestiStd, nRichiestiSpc, nProdottoStd, nProdottoSpc, costoTot);

                                break;
                            }

                            case 1:{

                                // Delta.
                                variante2(nRichiestiStd, nRichiestiSpc, nProdottoStd, nProdottoSpc, costoTot);

                                break;
                            }

                            case 2:{

                                // Delta e piu' economica (Uguale al 2 ma dinamico se cambiano i costi delle macchine e combinazioni).
                                variante3(nRichiestiStd, nRichiestiSpc, costoTot, nProdottoStd, nProdottoSpc);

                                break;
                            }

                            default:{

                                printf("\nERRORE! Non dovrebbe uscire un numero maggiore del numero di varianti possibili!");

                                break;
                            }
                        }
                    }

                    // Confronto il nuovo costo totale e salvo i dati.
                    if (costoMigliore > costoTot){

                        stdMigliore = nProdottoStd;
                        spcMigliore = nProdottoSpc;
                        costoMigliore = costoTot;
                        nOreMigliore = nOreTot;
                        varianteMigliore = i + 1;

                    }

                }

                // Riepilogo.
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

void variante3(int nRichiestiStd, int nRichiestiSpc, int &costoTot, int &nProdottoStd,
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

void variante2(int nRichiestiStd, int nRichiestiSpc, int &nProdottoStd, int &nProdottoSpc,
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

void variante1(int nRichiestiStd, int nRichiestiSpc, int &nProdottoStd, int &nProdottoSpc,
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

bool fileMatEsiste(){

    FILE *matFile = fopen("matasse.txt", "r");

    bool esiste = matFile != NULL;

    fclose(matFile);

    return esiste;
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}