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

void visFisica(const dato *vettore);

void visLogica(const dato *vettore);

bool presenteNomeConMessaggi(const dato *vettore, const string &nomeDaCercare);

int posizioneNome(const dato *vettore, const string &nomeDaCercare);

int posizioneVuota(const dato *vettore);

bool stringaAMinDiB(string A, string B);

bool stringaAMagDiB(string A, string B);

// Trovare il numero corrispondente alla lettera dell'alfabeto.
int valoreInAlfabeto(string lettera);

// Serve solamente per i cicli, il vettore non risulta dichiarabile tramite quest dimensione, da un errore.
int dimMaxVet = 20, posMinElemento = 0, valBandieraVuoto = -1;
string stringaBandieraVuoto = "null";

//TODO
// Finire analisi sul file .docx.
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
    vettore[9] = {"Vellone", valBandieraVuoto};

    printf("\nListe di G.C. 4BITI");

    int scelta;
    do {

        printf("\n\nOpzioni: "
               "\n0 -> Esci."
               "\n1 -> Inserisci."
               "\n2 -> Rimuovi."
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

                if (stringaAMinDiB(daInserire, vettore[posMinElemento].contenuto)){
                    // Inserisco l'elemento nel primo spazio libero e aggiorno la posizione dell'elemento piu' piccolo
                    // A quella nuova (essendo quello inserito il nuovo minore e primo).
                    // Poi questo nuovo minore appena inserito puntera' a quello che prima era il minore.
                    vettore[vuoto].contenuto = daInserire;
                    vettore[vuoto].pos_suc = posMinElemento;
                    posMinElemento = vuoto;
                } else {
                    // Questo invece e' un po' piu' complicato.
                    // Verifico subito una situazione di criticita', ossia quando l'elemento da inserire e' piu' grande
                    // Dell'ultimo elemento, quindi vado a cercarlo.
                    int posizioneLogica = posMinElemento;
                    int posizioneVecchioMaggiore = posizioneLogica;
                    do {
                        if (posizioneLogica != -1){
                            posizioneLogica = vettore[posizioneLogica].pos_suc;
                            if (posizioneLogica != -1){
                                posizioneVecchioMaggiore = posizioneLogica;
                            }
                        }
                    } while (posizioneLogica != valBandieraVuoto && vettore[posizioneLogica].contenuto != "null");

                    if (stringaAMagDiB(daInserire, vettore[posizioneLogica].contenuto)){
                        // Faccio puntare all'ultimo elemento il nuovo inserito ultimo, e inserisco il nuovo ultimo valore
                        // nello spazio vuoto trovato prima, e lo faccio puntare al valore bandiera nullo dal momento che
                        // dopo di lui non ci saranno altri valori (e' il maggiore).
                        vettore[posizioneVecchioMaggiore].pos_suc = vuoto;
                        printf("\nIl vecchio maggiore alla pos %d punta a: %d", posizioneVecchioMaggiore, vuoto);
                        vettore[vuoto].contenuto = daInserire;
                        vettore[vuoto].pos_suc = valBandieraVuoto;
                    } else {
                        // Condizioni normali d'inserimento, ossia cerco chi dovra' puntare al valore appena inserito
                        // (Ossia il suo precedente) e a chi dovra' puntare quello appena inserito (il suo successivo).
                        // Non mi devo preoccupare di criticita' dal momento che sono state verificate in precedenza.
                        posizioneLogica = posMinElemento;
                        int posPrecDaPuntareANuovo;
                        int daPuntare;
                        bool trovatoDaPuntare = false;
                        do {
                            if (posizioneLogica != valBandieraVuoto && vettore[posizioneLogica].contenuto != "null"){
                                if (stringaAMinDiB(vettore[posizioneLogica].contenuto, daInserire)){
                                    posPrecDaPuntareANuovo = posizioneLogica;
                                } else {
                                    if (!trovatoDaPuntare){
                                        daPuntare = posizioneLogica;
                                        trovatoDaPuntare = true;
                                    }
                                }
                                posizioneLogica = vettore[posizioneLogica].pos_suc;
                            }
                        } while (posizioneLogica != valBandieraVuoto && vettore[posizioneLogica].contenuto != "null");

                        vettore[vuoto].contenuto = daInserire;
                        vettore[vuoto].pos_suc = daPuntare;
                        vettore[posPrecDaPuntareANuovo].pos_suc = vuoto;
                    }
                }

                printf("\nValore nuovo %s inserito nella posizione %d:"
                       "\nContenuto: %s."
                       "\nPunta a: %d", daInserire.c_str(), vuoto, vettore[vuoto].contenuto.c_str(), vettore[vuoto].pos_suc);
                pausa();
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

                // Messaggio di benvenuto.
                printf("\nHai scelto: Visualizzazione fisica...");

                // Richiamo funzione per la visualizzazione fisica.
                visFisica(vettore);

                // Messaggio di fine.
                printf("\n\nVisualizzazione conclusa.");

                // Pausa e fine.
                pausa();
                break;
            }

            case 4:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Visualizzazione logica...");

                // Richiamo funzione visualizzazione logica.
                visLogica(vettore);

                // Messaggio di fine.
                printf("\n\nVisualizzazione conclusa.");

                // Pausa e fine.
                pausa();
                break;
            }

            case 5:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Ricerca...");

                // Chiedo input all'utente.
                string nomeDaCercare;
                printf("\n\nInserire il nome da cercare: ");
                cin >> nomeDaCercare;

                // Richiamo funzione ricderca.
                presenteNomeConMessaggi(vettore, nomeDaCercare);

                // Pausa e fine.
                pausa();
                break;
            }

            default:{

                // Messaggio d'errore.
                printf("\nValore non valido, per favore riprovare");

                break;
            }
        }



    } while (scelta != 0);

    // Fine messaggio.
    printf("\nUscito con successo!");
    return 0;
}

bool presenteNomeConMessaggi(const dato *vettore, const string &nomeDaCercare) {
    int posizioneLogica = posMinElemento;
    do {
        if (posizioneLogica != valBandieraVuoto && vettore[posizioneLogica].contenuto != "null") {
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
        if (posizioneLogica != valBandieraVuoto && vettore[posizioneLogica].contenuto != "null") {
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
        if (posizioneLogica != valBandieraVuoto && vettore[posizioneLogica].contenuto != "null") {
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

// Ritorna vero se A e' minore di B.
bool stringaAMinDiB(string A, string B){
    int i = 0;
    while (A[i] == B[i] && A.length() < i && B.length() < i){
        i++;
        if (A.length() < i){
            return true;
        }
        if (B.length() < i){
            return false;
        }
    }
    if (valoreInAlfabeto(A) < valoreInAlfabeto(B)){
        return true;
    }
    return false;
}

// Ritorna vero se A e' maggiore di B.
bool stringaAMagDiB(string A, string B){
    int i = 0;
    while (A[i] == B[i] && A.length() < i && B.length() < i){
        i++;
        if (A.length() < i){
            return false;
        }
        if (B.length() < i){
            return true;
        }
    }
    if (valoreInAlfabeto(A) > valoreInAlfabeto(B)){
        return true;
    }
    return false;
}

void pausa(){
    int numeroInutile;
    printf("\n\nInserire un numero per continuare: ");
    scanf("%d", &numeroInutile);
}
