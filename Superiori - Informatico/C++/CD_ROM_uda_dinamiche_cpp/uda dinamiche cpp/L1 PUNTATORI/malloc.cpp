#include <stdio.h>
#include <stdlib.h>
int main(){                               
  int num1, num2;                // due var definite staticamente
  int *pi;  
  pi  = (int*) malloc( 5 ) ;     // una var di 5 byte definita dinamicamente
  if ( pi == NULL ){
	printf ("non ho abbastanza memoria per l'allocazione!'");
	exit ( 1 );
  }  
  *pi  = 33;                     
  num1 = 66;                   
  num2 = *pi + num1;           // sommo una var statica ad una var dinamica 
  printf ( "Valore variabili:*pi = %d, num1 = %d, num2 = %d \n", *pi, num1, num2) ;
}

// allocazione dinamica di una variabile  
// pi  = malloc(5) ;     // una var di 5 byte definita dinamicamente


/* File: malloc.cpp                           */
/* Time-stamp: "2015-07-05 00:28:26           */
/* Scopo:  allocazione dinamica della memoria */
/* HOEPLI - Informatica in C e C++ - 2016     */
 
 
