/* File: _provaListaCir.cpp                   */
/* Time-stamp: "2015-07-05 00:28:26           */
/* Scopo: file per prove e debugging          */ 
/* HOEPLI - Informatica in C e C++ - 2016     */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // necessaria la libreria per le var booleane 
#include <time.h>

//-----------------------------------------------------------------------
#include "_listeLibBidCir.h"

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
  pCorrente = inserisciNodo(dato, pCorrente);
  stampaListaHT(pCorrente);
  
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
  printf( "\n da sx a dx\n");
  stampaListaHT(pCorrente) ;
  printf( "\n da dx a sx\n");
  stampaListaTH(pCorrente) ;
 
  /*----FUNZIONE TROVA POSIZIONE DI UN ELEMENTO NELLA LISTA----*/ 
  printf("\n\n /*----FUNZIONE RICERCA LA POSIZIONE DI UN ELEMENTO NELLA LISTA----*/ \n\n") ;
  printf( "\n Introduci il valore da cercare:\t");
  dato = 0 ;
  scanf( "%d", &dato );
  if (trova (dato, pCorrente))		      // cerca  un elemento nella lista 	
	{
	  printf( "\n Il valore  %d e' presente a destra in posizione %d ", dato, cercaDx (dato,pCorrente));
		printf( "\n Il valore  %d e' presente a sinistra in posizione %d ", dato, cercaSx (dato,pCorrente));
		
	}
	else
	  printf( "\n Il valore  %d non e' presente nella la lista", dato);
  
     
  /*----FUNZIONE CRTORDINATA----*/
  printf("\n\n /*----FUNZIONE CRTORDINATA----*/ \n\n ") ;
    
   
  /*----FUNZIONE CONTAELEMENTI----*/
  printf("\n\n /*----FUNZIONE CONTAELEMENTI----*/ \n\n ") ;
//  printf("\n La lista (lista2) contiene %d elementi \n", contaElementi(lista2)) ;



  system ("PAUSE") ;
}
 

