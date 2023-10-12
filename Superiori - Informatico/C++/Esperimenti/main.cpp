#include <iostream>

int main() {

    // Ruotare il ROBOT a destra o a sinistra in base alla bussola (posAttuale) e il punto specificato (destinazione).
    int destinazioneBussola = 5;
    int posAttualeBussola = 7;
    int appoggio;
    int conta1 = 0;
    int conta2 = 0;

    appoggio = posAttualeBussola;
    printf("\nSinistra: ");
    while(appoggio != destinazioneBussola){
        if (appoggio >= 7){
            appoggio = 0;
        }
        appoggio++;
        conta1++;
        printf("\n+1");
        if (conta1 > 4){
            break;
        }
    }

    appoggio = posAttualeBussola;
    printf("\n\nDestra: ");
    while (appoggio != destinazioneBussola){
        if (appoggio <= 0){
            appoggio = 7;
        }
        appoggio--;
        conta2++;
        printf("\n+1");
        if (conta2 >= 4){
            break;
        }
    }

    if (conta1 < conta2){
        printf("\n\nGira a sinistra!");
    } else if (conta2 < conta1){
        printf("\n\nGira a destra!");
    } else {
        printf("\n\nStessa distanza, giro a sinistra comunque.");
    }

    return 0;
}
