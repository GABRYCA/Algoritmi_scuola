#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include "graphics/graphics.h"

using namespace std;

bool inputBool();
void ordinaCilindri(int num, int A, int B, int C);
void ordinaCilindriGrafico(int num, int A, int B, int C);
void ordinaCilindriGrafico2(int num, int A, int B, int C);
void graficaVettoriAttuale();
void graficaVettoriAttuale2();
void resetVett();
void setColonnaABase(int nCilindri);
int posCilCimaVet(int nVet);
int pulisciGrafica();

bool pausaClick = false;
int delay = 100, nCilindriG = 0;
int vet[100][3] = {0};

// Coordinate dinamiche:
int unita = 30;

// Coordinate fisse:
int xSinRet = 2 * unita, ySinRet = 11 * unita, xDesRet = 16 * unita, yDesRet = 9 * unita; // Rettangolo.
int xBasAst1 = 4 * unita, yBasAst1 = 9 * unita, xCimAst1 = 4 * unita, yCimAst1 = 1 * unita; // Asta 1.
int xBasAst2 = 9 * unita, yBasAst2 = 9 * unita, xCimAst2 = 9 * unita, yCimAst2 = 1 * unita; // Asta 2.
int xBasAst3 = 14 * unita, yBasAst3 = 9 * unita, xCimAst3 = 14 * unita, yCimAst3 = 1 * unita; // Asta 3.

