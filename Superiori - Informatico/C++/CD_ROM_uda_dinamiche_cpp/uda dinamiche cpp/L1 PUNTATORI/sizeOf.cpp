#include <stdio.h>
int main(){
  char *pchar;
  int *pint;
  double *pdouble;
  // visulizza le dimensioni dei puntatori
  printf("sizeof(pchar)  = %d, sizeof(pint)  = %d, sizeof(pdouble)  = %d\n",
         sizeof(pchar), sizeof(pint), sizeof(pdouble));
  printf("sizeof(char *) = %d, sizeof(int *) = %d, sizeof(double *) = %d\n\n",
         sizeof(char *), sizeof(int *), sizeof(double *));
  // visulizza le dimensioni delle variabili
  printf("sizeof(*pchar) = %d, sizeof(*pint) = %d, sizeof(*pdouble) = %d\n",
         sizeof(*pchar), sizeof(*pint), sizeof(*pdouble));
  printf("sizeof(char)   = %d, sizeof(int)   = %d, sizeof(double)   = %d\n",
         sizeof(char), sizeof(int), sizeof(double));
}


/* File: sizeOf.c pp                      */
/* Time-stamp: "2014-07-05 00:28:26       */
/* Scopo:  sizeof per tipi puntatore      */
/* HOEPLI - Informatica in C e C++ - 2016 */
