#include <cstdio>
#include <graphics.h>
#include <time.h>
// #include <chrono>
#include <iostream>

void continua();

void memory2x2();
void memory4x4();
void memory6x6();

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
                memory2x2();

                break;
            }

            case 2:{

                // Richiamo funzione.
                memory4x4();

                break;
            }

            case 3:{

                // Richiamo funzione.
                memory6x6();

                break;
            }

            case 4:{

                // Messaggio d'inizio
                printf("\nHai scelto: generazione matrice vecchio...");

                // Inizializzo variabili e parametri
                int numeroRigheEColonne = 0, nTentativi = 0, matrice[500][500] = {0},
                        numeroCarteTot = numeroRigheEColonne * numeroRigheEColonne, valVerPari = numeroCarteTot, nNumeriPossibili = numeroCarteTot/2,
                        vetNPossibili[nNumeriPossibili];

                // Chiedo input.
                printf("\nInserire numero di righe e colonne (un valore è valido per entrambi) PARI: ");
                scanf("%d", &numeroRigheEColonne);

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
                int numeroRigheEColonne = 0, nTentativi = 0,
                        matrice[500][500] = {0}, numeroCarteTot = numeroRigheEColonne * numeroRigheEColonne, valVerPari = numeroCarteTot,
                        nNumeriPossibili = numeroCarteTot/2, vetNPossibili[nNumeriPossibili];

                // Richiedo input.
                printf("\nInserire numero di righe e colonne (un valore è valido per entrambi) PARI: ");
                scanf("%d", &numeroRigheEColonne);

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
                        printf("\nmatrice[%d][%d] = %d", riga, colonna, vetNPossibili[i]);
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

void memory2x2() {

    int vuoleGiocare = 1;

    // Loop che continua fintanto che la variabile bandiera abbia un valore diverso da 0
    while (vuoleGiocare != 0) {

        // Inizializzo variabili e parametri
        int numeroCarte = 4, x = 2, y = 2, vinto = 0, coppieTrovate = 0, tentativi = 0;

        // Comunica informazioni riguardo al gioco
        printf("\nLe dimensioni totali sono un %d x %d per un totale di %d carte, significa che ci saranno %d coppie"
               "\nda trovare.\n", x, y, numeroCarte, numeroCarte / 2);

        // Comunica come continuare
        printf("\n\nPer giocare, seguire le istruzioni a schermo..."
               "\ndigitare un numero a caso per iniziare: ");
        int inusato;
        scanf("%d", &inusato);

        // Variabili essenziali
        int vettore[2][2] = {0};
        int vettoreConNum[2][2] = {0}, vetNumPossibili[4] = {1, 2, 3, 4};
        srand(time(0));

        // Assegna valori casuali a coppie.
        for (int i = 0; i < numeroCarte / 2; i++) {
            int nValTemp = 0;

            while (nValTemp != 2) {

                int riga = rand() % (1 - (0) + 1) + (0);
                int colonna = rand() % (1 - (0) + 1) + (0);

                if (vettoreConNum[riga][colonna] == 0) {
                    vettoreConNum[riga][colonna] = vetNumPossibili[i];
                    nValTemp++;
                }
            }
        }

        // Mostra valori e coordinate
        //for (int i = 0; i < x; i++) {
        //    for (int j = 0; j < y; j++) {
        //        printf("\t%d", vettoreConNum[j][i]);
        //    }
        //    printf("\n");
        //}

        // continua();

        // Metodo per la generazione dei valori non funzionante per motivi ignoti.
        //for (int riga = 0; riga < x; riga++) {
        //    for (int colonna = 0; colonna < y; colonna++) {
        //        int numeroValido = 1;

        // Crea un numero casuale e verifica se questo è già disponibile 2 volte nel vettore, nel caso lo sia
        // Continua il loop fino a quando genera un numero valido, nel caso non lo sia, va avanti e lo aggiunge.
        //        while (numeroValido != 0) {
        //            int numeroVolteTrovato = 0;
        //            int numeroGenerato = rand() % (max - (min) + 1) + (min);

        //            for (int riga2 = 0; riga2 < riga; riga2++) {
        //                for (int colonna2 = 0; colonna2 < colonna; colonna2++) {
        //                    if (numeroGenerato == vettoreConNum[riga2][colonna2]){
        //                        numeroVolteTrovato++;
        //                    }
        //                }
        //            }

        // Significa che il numero è già presente almeno due volte se falso.
        //            if (numeroVolteTrovato == 1 || numeroVolteTrovato == 0){
        //                numeroValido = 0;
        //                vettoreConNum[riga][colonna] = numeroGenerato;
        //            }
        //        }
        //    }
        //}

        // Inizio timer
        // std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

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
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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
                   "\nInserire coordinate da provare carta 1: "
                   "\nx: ", tentativi);
            scanf("%d", &xTent);
            printf("y: ");
            scanf("%d", &yTent);
            if (xTent > x || yTent > y){
                nonValidi = true;
            }
            xTent--;
            yTent = y - yTent;

            // Pulisce il terminale e scrive gli spazi per non sovrascrivere la grafica con il testo.
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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
            printf("\nInserire coordinate da provare carta 2: "
                   "\nx: ");
            scanf("%d", &x2Tent);
            printf("y: ");
            scanf("%d", &y2Tent);
            if (x2Tent > x || y2Tent > y){
                nonValidi = true;
            }
            x2Tent--;
            y2Tent = y - y2Tent;

            // Pulisce il terminale e scrive gli spazi per non sovrascrivere la grafica con il testo.
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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
                printf("\nUno dei valori non è valido, magari è maggiore del massimo X o Y.");
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
                printf("\nHai inserito delle coordinate di carte già trovate in precedenza!");
            }

            // Se l'utente ha trovato tutte le carte, allora vinto verrà incrementato e finirà il gioco -> Vittoria!
            if (coppieTrovate == numeroCarte/2){
                vinto++;
            }

            // Pausa, attende conferma.
            continua();

            // Pulisce il terminale in preparazione alla nuova graphics o turno.
            system("cls");
        }

        // Tempo fine
        clock_t fine = clock();

        // Ferma timer
        // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

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

