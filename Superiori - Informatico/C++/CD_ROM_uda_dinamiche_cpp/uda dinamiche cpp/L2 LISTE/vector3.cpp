#include <vector>
#include <iostream>
using namespace std;

int main() {
  int x, num;
   vector<int> vet_int;             // definizione di un vettori di interi
   cout << "Quanti elementi desideri: ";
   cin >> num;                      // numeri di elementi del vettore 
              
   for (x = 1; x <= num; x++){
     vet_int.push_back(x);          // aggiunge un elemento 
   }
   
   for (x = vet_int.size() - 1; x >= 0; x--){  // visualizza a rovescio
      cout << vet_int[x] << " ";
   }
}
  



