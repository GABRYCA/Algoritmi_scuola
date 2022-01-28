#include <iostream>
#include <cstdlib>
#include <ctime>  
#include "albBinLib.h"           // nostra libreria di funzioni 

using namespace std;                                                         

int main(){
  int x, num, valore, altezza, livelli, riempi = 1;
  int *vetHeap;                 // vettore in formato heap 
  
	int vetHeap1 [7]= {10, 8,-9, 0,15, 0, 3};   
  int vetHeap2 [7]= {10, 4,30, 0, 8,16,50};   
  	 
	// inizio programma principale  
  srand((unsigned)time(NULL));  // inizializza il seme 
  pNodo radice= NULL, radice1= NULL, radice2 = NULL;          // puntatore radice dell'albero

  radice1 = da_array_a_albero (vetHeap1, 0, 7);  // genera l'albero  
  printf("stampa grafica albero 1 \n");
  stampa_grafica(radice1);

  radice2 = da_array_a_albero (vetHeap2, 0, 7);  // genera l'albero  
  printf("stampa grafica albero 2 \n");
  stampa_grafica(radice2);
 
  // creazione dell'albero partendo dal vettore heap  
  printf("Quanti nodi vuoi inserire ? ");
  scanf("%d", &num);
  
	vetHeap = genera_array (num);                  // genera i numeri  
  radice = da_array_a_albero (vetHeap, 0, num);  // genera l'albero dal vettore
  printf("stampa grafica \n");
  stampa_grafica(radice);
  
  // creazione dell'albero partendo dal vettore heap  
  printf("Quale nodo vuoi inserire ? ");
  scanf("%d", &num);
  radice = ABR_inserisci(radice, num); 

   // ricerca elemento   
  printf("Quale nodo vuoi cercare ? ");
  scanf("%d", &num);
  if (ABR_ricercaRic(radice, num))
    printf("il nodo %d e' presente nell'albero.", num );
  else
    printf("il nodo %d non e' presente nell'albero.", num );
   
  // ---------------- inizio elaborazione sull'albero binario 
  printf("\naltezza albero : ");              // calcola l'altezza 
  altezza = altezza_albero(radice);
  printf("%d  \n", altezza);
  livelli = altezza +1;                       // calcola i livelli 
  printf("livelli albero : ");
  printf("%d  \n\n", livelli);

  printf("\naltezza albero : ");              // calcola l'altezza 
  altezza = altezza_albero(radice);
  printf("%d  \n", altezza);
 
  printf("somma chiavi : ");
  valore = somma_chiavi(radice);
  printf("%d  \n", valore);
  printf("\n\n");

  printf("stampa parentetica : ");
  stampa_parentetica(radice);
  printf("\n\n");

  printf("stampa preorder    : ");
  stampa_preorder(radice);
  printf("\n");
  
  printf("stampa inorder     : ");
  stampa_inorder(radice);
  printf("\n");
  
  printf("stampa postorder   : ");
  stampa_postorder(radice);
  printf("\n");
  
  printf("stampa per livelli : ");
  stampa_per_livello(radice);
  printf("\n");
  
  printf("stampa grafica \n");
  stampa_grafica(radice);
  
	
	printf("\n");

} 


/* File: alberiBin.cpp                                */
/* Time-stamp: "2015-07-05 00:28:26                   */
/* Scopo: chiamata delle funzioni su alberi binari    */
/* HOEPLI - Informatica in C e C++ - 2016             */

 


