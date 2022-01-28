#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liste.h"                        // libreria con le mie funzioni                                     

int main() {
  srand(time(NULL));
  int num = 0 ;                             // num elementi di ogni lista
  lista lista1 = listaVuota() ;             // crea lista vuota 
  lista lista2 = listaVuota() ;             // crea lista vuota 
    
  printf( "\n Quanti elementi vuoi nella lista ? ");
  scanf("%d", &num);

  printf( "\n Genera una lista di %d elementi random:\n",num);
  lista1 = creaListaRandom(num);
  printf( "\n La lista 1 creata e' la seguente: \t");
  mostraLista( lista1 );
  
  lista2 = rovesciaLista(lista1);
  printf( "\n La lista rovesciata e' la seguente: \t");
  mostraLista( lista2 );
}


/* File: provaRovescio.cpp                  */
/* Time-stamp: "2015-07-05 00:28:26         */
/* Scopo: utilizzo libreria liste           */  
/* HOEPLI - Informatica in C e C++ - 2016   */ 
