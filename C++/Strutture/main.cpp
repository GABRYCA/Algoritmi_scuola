#include <iostream>
#include <cstdio>

using namespace std;

void continua();

void introduzioneStrutture();
void alunni();

int main() {

    // Valore bandiera, se diverso da 1 allora finisce il gioco.
    int sceltaMemory = 1;

    // Messaggio del creatore
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//            Esercizi di Gabriele Caretti 3BITI              //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Fintanto che la scelta è diversa da 0 (esci) allora andrà avanti.
    while (sceltaMemory != 0) {

        // Legenda e input utente
        printf("\nLegenda Memory: "
               "\n 0 -> Chiudi."
               "\n 1 -> Esercizio con i record."
               "\n 2 -> Esercizio alunni.""\nScelta: ");
        scanf("%d", &sceltaMemory);

        // Switch tra le scelte del menu.
        switch (sceltaMemory) {

            case 0:{

                printf("\nHai scelto: chiudi...\n");

                break;
            }

            case 1:{

                printf("\nLavoro con i record...");

                introduzioneStrutture();

                continua();
                break;
            }

            case 2:{

                printf("\nHai scelto: Alunni...");

                alunni();

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

void alunni() {
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

    // Inserimento dati.
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

        // Opzioni.
        if (i <= MAX_ALUNNI){

            // Legenda e altro menu.
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
}

void introduzioneStrutture() {
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
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}