int main() {

    // Messaggio di benvenuto.
    printf("\n//////////////////////////////////"
           "\nBenvenuto nell'Hanoi di G.C. 4BITI"
           "\n//////////////////////////////////");

    // Variabile scelta.
    int scelta;

    // Do while che continua fino a quando non si decida di uscire dal programma.
    do{

        // Menu opzioni e scelta utente.
        printf("\n\nEcco una lista delle scelte disponibili: "
               "\n0 -> Esci."
               "\n1 -> Hanoi."
               "\n2 -> Hanoi grafico."
               "\n3 -> Hanoi grafics.h (consigliato)."
               "\nScelta: ");
        scanf("%d", &scelta);

        // Switch in base alla scelta dell'utente.
        switch (scelta) {
            case 0:{

                // Scelta.
                printf("\n\nHai scelto esci...");

                break;
            }

            case 1:{

                // Scelta.
                printf("\n\nHai scelto: Hanoi numerico...");

                // Ottengo dall'utente il numero di cilindri.
                int nCilindri;
                do {
                    printf("\n\nInserire il numero di cilindri: ");
                    scanf("%d", &nCilindri);
                    if (nCilindri == 0){
                        printf("\nPer favore inserire un valore maggiore di 0.");
                    }
                } while (nCilindri <= 0);

                // Chiedo all'utente se vuole un delay o una pausa sul click.
                //printf("\nVuoi un delay oppure una pausa sul click (no per delay, si per pausa)? "
                //       "\nScelta: ");
                //pausaClick = inputBool();

                if (!pausaClick){
                    printf("\nInserire un delay in millisecondi (default 100ms): ");
                    scanf("%d", &delay);
                }

                // Comunico all'utente come conferma il numero di cilindri che ha scelto e inizio.
                printf("\nNumero cilindri: %d.", nCilindri);

                int asta = 0;
                while (asta != 1 && asta != 2) {
                    printf("\n\nInserire la colonna/asta di destinazione (2 o 3)"
                           "\nScelta:");
                    scanf("%d", &asta);
                    asta--;

                    if (asta != 1 && asta != 2){
                        printf("\n\nValore non valido, riprova.");
                    }
                }

                // Eseguo ordinamento cilindri.
                if (asta == 1) {
                    ordinaCilindri(nCilindri, 1, 2, 3);
                } else if (asta == 2){
                    ordinaCilindri(nCilindri, 1, 3, 2);
                }

                // Fine.
                printf("\nCompletato con successo.");
                break;
            }

            case 2:{

                // Scelta.
                printf("\n\nHai scelto: Hanoi grafico...");

                // Chiedo numero di cilindri.
                int nCilindri;
                do {
                    printf("\n\nInserire il numero di cilindri: ");
                    scanf("%d", &nCilindri);
                    if (nCilindri == 0){
                        printf("\nPer favore inserire un valore maggiore di 0.");
                    }
                } while (nCilindri <= 0);
                // Setto variabile globale dei cilindri al numero inserito.
                nCilindriG = nCilindri;

                // Resetta il vettore e setta la colonna base del vettore dei cilindri.
                resetVett();
                setColonnaABase(nCilindri);

                // Debug.
                //printf("\nposCimaCil VET A %d", posCilCimaVet(0));
                //printf("\nposCimaCil VET B %d", posCilCimaVet(1));
                //printf("\nposCimaCil VET C %d", posCilCimaVet(2));

                // Mostro la grafica dei vettori attuale, testuale in questo tipo.
                graficaVettoriAttuale();

                // Chiedo se l'utente vuole il delay o la pausa sul click.
                //printf("\nVuoi un delay oppure una pausa sul click (no per delay, si per pausa)? "
                //       "\nScelta: ");
                //pausaClick = inputBool();

                // Chiedo all'utente quanto vuole il delay.
                if (!pausaClick){
                    printf("\nInserire un delay in millisecondi (default 100ms): ");
                    scanf("%d", &delay);
                }

                int asta = 0;
                while (asta != 1 && asta != 2) {
                    printf("\n\nInserire la colonna/asta di destinazione (2 o 3)"
                           "\nScelta: ");
                    scanf("%d", &asta);
                    asta--;

                    if (asta != 1 && asta != 2){
                        printf("\n\nValore non valido, riprova.");
                    }
                }

                // Comunico il numero di cilindri inserisco e inizio.
                printf("\nNumero cilindri: %d.", nCilindri);

                // Eseguo.
                if (asta == 1) {
                    ordinaCilindriGrafico(nCilindri, 0, 1, 2);
                } else if (asta == 2){
                    ordinaCilindriGrafico(nCilindri, 0, 2, 1);
                }

                // Fine.
                printf("\nFine.");
                break;
            }

            case 3:{

                // Scelta.
                printf("\n\nHai scelto: Hanoi graphics.h...");

                // Chiedo numero di cilindri.
                int nCilindri;
                do {

                    printf("\n\nInserire il numero di cilindri: ");
                    scanf("%d", &nCilindri);

                    if (nCilindri == 0){
                        printf("\nPer favore inserire un valore maggiore di 0.");
                    }

                } while (nCilindri <= 0);
                // Setto la variabile gloabale al numero di cilindri inseriti dall'utente.
                nCilindriG = nCilindri;

                // Resetta il vettore e setta il primo vettore con i valori di default iniziali.
                resetVett();
                setColonnaABase(nCilindri);

                // Chiedo il delay all'utente.
                if (!pausaClick){
                    printf("\nInserire un delay in millisecondi (default 100ms): ");
                    scanf("%d", &delay);
                }

                // Comunico il numero di cilindri e inizio.
                printf("\nNumero cilindri: %d. "
                       "\nInizio...", nCilindri);

                int asta = 0;
                while (asta != 1 && asta != 2) {
                    printf("\n\nInserire la colonna/asta di destinazione (2 o 3)"
                           "\nScelta: ");
                    scanf("%d", &asta);
                    asta--;

                    if (asta != 1 && asta != 2){
                        printf("\n\nValore non valido, riprova.");
                    }
                }

                // Pausa iniziale prima dell'inizio.
                Sleep(delay);

                // CLS TESTO
                system("CLS");
                // Mostro la grafica dei vettori attuale, questa volta con la graphics.h.
                graficaVettoriAttuale2();
                // Eseguo.
                if (asta == 1) {
                    ordinaCilindriGrafico2(nCilindri, 0, 1, 2);
                } else if (asta == 2){
                    ordinaCilindriGrafico2(nCilindri, 0, 2, 1);
                }

                // Fine e pausa piu' grande rispetto al delay (moltiplico il delay).
                printf("\nFine.");
                Sleep(1000 * 5);

                break;
            }

            default:{

                // Scelta non valida, comunico all'utente di riprovare.
                printf("\n\nHai inserito una scelta non valida, per favore riprovare!");

                break;
            }
        }

    } while (scelta != 0);

    // Uscito con successo, messaggio di chiusura.
    printf("\nUscito con successo!");

    return 0;
}

