#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  main(){
  int n = 7;
  // dichiaro una stringa stringa e la inizializziamo:
  char stringa[] = "pippo"; 
  
  // dichiaro un array A di 3 stringhe di lunghezza diversa:  
  char *A1[3] = {"ali", "baba", "pluto"};

  A1[2] = stringa;  // ->  A[2] diventa “pippo” 
  printf("  A1[2]    : %s\n", A1[2]);

  // dichiaro un array A di 3 stringhe di lunghezza max = 15 
  char A2[3][15] = {"ali", "baba", "pluto"};
  //A+1 contiene il puntatore a “baba” --> *(A+1) è “baba”

  char *A3[n]; // indica un array di n puntatori 
 // char *A4[];  // indica un puntatore ad un array di puntatori ossia un puntatore a puntatore 



 // La notazione char *A[] è equivalente a char ** A (puntatore doppio) 
 /* Attenzione a come vengono definiti gli array, per non “incappatre” in errori di assegnazione:
  char A[3][] 	={“qui”, ”quo”, ”qua”}   	//dich. dinamica 
  char B[3][15] 	={“qui”, ”quo”, ”qua”} 		//dich. statica 
  char **C 		={“qui”, ”quo”, ”qua”}      	//dich. dinamica

 *(B[2]+2) è ammessa;  è equivalente a: 
  – *([x+15*2) con char *x =&B[0] ossia l’indirizzo di B 
  – *(*(B+2)+2)
  – entrambe restituiscono la lettera “q” di qua
  - notare che *(B+2)+y è uguale a B[2]+y = x+2*15+y 
  *(B+2) = B[2] = x+2*15 (indirizzi della stringa arrivederci)


 */
}
