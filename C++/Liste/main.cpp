#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

// Inizializzo struct.
struct dato{
    string contenuto;
    int pos_suc;
} vettore[20] = {
        {"Caretti", 1}, {"Cardillo", 2}, {"Castiglioni", 3}, {"Ferraro", 4}, {"Linzas", 5}, {"Martinetti", 6}, {"Moschella", 7}, {"Renella", 8}, {"Sinacori", 9}, {"Vellone", -1}};

void pausa();

// Parametri: Vettore struct, puntatore d'inizio.
void visFisica(dato *V);

// Parametri: Vettore struct, puntatore d'inizio.
void visLogica(dato *V, int pi);

// Parametri: Stringa da cercare, vettore struct, puntatore d'inizio.
bool presenteNomeConMessaggi(const string &nomeDaCercare, dato *V, int pi);

// Parametri: Valore da rimuovere stringa, vettore struct, puntatore d'inizio.
void rimuovi(const string &nomeDaCercare, dato *V, int pi);

// Parametri: vettore struct, puntatore d'inizio.
int posizioneVuota(dato *V);

// Parametri: Valore da inserire stringa, vettore struct, puntatore d'inizio.
void inserisci(string &daInserire, dato *V, int pi);

// Serve solamente per i cicli, il vettore non risulta dichiarabile tramite quest dimensione, da un errore.
int dimMaxVet = 20, posMinElemento = 0, valBandieraVuotoPuntato = -1, valBandieraEliminato = -2;

