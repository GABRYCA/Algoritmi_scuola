#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct s_nodo{
  int info;                 // campo informazione
  struct s_nodo *next;      // campo per il collegamento
};
typedef struct s_nodo nodo; // nodo della lista 
typedef nodo *puntaNodo;    // puntatore ad un elemento
 
/* Stampa la lista con grafica                 */
void stampaLista(puntaNodo lista){
  while (lista != NULL) {
    printf("[%1d]->", lista->info);
    lista = lista->next;
  }
  printf("NULL");
};   /* stampaLista */

/* Stampa gli elementi della lista: versione ricorsiva. */
void stampaListaRicorsiva(puntaNodo lista){
  if (lista != NULL) {
    printf("%4d ", lista->info);
    stampaListaRicorsiva(lista->next);
  }
}    /* stampaListaRicorsiva */

/* Stampa la lista in ordine invertito: versione ricorsiva. */
void stampaListaInvertita(puntaNodo lista){
  if (lista != NULL) {
    stampaListaInvertita(lista->next);
    printf("%4d ", lista->info);
  }
}   /* stampaListaInvertita */

puntaNodo creaListaTesta(int quanti){
  int x;
  puntaNodo pNodo;                 
  puntaNodo pTesta;                
  pTesta= NULL;           /* inizializzazione dei puntatore iniziale  */
  for (x=0; x<quanti; x++){
    pNodo = (puntaNodo)malloc(sizeof(nodo));   /* allocazione nuovo elemento     */
    pNodo->info = x+1;                         /* scrivo le informazioni         */
    pNodo->next = pTesta;                      /* collego all'ultimo inserito    */
    pTesta=pNodo;                              /* collego il locomotore          */
  }
  return pTesta;
};   /* creaListaTesta */

puntaNodo creaListaRandom(int quanti){
  int x;
  puntaNodo pNodo;                 
  puntaNodo pTesta;                
  pTesta= NULL;           /* inizializzazione dei puntatore iniziale  */
  for (x = 0; x < quanti; x++){
    pNodo = (puntaNodo)malloc(sizeof(nodo));  /* allocazione nuovo elemento     */
    pNodo->info = rand() % 9 + 1;             /* genero casualmente il dato     */
    pNodo->next = pTesta;                     /* collego all'ultimo inserito    */
    pTesta=pNodo;                             /* collego il locomotore          */
  }
  return pTesta;
};   /* creaListaTesta */

int main(){
// definizione delle variabili statiche e loro inizializzazione 
  int x;
  srand(time(NULL));   /* inizializa il seme dei numeri casuali       */
  puntaNodo pTesta;    /* puntatore al primo elemento della lista     */
  puntaNodo pNodo;     /* puntatore ad un generico nodo               */
  pTesta = NULL;       /* inizializzazione dei puntatori              */
  pNodo  = NULL;           

// creazione di una lista di testa                                                
  pTesta = creaListaRandom(6);        /* crea una lista di testa       */ 
  printf("\n\n Visualizzo la lista\n");
  stampaLista(pTesta);               /* visualizza la lista           */ 
  printf("\n\n Visualizzo la lista ricorsivamente \n");
  stampaListaRicorsiva(pTesta);      /* visualizza la lista ricorsiva */ 
  printf("\n\n Visualizzo la lista ricorsivamente ed invertita\n");
  stampaListaInvertita(pTesta);      /* visualizza la lista ricorsiva */ 

  printf("\n\n");
}

/* File: listaSempliceSol.cpp                                   */
/* Time-stamp: "2015-07-05 00:28:26                             */
/* Scopo: ceazione di una lista di testa e sua visualizzazione  */  
/* HOEPLI - Informatica in C e C++ - 2016                       */


