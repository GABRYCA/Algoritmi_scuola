#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

void continua();
bool magazzinoEsiste();
bool logEsiste();
string sostituisciSpaziConTrattini(string stringa);
string sostituisciTrattiniConSpazi(string stringa);

struct prodottoMagazzino{
    char categoria[20];
    char nomeProdotto[20];
    double prezzo;
    int quantita;
};

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//          Magazzino di G.C. 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;

    struct prodottoMagazzino prodotto{};
    struct prodottoMagazzino vuoto{"", "", 0, 0};
    FILE *magazzino;
    FILE *log;

    while (scelta != 0){

        printf("\nLegenda:"
               "\n0 -> Esci dal programma."
               "\n1 -> Inizializza nuovo FILE o resetta intero magazzino."
               "\n2 -> Aggiungi prodotto."
               "\n3 -> Modifica prodotto con menu."
               "\n4 -> Elimina prodotto."
               "\n5 -> Leggi contenuto intero magazzino."
               "\n6 -> Leggi prodotto appartenenti a una categoria."
               "\n7 -> Vendita prodotto."
               "\n8 -> Imprevisto prodotto."
               "\n9 -> Leggi informazioni prodotto."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\n\nUscita in corso\n");

                break;
            }

            case 1:{

                printf("\nHai scelto: Inizializza o resetta magazzino...");

                if (magazzinoEsiste()){

                    int conferma;
                    printf("\nSei sicuro di voler resettare il magazzino?"
                           "\n0 -> Annulla."
                           "\nQualsiasi altro numero per confermare..."
                           "\nScelta: ");
                    scanf("%d", &conferma);

                    if (conferma == 0){

                        printf("\nOperazione annullata");

                    } else {

                        remove("magazzino.txt");

                        magazzino = fopen("magazzino.txt", "wb");
                        fclose(magazzino);

                        printf("\nMagazzino resettato con successo!");

                    }

                } else {

                    magazzino = fopen("magazzino.txt", "wb");
                    fclose(magazzino);

                    printf("\nMagazzino creato con successo!");

                }

                continua();
                break;
            }

            case 2:{

                printf("\nHai scelto: Aggiungi prodotto...\n");

                printf("\nInserire categoria prodotto: ");
                cin >> prodotto.categoria;

                printf("\nInserire nome prodotto: ");
                cin >> prodotto.nomeProdotto;

                printf("\nInserire prezzo prodotto: ");
                cin >> prodotto.prezzo;

                printf("\nInserire disponibilità': ");
                cin >> prodotto.quantita;

                bool scrittoPrima = false;
                if (magazzinoEsiste()){

                    magazzino = fopen("magazzino.txt", "rb");

                    int numeroRigaTrovato = 0;
                    int numeroRiga = 0;
                    struct prodottoMagazzino prodottoLetto{};
                    // Cerca e verifica se già presente.
                    while (!feof(magazzino)){
                        numeroRiga++;
                        fread(&prodottoLetto, sizeof(struct prodottoMagazzino), 1, magazzino);
                        if (prodotto.nomeProdotto == prodottoLetto.nomeProdotto){
                            prodotto.quantita += prodottoLetto.quantita;
                            numeroRigaTrovato = numeroRiga;
                        }
                    }
                    fclose(magazzino);

                    if (numeroRigaTrovato != 0){
                        scrittoPrima = true;
                        magazzino = fopen("magazzino.txt", "rb");
                        FILE *temp = fopen("temp.txt", "wb");

                        numeroRiga = 0;
                        while (!feof(magazzino)){
                            if (numeroRiga != 0){
                                fprintf(temp, "%s", "\n");
                            }
                            numeroRiga++;
                            fread(&prodottoLetto, sizeof(struct prodottoMagazzino), 1, magazzino);
                            if (numeroRiga != numeroRigaTrovato){
                                fwrite(&prodottoLetto, sizeof(struct prodottoMagazzino), 1, temp);
                            } else {
                                fwrite(&prodotto, sizeof(struct prodottoMagazzino), 1, temp);
                            }
                        }
                        fclose(magazzino);
                        fclose(temp);
                        remove("magazzino.txt");
                        rename("magazzino.txt", "temp.txt");
                    }

                    if (!scrittoPrima){

                        magazzino = fopen("magazzino.txt", "ab");

                        fprintf(magazzino, "%s", "\n");
                        fwrite(&prodotto, sizeof(struct prodottoMagazzino), 1, magazzino);
                        fclose(magazzino);
                    }

                } else {

                    magazzino = fopen("magazzino.txt", "wb");

                    fwrite(&prodotto, sizeof(struct prodottoMagazzino), 1, magazzino);
                    fclose(magazzino);
                }

                printf("\nProdotto aggiunto con successo!");

                continua();
                break;
            }

            default:{

                printf("\nScelta non valida, per favore riprovare!");

                break;
            }

        }

    }

    printf("\nUscito con successo!");

    return 0;
}

/**
 * Verifica se il FILE magazzino.txt esiste.
 * */
bool magazzinoEsiste(){

    FILE *magazzino = fopen("magazzino.txt", "r");

    if (magazzino != NULL){
        fclose(magazzino);
        return true;
    } else {
        fclose(magazzino);
        return false;
    }
}

/**
 * Verifica se il FILE modifiche.txt esiste.
 * */
bool logEsiste(){

    FILE *modifiche = fopen("modifiche.txt", "r");

    if (modifiche != NULL){
        fclose(modifiche);
        return true;
    } else {
        fclose(modifiche);
        return false;
    }
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\n|--------------------------"
           "\n| Inserisci un NUMERO a caso per continuare...");
    scanf("%d", &inusato);
    printf("|--------------------------\n");

}

string sostituisciSpaziConTrattini(string stringa){

    // Per ogni carattere della stringa verifica se è uno spazio e lo sostituisce.
    for (int i = 0; i < stringa.length(); i++) {
        if (isspace(stringa[i])){
            stringa[i] = '_';
        }
    }

    // Non supportato da vecchie versioni di C++
    /*(for(char & i : stringa) {
        if (isspace(i))
            i = '_';
    }*/

    // Ritorna nuova stringa.
    return stringa;
}

string sostituisciTrattiniConSpazi(string stringa){

    // Per ogni carattere della stringa verifica se è un un trattino basso e lo sostituisce.
    for (int i = 0; i < stringa.length(); i++) {
        if (stringa[i] == '_'){
            stringa[i] = ' ';
        }
    }

    // Non supportato da vecchie versioni di C++
    /*for(char & i : stringa) {
        if (i == '_')
            i = ' ';
    }*/

    // Ritorna nuova stringa.
    return stringa;
}