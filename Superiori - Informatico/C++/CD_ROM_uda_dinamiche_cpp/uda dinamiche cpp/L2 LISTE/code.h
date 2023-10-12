/* File: libreria di funzioni per la coda                                */
/* Time-stamp: "2015-07-05 00:28:26                                      */
/* Scopo: allocazione dinamica di una CODA con lista concatenata         */
/* HOEPLI - Informatica in C e C++ - 2016                                */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  

// definizione della struttura NODO
struct s_nodo{
  int info;                 // campo informazione
  struct s_nodo *pnext;     // campo per il collegamento
};
typedef struct s_nodo nodo; // nodo della coda  
typedef nodo *pNodo;    // puntatore ad un elemento 

// pseudofunzioni ADT
void creaCoda (pNodo*, pNodo*);
bool isVuota(pNodo pTesta);
void inCoda (pNodo*, pNodo*, int);
void outCoda (pNodo*, pNodo*);
void stampaCoda (pNodo);
void creaCodaRandom(pNodo* , pNodo* , int );

//================================================== 
// FUNZIONE DI VERIFICA CODA VUOTA
bool isVuota(pNodo pTesta) {
  if (pTesta == NULL) 
    return true;
  else 
    return false;
}

// funzione che crea la coda
void creaCoda (pNodo *pTesta, pNodo *pFine){
  *pTesta = NULL;
  *pFine  = NULL;
  return;
}

// inserimento di un nodo come primo elemento della lista 
void inCoda (pNodo *pTesta, pNodo *pFine, int dato){
  nodo* pNuovo;      // punta al nuovo nodo
  nodo* pTempo;      // punta ad un nodo di servizio 
  nodo* pCorrente;   // punta ad un nodo di servizio 
  pNuovo=(nodo*)malloc(sizeof(nodo));  //creo un nuovo nodo
  if (pNuovo != NULL) {
    pNuovo->info = dato;           // inizializzo il nuovo nodo  
    pNuovo->pnext = NULL;
    //aggancio del record prima dell'ultimo inserito
    if (*pTesta != NULL)
      pNuovo->pnext = *pTesta;    // non è il primo nodo della coda
    *pTesta = pNuovo;             // aggiorno la testa
    //se è il primo elemento testa e coda coincidono  
    if (*pFine == NULL)
      *pFine = *pTesta;
  }
  else
    printf ("\n\tErrore di allocazione del nodo!\n\t");   
}

// FUNZIONE DI PRELEVAMENTO DI UN NODO DALLA TESTA DELLA CODA 
void outCoda (pNodo *pTesta, pNodo *pFine){
  pNodo pAppo;
  pNodo pCur;
  pAppo = NULL;
  pCur = NULL;
  // mi posiziono al fondo della coda
  pAppo = *pTesta;
  // prelevamento del nodo dalla testa della coda
  printf ("\n\tL'elemento prelevato dalla testa della coda e' %3d \n\t", (*pFine)->info);
  //aggiornamento della testa della coda e liberazione spazio allocato per nodo
  if (*pTesta != *pFine){ 
    while(pAppo != *pFine){
      pCur = pAppo;
      pAppo  = pAppo->pnext;
   }
   // aggiorno il ptr alla fine della coda
   *pFine=pCur;
   (*pFine)->pnext = NULL;
   //dealloco lo spazio
   free(pAppo); 
 }
  else{
   //dealloco lo spazio
   free(pAppo);
   *pTesta = NULL;
   *pFine = NULL;
   printf ("\n\tLa coda si e' svuotata: occorre ricrearla!\n\t");
  } 
}

void creaCodaRandom(pNodo *pTesta, pNodo *pFine, int quanti){
  int x, dato ;  
  creaCoda (pTesta, pFine);            // crea coda vuota 
  for (x = 0; x < quanti; x++){
    dato = rand()%9 + 1;               // genero casualmente il dato     
    inCoda (pTesta, pFine, dato);      // lo inserisco nella coda
  }
}
 
// FUNZIONE DI STAMPA A VIDEO DEI NODI DELLA CODA
void stampaCoda (nodo* prec){
  int i, n;
  nodo* pAppo = NULL;
  if (!isVuota(prec)) {     // ossia if(prec != NULL)
// conto i nodi per ottimizzare i motivi grafici
    pAppo = prec;
    n = 1;
    while (pAppo != NULL) {
      pAppo = pAppo-> pnext;
      n = n + 1; 
    }
    //stampo la cornice superiore adattandola al numero di nodi dell coda
    printf("\n\n      ");
    for(i = 1; i <= 2*n; i++)
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
    printf(" NULL  ");
    printf("\n      ");
    for(i = 1; i < n; i++)
      printf("\t");
    printf("    [pFine]");

    printf("\n      ");
    // stampo la cornice inferiore adattandola al numero di nodi della coda
    for(i = 1; i <= 2*n; i++)
      printf("----");
    
	printf("\n");
    printf ("\n\tcoda stampata con successo \n\t");
  }
  else
    printf ("\n\tLa coda e' vuota!\n\t");
return;
}

 
