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

int main(){
  int x, tanti = 6;
  srand((unsigned)time(NULL));
  list<int> lista1, lista2;         // def. 2 liste 
  for(x = 0; x < tanti; x++){       // riempimento casuale    
    lista1.push_back(rand() % 10);
    lista2.push_back(rand() % 10);
	} 
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

 
  



