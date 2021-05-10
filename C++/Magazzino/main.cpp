#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream>

using namespace std;

void continua();
bool magazzinoEsiste();
bool logEsiste();
string sostituisciSpaziConTrattini(string stringa);
string sostituisciTrattiniConSpazi(string stringa);

void resocontoPerTipo(FILE *modifiche, const string &nomeOperazione);

string daIntAString(int numero);

string dataTempo();

struct prodottoMagazzino{
    string categoria;
    string nomeProdotto;
    double prezzo;
    int quantita;
};

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//          Magazzino di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    // Inizializzo una struct vuoto anche se inusata, in pervisioni di possibilita' di FILE binari e inizializzo diverse variabili.
    struct prodottoMagazzino vuoto{"", "", 0, 0};
    struct prodottoMagazzino prodotto{};
    int scelta = 1;
    FILE *magazzino;
    FILE *modifiche;

    // Continuo fino a quando l'utente non sceglie l'opzione di uscita.
    while (scelta != 0){

        // Legenda.
        printf("\n\nLegenda:"
               "\n0 -> Esci dal programma."
               "\n1 -> Inizializza nuovo FILE o resetta intero magazzino."
               "\n2 -> Aggiungi prodotto."
               "\n3 -> Modifica prodotto con menu."
               "\n4 -> Elimina prodotto."
               "\n5 -> Leggi contenuto intero magazzino."
               "\n6 -> Leggi prodotti appartenenti a una categoria."
               "\n7 -> Vendita prodotto."
               "\n8 -> Imprevisto prodotto."
               "\n9 -> Leggi informazioni prodotto."
               "\n10 -> Operazioni con i log."
               "\n11 -> Reset quantita' intero magazzino."
               "\nScelta: ");
        scanf("%d", &scelta);

        // Scelte.
        switch (scelta) {

            case 0:{

                // Uscita.
                printf("\nHai scelto: Esci..."
                       "\n\nUscita in corso...\n");

                break;
            }

            case 1:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Inizializzazione FILE magazzino o reset...");

                // Variabili.
                bool esiste = magazzinoEsiste();
                int conferma;
                if (esiste){

                    // Chiedo conferma prima di procedere.
                    printf("\nSei sicuro di voler cancellare il magazzino e crearne uno nuovo vuoto?"
                           "\n0 -> Annulla."
                           "\n1 -> Conferma."
                           "\nScelta: ");
                    scanf("%d", &conferma);

                    // Verifica input valido.
                    if (conferma != 0 && conferma != 1){

                        // Messaggio d'errore.
                        printf("\nHai inserito una scelta non valida, annullo operazione reset magazzino!");
                        fclose(magazzino);
                        break;

                    }

                    // Scelta annullamento.
                    if (conferma == 0){

                        // Messaggio annullamento.
                        printf("\nAnnullo reset magazzino!");
                        fclose(magazzino);
                        break;

                    }
                }
                fclose(magazzino);

                // Apro magazzino in modalita' scrittura e lo chiudo per salvarlo.
                magazzino = fopen("magazzino.txt", "w");
                fclose(magazzino);

                // Tipo di modifica effettuata
                string tagModifica = "Reset";
                if (logEsiste()){
                    
                    // Apro il FILE log in modalita' append.
                    modifiche = fopen("modifiche.txt", "a");
                    fprintf(modifiche, "%s", "\n");
                    fprintf(modifiche, "%s %s %s %lf %d %s", tagModifica.c_str(), "reset", "reset", 0.00, 0, dataTempo().c_str());

                } else {

                    // Apro il FILE log in modalita' di scrittura.
                    modifiche = fopen("modifiche.txt", "w");
                    fprintf(modifiche, "%s %s %s %lf %d %s", tagModifica.c_str(), "reset", "reset", 0.00, 0, dataTempo().c_str());

                }
                fclose(modifiche);

                // Comunico messaggio successo.
                printf("\nCreato con successo nuovo FILE magazzino!");

                // Pausa e fine.
                continua();
                break;
            }

            case 2:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Aggiungi prodotto al magazzino...\n");

                // Chiedo dati in ingresso.
                printf("\nInserire categoria: ");
                cin.ignore();
                getline(cin, prodotto.categoria);
                prodotto.categoria = sostituisciSpaziConTrattini(prodotto.categoria);

                // Chiedo dati in ingresso.
                printf("\nInserire nome prodotto: ");
                // cin.ignore();
                getline(cin, prodotto.nomeProdotto);
                prodotto.nomeProdotto = sostituisciSpaziConTrattini(prodotto.nomeProdotto);

                // Chiedo dati in ingresso.
                printf("\nInserire prezzo: ");
                cin >> prodotto.prezzo;

                // Chiedo dati in ingresso.
                printf("\nInserire Disponibilita': ");
                cin >> prodotto.quantita;

                // Cerca quantita precedente del prodotto nel magazzino.
                int quantitaPrecedente = 0;
                int numeroRigaFinale = 0;
                bool scrittoModifiche = false;
                if (magazzinoEsiste()){
                    
                    // Apro magazzino in modalita' di sola lettura.
                    magazzino = fopen("magazzino.txt","r");

                    // Inizializzo una struct che uso per comodita' e ordine dove metto i valori letti e altre variabili.
                    struct prodottoMagazzino prodottoLetto{};
                    char categoria[100];
                    char nomeProdotto[100];
                    int numeroRiga = 0;
                    
                    // Leggo tutto il magazzino alla ricerca del prodotto per verificare se esiste gia' e quindi incrementare le quanita'.
                    while (!feof(magazzino)){
                        numeroRiga++;
                        fscanf(magazzino, "%s %s %lf %d", categoria, nomeProdotto, &prodottoLetto.prezzo, &prodottoLetto.quantita);
                        prodottoLetto.categoria = categoria;
                        prodottoLetto.nomeProdotto = nomeProdotto;

                        // Prodotto trovato, esegue azioni.
                        if (prodottoLetto.nomeProdotto == prodotto.nomeProdotto){
                            quantitaPrecedente = prodottoLetto.quantita;
                            numeroRigaFinale = numeroRiga;

                            printf("\nIl prodotto esiste gia', incrementando Disponibilita' totale in base al numero dato e quello salvato in precedenza.");

                            // In base se il FILE dei log esista o meno, eseguo azioni.
                            if (logEsiste()){
                                modifiche = fopen("modifiche.txt", "a");
                                fprintf(modifiche, "%s", "\n");
                                fprintf(modifiche, "%s %s %s %lf %d %s", "Aggiunto", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, dataTempo().c_str());
                                scrittoModifiche = true;
                            } else {
                                modifiche = fopen("modifiche.txt", "w");
                                fprintf(modifiche, "%s %s %s %lf %d %s", "Aggiunto", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, dataTempo().c_str());
                                scrittoModifiche = true;
                            }
                            fclose(modifiche);
                        }
                    }
                    fclose(magazzino);
                }
                // Somma quantita precedenta a quella nuova perche' stiamo aggiungendo
                prodotto.quantita = quantitaPrecedente + prodotto.quantita;

                // In base se il magazzino esiste o meno, eseguo le operazioni per aggiungere o modificare il prodotto.
                if (magazzinoEsiste()){


                   // Verifico con 0 perche' se lo e' significa che il prodotto non e' stato trovato.
                    if (numeroRigaFinale != 0) {
                        FILE *temporaneo = fopen("temp.txt", "w");
                        magazzino = fopen("magazzino.txt", "r");

                        // Leggo tutto il magazzino e lo scrivo con le modifiche su un FILE temporaneo, poi cancella il vecchio e rinomino.
                        int numeroLettura = 0;
                        while (!feof(magazzino)) {
                            if (numeroLettura != 0) {
                                fprintf(temporaneo, "%s", "\n");
                            }
                            numeroLettura++;
                            char categoria[100];
                            char nome[100];
                            double prezzo;
                            int quantita;
                            fscanf(magazzino, "%s %s %lf %d", categoria, nome, &prezzo, &quantita);
                            if (numeroLettura == numeroRigaFinale) {
                                fprintf(temporaneo, "%s %s %lf %d", prodotto.categoria.c_str(),
                                        prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);
                            } else {
                                fprintf(temporaneo, "%s %s %lf %d", categoria, nome, prezzo, quantita);
                            }
                        }
                        fclose(temporaneo);
                        fclose(magazzino);
                        remove("magazzino.txt");
                        rename("temp.txt", "magazzino.txt");
                    } else {

                        // Aggiungo il prodotto al magazzino.
                        magazzino = fopen("magazzino.txt", "a");
                        fprintf(magazzino, "%s", "\n");
                        fprintf(magazzino, "%s %s %lf %d", prodotto.categoria.c_str(),
                                prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);
                        fclose(magazzino);

                    }

                } else {

                    // Creo nuovo magazzino e aggiungo il prodotto.
                    magazzino = fopen("magazzino.txt", "w");
                    fprintf(magazzino, "%s %s %lf %d", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);
                }
                fclose(magazzino);

                // Verifico se l'operazione e' gia' stata fatta, se non allora scrivo ora i valori nei log.
                if (!scrittoModifiche){
                    if (logEsiste()){
                        modifiche = fopen("modifiche.txt", "a");
                        fprintf(modifiche, "%s", "\n");
                        fprintf(modifiche, "%s %s %s %lf %d %s", "Aggiunto", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, dataTempo().c_str());
                    } else {
                        modifiche = fopen("modifiche.txt", "w");
                        fprintf(modifiche, "%s %s %s %lf %d %s", "Aggiunto", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, dataTempo().c_str());
                    }
                    fclose(modifiche);
                }

                // Messaggio di successo.
                printf("\nOperazione prodotto effettuata con successo!");

                // Pausa e fine.
                continua();
                break;
            }

            case 3:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Modifica prodotto magazzino...\n");

                // Chiedo input.
                printf("\nInserire nome prodotto: ");
                cin.ignore();
                getline(cin, prodotto.nomeProdotto);
                prodotto.nomeProdotto = sostituisciSpaziConTrattini(prodotto.nomeProdotto);

                // Verifico se il magazzino esiste ed eseguo azioni.
                if (magazzinoEsiste()){

                    // Apro il magazzino in modalita' lettura.
                    magazzino = fopen("magazzino.txt", "r");

                    // Cerco il prodotto.
                    int rigaPosizione = 0;
                    struct prodottoMagazzino prodottoLetto{};
                    char categoriaLetta[100];
                    char nomeLetto[100];
                    int rigaInLettura = 0;
                    while (!feof(magazzino)){
                        rigaInLettura++;
                        fscanf(magazzino, "%s %s %lf %d", categoriaLetta, nomeLetto, &prodottoLetto.prezzo, &prodottoLetto.quantita);

                        // Prodotto trovato.
                        if (nomeLetto == prodotto.nomeProdotto){
                            rigaPosizione = rigaInLettura;
                            prodotto.categoria = categoriaLetta;
                            prodotto.prezzo = prodottoLetto.prezzo;
                            prodotto.quantita = prodottoLetto.quantita;
                        }
                    }
                    fclose(magazzino);

                    // Verifico se e' stato trovato in precedenza prima di procedere.
                    if (rigaPosizione != 0){

                        // Inizializzo una nuova struct con i dati vecchi, utili a volte nei log.
                        struct prodottoMagazzino vecchiDati{prodotto.categoria, prodotto.nomeProdotto, prodotto.prezzo, prodotto.quantita};
                        int sceltaOperazione;

                        // Comunico riassunto situazione all'utente.
                        printf("\nInformazioni attuali prodotto: "
                               "\nCategoria: %s"
                               "\nNome: %s"
                               "\nPrezzo: %2.f Euro"
                               "\nDisponibilita': %d\n", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);

                        // Menu' delle opzioni possibili.
                        printf("\nOperazioni possibili: "
                               "\n 0 -> Esci."
                               "\n 1 -> Modifica categoria."
                               "\n 2 -> Modifica nome."
                               "\n 3 -> Modifica prezzo."
                               "\n 4 -> Modifica Disponibilita'."
                               "\nScelta: ");
                        scanf("%d", &sceltaOperazione);

                        // Switch tra le varie scelte.
                        switch (sceltaOperazione) {

                            case 0:{

                                // Uscita.
                                printf("\nHai scelto: Esci...");

                                break;
                            }

                            case 1:{

                                // Messaggio d'inizio.
                                printf("\nHai scelto: Modifica categoria...");

                                // Chiedo dati in ingresso.
                                printf("\nInserire nuovo nome categoria: ");
                                cin.ignore();
                                getline(cin, prodotto.categoria);
                                prodotto.categoria = sostituisciSpaziConTrattini(prodotto.categoria);

                                // Apro i vari FILEs.
                                FILE *temp = fopen("temp.txt", "w");
                                magazzino = fopen("magazzino.txt", "r");

                                // Cerco il valore per posizione e lo modifico ricopiando tutto il magazzino nel FILE temporaneo poi rinominando.
                                rigaInLettura = 0;
                                while (!feof(magazzino)){
                                    if (rigaInLettura != 0){
                                        fprintf(temp, "%s", "\n");
                                    }
                                    rigaInLettura++;
                                    fscanf(magazzino, "%s %s %lf %d", categoriaLetta, nomeLetto, &prodottoLetto.prezzo, &prodottoLetto.quantita);
                                    if (rigaInLettura != rigaPosizione){
                                        fprintf(temp, "%s %s %lf %d", categoriaLetta, nomeLetto, prodottoLetto.prezzo, prodottoLetto.quantita);
                                    } else {
                                        fprintf(temp, "%s %s %lf %d", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);
                                    }
                                }
                                fclose(magazzino);
                                fclose(temp);
                                remove("magazzino.txt");
                                rename("temp.txt", "magazzino.txt");

                                // Comunico operazione effettuata con successo.
                                printf("\nOperazione effettuata con successo!");

                                // Log.
                                if (logEsiste()){

                                    modifiche = fopen("modifiche.txt", "a");
                                    fprintf(modifiche, "%s", "\n");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Categoria", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, dataTempo().c_str());

                                } else {

                                    modifiche = fopen("modifiche.txt", "w");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Categoria", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, dataTempo().c_str());

                                }
                                fclose(modifiche);
                                
                                // Pausa.
                                continua();
                                break;
                            }

                            case 2:{

                                // Messaggio d'inizio.
                                printf("\nHai scelto: Modifica nome...");

                                // Chiedo input.
                                printf("\nInserire nuovo nome prodotto: ");
                                cin.ignore();
                                getline(cin, prodotto.nomeProdotto);
                                prodotto.nomeProdotto = sostituisciSpaziConTrattini(prodotto.nomeProdotto);

                                // Apro i vari FILEs.
                                FILE *temp = fopen("temp.txt", "w");
                                magazzino = fopen("magazzino.txt", "r");

                                // Ricopio intero magazzino con valori modificati nel file temporaneo e poi cancello e rinomino per sostituirlo.
                                rigaInLettura = 0;
                                while (!feof(magazzino)){
                                    if (rigaInLettura != 0){
                                        fprintf(temp, "%s", "\n");
                                    }
                                    rigaInLettura++;
                                    fscanf(magazzino, "%s %s %lf %d", categoriaLetta, nomeLetto, &prodottoLetto.prezzo, &prodottoLetto.quantita);
                                    if (rigaInLettura != rigaPosizione){
                                        fprintf(temp, "%s %s %lf %d", categoriaLetta, nomeLetto, prodottoLetto.prezzo, prodottoLetto.quantita);
                                    } else {
                                        fprintf(temp, "%s %s %lf %d", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);
                                    }
                                }
                                fclose(magazzino);
                                fclose(temp);
                                remove("magazzino.txt");
                                rename("temp.txt", "magazzino.txt");

                                // Comunico successo.
                                printf("\nOperazione effettuata con successo!");

                                // Log.
                                if (logEsiste()){

                                    modifiche = fopen("modifiche.txt", "a");
                                    fprintf(modifiche, "%s", "\n");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Nome", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, dataTempo().c_str());

                                } else {

                                    modifiche = fopen("modifiche.txt", "w");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Nome", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, dataTempo().c_str());

                                }
                                fclose(modifiche);

                                // Pausa e fine.
                                continua();
                                break;
                            }

                            case 3:{

                                // Messaggio d'inizio.
                                printf("\nHai scelto: Modifica prezzo...");

                                // Chiedo input.
                                printf("\nInserire nuovo prezzo prodotto: ");
                                scanf("%lf", &prodotto.prezzo);

                                // Apro i vari FILEs.
                                FILE *temp = fopen("temp.txt", "w");
                                magazzino = fopen("magazzino.txt", "r");

                                // Eseguo copia contenuto magazzino in FILE temporaneo e valore modificato poi cancello il vecchio e rinomino.
                                rigaInLettura = 0;
                                while (!feof(magazzino)){
                                    if (rigaInLettura != 0){
                                        fprintf(temp, "%s", "\n");
                                    }
                                    rigaInLettura++;
                                    fscanf(magazzino, "%s %s %lf %d", categoriaLetta, nomeLetto, &prodottoLetto.prezzo, &prodottoLetto.quantita);
                                    if (rigaInLettura != rigaPosizione){
                                        fprintf(temp, "%s %s %lf %d", categoriaLetta, nomeLetto, prodottoLetto.prezzo, prodottoLetto.quantita);
                                    } else {
                                        fprintf(temp, "%s %s %lf %d", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);
                                    }
                                }
                                fclose(magazzino);
                                fclose(temp);
                                remove("magazzino.txt");
                                rename("temp.txt", "magazzino.txt");

                                // Comunico operazione effettuata con successo.
                                printf("\nOperazione effettuata con successo!");

                                // Log.
                                if (logEsiste()){

                                    modifiche = fopen("modifiche.txt", "a");
                                    fprintf(modifiche, "%s", "\n");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Prezzo", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, dataTempo().c_str());

                                } else {

                                    modifiche = fopen("modifiche.txt", "w");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Prezzo", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, dataTempo().c_str());

                                }
                                fclose(modifiche);

                                // Pausa e fine.
                                continua();
                                break;
                            }

                            case 4:{

                                // Messaggio d'inizio.
                                printf("\nHai scelto: Modifica Disponibilita'...");

                                // Chiedo dati in ingresso.
                                printf("\nInserire nuova Disponibilita' prodotto: ");
                                scanf("%d", &prodotto.quantita);

                                // Apro i FILEs.
                                FILE *temp = fopen("temp.txt", "w");
                                magazzino = fopen("magazzino.txt", "r");

                                // Copio il FiLE magazzino nel FILE temporaneo con i valori modificati, poi cancello e rinomino.
                                rigaInLettura = 0;
                                while (!feof(magazzino)){
                                    if (rigaInLettura != 0){
                                        fprintf(temp, "%s", "\n");
                                    }
                                    rigaInLettura++;
                                    fscanf(magazzino, "%s %s %lf %d", categoriaLetta, nomeLetto, &prodottoLetto.prezzo, &prodottoLetto.quantita);
                                    if (rigaInLettura != rigaPosizione){
                                        fprintf(temp, "%s %s %lf %d", categoriaLetta, nomeLetto, prodottoLetto.prezzo, prodottoLetto.quantita);
                                    } else {
                                        fprintf(temp, "%s %s %lf %d", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);
                                    }
                                }
                                fclose(magazzino);
                                fclose(temp);
                                remove("magazzino.txt");
                                rename("temp.txt", "magazzino.txt");

                                // Comunico FINE operazione effettuata con successo.
                                printf("\nOperazione effettuata con successo!");

                                // Log.
                                if (logEsiste()){

                                    modifiche = fopen("modifiche.txt", "a");
                                    fprintf(modifiche, "%s", "\n");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Aggiunto", vecchiDati.categoria.c_str(), vecchiDati.nomeProdotto.c_str(), vecchiDati.prezzo, vecchiDati.quantita + prodotto.quantita, dataTempo().c_str());

                                } else {

                                    modifiche = fopen("modifiche.txt", "w");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Aggiunto", vecchiDati.categoria.c_str(), vecchiDati.nomeProdotto.c_str(), vecchiDati.prezzo, vecchiDati.quantita + prodotto.quantita, dataTempo().c_str());

                                }
                                fclose(modifiche);

                                // Pausa e fine.
                                continua();
                                break;
                            }

                            default:{

                                // Comunico scelta non valida.
                                printf("\nScelta opzione non valida, per favore riprovare!");

                                break;
                            }
                        }

                    } else {

                        // Comunico prodotto non trovato.
                        printf("\nProdotto non trovato, annullando operazione!");
                        continua();
                        break;
                    }

                } else {

                    // Comunico che il magazzino non esiste.
                    printf("\nIl FILE magazzino.txt non esiste, per favore crearne uno con le opzioni.");

                }

                break;
            }

            case 4:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Eliminazione prodotto dal magazzino...\n");

                // Variabili e chiedo input utente.
                string nomeProdotto;
                printf("\nInserire nome prodotto: ");
                cin.ignore();
                getline(cin, nomeProdotto);
                nomeProdotto = sostituisciSpaziConTrattini(nomeProdotto);

                // Apro magazzino in modalita' lettura e verifico la presenza del FILE.
                magazzino = fopen("magazzino.txt", "r");
                if (magazzino != NULL){

                    // Riga in lettura per trovare la posizione.
                    int rigaDaEliminare = 0;

                    // Creo struct dove metto, per ordine e semplicita', i valori letti e anche le varie variabili per la lettura.
                    struct prodottoMagazzino prodottoLetto{};
                    char categoria[100];
                    char nome[100];
                    int rigaLettura = 0;
                    while (!feof(magazzino)){
                        fscanf(magazzino, "%s %s %lf %d", categoria, nome, &prodottoLetto.prezzo, &prodottoLetto.quantita);
                        prodottoLetto.categoria = categoria;
                        prodottoLetto.nomeProdotto = nome;
                        if (prodottoLetto.nomeProdotto == nomeProdotto){
                            rigaDaEliminare = rigaLettura;

                            // Log.
                            if (logEsiste()){
                                modifiche = fopen("modifiche.txt", "a");
                                fprintf(modifiche, "%s", "\n");
                                fprintf(modifiche, "%s %s %s %lf %d %s", "Eliminato", prodottoLetto.categoria.c_str(), prodottoLetto.nomeProdotto.c_str(), prodottoLetto.prezzo, prodottoLetto.quantita, dataTempo().c_str());
                            } else {
                                modifiche = fopen("modifiche.txt", "w");
                                fprintf(modifiche, "%s %s %s %lf %d %s", "Eliminato", prodottoLetto.categoria.c_str(), prodottoLetto.nomeProdotto.c_str(), prodottoLetto.prezzo, prodottoLetto.quantita, dataTempo().c_str());
                            }
                            fclose(modifiche);
                        }
                        rigaLettura++;
                    }
                    fclose(magazzino);

                    // Verifico RIGA da eliminare, se 0 non e' stata trovata.
                    if (rigaDaEliminare != 0){

                        // Apro i FILEs.
                        FILE *temporaneo = fopen("temp.txt", "w");
                        magazzino = fopen("magazzino.txt", "r");

                        // Leggo l'intero magazzino e copio i valori con quello modificato, poi chiudo e cancello e rinomino.
                        int rigaInLettura = 0;
                        while (!feof(magazzino)){
                            fscanf(magazzino, "%s %s %lf %d", categoria, nome, &prodottoLetto.prezzo, &prodottoLetto.quantita);
                            prodottoLetto.categoria = categoria;
                            prodottoLetto.nomeProdotto = nome;
                            if (rigaInLettura != rigaDaEliminare){
                                if (rigaInLettura != 0){
                                    fprintf(temporaneo, "%s", "\n");
                                }
                                fprintf(temporaneo, "%s %s %lf %d", prodottoLetto.categoria.c_str(), prodottoLetto.nomeProdotto.c_str(), prodottoLetto.prezzo, prodottoLetto.quantita);
                            }
                            rigaInLettura++;
                        }
                        fclose(magazzino);
                        fclose(temporaneo);
                        remove("magazzino.txt");
                        rename("temp.txt", "magazzino.txt");

                        // Messaggio di successo.
                        printf("\nProdotto eliminato con successo!");

                    } else {

                        // Messaggio prodotto non trovato.
                        printf("\nProdotto non trovato, operazione annullata!");

                    }


                } else {
                    
                    // Il Magazzino non esiste.
                    printf("\nNon esiste un FILE magazzino.txt, usa le altre opzioni per crearne uno e aggiungerci prodotti!");
                }

                // Pausa e fine.
                continua();
                break;
            }

            case 5:{

                // Messaggio dell'inizio.
                printf("\nHai scelto: Leggi contenuto intero magazzino...\n");

                // Verifico se il magazzino esiste.
                if (magazzinoEsiste()){

                    // Apro il magazzino in modalita' di sola lettura.
                    magazzino = fopen("magazzino.txt", "r");

                    // Output.
                    printf("\nMagazzino: "
                           "\nCategoria \tNome \tPrezzo \tDisponibilita'");
                    while (!feof(magazzino)){
                        char categoriaLetta[100];
                        char nomeLetto[100];
                        double prezzo;
                        int quantita;

                        fscanf(magazzino, "%s %s %lf %d", categoriaLetta, nomeLetto, &prezzo, &quantita);
                        printf("\n%s \t%s \t%2.f \t%d", sostituisciTrattiniConSpazi(categoriaLetta).c_str(), sostituisciTrattiniConSpazi(nomeLetto).c_str(), prezzo, quantita);
                    }

                } else {

                    // IL magazzino non esiste quindi errore.
                    printf("\nNon e' stato trovato il file magazzino.txt, creano uno e aggiungici dei prodotti usando le varie opzioni!");

                }

                // Pausa e fine.
                continua();
                break;
            }

            case 6:{

                // Messaggio d'inizio.
                printf("\nHai scelto: Leggi prodotti appartenenti a una categoria...\n");

                // Chiedo input.
                string nomeCategoria;
                printf("\nInserire nome categoria: ");
                cin.ignore();
                getline(cin, nomeCategoria);
                nomeCategoria = sostituisciSpaziConTrattini(nomeCategoria);

                // Verifico che il magazzino esista.
                if (magazzinoEsiste()){

                    // Apro il magazzino in modalita' lettura.
                    magazzino = fopen("magazzino.txt", "r");

                    // Output.
                    int numeroLetti = 0;
                    printf("\nMagazzino: "
                           "\nCategoria \tNome \tPrezzo \tDisponibilita'");
                    while (!feof(magazzino)){
                        char categoriaLetta[100];
                        char nomeLetto[100];
                        double prezzo;
                        int quantita;

                        // Leggo.
                        fscanf(magazzino, "%s %s %lf %d", categoriaLetta, nomeLetto, &prezzo, &quantita);

                        // Se la categoria corrisponde, allora scrivo in output.
                        if (categoriaLetta == nomeCategoria) {
                            numeroLetti++;
                            printf("\n%s \t%s \t%2.f \t%d", sostituisciTrattiniConSpazi(categoriaLetta).c_str(), sostituisciTrattiniConSpazi(nomeLetto).c_str(), prezzo, quantita);
                        }
                    }

                    // Se non sono stati trovati prodotti nella categoria specificata allora mando messaggio di errore non trovato.
                    if (numeroLetti == 0){
                        printf("\nNon sono stati trovati prodotti in questa categoria!");
                    }

                } else {

                    // Non esiste un magazzino quindi errore.
                    printf("\nNon e' stato trovato il file magazzino.txt, creano uno e aggiungici dei prodotti usando le varie opzioni!");

                }

                // Pausa e fine.
                continua();
                break;
            }

            case 7:{

                // Messaggio di inizio.
                printf("\nHai scelto: Vendita prodotto...");

                if (magazzinoEsiste()){
                    int numeroProdottiDisp = 0;

                    magazzino = fopen("magazzino.txt", "r");

                    printf("\n\nProdotti disponibili: "
                           "\nNome:   -   Prezzo:   -   Quantita':");
                    char categoriaLetta[100];
                    char nomeLetto[100];
                    double prezzoLetto;
                    int disponibilita;
                    string nomeLettoString;
                    while (!feof(magazzino)){

                        fscanf(magazzino, "%s %s %lf %d", categoriaLetta, nomeLetto, &prezzoLetto, &disponibilita);

                        if (disponibilita != 0) {
                            nomeLettoString = sostituisciTrattiniConSpazi(nomeLetto);
                            printf("\n%s   -   %lf   -   %d", nomeLettoString.c_str(), prezzoLetto, disponibilita);

                            numeroProdottiDisp++;
                        }
                    }

                    fclose(magazzino);

                    if (numeroProdottiDisp == 0){

                        printf("Non sono disponibili prodotti nel magazzino!");
                        break;
                    }
                } else {

                    printf("\nNon esiste un magazzino.txt, per favore creane uno e aggiungici dei prodotti.");
                    break;
                }

                // Chiedo input.
                printf("\n\nInserire nome prodotto: ");
                cin.ignore();
                getline(cin, prodotto.nomeProdotto);
                prodotto.nomeProdotto = sostituisciSpaziConTrattini(prodotto.nomeProdotto);

                // Chiedo input.
                printf("\nInserire Quantita': ");
                cin >> prodotto.quantita;

                // Chiedo input.
                int sconto;
                printf("\nInserire percentuale sconto: ");
                scanf("%d", &sconto);
                
                
                int quantitaVenduta = prodotto.quantita;


                // Cerca quantita precedente del prodotto nel magazzino.
                int quantitaPrecedente = 0;
                int numeroRigaFinale = 0;
                bool scrittoModifiche = false;
                if (magazzinoEsiste()){

                    magazzino = fopen("magazzino.txt","r");

                    struct prodottoMagazzino prodottoLetto{};
                    char categoria[100];
                    char nomeProdotto[100];
                    int numeroRiga = 0;
                    while (!feof(magazzino)){
                        numeroRiga++;
                        fscanf(magazzino, "%s %s %lf %d", categoria, nomeProdotto, &prodottoLetto.prezzo, &prodottoLetto.quantita);
                        prodottoLetto.categoria = categoria;
                        prodottoLetto.nomeProdotto = nomeProdotto;

                        if (prodottoLetto.nomeProdotto == prodotto.nomeProdotto){
                            quantitaPrecedente = prodottoLetto.quantita;
                            prodotto.categoria = prodottoLetto.categoria;
                            prodotto.prezzo = prodottoLetto.prezzo;
                            numeroRigaFinale = numeroRiga;

                            if (prodottoLetto.quantita - prodotto.quantita < 0){

                                printf("\nNon sono disponibili abbastanza prodotti! Operazione annullata!");
                                fclose(magazzino);
                                break;
                            }

                            // Log.
                            if (logEsiste()){
                                modifiche = fopen("modifiche.txt", "a");
                                fprintf(modifiche, "%s", "\n");
                                fprintf(modifiche, "%s %s %s %lf %d %s", "Venduto", prodottoLetto.categoria.c_str(), prodottoLetto.nomeProdotto.c_str(), prodottoLetto.prezzo - (prodottoLetto.prezzo / 100 * sconto), prodotto.quantita, dataTempo().c_str());
                                scrittoModifiche = true;
                            } else {
                                modifiche = fopen("modifiche.txt", "w");
                                fprintf(modifiche, "%s %s %s %lf %d %s", "Venduto", prodottoLetto.categoria.c_str(), prodottoLetto.nomeProdotto.c_str(), prodottoLetto.prezzo - (prodottoLetto.prezzo / 100 * sconto), prodotto.quantita, dataTempo().c_str());
                                scrittoModifiche = true;
                            }
                            fclose(modifiche);
                        }
                    }
                    fclose(magazzino);
                } else {

                    printf("\nNon esiste un magazzino.txt, creano uno e aggiungici dei prodotti con le varie opzioni!");

                    break;
                }
                // Somma quantita precedenta a quella nuova perche' stiamo aggiungendo
                prodotto.quantita = quantitaPrecedente - prodotto.quantita;

                if (!scrittoModifiche){

                    printf("\nProdotto non trovato, operazione annullata");
                    break;
                }

                if (magazzinoEsiste()){

                    if (numeroRigaFinale != 0) {
                        FILE *temporaneo = fopen("temp.txt", "w");
                        magazzino = fopen("magazzino.txt", "r");

                        int numeroLettura = 0;
                        while (!feof(magazzino)) {
                            if (numeroLettura != 0) {
                                fprintf(temporaneo, "%s", "\n");
                            }
                            numeroLettura++;
                            char categoria[100];
                            char nome[100];
                            double prezzo;
                            int quantita;
                            fscanf(magazzino, "%s %s %lf %d", categoria, nome, &prezzo, &quantita);
                            if (numeroLettura == numeroRigaFinale) {
                                fprintf(temporaneo, "%s %s %lf %d", prodotto.categoria.c_str(),
                                        prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);
                            } else {
                                fprintf(temporaneo, "%s %s %lf %d", categoria, nome, prezzo, quantita);
                            }
                        }
                        fclose(temporaneo);
                        fclose(magazzino);
                        remove("magazzino.txt");
                        rename("temp.txt", "magazzino.txt");
                    } else {

                        magazzino = fopen("magazzino.txt", "a");
                        fprintf(magazzino, "%s", "\n");
                        fprintf(magazzino, "%s %s %lf %d", prodotto.categoria.c_str(),
                                prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);
                        fclose(magazzino);

                    }

                } else {

                    magazzino = fopen("magazzino.txt", "w");
                    fprintf(magazzino, "%s %s %lf %d", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);
                }
                fclose(magazzino);

                printf("\nOperazione prodotto effettuata con successo!"
                       "\nRiepilogo operazione:"
                       "\n- Categoria prodotto: %s"
                       "\n- Nome prodotto: %s"
                       "\n- Prezzo unitario: %2.f Euro"
                       "\n- Prezzo totale: %2.f Euro"
                       "\n- Disponibilita' venduta: %d"
                       "\n- Disponibilita' rimanente: %d", sostituisciTrattiniConSpazi(prodotto.categoria).c_str(),
                       sostituisciTrattiniConSpazi(prodotto.nomeProdotto).c_str(), prodotto.prezzo - (prodotto.prezzo / 100 * sconto), (prodotto.prezzo - (prodotto.prezzo / 100 * sconto)) * quantitaVenduta, quantitaVenduta, prodotto.quantita);

                continua();
                break;
            }

            case 8:{

                printf("\nHai scelto: Imprevisto prodotto...");

                printf("\nInserire nome prodotto: ");
                cin >> prodotto.nomeProdotto;

                if (magazzinoEsiste()){

                    int posizioneTrovato = 0;
                    int posizioneInLettura = 0;
                    char categoria[100];
                    char nome[100];
                    struct prodottoMagazzino prodottoLetto{};
                    magazzino = fopen("magazzino.txt", "r");

                    while (!feof(magazzino)){
                        posizioneInLettura++;
                        fscanf(magazzino, "%s %s %lf %d", categoria, nome, &prodottoLetto.prezzo, &prodottoLetto.quantita);
                        if(nome == prodotto.nomeProdotto){
                            prodotto.categoria = categoria;
                            prodotto.prezzo = prodottoLetto.prezzo;
                            prodotto.quantita = prodottoLetto.quantita;
                            posizioneTrovato = posizioneInLettura;
                        }
                    }
                    fclose(magazzino);

                    if (posizioneTrovato != 0){

                        struct prodottoMagazzino prodottoPrecedente{prodotto.categoria, prodotto.nomeProdotto, prodotto.prezzo, prodotto.quantita};
                        int sceltaOperazione;

                         printf("\nScegli operazione da fare: "
                                "\n0 -> Esci."
                                "\n1 -> Decrementa prodotto e aggiungi nota."
                                "\n2 -> Incrementa prodotto e aggiungi nota."
                                "\nScelta: ");
                         scanf("%d", &sceltaOperazione);

                         switch (sceltaOperazione) {

                             case 0: {

                                 printf("\nHai scelto: Annulla operazione...");

                                 break;
                             }

                             case 1:{

                                 printf("\nHai scelto: Decrementa prodotto e aggiungi nota...");

                                 int quantitaLetta;
                                 printf("\nInserire Disponibilita' da decrementare: ");
                                 scanf("%d", &quantitaLetta);

                                 if (quantitaLetta <= prodotto.quantita){

                                     prodotto.quantita -= quantitaLetta;

                                     string nota;
                                     printf("\nInserire nota: ");
                                     cin.ignore();
                                     getline(cin, nota);
                                     nota = sostituisciSpaziConTrattini(nota);

                                     FILE *temp = fopen("temp.txt", "w");
                                     magazzino = fopen("magazzino.txt", "r");

                                     posizioneInLettura = 0;
                                     while (!feof(magazzino)){
                                         if (posizioneInLettura != 0){
                                             fprintf(temp, "%s", "\n");
                                         }
                                         posizioneInLettura++;
                                         fscanf(magazzino, "%s %s %lf %d", categoria, nome, &prodottoLetto.prezzo, &prodottoLetto.quantita);
                                         if (posizioneTrovato != posizioneInLettura){
                                             fprintf(temp, "%s %s %lf %d", categoria, nome, prodottoLetto.prezzo, prodottoLetto.quantita);
                                         } else {
                                             fprintf(temp, "%s %s %lf %d", prodotto.categoria.c_str(),
                                                     prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);
                                         }
                                     }
                                     fclose(magazzino);
                                     fclose(temp);
                                     remove("magazzino.txt");
                                     rename("temp.txt", "magazzino.txt");

                                     printf("\nOperazione effettuata con successo!");
                                     string notaOp = sostituisciSpaziConTrattini("Venduto" + nota);

                                     // Log.
                                     if (logEsiste()) {

                                         modifiche = fopen("modifiche.txt", "a");
                                         fprintf(modifiche, "%s", "\n");
                                         fprintf(modifiche, "%s %s %s %lf %d %s", notaOp.c_str(), prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), -prodotto.prezzo, prodotto.quantita, dataTempo().c_str());


                                     } else {

                                         modifiche = fopen("modifiche.txt", "w");
                                         fprintf(modifiche, "%s %s %s %lf %d %s", notaOp.c_str(), prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), -prodotto.prezzo, prodotto.quantita, dataTempo().c_str());
                                     }
                                     fclose(modifiche);

                                 } else {

                                     printf("\nHai scelto una Disponibilita' non valida, annullando operazione...");
                                     continua();
                                     break;
                                 }

                                 continua();
                                 break;
                             }

                             case 2:{

                                 printf("\nHai scelto: Decrementa e aggiunti nota...");

                                 int quantitaLetta;
                                 printf("\nInserire Disponibilita' da incrementare: ");
                                 scanf("%d", &quantitaLetta);

                                 prodotto.quantita += quantitaLetta;

                                 string nota;
                                 printf("\nInserire nota: ");
                                 cin.ignore();
                                 getline(cin, nota);
                                 nota = sostituisciSpaziConTrattini(nota);

                                 FILE *temp = fopen("temp.txt", "w");
                                 magazzino = fopen("magazzino.txt", "r");

                                 posizioneInLettura = 0;
                                 while (!feof(magazzino)){
                                     if (posizioneInLettura != 0){
                                         fprintf(temp, "%s", "\n");
                                     }
                                     posizioneInLettura++;
                                     fscanf(magazzino, "%s %s %lf %d", categoria, nome, &prodottoLetto.prezzo, &prodottoLetto.quantita);
                                     if (posizioneTrovato != posizioneInLettura){
                                         fprintf(temp, "%s %s %lf %d", categoria, nome, prodottoLetto.prezzo, prodottoLetto.quantita);
                                     } else {
                                         fprintf(temp, "%s %s %lf %d", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);
                                     }
                                 }
                                 fclose(magazzino);
                                 fclose(temp);
                                 remove("magazzino.txt");
                                 rename("temp.txt", "magazzino.txt");

                                 printf("\nOperazione effettuata con successo!");
                                 string notaOp = "Aggiunto";

                                 // Log.
                                 if (logEsiste()){

                                     modifiche = fopen("modifiche.txt", "a");
                                     fprintf(modifiche, "%s", "\n");
                                     fprintf(modifiche, "%s %s %s %lf %d %s %s", notaOp.c_str(), prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, dataTempo().c_str(), nota.c_str());

                                 } else {

                                     modifiche = fopen("modifiche.txt", "w");
                                     fprintf(modifiche, "%s %s %s %lf %d %s %s", notaOp.c_str(), prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, dataTempo().c_str(), nota.c_str());

                                 }
                                 fclose(modifiche);
                                 break;
                             }

                             default:{

                                 printf("\nScelta non valida, per favore riprovare!");

                                 continua();
                                 break;
                             }
                         }

                    } else {

                        printf("\nIl prodotto %s non e' stato trovato, annullando operazione!", prodotto.nomeProdotto.c_str());
                        continua();
                        break;
                    }

                } else {
                    printf("\nNon esiste un magazzino.txt, per favore creane uno con le varie opzioni!");
                }

                printf("\n\nOperazione terminata!");

                continua();
                break;
            }

            case 9:{

                printf("\nHai scelto: Leggi informazioni prodotto...");
                printf("\nInserire nome prodotto: ");
                cin.ignore();
                getline(cin, prodotto.nomeProdotto);
                prodotto.nomeProdotto = sostituisciSpaziConTrattini(prodotto.nomeProdotto);

                if (magazzinoEsiste()){

                    magazzino = fopen("magazzino.txt", "r");

                    bool successo = false;
                    char categoriaLetta[100];
                    char nomeLetto[100];
                    while (!feof(magazzino)){
                        fscanf(magazzino, "%s %s %lf %d", categoriaLetta, nomeLetto, &prodotto.prezzo, &prodotto.quantita);
                        if (prodotto.nomeProdotto == nomeLetto){
                            printf("\nInformazioni prodotto: "
                                   "\nCategoria: %s"
                                   "\nNome: %s"
                                   "\nPrezzo: %2.f Euro"
                                   "\nDisponibilita': %d", sostituisciTrattiniConSpazi(categoriaLetta).c_str(),
                                   sostituisciTrattiniConSpazi(nomeLetto).c_str(), prodotto.prezzo, prodotto.quantita);
                            fclose(magazzino);
                            successo = true;
                            break;
                        }
                    }

                    if (!successo) {
                        printf("\nProdotto non trovato!");
                    }

                } else {

                    printf("\nIl FILE magazzino.txt non esiste, creane uno con le varie opzioni!");

                }

                continua();
                break;
            }

            case 10:{

                printf("\nHai scelto: Operazioni con i log...");

                if (logEsiste()){

                    int sceltaLog = 1;

                    while (sceltaLog != 0){

                        printf("\n\nLegenda opzioni: "
                               "\n0 -> Esci."
                               "\n1 -> Cancella FILE dei log e creane uno nuovo."
                               "\n2 -> Leggi intero FILE dei log."
                               "\n3 -> Resoconto per operazione Venduto."
                               "\n4 -> Resoconto per operazione Aggiunto."
                               "\nScelta: ");
                        scanf("%d", &sceltaLog);

                        switch (sceltaLog) {

                            case 0:{

                                printf("\nHai scelto: Esci..."
                                       "\nUscita dai log completata con successo!");

                                break;
                            }

                            case 1:{

                                printf("\nHai scelto: Cancella FILE dei log...");

                                int conferma;
                                printf("\nInserire 0 per annullare, un numero a caso per confermare: ");
                                scanf("%d", &conferma);

                                if (conferma != 0){

                                    remove("modifiche.txt");

                                    modifiche = fopen("modifiche.txt", "w");
                                    fclose(modifiche);

                                    printf("\nFILE dei log cancellato con successo! Creato uno nuovo vuoto.");

                                } else {

                                    printf("\nIl FILE dei log non e' stato cancellato, operazione annullata!\n");

                                }

                                continua();
                                break;
                            }

                            case 2:{

                                printf("\nHai scelto: Leggi intero FILE dei log...");

                                modifiche = fopen("modifiche.txt", "r");

                                printf("\n\nValori letti: ");

                                string rigaLetta;
                                char tipoOperazione[100];
                                char categoria[100];
                                char nome[100];
                                double prezzoLetto;
                                int quantitaLetta;
                                char dataLetta[100];
                                int numeroRiga = 0;
                                while (!feof(modifiche)){
                                    numeroRiga++;
                                    fscanf(modifiche, "%s %s %s %lf %d %s", tipoOperazione, categoria, nome, &prezzoLetto, &quantitaLetta, dataLetta);

                                    printf("\n%d -> %s %s %s %lf %d %s", numeroRiga, sostituisciTrattiniConSpazi(tipoOperazione).c_str(),
                                           sostituisciTrattiniConSpazi(categoria).c_str(), sostituisciTrattiniConSpazi(nome).c_str(), prezzoLetto, quantitaLetta,
                                           sostituisciTrattiniConSpazi(dataLetta).c_str());
                                }
                                fclose(modifiche);

                                continua();
                                break;
                            }

                            case 3:{

                                printf("\nHai scelto: Resoconto Venduto...");

                                resocontoPerTipo(modifiche, "Venduto");

                                continua();
                                break;
                            }

                            case 4:{

                                printf("\nHai scelto: Resoconto aggiunte...");

                                resocontoPerTipo(modifiche, "Aggiunto");

                                continua();
                                break;
                            }

                            default:{

                                printf("\nHai fatto una scelta non valida, per favore riprovare!");

                                break;
                            }
                        }

                    }

                } else {

                    printf("\nNon e' stato trovato un file dei LOG di nome modifiche.txt.");
                    continua();
                }

                break;
            }

            case 11:{

                printf("\nHai scelto: Resetta quantita' intero magazzino...\n");

                if (magazzinoEsiste()){

                    printf("\nSei sicuro di voler resettare le quantita' dell'intero magazzino?"
                           "\n0 -> Annulla."
                           "\nQualsiasi altro numero conferma."
                           "\nScelta: ");

                    int valoreLetto;
                    scanf("%d", &valoreLetto);

                    if (valoreLetto != 0){

                        printf("\nOperazione iniziata...");

                        magazzino = fopen("magazzino.txt", "r");
                        FILE *temp = fopen("temp.txt", "w");

                        char categoriaLetta[100];
                        char nomeLetto[100];

                        int numeroCopiata = 0;
                        while (!feof(magazzino)){
                            if (numeroCopiata != 0){
                                fprintf(temp, "%s", "\n");
                            }

                            fscanf(magazzino, "%s %s %lf %d", categoriaLetta, nomeLetto, &prodotto.prezzo, &prodotto.quantita);

                            fprintf(temp, "%s %s %lf %d", categoriaLetta, nomeLetto, prodotto.prezzo, 0);

                            numeroCopiata++;
                        }
                        fclose(magazzino);
                        fclose(temp);
                        remove("magazzino.txt");
                        rename("temp.txt", "magazzino.txt");

                        printf("\nOperazione completata con successo!");

                        // Tipo di modifica effettuata
                        string tagModifica = "Reset-Quantita'";
                        if (logEsiste()){

                            // Apro il FILE log in modalita' append.
                            modifiche = fopen("modifiche.txt", "a");
                            fprintf(modifiche, "%s", "\n");
                            fprintf(modifiche, "%s %s %s %lf %d %s", tagModifica.c_str(), "reset", "reset", 0.00, 0, dataTempo().c_str());

                        } else {

                            // Apro il FILE log in modalita' di scrittura.
                            modifiche = fopen("modifiche.txt", "w");
                            fprintf(modifiche, "%s %s %s %lf %d %s", tagModifica.c_str(), "reset", "reset", 0.00, 0, dataTempo().c_str());

                        }
                        fclose(modifiche);

                    } else {

                        printf("\nOperazione annullata!");

                    }

                } else {

                    printf("\nIl magazzino.txt non esiste, per favore crearne uno aggiungendo un prodotto prima o inizializzarlo.");

                }

                continua();
                break;
            }
            default:{

                printf("\nHai inserito una scelta non valida, per favore riprovare!");

                break;
            }

        }

    }

    printf("\nUscito con successo!");
    return 0;
}

