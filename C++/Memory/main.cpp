#include <cstdio>
#include <graphics.h>

void continua();

int main() {

    int vuoleGiocare = 1;

    printf("\n//////////////////////////////////////////////////////////////"
           "\n//            Memory di Gabriele Caretti 3BITI              //"
           "\n//////////////////////////////////////////////////////////////");

    // rettangolo(50,50,10,10,rosso,false);

    while (vuoleGiocare != 0) {

        int numeroCarte = 36, x = 6, y = 6, vinto = 0, coppieTrovate = 0, erroriMassimi, nErrori = 0;

        printf("\nLe dimensioni totali sono un %d x %d per un totale di %d carte, significa che ci saranno %d coppie"
               "\nda trovare.", x, y, numeroCarte, numeroCarte / 2);

        printf("\nQuante possibilità di errore vuoi avere? "
               "\nValore: ");
        scanf("%d", &erroriMassimi);

        printf("\n\nPer giocare, seguire le istruzioni a schermo...\n");

        int vettore[6][6] = {0};



        while (vinto == 0 && nErrori < erroriMassimi) {

            int xTent, yTent;

            // Spazio da in cima
            printf("\n\n\n\n\n\n\n");

            int coordX = 50, coordY = 10, coordX2 = coordX, coordY2 = coordY;

            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    printf("\t%d", vettore[j][i]);
                }
                printf("\n");
            }

            // Qui andrà scitta la grafica

            printf("\nInserire coordinate da provare: "
                   "\nx: ");
            scanf("%d", xTent);
            printf("y: ");
            scanf("%d", &yTent);

            if (coppieTrovate == numeroCarte / 2) {
                vinto++;
            }

            system("cls");
        }

        if (vinto != 0) {
            printf("\nCongratulazioni, hai vinto!");
        } else {
            printf("\nHai perso, sarai più fortunato la prossima volta...");
        }

        printf("\nVuoi ancora giocare? Scegli: "
               "\n0 -> No"
               "\n1 -> Si"
               "\nScelta: ");
        scanf("%d", &vuoleGiocare);
    }

    return 0;
}


void continua(){

    // Dichiaro una variabile bandiera
    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un NUMERO a caso per continuare... ");
    scanf("%d", &inusato);

}

