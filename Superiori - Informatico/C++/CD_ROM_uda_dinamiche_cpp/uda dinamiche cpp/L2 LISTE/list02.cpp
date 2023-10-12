#include <list>
#include <iostream>
using namespace std;

int main(){
	int x, tanti = 10;
  list<int> lista;
  for(x = 0; x < tanti; x++) 
    lista.push_back(x);
  for (x = 0; x < tanti; x++) {
    cout << "Elemento " << x << ": " << lista.back() << endl;
    lista.pop_back();
  }
  return 0;
}

 
  



