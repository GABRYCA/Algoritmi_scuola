#include <stdio.h>
#include <stdlib.h>
struct s_nodo{
  int info;                 // campo informazione
  struct s_nodo *next;      // campo per il collegamento
};
typedef struct s_nodo nodo; // nodo della lista 
typedef nodo *puntaNodo;    // puntatore ad un elemento 

void stampaLista(puntaNodo lista){
  while (lista != NULL) {
    printf(" [%1]->", lista->info);
    lista = lista->next;
  }
  printf("NULL");
};   /* stampaLista */

void stampaListaRicorsiva(puntaNodo lista){
  if (lista != NULL) {
    printf(" [%1d] ->", lista->info);
    stampaListaRicorsiva(lista->next);
    }
  else
    printf("NULL");
};   /* stampaLista 
}  /* StampaListaRicorsiva */

void stampaListaInvertita(puntaNodo lista)
  /* Stampa la lista lis in ordine invertito.  Versione ricorsiva. */
{
  if (lista != NULL) {
    stampaListaInvertita(lista->next);
    printf("%4d ", lista->info);
  }
}  /* StampaListaInvertita */

puntaNodo creaListaTesta1(int quanti){
  int x;
  puntaNodo pNodo;                 
  puntaNodo pTesta;                
  pTesta= NULL;           /* inizializzazione dei puntatore iniziale */
  for (x=0; x<quanti; x++){
    pNodo = (puntaNodo)malloc(sizeof(nodo));   /* allocazione nuovo elemento    */
    pNodo->info = x+1;              /* scrivo le informazioni        */
    pNodo->next = pTesta;           /* collego all'ultimo inserito   */
    pTesta=pNodo;                   /* collego il locomotore         */
  }
  return pTesta;
};   /* creaListaTesta */

int inserisciCodaLista(puntaNodo *lista, int dato){                                   
  puntaNodo ultimo;                  /* puntatore usato per la scansione   */
  puntaNodo pNodo;                   /* puntatore di servizio temporaneo   */
  /* creazione del nuovo record  */
  pNodo = (puntaNodo)malloc(sizeof(nodo));              
  pNodo->info = dato;          
  pNodo->next = NULL;                /* NULL perchè sarà l'ultimo in lista */
  /* scansione della lista per trovare l'ultimo*/
  if (*lista == NULL)
    *lista = pNodo;
  else {
    ultimo = *lista;
    while (ultimo->next != NULL)
      ultimo = ultimo->next;
  /* concatenazione del nuovo record in coda alla lista */
    ultimo->next = pNodo;               
  }
}  /* fine inserisciCodaLista */

int main(){
  // definizione delle variabili statiche e loro inizializzazione 
  int x;
  puntaNodo pTesta;      /* puntatore al primo elemento della lista   */
  puntaNodo pNodo;       /* puntatore ad un generico nodo             */
  pTesta = NULL;         /* inizializzazione dei puntatori            */
  pNodo  = NULL;           
  // creazione di una lista di coda                                                
  inserisciCodaLista(&pTesta, 1);    /* aggiungo un elemento in coda  */
  inserisciCodaLista(&pTesta, 2);    /* aggiungo un elemento in coda  */
  inserisciCodaLista(&pTesta, 3);    /* aggiungo un elemento in coda  */
  printf("\n\n Visualizzo la lista ricorsivamente \n");
  stampaListaRicorsiva(pTesta);      /* visualizza la lista ricorsiva */ 
  printf("\n\n Visualizzo la lista ricorsivamente ed invertita\n");
  stampaListaInvertita(pTesta);      /* visualizza la lista ricorsiva */ 
}

/* File: inserisciCoda.cpp                                       */
/* Time-stamp: "2015-07-05 00:28:26                              */
/* Scopo: ceazione di una lista di coda e sua visualizzazione    */  
/* HOEPLI - Informatica in C e C++ - 2016                        */




