#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <ctime>

using namespace std;

int main(){
  srand((unsigned)time(NULL));
  vector<double> numeri;
  int num = 8;	 
	double valore = 1;
  // allocazione num variabili intere 
  for (int x = 0; x < num; x++)
    numeri.push_back(rand() % 10);
  cout<<"\n Elenco dei valori generati: ";
  for (int i=0; i<numeri.size();i++)
    cout<<numeri[i]<<" - ";
  cout << "\n Il vettore contiene ";
  cout << numeri.size() << " elementi\n";
  cout << "\n togliamo l'ultimo elemento: ";
  numeri.pop_back();   // estraiamo l' ultimo elemento
  cout << "ora il vettore contiene ";
  cout << numeri.size() << " elementi\n";
  cout<<"\n Elenco dei valori rimasti: ";
  for (int i=0; i<numeri.size();i++)
    cout<<numeri[i]<<" - ";
}

  




