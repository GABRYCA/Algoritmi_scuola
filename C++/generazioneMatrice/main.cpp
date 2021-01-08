#include <iostream>
#include <random>

void continua();

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
               "\n 1 -> Generazione matrice vecchio."
               "\n 2 -> Generazione matrice nuovo.""\nScelta: ");
        scanf("%d", &sceltaMemory);

        // Switch tra le scelte del menu.
        switch (sceltaMemory) {

            case 0:{

                printf("\nHai scelto: chiudi...\n");

                break;
            }

            case 1:{

                // Messaggio d'inizio
                printf("\nHai scelto: generazione matrice vecchio...");

                // Inizializzo variabili e parametri
                int numeroRigheEColonne = 0;

                // Chiedo input.
                printf("\nInserire numero di righe e colonne (un valore è valido per entrambi) PARI: ");
                scanf("%d", &numeroRigheEColonne);

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

            case 2:{

                // Messaggio d'inizio.
                printf("\nHai scelto: generazione matrice nuovo...");

                // Inizializzo variabili e parametri.
                int numeroRigheEColonne = 0;

                // Richiedo input.
                printf("\nInserire numero di righe e colonne (un valore è valido per entrambi) PARI: ");
                scanf("%d", &numeroRigheEColonne);

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

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}
