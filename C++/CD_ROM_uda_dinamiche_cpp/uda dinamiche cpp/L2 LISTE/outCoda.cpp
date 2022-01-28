//----------------------------------------------------------
// crea la coda inserendo in tanti elementi e togliendone 2 
// ---------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  
#include "code.h"

// programma principale
int main(){
  // dichiarazione variabili locali
  int tanti = 5;
  puntaNodo pTesta;
  puntaNodo pFine;
  
  // creazione coda
  creaCodaRandom (&pTesta, &pFine, tanti);
  stampaCoda (pTesta);

  outCodaTesta (&pTesta, &pFine);
  outCodaTesta (&pTesta, &pFine);
  outCodaTesta (&pTesta, &pFine);
  outCodaTesta (&pTesta, &pFine);
  outCodaTesta (&pTesta, &pFine);
  stampaCoda (pTesta);
  
  printf("\n\n");
} 

/* File: outCoda.cpp                                           */
/* Time-stamp: "2015-07-05 00:28:26                            */
/* Scopo: creazione e estrazione elementi da una coda dinamica */
/* HOEPLI - Informatica in C e C++ - 2016                      */

 
