#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

using namespace std;

void continua();

void nomiCarte(int numero, int tipo);

int main() {

    // Valore bandiera, se diverso da 1 allora finisce il gioco.
    int sceltaMemory = 1;

    // Messaggio del creatore
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//            Esercizi di Gabriele Caretti 3BITI            //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Fintanto che la scelta è diversa da 0 (esci) allora andrà avanti.
    while (sceltaMemory != 0) {

        // Legenda e input utente
        printf("\nLegenda Memory: "
               "\n 0 -> Chiudi."
               "\n 1 -> Generazione matrice vecchio."
               "\n 2 -> Generazione matrice nuovo."
               "\n 3 -> Gioco di carte."
               "\n 4 -> Stringhe."
               "\n 5 -> Altre cose con le stringhe."
               "\n 6 -> Esercizio con i record."
               "\n 7 -> Esercizio alunni.""\nScelta: ");
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

                // Messaggio d'inizio
                printf("\nHai scelto: gioco di carte...");

                // Legenda
                printf(RED "\n\n------------Come si gioca:------------" RESET);
                printf(YELLOW "\nHai un mazzo da 52 e una mano da 7."
                       "\nAd ogni turno potrai scegliere se: "
                       "\n - Mischiare le carte (mazzo e in mano), quindi ottieni una nuova mano"
                       "\n - Vedere una carta nel mazzo in una posizione casuale tra 1 e 52" RESET);

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

                // srand
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
                printf(GREEN "\n\nCarte mischiate con successo!" RESET);

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

                // Messaggio di successo
                printf(GREEN "\n\nMano creata con successo!" RESET);

                // Valore bandiera per uscire dal while delle opzioni (menu 2).
                int vuoleUscire = 1;
                while (vuoleUscire != 0){

                    // Legenda
                    printf(YELLOW "\n\nScegli cosa fare: "
                           "\n 0 -> Esci"
                           "\n 1 -> Mostra mano."
                           "\n 2 -> Rimischia carte."
                           "\n 3 -> Mostra una carta del mazzo."
                           "\n 4 -> Crea nuova mano."
                           "\n 5 -> Mostra mazzo."
                           "\n 6 -> Mostra una carta della mano."
                           "\nScelta: " RESET);
                    scanf("%d", &vuoleUscire);

                    // Opzioni
                    switch (vuoleUscire) {

                        case 0:{

                            // Chiude
                            printf(RED "\n\nHai scelto: chiudere il gioco..."
                                   "\n\n -> Chiusura in corso..." RESET);

                            break;
                        }

                        case 1:{

                            // Messaggio d'inizio
                            printf(YELLOW "\n\nHai scelto: Mostra mano..." RESET);

                            // Mostra la mano
                            printf(BLUE "\n\nCarte mano:" RESET);
                            for (int i = 0; i < 7; i++) {
                                printf(CYAN "\nCarta %d: " RESET, i + 1);

                                int numero = mano[i][1];
                                int tipo = mano[i][0];

                                nomiCarte(numero, tipo);
                            }

                            continua();
                            break;
                        }

                        case 2:{

                            // Messaggio d'inizio
                            printf(YELLOW "\n\nHai scelto: mischia carte..." RESET);

                            // Mischia le carte
                            printf(BLUE "\n\nMischiando le carte..." RESET);
                            for (int i=0; i<52; i++){
                                int numeroACaso = rand() % 52;
                                for (int j = 0; j < 2; j++){
                                    int valCarta1 = carte[i][j];
                                    carte[i][j] = carte[numeroACaso][j];
                                    carte[numeroACaso][j] = valCarta1;
                                }
                            }
                            printf(GREEN "\nCarte mischiate con successo!" RESET);

                            continua();
                            break;
                        }

                        case 3:{

                            // Messaggio d'inizio.
                            printf(YELLOW "\n\nHai scelto: Mostra una carta del mazzo..." RESET);

                            // Variabile che sarà scelta dall'utente.
                            int cartaScelta = 0;

                            // Chiedo input.
                            printf(CYAN "\n\nPer favore inserire il numero della carta (minore/uguale a 52): " RESET);
                            scanf("%d", &cartaScelta);

                            // Verifica sia valida.
                            if (cartaScelta > 52 || cartaScelta == 0){
                                printf(RED "\n\nHai inserito un valore non valido!" RESET);
                                continua();
                                break;
                            }

                            // Lo decremento perchè nel vettore la posizione 52 non esiste, e comunque è sempre
                            // -1 rispetto a quella inserita dall'utente per essere valido.
                            cartaScelta--;

                            // Comunica la carta.
                            printf(BLUE "\n\nNome carta: " RESET);
                            nomiCarte(carte[cartaScelta][1], carte[cartaScelta][0]);

                            continua();
                            break;
                        }

                        case 4:{

                            // Messaggio d'inizio.
                            printf(YELLOW "\n\nHai scelto: crea nuova mano..." RESET);

                            // Comunica che è in corso l'operazione.
                            printf(BLUE "\n\nCreazione nuova mano in corso..." RESET);

                            // Resetta valori mano a 0.
                            for (int i = 0; i < 7; i++) {
                                for (int j = 0; j < 2; j++) {
                                    mano[i][j] = 0;
                                }
                            }

                            // Carte mano casuale
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

                            // Successo.
                            printf(GREEN "\n\nCreata nuova mano con successo!" RESET);

                            continua();
                            break;
                        }

                        case 5:{

                            // Messaggio d'inizio.
                            printf(YELLOW "\n\nHai scelto: Mostra mazzo" RESET);

                            // Comunica le carte nel mazzo.
                            printf(BLUE "\n\nCarte del mazzo: " RESET);
                            for (int i = 0; i < 52; i++) {
                                printf(CYAN "\nCarta %d: " RESET, i + 1);

                                nomiCarte(carte[i][1], carte[i][0]);
                            }

                            continua();
                            break;
                        }

                        case 6:{

                            // Messaggio d'inizio.
                            printf(YELLOW "\n\nHai scelto: Mostra una carta della mano..." RESET);

                            // Variabile carta scelta.
                            int cartaScelta = 0;

                            // Chiede input.
                            printf(CYAN "\n\nPer favore inserire il numero della carta (minore/uguale a 7): " RESET);
                            scanf("%d", &cartaScelta);

                            // Verifica se la scelta è valida.
                            if (cartaScelta > 7 || cartaScelta == 0){
                                printf(RED "\n\nHai inserito un valore non valido!" RESET);
                                continua();
                                break;
                            }

                            // Lo decremento perchè nel vettore la posizione 52 non esiste, e comunque è sempre
                            // -1 rispetto a quella inserita dall'utente per essere valido.
                            cartaScelta--;

                            // Comunica il valore della carta.
                            printf(BLUE "\nNome carta: " RESET);
                            nomiCarte(mano[cartaScelta][1], mano[cartaScelta][0]);

                            continua();
                            break;
                        }

                        default:{

                            // Comunica errore selezione non valida.
                            printf(RED "\nHai inserito una scelta non valida, per favore riprova!" RESET);

                            continua();
                            break;
                        }
                    }
                }
                // FINE GIOCO.
                printf(RED "\n\nFine del gioco..." RESET);

                continua();
            }

            case 4:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Stringhe...\n");

                // Ricordati che c'è sempre un errore!

                // Primo.
                string s1 = "ciao mondo";
                string s2 = "ciao";
                string s3 = "pera nera";
                string s4 = "cia";

                cout << s1.compare(s2) << "\n";
                cout << s1.compare(0,4,s2) << "\n";
                cout << s3.compare(1,3, s2, 6,3) << "\n";
                cout << s3.compare(0,4,"pera") << "\n";
                cout << s4.compare(s1) << "\n";



                // Secondo.
                s1 = "ciao mondo";
                s2 = "al";

                cout << s1.insert(5,s2) << "\n";
                cout << s1.insert(13, " tondo") << "\n";



                // Terzo.
                s1 ="ciao mondo";
                s2 ="a tutti";
                s3 ="buongiorno buonasera";
                cout <<s1.replace(5, 9, s2) <<"\n";
                cout <<s1.replace(0, 3, s3, 0, 9) <<"\n";
                cout <<s1.replace(0, 13, "hallo" ) <<"\n";
                cout <<s1.replace(5, 6, "") <<"\n";
                cout <<s3.replace(0, 11, "") <<"\n";



                // Quarto.
                s1 ="ciao mondo";
                s2 ="buongiorno buonasera";
                cout <<s1.substr(5, 9) <<"\n";
                cout <<s2.substr(0, 10) <<"\n\n";



                // Quinto.
                s1 ="ciao mondo";
                s2 ="mondo";
                cout <<s1.find(s2) <<"\n";
                cout <<s1.find("do") <<"\n";
                cout <<s1.find("zz") <<"\n";



                // Sesto.
                s1 ="123";
                s2 ="12.3";
                int k1 = atoi(s1.c_str());
                float k2 = atof(s2.c_str());
                cout << k1 <<"\n";
                cout << k2 <<"\n\n";



                // Settimo.
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

            case 5:{

                string sonoUnaStringa = "\nHai scelto: gioco con le stringhe...";

                printf("%s", sonoUnaStringa.c_str());

                string parte1 = "Stringa 1";
                string parte2 = "Stringa 2";
                string sommaP1P2 = parte1 + " " + parte2;

                printf("\nSomma di stringhe:");
                printf("\n[%s] + [%s] = [%s]\n", parte1.c_str(), parte2.c_str(), sommaP1P2.c_str());

                printf("\nParagono di stringhe (0 diverse, 1 uguali):");
                printf("\n[%s] == [%s] = [%d]", parte1.c_str(), parte2.c_str(), parte1 == parte2);
                printf("\n[%s] == [%s] = [%d]\n", parte1.c_str(), parte1.c_str(), parte1 == parte1);

                printf("\nASCII: ");
                char x='a', y='3',z='\n';
                char u='\x7D', v='\176';
                printf("il carattere %c ha codice ASCII %d.\n",x,x);
                printf("il carattere %c ha codice ASCII %d.\n",y,y);
                printf("il carattere %c ha codice ASCII %d.\n",z,z);
                printf("il carattere %c ha codice ASCII %d.\n",u,u);
                printf("il carattere %c ha codice ASCII %d.\n",v,v);

                string cord1;
                printf("\nInserire coord: ");
                cin >> cord1;
                string delimiter = ",";
                int xTent = stoi(cord1.substr(0, cord1.find(delimiter))); // ritorna "x"
                int yTent = stoi(cord1.substr(cord1.find(delimiter) + 1, cord1.length())); // ritorna y
                printf("\n%d e %d", xTent, yTent);

                continua();
                break;
            }
            case 6:{

                printf("\nLavoro con i record...");

                int MAX_ALUNNI;

                printf("\nInserire il numero massimo di alunni: ");
                scanf("%d", &MAX_ALUNNI);

                struct s_data{
                    int giorno, mese, anno;
                };

                struct s_interrogazione{
                    char cognome[30];
                    char nome[20];
                    int classe;
                    char sezione;
                    double voto;
                    s_data dataVoto;
                };

                struct s_interrogazione verifica[MAX_ALUNNI];

                int i;
                for (i = 0; i < MAX_ALUNNI; i++) {

                    printf("\nInserire dati alunno numero %d...", i + 1);

                    printf("\nInserire cognome: ");
                    cin >> verifica[i].cognome;

                    printf("\nInserire nome: ");
                    cin >> verifica[i].nome;

                    printf("\nInserire classe: ");
                    cin >> verifica[i].classe;

                    printf("\nInserire sezione: ");
                    cin >> verifica[i].sezione;

                    printf("\nInserire data GG: ");
                    cin >> verifica[i].dataVoto.giorno;

                    printf("\nInserire data MM: ");
                    cin >> verifica[i].dataVoto.mese;

                    printf("\nInserire anno AA: ");
                    cin >> verifica[i].dataVoto.anno;

                    printf("\nInserire voto: ");
                    cin >> verifica[i].voto;
                }

                printf("\n\n \tCognome \tNOME \tClasse \t\tVoto\n");
                for (i = 0; i < MAX_ALUNNI; i++) {
                    cout << i + 1 << ": ";
                    cout << verifica[i].cognome;
                    cout << "\t" << verifica[i].nome;
                    cout << "\t" << verifica[i].classe << verifica[i].sezione;
                    cout << "\t\t" << verifica[i].dataVoto.giorno << "-";
                    cout << verifica[i].dataVoto.mese << "-" << verifica[i].dataVoto.anno;
                    cout << "\t\t" << verifica[i].voto;
                    cout << endl;
                }

                continua();
                break;
            }

            case 7:{

                int MAX_ALUNNI;

                printf("\nInserire il numero massimo di alunni: ");
                scanf("%d", &MAX_ALUNNI);

                struct s_voto{
                    int voto;
                };

                struct s_interrogazione{
                    char cognome[30];
                    char nome[20];
                    int classe;
                    char sezione;
                    s_voto voto[10];
                    int nVoti;
                };

                struct s_interrogazione verifica[MAX_ALUNNI];

                int i;
                for (i = 0; i < MAX_ALUNNI; i++) {

                    printf("\nInserire dati alunno numero %d...", i + 1);

                    printf("\nInserire cognome: ");
                    cin >> verifica[i].cognome;

                    printf("\nInserire nome: ");
                    cin >> verifica[i].nome;

                    printf("\nInserire classe: ");
                    cin >> verifica[i].classe;

                    printf("\nInserire sezione: ");
                    cin >> verifica[i].sezione;

                    printf("\nInserire voto: ");
                    cin >> verifica[i].voto[0].voto;

                    int nVoti = 1;

                    int vuoleInserireVoti = 1;

                    while (vuoleInserireVoti == 1) {
                        printf("\nVuoi inserire altri voti a questo alunno?"
                               "\n0 -> No."
                               "\n1 -> Si."
                               "\nScelta: ");
                        scanf("%d", &vuoleInserireVoti);

                        if (vuoleInserireVoti == 1){

                            printf("\nInserire voto: ");
                            cin >> verifica[i].voto[nVoti].voto;

                            nVoti++;
                        }
                    }
                    verifica[i].nVoti = nVoti;

                    if (i <= MAX_ALUNNI){

                        int sceltaFatta = 1;

                        while (sceltaFatta != 0) {
                            printf("\nScegli cosa fare:"
                                   "\n 0 -> Vedere info di tutti gli alunni e uscire."
                                   "\n 1 -> Inserire dati successivo alunno (non sempre disponibile)."
                                   "\n 2 -> Vedere info alunno in particolare."
                                   "\n 3 -> Modifica dato alunno."
                                   "\n 4 -> Info alunni inseriti fino adesso."
                                   "\nScelta: ");
                            scanf("%d", &sceltaFatta);

                            switch (sceltaFatta) {

                                case 0:{

                                    printf("\nHai scelto: Info alunni e uscita...");

                                    printf("\n\n \tCognome \tNOME \tClasse \t\tVoti \t\t\t\t\tMedia \n");
                                    for (int j = 0; j < i + 1; j++) {
                                        cout << j + 1 << ": ";
                                        cout << verifica[j].cognome;
                                        cout << "\t" << verifica[j].nome;
                                        cout << "\t" << verifica[j].classe << verifica[j].sezione;

                                        cout << "\t\t";

                                        int media = 0;

                                        for (int k = 0; k < verifica[j].nVoti; k++) {
                                            cout << "\t" << verifica[j].voto[k].voto;
                                            media += verifica[j].voto[k].voto;
                                        }

                                        media = media / verifica[j].nVoti;

                                        cout << "\t\tMedia: " << media;
                                        cout << endl;
                                    }

                                    i = MAX_ALUNNI;

                                    continua();
                                    break;
                                }

                                case 1:{

                                    if (i + 1 >= MAX_ALUNNI){

                                        printf("\nHai già inserito un numero pari al numero massimo di alunni.");

                                        continua();
                                    } else {

                                        sceltaFatta = 0;

                                    }

                                    break;
                                }

                                case 2:{

                                    printf("\nHai scelto: vedere info particolare alunno...");

                                    printf("\nScegliere un alunno nella lista:");

                                    for (int j = 0; j < i + 1; j++) {
                                        printf("\n%d -> %s", j, verifica[j].cognome);
                                    }

                                    int scelta;

                                    printf("\nScelta: ");
                                    scanf("%d", &scelta);

                                    if (scelta > i){
                                        printf("\nHai scelto un alunno non valido");
                                    } else {

                                        printf("\n\n \tCognome \tNOME \tClasse \t\tVoti \t\t\t\t\tMedia \n");

                                        cout << scelta + 1 << ": ";
                                        cout << verifica[scelta].cognome;
                                        cout << "\t" << verifica[scelta].nome;
                                        cout << "\t" << verifica[scelta].classe << verifica[scelta].sezione;

                                        cout << "\t\t";

                                        int media = 0;

                                        for (int j = 0; j < verifica[scelta].nVoti; j++) {
                                            cout << "\t" << verifica[scelta].voto[j].voto;
                                            media += verifica[scelta].voto[j].voto;
                                        }

                                        media = media / verifica[i].nVoti;

                                        cout << "\t\tMedia: " << media;
                                        cout << endl;
                                    }

                                    continua();
                                    break;
                                }

                                case 3:{

                                    printf("\nHai scelto: Modifica dati alunno...");


                                    printf("\nScegli che alunno modificare dalla lista: ");
                                    for (int j = 0; j < i + 1; j++) {
                                        printf("\n%d -> %s", j, verifica[j].cognome);
                                    }

                                    int scelta;

                                    printf("\nScelta: ");
                                    scanf("%d", &scelta);

                                    if (scelta > i){
                                        printf("\nHai scelto un alunno non valido!");
                                    } else {

                                        int sceltaModifica = 1;

                                        while (sceltaModifica != 0) {
                                            printf("\nScegli che dato modificare: "
                                                   "\n0 -> Esci."
                                                   "\n1 -> Cognome."
                                                   "\n2 -> Nome."
                                                   "\n3 -> Classe."
                                                   "\n4 -> Sezione."
                                                   "\n5 -> Voti."
                                                   "\nScelta: ");
                                        scanf("%d", &sceltaModifica);

                                            switch (sceltaModifica) {

                                                case 0:{

                                                    printf("\nHai scelto: esci");

                                                    continua();
                                                    break;
                                                }

                                                case 1:{

                                                    printf("\nHai scelto: modifica cognome...");

                                                    printf("\nInserire il nuovo cognome: ");
                                                    cin >> verifica[scelta].cognome;

                                                    printf("\nCognome modificato con successo!");

                                                    continua();
                                                    break;
                                                }

                                                case 2:{

                                                    printf("\nHai scelto: modifica nome...");

                                                    printf("\nInserire il nuovo nome: ");
                                                    cin >> verifica[scelta].nome;

                                                    printf("\nNome modificato con successo!");

                                                    continua();
                                                    break;
                                                }

                                                case 3:{

                                                    printf("\nHai scelto: modifica classe...");

                                                    printf("\nInserire nuova classe: ");
                                                    cin >> verifica[scelta].classe;

                                                    printf("\nClasse modificata con successo!");

                                                    continua();
                                                    break;
                                                }

                                                case 4:{

                                                    printf("\nHai scelto: modifica sezione...");

                                                    printf("\nInserire nuova sezione: ");
                                                    cin >> verifica[scelta].sezione;

                                                    printf("\nSezione modificata con successo!");

                                                    continua();
                                                    break;
                                                }

                                                case 5:{

                                                    printf("\nHai scelto: modifica voto");

                                                    int sceltaVoto;

                                                    printf("\nScegli un voto dalla lista: ");

                                                    for (int j = 0; j < verifica[scelta].nVoti; j++) {
                                                        printf("\n%d -> %d", j, verifica[scelta].voto[j].voto);
                                                    }

                                                    printf("\nScelta: ");
                                                    scanf("%d", &sceltaVoto);

                                                    if (sceltaVoto > verifica[scelta].nVoti){

                                                        printf("\nHai scelto un voto non valido!");

                                                    } else {

                                                        printf("\nInserisci nuovo voto: ");
                                                        cin >> verifica[scelta].voto[sceltaVoto].voto;

                                                        printf("\nVoto modificato con successo!");

                                                    }

                                                    continua();
                                                    break;
                                                }

                                                default:{

                                                    printf("\nScelta non valida!");

                                                    continua();
                                                    break;
                                                }
                                            }
                                        }
                                    }

                                    continua();
                                    break;
                                }

                                case 4:{

                                    printf("\nHai scelto: Info alunni inseriti fino adesso...");

                                    printf("\n\n \tCognome \tNOME \tClasse \tData \t\tVoti \t\t\t\t\tMedia \n");
                                    for (int j = 0; j < i + 1; j++) {
                                        cout << j + 1 << ": ";
                                        cout << verifica[j].cognome;
                                        cout << "\t" << verifica[j].nome;
                                        cout << "\t" << verifica[j].classe << verifica[j].sezione;

                                        cout << "\t\t";

                                        int media = 0;

                                        for (int k = 0; k < verifica[j].nVoti; k++) {
                                            cout << "\t" << verifica[j].voto[k].voto;
                                            media += verifica[j].voto[k].voto;
                                        }

                                        media = media / verifica[j].nVoti;

                                        cout << "\t\tMedia: " << media;
                                        cout << endl;
                                    }

                                    continua();
                                    break;
                                }

                                default:{

                                    printf("\nScelta non valida, per favore riprova.");

                                    continua();
                                    break;
                                }
                            }
                        }
                    }
                }

                printf("\nFine...");

                continua();
                break;
            }

            default:{

                // Selezione non valida, errore.
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

    string carta;

    if (numero == 11){

        carta = "Jack";

    } else if (numero == 12){

        carta = "Regina";

    } else if (numero == 13){

        carta = "Re";

    } else {

        carta = to_string(numero);

    }

    carta = carta + " di ";

    switch (tipo) {
        case 1:{

            carta = carta + "Fiori";

            break;
        }
        case 2:{

            carta = carta + RED "Quadri" RESET;

            break;
        }
        case 3:{

            carta = carta + RED "Cuori" RESET;

            break;
        }
        case 4:{

            carta = carta + "Picche";

            break;
        }
        default:{

            carta = carta + YELLOW "Sconosciuto" RESET;

            break;
        }
    }
    printf(CYAN "%s" RESET, carta.c_str());
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}
