#include <iostream>
#include <stdio.h>
#include <string>
#include "Bicchiere.h"

using namespace std;

void pausa();

int main(){

    // Messaggio di benvenuto.
    printf("\n/////////////////////////////////////"
           "\n// Compito Bicchiere di G.C. 4BITI //"
           "\n/////////////////////////////////////");

    // Dati temporanei dalla lettura dell'utente.
    string forma;
    string materiale;
    float livello;
    float capacita;

    // Chiedo dati in input.
    printf("\n\nCreazione del bicchiere..."
           "\n\nInserire materiale: ");
    cin >> materiale;
    printf("\nMateriale impostato con successo!"
           "\n\nInserire forma: ");
    cin >> forma;
    printf("\nForma impostata con successo!");

    // Chiedo altri dati e poi creo il bicchiere.
    printf("\nInserire capacita' (mL): ");
    scanf("%f", &capacita);
    printf("\nCapacita' impostata con successo!");

    // Mi assicuro che l'utente inserisca un livello valido.
    do {
        printf("\nInserire livello (0 (vuoto) <= capacita') (mL): ");
        scanf("%f", &livello);
        if (livello < 0 || livello > capacita){
            printf("\n\nLivello non valido, per favore riprovare!\n");
        }
    } while (livello < 0 || livello > capacita);

    // Creo l'oggetto con i valori inseriti.
    printf("\n\nCreazione del bicchiere con i dati impostati...");
    Bicchiere bicchiere = Bicchiere(materiale, forma, livello, capacita);

    // Riassunto bicchiere creato.
    printf("\n\nBicchiere creato con successo, riepilogo bicchiere: "
           "\nMateriale: %s"
           "\nForma: %s"
           "\nCapacita': %.2fmL"
           "\nLivello: %.2fmL", bicchiere.getMateriale().c_str(), bicchiere.getForma().c_str(), bicchiere.getCapacita(), bicchiere.getLivello());

    // Menu.
    int scelta;
    do {
        printf("\n\nOpzioni bicchiere: "
               "\n0 -> Esci."
               "\n1 -> Bevi."
               "\n2 -> Riempi."
               "\n3 -> Aggiungi una certa quantita'."
               "\n4 -> Svuota."
               "\n5 -> Informazioni bicchiere."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0:{

                printf("\nHai scelto: Esci...\n"
                       "\nUscita in corso!");

                break;
            }
            case 1:{

                printf("\nHai scelto: Bevi...\n");

                float livelloBicchiere = bicchiere.getLivello();

                if (livelloBicchiere <= 0){
                    printf("\n\nIl bicchiere e' vuoto, non puoi bere l'aria!");
                    pausa();
                    break;
                }

                // Chiedo all'utente quanto voglia bere.
                float daBere;
                printf("\nQuanto vuoi bere? Il bicchiere ha %.2fmL:", livelloBicchiere);
                scanf("%f", &daBere);

                if (livelloBicchiere < daBere){
                    printf("\nHai inserito una quantita' troppo alta, il bicchiere non la contiene!");
                } else {
                    bicchiere.setLivello(livelloBicchiere - daBere);
                    printf("\nBevuto con successo %.2fmL, rimane %.2fmL nel bicchiere!", daBere, bicchiere.getLivello());
                }

                pausa();
                break;
            }

            case 2:{

                printf("\nHai scelto: Riempi...\n");

                float livelloBicchiere = bicchiere.getLivello();
                if (livelloBicchiere == bicchiere.getCapacita()){
                    printf("\nIl bicchiere e' gia' pieno, non puoi riempirlo di piu'!");
                    break;
                }

                float daRiempire = bicchiere.getCapacita() - livelloBicchiere;
                bicchiere.setLivello(livelloBicchiere + daRiempire);
                printf("\nBicchiere riempito con successo! E' stato aggiunto %2.fmL, ora contiene %.2fmL ed e' pieno!", daRiempire, bicchiere.getLivello());

                pausa();
                break;
            }

            case 3:{

                printf("\nHai scelto: Riempi di una certa quantita'...\n");

                float livelloBicchiere = bicchiere.getLivello();
                if (livelloBicchiere == bicchiere.getCapacita()){
                    printf("\nIl bicchiere e' gia' pieno, non puoi riempirlo di piu'!");
                    break;
                }

                float daRiempire;
                printf("\n\nInserire quantita' da riempire: ");
                scanf("%f", &daRiempire);

                if (livelloBicchiere + daRiempire > bicchiere.getCapacita()){
                    printf("\nHai inserito una quantita' troppo alta, il bicchiere e' troppo piccolo!");
                } else {
                    bicchiere.setLivello(livelloBicchiere + daRiempire);
                    printf("\nBicchiere riempito con successo! Ora contiene %.2fmL.", bicchiere.getLivello());
                }

                pausa();
                break;
            }

            case 4:{

                printf("\nHai scelto: Svuota...\n");

                float livelloBicchiere = bicchiere.getLivello();
                if (livelloBicchiere <= 0){
                    printf("\nIl bicchiere e' gia' vuoto!");
                    break;
                }

                bicchiere.setLivello(0);
                printf("\nIl bicchiere e' stato svuotato, %.2fmL sono stati buttati!", livelloBicchiere);

                pausa();
                break;
            }

            case 5:{

                printf("\nHai scelto: Informazioni bicchiere...\n");

                // Riassunto bicchiere creato.
                printf("\nInformazioni bicchiere: "
                       "\nMateriale: %s"
                       "\nForma: %s"
                       "\nCapacita': %.2fmL"
                       "\nLivello: %.2fmL", bicchiere.getMateriale().c_str(), bicchiere.getForma().c_str(), bicchiere.getCapacita(), bicchiere.getLivello());

                pausa();
                break;
            }

            default:{
                printf("\nValore non valido!");
                break;
            }
        }
    } while (scelta != 0);

    printf("\n\nProgramma chiuso con successo!");
    return 0;
}

void pausa(){
    printf("\n\nInserire un numero per continuare: ");
    scanf("%d");
}

