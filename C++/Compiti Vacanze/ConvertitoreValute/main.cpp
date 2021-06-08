#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void continua();

bool valuteFileEsiste();

struct valuta{
    string nome;
    double valoreRisDollaro; // Valore rispetto al dollaro.
};

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//        Convertitore di Gabriele Caretti 3BITI            //"
           "\n//////////////////////////////////////////////////////////////\n");

    int nValuteTrovate = 0;
    int nValuteDefault = 3;
    valuta valute[100];
    valute[0] = {"Euro", 1.22};
    valute[1] = {"Franco", 1.05};
    valute[2] = {"Sterlina", 1.33};


    FILE *valuteFile;

    if (valuteFileEsiste()){

        valuteFile = fopen("valute.txt", "r");

        while (!feof(valuteFile)){
            char valutaLetta[100];
            double valoreLetto;
            fscanf(valuteFile, "%s %lf", valutaLetta, &valoreLetto);
            valute[nValuteTrovate].nome = valutaLetta;
            valute[nValuteTrovate].valoreRisDollaro = valoreLetto;
            nValuteTrovate++;
        }
        fclose(valuteFile);

        printf("\n\nFILE esistente delle valute letto con successo!");
    } else {

        valuteFile = fopen("valute.txt", "w");

        for (int i = 0; i < nValuteDefault; i++) {
            if (i != 0){
                fprintf(valuteFile, "%s", "\n");
            }
            fprintf(valuteFile, "%s %lf", valute[i].nome.c_str(), valute[i].valoreRisDollaro);
        }
        fclose(valuteFile);

        nValuteTrovate = nValuteDefault;
        printf("\n\nNuovo FILE delle valute scritto con successo con i valori di default!");
    }

    printf("\nSono state trovate %d valute.", nValuteTrovate);

    int scelta = 1;

    while (scelta != 0){

        printf("\n\nLegenda opzioni:"
               "\n0 -> Esci."
               "\n1 -> Converti valuta."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Converti valute...");


                int sceltaValuta;
                printf("\n\nEcco una lista delle valute:");
                for (int i = 0; i < nValuteTrovate; i++) {
                    printf("\n%d -> %s", i, valute[i].nome.c_str());
                }
                printf("\n\nScegliere valuta da convertire: ");

                bool sceltaValida = false;
                while (!sceltaValida) {
                    scanf("%d", &sceltaValuta);

                    if (sceltaValuta < 0 || sceltaValuta >= nValuteTrovate){
                        printf("\nScelta non valida, per favore riprovare..."
                               "\nScelta: ");
                    } else {
                        sceltaValida = true;
                    }
                }

                printf("\n\nHai scelto %s, con valore rispetto al dollaro di $%lf.", valute[sceltaValuta].nome.c_str(), valute[sceltaValuta].valoreRisDollaro);

                printf("\n\nEcco una lista delle valute:");
                for (int i = 0; i < nValuteTrovate; i++) {
                    printf("\n%d -> %s", i, valute[i].nome.c_str());
                }

                printf("\n\nInserire valute a cui convertire: ");

                sceltaValida = false;
                int sceltaValutaDestinazione;
                while (!sceltaValida) {
                    scanf("%d", &sceltaValutaDestinazione);

                    if (sceltaValutaDestinazione < 0 || sceltaValutaDestinazione >= nValuteTrovate){
                        printf("\nScelta non valida, per favore riprovare..."
                               "\nScelta: ");
                    } else {
                        sceltaValida = true;
                    }
                }

                printf("\n\nHai scelto %s, con valore rispetto al dollaro di $%lf.", valute[sceltaValutaDestinazione].nome.c_str(), valute[sceltaValutaDestinazione].valoreRisDollaro);

                double quantita;
                printf("\n\nInserire quantita' di %s da convertire in %s: ", valute[sceltaValuta].nome.c_str(), valute[sceltaValutaDestinazione].nome.c_str());
                scanf("%lf", &quantita);

                // Convertitore.
                double risultato = (quantita * valute[sceltaValuta].valoreRisDollaro) / valute[sceltaValutaDestinazione].valoreRisDollaro;

                printf("\n\n%lf di %s equivalgono a circa %lf di %s", quantita, valute[sceltaValuta].nome.c_str(), risultato, valute[sceltaValutaDestinazione].nome.c_str());

                continua();
                break;
            }

            default:{

                printf("\nScelta non valida, per favore riprovare!");

                break;
            }

        }

    }

    printf("\n\nUscito con successo!");

    return 0;
}

bool valuteFileEsiste(){

    if (fopen("valute.txt", "r") != NULL){
        return true;
    }

    return false;
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}
