#include <cstdio>
#include <graphics.h>
#include <time.h>
#include <chrono>
#include <iostream>

void continua();

int main() {

    // Valore bandiera, se diverso da 1 allora finisce il gioco.
    int vuoleGiocare = 1;

    // Messaggio del creatore
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//            Memory di Gabriele Caretti 3BITI              //"
           "\n//////////////////////////////////////////////////////////////\n");

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
        int vettoreConNum[6][6] = {0}, vetNumPossibili[18] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
        srand(time(0));

        // Assegna valori casuali a coppie.
        for (int i = 0; i < numeroCarte/2; i++) {
            int nValTemp = 0;

            while (nValTemp != 2){

                int riga = rand() % (5 - (0) + 1) + (0);
                int colonna = rand() % (5 - (0) + 1) + (0);

                if (vettoreConNum[riga][colonna] == 0){
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
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

        // Continua fintanto che l'utente non abbia vinto
        while (vinto == 0) {

            tentativi++;

            // Variabili
            int xTent, yTent, x2Tent, y2Tent;

            // Pulisce il terminale e scrive gli spazi per non sovrascrivere la grafica con il testo.
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

            // Parametri grafici
            int xc, yc, incremX = 40, incremY = 40, spazio = 5;

            // Parte grafica
            yc = 50;
            for(int i = 0; i<y; i++){
                xc = 10;
                for(int j = 0; j<x; j++){
                    if (vettore[j][i] == 1){
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
            xTent--;
            yTent = y - yTent;

            // Pulisce il terminale e scrive gli spazi per non sovrascrivere la grafica con il testo.
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

            // Parte grafica
            yc = 50;
            for(int i = 0; i<y; i++){
                xc = 10;
                for(int j = 0; j<x; j++){
                    if (xTent == j && yTent == i){
                        rettangolo(xc, yc, xc + incremX, yc + incremY, verde, false);
                    } else if (vettore[j][i] == 1){
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
            x2Tent--;
            y2Tent = y - y2Tent;

            // Pulisce il terminale e scrive gli spazi per non sovrascrivere la grafica con il testo.
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

            // Parte grafica
            yc = 50;
            for(int i = 0; i<y; i++){
                xc = 10;
                for(int j = 0; j<x; j++){
                    if (xTent == j && yTent == i || x2Tent == j && y2Tent == i){
                        rettangolo(xc, yc, xc + incremX, yc + incremY, verde, false);
                    } else if (vettore[j][i] == 1){
                        rettangolo(xc, yc, xc + incremX, yc + incremY, arancione, true);
                    } else {
                        rettangolo(xc, yc, xc + incremX, yc + incremY, arancione, false);
                    }
                    xc += incremX + spazio;
                }
                yc += incremY + spazio;
            }

            // Variabile booleana, verifica se i due valori del vettore sono uguali ed esegue le condizioni a esso collegate.
            bool valoreGiusto = vettoreConNum[xTent][yTent] == vettoreConNum[x2Tent][y2Tent];
            if (valoreGiusto && (xTent != x2Tent || yTent != y2Tent) && (vettore[xTent][yTent] != 1 && vettore[x2Tent][y2Tent] != 1)){
                printf("\nHai indovinato! Sia la carta 1 che 2 hanno il valore %d!", vettoreConNum[xTent][yTent]);
                vettore[xTent][yTent] = 1;
                vettore[x2Tent][y2Tent] = 1;
                coppieTrovate++;
            } else if ((xTent != x2Tent || yTent != y2Tent) && (vettore[xTent][yTent] != 1 && vettore[x2Tent][y2Tent] != 1)){
                printf("\nLe carte sono diverse, la carta 1 vale -> %d mentre la carta 2 -> %d", vettoreConNum[xTent][yTent], vettoreConNum[x2Tent][y2Tent]);
            } else if (xTent == x2Tent && yTent == y2Tent){
                printf("\nHai messo le stesse coordinate per entrambi i punti!");
            } else if ((vettore[xTent][yTent] == 1 || vettore[x2Tent][y2Tent] == 1)){
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
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        // Messaggio di vittoria.
        printf("\nCongratulazioni, hai vinto in %d tentativi!\n", tentativi);
        std::cout << "Hai impiegato: " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << " secondi per finire il Memory!" << std::endl;

        // Chiede se vuole ancora giocare.
        printf("\nVuoi ancora giocare? Scegli: "
               "\n0 -> No"
               "\n1 -> Si"
               "\nScelta: ");
        scanf("%d", &vuoleGiocare);
    }

    // Messaggio di fine.
    printf("\n\nChiusura in corso..."
           "\nChiuso con successo!");

    return 0;
}


void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}

