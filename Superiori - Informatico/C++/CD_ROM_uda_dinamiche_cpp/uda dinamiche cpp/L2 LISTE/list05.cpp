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
  cout << "NULL" << endl;
}

void casuale(list<int> &listRef, int tanti, int max){
 int x ;
 for(x = 0; x < tanti; x++) 
   listRef.push_back(rand() % max);
}


int main(){
  int tanti = 6, range = 10;
  srand((unsigned)time(NULL));
  list<int> lista1, lista2;         // def. 2 liste 
  casuale(lista1, tanti, range);
  casuale(lista2, tanti, range);
  cout << "\nliste prima del sort(): " << endl;
  print(lista1.begin(), lista1.end());
  print(lista2.begin(), lista2.end());
  lista1.sort();                   // ordiniamo le  liste 
  lista2.sort();
  cout << "\nliste dopo il sort(): " << endl;
  print(lista1.begin(), lista1.end());
  print(lista2.begin(), lista2.end());
  lista1.merge(lista2);             // fusione delle liste  
  cout << "\nliste dopo il merge(): " << endl;
  print(lista1.begin(), lista1.end());
  return 0;
}

 
  



