#include <stdio.h>
#include <stdlib.h>
struct s_nodo{
  int info;                 // campo informazione
  struct s_nodo *next;      // campo per il collegamento
};
typedef struct s_nodo nodo; // nodo della lista 
typedef nodo *puntaNodo;    // puntatore ad un elemento 
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
 
void inserisciCodaLista(puntaNodo *lista, int dato){                                   
  puntaNodo ultimo;                        //puntatore usato per la scansione 
  puntaNodo pNodo;                         // puntatore di servizio temporaneo
  pNodo = (puntaNodo)malloc(sizeof(nodo)); // creazione del nuovo record              
  pNodo->info = dato;          
  pNodo->next = NULL;                     // NULL perchè sarà l'ultimo in lista 

  if (*lista == NULL)              // scansione della lista per trovare l'ultimo 
    *lista = pNodo;
  else{
    ultimo = *lista;               // ipotizzo che sia l'ultimo 
    while (ultimo->next != NULL)   // se ha un record "agganciato"
      ultimo = ultimo->next;       // sposta il puntatore al prossimo
    ultimo->next = pNodo;          // alla fine pongo il nuovo record come ultimo       
  }
}  // fine inserisciCodaLista 

int main(){
// definizione delle variabili statiche e loro inizializzazione 
  int x,quanti;
  puntaNodo pTesta;      /* puntatore al primo elemento della lista   */
  puntaNodo pNodo;       /* puntatore ad un generico nodo             */
  pTesta= NULL;          /* inizializzazione dei puntatori            */
  pNodo = NULL;      
  printf("\n Quanti numeri vuoi visualizzare ? ");
  scanf ("\ %d",&quanti);
       
// creazione di una lista alternando testa/coda   
  for  (x=1;x<=quanti;x++) 
    if ((x%2)*x==x)
      inserisciCodaLista(&pTesta,x);   /* aggiungo un elemento in coda  */
    else
     inserisciTestaLista(&pTesta,x);   /* aggiungo un elemento in testa */

  printf("\n\n Visualizzo la lista ricorsivamente \n");
  stampaListaRicorsiva(pTesta);        /* visualizza la lista ricorsiva */ 
  printf("\n\n Visualizzo la lista ricorsivamente ed invertita\n");
  stampaListaInvertita(pTesta);        /* visualizza la lista ricorsiva */ 
  printf("\n\n");

  }
  
/* File: inserisciCodaSol.cpp                                    */
/* Time-stamp: "2015-07-05 00:28:26                              */
/* Scopo: ceazione di una lista di coda e sua visualizzazione    */  
/* HOEPLI - Informatica in C e C++ - 2016                        */

  
