/* File: libreria di funzioni per la pila                                */
/* Time-stamp: "2015-07-05 00:28:26                                      */
/* Scopo: allocazione dinamica di una PILA o STACK con lista concatenata */
/* HOEPLI - Informatica in C e C++ - 2016                                */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   // necessaria la libreria per le var booleane 

// definizione della struttura NODO
struct s_nodo{
  int info;                 // campo informazione
  struct s_nodo *next;      // campo per il collegamento
};
typedef struct s_nodo nodo; // nodo della pila 
typedef nodo *puntaNodo;    // puntatore ad un elemento 
typedef nodo *pila     ;    // puntatore al TOP della pila

// nuove funzioni 
pila creaPila (void);     
bool isVuota(pila pTesta);
pila creaPilaRandom(int quanti);
void push (pila *pTesta, int dato); 
void pop (pila *pTesta);

void stampaPila    (pila);
void deallocaPila  (pila);

// funzioni con comunicazione all'utente
void push1 (pila*, int); 
void pop1 (pila*);


//================================================== 
// FUNZIONE DI CREAZIONE DELLA PILA VUOTA
pila creaPila (void) {
  return NULL;
}

// FUNZIONE DI VERIFICA PILA VUOTA
bool isVuota(pila pila1) {
  if (pila1 == NULL) 
    return true;
  else 
    return false;
}

 pila creaPilaRandom(int quanti){
   int x, dato ;
   pila temp, pTesta;
   pTesta = creaPila ();              // crea pila vuota                
   for (x = 0; x < quanti; x++){
     dato = rand()%9 + 1;             // genero casualmente il dato     
     push (&pTesta, dato);            // lo inserisco nell pila
   }
   return pTesta;
};   /* crea pila di quantie lementi  */


// FUNZIONE DI INSERIMENTO DI UN NODO IN TESTA DELLA PILA 
void push (pila *pTesta, int elemento){
  puntaNodo pNuovo;
  // creazione del nuovo nodo da aggiungere in testa alla lista
  pNuovo = (pila) malloc (sizeof(nodo));
  if (pNuovo != NULL){
    pNuovo->info = elemento;
    pNuovo->next = *pTesta;      // collego alla vecchia pila      
    *pTesta = pNuovo;            // aggiorno la testa della pila   
  }
}


// FUNZIONE DI INSERIMENTO DI UN NODO IN TESTA DELLA PILA (senza parametro di ritorno)
void push1 (pNodo *pTesta, int elemento){
  pNodo pNuovo;
  // creazione del nuovo nodo da aggiungere in testa alla lista
  pNuovo = (pNodo) malloc (sizeof(nodo));
  if (pNuovo != NULL){
    pNuovo->info = elemento;
    pNuovo->next = *pTesta;
    //aggiornamento del puntatore della testa
    *pTesta = pNuovo;
  }
  else
    printf ("\n\tErrore nell'allocazione di memoria!\n\n\t");
}

// FUNZIONE DI PRELEVAMENTO DI UN NODO DALLA TESTA DELLA PILA  (senza comunicazioni)
void pop (pNodo *pTesta){
 pNodo pTempo = NULL;        // variabile temporanea 
  if(*pTesta != NULL) {        
   //aggiornamento della testa della pila e liberazione spazio allocato per nodo
   pTempo = *pTesta;
   if ((*pTesta)->next != NULL)
     *pTesta = (*pTesta)->next;
   else
     *pTesta = NULL;
   free(pTempo);                 // dealloco lo spazio
 }
 return;
}

// FUNZIONE DI PRELEVAMENTO DI UN NODO DALLA TESTA DELLA PILA  (senza parametro di ritorno)
void pop1 (pila *pTesta){
 puntaNodo pTempo = NULL;        // variabile temporanea 
  if(*pTesta != NULL) {        
   // prelevamento del nodo dalla testa della pila
   printf ("\n\tL'elemento prelevato dalla testa della pila e':  %2d     \n\n\t", (*pTesta)->info);
   //aggiornamento della testa della pila e liberazione spazio allocato per nodo
   pTempo = *pTesta;
   if ((*pTesta)->next != NULL)
     *pTesta = (*pTesta)->next;
   else
     *pTesta = NULL;
   free(pTempo);                 // dealloco lo spazio
 }
 else
   printf ("\n\t Attenzione: la PILA e'  vuota \n\n\t"); 
 return;
}

// FUNZIONE DI STAMPA A VIDEO DEI NODI DELLA PILA
void stampaPila (pila pTesta){
  int x, num;
  puntaNodo ptemp;
  if(!isVuota(pTesta)) {       // oppure (*pPrec != NULL){ 
//  if( pPrec != NULL) {        // oppure (*pPrec != NULL){ 
    /* conto i nodi per la veste grafica */
    ptemp = pTesta;
    num = 1;
    while (ptemp != NULL){  
      ptemp = ptemp-> next;
      num = num + 1; 
    }
    // stampo la pila 
    system ("CLS");
    x = 1;
    printf ("\n\n\n\t_                       _ \n\t");
    printf ("|                       |  Testa della pila\n\t");
    while (pTesta != NULL){
      printf ("| %2d^ nodo = %3d\t|\n\t", --num, pTesta->info);
      pTesta = pTesta->next;
      x = x + 1; 
    }
    printf ("|_______________________|  Fondo della pila\n\n\t");
  }
  else{
    printf ("\n\tOPERAZIONE IMPOSSIBILE: La pila e' vuota \n\n\t"); 
  }
  return;
}

// FUNZIONE DI DEALLOCAZIONE DEI NODI DELLA PILA
void deallocaPila (puntaNodo pTesta){
  puntaNodo pCorrente;
  if (!isVuota(pTesta)) {                    
    while (pTesta != NULL){
      pCorrente = pTesta;
      // pPrec punta al nodo seguente 
      pTesta = pCorrente->next;
      free(pCorrente);
    }
    // la pila deve essere ricreata
    printf ("\n\tPila deallocata con successo \n\t");
    printf("(Garbage collection ad opera del programmatore)\n\n\t");
  }
  else{
    printf ("\n\tOPERAZIONE IMPOSSIBILE: La pila e' vuota \n\n\t");
  }
  return;
}

