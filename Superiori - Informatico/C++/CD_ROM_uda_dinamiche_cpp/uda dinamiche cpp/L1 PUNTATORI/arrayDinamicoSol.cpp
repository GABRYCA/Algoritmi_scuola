#include <stdio.h>
#include <stdlib.h>
int main(){                               // accesso mediante puntatore 
  int *pi, num1, num2, dim, x;
  printf("Inserisci il numero di elementi da memorizzare: ");
  scanf ("%d",&dim);
  pi = (int*) malloc(dim * sizeof(int));  // alloco dim numeri interi
  if (pi == NULL) {                       // verifica corretta allocazione
   printf("Non ho abbastanza memoria per l'allocazione\n");
   system("PAUSE");
   exit(1);                               // terminazione errata
  }
  for(x = 0; x < dim; x++)  {
    printf ("\ninserisci il numero %d :", x + 1);
    scanf  ("%d",&pi[x]);                 // inserisco i numeri a partire da &pi[0]
  }
  for (x=0;x<dim;x++)                     // li visualizzo direttamente con *(pi+offset)  
    printf("\n numero %d =%d", x+1, *(pi + x));
  return 0;                               // terminazione corretta
}

 
/* Time-stamp: "2014-09-06 03:26:06 paolo"    */
/* Scopo: esercizi                            */ 
/* HOEPLI - Informatica in C e C++ - 2016     */

