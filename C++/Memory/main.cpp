#include <cstdio>
#include <graphics.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
// #include <chrono>
#include <iostream>

using namespace std;

void continua();

void memoryParametrizzato(int x);

void poligonoCol(int xc, int yc, int incremX, int incremY, bool trovato, int colore);

int main() {

    // Valore bandiera, se diverso da 1 allora finisce il gioco.
    int sceltaMemory = 1;

    // Messaggio del creatore
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//            Memory di Gabriele Caretti 3BITI              //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Fintanto che la scelta è diversa da 0 (esci) allora andrà avanti.
    while (sceltaMemory != 0) {

        // Legenda e input utente
        printf("\nLegenda Memory: "
               "\n 0 -> Chiudi."
               "\n 1 -> Memory 2x2."
               "\n 2 -> Memory 4x4."
               "\n 3 -> Memory 6x6."
               "\n 4 -> Generazione matrice vecchio."
               "\n 5 -> Generazione matrice nuovo."
               "\n 6 -> Memory parametrizzato."
               "\nScelta: ");
        scanf("%d", &sceltaMemory);

        // Switch tra le scelte del menu.
        switch (sceltaMemory) {

            case 0:{

                printf("\nHai scelto: chiudi...\n");

                break;
            }

            case 1:{

                // Richiamo funzione.
                memoryParametrizzato(2);

                break;
            }

            case 2:{

                // Richiamo funzione.
                memoryParametrizzato(4);

                break;
            }

            case 3:{

                int x;

                // Richiamo funzione.
                memoryParametrizzato(6);

                break;
            }

            case 4:{

                // Messaggio d'inizio
                printf("\nHai scelto: generazione matrice vecchio...");

                // Inizializzo variabili e parametri
                int numeroRigheEColonne = 0;

                // Chiedo input.
                printf("\nInserire numero di righe e colonne (un valore valido per entrambi) PARI: ");
                scanf("%d", &numeroRigheEColonne);

                // Inizializzo variabili e parametri
                int nTentativi = 0, matrice[500][500] = {0},
                        numeroCarteTot = numeroRigheEColonne * numeroRigheEColonne, valVerPari = numeroCarteTot, nNumeriPossibili = numeroCarteTot/2,
                        vetNPossibili[nNumeriPossibili];

                // Decremento per ottenere un valore come 0 o 1 (verifica se pari o dispari).
                while (valVerPari >= 2){
                    valVerPari -= 2;
                }

                // Verifica se il valore inserito dall'utente moltiplicato per se stesso da un numero pari.
                if(valVerPari != 0 || numeroRigheEColonne == 0){
                    printf("\nHai inserito un numero di righe e colonne non valido!");
                    continua();
                    break;
                }

                // Ottiene i valori possibili tra 1 e nNumeri
                for (int i = 0; i < nNumeriPossibili; i++) {
                    vetNPossibili[i] = i + 1;
                }

                srand(time(0));

                // Assegna a coppie i valori in ordine.
                for (int i = 0; i < numeroCarteTot / 2; i++) {
                    int nValTemp = 0;

                    while (nValTemp != 2) {

                        nTentativi++;

                        int riga = rand() % numeroRigheEColonne;
                        int colonna = rand() % numeroRigheEColonne;

                        if (matrice[riga][colonna] == 0) {
                            matrice[riga][colonna] = vetNPossibili[i];
                            printf("\nmatrice[%d][%d] = %d", riga, colonna, vetNPossibili[i]);
                            nValTemp++;
                        }
                    }
                }

                // Stampo i valori.
                for (int i = 0; i < numeroRigheEColonne; i++) {
                    printf("\n");
                    for (int j = 0; j < numeroRigheEColonne; j++) {
                        printf("\t%d", matrice[i][j]);
                    }
                }

                // Comunico i risultati.
                printf("\n%d Valori generati con successo in %d tentativi a coppie.", numeroCarteTot, nTentativi);

                continua();
                break;
            }

            case 5:{

                // Messaggio d'inizio.
                printf("\nHai scelto: generazione matrice nuovo...");

                // Inizializzo variabili e parametri.
                int numeroRigheEColonne = 0;

                // Richiedo input.
                printf("\nInserire numero di righe e colonne (un valore valido per entrambi) PARI: ");
                scanf("%d", &numeroRigheEColonne);

                // Inizializzo variabili e parametri
                int nTentativi = 0,
                        matrice[500][500] = {0}, numeroCarteTot = numeroRigheEColonne * numeroRigheEColonne, valVerPari = numeroCarteTot,
                        nNumeriPossibili = numeroCarteTot/2, vetNPossibili[nNumeriPossibili];

                // Decrementa questo valore bandiera.
                while (valVerPari >= 2){
                    valVerPari -= 2;
                }

                // Verifica se si ha inserito un numero di colonne e righe che moltiplicati fanno un numero pari.
                if(valVerPari != 0 || numeroRigheEColonne == 0){
                    printf("\nHai inserito un numero di righe e colonne non valido!");
                    continua();
                    break;
                }


                // Ottengo tutti i valori possibile tra 1 e nNumeri
                for (int i = 0; i < nNumeriPossibili; i++) {
                    vetNPossibili[i] = i + 1;
                }

                srand(time(0));

                // Assegna valori a coppie, in ordine.
                int riga = 0, colonna = 0;
                for (int i = 0; i < numeroCarteTot / 2; i++) {
                    int nValTemp = 0;

                    while (nValTemp != 2) {
                        if (colonna == numeroRigheEColonne){
                            riga++;
                            colonna = 0;
                        }
                        matrice[riga][colonna] = vetNPossibili[i];
                        printf("\nMatrice[%d][%d] = %d", riga, colonna, vetNPossibili[i]);
                        colonna++;
                        nTentativi++;
                        nValTemp++;
                    }
                }

                // Miscelatore.
                int t1,t2;
                for(int i = 0; i < numeroRigheEColonne; i++){
                    for(int k=0; k < numeroRigheEColonne; k++){
                        // Righe
                        int r2 = rand() % numeroRigheEColonne;
                        for(int m=0;m<numeroRigheEColonne;m++){
                            nTentativi++;
                            t1=matrice[k][m];
                            t2=matrice[r2][m];
                            matrice[r2][m]=t1;
                            matrice[k][m]=t2;
                        }
                        // Colonne.
                        r2 = rand() % numeroRigheEColonne;
                        for(int m=0;m<numeroRigheEColonne;m++){
                            nTentativi++;
                            t1=matrice[k][m];
                            t2=matrice[k][r2];
                            matrice[k][r2]=t1;
                            matrice[k][m]=t2;
                        }
                    }
                }

                // Mostra valori
                for (int i = 0; i < numeroRigheEColonne; i++) {
                    printf("\n");
                    for (int j = 0; j < numeroRigheEColonne; j++) {
                        printf("\t%d", matrice[i][j]);
                    }
                }

                // Comunico all'utente i risultati.
                printf("\n%d Valori generati con successo in %d tentativi a coppie.", numeroCarteTot, nTentativi);

                continua();
                break;
            }

            case 6:{

                int x;

                // Chiedo input
                printf("\nInserire righe/colonne memory: ");
                scanf("%d", &x);

                memoryParametrizzato(x);

                break;
            }

            default:{

                printf("\nHai inserito un valore non valido, per favore riprova.");

                continua();
                break;
            }

        }
    }

    // Messaggio di fine.
    printf("\n\nChiusura in corso..."
           "\nChiuso con successo!");

    return 0;
}

