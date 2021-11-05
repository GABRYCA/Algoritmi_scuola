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

void visFisica(const dato *vettore);

void visLogica(const dato *vettore);

bool presenteNomeConMessaggi(const dato *vettore, const string &nomeDaCercare);

int posizioneNome(const dato *vettore, const string &nomeDaCercare);

int posizioneVuota(const dato *vettore);

int posizionePrecedenteANome(const dato *vettore, string nome);

int posizioneSuccessivoANome(const dato *vettore, string nome);

// Trovare il numero corrispondente alla lettera dell'alfabeto.
int valoreInAlfabeto(string lettera);

// Serve solamente per i cicli, il vettore non risulta dichiarabile tramite quest dimensione, da un errore.
int dimMaxVet = 20, posMinElemento = 0, valBandieraVuoto = -1;
string stringaBandieraVuoto = "null";

// Funzioni da fare:
// - Inserimento.
// - Rimozione.
// - Visualizzazione Fisica.
// - Visualizzazione Logica.
// - Ricerca Valore.
int main() {

    // Inizializzo vettore vuoto.
    dato vettore[20] = {stringaBandieraVuoto, valBandieraVuoto};

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
    vettore[9] = {"Vellone", -1};

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

                if (posizioneVuota(vettore) == -1){
                    printf("\nNessuno spazio libero rimasto!");
                    break;
                }

                string daInserire;
                printf("\n\nInserire il nome da inserire: ");
                cin >> daInserire;

                int vuoto = posizioneVuota(vettore);
                vettore[vuoto].contenuto = daInserire;

                // Stabilire posizione a cui punta, ossia elemento che in ordine alfabetico viene dopo.
                // Se niente e' disponibile (e' il più grande), allora punta a -1.
                //vettore[vuoto].pos_suc = "daStabilire";

                // Oppure trovare chi puntava all'elemento successivo a quello da inserire, e quindi far puntare
                // a questo appena inserito a quello successivo, e quello che puntava al suo successivo sara' il
                // precedente che ora puntera' al nuovo elemento inserito.

                break;
            }

            case 2:{

                printf("\nHai scelto: Rimozione...");
                string daCancellare;

                printf("\n\nInserire il nome da cancellare: ");
                cin >> daCancellare;

                // Verifica se presente, se la posizione e' diversa dal valore bandiera allora il valore e' stato trovato.
                int posNome = posizioneNome(vettore, daCancellare);
                if (posNome == valBandieraVuoto){
                    printf("\nNome non trovato!");
                    pausa();
                    break;
                }

                // Setta al valore nullo la casella con il valore cancellato e ottiene la posizione a cui puntava per il
                // prossimo passaggio.
                int daPuntare = vettore[posNome].pos_suc;
                vettore[posNome].contenuto = "null";
                vettore[posNome].pos_suc = valBandieraVuoto;

                // Verifica se la posizione in cui si trovava il nome rimosso era la prima, e nel caso aggiorna
                // la variabile della variabile a cui puntava con lui perche' ora diventa la prima.
                if (posNome == posMinElemento){
                    posMinElemento = daPuntare;
                    printf("\nRimosso con successo il nome %s", daCancellare.c_str());
                    pausa();
                    break;
                }

                // Trovare chi punta a posNome, che dovrà ora puntare a "daPuntare".
                int daModificare = 0;
                while (daModificare < dimMaxVet){
                    if (vettore[daModificare].pos_suc == posNome){
                        vettore[daModificare].pos_suc = daPuntare;
                        break;
                    }
                    daModificare++;
                }

                printf("\nRimosso con successo il nome %s", daCancellare.c_str());
                pausa();
                break;
            }

            case 3:{

                printf("\nHai scelto: Visualizzazione fisica...");

                visFisica(vettore);

                printf("\n\nVisualizzazione conclusa.");

                pausa();
                break;
            }

            case 4:{

                printf("\nHai scelto: Visualizzazione logica...");

                visLogica(vettore);

                printf("\n\nVisualizzazione conclusa.");

                pausa();
                break;
            }

            case 5:{

                printf("\nHai scelto: Ricerca...");

                string nomeDaCercare;
                printf("\n\nInserire il nome da cercare: ");
                cin >> nomeDaCercare;

                presenteNomeConMessaggi(vettore, nomeDaCercare);

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

bool presenteNomeConMessaggi(const dato *vettore, const string &nomeDaCercare) {
    int posizioneLogica = posMinElemento;
    do {
        if (posizioneLogica != -1 && vettore[posizioneLogica].contenuto != "null") {
            if (vettore[posizioneLogica].contenuto == nomeDaCercare){
            printf("\n\nNome trovato! Posizione Logica %d:"
                   "\n - Contenuto: %s."
                   "\n - Posizione Puntata: %d", posizioneLogica, vettore[posizioneLogica].contenuto.c_str(),
                   vettore[posizioneLogica].pos_suc);
                return true;
            }
            posizioneLogica = vettore[posizioneLogica].pos_suc;
        }
    } while (posizioneLogica != valBandieraVuoto && vettore[posizioneLogica].contenuto != "null");

    printf("\nIl nome inserito non e' stato trovato (%s)!", nomeDaCercare.c_str());
    return false;
}

int posizioneNome(const dato *vettore, const string &nomeDaCercare){
    int posizioneLogica = posMinElemento;
    do {
        if (posizioneLogica != -1 && vettore[posizioneLogica].contenuto != "null") {
            if (vettore[posizioneLogica].contenuto == nomeDaCercare){
                return posizioneLogica;
            }
            posizioneLogica = vettore[posizioneLogica].pos_suc;
        }
    } while (posizioneLogica != valBandieraVuoto && vettore[posizioneLogica].contenuto != "null");
    return valBandieraVuoto;
}

int posizioneVuota(const dato *vettore){
    int posRicerca = 0;
    while (posRicerca < dimMaxVet){
        if (vettore[posRicerca].contenuto == "null"){
            return posRicerca;
        }
        posRicerca++;
    }
    return valBandieraVuoto;
}

void visLogica(const dato *vettore) {
    int posizioneLogica = posMinElemento;
    do {
        if (posizioneLogica != -1 && vettore[posizioneLogica].contenuto != "null") {
            printf("\n\nPos. Logica %d:"
                   "\n - Contenuto: %s."
                   "\n - Posizione Puntata: %d", posizioneLogica, vettore[posizioneLogica].contenuto.c_str(),
                   vettore[posizioneLogica].pos_suc);
            posizioneLogica = vettore[posizioneLogica].pos_suc;
        }
    } while (posizioneLogica != valBandieraVuoto && vettore[posizioneLogica].contenuto != "null");
}

void visFisica(const dato *vettore) {
    int posizioneLettura = 0;
    while (posizioneLettura < dimMaxVet){
        if (vettore[posizioneLettura].contenuto != "null") {
            printf("\n\nPos. Fisica %d:"
                   "\n - Contenuto: %s."
                   "\n - Posizione puntata: %d.", posizioneLettura, vettore[posizioneLettura].contenuto.c_str(),
                   vettore[posizioneLettura].pos_suc);
        }
        posizioneLettura++;
    }
}

int valoreInAlfabeto(string lettera){
    lettera[0] = toupper(lettera[0]);
    string vett[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    for (int i = 0; i < 26; i++) {
        if (vett[i][0] == lettera[0]){
            return i;
        }
    }
    return valBandieraVuoto;
}

int posizionePrecedenteANome(const dato *vettore, string nome){
    int conta = 0;
    while (conta < dimMaxVet){



        conta++;
    }
    return -1;
}

int posizioneSuccessivoANome(const dato *vettore, string nome){
    int conta = 0;
    while (conta < dimMaxVet){



        conta++;
    }
    return -1;
}

void pausa(){
    int numeroInutile;
    printf("\n\nInserire un numero per continuare: ");
    scanf("%d", &numeroInutile);
}
