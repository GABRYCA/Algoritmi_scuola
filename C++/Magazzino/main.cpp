#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

void continua();
bool magazzinoEsiste();
bool logEsiste();
string sostituisciSpaziConTrattini(string stringa);
string sostituisciTrattiniConSpazi(string stringa);

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

    struct prodottoMagazzino vuoto{"", "", 0, 0};
    struct prodottoMagazzino prodotto{};
    int scelta = 1;
    FILE *magazzino;
    FILE *modifiche;

    while (scelta != 0){

        printf("\nLegenda:"
               "\n0 -> Esci dal programma."
               "\n1 -> Inizializza nuovo FILE o resetta intero magazzino."
               "\n2 -> Aggiungi prodotto."
               "\n3 -> Modifica prodotto con menu."
               "\n4 -> Elimina prodotto."
               "\n5 -> Leggi contenuto intero magazzino."
               "\n6 -> Leggi prodotto appartenenti a una categoria."
               "\n7 -> Vendita prodotto."
               "\n8 -> Imprevisto prodotto."
               "\n9 -> Leggi informazioni prodotto."
               "\n10 -> Operazioni con i log."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                // Uscita.
                printf("\nHai scelto: Esci..."
                       "\n\nUscita in corso...\n");

                break;
            }

            case 1:{

                printf("\nHai scelto: Inizializzazione FILE magazzino o reset...");

                bool esiste = magazzinoEsiste();
                int conferma;
                if (esiste){

                    printf("\nSei sicuro di voler cancellare il magazzino e crearne uno nuovo vuoto?"
                           "\n0 -> Annulla."
                           "\n1 -> Conferma."
                           "\nScelta: ");
                    scanf("%d", &conferma);

                    // Verifica input valido.
                    if (conferma != 0 && conferma != 1){

                        printf("\nHai inserito una scelta non valida, annullo operazione reset magazzino!");
                        fclose(magazzino);
                        break;

                    }

                    // Scelta annullamento.
                    if (conferma == 0){

                        printf("\nAnnullo reset magazzino!");
                        fclose(magazzino);
                        break;

                    }
                }
                fclose(magazzino);

                magazzino = fopen("magazzino.txt", "w");
                fclose(magazzino);

                time_t ct;
                ct = time(NULL);
                string tempo = sostituisciSpaziConTrattini(ctime(&ct));

                string tagModifica = "Reset";
                if (logEsiste()){

                    modifiche = fopen("modifiche.txt", "a");
                    fprintf(modifiche, "%s", "\n");
                    fprintf(modifiche, "%s %s", tagModifica.c_str(), tempo.c_str());

                } else {

                    modifiche = fopen("modifiche.txt", "w");
                    fprintf(modifiche, "%s %s", tagModifica.c_str(), tempo.c_str());

                }
                fclose(modifiche);

                printf("\nCreato con successo nuovo FILE magazzino!");

                continua();
                break;
            }

            case 2:{

                printf("\nHai scelto: Aggiungi prodotto al magazzino...\n");

                printf("\nInserire categoria: ");

                cin.ignore();
                getline(cin, prodotto.categoria);
                prodotto.categoria = sostituisciSpaziConTrattini(prodotto.categoria);

                printf("\nInserire nome prodotto: ");

                // cin.ignore();
                getline(cin, prodotto.nomeProdotto);
                prodotto.nomeProdotto = sostituisciSpaziConTrattini(prodotto.nomeProdotto);

                printf("\nInserire prezzo: ");
                cin >> prodotto.prezzo;

                printf("\nInserire Disponibilita': ");
                cin >> prodotto.quantita;


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
                            numeroRigaFinale = numeroRiga;

                            printf("\nIl prodotto esiste gia', incrementando Disponibilita' totale in base al numero dato e quello salvato in precedenza.");

                            time_t ct;
                            ct = time(NULL);
                            string tempo = sostituisciSpaziConTrattini(ctime(&ct));
                            if (logEsiste()){
                                modifiche = fopen("modifiche.txt", "a");
                                fprintf(modifiche, "%s", "\n");
                                fprintf(modifiche, "%s %s %s %lf %d %s %s %lf %d %s", "Aggiunto", prodottoLetto.categoria.c_str(), prodottoLetto.nomeProdotto.c_str(), prodottoLetto.prezzo, prodottoLetto.quantita, prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodottoLetto.quantita + prodotto.quantita, tempo.c_str());
                                scrittoModifiche = true;
                            } else {
                                modifiche = fopen("modifiche.txt", "w");
                                fprintf(modifiche, "%s %s %s %lf %d %s %s %lf %d %s", "Aggiunto", prodotto.categoria.c_str(), prodottoLetto.nomeProdotto.c_str(), prodotto.prezzo, prodottoLetto.quantita, prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita + prodotto.quantita, tempo.c_str());
                                scrittoModifiche = true;
                            }
                            fclose(modifiche);
                        }
                    }
                    fclose(magazzino);
                }
                // Somma quantita precedenta a quella nuova perche' stiamo aggiungendo
                prodotto.quantita = quantitaPrecedente + prodotto.quantita;

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

                if (!scrittoModifiche){
                    time_t ct;
                    ct = time(NULL);
                    string tempo = sostituisciSpaziConTrattini(ctime(&ct));
                    if (logEsiste()){
                        modifiche = fopen("modifiche.txt", "a");
                        fprintf(modifiche, "%s", "\n");
                        fprintf(modifiche, "%s %s %s %lf %d %s", "Aggiunto", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, tempo.c_str());
                    } else {
                        modifiche = fopen("modifiche.txt", "w");
                        fprintf(modifiche, "%s %s %s %lf %d %s", "Aggiunto", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, tempo.c_str());
                    }
                    fclose(modifiche);
                }

                printf("\nOperazione prodotto effettuata con successo!");

                continua();
                break;
            }

            case 3:{

                printf("\nHai scelto: Modifica prodotto magazzino...\n");

                printf("\nInserire nome prodotto: ");
                cin.ignore();
                getline(cin, prodotto.nomeProdotto);
                prodotto.nomeProdotto = sostituisciSpaziConTrattini(prodotto.nomeProdotto);

                if (magazzinoEsiste()){

                    magazzino = fopen("magazzino.txt", "r");

                    int rigaPosizione = 0;
                    struct prodottoMagazzino prodottoLetto{};
                    char categoriaLetta[100];
                    char nomeLetto[100];
                    int rigaInLettura = 0;
                    while (!feof(magazzino)){
                        rigaInLettura++;
                        fscanf(magazzino, "%s %s %lf %d", categoriaLetta, nomeLetto, &prodottoLetto.prezzo, &prodottoLetto.quantita);

                        if (nomeLetto == prodotto.nomeProdotto){
                            rigaPosizione = rigaInLettura;
                            prodotto.categoria = categoriaLetta;
                            prodotto.prezzo = prodottoLetto.prezzo;
                            prodotto.quantita = prodottoLetto.quantita;
                        }
                    }
                    fclose(magazzino);

                    if (rigaPosizione != 0){

                        struct prodottoMagazzino vecchiDati{prodotto.categoria, prodotto.nomeProdotto, prodotto.prezzo, prodotto.quantita};
                        int sceltaOperazione;

                        printf("\nInformazioni attuali prodotto: "
                               "\nCategoria: %s"
                               "\nNome: %s"
                               "\nPrezzo: %2.f Euro"
                               "\nDisponibilita': %d\n", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita);

                        printf("\nOperazioni possibili: "
                               "\n 0 -> Esci."
                               "\n 1 -> Modifica categoria."
                               "\n 2 -> Modifica nome."
                               "\n 3 -> Modifica prezzo."
                               "\n 4 -> Modifica Disponibilita'."
                               "\nScelta: ");
                        scanf("%d", &sceltaOperazione);


                        switch (sceltaOperazione) {

                            case 0:{

                                printf("\nHai scelto: Esci...");

                                break;
                            }

                            case 1:{

                                printf("\nHai scelto: Modifica categoria...");

                                printf("\nInserire nuovo nome categoria: ");
                                cin.ignore();
                                getline(cin, prodotto.categoria);
                                prodotto.categoria = sostituisciSpaziConTrattini(prodotto.categoria);

                                FILE *temp = fopen("temp.txt", "w");
                                magazzino = fopen("magazzino.txt", "r");

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

                                printf("\nOperazione effettuata con successo!");

                                time_t ct;
                                ct = time(NULL);
                                string tempo = sostituisciSpaziConTrattini(ctime(&ct));
                                if (logEsiste()){

                                    modifiche = fopen("modifiche.txt", "a");
                                    fprintf(modifiche, "%s", "\n");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Categoria", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, tempo.c_str());

                                } else {

                                    modifiche = fopen("modifiche.txt", "w");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Categoria", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, tempo.c_str());

                                }
                                fclose(modifiche);

                                continua();
                                break;
                            }

                            case 2:{

                                printf("\nHai scelto: Modifica nome...");

                                printf("\nInserire nuovo nome prodotto: ");
                                cin.ignore();
                                getline(cin, prodotto.nomeProdotto);
                                prodotto.nomeProdotto = sostituisciSpaziConTrattini(prodotto.nomeProdotto);

                                FILE *temp = fopen("temp.txt", "w");
                                magazzino = fopen("magazzino.txt", "r");

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

                                printf("\nOperazione effettuata con successo!");

                                time_t ct;
                                ct = time(NULL);
                                string tempo = sostituisciSpaziConTrattini(ctime(&ct));
                                if (logEsiste()){

                                    modifiche = fopen("modifiche.txt", "a");
                                    fprintf(modifiche, "%s", "\n");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Nome", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, tempo.c_str());

                                } else {

                                    modifiche = fopen("modifiche.txt", "w");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Nome", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, tempo.c_str());

                                }
                                fclose(modifiche);

                                continua();
                                break;
                            }

                            case 3:{

                                printf("\nHai scelto: Modifica prezzo...");

                                printf("\nInserire nuovo prezzo prodotto: ");
                                scanf("%lf", &prodotto.prezzo);

                                FILE *temp = fopen("temp.txt", "w");
                                magazzino = fopen("magazzino.txt", "r");

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

                                printf("\nOperazione effettuata con successo!");

                                time_t ct;
                                ct = time(NULL);
                                string tempo = sostituisciSpaziConTrattini(ctime(&ct));
                                if (logEsiste()){

                                    modifiche = fopen("modifiche.txt", "a");
                                    fprintf(modifiche, "%s", "\n");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Prezzo", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, tempo.c_str());

                                } else {

                                    modifiche = fopen("modifiche.txt", "w");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Prezzo", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, tempo.c_str());

                                }
                                fclose(modifiche);

                                continua();
                                break;
                            }

                            case 4:{

                                printf("\nHai scelto: Modifica Disponibilita'...");

                                printf("\nInserire nuova Disponibilita' prodotto: ");
                                scanf("%d", &prodotto.quantita);

                                FILE *temp = fopen("temp.txt", "w");
                                magazzino = fopen("magazzino.txt", "r");

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

                                printf("\nOperazione effettuata con successo!");

                                time_t ct;
                                ct = time(NULL);
                                string tempo = sostituisciSpaziConTrattini(ctime(&ct));
                                if (logEsiste()){

                                    modifiche = fopen("modifiche.txt", "a");
                                    fprintf(modifiche, "%s", "\n");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Aggiunto", vecchiDati.categoria.c_str(), vecchiDati.nomeProdotto.c_str(), vecchiDati.prezzo, vecchiDati.quantita + prodotto.quantita, tempo.c_str());

                                } else {

                                    modifiche = fopen("modifiche.txt", "w");
                                    fprintf(modifiche, "%s %s %s %lf %d %s", "Aggiunto", vecchiDati.categoria.c_str(), vecchiDati.nomeProdotto.c_str(), vecchiDati.prezzo, vecchiDati.quantita + prodotto.quantita, tempo.c_str());

                                }
                                fclose(modifiche);

                                continua();
                                break;
                            }

                            default:{

                                printf("\nScelta opzione non valida, per favore riprovare!");

                                break;
                            }
                        }

                    } else {

                        printf("\nProdotto non trovato, annullando operazione!");
                        continua();
                        break;
                    }

                } else {

                    printf("\nIl FILE magazzino.txt non esiste, per favore crearne uno con le opzioni.");

                }

                break;
            }

            case 4:{

                printf("\nHai scelto: Eliminazione prodotto dal magazzino...\n");

                string nomeProdotto;
                printf("\nInserire nome prodotto: ");
                cin.ignore();
                getline(cin, nomeProdotto);
                nomeProdotto = sostituisciSpaziConTrattini(nomeProdotto);

                magazzino = fopen("magazzino.txt", "r");
                if (magazzino != NULL){

                    int rigaDaEliminare = 0;

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

                            time_t ct;
                            ct = time(NULL);
                            string tempo = sostituisciSpaziConTrattini(ctime(&ct));
                            if (logEsiste()){
                                modifiche = fopen("modifiche.txt", "a");
                                fprintf(modifiche, "%s", "\n");
                                fprintf(modifiche, "%s %s %s %lf %d %s", "Eliminato", prodottoLetto.categoria.c_str(), prodottoLetto.nomeProdotto.c_str(), prodottoLetto.prezzo, prodottoLetto.quantita, tempo.c_str());
                            } else {
                                modifiche = fopen("modifiche.txt", "w");
                                fprintf(modifiche, "%s %s %s %lf %d %s", "Eliminato", prodottoLetto.categoria.c_str(), prodottoLetto.nomeProdotto.c_str(), prodottoLetto.prezzo, prodottoLetto.quantita, tempo.c_str());
                            }
                            fclose(modifiche);
                        }
                        rigaLettura++;
                    }
                    fclose(magazzino);

                    if (rigaDaEliminare != 0){

                        FILE *temporaneo = fopen("temp.txt", "w");
                        magazzino = fopen("magazzino.txt", "r");

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

                        printf("\nProdotto eliminato con successo!");

                    } else {

                        printf("\nProdotto non trovato, operazione annullata!");

                    }


                } else {
                    printf("\nNon esiste un FILE magazzino.txt, usa le altre opzioni per crearne uno e aggiungerci prodotti!");
                }

                continua();
                break;
            }

            case 5:{

                printf("\nHai scelto: Leggi contenuto intero magazzino...\n");

                if (magazzinoEsiste()){

                    magazzino = fopen("magazzino.txt", "r");

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

                    printf("\nNon e' stato trovato il file magazzino.txt, creano uno e aggiungici dei prodotti usando le varie opzioni!");

                }

                continua();
                break;
            }

            case 6:{

                printf("\nHai scelto: Leggi prodotti appartenenti a una categoria...\n");

                string nomeCategoria;
                printf("\nInserire nome categoria: ");
                cin.ignore();
                getline(cin, nomeCategoria);
                nomeCategoria = sostituisciSpaziConTrattini(nomeCategoria);

                if (magazzinoEsiste()){

                    magazzino = fopen("magazzino.txt", "r");

                    int numeroLetti = 0;
                    printf("\nMagazzino: "
                           "\nCategoria \tNome \tPrezzo \tDisponibilita'");
                    while (!feof(magazzino)){
                        char categoriaLetta[100];
                        char nomeLetto[100];
                        double prezzo;
                        int quantita;

                        fscanf(magazzino, "%s %s %lf %d", categoriaLetta, nomeLetto, &prezzo, &quantita);

                        if (categoriaLetta == nomeCategoria) {
                            numeroLetti++;
                            printf("\n%s \t%s \t%2.f \t%d", sostituisciTrattiniConSpazi(categoriaLetta).c_str(), sostituisciTrattiniConSpazi(nomeLetto).c_str(), prezzo, quantita);
                        }
                    }

                    if (numeroLetti == 0){
                        printf("\nNon sono stati trovati prodotti in questa categoria!");
                    }

                } else {

                    printf("\nNon e' stato trovato il file magazzino.txt, creano uno e aggiungici dei prodotti usando le varie opzioni!");

                }

                continua();
                break;
            }

            case 7:{

                printf("\nHai scelto: Vendita prodotto...");

                printf("\nInserire nome prodotto: ");

                cin.ignore();
                getline(cin, prodotto.nomeProdotto);
                prodotto.nomeProdotto = sostituisciSpaziConTrattini(prodotto.nomeProdotto);


                printf("\nInserire Quantita': ");
                cin >> prodotto.quantita;

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

                            time_t ct;
                            ct = time(NULL);
                            string tempo = sostituisciSpaziConTrattini(ctime(&ct));
                            if (logEsiste()){
                                modifiche = fopen("modifiche.txt", "a");
                                fprintf(modifiche, "%s", "\n");
                                fprintf(modifiche, "%s %s %s %lf %d %s", "Venduto", prodottoLetto.categoria.c_str(), prodottoLetto.nomeProdotto.c_str(), prodottoLetto.prezzo - (prodottoLetto.prezzo / 100 * sconto), prodotto.quantita, tempo.c_str());
                                scrittoModifiche = true;
                            } else {
                                modifiche = fopen("modifiche.txt", "w");
                                fprintf(modifiche, "%s %s %s %lf %d %s", "Venduto", prodottoLetto.categoria.c_str(), prodottoLetto.nomeProdotto.c_str(), prodottoLetto.prezzo - (prodottoLetto.prezzo / 100 * sconto), prodotto.quantita, tempo.c_str());
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
                       "\n- Disponibilita' rimanente: %d", prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo - (prodotto.prezzo / 100 * sconto), (prodotto.prezzo - (prodotto.prezzo / 100 * sconto)) * quantitaVenduta, quantitaVenduta, prodotto.quantita);

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
                                     nota = "imprevisto-decremento-" + nota;

                                     time_t ct;
                                     ct = time(NULL);
                                     string tempo = sostituisciSpaziConTrattini(ctime(&ct));
                                     if (logEsiste()) {

                                         modifiche = fopen("modifiche.txt", "a");
                                         fprintf(modifiche, "%s", "\n");
                                         fprintf(modifiche, "%s %s %s %lf %d %s %s %lf %d %s",
                                                 nota.c_str(),
                                                 prodottoPrecedente.categoria.c_str(),
                                                 prodottoPrecedente.nomeProdotto.c_str(), prodottoPrecedente.prezzo,
                                                 prodottoPrecedente.quantita, prodotto.categoria.c_str(),
                                                 prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, tempo.c_str());

                                     } else {

                                         modifiche = fopen("modifiche.txt", "w");
                                         fprintf(modifiche, "%s %s %s %lf %d %s %s %lf %d %s", nota.c_str(), prodottoPrecedente.categoria.c_str(), prodottoPrecedente.nomeProdotto.c_str(), prodottoPrecedente.prezzo, prodottoPrecedente.quantita, prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, tempo.c_str());
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
                                 printf("\nInserire Disponibilita' da decrementare: ");
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
                                 nota = "imprevisto-aggiunto-" + nota;

                                 time_t ct;
                                 ct = time(NULL);
                                 string tempo = sostituisciSpaziConTrattini(ctime(&ct));
                                 if (logEsiste()){

                                     modifiche = fopen("modifiche.txt", "a");
                                     fprintf(modifiche, "%s", "\n");
                                     fprintf(modifiche, "%s %s %s %lf %d %s", nota.c_str(), prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, tempo.c_str());

                                 } else {

                                     modifiche = fopen("modifiche.txt", "w");
                                     fprintf(modifiche, "%s %s %s %lf %d %s", nota.c_str(), prodotto.categoria.c_str(), prodotto.nomeProdotto.c_str(), prodotto.prezzo, prodotto.quantita, tempo.c_str());

                                 }
                                 fclose(modifiche);

                                 continua();
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

            default:{

                printf("\nHai inserito una scelta non valida, per favore riprovare!");

                break;
            }

        }

    }

    printf("\nUscito con successo!");
    return 0;
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