string dataTempo() {

    // Ottengo il tempoo.
    time_t ct;
    string tempo;

    ct = time(NULL);

    struct tm * tempoStruct = localtime(&ct);


    tempo = daIntAString(tempoStruct->tm_mday) + "/" + daIntAString(tempoStruct->tm_mon + 1) + "/" + daIntAString(tempoStruct->tm_year + 1900) + "-" +
            daIntAString(tempoStruct->tm_hour) + ":" + daIntAString(tempoStruct->tm_min);
    //tempo = sostituisciSpaziConTrattini(ctime(&ct));
    return tempo;
}

string daIntAString(int numero){

    // Variabili.
    string stringaFinale;
    stringstream stringaTemp;

    // Inserisco l'int nello stringstream e poi lo stringstream nella string.
    stringaTemp << numero;
    stringaTemp >> stringaFinale;

    // Ritorno il valore.
    return stringaFinale;
}


void resocontoPerTipo(FILE *modifiche, const string &nomeOperazione) {
    modifiche = fopen("modifiche.txt", "r");

    struct prodottoMagazzino prodottoLetto{};
    struct prodottoMagazzino prodottiTrovatiInCategoria[200];
    char tipoOperazioneLetta[100];
    char categoriaLetta[100];
    char nomeLetto[100];
    char dataLetta[100];
    int numeroOper = 0;
    while (!feof(modifiche)){
        fscanf(modifiche, "%s %s %s %lf %d %s", tipoOperazioneLetta, categoriaLetta, nomeLetto, &prodottoLetto.prezzo, &prodottoLetto.quantita, dataLetta);

        string tipoOpLettaInStringa = tipoOperazioneLetta;
        if (tipoOpLettaInStringa == nomeOperazione){
            prodottiTrovatiInCategoria[numeroOper].categoria = categoriaLetta;
            prodottiTrovatiInCategoria[numeroOper].nomeProdotto = nomeLetto;
            prodottiTrovatiInCategoria[numeroOper].prezzo = prodottoLetto.prezzo;
            prodottiTrovatiInCategoria[numeroOper].quantita = prodottoLetto.quantita;
            numeroOper++;
        }
    }

    struct prodottoMagazzino singoloResoconto[200];
    int resocontiSingoliTrovati = 0;
    for (int i = 0; i < numeroOper; i++) {

        // Ricerca se gia' trovato.
        bool nonTrovato = true;
        string nomeProdotto = prodottiTrovatiInCategoria[i].nomeProdotto;
        for (int j = 0; j < resocontiSingoliTrovati; j++) {
            if (singoloResoconto[j].nomeProdotto == nomeProdotto){
                singoloResoconto[j].quantita += prodottiTrovatiInCategoria[i].quantita;
                singoloResoconto[j].prezzo += prodottiTrovatiInCategoria[i].prezzo * prodottiTrovatiInCategoria[i].quantita;
                nonTrovato = false;
            }
        }

        if (nonTrovato){
            singoloResoconto[resocontiSingoliTrovati].categoria = prodottiTrovatiInCategoria[i].categoria;
            singoloResoconto[resocontiSingoliTrovati].nomeProdotto = nomeProdotto;
            singoloResoconto[resocontiSingoliTrovati].prezzo = prodottiTrovatiInCategoria[i].prezzo * prodottiTrovatiInCategoria[i].quantita;
            singoloResoconto[resocontiSingoliTrovati].quantita = prodottiTrovatiInCategoria[i].quantita;
            resocontiSingoliTrovati++;
        }
    }


    if (numeroOper != 0 && resocontiSingoliTrovati != 0){

        printf("\n\nResoconti: ");
        double soldiTotaliTutto = 0;
        int quantitaTotaliTutto = 0;
        for (int i = 0; i < resocontiSingoliTrovati; i++) {
            printf("\n\nResoconto N.%d"
                   "\nCategoria: %s"
                   "\nNome prodotto: %s"
                   "\nDenaro totale prodotto: %2.f"
                   "\nQuantita' finale: %d", i + 1, sostituisciTrattiniConSpazi(singoloResoconto[i].categoria).c_str(),
                   sostituisciTrattiniConSpazi(singoloResoconto[i].nomeProdotto).c_str(), singoloResoconto[i].prezzo, singoloResoconto[i].quantita);
            soldiTotaliTutto += singoloResoconto[i].prezzo;
            quantitaTotaliTutto += singoloResoconto[i].quantita;
        }

        printf("\n\nTotale di tutto: "
               "\nAmmontare denaro: %2.f"
               "\nNumero %s: %d", soldiTotaliTutto, nomeOperazione.c_str(), quantitaTotaliTutto);
    } else {

        printf("\nNon sono stati %s prodotti.", nomeOperazione.c_str());

    }
    fclose(modifiche);
}

