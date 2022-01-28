#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#include "liste.h"

/////////////////////////////////////////////////////////////////
int main() {
  srand(time(NULL));
  int num = 4 ;                               // num elementi di ogni lista
  int x, quanti, dato ;
  lista lista1 = listaVuota() ;             // crea lista vuota 
  lista lista2 = listaVuota() ;             // crea lista vuota 
  lista lista3 = listaVuota() ;             // crea lista vuota 
  lista lista4 = listaVuota() ;             // crea lista vuota 
  
  
  printf( "\n Quanti elementi vuoi nelle due liste ? ");
  scanf("%d", &num);

  printf( "\n Genera due lista di %d elementi random:\n",num);
  for (x=0; x<num; x++){
    dato = rand()%99 + 1;     /* genero casualmente il dato     */
    lista1 = inserisciOrdinato(dato, lista1);
  }
  printf( "\n La lista 1 creata e' la seguente: \t");
  mostraLista( lista1 );
  
  printf( "\n Genera due lista di %d elementi random:\n",num);
  for (x=0; x<num; x++){
    dato = rand()%99 + 1;     /* genero casualmente il dato     */
    lista2 = inserisciOrdinato(dato, lista2);
  }
  printf( "\n La lista 2 creata e' la seguente: \t");
  mostraLista( lista2 );
	
  if (ctrOrdinata(lista1) && ctrOrdinata(lista2)){
    lista3 = mergeListe(lista1, lista2) ; 
    printf( "\n La fusione delle due liste  e' la seguente: \t");
    mostraLista( lista3 );
  }
  else
    printf( "\n le liste devono essere ordinata per poter fare la fusione! \t");
} 

/* File: provaMergeSol.cpp                  */
/* Time-stamp: "2015-07-05 00:28:26         */
/* Scopo: merge-sort in una lista           */  
/* HOEPLI - Informatica in C e C++ - 2016   */
