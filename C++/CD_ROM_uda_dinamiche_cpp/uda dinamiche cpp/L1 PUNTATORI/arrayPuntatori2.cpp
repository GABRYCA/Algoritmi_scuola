#include <stdio.h>
#include <stdlib.h>
int main(){ 
  int *p5i;                                        // dichiaro un puntatore
  p5i = (int*)malloc( 5 * sizeof(int));            // alloco 5 interi 
  int vet[5];        // dichiaro un puntatore e alloco 5 spazi interi  
  int x;
  for ( x = 0 ; x < 5 ; x++ ){  // assegno valori alle celle di memoria 
    p5i[x] = x;
    vet[x] = x * 10;
  } 
  printf("\n Valori dati in memoria" );            // recupero dei dati:  
  printf("\n notaz.vettore  notaz.puntatori ");     
  printf("\n heap vettore heap vettore ");     
  for ( x = 0 ; x < 5 ; x++ ){                   
    printf("\n %4d %4d", p5i[x], vet[x]);          // a) notazione vettore
    printf("   %4d %4d", *(p5i + x), *(vet + x));  // b) notazione puntatori
  }
  
  printf("\n\n Indirizzi delle celle ");           // recupero indirizzi       
  printf("\n notazione vettore           notazione puntatori ");     
  printf("\n vettore          heap       vettore          heap ");             
  for (x=0;x<5;x++){                         
   printf("\n %p 0x%X", p5i + x, vet + x );        // a) notazione vettore
   printf("   %p 0x%X",  &p5i[x], &vet[x] );       // b) notazione puntatori
  }
}

/* File: arrayPuntatori2.cpp                             */
/* Time-stamp: "2015-07-05 00:28:26                      */
/* Scopo:  operazioni sulLe matrici mediante puntatori   */  
/* HOEPLI - Informatica in C e C++ - 2016                */

 

 
