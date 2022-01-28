#include <stdio.h>
int main(){
  //scambio tramite i valori
  int n1 = 10, n2 = 20, temp;
  temp = n1;
  n1 = n2;
  n2 = temp;
  printf("\n n1= %d n2= %d", n1, n2);
  // scambio tramite i puntatori
  int *pn1, *pn2;
  pn1 = &n1;         // *pn1 diventa un alias per n1 
  pn2 = &n2;         // *pn2 diventa un alias per n2 
  temp = *pn1;
  *pn1 = *pn2;
  *pn2 = temp;
  printf("\n n1= %d n2= %d", n1, n2);
}


/* File: scambioVariabili.cpp             */
/* Time-stamp: "2015-04-05                */
/* Scopo:  scambio di due variabili       */
/* HOEPLI - Informatica in C e C++ - 2016 */

