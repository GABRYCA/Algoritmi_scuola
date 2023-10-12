// crea la coda inserendo gli elementi in testa alla lista  
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  
#define MAXLEN 20

// definizione della struttura NODO
struct s_nodo{
  int info;                 // campo informazione
  struct s_nodo *pnext;     // campo per il collegamento
};
typedef struct s_nodo nodo; // nodo della coda  
typedef nodo *puntaNodo;    // puntatore ad un elemento 

// pseudofunzioni ADT
void creaCoda (puntaNodo*, puntaNodo*);
bool isVuota(puntaNodo pTesta);
void inCoda (puntaNodo*, puntaNodo*, int);
void stampaCoda (puntaNodo);
void creaCodaRandom(puntaNodo*, puntaNodo*, int);

//================================================== 
// FUNZIONE DI VERIFICA PILA VUOTA
bool isVuota(puntaNodo pTesta) {
  if (pTesta == NULL) 
    return true;
  else 
    return false;
}

// funzione che crea la coda
void creaCoda (puntaNodo *pTesta, puntaNodo *pFine){
  *pTesta = NULL;
  *pFine  = NULL;
  return;
}

// inserimento di un nodo come primo elemento della lista 
void inCoda (puntaNodo *pTesta, puntaNodo *pFine, int dato){
  nodo* pNuovo;                         // punta al nuovo nodo
  nodo* pTempo;                         // punta ad un nodo di servizio 
  nodo* pCorrente;                      // punta ad un nodo di servizio 
  pNuovo = (nodo*)malloc(sizeof(nodo)); // creo un nuovo nodo
  if (pNuovo != NULL) {
    pNuovo->info = dato;                // inizializzo il nuovo nodo  
    pNuovo->pnext = NULL;
    // aggancio del record prima dell'ultimo inserito
    if (*pTesta != NULL)
      pNuovo->pnext = *pTesta;          // non è il primo nodo della coda
    *pTesta = pNuovo;                   // aggiorno la testa
    // se è il primo elemento testa e coda coincidono  
    if (*pFine == NULL)
      *pFine = *pTesta;
  }
  else
    printf ("\n\tErrore di allocazione del nodo!\n\t");   
  return;
}

void creaCodaRandom(puntaNodo *pTesta, puntaNodo *pFine, int quanti){
  int x, dato ;  
  creaCoda (pTesta, pFine);            // crea coda vuota 
  for (x = 0; x < quanti; x++){
    dato = rand() % 9 + 1;             // genero casualmente il dato     
    inCoda (pTesta, pFine, dato);      // lo inserisco nella coda
  }
}
 
// FUNZIONE DI STAMPA A VIDEO DEI NODI DELLA coda
void stampaCoda (nodo* prec){
  int i, n;
  nodo* pAppo = NULL;
  if (!isVuota(prec)) {    
  // conto i nodi per ottimizzare i motivi grafici
    pAppo = prec;
    n = 1;
    while (pAppo != NULL) {
      pAppo = pAppo-> pnext;
      n = n + 1; 
    }
    //stampo la cornice superiore adattandola al numero di nodi dell coda
    printf("\n\n");
    for(i = 1; i <= 2 * n; i++)
      printf("----");
    printf("\n");
    // stampo i nodi della coda
    printf("(Last In) [pTesta]->");
    i = 1;
    while (prec != NULL){
      printf (" %2d ->", prec->info);
      prec = prec-> pnext;
      i  = i + 1; 
    }   
    printf(" NULL ");
    printf("\n      ");
    for(i = 1; i < n; i++)
      printf("\t");
    printf("    [pFine]");

    printf("\n      ");
    // stampo la cornice inferiore adattandola al numero di nodi della coda
    for(i = 1; i <= 2 * n; i++)
      printf("----");
    
	printf("\n");
    printf ("\n\tcoda stampata con successo \n\t");
  }
  else
    printf ("\n\tLa coda e' vuota!\n\t");
return;
}

// programma principale
int main(){
  // dichiarazione variabili locali
  int x, dato;
  int tanti = 5;
  puntaNodo pTesta;
  puntaNodo pFine;
  
  // creazione coda
  creaCodaRandom (&pTesta, &pFine, tanti);
   
  stampaCoda (pTesta);
  
  printf("\n\n");
} 

/* File: provaCoda.cpp                                         */
/* Time-stamp: "2015-07-05 00:28:26                            */
/* Scopo: creazione e visualizzazione di una coda dinamica     */
/* HOEPLI - Informatica in C e C++ - 2016                      */ 

