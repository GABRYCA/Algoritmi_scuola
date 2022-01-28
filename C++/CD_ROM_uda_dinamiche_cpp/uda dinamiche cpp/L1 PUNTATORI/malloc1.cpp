#include <stdio.h>                       // allocazione 5 celle integer contigue 
#include <stdlib.h>
int main(){                               
  int  num1, num2, x;                    // tre var definite staticamente
  int *pint; 
  pint = (int*)malloc(5 * sizeof(int));  // una var definita dinamicamente di 5 int
  pint[0] = 1;                           // inizializzazione variabili nel vettore
  pint[1] = 3;
  pint[2] = 5;
  pint[3] = 7;
  pint[4] = 9;
  *(pint + 4) = -11;                       // scrive nella cella  pint[4]
  for(x = 0; x < 5; x ++)  
    printf ("%4d", pint[x]);             // visualizza vettore
 }

void visualizza ( int vet[], int inizio, int num );
//  visualizza (pint,0,5);
void visualizza ( int vet[], int inizio, int num ){
  int conta;
  printf ("\n");
  for ( conta = 0; conta < num; conta ++ ){ 
    if ( conta < inizio )
      printf ("    ");                    // visualizza blanc
    else
      printf ("%4d", vet[conta]);         // visualizza vettore
  }
}
    
    
/* File: malloc1.cpp                          */
/* Time-stamp: "2015-07-05 00:28:26           */
/* Scopo:  allocazione dinamica della memoria */
/* HOEPLI - Informatica in C e C++ - 2016     */
 


