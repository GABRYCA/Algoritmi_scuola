// autore : Tommaso Arrighi
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
int main()
{
  int n1, n2, n3, *pi1, *pi2;
  n1=2;
  n2=3;
  n3=5;
  pi1=&n3;
  pi2=&n1;
  *pi2=n2+*pi2+*pi1+*&n1;
  pi1=&n2;
  pi2=&n3;
  *&n3=*pi2+n1+*pi1;
  *pi1=n1+*pi1;
  pi2=&n1;
  *pi2=n1+*pi1+*pi2;
  pi2=&n2;
  *pi1=n3+*pi2+*&n2;
  printf("n1= %d, n2= %d, *pi1= %d, *pi2= %d",n1,n2,*pi1,*pi2);
  printf("\n\n");
  system("pause");
}

