/* File: primaPila.cpp                         */
/* Time-stamp: "2015-07-05 00:28:26            */
/* Scopo: creazione automatica di una pila     */ 
/* ==> con le funzioni interne al programma    */ 
/* HOEPLI - Informatica in C e C++ - 2016      */

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
void push (pila *pTesta, int dato); 

void stampaPila(pila);
pila creaPilaRandom(int quanti);

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
  int x;
  puntaNodo pNodo;                 
  puntaNodo pTesta;                
  pTesta = NULL;                    // inizializzazione dei puntatore iniziale  
  for (x = 0; x < quanti; x++){
    pNodo = (puntaNodo)malloc(sizeof(nodo));   // allocazione nuovo elemento     
    pNodo->info = rand() % 9 + 1;   // genero casualmente il dato     
    pNodo->next = pTesta;           // collego all'ultimo inserito    
    pTesta=pNodo;                   // aggorno testa della lista        
  }
  return pTesta;
};   /* crea pila di quanti elementi  */

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

// FUNZIONE DI STAMPA A VIDEO DEI NODI DELLA PILA
void stampaPila(pila pTesta){
  int x, num;
  puntaNodo ptemp;
  if(!isVuota(pTesta)) {
  // conto i nodi per la veste grafica 

  // stampo la pila 
    system ("CLS");

    printf ("|_______________________|  Fondo della pila\n\n\t");
  }
  else{
    printf ("\n\tOPERAZIONE IMPOSSIBILE: La pila e' vuota \n\n\t"); 
  }
  return;
}

// programma principale
int main(int argc, char *argv[]){
  // dichiaraziuone variabili locali
  puntaNodo pTesta;
  int tanti;
  // ripulisco lo schermo
  system("CLS");
  
  // chiamo la funzione che crea la pila di tanti elementi 
  printf("Quanti elementi inserirsco nella pila? ");
  scanf("%d", &tanti);
  pTesta = creaPilaRandom(tanti);

  // chiamo la funzione che visualizza la pila
  stampaPila (pTesta); 
  return 0;
}