/**
 * Verifica se il FILE magazzino.txt esiste.
 * */
bool magazzinoEsiste(){

    FILE *magazzino = fopen("magazzino.txt", "r");

    if (magazzino != NULL){
        fclose(magazzino);
        return true;
    } else {
        fclose(magazzino);
        return false;
    }
}

/**
 * Verifica se il FILE modifiche.txt esiste.
 * */
bool logEsiste(){

    FILE *modifiche = fopen("modifiche.txt", "r");

    if (modifiche != NULL){
        fclose(modifiche);
        return true;
    } else {
        fclose(modifiche);
        return false;
    }
}

void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\n|--------------------------"
           "\n| Inserisci un NUMERO a caso per continuare...");
    scanf("%d", &inusato);
    printf("|--------------------------\n");

}

string sostituisciSpaziConTrattini(string stringa){

    // Per ogni carattere della stringa verifica se e' uno spazio e lo sostituisce.
    for (int i = 0; i < stringa.length(); i++) {
        if (isspace(stringa[i])){
            stringa[i] = '_';
        }
    }

    // Non supportato da vecchie versioni di C++
    /*(for(char & i : stringa) {
        if (isspace(i))
            i = '_';
    }*/

    // Ritorna nuova stringa.
    return stringa;
}

string sostituisciTrattiniConSpazi(string stringa){

    // Per ogni carattere della stringa verifica se e' un un trattino basso e lo sostituisce.
    for (int i = 0; i < stringa.length(); i++) {
        if (stringa[i] == '_'){
            stringa[i] = ' ';
        }
    }

    // Non supportato da vecchie versioni di C++
    /*for(char & i : stringa) {
        if (i == '_')
            i = ' ';
    }*/

    // Ritorna nuova stringa.
    return stringa;
}
