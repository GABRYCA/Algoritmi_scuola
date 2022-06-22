#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

void estraiParole(const string &input, list<string> &paroleInput);

void letturaDizionario(list<string> &paroleDizionario);

int main() {
    printf("/////////////////////"
           "\nLavoro di G.C. 4BITI"
           "\n/////////////////////\n");

    // Caricamento vettore dizionario italiano da file.
    list<string> paroleDizionario;
    letturaDizionario(paroleDizionario);

    // Input utente.
    printf("\n\nInserire frase da cui trovare anagrammi:");
    printf("\nFrase: ");

    string input;
    cin.clear();
    getline(cin, input);

    // Divido la frase in singole parole.
    list<string> paroleInput;
    estraiParole(input, paroleInput);

    // La mia soluzione per trovare gli anagrammi di una parola è ordinare i caratteri di entrambi e confrontarli.
    // Se questi sono uguali, allora sono anagrammi.
    // Se si ordinavano prima le parole e l'intero dizionario, la complessità sarebbe lineare O(N) al massimo O(2N) data l'inizializzazione.
    // In questo caso è maggiore dal momento che ad ogni ciclo ci deve ordinare la parola stessa e quella del dizionario.
    // Quindi O(N^2).

    clock_t inizio = clock();

    // Per ogni parola in input.
    for (string parola: paroleInput) {

        string temp = parola;
        paroleDizionario.begin();

        // Ordino caratteri parola input.
        sort(temp.begin(), temp.end());

        // Per ogni parola del dizionario.
        int contatoreAnagrammi = 0;
        for (string parolaDizionario: paroleDizionario) {

            if (!(parola == parolaDizionario)) { // Evito di stampare come anagramma la parola stessa

                string tempDizionario = parolaDizionario;

                sort(tempDizionario.begin(), tempDizionario.end());

                if (tempDizionario == temp) {
                    printf("\nAnagramma [%s] -> [%s]", parola.c_str(), parolaDizionario.c_str());
                    contatoreAnagrammi++;
                }
            }
        }

        if (contatoreAnagrammi == 0){
            printf("\nNon sono stati trovati anagrammi della parola [%s].", parola.c_str());
        }

    }

    clock_t fine = clock();

    double tempoEsecuzione = (fine - inizio)/(CLOCKS_PER_SEC/1000);

    printf("\n\nFine programma! Il tempo di esecuzione e' stato di circa %.2f millisecondi.", tempoEsecuzione);

    return 0;
}

void letturaDizionario(list<string> &paroleDizionario) {

    printf("\nLettura iniziale dizionario in corso...");

    string letto;

    ifstream file;
    file.open("dizionario.txt");
    if (file.is_open()) {
        while (file) {
            getline(file, letto);
            paroleDizionario.push_back(letto);
        }
    }

    printf("\nFine lettura iniziale dizionario!");
}

void estraiParole(const string &input, list<string> &paroleInput) {
    stringstream streamDiParole(input);
    string parola;
    while (getline(streamDiParole, parola, ' ')) {

        std::for_each(parola.begin(), parola.end(), [](char & c) { // Rendo tutto lowercase.
            c = ::tolower(c);
        });

        paroleInput.push_back(parola);
    }
}


