#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void continua();

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//         Farfallino di Gabriele Caretti 3BITI            //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;

    while (scelta != 0){

        printf("\n\nLegenda:"
               "\n0 -> Esci."
               "\n1 -> Scrivi testo in farfallino."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Testo in farfallino...");

                string testo;
                printf("\nInserire testo da convertire in farfallino: ");
                cin.ignore();
                getline(cin, testo);

                printf("\n");

                char vocali[6] = {"aeiou"};
                char carattereFarfallino[2] = "f";
                int numeroVocali = 6;

                for (int i = 0; i < testo.size(); i++) {

                    bool carattereVocale = false;
                    for (int j = 0; j < numeroVocali; j++) {
                        if (testo[i] == vocali[j]){
                            carattereVocale = true;
                        }
                    }

                    if (carattereVocale){
                        printf("%c%c", testo[i], carattereFarfallino[0]);
                    } else {
                        printf("%c", testo[i]);
                    }

                }

                break;
            }

            default:{

                printf("\nScelta non valida, per favore riprovare!");

                break;
            }

        }

    }

    printf("\n\nUscito con successo!");
    return 0;
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}