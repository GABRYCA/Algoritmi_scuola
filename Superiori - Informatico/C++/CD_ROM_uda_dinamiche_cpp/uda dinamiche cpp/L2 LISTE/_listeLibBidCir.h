// libreria per le liste bidirezionali 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // necessaria la libreria per le var booleane 
#include <time.h>
//-------------------------------------------------------------------------
// informazione un campo di tipo intero ==================================
struct s_nodo{
  int info;                 // campo informazione
  struct s_nodo *prec;      // campo per il collegamento al precedente
  struct s_nodo *next;      // campo per il collegamento al successivo
  
};
typedef struct s_nodo nodo; // nodo della lista 

typedef nodo *lista    ;    // puntatore alla testa della lista/sottolista
typedef nodo *puntaNodo;    // puntatore ad un elemento 
//-------------------------------------------------------------------------

// funzioni primitive 
lista listaVuota();                                    // ritorna una lista vuota			
lista creaListaRandom(lista pCorrente, int quanti);   // crea lista di quanti elementi in modo casuale 
bool isVuota(lista lis1);               	            // vero se lista vuota						

void stampaListaHT(lista lis1);               // visualizza la lista dalla testa alla coda                  
void stampaListaTH(lista lis1);               // visualizza la lista dalla coda alla testa                   
bool trova (int dato, lista lis1);       	    // vero se dato è nella lista			
bool ctrOrdinata(lista lis1);                 // controlla se lista ordinata crescente 	
int contaElementi(lista lis1);				        // ritorna il nr. degli elementi 																	//	X
bool isMembro(int dato, lista lis1);		      // cerca ricorsivamente un elemento nella lista 															
int cercaDx (int dato, lista lis1);           // trova posizione di dato verso destra 
int cercaSx (int dato, lista lis1);           // trova posizione di dato verso sinistra 
lista inserisciOrdinato(int dato, lista lis1);      // inserisce ricorsivamente un dato in una lista 															
int ripetizioni (int dato, lista lis1);             // trova il numero di occorrenze in una lista
int piuRipetuto (lista lis1);                       // trova l'elemento con più ripetizione nella lista 
int cambiaTutti (int dato1, int dato2, lista lis1); // sostituisci tutte le occorrenze di dato1 con dato2  
lista scambiaPosto(int dato, lista lis1);           // scambia un elemento con suo predecessore
lista togliElemento(int dato, lista lis1);
lista ordinaLista(lista lis1);                      // ordinamento crescente dei dati di una lista x inserzione  
lista bubbleLista(lista lis1);                      // ordinamento con bubble sort 
//====================================================================================================

//================================================== 
lista listaVuota(){
 	puntaNodo pCorrente;    
  pCorrente = NULL;
  return pCorrente;
}

//------------------------------
bool isVuota(lista lis1) {
  if (lis1 == NULL) 
    return true;
  else 
    return false;
}

//-----------------------------------------------------------
lista inserisciNodo (int dato, lista pCorrente) { 
  puntaNodo pNodo;                           
  pNodo = (puntaNodo) malloc(sizeof(nodo)); // allocazione nuovo elemento     
  pNodo->info = dato;        
  if (isVuota(pCorrente)){      // se la lista è vuota punta a se stesso
 	  pCorrente   = pNodo;
    pNodo->next = pNodo;        // successivo punta  a lui
	  pNodo->prec = pNodo;        // precedente punta  a lui   
  }	
  else
  {
    pNodo->next = pCorrente->next;  // lo inserisco come secondo elemento 
    pNodo->prec = pCorrente;    
    pCorrente->next->prec = pNodo;  // 
    pCorrente->next = pNodo;        // 
 	}
  return pCorrente;
}
	
//-------------------------------------------
lista creaListaRandom(lista pCorrente, int quanti){
  int i, dato; 
  for (i = 1; i <= quanti; i++){
    dato = rand() % 9 + 1;             // genero casualmente il dato       
    pCorrente = inserisciNodo (dato, pCorrente) ; 
  }
  return pCorrente;
}

//  printf("valore di punta  %d  %d  = 0x%X\n", i, pNodo->info, pNodo->next);

//------------------------------
void stampaListaHT(lista pCorrente){
  lista pTempo;
  pTempo = pCorrente;
  printf(" [pCorrente]=>");
  if (isVuota(pTempo))                     // lista vuota
    printf("NULL \n");
  else
  {
    printf("[%1d]<=>", pCorrente->info);    // visualizza il primo
    while (pTempo != pCorrente->next){
      pCorrente = pCorrente->next;
      printf("[%1d]<=>", pCorrente->info);
    }
    printf("[pCorrente]");  
	}
}

//------------------------------
void stampaListaTH(lista pCorrente){
  lista pTempo;
  pTempo = pCorrente;
  printf(" [pCorrente]=>");
  if (isVuota(pTempo))                      // lista vuota
    printf("NULL \n");
  else
  {
    printf("[%1d]<=>", pCorrente->info);    // visualizza il primo
    while (pTempo != pCorrente->prec){
      pCorrente = pCorrente->prec;
      printf("[%1d]<=>", pCorrente->info);
    }
    printf("[pCorrente]");  
	}
}


bool trova (int dato, lista lis1)		      // cerca  un elemento nella lista 															
{
	bool trovato = false;
	lista lis_inizio;
	lis_inizio = lis1;		// salvo indirizzo del primo elemento
	do
	{
		if (lis1->info == dato){
			trovato = true;
     	return trovato ;
		}
		else
			lis1 = lis1->next;
  } while(lis1 != lis_inizio);
 	return trovato ;
}


int cercaDx (int dato, lista lis1)           // trova posizione di dato verso destra 
{
	bool trovato = false;
   // DA FARE 
 	return 0 ;
}

int cercaSx (int dato, lista lis1)           // trova posizione di dato verso destra 
{
	bool trovato = false;

   // DA FARE 
 	return 0 ;
}
 

//-------------------------------------------
bool ctrOrdinata(lista lis1){ 
   // DA FARE 

   
}



//-------------------------------------------
int contaElementi(lista lis1){
   // DA FARE 

}

/* =================================================
   Ritorna la posizione di un elemento cercato
   Richiama le primitiva trova() 	
*/
int posizione(int dato, lista lis1){
   // DA FARE 

}

/* =================================================
   Ritorna la testa della lista 
   Richiama le primitiva isVuota() 	
*/
int testa(lista lis1) {
   // DA FARE 

   	
}

 
/* File: _listeLibBidCir.h                  */
/* Time-stamp: "2015-07-05 00:28:26         */
/* Scopo: libreria liste bidirezionali      */  
/* HOEPLI - Informatica in C e C++ - 2016   */ 


 

