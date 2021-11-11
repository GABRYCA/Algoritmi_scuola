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

void visFisica();

void visLogica();

bool presenteNomeConMessaggi(const string &nomeDaCercare);

void rimuovi(const string &nomeDaCercare);

int posizioneVuota();

bool stringaAMinDiB(string A, string B);

bool stringaAMagDiB(string A, string B);

// Trovare il numero corrispondente alla lettera dell'alfabeto.
int valoreInAlfabeto(string lettera);

void inserisci(string &daInserire);

// Serve solamente per i cicli, il vettore non risulta dichiarabile tramite quest dimensione, da un errore.
int dimMaxVet = 20, posMinElemento = 0, valBandieraVuoto = -1;
string stringaBandieraVuoto = "null";

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

                if (posizioneVuota() == -1){
                    printf("\nNessuno spazio libero rimasto!");
                    break;
                }

                string daInserire;
                printf("\n\nInserire il nome da inserire: ");
                cin >> daInserire;

                inserisci(daInserire);

                pausa();
                break;
            }

            case 2:{

                printf("\nHai scelto: Rimozione...");
                string daCancellare;

                printf("\n\nInserire il nome da cancellare: ");
                cin >> daCancellare;

                // Verifica se presente, se la posizione e' diversa dal valore bandiera allora il valore e' stato trovato.
                rimuovi(daCancellare);

                pausa();
                break;
            }

            case 3:{

                // Messaggio di benvenuto.
                printf("\nHai scelto: Visualizzazione fisica...");

                // Richiamo funzione per la visualizzazione fisica.
                visFisica();

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
                visLogica();

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
                presenteNomeConMessaggi(nomeDaCercare);

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

void inserisci(string &daInserire) {
    int vuoto = posizioneVuota();

    if (vuoto == valBandieraVuoto){
        printf("\nNessuno spazio libero trovato!");
        return;
    }

    // Inserisco le primo spazio vuoto trovato il valore nuovo.
    vettore[vuoto].contenuto = daInserire;

    // Verifico subito se l'elemento da inserire e' minore del primo.
    if (daInserire < vettore[posMinElemento].contenuto){
        // Inserisco l'elemento nel primo spazio libero e aggiorno la posizione dell'elemento piu' piccolo
        // A quella nuova (essendo quello inserito il nuovo minore e primo).
        // Poi questo nuovo minore appena inserito puntera' a quello che prima era il minore.

        vettore[vuoto].pos_suc = posMinElemento;
        posMinElemento = vuoto;
    } else {

        int posizioneLogica = posMinElemento, posizioneElementoPrecedente, posElementoDaPuntare = valBandieraVuoto;
        while (posizioneLogica != valBandieraVuoto){
            if (vettore[posizioneLogica].contenuto > daInserire){
                posElementoDaPuntare = posizioneLogica;
                break;
            } else {
                posizioneElementoPrecedente = posizioneLogica;
            }
            posizioneLogica = vettore[posizioneLogica].pos_suc;
        }
        vettore[posizioneElementoPrecedente].pos_suc = vuoto;
        vettore[vuoto].pos_suc = posElementoDaPuntare;
    }

    printf("\nValore nuovo %s inserito nella posizione %d:"
           "\nContenuto: %s."
           "\nPunta a: %d", daInserire.c_str(), vuoto, vettore[vuoto].contenuto.c_str(), vettore[vuoto].pos_suc);
}

bool presenteNomeConMessaggi(const string &nomeDaCercare) {
    int posizioneLogica = posMinElemento;
    while (posizioneLogica != valBandieraVuoto){
        if (vettore[posizioneLogica].contenuto == nomeDaCercare){
            printf("\n\nNome trovato! Posizione Logica %d:"
                   "\n - Contenuto: %s."
                   "\n - Posizione Puntata: %d", posizioneLogica, vettore[posizioneLogica].contenuto.c_str(),
                   vettore[posizioneLogica].pos_suc);
            return true;
        }
        posizioneLogica = vettore[posizioneLogica].pos_suc;
    }

    printf("\nIl nome inserito non e' stato trovato (%s)!", nomeDaCercare.c_str());
    return false;
}

// Questo e' modificabile in modo da fare un singolo ciclo e trovare il valore precedente da modificare e l'attuale.
// puc = p
// p = V[p].succ
void rimuovi(const string &nomeDaCercare){
    int posizioneLogica = posMinElemento;

    // Verifico se il nome da modificare coincide con quello presente alla prima posizione, e in caso affermativo
    // Vado a modificare la posizione del valore minimo presente (il primo letto nella lettura logica) con quello a cui
    // puntava il valore che sta venendo rimosso.
    if (vettore[posizioneLogica].contenuto == nomeDaCercare){
        vettore[posizioneLogica].contenuto = stringaBandieraVuoto;
        if (vettore[posizioneLogica].pos_suc != valBandieraVuoto) {
            posMinElemento = vettore[posizioneLogica].pos_suc;
        } else {
            // Resetto posizione iniziale, alla prima in cui si trovera' il primo valore aggiunto in futuro (primo spazio vuoto).
            posMinElemento = 0;
        }
        vettore[posizioneLogica].pos_suc = valBandieraVuoto;
        printf("\n%s rimosso con successo!", nomeDaCercare.c_str());
        return;
    }

    while (vettore[posizioneLogica].pos_suc != valBandieraVuoto){

        // In condizioni normali, eseguo una lettura tramite posizione logica dal primo elemento fino a quando:
        // a) Trovo il valore precedente a quello da eliminare ed eseguo le opportune modifiche ai puntatori.
        // b) Non trovo il valore precedente a quello da eliminare (posizione successiva = -1) e quindi comunico l'errore.

        // Valore stringa del valore successivo, ho controllato prima che non sia nullo.
        string valoreSuccessivo = vettore[vettore[posizioneLogica].pos_suc].contenuto;

        // Confronto valore stringa successivo con quello da cercare.
        if (valoreSuccessivo == nomeDaCercare){
            // Memorizzo il valore della posizione del nome da rimuovere, perche' nel passaggio successivo sara' modificato.
            int posizioneNomeSuccessivo = vettore[posizioneLogica].pos_suc;
            // Valore trovato, ora setto la posizione del puntatore precedente a quella a cui puntava il valore da rimuovere.
            vettore[posizioneLogica].pos_suc = vettore[posizioneNomeSuccessivo].pos_suc;
            // E setto ai valori di default vuoti il valore da rimuovere.
            vettore[posizioneNomeSuccessivo].pos_suc = valBandieraVuoto;
            vettore[posizioneNomeSuccessivo].contenuto = stringaBandieraVuoto;
            printf("\n%s rimosso con successo!", nomeDaCercare.c_str());
            return;
        }
        posizioneLogica = vettore[posizioneLogica].pos_suc;
    }
    // Valore non trovato.
    printf("\n%s non trovato!", nomeDaCercare.c_str());
}

int posizioneVuota(){
    int posRicerca = 0;
    while (posRicerca < dimMaxVet){
        if (vettore[posRicerca].contenuto == "null" || vettore[posRicerca].contenuto.empty()){
            return posRicerca;
        }
        posRicerca++;
    }
    return valBandieraVuoto;
}

void visLogica() {
    int posizioneLogica = posMinElemento;

    while (posizioneLogica != valBandieraVuoto){
        printf("\n\nPos. Logica %d:"
               "\n - Contenuto: %s."
               "\n - Posizione Puntata: %d", posizioneLogica, vettore[posizioneLogica].contenuto.c_str(),
               vettore[posizioneLogica].pos_suc);
        posizioneLogica = vettore[posizioneLogica].pos_suc;
    }
}

void visFisica() {
    int posizioneLettura = 0;
    while (posizioneLettura < dimMaxVet){
        if (vettore[posizioneLettura].contenuto != "null" && !vettore[posizioneLettura].contenuto.empty()) {
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
