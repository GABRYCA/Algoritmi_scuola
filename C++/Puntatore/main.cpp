#include <iostream>
#include <stdio.h>

void Double(int *number);

int elevaCubo(int valore);

void elevaCuboPtr(int *cubo);

void dimostrazioneBase();

void dimostrazioneCuboBase();

void dimostrazioneCuboPtr();

int main() {

    // Messaggio del creatore.
    printf("\n//////////////////////////////////////////////////////////////"
           "\n//          Puntatori di Gabriele Caretti 3BITI             //"
           "\n//////////////////////////////////////////////////////////////\n");

    int scelta = 1;

    while (scelta != 0){

        printf("\nLegenda: "
               "\n0 -> Esci."
               "\n1 -> Dimostrazione base."
               "\n2 -> Cubo con funzione senza indirizzo memoria."
               "\n3 -> Cubo con funzione con indirizzo memoria."
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
            default:{

                printf("\nHai inserito un valore non valido, per favore riprova.");

                break;
            }
        }

    }

    printf("\n\nUscito con successo!");

    return 0;
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

    printf("Indirizzo di a è %p"
           "\nIl valore di aPtr è %p", &a, aPtr);

    printf("\n\nIl valore di a è %d"
           "\nIl valore di *aPtr è %d", a, *aPtr);

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
