#include <iostream>
#include <stdio.h>

void Double(int *number);

void continua();

int elevaCubo(int valore);

void elevaCuboPtr(int *cubo);

void dimostrazioneBase();

void dimostrazioneCuboBase();

void dimostrazioneCuboPtr();

void sommaVettore(int x[], int numeroValori, int *tot);

void sommaVettorePtr(const int *x, int numeroValori, int *tot2);

void vettoriEPuntatori();

void esempioUppercasePtr(char *sPtr);

using namespace std;

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//          Puntatori di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;

    while (scelta != 0){

        printf("\n\nLegenda: "
               "\n0 -> Esci."
               "\n1 -> Dimostrazione base."
               "\n2 -> Cubo con funzione senza indirizzo memoria."
               "\n3 -> Cubo con funzione con indirizzo memoria."
               "\n4 -> Funzione nascosta vettore."
               "\n5 -> Tipi di puntatori costanti."
               "\n6 -> Esempio."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscendo dal programma...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Dimostrazione base...\n\n");

                dimostrazioneBase();

                break;
            }

            case 2:{

                printf("\nHai scelto: Cubo con funzione classica...");

                dimostrazioneCuboBase();

                break;
            }

            case 3:{

                printf("\nHai scelto: Cubo con funzione e indirizzi di memoria...");

                dimostrazioneCuboPtr();

                break;
            }

            case 4:{

                printf("\nHai scelto: Vettori e puntatori...");

                vettoriEPuntatori();

                continua();
                break;
            }

            case 5:{

                int x = 2;

                // Tipi di const con puntatori.
                // int *const myPtr = &x; // Puntatatore constante ad un int.
                // const int *myPtr = &x; // Puntatore "normale" ad un const int.
                // const int *const Ptr = &x; // Puntatotre costante ad un const int.

                break;
            }

            case 6:{

                printf("\nHai scelto: Esempio puntatore char conversione...");

                char string[] = "Prova bella.";

                esempioUppercasePtr(string);

                printf("\nValore finale string = %s", string);

                break;
            }

            case 7:{

                // Scrivere funzione per scrivere una stringa char usando un puntatore carattere per carattere.

                break;
            }
            default:{

                printf("\nHai inserito un valore non valido, per favore riprova.");

                break;
            }
        }

    }

    printf("\n\nUscito con successo!");

    return 0;
}

void esempioUppercasePtr(char *sPtr){

    while (*sPtr != '\0'){

        if (islower(*sPtr)){
            *sPtr = toupper(*sPtr);
        }

        ++sPtr; // Sposta puntatore al carattere successivo.

    }
}

void vettoriEPuntatori() {
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numeroValori = 10;

    int tot = 0;
    sommaVettore(x, numeroValori, &tot);

    printf("\nTot = %d", tot);

    int tot2 = 0;
    sommaVettorePtr(x, numeroValori, &tot2);

    printf("\nTot2 = %d", tot2);
}

void sommaVettorePtr(const int *x, int numeroValori, int *tot2) {
    for (int i = 0; i < numeroValori; i++) {
        *tot2 += x[i];
    }
}

void sommaVettore(int x[], int numeroValori, int *tot) {
    for (int i = 0; i < numeroValori; i++) {
        *tot += x[i];
    }
}

void dimostrazioneCuboPtr() {
    int valore;
    printf("\n\nInserire il valore da elevare al cubo: ");
    scanf("%d", &valore);

    elevaCuboPtr(&valore);

    printf("\n\nRisultato = %d", valore);
}

void dimostrazioneCuboBase() {
    int valore;
    printf("\n\nInserire valore da fare al cubo: ");
    scanf("%d", &valore);

    int cubo = elevaCubo(valore);

    printf("\n\nRisultato = %d", cubo);
}

void dimostrazioneBase() {
    int a;
    int *aPtr;

    a = 7;
    aPtr = &a;

    printf("Indirizzo di a e' %p"
           "\nIl valore di aPtr e' %p", &a, aPtr);

    printf("\n\nIl valore di a e' %d"
           "\nIl valore di *aPtr e' %d", a, *aPtr);

    printf("\n\nDimostro che * e & si ellidono: "
           "\n&*aPtr = %p"
           "\n*&aPtr = %p\n", &*aPtr, *&aPtr);

    Double(&a);
    printf("\nRisultato = %d", a);
}

void elevaCuboPtr(int *cubo){

    *cubo = *cubo * *cubo * *cubo;

}

int elevaCubo(int valore) {
    int cubo;
    cubo = valore * valore * valore;
    return cubo;
}

void Double(int *number){
    *number = 2 * ( *number );
}

void continua(){

    int inusato;

    // Chiedo all'utente di inserire un numero casuale per continuare e ottengo l'input
    printf("\n\nInserisci un numero per continuare... ");
    scanf("%d", &inusato);

}