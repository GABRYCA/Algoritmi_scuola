#include <stdio.h>
#include <stdlib.h>
int *vetAlloc(int numEle, int dim){
 int *p;
 /* p punta al vettore di numEle elementi */
 p = (int*) malloc(numEle * dim);
 if (p == NULL){
   printf("errore di memoria!\n");
   exit(-1);
 }
 return p;
}

int main(){ // accesso mediante puntatore 
  int *pi, num1, num2, dim, x;
  printf("Inserisci il numero di elementi da memorizzare: ");
  scanf ("%d", &dim);
  pi = (int *)vetAlloc(dim,sizeof(int));
  if (pi == NULL) {                  // verifica corretta allocazione
    printf("Non ho abbastanza memoria per l'allocazione\n");
    system("PAUSE");
    exit(1);  //terminazione errata
  }
  for(x = 0; x < dim; x++)
  {
    printf ("\ninserisci il numero %d :", x+1);
    scanf  ("%d", &pi[x]); // inserisco i numeri a partire da &pi[0]
  }
  for (x = 0; x < dim; x++)     // li visualizzo direttamente con *(pi+offset)  
    printf("\n numero %d =%d", x + 1, *(pi + x));

  return 0;  //terminazione corretta
}

/* File: provaVetSol.cpp                             */
/* Time-stamp: "2015-07-05 00:28:26                      */
/* Scopo:  operazioni sulLe matrici mediante puntatori   */  
/* HOEPLI - Informatica in C e C++ - 2016                */
