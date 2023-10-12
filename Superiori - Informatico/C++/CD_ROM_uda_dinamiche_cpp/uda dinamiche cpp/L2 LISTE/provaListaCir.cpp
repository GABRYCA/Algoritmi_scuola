/* File: _provaListaCir.cpp                        */
/* Time-stamp: "2015-07-05 00:28:26                 */
/* Scopo: file incompleto per prove e esercitazioni */ 
/* HOEPLI - Informatica in C e C++ - 2016           */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // necessaria la libreria per le var booleane 
#include <time.h>

//-----------------------------------------------------------------------
#include "_listeLibCir.h"

int main() {
  lista pCorrente = listaVuota() ;             /*----FUNZIONE CREO LISTA VUOTA----*/
  int dato, x ;
  srand(time(0));  /* setta casualmente l'origine della sequenza */
 
  /*----FUNZIONE CTR VUOTA ----*/
  if (isVuota(pCorrente))
    printf( "\n la lista e' vuota \t");
  else
    printf( "\n la lista non e' vuota \t");
 	 
	/*----FUNZIONE INSERISCI NODO IN LISTA ----*/
  printf("\n\n /*----INSERISCI NODO ----*/ \n\n ") ;
  printf( "\n Introduci numero da inserire nella lista:\t");
  scanf("%d", &dato ); 
  //pCorrente = inserisciNodo(dato, pCorrente);
  stampaLista(pCorrente) ;
  
  /*----FUNZIONE CTR VUOTA ----*/
  if (isVuota(pCorrente))
    printf( "\n la lista e' vuota \t");
  else
    printf( "\n la lista non e' vuota \t");

  /*----FUNZIONE CREA LISTA RANDOM----*/
  printf("\n\n /*----FUNZIONE CREALISTA RANDOM----*/ \n\n ") ;
  printf( "\n Introduci la grandezza della lista:\t");
  dato = 5 ;
  scanf("%d", &dato ); 
  pCorrente = creaListaRandom(pCorrente, dato);
  stampaLista(pCorrente) ;

  /*----FUNZIONE se un elemento è presente  NELLA LISTA----*/ 
  printf("\n\n /*----FUNZIONE RICERCA PRESENZA ELEMENTO NELLA LISTA----*/ \n\n") ;
  printf( "\n Introduci il valore da cercare: ");
  dato = 0 ;
  scanf("%d", &dato ); 
  if (trova(dato, pCorrente))
    printf( "\n il numero %d e' nella lista", dato);
  else
    printf( "\n il numero %d non e' nella lista", dato);

  /*----FUNZIONE TROVA POSIZIONE DI UN ELEMENTO NELLA LISTA----*/ 
  printf("\n\n /*----FUNZIONE RICERCA LA POSIZIONE DI UN ELEMENTO NELLA LISTA----*/ \n\n") ;
  int distanza = posizione(dato, pCorrente);
  if (distanza == 0)
    printf( "\n il numero %d non e' nella lista", dato);
  else
    printf( "\n il numero %d e' nella lista tra %d posti", dato, distanza);
 
  /*----FUNZIONE CRTORDINATA----*/
  printf("\n\n /*----FUNZIONE CRTORDINATA----*/ \n ") ;
  if (ctrOrdinata(pCorrente))
    printf( "\n la lista e' ordinata \t");
  else
    printf( "\n la lista non e' ordinata \t");
  
  /*----FUNZIONE CONTAELEMENTI----*/
  printf("\n\n /*----FUNZIONE CONTAELEMENTI----*/ \n ") ;
  printf("\n La lista contiene %d elementi \n", contaElementi(pCorrente)) ;
  //  system ("PAUSE") ;
}
 

