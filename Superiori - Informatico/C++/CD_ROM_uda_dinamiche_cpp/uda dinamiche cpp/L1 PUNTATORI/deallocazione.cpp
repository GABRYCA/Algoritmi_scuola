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
  printf( "valore all'indirizzo di pa (istruzione 12) = %d\n", *pa ) ;
  
  pa  = (int*) malloc( sizeof(int) ) ;  // allocazione dinamica della I cella intera 
  printf( "indirizzo di pa (istruzione 15) = 0x%x\n", pa ) ;
  *pa = 777;  
                                        // ora *pa ha di nuovo un valore significativo 
  pb  = (int*) malloc( sizeof(int) ) ;  // allocazione dinamica della II cella intera
  printf( "\nindirizzo di pb (istruzione 19) = 0x%x\n", pb ) ;
 
  *pb = *pa;                            // le celle contengono lo stesso valore 
  pb  = (int*) malloc( sizeof(int) ) ;  // ERRORE: allocazione dinamica della III cella  
                                        // con perdita del riferimento alla II cella  
  printf( "\nindirizzo di pa (istruzione 24) = 0x%x\n", pa ) ;
  printf( "valore all'indirizzo di pa  = %d\n", *pa ) ;
  printf( "indirizzo di pb (istruzione 26) = 0x%x\n", pb ) ;
  printf( "valore all'indirizzo di pb  = %d\n", *pb ) ;
}                                        
	
/* File: deallocazione.cpp */
/* Time-stamp: "2014-07-05 00:28:26         */ 		
/* Scopo:  errore di rilascio della memoria */