void memory4x4() {

    int vuoleGiocare = 1;

    // Loop che continua fintanto che la variabile bandiera abbia un valore diverso da 0
    while (vuoleGiocare != 0) {

        // Inizializzo variabili e parametri
        int numeroCarte = 16, x = 4, y = 4, vinto = 0, coppieTrovate = 0, tentativi = 0;

        // Comunica informazioni riguardo al gioco
        printf("\nLe dimensioni totali sono un %d x %d per un totale di %d carte, significa che ci saranno %d coppie"
               "\nda trovare.\n", x, y, numeroCarte, numeroCarte / 2);

        // Comunica come continuare
        printf("\n\nPer giocare, seguire le istruzioni a schermo..."
               "\ndigitare un numero a caso per iniziare: ");
        int inusato;
        scanf("%d", &inusato);

        // Variabili essenziali
        int vettore[4][4] = {0};
        int vettoreConNum[4][4] = {0}, vetNumPossibili[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
        srand(time(0));

        // Assegna valori casuali a coppie.
        for (int i = 0; i < numeroCarte / 2; i++) {
            int nValTemp = 0;

            while (nValTemp != 2) {

                int riga = rand() % (3 - (0) + 1) + (0);
                int colonna = rand() % (3 - (0) + 1) + (0);

                if (vettoreConNum[riga][colonna] == 0) {
                    vettoreConNum[riga][colonna] = vetNumPossibili[i];
                    nValTemp++;
                }
            }
        }

        // Mostra valori e coordinate
        //for (int i = 0; i < x; i++) {
        //    for (int j = 0; j < y; j++) {
        //        printf("\t%d", vettoreConNum[j][i]);
        //    }
        //    printf("\n");
        //}

        // continua();

        // Metodo per la generazione dei valori non funzionante per motivi ignoti.
        //for (int riga = 0; riga < x; riga++) {
        //    for (int colonna = 0; colonna < y; colonna++) {
        //        int numeroValido = 1;

        // Crea un numero casuale e verifica se questo è già disponibile 2 volte nel vettore, nel caso lo sia
        // Continua il loop fino a quando genera un numero valido, nel caso non lo sia, va avanti e lo aggiunge.
        //        while (numeroValido != 0) {
        //            int numeroVolteTrovato = 0;
        //            int numeroGenerato = rand() % (max - (min) + 1) + (min);

        //            for (int riga2 = 0; riga2 < riga; riga2++) {
        //                for (int colonna2 = 0; colonna2 < colonna; colonna2++) {
        //                    if (numeroGenerato == vettoreConNum[riga2][colonna2]){
        //                        numeroVolteTrovato++;
        //                    }
        //                }
        //            }

        // Significa che il numero è già presente almeno due volte se falso.
        //            if (numeroVolteTrovato == 1 || numeroVolteTrovato == 0){
        //                numeroValido = 0;
        //                vettoreConNum[riga][colonna] = numeroGenerato;
        //            }
        //        }
        //    }
        //}

        // Inizio timer
        // std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

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
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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
                   "\nInserire coordinate da provare carta 1: "
                   "\nx: ", tentativi);
            scanf("%d", &xTent);
            printf("y: ");
            scanf("%d", &yTent);
            if (xTent > x || yTent > y){
                nonValidi = true;
            }
            xTent--;
            yTent = y - yTent;

            // Pulisce il terminale e scrive gli spazi per non sovrascrivere la grafica con il testo.
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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
            printf("\nInserire coordinate da provare carta 2: "
                   "\nx: ");
            scanf("%d", &x2Tent);
            printf("y: ");
            scanf("%d", &y2Tent);
            if (x2Tent > x || y2Tent > y){
                nonValidi = true;
            }
            x2Tent--;
            y2Tent = y - y2Tent;

            // Pulisce il terminale e scrive gli spazi per non sovrascrivere la grafica con il testo.
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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
                printf("\nUno dei valori non è valido, magari è maggiore del massimo X o Y.");
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
                printf("\nHai inserito delle coordinate di carte già trovate in precedenza!");
            }

            // Se l'utente ha trovato tutte le carte, allora vinto verrà incrementato e finirà il gioco -> Vittoria!
            if (coppieTrovate == numeroCarte / 2) {
                vinto++;
            }

            // Pausa, attende conferma.
            continua();

            // Pulisce il terminale in preparazione alla nuova graphics o turno.
            system("cls");
        }

        // Ferma timer
        // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

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

