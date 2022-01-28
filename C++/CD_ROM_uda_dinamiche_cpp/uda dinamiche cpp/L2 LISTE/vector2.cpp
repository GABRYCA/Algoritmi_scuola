#include <vector>
#include <iostream>
using namespace std;

int main() {
  int x, valore ;
  vector<int> vet_int;
  cout<<"Digita 0 per terminare l'inserimento \n";
  while (valore != 0)
  {
    cout<<"Inserisci un numero: ";
    cin >> valore;
    vet_int.push_back(valore);
  }
  for (x =0 ;x < vet_int.size(); x++){  
    cout << vet_int[x] << " ";
  }

  for (x =0 ;x < vet_int.size(); x++){ 
    cout << vet_int.at(x) << " ";
  }

}
  



