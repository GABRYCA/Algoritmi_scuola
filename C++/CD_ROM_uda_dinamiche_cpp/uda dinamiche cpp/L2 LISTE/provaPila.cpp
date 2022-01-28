#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define MAXLEN 20

#define VERO 0
#define FALSO 1

void deallocaPila1 (puntaNodo pTesta){
	
	// funzione da scrivere 

}
// programma principale
int main(int argc, char *argv[]){
  // dichiarazione variabili locali
  puntaNodo pTesta;
  int tanti; 

  system("CLS");             // ripulisco lo schermo
 
  printf("Quanti elementi inserirsco nella pila? ");
  scanf("%d", &tanti);

  pTesta = creaPilaRandom( tanti );   // crea causualmente la pila 

  deallocaPila1(pTesta);               // toglie tutti gli elementi  

  stampaPila (pTesta);                //  visualizza la pila

  return 0;
}

/* File: provaPila.cpp                                         */
/* Time-stamp: "2015-07-05 00:28:26                            */
/* Scopo: ceazione di una pila random e sua visualizzazione    */  
/* HOEPLI - Informatica in C e C++ - 2016                      */ 


