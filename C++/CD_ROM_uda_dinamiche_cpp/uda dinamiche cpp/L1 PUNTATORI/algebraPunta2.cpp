#include <stdio.h>
#include <stdlib.h>
int main(){            
  int vet[8], *punta1, x; 
  for(x = 0; x < 8; x++ ){    // inizializzazione del vettore 
   *( vet + x ) = 0;          // equivale a  vet[x] 
  }
  punta1 = vet;               // equivale a  *punta1 = &vet[0];
  for(x = 0; x < 8; x++ ) 
  {
    // aggiornamento con indice 
    vet[x] = x * 5;               // aggiorna il contenuto cella pari   
    printf("valore di x , punta1, vet[%d] = %d 0x%X  %d\n", x, x, punta1, vet[x]);
    x++;
    // aggiornamento diretto mediante indirizzo 
   	punta1  = punta1 + 1;         // sposta puntatore avanti di una posizione
 	*punta1 = x * 5;	          // aggiorna il contenuto cella dispari
    printf("valore di x , punta1, vet[%d] = %d 0x%X  %d\n", x, x, punta1, vet[x]);  
   	punta1  = punta1 + 1;         // sposta puntatore avanti di una posizione
  }
}

/* File: algebraPunta.cpp                  */
/* Time-stamp: "2015-07-05 00:28:26        */
/* Scopo:  scrittura diretta in un vettore */
/* HOEPLI - Informatica in C e C++ - 2016  */



/*
 // Allocaz.dinamica di 10 byte per memorizzare numeri reali
 float *pf;
 pf = (float*) malloc(10); 

 // Allocaz.dinamica di 6 interi "liberi" dal tipo di HW 
 int *pi;
 pi = (int*) malloc(6*sizeof(int));

*/
