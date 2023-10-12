// bidirezionali 
#include <list>
#include <iostream>
#include <stdlib.h>   
#include <ctime>    
using namespace std;
 
void print(list<int>::iterator a, list<int>::iterator b){
  list<int>::iterator p;
  cout << "head->";
  for (p = a; p != b; ++p) 
	  cout << "[" << *p << "]->" ;
  cout << "tail" << endl;
}

void printRev(list<int>::reverse_iterator a, list<int>::reverse_iterator b){
  list<int>::reverse_iterator p;
  cout << "tail->";
  for (p = a; p != b; ++p) 
	  cout << "[" << *p << "]->" ;
  cout << "head" << endl;
}

void casuale(list<int> &listRef, int tanti, int max){
 int x ;
 for(x = 0; x < tanti; x++) 
   listRef.push_back(rand() % max);
}

int main(){
  int tanti = 8, range = 10;
  srand((unsigned)time(NULL));
  list<int> lista1;         // def. lista 
  casuale(lista1, tanti, range);
  cout << "\nvisualizzazione della lista nelle due direzioni: " << endl;
  print(lista1.begin(), lista1.end());
  printRev(lista1.rbegin(), lista1.rend());
  return 0;
}

   



