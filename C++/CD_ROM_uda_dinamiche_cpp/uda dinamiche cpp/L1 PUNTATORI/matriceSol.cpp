#include <stdio.h>
#include <stdlib.h>
main(){
  int **matrice, righe, colonne, x, y;
  righe = 3 ;     //  3 righe  
  colonne = 5  ;  //  5 colonne
    
  // alloco il vettore delle righe: ogni elemento è un puntatore 
  matrice = (int**) malloc ( righe * sizeof( int* ) );
  
  // per ogni riga  alloco le colonne composte da interi inizializzati a 0
  for ( x = 0 ; x < righe ; x++)
    matrice[x] = (int*) calloc ( colonne, sizeof( int ) );
    
  // scrivo nelle celle delle matrice per riga
   for ( y = 0 ; y < righe ; y++ )              // per ogni riga 
     for ( x = 0 ; x < colonne ; x++ )          // per ogni colonna  
        *( matrice[y] + x ) = ( y + 1 ) * ( x + 1 );  

  // visualizzo le celle delle matrice per riga
   for ( y = 0 ; y < righe ; y++ ) {            // per ogni riga 
     for ( x = 0 ; x < colonne ; x++ )          // per ogni colonna  
        printf (" %2d ", *( matrice[y] + x ));  
     printf("\n");
   }  

   // visualizzo le celle delle matrice di seguito 
   printf("\n");
   for ( y = 0 ; y < righe*colonne ; y++ )      // per tutte le celle 
        printf (" %2d ", **matrice + y );  
   printf("\n");

  // visualizzo le celle delle matrice per colonna 
   printf("\n");
   for ( x = 0 ; x < colonne ; x++ ) {          // per ogni colonna  
     for ( y = 0 ; y < righe ; y++ )            // per ogni riga 
       printf ( " %2d ", matrice[y][x] );  
     printf("\n");
   } 
}
 
 
/* File: matriceSol.cpp                     */
/* Time-stamp: "2011-07-05 00:28:26         */
/* Scopo: allocazione dinamica dei vettori  */  
/* HOEPLI - Informatica in C e C++ - 2016   */

