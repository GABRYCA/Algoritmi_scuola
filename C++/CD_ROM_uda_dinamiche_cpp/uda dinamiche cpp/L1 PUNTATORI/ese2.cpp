#include <stdio.h>
#include <stdlib.h>
int main(){            
  int vet[8], *punta1, x; 
  for(x = 0; x < 8; x++ ){   
   *( vet + x ) = 0;          
  }
  punta1 = vet;                
  for(x = 0; x < 8; x++ ){
    vet[x] = x * 3; 
    printf("valore di x , punta1, vet[%d] = %d 0x%X  %d\n", x, x, punta1, vet[x]);
    x++;
    punta1  = punta1 + 1;         
    *punta1 = x * -3;	
    printf("valore di x , punta1, vet[%d] = %d 0x%X  %d\n", x, x, punta1, vet[x]);  
    punta1  = punta1 + 1;         
  }
}

  
