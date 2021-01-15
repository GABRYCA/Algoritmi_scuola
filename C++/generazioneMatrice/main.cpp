#include <iostream>
#include <random>
#include <string>

using namespace std;

void continua();

void nomiCarte(int numero, int tipo);

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
               "\n 2 -> Generazione matrice nuovo."
               "\n 3 -> Gioco di carte."
               "\n 4 -> Stringhe.""\nScelta: ");
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
            case 3:{

                printf("\nHai scelto: gioco di carte...");

                printf("\n\n------------Come si gioca:------------");
                printf("\nHai un mazzo da 52 e una mano da 7."
                       "\nAd ogni turno potrai scegliere se:"
                       "\n - Mischiare le carte (mazzo e in mano), quindi ottieni una nuova mano"
                       "\n - Vedere una carta nel mazzo in una posizione casuale tra 1 e 52");

                // Carte da 1 a re e da fiori a picche.
                int carte[52][2] = {
                        {1,1},
                        {1,2},
                        {1,3},
                        {1,4},
                        {1,5},
                        {1,6},
                        {1,7},
                        {1,8},
                        {1,9},
                        {1,10},
                        {1,11},
                        {1,12},
                        {1,13},
                        {2,1},
                        {2,2},
                        {2,3},
                        {2,4},
                        {2,5},
                        {2,6},
                        {2,7},
                        {2,8},
                        {2,9},
                        {2,10},
                        {2,11},
                        {2,12},
                        {2,13},
                        {3,1},
                        {3,2},
                        {3,3},
                        {3,4},
                        {3,5},
                        {3,6},
                        {3,7},
                        {3,8},
                        {3,9},
                        {3,10},
                        {3,11},
                        {3,12},
                        {3,13},
                        {4,1},
                        {4,2},
                        {4,3},
                        {4,4},
                        {4,5},
                        {4,6},
                        {4,7},
                        {4,8},
                        {4,9},
                        {4,10},
                        {4,11},
                        {4,12},
                        {4,13},
                };

                srand(time(0));

                // Mischio le carte per la prima volta
                for (int i=0; i<52; i++){
                    int numeroACaso = rand() % 52;
                    for (int j = 0; j < 2; j++){
                        int valCarta1 = carte[i][j];
                        carte[i][j] = carte[numeroACaso][j];
                        carte[numeroACaso][j] = valCarta1;
                    }
                }
                printf("\n\nCarte mischiate con successo!");

                // Carte mano casuale
                int mano[7][2] = {0};
                int carteManoSuccesso = 0;
                while (carteManoSuccesso < 7) {
                    int numeroACasoRiga = rand() % 52;
                    int valBandiera = 0;
                    for (int i = 0; i < 7; i++) {
                        if (mano[i][0] == carte[numeroACasoRiga][0] && mano[i][1] == carte[numeroACasoRiga][1]){
                            valBandiera++;
                        }
                    }
                    if (valBandiera == 0){
                        mano[carteManoSuccesso][0] = carte[numeroACasoRiga][0];
                        mano[carteManoSuccesso][1] = carte[numeroACasoRiga][1];
                        carteManoSuccesso++;
                    }
                }

                printf("\n\nMano creata con successo!");

                int vuoleUscire = 1;

                while (vuoleUscire != 0){

                    printf("\n\nScegli cosa fare: "
                           "\n 0 -> Esci"
                           "\n 1 -> Mostra mano."
                           "\n 2 -> Rimischia carte."
                           "\n 3 -> Mostra una carta del mazzo."
                           "\n 4 -> Crea nuova mano."
                           "\n 5 -> Mostra mazzo."
                           "\n 6 -> Mostra una carta della mano."
                           "\nScelta: ");
                    scanf("%d", &vuoleUscire);

                    switch (vuoleUscire) {

                        case 0:{

                            printf("\n\nHai scelto: chiudere il gioco..."
                                   "\n\n -> Chiusura in corso...");

                            break;
                        }

                        case 1:{

                            printf("\n\nHai scelto: Mostra mano...");

                            printf("\n\nCarte mano:");
                            for (int i = 0; i < 7; i++) {
                                printf("\nCarta %d: ", i + 1);

                                int numero = mano[i][1];
                                int tipo = mano[i][0];

                                nomiCarte(numero, tipo);
                            }

                            continua();
                            break;
                        }

                        case 2:{

                            printf("\n\nHai scelto: mischia carte...");

                            printf("\n\nMischiando le carte...");
                            for (int i=0; i<52; i++){
                                int numeroACaso = rand() % 52;
                                for (int j = 0; j < 2; j++){
                                    int valCarta1 = carte[i][j];
                                    carte[i][j] = carte[numeroACaso][j];
                                    carte[numeroACaso][j] = valCarta1;
                                }
                            }
                            printf("\nCarte mischiate con successo!");

                            continua();
                            break;
                        }

                        case 3:{

                            printf("\n\nHai scelto: Mostra una carta del mazzo...");

                            int cartaScelta = 0;

                            printf("\n\nPer favore inserire il numero della carta (minore/uguale a 52): ");
                            scanf("%d", &cartaScelta);

                            if (cartaScelta > 52 || cartaScelta == 0){
                                printf("\n\nHai inserito un valore non valido!");
                                continua();
                                break;
                            }

                            // Lo decremento perchè nel vettore la posizione 52 non esiste, e comunque è sempre
                            // -1 rispetto a quella inserita dall'utente per essere valido.
                            cartaScelta--;

                            printf("\n\nNome carta: ");
                            nomiCarte(carte[cartaScelta][1], carte[cartaScelta][0]);

                            continua();
                            break;
                        }

                        case 4:{

                            printf("\n\nHai scelto: crea nuova mano...");

                            printf("\n\nCreazione nuova mano in corso...");

                            // Carte mano casuale
                            int mano[7][2] = {0};
                            carteManoSuccesso = 0;
                            while (carteManoSuccesso < 7) {
                                int numeroACasoRiga = rand() % 52;
                                int valBandiera = 0;
                                for (int i = 0; i < 7; i++) {
                                    if (mano[i][0] == carte[numeroACasoRiga][0] && mano[i][1] == carte[numeroACasoRiga][1]){
                                        valBandiera++;
                                    }
                                }
                                if (valBandiera == 0){
                                    mano[carteManoSuccesso][0] = carte[numeroACasoRiga][0];
                                    mano[carteManoSuccesso][1] = carte[numeroACasoRiga][1];
                                    carteManoSuccesso++;
                                }
                            }

                            printf("\n\nCreata nuova mano con successo!");

                            continua();
                            break;
                        }

                        case 5:{

                            printf("\n\nHai scelto: Mostra mazzo");

                            printf("\n\nCarte del mazzo: ");
                            for (int i = 0; i < 52; i++) {
                                printf("\nCarta %d: ", i + 1);

                                nomiCarte(carte[i][1], carte[i][0]);
                            }

                            continua();
                            break;
                        }

                        case 6:{

                            printf("\n\nHai scelto: Mostra una carta della mano...");

                            int cartaScelta = 0;

                            printf("\n\nPer favore inserire il numero della carta (minore/uguale a 7): ");
                            scanf("%d", &cartaScelta);

                            if (cartaScelta > 7 || cartaScelta == 0){
                                printf("\n\nHai inserito un valore non valido!");
                                continua();
                                break;
                            }

                            // Lo decremento perchè nel vettore la posizione 52 non esiste, e comunque è sempre
                            // -1 rispetto a quella inserita dall'utente per essere valido.
                            cartaScelta--;

                            printf("\nNome carta: ");
                            nomiCarte(mano[cartaScelta][1], mano[cartaScelta][0]);

                            continua();
                            break;
                        }

                        default:{

                            printf("\nHai inserito una scelta non valida, per favore riprova!");

                            continua();
                            break;
                        }
                    }
                }
                printf("\n\nFine del gioco...");

                continua();
            }

            case 4:{

                printf("\nHai scelto: Stringhe...\n");

                // Ricordati che c'è sempre un errore!

                string s1 = "ciao mondo";
                string s2 = "ciao";
                string s3 = "pera nera";
                string s4 = "cia";

                cout << s1.compare(s2) << "\n";
                cout << s1.compare(0,4,s2) << "\n";
                cout << s3.compare(1,3, s2, 6,3) << "\n";
                cout << s3.compare(0,4,"pera") << "\n";
                cout << s4.compare(s1) << "\n";



                s1 = "ciao mondo";
                s2 = "al";

                cout << s1.insert(5,s2) << "\n";
                cout << s1.insert(13, " tondo") << "\n";



                s1 ="ciao mondo";
                s2 ="a tutti";
                s3 ="buongiorno buonasera";
                cout <<s1.replace(5, 9, s2) <<"\n";
                cout <<s1.replace(0, 3, s3, 0, 9) <<"\n";
                cout <<s1.replace(0, 13, "hallo" ) <<"\n";
                cout <<s1.replace(5, 6, "") <<"\n";
                cout <<s3.replace(0, 11, "") <<"\n";



                s1 ="ciao mondo";
                s2 ="buongiorno buonasera";
                cout <<s1.substr(5, 9) <<"\n";
                cout <<s2.substr(0, 10) <<"\n\n";



                s1 ="ciao mondo";
                s2 ="mondo";
                cout <<s1.find(s2) <<"\n";
                cout <<s1.find("do") <<"\n";
                cout <<s1.find("zz") <<"\n";



                s1 ="123";
                s2 ="12.3";
                int k1 = atoi(s1.c_str());
                float k2 = atof(s2.c_str());
                cout << k1 <<"\n";
                cout << k2 <<"\n\n";



                double n1 = 23.43;
                long n2 = 1.234;
                float n3 = 0.0001;
                string n1_str = to_string(n1);
                string n2_str = to_string(n2);
                string n3_str = to_string(n3);
                cout << n1_str <<"\n";
                cout << n2_str <<"\n";
                cout << n3_str <<"\n";

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

void nomiCarte(int numero, int tipo) {
    switch (numero) {
        case 1:{

            printf("1");

            break;
        }
        case 2:{

            printf("2");

            break;
        }
        case 3:{

            printf("3");

            break;
        }
        case 4:{

            printf("4");

            break;
        }
        case 5:{

            printf("5");

            break;
        }
        case 6:{

            printf("6");

            break;
        }
        case 7:{

            printf("7");

            break;
        }
        case 8:{

            printf("8");

            break;
        }
        case 9:{

            printf("9");

            break;
        }
        case 10:{

            printf("10");

            break;
        }
        case 11:{

            printf("Jack");

            break;
        }
        case 12:{

            printf("Regina");

            break;
        }
        case 13:{

            printf("Re");

            break;
        }
        default:{

            printf("Sconosciuto");

            break;
        }
    }

    printf(" di ");

    switch (tipo) {
        case 1:{

            printf("Fiori");

            break;
        }
        case 2:{

            printf("Quadri");

            break;
        }
        case 3:{

            printf("Cuori");

            break;
        }
        case 4:{

            printf("Picche");

            break;
        }
        default:{

            printf("Sconosciuto");

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
