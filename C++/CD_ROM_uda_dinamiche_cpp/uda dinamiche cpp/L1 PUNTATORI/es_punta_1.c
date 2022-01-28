// autore : Tommaso Arrighi
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
using namespace std;
int main()
{
  int n1, n2, n3;
  int *pi1, *pi2, **pi3;
  n1=2;
  n2=5;
  n3=11;
  pi1=&n2;
  pi2=&n1;
  pi3=&pi2;
  n1=*pi1*n1+**pi3-*pi2;
  *pi1=*pi2-n3+n2;
  pi1=&n3;
  pi3=&pi1;
  *pi1=n2+**pi3-*pi2;
  printf("n1 = %d, n2= %d, n3= %d, *pi1= %d, *pi2= %d, **pi3= %d\n",n1,n2,n3,*pi1,*pi2,**pi3);

  pi2=&n2;
  pi1=&n1;
  n3=n1+*pi1+**pi3;
  *pi1=*pi2+**pi3+n2;
  pi3=&pi2;
  n2=n3-*pi1+**pi3;
  n1=n3+**pi3+*pi1;
  printf("n1 = %d, n2= %d, n3= %d, *pi1= %d, *pi2= %d, **pi3= %d",n1,n2,n3,*pi1,*pi2,**pi3);
  printf("\n\n");
  system("pause");
}

