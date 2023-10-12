#include <stdio.h>
#include <stdlib.h>
int main()
{            
 
  int num = 7, *punta;     // dichiaro var.intera e punta _intero
  punta = &num;            // al puntatore assegno l'indirizzo
  printf("indirizzo di num  = 0x%X\n", &num);
  printf("valore di punta   = 0x%X\n", punta);
  punta++ ;               // incremento il puntatore  
  printf("valore di punta++ = 0x%X\n", punta);
 
  printf("\n\n");
  
  
  /*
  int num2 = 17, *punta;    // dichiaro var.intera e punta _intero
  punta = &num2;            // al puntatore assegno l'indirizzo
  printf("valore di punta     = 0x%X\n", punta);
  punta = punta - 2;        // sottraggo due "valori" ad un puntatore
  printf("valore di punta - 2 = 0x%X\n", punta);
 
  printf("\n\n");
  
  
  int num3 = 7, *pi1, *pi2 , diff;   // dichiarazione var.intere e puntatori
  pi1 = &num3;                       // al puntatore assegno l'indirizzo di num3
  printf("valore di pi1     = 0x%X\n", pi1);
  pi1 = pi1 + 3;                     // incremento di 3 interi   
  printf("valore di pi1 + 3 = 0x%X\n", pi1);
  pi2 = pi1 - 2;                    // decremento di  2 interi   
  printf("valore di pi2     = 0x%X\n", pi2);
  diff = pi1 - pi2;                 // differenza tra puntatori   
  printf("valore di diff    = %d\n", diff);
 
  printf("\n\n");
  
  */ 
 
}

/* File: algebraPunta.cpp                  */
/* Time-stamp: "2011-07-05 00:28:26        */
/* Scopo:  scrittura diretta in un vettore */
/* HOEPLI - Informatica in C e C++ - 2016  */




/*
 // Allocaz.dinamica di 10 byte per memorizzare numeri reali
 float *pf;
 pf = (float*) malloc(10); 

 // Allocaz.dinamica di 6 interi "liberi" dal tipo di HW 
 int *pi;
 pi = (int*) malloc(6*sizeof(int));

*/
