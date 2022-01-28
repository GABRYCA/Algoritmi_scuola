#include <stdio.h>
#include <stdlib.h>
struct s_nodo{
  int info;                       // campo informazione
  struct s_nodo *next;            // campo per il collegamento
};
typedef struct s_nodo nodo;       // nodo della lista 
typedef nodo *puntaNodo;          // puntatore ad un elemento 
void stampaLista(puntaNodo lista)
{
  while (lista != NULL) {
    printf("%4d ", lista->info);
    lista = lista->next;
  }
};   /* stampaLista */
void stampaListaRicorsiva(puntaNodo lista){
  if (lista != NULL) {
    printf("%4d ", lista->info);
    stampaListaRicorsiva(lista->next);
  }
}  /* StampaListaRicorsiva */

void stampaListaInvertita(puntaNodo lista)
  /* Stampa la lista lis in ordine invertito.  Versione ricorsiva. */
{
  if (lista != NULL) {
    stampaListaInvertita(lista->next);
    printf("%4d ", lista->info);
  }
}  /* StampaListaInvertita */

/* Inserisce l'elemento elemento in testa alla lista *plista */
void inserisciTestaLista(puntaNodo *plista, int elemento){
  puntaNodo tempo;
  tempo = (puntaNodo)malloc(sizeof(nodo));  /* alloca spazio in memoria           */
  tempo->info = elemento;        /* aggiorna il campo informazione     */
  tempo->next = *plista;         /* gli collega la lista precedente    */
  *plista = tempo;               /* diviene la nuova testa della lista */
}  /* fine inserisciTestaLista */

 
main(){
// definizione delle variabili statiche e loro inizializzazione 
  int x,quanti;
  puntaNodo pTesta;         /* puntatore al primo elemento della lista   */
  puntaNodo pUltimo;        /* puntatore all'ultimo elemento della lista */
  puntaNodo pNodo;          /* puntatore ad un generico nodo             */
  pTesta= NULL;             /* inizializzazione dei puntatori            */
  pNodo = NULL;           

// creazione di una con dummy                                                 
  inserisciTestaLista(&pTesta,1);    /* aggiungo un elemento in coda */
  printf("\n Quanti numeri vuoi visualizzare ? ");
  scanf ("\%d",&quanti);
  pUltimo=pTesta;
// creazione di una lista alternando testa/coda   
  for  (x=2;x<=quanti;x++) 
  {
    pNodo = (puntaNodo)malloc(sizeof(nodo));              
    pUltimo->next = pNodo;          /* gli collega la lista precedente    */
    pNodo->info = x;                /* aggiorna il campo informazione     */
    pNodo->next = NULL;             /* gli collega la lista precedente    */
    pUltimo=pNodo;
  }
  printf("\n\n Visualizzo la lista ricorsivamente \n");
  stampaListaRicorsiva(pTesta);      /* visualizza la lista ricorsiva */ 
  printf("\n\n Visualizzo la lista ricorsivamente ed invertita\n");
  stampaListaInvertita(pTesta);      /* visualizza la lista ricorsiva */ 
  printf("\n\n");
  system("PAUSE");
}

/* File: inserisciCoda2.cpp                                      */
/* Time-stamp: "2015-07-05 00:28:26                              */
/* Scopo: creazione di una lista di coda e sua visualizzazione   */  
/* HOEPLI - Informatica in C e C++ - 2016                        */