void ordinaCilindriGrafico(int num, int A, int B, int C){
    // Se il numero dei cilindri e' uguale a uno, allora sposta dalla colonna parametro A al parametro B, e ritorno.
    if (num == 1){
        // Sposta cilindro in cima.
        vet[posCilCimaVet(A)][A] = 0;
        vet[posCilCimaVet(B) + 1][B] = 1;
        printf("\nSpostato disco 1 dalla colonna %d alla colonna %d.", A, B);
        // Pausa.
        if (!pausaClick) {
            Sleep(delay);
        }
        // Mostro la grafica attuale.
        graficaVettoriAttuale();
        return;
    }
    // Richiamo in modo ricorsivo la funzione con i parametri B e C scambiati.
    ordinaCilindriGrafico(num - 1, A, C, B);
    // Sposta cilindro in cima.
    vet[posCilCimaVet(A)][A] = 0;
    vet[posCilCimaVet(B) + 1][B] = num;
    // Comunico lo spostamento dei cilindri.
    printf("\nSpostato disco %d dalla colonna %d alla colonna %d.", num, A, B);
    // Pausa.
    if (!pausaClick) {
        Sleep(delay);
    }
    // Mostrare qui grafica.
    graficaVettoriAttuale();
    // Richiamo la funzione scambiando C ed A e decremento num ossia il numero di cilindri.
    ordinaCilindriGrafico(num - 1, C, B, A);
}

void ordinaCilindriGrafico2(int num, int A, int B, int C){
    // Se il numero di cilindri e' uguale a uno, allora eseguo questo spostamento e ritorno.
    if (num == 1){
        // Sposta cilindro in cima.
        vet[posCilCimaVet(A)][A] = 0;
        vet[posCilCimaVet(B) + 1][B] = 1;
        // Pausa.
        if (!pausaClick) {
            Sleep(delay);
        }
        // Mostrare qui grafica.
        graficaVettoriAttuale2();
        return;
    }
    // Richiamo la funzione in modo ricorsivo scambiando parametri C e B.
    ordinaCilindriGrafico2(num - 1, A, C, B);
    // Sposta cilindro in cima.
    vet[posCilCimaVet(A)][A] = 0;
    vet[posCilCimaVet(B) + 1][B] = num;
    // Pausa.
    if (!pausaClick) {
        Sleep(delay);
    }
    // Mostrare qui grafica.
    graficaVettoriAttuale2();
    // Richiamo in modo ricorsivo scambiando A e C, e decrementando il numero di cilindri.
    ordinaCilindriGrafico2(num - 1, C, B, A);
}

void ordinaCilindri(int num, int A, int B, int C){
    // Ordinamento base di Hanoi, se 1 cilindri e' presente allora esegue questo e ritorna per passare all'asta successiva.
    if (num == 1){
        // Comunico spostamento del parametro A in B.
        printf("\n Spostato disco 1 dalla colonna %d alla colonna %d", A, B);
        // Pausa.
        if (!pausaClick) {
            Sleep(delay);
        }
        return;
    }
    // Richiamo in modo ricorsivo la funzione scambiando B e C.
    ordinaCilindri(num - 1, A, C, B);
    // Comunico l'azione eseguita e il numero del cilindro interessato.
    printf("\n Spostato disco %d dalla colonna %d alla colonna %d", num, A, B);
    // Pausa.
    if (!pausaClick) {
        Sleep(delay);
    }
    // Richiamo in modo ricorsivo la funzione, scambiando A e C e decrementando il numero di cilindri.
    ordinaCilindri(num - 1, C, B, A);
}

