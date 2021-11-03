#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

struct dato{
    string contenuto = "null";
    int pos_suc = 0;
};

void pausa();

// Bisognerebbe usare una struct con almeno due valori, per esempio:
// - Contenuto.
// - Posizione_Intera_Successivo.

// Funzioni da fare:
// - Inserimento.
// - Rimozione.
// - Visualizzazione Fisica.
// - Visualizzazione Logica.
// - Ricerca Valore.
int main() {

    // Inizializzo vettore vuoto.
    dato vettore[20] = {"null", 0};

    // Inserisco i valori nel vettore.
    vettore[0] = {"Caretti", 1};
    vettore[1] = {"Cardillo", 2};
    vettore[2] = {"Castiglioni", 3};
    vettore[3] = {"Ferraro", 4};
    vettore[4] = {"Linzas", 5};
    vettore[5] = {"Martinetti", 6};
    vettore[6] = {"Moschella", 7};
    vettore[7] = {"Renella", 8};
    vettore[8] = {"Sinacori", 9};
    vettore[9] = {"Vellone", 10};

    printf("\nListe di G.C. 4BITI");

    int scelta;
    do {

        printf("\n\nOpzioni: "
               "\n0 -> Esci."
               "\n1 -> Inserisci (non pronto)."
               "\n2 -> Rimuovi (non pronto)."
               "\n3 -> Visualizzazione Fisica (Visualizza in ordine fisico)."
               "\n4 -> Visualizzazione Logica (Visualizza in ordine delle posizioni puntate)."
               "\n5 -> Cerca valore."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0:{

                printf("\nHai scelto... Esci."
                       "\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Inserimento...");

                break;
            }

            case 2:{

                printf("\nHai scelto: Rimozione...");

                break;
            }

            case 3:{

                printf("\nHai scelto: Visualizzazione fisica...");

                int posizioneLettura = 1;
                while (vettore[posizioneLettura].pos_suc != 0){
                    printf("\n\nPos. Fisica %d:"
                           "\n - Contenuto: %s."
                           "\n - Posizione puntata: %d.", posizioneLettura, vettore[posizioneLettura].contenuto.c_str(), vettore[posizioneLettura].pos_suc);
                    posizioneLettura++;
                }

                printf("\n\nVisualizzazione conclusa.");

                pausa();
                break;
            }

            case 4:{

                printf("\nHai scelto: Visualizzazione logica...");

                int posizioneLogica = 1;
                while (vettore[posizioneLogica].pos_suc != 0){
                    printf("\n\nPos. Logica %d:"
                           "\n - Contenuto: %s."
                           "\n - Posizione Puntata: %d", posizioneLogica, vettore[posizioneLogica].contenuto.c_str(), vettore[posizioneLogica].pos_suc);
                posizioneLogica = vettore[posizioneLogica].pos_suc;
                }

                printf("\n\nVisualizzazione conclusa.");

                pausa();
                break;
            }

            case 5:{

                printf("\nHai scelto: Ricerca...");

                string nomeDaCercare;
                printf("\n\nInserire il nome da cercare: ");
                cin >> nomeDaCercare;

                bool trovato = false;
                int posRicerca = 1;
                while (!trovato && vettore[posRicerca].pos_suc != 0){
                    if (vettore[posRicerca].contenuto == nomeDaCercare){
                        printf("\nIl nome %s e' stato trovato: "
                               "\n - Alla posizione %d."
                               "\n - Punta alla %d.", vettore[posRicerca].contenuto.c_str(), posRicerca, vettore[posRicerca].pos_suc);
                        trovato = true;
                    }
                    posRicerca = vettore[posRicerca].pos_suc;
                }

                if (!trovato){
                    printf("\nIl nome inserito non e' stato trovato (%s)!", nomeDaCercare.c_str());
                }

                pausa();
                break;
            }

            default:{

                printf("\nValore non valido, per favore riprovare");

                break;
            }
        }



    } while (scelta != 0);


    printf("\nUscito con successo!");
    return 0;
}

void pausa(){
    int numeroInutile;
    printf("\n\nInserire un numero per continuare: ");
    scanf("%d", &numeroInutile);
}