int main() {

    // Inserisco i valori nel vettore.
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

                if (posizioneVuota(vettore) == valBandieraVuotoPuntato){
                    printf("\nNessuno spazio libero rimasto!");
                    break;
                }

                string daInserire;
                printf("\n\nInserire il nome da inserire: ");
                cin >> daInserire;

                inserisci(daInserire, vettore, posMinElemento);

                pausa();
                break;
            }

            case 2:{

                printf("\nHai scelto: Rimozione...");
                string daCancellare;

                printf("\n\nInserire il nome da cancellare: ");
                cin >> daCancellare;

                // Verifica se presente, se la posizione e' diversa dal valore bandiera allora il valore e' stato trovato.
                rimuovi(daCancellare, vettore, posMinElemento);

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
                visLogica(vettore, posMinElemento);

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
                presenteNomeConMessaggi(nomeDaCercare, vettore, posMinElemento);

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

void inserisci(string &daInserire, dato *V, int pi){
    int vuoto = posizioneVuota(vettore);
    printf("\nSono qui!");

    if (vuoto == valBandieraVuotoPuntato){
        printf("\nNessuno spazio libero trovato!");
        return;
    }

    // Inserisco le primo spazio vuoto trovato il valore nuovo.
    V[vuoto].contenuto = daInserire;

    // Verifico subito se l'elemento da inserire e' minore del primo.
    if (daInserire < V[pi].contenuto){
        // Inserisco l'elemento nel primo spazio libero e aggiorno la posizione dell'elemento piu' piccolo
        // A quella nuova (essendo quello inserito il nuovo minore e primo).
        // Poi questo nuovo minore appena inserito puntera' a quello che prima era il minore.

        V[vuoto].pos_suc = pi;
        posMinElemento = vuoto;
    } else {

        // Dichiaro la variabile temporanea logica da cui iniziare a leggere i valori, e quella a cui punterà l'elemento
        // da inserire con il valore bandiera nullo, che se nel ciclo viene modificata, allora sarà diversa dal valore nullo.
        int posizioneLogica = pi, posizioneElementoPrecedente, posElementoDaPuntare = valBandieraVuotoPuntato;
        // Eseguo il ciclo per ogni valore logico disponibili oppure fino a quando non raggiungo uno maggiore di quello
        // da inserire. Tramite questo ciclo ottengo la posizione a cui deve puntare l'elemento inserito e chi punta a lui.
        // Verifico anche il caso speciale in cui sia l'ultimo elemento, semplicemente senza trovare l'elemento da puntare
        // E quindi lasciando quello bandiera nullo, mentre quello che punta al valore inserito sara' sempre disponibile
        // dal momento che la condizione particolare del primo elemento minore e' gia' stata verificata prima.
        while (posizioneLogica != valBandieraVuotoPuntato){
            if (V[posizioneLogica].contenuto > daInserire){
                posElementoDaPuntare = posizioneLogica;
                break;
            } else {
                posizioneElementoPrecedente = posizioneLogica;
            }
            posizioneLogica = V[posizioneLogica].pos_suc;
        }
        V[posizioneElementoPrecedente].pos_suc = vuoto;
        V[vuoto].pos_suc = posElementoDaPuntare;
    }

    // Messaggio di successo.
    printf("\nValore nuovo %s inserito nella posizione %d:"
           "\nContenuto: %s."
           "\nPunta a: %d", daInserire.c_str(), vuoto, V[vuoto].contenuto.c_str(), V[vuoto].pos_suc);
}

bool presenteNomeConMessaggi(const string &nomeDaCercare, dato *V, int pi){
    int posizioneLogica = pi;
    while (posizioneLogica != valBandieraVuotoPuntato){
        if (V[posizioneLogica].contenuto == nomeDaCercare){
            printf("\n\nNome trovato! Posizione Logica %d:"
                   "\n - Contenuto: %s."
                   "\n - Posizione Puntata: %d", posizioneLogica, V[posizioneLogica].contenuto.c_str(),
                   V[posizioneLogica].pos_suc);
            return true;
        }
        posizioneLogica = V[posizioneLogica].pos_suc;
    }

    printf("\nIl nome inserito non e' stato trovato (%s)!", nomeDaCercare.c_str());
    return false;
}

// Questo e' modificabile in modo da fare un singolo ciclo e trovare il valore precedente da modificare e l'attuale.
// puc = p
// p = V[p].succ
void rimuovi(const string &nomeDaCercare, dato *V, int pi){
    int posizioneLogica = pi;

    // Verifico se il nome da modificare coincide con quello presente alla prima posizione, e in caso affermativo
    // Vado a modificare la posizione del valore minimo presente (il primo letto nella lettura logica) con quello a cui
    // puntava il valore che sta venendo rimosso.
    if (V[posizioneLogica].contenuto == nomeDaCercare){
        //V[posizioneLogica].contenuto = stringaBandieraVuoto;
        if (V[posizioneLogica].pos_suc != valBandieraVuotoPuntato) {
            posMinElemento = V[posizioneLogica].pos_suc;
        } else {
            // Resetto posizione iniziale, alla prima in cui si trovera' il primo valore aggiunto in futuro (primo spazio vuoto).
            posMinElemento = 0;
        }
        V[posizioneLogica].pos_suc = valBandieraEliminato;
        printf("\n%s rimosso con successo!", nomeDaCercare.c_str());
        return;
    }

    while (V[posizioneLogica].pos_suc != valBandieraVuotoPuntato){

        // In condizioni normali, eseguo una lettura tramite posizione logica dal primo elemento fino a quando:
        // a) Trovo il valore precedente a quello da eliminare ed eseguo le opportune modifiche ai puntatori.
        // b) Non trovo il valore precedente a quello da eliminare (posizione successiva = -1) e quindi comunico l'errore.

        // Valore stringa del valore successivo, ho controllato prima che non sia nullo.
        string valoreSuccessivo = V[V[posizioneLogica].pos_suc].contenuto;

        // Confronto valore stringa successivo con quello da cercare.
        if (valoreSuccessivo == nomeDaCercare){
            // Memorizzo il valore della posizione del nome da rimuovere, perche' nel passaggio successivo sara' modificato.
            int posizioneNomeSuccessivo = V[posizioneLogica].pos_suc;
            // Valore trovato, ora setto la posizione del puntatore precedente a quella a cui puntava il valore da rimuovere.
            V[posizioneLogica].pos_suc = V[posizioneNomeSuccessivo].pos_suc;
            // E setto ai valori di default vuoti il valore da rimuovere.
            V[posizioneNomeSuccessivo].pos_suc = valBandieraEliminato;
            //V[posizioneNomeSuccessivo].contenuto = valBandieraEliminato;
            printf("\n%s rimosso con successo!", nomeDaCercare.c_str());
            return;
        }
        posizioneLogica = V[posizioneLogica].pos_suc;
    }
    // Valore non trovato.
    printf("\n%s non trovato!", nomeDaCercare.c_str());
}

int posizioneVuota(dato *V) {
    int posRicerca = 0;
    while (posRicerca < dimMaxVet){
        if (V[posRicerca].contenuto.empty() || V[posRicerca].pos_suc == valBandieraEliminato){
            return posRicerca;
        }
        posRicerca++;
    }
    return valBandieraVuotoPuntato;
}

void visLogica(dato *V, int pi){
    int posizioneLogica = pi;

    while (posizioneLogica != valBandieraVuotoPuntato){
        printf("\n\nPos. Logica %d:"
               "\n - Contenuto: %s."
               "\n - Posizione Puntata: %d", posizioneLogica, V[posizioneLogica].contenuto.c_str(),
               V[posizioneLogica].pos_suc);
        posizioneLogica = V[posizioneLogica].pos_suc;
    }
}

void visFisica(dato *V) {
    int posizioneLettura = 0;
    while (posizioneLettura < dimMaxVet){
        if (V[posizioneLettura].contenuto != "null" && !V[posizioneLettura].contenuto.empty()) {
            printf("\n\nPos. Fisica %d:"
                   "\n - Contenuto: %s."
                   "\n - Posizione puntata: %d.", posizioneLettura, V[posizioneLettura].contenuto.c_str(),
                   V[posizioneLettura].pos_suc);
        }
        posizioneLettura++;
    }
}

void pausa(){
    int numeroInutile;
    printf("\n\nInserire un numero per continuare: ");
    scanf("%d", &numeroInutile);
}
