// allocazione di un vettore di float  
#include <stdio.h>
#include <stdlib.h>
int miaFunzione(){
  int *pa;
  int num = 100;
  . . . 
  pa  = (int*)malloc(sizeof(int)); // allocazione dinamica 
  
  *pa = 69;        // assegno a *pa un valore          
  free(pa);         // deallocazione di *pa 
  ...
  *pa = 777;        // errore di DANDLING REFERENCE 

}  






