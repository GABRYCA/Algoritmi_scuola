#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // necessaria la libreria per le var booleane 
#include <time.h>
//-------------------------------------------------------------------------
// informazione un campo di tipo intero ==================================
struct s_nodo{
  int info;                 // campo informazione
  struct s_nodo *next;      // campo per il collegamento
};
typedef struct s_nodo nodo; // nodo della lista 

typedef nodo *lista    ;    // puntatore alla testa della lista/sottolista
typedef nodo *puntaNodo;    // puntatore ad un elemento 
//-------------------------------------------------------------------------

// funzioni primitive 
lista listaVuota(void);                       // ritorna una lista vuota			
bool isVuota(lista lis1);                  	  // vero se lista vuota						

// funzioni non primitive
lista inserisciNodo(int dato, lista lis);     // appende un elemento in lista 			
lista creaListaRandom(int quanti);            // crea lista di quanti elementi in modo casuale 
void stampaLista(lista lis1);                 // visualizza la lista                   
bool trova (int dato, lista lis1);     	      // vero se dato è nella lista			
int posizione(int dato, lista lis1);     	  // 0 = non trovato,  x = posizione 			
bool ctrOrdinata(lista lis1);                 // controlla se lista ordinata crescente 	
int contaElementi(lista lis1);				  // ritorna il nr. degli elementi 																	//	X

bool isMembro(int dato, lista lis1);		           // cerca ricorsivamente un elemento nella lista 															
lista inserisciOrdinato(int dato, lista lis1);     // inserisce ricorsivamente un dato in una lista 															
int ripetizioni (int dato, lista lis1);        	   // trova il numero di occorrenze in una lista
int piuRipetuto (lista lis1);                      // trova l'elemento con più ripetizione nella lista 
int cambiaTutti (int dato1, int dato2,lista lis1); // sostituisci tutte le occorrenze di dato1 con dato2  
lista scambiaPosto(int dato, lista lis1);          // scambia un elemento con suo predecessore
lista togliElemento(int dato, lista lis1);
lista ordinaLista(lista lis1);                     // ordinamento crescente dei dati di una lista x inserzione  
lista bubbleLista(lista lis1);                     // ordinamento con bubble sort 
//====================================================================================================

//================================================== 
lista listaVuota(void) {
	struct s_nodo* next; // puntatore prossimo nodo
	struct s_nodo* head; // puntatore all'inizio della lista
return NULL;
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
  pNodo = (puntaNodo) malloc(sizeof(nodo));  // allocazione nuovo elemento     
  pNodo->info = dato;        
  if (isVuota(pCorrente)){                   // se la lista è vuota punta a se stesso
 	  pCorrente   = pNodo;
    pNodo->next = pNodo;   
  }	
  else
  {
    pNodo->next = pCorrente->next;           // lo inserisco come primo elemento 
    pCorrente->next = pNodo;
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

//--------------------------------------------------------------------
void stampaLista(lista pCorrente){
  lista pTempo;
  pTempo = pCorrente;
  printf(" [pCorrente]->");
  if (isVuota(pTempo))                     // lista vuota
    printf("NULL \n");
  else
  {
    printf("[%1d]->", pCorrente->info);    // visualizza il primo
    while (pTempo != pCorrente->next){
      pCorrente = pCorrente->next;
      printf("[%1d]->", pCorrente->info);
    }
  printf("[pCorrente]");  
  }
}
  
//-------------------------------------------
bool trova(int dato, lista lis1){
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

//-------------------------------------------
int posizione(int dato, lista lis1){
	bool trovato = false;
	int conta = 0;
	lista lis_inizio;
	lis_inizio = lis1;		// salvo indirizzo del primo elemento
	do
	{
	  conta++; 
		if (lis1->info == dato){
			trovato = true;
     	return conta ;
		}
		else
			lis1 = lis1->next;
  } while(lis1 != lis_inizio);
  return 0 ;
}

//-------------------------------------------
int contaElementi(lista lis1){
  int conta = 0;
  lista lis_inizio;
  lis_inizio = lis1;		        // salvo indirizzo del primo elemento
  do
  {
    conta++; 
	  lis1 = lis1->next;
  } while(lis1 != lis_inizio);
return conta ;
}

//-------------------------------------------
bool ctrOrdinata(lista lis1){ 
	bool corretto = true;
	int elemento = lis1->info;	        // assegno il primo valore
	lista lis_inizio = lis1;	        // salvo l'inizio della lista per confrontare quando ricomincia
	lis1 = lis1->next;
	do{
		if (elemento > lis1->info )		// controllo se è ordinato
		{
			corretto = false;			// aggiorno "corretto" in base al risultato
		}
		elemento = lis1->info;
		lis1 = lis1->next;
	}while (lis1 != lis_inizio);
	return corretto ;
}


/* =================================================*/
int cambiaTutti1 (int dato1, int dato2, lista lis1) {
// sostituisci tutte le occorrenze di dato1 con dato2  
	int tot;
	tot = contaElementi(lis1);
	while(tot>0)
	{
		if (lis1->info==dato1)
		{
			lis1->info=dato2;
		}
		tot--;
	}

return 1;
}

/* =================================================
   Ritorna se un elemento è presente ricorsivamente() 
   Richiama le primitiva isVuota() 	
   Accoda due liste ricorsivamente 
*/
lista accodaListe(lista lis1, lista lis2) {
	if (isVuota(lis1)) {
		return lis2;
	}
	else {
//		return inserisciTesta(testa(lis1), accodaListe(coda(lis1), lis2));
	}
}

/* ============================================================
   Accoda due liste ricorsivamente - un dato alla volta  
   Richiama le primitiva isVuota() inserisciTesta() inserisciOrdinato()
*/
lista inserisciOrdinato(int dato, lista lis1){

}

/*ordinamento con bubble sort */ 
lista bubbleLista(lista lista1) {
struct s_nodo *p, *ultimo;
  int flag, temp;
	ultimo = NULL;
	flag = 1;
  while (flag == 1) {
    p = lista1;
    flag = 0;
    while (p->next != ultimo) {
      if (p->info > (p->next)->info) {
        temp = p->info;
        p->info = (p->next)->info;
        (p->next)->info = temp;
        flag = 1;
      }
      p = p->next;
    }
    ultimo = p;
  }
  return(lista1);
}

/* File: _listeLibCir.h                     */
/* Time-stamp: "2015-07-05 00:28:26         */
/* Scopo: libreria liste circolari ali      */  
/* HOEPLI - Informatica in C e C++ - 2016   */ 

 

