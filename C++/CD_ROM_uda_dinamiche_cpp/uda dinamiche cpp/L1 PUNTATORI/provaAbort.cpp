#include <cstdlib>
#include <iostream>
void abort(void);
using namespace std;
int main(int argc, char *argv[]){
  double num1, num2;
  cout<< "Fornisci il dividendo: ";
  cin >> num1;
  cout<< "Fornisci il divisore: ";
  cin >> num2;
  if (num2 == 0)
    abort();
  cout << "Il risultato della divisione e': " << num1 / num2 << "\n";
  return EXIT_SUCCESS;
}


/* Time-stamp: "2014-09-06 03:26:06 paolo"    */
/* Scopo: gesercizi                           */ 
/* HOEPLI - Informatica in C e C++ - 2016     */