void memoryParametrizzato(int x) {

    int vuoleGiocare = 1;

    // Loop che continua fintanto che la variabile bandiera abbia un valore diverso da 0
    while (vuoleGiocare != 0) {

        // Inizializzo variabili e parametri
        int y = x, vinto = 0, coppieTrovate = 0, tentativi = 0;

        int nTentativi = 0, vettoreConNum[200][200] = {0},
                numeroCarteTot = x * x, valVerPari = numeroCarteTot, nNumeriPossibili = numeroCarteTot/2,
                vetNPossibili[nNumeriPossibili];

        // Decremento per ottenere un valore come 0 o 1 (verifica se pari o dispari).
        while (valVerPari >= 2){
            valVerPari -= 2;
        }

        // Verifica se il valore inserito dall'utente moltiplicato per se stesso da un numero pari.
        if(valVerPari != 0 || x == 0){
            printf("\nHai inserito un numero di righe e colonne non valido!");
            continua();
            break;
        }

        // Ottiene i valori possibili tra 1 e nNumeri
        for (int i = 0; i < nNumeriPossibili; i++) {
            vetNPossibili[i] = i + 1;
        }

        srand(time(0));

        // Assegna a coppie i valori in ordine.
        for (int i = 0; i < numeroCarteTot / 2; i++) {
            int nValTemp = 0;

            while (nValTemp != 2) {

                int riga = rand() % x;
                int colonna = rand() % x;

                if (vettoreConNum[riga][colonna] == 0) {
                    vettoreConNum[riga][colonna] = vetNPossibili[i];
                    nValTemp++;
                }
            }
        }

        // Comunica informazioni riguardo al gioco
        printf("\nLe dimensioni totali sono un %d x %d per un totale di %d carte, significa che ci saranno %d coppie"
               "\nda trovare.\n", x, y, numeroCarteTot, nNumeriPossibili);

        // Comunica come continuare
        printf("\n\nPer giocare, seguire le seguenti istruzioni: "
               "\n - Inserire entrambe le coordinate come su un normale piano cartesiano, le coordinate"
               "\nIniziano con x e y uguali a 1, e massimo le dimensioni massime."
               "\n - Ad ogni turno, ti saranno chieste le coordinate di prima una carta, poi della seconda,"
               "\nInserisci ad esempio (1 1) e (2 2) per scegliere la carta 1 e 2 a quelle posizioni."
               "\n - Se le carte sono diverse, quindi non si ha indovinato, sarà mostrato il memory con "
               "\nLe coppie a colori."
               "\n - Se inserisci coordinate non valide (dimensioni troppo alte o già indovinate) ti sarà comunicato."
               "\n - Ad ogni azioni ti sarà richiesto di inserire un numero per continuare."
               "\ndigitare un numero a caso per iniziare: ");
        int inusato;
        scanf("%d", &inusato);

        // Variabili essenziali
        int vettore[200][200] = {0};

        // Tempo inizio
        clock_t inizio = clock();

        // Continua fintanto che l'utente non abbia vinto
        while (vinto == 0) {

            tentativi++;

            // Variabili
            int xTent, yTent, x2Tent, y2Tent;
            bool nonValidi = false;

            // Pulisce il terminale e scrive gli spazi per non sovrascrivere la grafica con il testo.
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

            // Parametri grafici
            int xc, yc, incremX = 40, incremY = 40, spazio = 5;

            // Parte grafica
            yc = 50;
            for (int i = 0; i < y; i++) {
                xc = 10;
                for (int j = 0; j < x; j++) {
                    if (vettore[j][i] == 1) {
                        rettangolo(xc, yc, xc + incremX, yc + incremY, arancione, true);
                    } else {
                        rettangolo(xc, yc, xc + incremX, yc + incremY, arancione, false);
                    }
                    xc += incremX + spazio;
                }
                yc += incremY + spazio;
            }

            // Comunica il numero del tentativo e chiede dati in ingresso
            printf("\nTentativo n.%d"
                   "\nInserire coordinate da provare carta 1 (inserire x e y con spazio, es: 1 2): ", tentativi);
            scanf("%d %d", &xTent, &yTent);
            if (xTent > x || yTent > y){
                nonValidi = true;
            }
            xTent--;
            yTent = y - yTent;

            // Pulisce il terminale e scrive gli spazi per non sovrascrivere la grafica con il testo.
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

            // Parte grafica
            yc = 50;
            for (int i = 0; i < y; i++) {
                xc = 10;
                for (int j = 0; j < x; j++) {
                    if (xTent == j && yTent == i) {
                        rettangolo(xc, yc, xc + incremX, yc + incremY, verde, false);
                    } else if (vettore[j][i] == 1) {
                        rettangolo(xc, yc, xc + incremX, yc + incremY, arancione, true);
                    } else {
                        rettangolo(xc, yc, xc + incremX, yc + incremY, arancione, false);
                    }
                    xc += incremX + spazio;
                }
                yc += incremY + spazio;
            }

            // Comunica all'utente il numero di tentativi e richiede un input delle coordinate.
            printf("\nInserire coordinate da provare carta 2 (scrivere x e y con spazio, es: x y): ");
            scanf("%d %d", &x2Tent, &y2Tent);
            if (x2Tent > x || y2Tent > y){
                nonValidi = true;
            }
            x2Tent--;
            y2Tent = y - y2Tent;

            // Pulisce il terminale e scrive gli spazi per non sovrascrivere la grafica con il testo.
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

            // Parte grafica
            yc = 50;
            for (int i = 0; i < y; i++) {
                xc = 10;
                for (int j = 0; j < x; j++) {
                    if ((xTent == j && yTent == i) || (x2Tent == j && y2Tent == i)) {
                        rettangolo(xc, yc, xc + incremX, yc + incremY, verde, false);
                    } else if (vettore[j][i] == 1) {
                        rettangolo(xc, yc, xc + incremX, yc + incremY, arancione, true);
                    } else {
                        rettangolo(xc, yc, xc + incremX, yc + incremY, arancione, false);
                    }
                    xc += incremX + spazio;
                }
                yc += incremY + spazio;
            }

            if (nonValidi){
                printf("\nUno dei valori non e' valido, magari e' maggiore del massimo X o Y.");
            }

            // Variabile booleana, verifica se i due valori del vettore sono uguali ed esegue le condizioni a esso collegate.
            bool valoreGiusto = vettoreConNum[xTent][yTent] == vettoreConNum[x2Tent][y2Tent];
            if (valoreGiusto && (xTent != x2Tent || yTent != y2Tent) &&
                (vettore[xTent][yTent] != 1 && vettore[x2Tent][y2Tent] != 1)) {
                printf("\nHai indovinato! Sia la carta 1 che 2 hanno il valore %d!",
                       vettoreConNum[xTent][yTent]);
                vettore[xTent][yTent] = 1;
                vettore[x2Tent][y2Tent] = 1;
                coppieTrovate++;
            } else if ((xTent != x2Tent || yTent != y2Tent) &&
                       (vettore[xTent][yTent] != 1 && vettore[x2Tent][y2Tent] != 1)) {
                printf("\nLe carte sono diverse, la carta 1 vale -> %d mentre la carta 2 -> %d",
                       vettoreConNum[xTent][yTent], vettoreConNum[x2Tent][y2Tent]);
            } else if (xTent == x2Tent && yTent == y2Tent) {
                printf("\nHai messo le stesse coordinate per entrambi i punti!");
            } else if ((vettore[xTent][yTent] == 1 || vettore[x2Tent][y2Tent] == 1)) {
                printf("\nHai inserito delle coordinate di carte gia' trovate in precedenza!");
            }

            // Se l'utente ha trovato tutte le carte, allora vinto verrà incrementato e finirà il gioco -> Vittoria!
            if (coppieTrovate == nNumeriPossibili){
                vinto++;
            }

            // Pausa, attende conferma.
            continua();

            // Parte grafica custom
            if(!valoreGiusto){

                // Pulisce il terminale
                system("cls");

                // Parte grafica
                yc = 50;
                for (int i = 0; i < y; i++) {
                    xc = 10;
                    for (int j = 0; j < x; j++) {
                        bool trovato = false;
                        if (vettore[j][i] == 1) {
                            trovato = true;
                        }
                        int colore = vettoreConNum[j][i];
                        poligonoCol(xc, yc, incremX, incremY, trovato, colore);
                        xc += incremX + spazio;
                    }
                    yc += incremY + spazio;
                }

                continua();
            }

            // Pulisce il terminale in preparazione alla nuova graphics o turno.
            system("cls");
        }

        // Tempo fine
        clock_t fine = clock();

        // Messaggio di vittoria.
        printf("\nCongratulazioni, hai vinto in %d tentativi!\n", tentativi);
        cout << "Hai impiegato: " << fine-inizio/CLOCKS_PER_SEC << " secondi per finire il Memory!" << endl;

        // Chiede se vuole ancora giocare.
        printf("\nVuoi ancora giocare? Scegli: "
               "\n0 -> No"
               "\n1 -> Si"
               "\nScelta: ");
        scanf("%d", &vuoleGiocare);
    }
}

