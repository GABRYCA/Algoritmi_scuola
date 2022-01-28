#include <stdio.h>
#include <stdlib.h>
#define  N 6
int main(){   

int a[N], *p = a, *q, tmp, x;
int sum = 0;

/* versione 1 */
for(x = 0; x < N; x++)
  sum += a[x];

/* versione 2 */
for(x = 0; x < N; x++)
  sum += *(a + x);

/* versione 3 */
for(x = 0; x < N; x++)
  sum += p[x];

/* versione 4 */
for(p = a; p < (a + N); p++)
  sum += *p;

}


/* Time-stamp: "2014-09-06 03:26:06 paolo"    */
/* Scopo: esercizi                            */ 
/* HOEPLI - Informatica in C e C++ - 2016     */

