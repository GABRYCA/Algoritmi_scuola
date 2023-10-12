#include <stdio.h>
#include <stdlib.h>
int main(){   
  int *pi, num1, num2, dim, x;
  printf( "Inserisci il numero di elementi da memorizzare: " ) ;
  scanf ( "%d", &dim );            			 // leggo la dimensione del vettore run-time
  pi = (int*) malloc ( dim * sizeof (int) ); // alloco dinamicamnte lo spazio necessario
  for( x = 0 ; x < dim ; x++){
    printf ( "\ninserisci il numero %d : ", x + 1 ) ;    // riempio il vettore
    scanf  ( "%d", &pi[x] );
  }
  for ( x = 0 ; x < dim ; x++ )
    printf( "\n numero %d =%d ", x + 1, *( pi + x ) ) ;  // visualizzo il suo contenuto 
}


/* File: arrayDinamico.cpp                    */
/* Time-stamp: "2015-07-05 00:28:26           */
/* Scopo:  creazione di un array dinamico     */
/* HOEPLI - Informatica in C e C++ - 2016     */
 

/*
 // Allocaz.dinamica di 10 byte per memorizzare numeri reali
 float *pf;
 pf = (float*) malloc(10); 

 // Allocaz.dinamica di 6 interi "liberi" dal tipo di HW 
 int *pi;
 pi = (int*) malloc(6*sizeof(int));

*/
