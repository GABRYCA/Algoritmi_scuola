#include <stdio.h>
#include <stdlib.h>
int main(){
  int *pa, *pb;                         // definizione di due puntatori 
  pa  = (int*) malloc( sizeof(int) ) ;  // allocazione dinamica della I cella intera 
  printf( "indirizzo di pa (istruzione  6) = 0x%x\n", pa ) ;
  
  *pa = 222 ;                    // assegno a *pa un valore          
  pb = pa ;                      // pa e pb PUNTANO ALLA STESSA CELLA DI MEMORIA 
  printf( "valore all'indirizzo di pa (istruzione 10) = %d\n", *pa ) ;
  free( pb ) ;                   // deallocazione di *pb, E QUINDI ANCHE DI *pa 
 
  printf( "\nindirizzo di pa (istruzione 13) = 0x%x\n", pa ) ;
  printf( "valore all'indirizzo di pa  = %d\n", *pa ) ;
  printf( "indirizzo di pb (istruzione 15) = 0x%x\n", pb ) ;
  printf( "valore all'indirizzo di pb  = %d\n", *pb ) ;
}                                        
	
/* File: deallocazione1.cpp */
/* Time-stamp: "2014-07-05 00:28:26         */ 		
/* Scopo:  errore di rilascio della memoria */
/* HOEPLI - Informatica in C e C++ - 2016   */
 

