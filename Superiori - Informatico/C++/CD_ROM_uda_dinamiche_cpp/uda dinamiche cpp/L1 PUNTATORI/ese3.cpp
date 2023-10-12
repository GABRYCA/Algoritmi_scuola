#include <stdio.h>
#include <stdlib.h>
int main(){            
  int num1=2, num2=3, num3=4, *pi1, *pi2, diff, temp;   
  pi1 = &num3;                       
  pi1 = pi2;                       
  pi1 = &num1;        
  temp = *pi1;
  pi2 = &num2;      
  num3 = temp*2+*pi2;
  num3 = *pi1*2+*pi2-12;
  *pi1 = *pi2;
  *pi2 = temp;
  num1 = *pi1 + num2*2;
  num2 = *pi1- temp;
  diff = num1-num2**pi1+num3;
       
  printf("valore di num1    = %d\n", num1);
  printf("valore di num2    = %d\n", num2);
  printf("valore di num3    = %d\n", num3);
  printf("valore di diff    = %d\n", diff);
 }
 
 		
