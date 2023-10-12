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
  int n1, n2, *pi1, *pi2;
  n1=4;
  n2=8;
  pi1=&n2;
  pi2=&n2;
  *pi1=*pi2+n1;
  *pi2=*pi1-n1+*pi2;
  pi2=&n1;
  *&n1=*pi1-*pi2;
  *pi1=n2/2+*pi2/2;
  *pi2=*&n1+*pi1+*pi2;
  n2=*pi2+n1-*pi1;
  printf("*&n1= %d, *&n2= %d, *pi1= %d, *pi2= %d",*&n1, *&n2, *pi1, *pi2);
  printf("\n\n");
  system("pause");
}

