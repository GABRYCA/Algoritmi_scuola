/* File: primaPilaSol.cpp                      */
/* Time-stamp: "2015-07-05 00:28:26            */
/* Scopo: creazione automatica di una pila     */  
/* HOEPLI - Informatica in C e C++ - 2016      */ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   // necessaria la libreria per le var booleane 
#include <time.h>      // per la generazione casuale elementi della pila 

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

void stampaPila    (pila);
pila creaPilaRandom(int quanti);


//================================================== 
// FUNZIONE DI CREAZIONE DELLA PILA VUOTA
pila creaPila (void){
return NULL;
}

// FUNZIONE DI VERIFICA PILA VUOTA
bool isVuota(pila pila1){
  if (pila1 == NULL) 
    return true;
  else 
    return false;
}

 pila creaPilaRandom(int quanti){
   int x, dato;
   srand(time(0));
   pila temp, pTesta;
   pTesta = creaPila ();              // crea pila vuota                
   for (x = 0; x < quanti; x++){
     dato = rand() % 99 + 1;           // genero casualmente il dato     
     push (&pTesta, dato);            // lo inserisco nell pila
   }
   return pTesta;
};   /* crea pila di quanti elementi  */

// FUNZIONE DI INSERIMENTO DI UN NODO IN TESTA DELLA PILA 
void push (pila *pTesta, int elemento){
  puntaNodo pNuovo;
  // creazione del nuovo nodo da aggiungere in testa alla lista
  pNuovo = (pila)malloc (sizeof(nodo));
  if (pNuovo != NULL){
    pNuovo->info = elemento;
    pNuovo->next = *pTesta;      // collego alla vecchia pila      
    *pTesta = pNuovo;            // aggiorno la testa della pila   
  }
}

// FUNZIONE DI STAMPA A VIDEO DEI NODI DELLA PILA
void stampaPila (pila pTesta){
  int x, num;
  puntaNodo ptemp;
  if(!isVuota(pTesta)){       
    /* conto i nodi per la veste grafica */
    ptemp = pTesta;
    num = 1;
    while (ptemp != NULL){  
      ptemp = ptemp->next;
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

// programma principale
int main(int argc, char *argv[]){
  // dichiaraziuone variabili locali
  int cePila;   	//variabile che indica se la coda è stata creata oppure no
  puntaNodo pTesta;
  int scelta;

  // inizializzazioni
  scelta = 0;
  cePila = 0;
 
  // ripulisco lo schermo
  system("CLS");
  
  // chiamo la funzione che crea la pila di tanti elementi 
  int tanti = 5;
  printf("Quanti elementi inserirsco nella pila? ");
  scanf("%d", &tanti);
  pTesta = creaPilaRandom(tanti);

  // chiamo la funzione che visualizza la pila
  stampaPila (pTesta); 
  return 0;
}

