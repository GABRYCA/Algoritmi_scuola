// allocazione di un vettore di float  
#include <stdio.h>
#include <stdlib.h>

int main(){ 
 float *vetf; int tanti;
 printf("Dimensione del vettore: "); 
 scanf("%d", &tanti); 
 vetf = (float*) malloc(tanti * sizeof(float));
  if ( vetf == NULL)  {                     // verifica corretta allocazione
   printf ( "Non ho abbastanza memoria per l'allocazione\n ");
   system ("PAUSE");
   exit( 1 ) ;                              // terminazione errata
  }

 //   ... uso dell'array ... 
   exit( 0 );                                // terminazione ok 
   
}

/* File: arrayFloatSol.cpp                    */
/* Time-stamp: "2015-07-05 00:28:26           */
/* Scopo:  creazione di un array dinamico     */
/* HOEPLI - Informatica in C e C++ - 2016     */
 