void memory6x6() {

    int vuoleGiocare = 1;

    // Loop che continua fintanto che la variabile bandiera abbia un valore diverso da 0
    while (vuoleGiocare != 0) {

        // Inizializzo variabili e parametri
        int numeroCarte = 36, x = 6, y = 6, vinto = 0, coppieTrovate = 0, tentativi = 0;

        // Comunica informazioni riguardo al gioco
        printf("\nLe dimensioni totali sono un %d x %d per un totale di %d carte, significa che ci saranno %d coppie"
               "\nda trovare.\n", x, y, numeroCarte, numeroCarte / 2);

        // Comunica come continuare
        printf("\n\nPer giocare, seguire le istruzioni a schermo..."
               "\ndigitare un numero a caso per iniziare: ");
        int inusato;
        scanf("%d", &inusato);

        // Variabili essenziali
        int vettore[6][6] = {0};
        int vettoreConNum[6][6] = {0}, vetNumPossibili[18] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                                                              16,
                                                              17, 18};
        srand(time(0));

        // Assegna valori casuali a coppie.
        for (int i = 0; i < numeroCarte / 2; i++) {
            int nValTemp = 0;

            while (nValTemp != 2) {

                int riga = rand() % (5 - (0) + 1) + (0);
                int colonna = rand() % (5 - (0) + 1) + (0);

                if (vettoreConNum[riga][colonna] == 0) {
                    vettoreConNum[riga][colonna] = vetNumPossibili[i];
                    nValTemp++;
                }
            }
        }

        // Mostra valori e coordinate
        //for (int i = 0; i < x; i++) {
        //    for (int j = 0; j < y; j++) {
        //        printf("\t%d", vettoreConNum[j][i]);
        //    }
        //    printf("\n");
        //}

        // continua();

        // Metodo per la generazione dei valori non funzionante per motivi ignoti.
        //for (int riga = 0; riga < x; riga++) {
        //    for (int colonna = 0; colonna < y; colonna++) {
        //        int numeroValido = 1;

        // Crea un numero casuale e verifica se questo è già disponibile 2 volte nel vettore, nel caso lo sia
        // Continua il loop fino a quando genera un numero valido, nel caso non lo sia, va avanti e lo aggiunge.
        //        while (numeroValido != 0) {
        //            int numeroVolteTrovato = 0;
        //            int numeroGenerato = rand() % (max - (min) + 1) + (min);

        //            for (int riga2 = 0; riga2 < riga; riga2++) {
        //                for (int colonna2 = 0; colonna2 < colonna; colonna2++) {
        //                    if (numeroGenerato == vettoreConNum[riga2][colonna2]){
        //                        numeroVolteTrovato++;
        //                    }
        //                }
        //            }

        // Significa che il numero è già presente almeno due volte se falso.
        //            if (numeroVolteTrovato == 1 || numeroVolteTrovato == 0){
        //                numeroValido = 0;
        //                vettoreConNum[riga][colonna] = numeroGenerato;
        //            }
        //        }
        //    }
        //}

        // Inizio timer
        // std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

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
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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
                   "\nInserire coordinate da provare carta 1: "
                   "\nx: ", tentativi);
            scanf("%d", &xTent);
            printf("y: ");
            scanf("%d", &yTent);
            if (xTent > x || yTent > y){
                nonValidi = true;
            }
            xTent--;
            yTent = y - yTent;

            // Pulisce il terminale e scrive gli spazi per non sovrascrivere la grafica con il testo.
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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
            printf("\nInserire coordinate da provare carta 2: "
                   "\nx: ");
            scanf("%d", &x2Tent);
            printf("y: ");
            scanf("%d", &y2Tent);
            if (x2Tent > x || y2Tent > y){
                nonValidi = true;
            }
            x2Tent--;
            y2Tent = y - y2Tent;

            // Pulisce il terminale e scrive gli spazi per non sovrascrivere la grafica con il testo.
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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
                printf("\nUno dei valori non è valido, magari è maggiore del massimo X o Y.");
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
                printf("\nHai inserito delle coordinate di carte già trovate in precedenza!");
            }

            // Se l'utente ha trovato tutte le carte, allora vinto verrà incrementato e finirà il gioco -> Vittoria!
            if (coppieTrovate == numeroCarte / 2) {
                vinto++;
            }

            // Pausa, attende conferma.
            continua();

            // Pulisce il terminale in preparazione alla nuova graphics o turno.
            system("cls");
        }

        // Ferma timer
        // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

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


void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}

