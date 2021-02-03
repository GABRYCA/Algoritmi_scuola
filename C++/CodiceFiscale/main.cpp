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
           "\n//            Stringhe di Gabriele Caretti 3BITI            //"
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

                struct s_data{
                    string anno, giorno;
                    int mese = 0;
                };

                struct s_persona{
                    string nome, cognome, comune, sesso;
                    s_data dataNascita;
                } persona;

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

                string codiceFiscale;

                printf("\nGenerazione codice fiscale in corso...");

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
                numerLet += 2;
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
                numerLet++;
                // Fine lettere per mese di nascita.

                // Inizio numeri per giorno di nascita.
                int giornoNascita = atoi(persona.dataNascita.giorno.c_str());
                stringstream ss1;
                stringstream ss2;
                ss1 << (giornoNascita + 40);
                ss2 << giornoNascita;

                if (giornoNascita > 31 || giornoNascita < 1 || (persona.sesso != "M" && persona.sesso != "m" && persona.sesso != "F" && persona.sesso != "f")){
                    codiceFiscale += carattereSpeciale + carattereSpeciale;
                } else if (persona.sesso == "f" || persona.sesso == "F"){
                    codiceFiscale += ss1.str();
                } else {
                    codiceFiscale += ss2.str();
                }
                numerLet += 2;
                // Fine numeri per giorno di nascita.

                std::transform(codiceFiscale.begin(), codiceFiscale.end(),codiceFiscale.begin(), ::toupper);

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

    string vocali = "aAeEiIoOuU";

    for (int j = 0; j < vocali.size(); j++) {
        if (nome[i] == vocali[j]){
            return false;
        }
    }

    return true;
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}