void poligonoCol(int xc, int yc, int incremX, int incremY, bool trovato, int colore) {
    switch (colore){
        case 1:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, rosso, trovato);

            break;
        }
        case 2:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, arancione, trovato);

            break;
        }
        case 3:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, giallo, trovato);

            break;
        }
        case 4:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, lime, trovato);

            break;
        }
        case 5:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, verde, trovato);

            break;
        }
        case 6:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, azzurro, trovato);

            break;
        }
        case 7:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, blu, trovato);

            break;
        }
        case 8:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, viola, trovato);

            break;
        }
        case 9:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, bianco, trovato);

            break;
        }
        case 10:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (128,255,255), trovato);

            break;
        }
        case 11:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (128,128,255), trovato);

            break;
        }
        case 12:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (128,128,128), trovato);

            break;
        }
        case 13:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (64,255,255), trovato);

            break;
        }

        case 14:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (64,64,255), trovato);

            break;
        }
        case 15:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (64,64,64), trovato);

            break;
        }
        case 16:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (196,64,64), trovato);

            break;
        }
        case 17:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (196,196,64), trovato);

            break;
        }
        case 18:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (196,196,196), trovato);

            break;
        }
        case 19:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (0,0,196), trovato);

            break;
        }
        case 20:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (0,196,196), trovato);

            break;
        }
        case 21:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (0,255,196), trovato);

            break;
        }
        case 22:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (255,255,196), trovato);

            break;
        }
        case 23:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (255,196,255), trovato);

            break;
        }
        case 24:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (196,0,196), trovato);

            break;
        }
        case 25:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (255,0,196), trovato);

            break;
        }
        case 26:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (240,240,196), trovato);

            break;
        }
        default:{

            rettangolo(xc, yc, xc + incremX, yc + incremY, RGB (196,0,0), trovato);

            break;
        }
    }
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}