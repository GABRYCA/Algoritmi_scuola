#include <stdio.h>
#include <stdlib.h>
struct s_nodo{
  int info;                  // campo informazione
  struct s_nodo *next;       // campo per il collegamento
};
typedef struct s_nodo nodo;  // nodo della lista 
typedef nodo *puntaNodo;     // puntatore ad un elemento 

void stampaLista(puntaNodo lista){
  while (lista != NULL) {
    printf("%4d", lista->info);
    lista = lista->next;
  }
}; // fine stampaLista 

int main(){
// definizione delle variabili statiche e loro inizializzazione 
  int x;
  puntaNodo pTesta;    /* puntatore al primo elemento della lista    */
  puntaNodo pNodo;     /* puntatore ad un generico nodo              */
  pTesta= NULL;        /* inizializzazione dei puntatori             */
  pNodo = NULL;           
// creazione di una lista di testa                                                
  for ( x = 0; x < 3; x++){
    pNodo = (puntaNodo) malloc(sizeof(nodo));   /*  nuovo elemento   */
    pNodo->info = x + 1;            /* scrivo le informazioni        */
    pNodo->next = pTesta;           /* collego all'ultimo inserito   */
    pTesta=pNodo;                   /* collego il locomotore         */
  }
  printf("\n\n Visualizzo la lista\n");
  stampaLista(pTesta);              /* visualizza la lista           */ 
 }

/* File: listaSemplice.cpp                                      */
/* Time-stamp: "2015-07-05 00:28:26                             */
/* Scopo: ceazione di una lista di testa e sua visualizzazione  */  
/* HOEPLI - Informatica in C e C++ - 2016                       */
 



