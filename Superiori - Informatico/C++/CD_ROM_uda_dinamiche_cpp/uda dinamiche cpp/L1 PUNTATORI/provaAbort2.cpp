#include <cstdlib>
#include <iostream>
#include <cmath>

void abort(void);
using namespace std;

int primo(int x){
 int num, flag;
 flag = 1;
 num = 2;
 while (num <= sqrt(x) && flag == 1){
   if (x % num == 0)
     flag = 0;
   num = num +1;
 }
 return(flag);
}

int main(int argc, char *argv[]){
  double num1, num2;
  cout<< "Fornisci il dividendo: ";
  cin >> num1;
  cout<< "Fornisci il divisore: ";
  cin >> num2;
  if (num2 == 0)
    abort();
  cout << "Il risultato della divisione e': " << num1 / num2 << "\n";
  if (primo(num1) == 1)
    cout << "Il numero : " << num1 << " e' primo \n";
  else
    cout << "Il numero : " << num1  << " non e' primo\n";
  
  return EXIT_SUCCESS;
}


/* Time-stamp: "2014-09-06 03:26:06 paolo"    */
/* Scopo: gesercizi                           */ 
/* HOEPLI - Informatica in C e C++ - 2016     */

