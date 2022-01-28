#include <stdio.h>
#include <stdlib.h>
int main(){   
  int vet[5] ;   // dichiarazione di un vettore di 5 elementi 
  printf ("\nvet     -> 0x%X \n&vet[0] -> 0x%X ",  vet  ,  &vet[ 0 ] );
  printf( "\nvet+1   -> 0x%X \n&vet[1] -> 0x%X ",  vet+1 , &vet[ 1 ] );
  printf( "\nvet+2   -> 0x%X \n&vet[2] -> 0x%X ",  vet+2 , &vet[ 2 ] );

  int x;
  for ( x = 0; x < 5; x ++) 
    vet[x] = 100+x;  


  printf( "\n\n vet    -> %d \n&vet[0] -> %d ",   vet ,   &vet[ 0 ] );
  printf( "  \n vet+1  -> %d \n&vet[1] -> %d ",   vet+1 , &vet[ 1 ] );

  printf( "\n\n*vet    -> %d \nvet[0]  -> %d ",  *vet ,   vet[ 0 ] );
  printf( "  \n*vet+1  -> %d \nvet[1]  -> %d ",  *vet+1 , vet[ 1 ] );

  printf( "\n\n&vet[0]  -> %d \nvet      -> %d ",   &vet[0] ,  vet  );
  printf( "  \n&vet[1]  -> %d \nvet +1   -> %d ",  &vet[1] ,  vet +1);

  printf( "\n\n*vet[0]  -> %d \n*(vet+1) -> %d ",  vet[0] , *(vet));
  printf( "  \n*vet[1]  -> %d \n*(vet+1) -> %d ",  vet[1] , *(vet+1));



}



 
