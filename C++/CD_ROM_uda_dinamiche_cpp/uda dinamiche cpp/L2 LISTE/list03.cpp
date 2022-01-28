#include <list>
#include <iostream>
using namespace std;
int main(){
	int x, tanti = 10;
  list<int> lista;
  for(x = 0; x < tanti; x++) 
    lista.push_back(x);
  // definizione iteratore 
  list<int>::iterator p;
  x = 0;
  for (p = lista.begin(); p != lista.end(); p++) 
     cout << "Elemento " << x++ << ": " << *p << endl;  
  return 0;
}
 



