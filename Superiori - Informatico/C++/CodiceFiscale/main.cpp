#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void continua();

bool carattereEssereConsonante(int i, string nome);

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//            Stringhe di G.C. 3BITI            //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;

    while (scelta != 0){

        printf("\n\nLegenda:"
               "\n 0 -> Esci."
               "\n 1 -> Codice fiscale, inserire dati."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nUscendo dal programma...");

                break;
            }

            case 1:{

                // Data
                struct s_data{
                    string anno, giorno;
                    int mese = 0;
                };

                // Persona
                struct s_persona{
                    string nome, cognome, comune, sesso;
                    s_data dataNascita;
                } persona;

                // Inserimento dati:
                printf("\nHai scelto: Codice fiscale.");

                printf("\nInserire sesso (M Maschio, F Femmina): ");
                cin >> persona.sesso;

                printf("\nInserire nome: ");
                cin >> persona.nome;

                printf("\nInserire cognome: ");
                cin >> persona.cognome;

                printf("\nInserire comune di nascita: ");
                cin >> persona.comune;

                printf("\nInserire giorno di nascita GG: ");
                cin >> persona.dataNascita.giorno;

                printf("\nInserire mese di nascita MM: ");
                cin >> persona.dataNascita.mese;

                printf("\nInserire anno di nascita AAAA: ");
                cin >> persona.dataNascita.anno;

                // Dichiaro stringa codice fiscale.
                string codiceFiscale;

                // Comunico inizio conversione.
                printf("\nGenerazione codice fiscale in corso...");

                // Dichiaro variabile utile e carattere speciale
                int numerLet = 0;
                string carattereSpeciale = "X";

                // Inizio prime 3 lettere
                for (int i = 0; i < persona.cognome.size() && numerLet < 3; i++) {
                    if (carattereEssereConsonante(i, persona.cognome)){
                        codiceFiscale += persona.cognome[i];
                        numerLet++;
                    }
                }

                if (numerLet < 3){
                    for (int i = 0; i < persona.cognome.size(); i++) {
                        if (!carattereEssereConsonante(i, persona.cognome)){
                            codiceFiscale += persona.cognome[i];
                            numerLet++;
                        }
                    }
                }

                while (numerLet < 3) {
                    codiceFiscale += carattereSpeciale;
                    numerLet++;
                }
                // Fine prime 3 lettere per cognome.

                // Inizio 3 Lettere dal nome.
                // Ottieni numero consonanti
                int numeroConsonanti = 0;
                for (int i = 0; i < persona.nome.size(); i++) {
                    if (carattereEssereConsonante(i, persona.nome)){
                        numeroConsonanti++;
                    }
                }

                if (numeroConsonanti > 3){
                    int consonanteInUso = 0;

                    for (int i = 0; i < persona.nome.size(); i++) {
                        if (carattereEssereConsonante(i, persona.nome)){
                            if (consonanteInUso == 0 || consonanteInUso == 2 || consonanteInUso == 3){
                                codiceFiscale += persona.nome[i];
                                numerLet++;
                            }
                            consonanteInUso++;
                        }
                    }

                } else {

                    for (int i = 0; i < persona.nome.size() && numerLet < 6; i++) {
                        if (carattereEssereConsonante(i, persona.nome)){
                            codiceFiscale += persona.nome[i];
                            numerLet++;
                        }
                    }

                    if (numerLet < 6){
                        for (int i = 0; i < persona.nome.size() && numerLet < 6; i++) {
                            if (!carattereEssereConsonante(i, persona.nome)){
                                codiceFiscale += persona.nome[i];
                                numerLet++;
                            }
                        }
                    }

                    while (numerLet < 6){
                        codiceFiscale += carattereSpeciale;
                        numerLet++;
                    }
                }
                // Fine 3 lettere dal nome.

                // Inizio 2 numeri per anno di nascita.
                codiceFiscale += persona.dataNascita.anno.substr(2);
                // Fine 2 numeri per anno di nascita.

                // Inizio lettera per mese di nascita.
                switch (persona.dataNascita.mese) {

                    case 1:{

                        codiceFiscale += "A";

                        break;
                    }

                    case 2:{

                        codiceFiscale += "B";

                        break;
                    }

                    case 3:{

                        codiceFiscale += "C";

                        break;
                    }

                    case 4:{

                        codiceFiscale += "D";

                        break;
                    }

                    case 5:{

                        codiceFiscale += "E";

                        break;
                    }

                    case 6:{

                        codiceFiscale += "H";

                        break;
                    }

                    case 7:{

                        codiceFiscale += "L";

                        break;
                    }

                    case 8:{

                        codiceFiscale += "M";

                        break;
                    }

                    case 9:{

                        codiceFiscale += "P";

                        break;
                    }

                    case 10:{

                        codiceFiscale += "R";

                        break;
                    }

                    case 11:{

                        codiceFiscale += "S";

                        break;
                    }

                    case 12:{

                        codiceFiscale += "T";

                        break;
                    }

                    default:{

                        codiceFiscale += carattereSpeciale;

                    }

                }
                // Fine lettere per mese di nascita.

                // Inizio numeri per giorno di nascita.

                // Ottengo dalla struct il giorno di nascita.
                int giornoNascita = atoi(persona.dataNascita.giorno.c_str());
                // Introduco alternativa a string per funzionare anche in CodeBlocks to_string in str.
                stringstream ss1;
                stringstream ss2;
                ss1 << (giornoNascita + 40);
                ss2 << giornoNascita;

                // Condizioni logiche in base al giorno di nascita inserito e il sesso, verifica anche se è valido, se non valido inserisce carattere speciale.
                if (giornoNascita > 31 || giornoNascita < 1 || (persona.sesso != "M" && persona.sesso != "m" && persona.sesso != "F" && persona.sesso != "f")){
                    codiceFiscale += carattereSpeciale + carattereSpeciale;
                } else if (persona.sesso == "f" || persona.sesso == "F"){
                    codiceFiscale += ss1.str();
                } else {
                    codiceFiscale += ss2.str();
                }
                // Fine numeri per giorno di nascita.

                // Inserimento codice comune:
                string codiceComune;
                printf("\n\nInserire codice comune (1 lettera e 3 numeri, es H501): ");
                cin >> codiceComune;

                // Aggiungo al codice fiscale il codice del comune inserito dall'utente.
                codiceFiscale += codiceComune;

                // Comunico che è stata ripresa la generazione.
                printf("\n\nRipresa generazione codice fiscale...");

                // Generazione carattere di controllo.

                // Rende tutto uppercase.
                std::transform(codiceFiscale.begin(), codiceFiscale.end(),codiceFiscale.begin(), ::toupper);

                // Variabile somma dei valori e alfabeto.
                int sommaValori = 0;
                string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVXYZ";

                // Ciclo per ogni carattere del codice fiscale
                for (int i = 0; i < codiceFiscale.size(); i++) {
                    // Ottengo posizione corretta.
                    int posizione = i + 1;

                    // Verifica se è pari o dispari
                    if (posizione % 2 == 0){

                        // Esegui azione in base al valore.
                        switch (codiceFiscale[i]) {

                            case '0':{

                                sommaValori += 0;

                                break;
                            }

                            case '1':{

                                sommaValori += 1;

                                break;
                            }

                            case '2':{

                                sommaValori += 2;

                                break;
                            }

                            case '3':{

                                sommaValori += 3;

                                break;
                            }

                            case '4':{

                                sommaValori += 4;

                                break;
                            }

                            case '5':{

                                sommaValori += 5;

                                break;
                            }

                            case '6':{

                                sommaValori += 6;

                                break;
                            }

                            case '7':{

                                sommaValori += 7;

                                break;
                            }

                            case '8':{

                                sommaValori += 8;

                                break;
                            }

                            case '9':{

                                sommaValori += 9;

                                break;
                            }

                            default:{

                                // Ciclo logico in caso non sia numero ma una lettera.
                                for (int j = 0; j < alfabeto.size(); j++) {
                                    if (codiceFiscale[i] == alfabeto[j]){
                                        sommaValori += j;
                                    }
                                }

                                break;
                            }
                        }

                    } else {

                        // Eseguo azioni in base al valore.
                        switch (codiceFiscale[i]) {
                            case 'A':{

                                sommaValori += 1;

                                break;
                            }

                            case 'B':{

                                sommaValori += 0;

                                break;
                            }

                            case 'C':{

                                sommaValori += 5;

                                break;
                            }

                            case 'D':{

                                sommaValori += 7;

                                break;
                            }

                            case 'E':{

                                sommaValori += 9;

                                break;
                            }

                            case 'F':{

                                sommaValori += 13;

                                break;
                            }

                            case 'G':{

                                sommaValori += 15;

                                break;
                            }

                            case 'H':{

                                sommaValori += 17;

                                break;
                            }

                            case 'I':{

                                sommaValori += 19;

                                break;
                            }

                            case 'J':{

                                sommaValori += 21;

                                break;
                            }

                            case 'K':{

                                sommaValori += 2;

                                break;
                            }

                            case 'L':{

                                sommaValori += 4;

                                break;
                            }

                            case 'M':{

                                sommaValori += 18;

                                break;
                            }

                            case 'N':{

                                sommaValori += 20;

                                break;
                            }

                            case 'O':{

                                sommaValori += 11;

                                break;
                            }

                            case 'P':{

                                sommaValori += 3;

                                break;
                            }

                            case 'Q':{

                                sommaValori += 6;

                                break;
                            }

                            case 'R':{

                                sommaValori += 8;

                                break;
                            }

                            case 'S':{

                                sommaValori += 12;

                                break;
                            }

                            case 'T':{

                                sommaValori += 14;

                                break;
                            }

                            case 'U':{

                                sommaValori += 16;

                                break;
                            }

                            case 'V':{

                                sommaValori += 10;

                                break;
                            }

                            case 'W':{

                                sommaValori += 22;

                                break;
                            }

                            case 'X':{

                                sommaValori += 25;

                                break;
                            }

                            case 'Y':{

                                sommaValori += 24;

                                break;
                            }

                            case 'Z':{

                                sommaValori += 23;

                                break;
                            }

                            case '0':{

                                sommaValori += 1;

                                break;
                            }

                            case '1':{

                                sommaValori += 0;

                                break;
                            }

                            case '2':{

                                sommaValori += 5;

                                break;
                            }

                            case '3':{

                                sommaValori += 7;

                                break;
                            }

                            case '4':{

                                sommaValori += 9;

                                break;
                            }

                            case '5':{

                                sommaValori += 13;

                                break;
                            }

                            case '6':{

                                sommaValori += 15;

                                break;
                            }

                            case '7':{

                                sommaValori += 17;

                                break;
                            }

                            case '8':{

                                sommaValori += 19;

                                break;
                            }

                            case '9':{

                                sommaValori += 21;

                                break;
                            }

                            default:{

                                sommaValori += 0;

                                break;
                            }
                        }
                    }
                }

                // Ottengo lettera in base al valore del resto.
                codiceFiscale += alfabeto[(sommaValori % 26)];

                // Fine carattere di controllo.

                // Comunico.
                cout << "\nCodice fiscale: " << codiceFiscale;

                continua();
                break;
            }

            default:{

                // Scelta non valida
                printf("\nHai inserito una scelta non valida!");

                continua();
                break;
            }


        }
    }

    printf("\nUscito dal programma con successo!");
    return 0;
}

bool carattereEssereConsonante(int i, string nome) {

    // Insieme vocali.
    string vocali = "aAeEiIoOuU";

    // Ciclo logico
    for (int j = 0; j < vocali.size(); j++) {
        if (nome[i] == vocali[j]){
            return false;
        }
    }

    return true;
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci qualcosa per continuare... ");
    scanf("%d", &inusato);

}
