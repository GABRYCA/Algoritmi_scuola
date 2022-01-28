// crea la coda inserendo in lista di testa  
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  
#include "code.h" 

#define MAXLEN 20

// programma principale
int main(){
  // dichiarazione variabili locali
  int x, dato;
  int tanti = 5;
  puntaNodo pTesta;
  puntaNodo pFine;
  creaCodaRandom (&pTesta, &pFine, tanti);
  stampaCoda (pTesta);
  
  printf("\n\n");
}

/* File: provaCodaSol.cpp                                      */
/* Time-stamp: "2015-07-05 00:28:26                            */
/* Scopo: creazione e visualizzazione di una coda dinamica     */
/* HOEPLI - Informatica in C e C++ - 2016                      */

