#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <ctime>

using namespace std;

int main(){
  srand((unsigned)time(NULL));
  vector<double> numeri;
  int num = 6;	 
 
  // allocazione num variabili intere 
  for (int x = 0; x < num; x++)
    numeri.push_back(x);
  cout<<"\n Elementi presenti nel vettore: ";
  for (int i = 0; i<numeri.size();i++)
    cout<<numeri[i]<<" - ";
  
  // cancella elementi di posto pari
	for (int x = 0; x < num-1; x++){
    if (numeri.at(x) == 3){
 	  //	 numeri.insert(numeri, 33);
    }
	 }
  
 //   numeri.push_back(rand() % 10);
  
  cout<<"\n Elemento di posdizione 3: ";
    cout<<" -> "<< numeri[3]<<" <- ";


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

  




