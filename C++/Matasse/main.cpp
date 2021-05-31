#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

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

void continua();

void macchinaEconomica(int costMatMinStdSingolo, int costMatMinSpcSingolo, int nMacchine, int &nMacMatStd, int &nMacMatSpc);

void fileMatIniz(int nMatasseMac, FILE *fileMat);

void salvaModifiche(int nMatasseMac, FILE *fileMat);

void modificaMacchine(int nMatasseMac);

void valoriDefault();

void calcolatoreFin(int nRichiestiStd, int nRichiestiSpc, int &costoMigliore, int &stdMigliore, int &spcMigliore,
                    int &nOreMigliore, int &varianteMigliore);

int main() {

    int nMatasseMac = 3;
    int nRichiestiStd = 60;
    int nRichiestiSpc = 40;

    // Valori default.
    valoriDefault();

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//          Lanificio di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    FILE *fileMat = NULL;
    // Verifico se esiste il FILE delle matasse e nel caso non esista ne creo uno nuovo con i valori di default, nel
    // caso esista invece lo leggo e inserisco nelle struct delle matasse.
    fileMatIniz(nMatasseMac, fileMat);

    int scelta = 1;

    while (scelta != 0){

        printf("\n\nLegenda:"
               "\n0 -> Esci."
               "\n1 -> Elabora risultato."
               "\n2 -> Modifica macchine."
               "\n3 -> Vendita."
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

                int costoMigliore;
                int stdMigliore;
                int spcMigliore;
                int nOreMigliore;
                int varianteMigliore;
                calcolatoreFin(nRichiestiStd, nRichiestiSpc, costoMigliore, stdMigliore, spcMigliore, nOreMigliore,
                               varianteMigliore);

                // Riepilogo.
                printf("\n\nRiepilogo: "
                       "\nCostoTot: %d"
                       "\nnMatStandard: %d"
                       "\nnMatSpc: %d"
                       "\nnOreTot: %d"
                       "\nVariante Algoritmo migliore: %d", costoMigliore, stdMigliore, spcMigliore, nOreMigliore, varianteMigliore);


                continua();
                break;
            }

            case 2:{

                printf("\nHai scelto: modifica macchine matasse...");

                modificaMacchine(nMatasseMac);

                salvaModifiche(nMatasseMac, fileMat);
                printf("\nUscito e salvato con successo (se sono state apportate modifiche).");
                break;
            }

            case 3:{

                printf("\nHai scelto: Spese e ricavi...");

                int prezzoMatStd, prezzoMatSpc, numeroOre;
                printf("\n\nInserire prezzo Matassa Standard: ");
                scanf("%d", &prezzoMatStd);

                printf("\nInserire prezzo Matassa Speciale: ");
                scanf("%d", &prezzoMatSpc);

                printf("\nInserire numero ore: ");
                scanf("%d", &numeroOre);

                int costoMigliore;
                int stdMigliore;
                int spcMigliore;
                int nOreMigliore;
                int varianteMigliore;
                calcolatoreFin(nRichiestiStd, nRichiestiSpc, costoMigliore, stdMigliore, spcMigliore, nOreMigliore,
                               varianteMigliore);

                int costoFinale = round((double) ((double) costoMigliore / nOreMigliore) * numeroOre);
                int stdProdotti = round(((double) stdMigliore / nOreMigliore) * numeroOre);
                int spcProdotti = round(((double) spcMigliore / nOreMigliore) * numeroOre);
                int venditeStandard = round((double) stdProdotti * prezzoMatStd);
                int venditeSpeciali = round((double) spcProdotti * prezzoMatSpc);
                int venditePreCosti = round((double) venditeStandard + venditeSpeciali);

                printf("\nRisultati: "
                       "\nTempo: %d ore"
                       "\nCosto Finale totale: Euro %d"
                       "\nNumero Matasse standard: %d"
                       "\nNumero Matasse speciali: %d"
                       "\nVendita pre-costi standard: Euro %d"
                       "\nVendita pre-costi speciali: Euro %d"
                       "\nVendita pre-costi: (%d * %d) + (%d * %d) = Euro %d"
                       "\nGuadagni dopo costi: %d - %d = Euro %d", numeroOre, costoFinale, stdProdotti, spcProdotti, venditeStandard, venditeSpeciali ,stdProdotti, prezzoMatStd, spcProdotti, prezzoMatSpc, venditePreCosti, venditePreCosti, costoFinale, venditePreCosti - costoFinale);

                continua();
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

void calcolatoreFin(int nRichiestiStd, int nRichiestiSpc, int &costoMigliore, int &stdMigliore, int &spcMigliore,
                    int &nOreMigliore, int &varianteMigliore) {
    costoMigliore= 999999;
    int nOreMax = 24;
    int nVarianti = 3;
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
}

void valoriDefault() {
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
}

void modificaMacchine(int nMatasseMac) {

    printf("\n\nMacchine: ");
    for (int i = 0; i < nMatasseMac; i++) {

        printf("\n\n[ID %d]"
               "\n - Mat. Costo: %d"
               "\n - Mat. Standard: %d"
               "\n - Mat. Speciali: %d"
               "\n - Max. Utilizzi: %d", i + 1, matasse[i].costo, matasse[i].prodStd, matasse[i].prodSpc, matasse[i].maxUtilizzi);

    }

    int sceltaMac = 0;
    while (sceltaMac == 0 || sceltaMac > nMatasseMac) {
        printf("\n\nSelezionare una delle macchine: "
               "\nID: ");
        scanf("%d", &sceltaMac);

        if (sceltaMac == 0 || sceltaMac > nMatasseMac){
            printf("\nHai inserito un ID non valido! Per favore riprovare...");
        }
    }

    printf("\n\nSelezionata macchina ID: %d", sceltaMac);

    // Chiedo all'utente un ID da 1 a nMac per semplicita', ma nella realta' serve uno valido per un vettore
    // che parte da 0.
    sceltaMac--;

    printf("\n\nRiepilogo specifiche macchina selezionata: ");
    printf("\n[ID %d]"
           "\n - Mat. Costo: %d"
           "\n - Mat. Standard: %d"
           "\n - Mat. Speciali: %d"
           "\n - Max. Utilizzi: %d", sceltaMac + 1, matasse[sceltaMac].costo, matasse[sceltaMac].prodStd, matasse[sceltaMac].prodSpc, matasse[sceltaMac].maxUtilizzi);


    int sceltaModifica = 1;
    while (sceltaModifica != 0) {
        printf("\n\nScegli cosa vuoi modificare: "
               "\n 0 -> Esci e salva."
               "\n 1 -> Costo."
               "\n 2 -> Mat. Standard."
               "\n 3 -> Mat. Speciali."
               "\n 4 -> Max. Utilizzi."
               "\nScelta: ");
        scanf("%d", &sceltaModifica);

        switch (sceltaModifica) {

            case 0:{

                printf("\nHai scelto: Esci e salva.");

                break;
            }

            case 1:{

                printf("\nHai scelto: Modifica costo...");

                int valoreInserito;
                printf("\nInserire il nuovo valore: ");
                scanf("%d", &valoreInserito);

                matasse[sceltaMac].costo = valoreInserito;

                printf("\nModifica effettuata con successo!");

                continua();
                break;
            }

            case 2:{

                printf("\nHai scelto: Modifica numero Mat. Standard...");

                int valoreInserito;
                printf("\nInserire il nuovo valore: ");
                scanf("%d", &valoreInserito);

                matasse[sceltaMac].prodStd = valoreInserito;

                printf("\nModifica effettuata con successo!");

                continua();
                break;
            }

            case 3:{

                printf("\nHai scelto: Modifica numero Mat. Speciali...");

                int valoreInserito;
                printf("\nInserire il nuovo valore: ");
                scanf("%d", &valoreInserito);

                matasse[sceltaMac].prodSpc = valoreInserito;

                printf("\nModifica effettuata con successo!");

                continua();
                break;
            }

            case 4:{

                printf("\nHai scelto: Modifica numero Max. Utilizzi...");

                int valoreInserito;
                printf("\nInserire il nuovo valore: ");
                scanf("%d", &valoreInserito);

                matasse[sceltaMac].maxUtilizzi = valoreInserito;

                printf("\nModifica effettuata con successo!");

                continua();
                break;
            }

            default:{

                printf("\nScelta non valida, per favore riprovare!");

                break;
            }

        }

    }
}

void salvaModifiche(int nMatasseMac, FILE *fileMat) {
    fileMat = fopen("matasse.txt", "w");

    for (int i = 0; i < nMatasseMac; i++) {
        if (i != 0){
            fprintf(fileMat, "%s", "\n");
        }
        fprintf(fileMat, "%d %d %d %d", matasse[i].costo, matasse[i].prodStd, matasse[i].prodSpc, matasse[i].maxUtilizzi);
    }
    fclose(fileMat);
}

void fileMatIniz(int nMatasseMac, FILE *fileMat) {
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
}

void variante3(int nRichiestiStd, int nRichiestiSpc, int &costoTot, int &nProdottoStd,
               int &nProdottoSpc) {

    int costMatMinStdSingolo = 999;
    int nMacMatStd;
    int costMatMinSpcSingolo = 999;
    int nMacMatSpc;
    int nMacchine = 3;
    int utilizziRimastiMac[3] = {matasse[0].maxUtilizzi, matasse[1].maxUtilizzi, matasse[2].maxUtilizzi};

    // Cerca macchine piu' economiche per singola matassa variante.
    macchinaEconomica(costMatMinStdSingolo, costMatMinSpcSingolo, nMacchine, nMacMatStd, nMacMatSpc);

    int deltaStd = nRichiestiStd - nProdottoStd;
    int deltaSpd = nRichiestiSpc - nProdottoSpc;

    if (deltaStd > deltaSpd && (utilizziRimastiMac[nMacMatStd] > 0)){

        costoTot += matasse[nMacMatStd].costo;
        nProdottoStd += matasse[nMacMatStd].prodStd;
        nProdottoSpc += matasse[nMacMatStd].prodSpc;
        utilizziRimastiMac[nMacMatStd]--;

    } else if (deltaStd == deltaSpd && (utilizziRimastiMac[1] > 0)){

        costoTot += matasse[1].costo;
        nProdottoStd += matasse[1].prodStd;
        nProdottoSpc += matasse[1].prodSpc;
        utilizziRimastiMac[1]--;

    } else if (deltaSpd > deltaStd && (utilizziRimastiMac[nMacMatSpc] > 0)){

        costoTot += matasse[nMacMatSpc].costo;
        nProdottoStd += matasse[nMacMatSpc].prodStd;
        nProdottoSpc += matasse[nMacMatSpc].prodSpc;
        utilizziRimastiMac[nMacMatSpc]--;

    } else {

        if (utilizziRimastiMac[1] > 0){

            costoTot += matasse[1].costo;
            nProdottoStd += matasse[1].prodStd;
            nProdottoSpc += matasse[1].prodSpc;
            utilizziRimastiMac[1]--;

        } else if (utilizziRimastiMac[nMacMatSpc] > 0){

            costoTot += matasse[nMacMatSpc].costo;
            nProdottoStd += matasse[nMacMatSpc].prodStd;
            nProdottoSpc += matasse[nMacMatSpc].prodSpc;
            utilizziRimastiMac[nMacMatSpc]--;

        } else if (utilizziRimastiMac[nMacMatStd] > 0){

            costoTot += matasse[nMacMatStd].costo;
            nProdottoStd += matasse[nMacMatStd].prodStd;
            nProdottoSpc += matasse[nMacMatStd].prodSpc;
            utilizziRimastiMac[nMacMatStd]--;

        } else {

            printf("\nFiniti utilizzi di tutte le macchine, errore!");
            return;
        }

    }
}

void macchinaEconomica(int costMatMinStdSingolo, int costMatMinSpcSingolo, int nMacchine, int &nMacMatStd, int &nMacMatSpc) {
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
}

void variante2(int nRichiestiStd, int nRichiestiSpc, int &nProdottoStd, int &nProdottoSpc,
               int &costoTot) {

    int deltaStd = nRichiestiStd - nProdottoStd;
    int deltaSpd = nRichiestiSpc - nProdottoSpc;
    int utilizziRimastiMac[3] = {matasse[0].maxUtilizzi, matasse[1].maxUtilizzi, matasse[2].maxUtilizzi};

    if (deltaStd > deltaSpd && utilizziRimastiMac[0] > 0){

        costoTot += matasse[0].costo;
        nProdottoStd += matasse[0].prodStd;
        nProdottoSpc += matasse[0].prodSpc;
        utilizziRimastiMac[0]--;

    } else if (deltaStd == deltaSpd && utilizziRimastiMac[1] > 0){

        costoTot += matasse[1].costo;
        nProdottoStd += matasse[1].prodStd;
        nProdottoSpc += matasse[1].prodSpc;
        utilizziRimastiMac[1]--;

    } else if (deltaSpd > deltaStd && utilizziRimastiMac[2] > 0){

        costoTot += matasse[2].costo;
        nProdottoStd += matasse[2].prodStd;
        nProdottoSpc += matasse[2].prodSpc;
        utilizziRimastiMac[2]--;

    } else {

        if (utilizziRimastiMac[1] > 0){

            costoTot += matasse[1].costo;
            nProdottoStd += matasse[1].prodStd;
            nProdottoSpc += matasse[1].prodSpc;
            utilizziRimastiMac[1]--;

        } else if (utilizziRimastiMac[2] > 0){

            costoTot += matasse[2].costo;
            nProdottoStd += matasse[2].prodStd;
            nProdottoSpc += matasse[2].prodSpc;
            utilizziRimastiMac[2]--;

        } else if (utilizziRimastiMac[0] > 0){

            costoTot += matasse[0].costo;
            nProdottoStd += matasse[0].prodStd;
            nProdottoSpc += matasse[0].prodSpc;
            utilizziRimastiMac[0]--;

        } else {

            printf("\nFiniti utilizzi di tutte le macchine, errore!");
            return;
        }

    }
}

void variante1(int nRichiestiStd, int nRichiestiSpc, int &nProdottoStd, int &nProdottoSpc,
               int &costoTot) {

    int utilizziRimastiMac[3] = {matasse[0].maxUtilizzi, matasse[1].maxUtilizzi, matasse[2].maxUtilizzi};

    // Richiama macchina che produce piu' standard e speciali.
    if ((nProdottoStd < nRichiestiStd) && (nProdottoSpc < nRichiestiSpc) && utilizziRimastiMac[2] > 0){

        costoTot += matasse[2].costo;
        nProdottoSpc += matasse[2].prodSpc;
        nProdottoStd += matasse[2].prodStd;
        utilizziRimastiMac[2]--;

        // Macchina che produce piu' standard.
    } else if (nProdottoStd < nRichiestiStd && utilizziRimastiMac[0] > 0){

        costoTot += matasse[0].costo;
        nProdottoSpc += matasse[0].prodSpc;
        nProdottoStd += matasse[0].prodStd;
        utilizziRimastiMac[0]--;

        // Macchina che produce piu' speciali.
    } else if (nProdottoSpc < nRichiestiSpc && utilizziRimastiMac[1] > 0){

        costoTot += matasse[1].costo;
        nProdottoSpc += matasse[1].prodSpc;
        nProdottoStd += matasse[1].prodStd;
        utilizziRimastiMac[1]--;

    } else {

        if (utilizziRimastiMac[1] > 0){

            costoTot += matasse[1].costo;
            nProdottoStd += matasse[1].prodStd;
            nProdottoSpc += matasse[1].prodSpc;
            utilizziRimastiMac[1]--;

        } else if (utilizziRimastiMac[0] > 0){

            costoTot += matasse[0].costo;
            nProdottoStd += matasse[0].prodStd;
            nProdottoSpc += matasse[0].prodSpc;
            utilizziRimastiMac[0]--;

        } else if (utilizziRimastiMac[2] > 0){

            costoTot += matasse[2].costo;
            nProdottoStd += matasse[2].prodStd;
            nProdottoSpc += matasse[2].prodSpc;
            utilizziRimastiMac[2]--;

        } else {

            printf("\nFiniti utilizzi di tutte le macchine, errore!");
            return;
        }

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