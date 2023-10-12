#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
using namespace std;

int main(){            
  int num1=3, num2=6, num3=9, *pi1, *pi2 , diff, temp ;   
  pi1 = &num3;                       
  pi1 = pi2;                       
  pi1 = &num1;        
  temp = *pi1;
  pi2 = &num2;      
  *pi1 = *pi2;
  *pi2 = temp;
  num1 = *pi1 + num2*2;
  num2 = *pi1- temp ;
  diff = num1-num2**pi1;
      
  printf("valore di num1    = %d\n", num1);
  printf("valore di num2    = %d\n", num2);
  printf("valore di diff    = %d\n", diff);
              
  printf("valore di pi1     = 0x%X\n", pi1);
  printf("valore di pi2     = 0x%X\n", pi2);
  
  return 0;
 
 }
 
 		
