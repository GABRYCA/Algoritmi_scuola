// allocazione di un vettore di float  
#include <stdio.h>
#include <stdlib.h>
int main()
{
  int *pa;
  int *pb;
  pa  = (int*)malloc(sizeof(int)); // allocazione dinamica della I cella intera 
  printf("indirizzo di pa= 0x%x\n", pa);

  *pa = 222;        // assegno a *pa un valore          
  free(pa);         // deallocazione di *pa 
  ...
  *pa = 777;        // errore di DANDLING REFERENCE 
  
  printf("indirizzo di pb= 0x%x\n", pA);
  printf("\n\n");
  system("PAUSE");
}                            // con perdita del riferimento alla II cella           





/* Time-stamp: "2014-09-06 03:26:06 paolo"    */
/* Scopo: esercizi                            */ 
/* HOEPLI - Informatica in C e C++ - 2016     */

