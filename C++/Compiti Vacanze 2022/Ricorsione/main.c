#include <stdio.h>

// Dare in input la dim-1 reale, un vettore da 10 elementi, dare 9 come dim che e' la posizione dell'ultimo.
int nInVett(int vet[], int dim, int n);

// Dare in input dim la posizione dell'ultimo elemento.
int nPosInVett(int vet[], int dim);

// Dare in input dim la posizione dell'ultimo elemento.
void rimuoviDuplicati(int vet[], int dim);

int main() {
    printf("/////////////////////"
           "\nLavoro di G.C. 4BITI"
           "\n/////////////////////");

    int scelta;
    do {

        printf("\n\nOpzioni:"
               "\n0 -> Esci."
               "\n1 -> Elemento in vettore ricorsivo."
               "\n2 -> Numero elementi positivi."
               "\n3 -> Rimuovi doppioni."
               "\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 0:{

                printf("\nHai scelto: Esci..."
                       "\nUscita in corso...");

                break;
            }

            case 1:{

                printf("\nHai scelto: Ricerca elemento in vettore ricorsiva...");

                int nElementi = 10;
                int vettore[] = {1,2,3,4,5,6,7,8,9,0};
                int n;

                printf("\nInserire numero da cercare: ");
                scanf("%d", &n);

                // 0 = Non trovato, 1 = Trovato.
                printf("\nRisultato ricerca: [%d]", nInVett(vettore, nElementi-1, n));

                break;
            }

            case 2: {

                printf("\nHai scelto: Numero elementi positivi in array...");

                int nElementi = 10;
                int vettore[] = {0,1,2,3,-4,5,-6,7,8,9};

                printf("\nNumero elementi positivi nel vettore: [%d]", nPosInVett(vettore, nElementi - 1));

                break;
            }

            case 3: {

                printf("\nHai scelto: Rimuovi doppioni...");

                int nElementi = 10;
                int vettore[] = {0, 0, 1, 2, 3 ,4 ,5, 6, 6, 7};

                printf("\nNumeri nel vettore: ");
                for (int i = 0; i < nElementi; i++) {
                    printf("\n%d", vettore[i]);
                }

                rimuoviDuplicati(vettore, nElementi - 1);

                // I valori duplicati vengono sostituiti con -404 (valore bandiera) e ignorati dal print.
                printf("\n\nValori senza duplicati nel vettore: ");
                for (int i = 0; i < nElementi; i++) {
                    if (vettore[i] != -404){
                        printf("\n%d", vettore[i]);
                    }
                }

                break;
            }

            default:{

                printf("\nOpzione non valida! Per favore riprovare!\n");

                break;
            }
        }

    } while (scelta != 0);

    return 0;
}

int nInVett(int vet[], int dim, int n){

    if (dim < 0){
        return 0;
    }

    if (vet[dim] == n){
        return 1;
    }

    return nInVett(vet, dim-1, n);
}

int nPosInVett(int vet[], int dim){
    if (dim < 0){
        return 0;
    }

    if (vet[dim] >= 0){
        return nPosInVett(vet, dim - 1) + 1;
    } else {
        return nPosInVett(vet, dim - 1);
    }
}

void rimuoviDuplicati(int vet[], int dim){
    if (dim < 0){
        return;
    }

    for (int i = 0; i < dim; i++){
        if (vet[i] == vet[dim]){
            vet[i] = -404; // Sostituisco con valore bandiera.
        }
    }

    rimuoviDuplicati(vet, dim - 1);
}