// Ottengo la posizione dell'elemento in cima al vettore, nel caso non sia presente, allora ritorno un valore bandiera di -1.
int posCilCimaVet(int nVet){
    int nVal = -1;
    while (true){
        if (vet[nVal + 1][nVet] != 0){
            nVal++;
        } else {
            return nVal;
        }
    }
}

void graficaVettoriAttuale(){
    // Mostro un debug della grafica testuale delle aste attuali.
    for (int i = 0; i < 3; i++) {
        printf("\n\nVet %d: ", i);
        for (int j = 0; j < nCilindriG; j++) {
            if (vet[j][i] != 0) {
                printf("\n%d -> %d", j, vet[j][i]);
            }
        }
    }
    // Mando a capo.
    printf("\n");
}

// Grafica importante con l'ausilio della graphics.h.
void graficaVettoriAttuale2(){

    // Pulisco la console.
    pulisciGrafica();

    // Rettangolo alla base.
    rettangolo(xSinRet, ySinRet, xDesRet, yDesRet, bianco, true);

    // Aste.
    linea(xBasAst1, yBasAst1, xCimAst1, yCimAst1, rosso);
    linea(xBasAst2, yBasAst2, xCimAst2, yCimAst2, rosso);
    linea(xBasAst3, yBasAst3, xCimAst3, yCimAst3, rosso);

    // Ottengo la dimensione dinamica in base all'unita' e numero di cilindri scelti, in modo da non uscire mai oltre alla
    // Dimensione dell'asta e non sovrapporre i cilindri.
    int dimUnitaCilOriz = (xDesRet - xSinRet) / (nCilindriG * 1.5);
    int dimUnitaCilVert = (yBasAst1 - yCimAst1) / (nCilindriG * 1);

    // Ciclo for per ogni asta.
    for (int i = 0; i < 3; i++) {
        // Coordinate e variabili importanti.
        int yCil = yBasAst1;
        int xCilCentro;
        // In base al numero di i, si scelgono le coordinate di riferimento per il centro del rettangolo/cilindro.
        if (i == 0){
            xCilCentro = xBasAst1;
        } else if (i == 1){
            xCilCentro = xBasAst2;
        } else if (i == 2){
            xCilCentro = xBasAst3;
        }

        // Ciclo for che scrive i rettangoli.
        for (int j = 0; j < nCilindriG; j++){
            // Se il valore nel vettore è diverso da 0, allora aggiunge il disco.
            if (vet[j][i] != 0) {
                // Calcola la posizione delle coordinate a sinistra e a destra del rettangolo/cilindro.
                int xDestraSinistraOffset = (vet[j][i] * dimUnitaCilOriz) / 5;
                // Disegna rettangolo con la graphics.h.
                rettangolo(xCilCentro - xDestraSinistraOffset, yCil, xCilCentro + xDestraSinistraOffset, yCil - dimUnitaCilVert, arancione, false);
            }
            // Sposto l'altezza del cilindro.
            yCil -= dimUnitaCilVert;
        }
    }
}

// Imposta i valori del vettore base per la grafica in modo ordinato.
void setColonnaABase(int nCilindri){
    for (int i = 0; i < nCilindri; i++) {
        vet[i][0] = nCilindri - i;
    }
}

// Resetta il vettore con degli 0.
void resetVett(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 100; j++) {
            vet[j][i] = 0;
        }
    }
}

int pulisciGrafica(){
    rettangolo(0,0, 100*unita, 100*unita, nero, true);
}

// Inutile ormai, serviva per l'opzione non funzionante della pausa sul click, ma questa cancellava la graphics in pausa.
bool inputBool(){

    while (true){

        int num;
        printf("\n0 -> No."
               "\n1 -> Si."
               "\nScelta: ");
        scanf("%d", &num);

        if (num == 1){
            printf("\nHai scelto: Si.");
            return true;
        } else if (num == 0){
            printf("\nHai scelto: No.");
            return false;
        }
        printf("\nScelta non valida, per favore riprovare.");
    }
}