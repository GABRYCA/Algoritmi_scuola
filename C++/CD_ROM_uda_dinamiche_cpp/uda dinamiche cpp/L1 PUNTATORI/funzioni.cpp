#include <stdio.h>
#include <stdlib.h>
//         S5 = S2 * S3 *S4 - 10
//     S2       S3          S4 
//	(2 + x) *( 3 + y ) * (7*z + 4) -10            // x e y vengono letti da input  

void segmento_S1(int* x, int* y, int* z){
  // fase di input delle variabili 
  printf("S1 elab. parallela processo padre \n");
  printf ("inserisci valore per la variabile x :");
  scanf ("%d", x);
  printf ("inserisci valore per la variabile y :");
  scanf ("%d", y);
  printf ("inserisci valore per la variabile z :");
  scanf ("%d", z);
  printf("  x: %d, y: %d, z:= %d\n", &x, *y, z);  // ok *y 
}
 
int segmento_S2(int x){
  int k;
  printf(" S2 elab. parallela processo padre \n");
  k = 2 + x;
  printf(" -> S2 = %d\n", k );
 return k; 
} 

int segmento_S3(int y){
  int k;
  printf("   S3 elab. parallela processo figlio 1 \n");
  k = 3 + y;
  printf("   -> S3 = %d\n", k );
  return k; 
}

int segmento_S4(int *z){
  int k;
  printf("    S4 elab. parallela processo figlio 2 \n");
  k = 7 * *z + 4;
  printf("    -> S4 = %d\n", k );
  return k; 
}
 
int segmento_S5(int x, int y, int z){
  int k;
  printf("S5 - elab. finale padre \n");
  k = x * y * z -10 ;
  printf("-> S5 = %d\n", k );
  return k; 
}

void ramo34(int *y, int *z){
  int status;
  int pid4;
  printf("    S4 (figlio2)- \n" );
   
  *z = segmento_S4(z);
  // *z = 4;
   printf("????????  *z:= %d\n", *z);
 
} 

int main(){ 
  int x, y, z, ris, retv1, retv2, status;
  int pid_figlio, pid1, pid2;

  //----------------------------------------------------
  x= 0; y = 0; z = 0;
  printf ("S1 (padre1) - pid \n");
  segmento_S1(&x, &y, &z);
  printf("1  x: %d, y: %d, z:= %d\n", x, y, z);
 

  //----------------------------------------------
   printf("2  x: %d, y: %d, z:= %d\n", x, y, z);
 
   ramo34(&y, &z);     // esecuzione fork processi 3 e 4  (P34)
   printf("3  x: %d, y: %d, z:= %d\n", x, y, z);

   x = segmento_S2(x);
   printf("4  x: %d, y: %d, z:= %d\n", x, y, z);
       
       
  //==========================================     
  ris = segmento_S5(x, y, z);
  printf("5  ris : %d ", ris );
  
  exit( 0 );
} 

 
 
/* Time-stamp: "2014-09-06 03:26:06 paolo"    */
/* Scopo: gesercizi                           */ 
/* HOEPLI - Informatica in C e C++ - 2016     */

