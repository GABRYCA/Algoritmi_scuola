/* Time-stamp: "2015-07-05 00:28:26                 */
/* Scopo: file incompleto per prove e esercitazioni */ 
/* HOEPLI - Informatica in C e C++ - 2016           */


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
void listaVuota(lista *pTesta, lista *pCoda);                   // ritorna una lista vuota			
void creaListaRandom(int quanti, puntaNodo *pTesta, puntaNodo *pCoda);      // crea lista di quanti elementi in modo casuale 
bool isVuota(lista lis1);               	  // vero se lista vuota						
void stampaListaHT(lista lis1);               // visualizza la lista dalla testa alla coda                  
void stampaListaTH(lista lis1);               // visualizza la lista dalla coda alla testa                   
bool trova (int dato, lista lis1);       	  // vero se dato è nella lista			
bool ctrOrdinata(lista lis1);                 // controlla se lista ordinata crescente 	
int contaElementi(lista lis1);				  // ritorna il nr. degli elementi 																	//	X

// funzioni da fare primitive
lista inserisciTesta(int dato, lista lis1);   // appende un elemento in testa 			
lista inserisciCoda (int dato, lista lis1);   // appende un elemento in coda 			
lista subLista(int num, lista lis1) ;         // crea due liste, la prima di num elementi

// funzioni da fare non primitive
void mostraLista(lista lis1); 				   // visualizza la lista (ricorsiva)     
int posizione(int dato, lista lis1);     	   // 0 = non trovato,  x = posizione 			
int testa(lista lis1);                   	   // ritorna valore del primo elemento della lista 			
lista coda(lista lis1);                 	   // toglie il primo elemento della lista					
lista accodaListe (lista lis1, lista lis2) ;   // accoda un elemento alla volta - ricorsivamente															
lista inserisciOrdinato(int dato, lista lis1); // inserisce ricorsivamente un dato in una lista 															
int ripetizioni (int dato, lista lis1);        // trova il numero di occorrenze in una lista
lista cambiaTutti (int dato1, int dato2, lista lis1); // sostituisci tutte le occorrenze di dato1 con dato2  
lista rovesciaLista(lista lis1);
lista scambiaPosto(int dato, lista lis1);      // scambia un elemento con suo predecessore
lista copy(lista lis1, lista lis2);                       
lista togliElemento(int dato, lista lis1);
lista mergeListe(lista lis1, lista lis2);       // fusione ordinata di due liste      
lista ordinaLista(lista lis1);                  // ordinamento crescente dei dati di una lista x inserzione  
lista bubbleLista(lista lis1);                  // ordinamento con bubble sort 
//====================================================================================================

//================================================== 
void listaVuota(lista *pTesta, lista *pCoda){
   // Autore : prof  
  *pTesta = NULL;
  *pCoda  = NULL;
}

//------------------------------
bool isVuota(lista lis1) {
   // Autore : prof  
  if (lis1 == NULL) 
    return true;
  else 
    return false;
}

//------------------------------
void stampaListaHT(lista lis1){
   // Autore : prof  
  while (lis1 != NULL) {
    printf("[%1d]->", lis1->info);
    lis1 = lis1->next;
  }
  printf("NULL \n");
};   /* stampaListaTesta */

//------------------------------
void stampaListaTH(lista lis1){
   // Autore : prof  
  while (lis1 != NULL) {
    printf("[%1d]->", lis1->info);
    lis1 = lis1->prec;
  }
  printf("NULL \n");
};   /* stampaListaCoda */

//------------------------------------------
lista inserisciTesta(int elem, lista lis1) { 
  lista temp;                      // creo lista temporanea
  temp = (lista) malloc(sizeof(nodo));
  temp->info = elem;               // aggiunge l'elemento elem alla lista temporanea
  temp->next = lis1;               // accoda alla lista temp la lista lis1
  temp->prec = NULL;
  lis1->prec = temp;
  return temp;                     // ritorna la lista con aggiunto elem di testa
}

//------------------------------------------
lista coda(lista lis1){                 //  Rimuove il primo elemento dalla lista
  lista pNodo;
  if (isVuota(lis1)) {
    abort(); 
  }
  else
  { 
    pNodo->info= NULL;
    pNodo->next=lis1;
  }
}

//------------------------------------------
lista inserisciCoda ( int ele,  lista lis ){	
  lista aux = lis ;
  if ( lis == NULL )
  { 	
    lis = ( lista ) malloc ( sizeof ( nodo ) ) ;
    lis -> info = ele ;
    lis -> next = NULL ;
    lis -> prec = NULL ;
  }  
  else 
  {
    while ( aux -> next != NULL )
    {
      aux = aux -> next ;
    } 
    aux -> next =  ( lista ) malloc ( sizeof ( nodo ) ) ;
    aux = aux -> next ;
    aux -> info = ele ;
    aux -> next = NULL ; 		
  }  
  return lis ;
}


//-------------------------------------------
bool trova(int dato, lista lis1){
   // Autore : prof  
  int trovato = false;
  while ((!trovato) && (lis1 != NULL)) {
    if (lis1->info == dato)
  		trovato = true;
  	else
      lis1 = lis1->next ;
  }  
  return trovato ;
}


//-------------------------------------------
lista subLista(int num, lista lis1){
  	// Controllo input utente
	if (num <= 0)
	{
		return NULL;
	}
	struct s_nodo *testa, *nodo, *prec;
	int i;
	
	nodo = NULL;
	testa = NULL;

	for (i = 1; i <= num; i++)
	{
		// salvo elemento precedente (null se sono al primo giro)
		prec = nodo;

		// creo il nuovo elemento
		nodo = (struct s_nodo *)malloc(sizeof(struct s_nodo));

		// valorizzo il campo "informazione" del nodo corrente
		printf("Inserisci il %d%c elemento: ", i, 167);
		scanf("%d", &nodo->info);

		// collego il nodo corrente con il precedente
		nodo -> prec = prec;

		// inizializzo il successivo del nodo corrente
		nodo -> next = NULL;

		// collego il nodo precedente con il suo successivo (nodo corrente)
		if (prec != NULL)
		{
			prec -> next = nodo;
		}

		// salvo il nodo corrente nel primo elemento (solo al primo giro)
		if (testa == NULL)
		{
			testa = nodo;
		}
	}
	return testa;
}

//-------------------------------------------
bool ctrOrdinata(lista lis1){ 
   // Autore : prof  
  int prec=0, corretto = 1;
  while ((lis1 != NULL) && (corretto == 1)){
 	if (prec <= lis1->info)
	{  //confronto
      prec = lis1->info ;
      lis1 = lis1->next ;
    }
    else
      corretto  = 0; 
  }
  return corretto ;
}

//-------------------------------------------
void creaListaRandom(int quanti, puntaNodo *pHead, puntaNodo *pTail){
  int x;
  srand(time(0));
  puntaNodo pNodo;                  // nuovo nodo da inserire
  for (x = 0; x < quanti; x++){
    pNodo = (puntaNodo)malloc(sizeof(nodo));   // allocazione nuovo elemento     
    pNodo->info = rand() % 9 + 1;   // genero casualmente il dato       
    // lista da testa a coda
    pNodo->next = *pHead;           // collego all'ultimo inserito    
    pNodo->prec = NULL ;            // ultimo elemento della lista dalla coda    
    if (x == 0){                    // primo elemento 
      // inizializza la lista da coda a testa col primo elemento 
      pNodo->prec = *pTail;         // collego all'ultimo inserito    
      *pTail  = pNodo;              // aggiorno coda che coincide con la testa         
    } 
    else {
      (*pHead)->prec = pNodo;      // collego all'ultimo inserito      
    } 
    *pHead = pNodo;                // aggiorno testa della lista          
  }
}


//-------------------------------------------
int contaElementi(lista lis1){
   // Autore : prof  
  int conta = 0 ;
  while (lis1 != NULL){
    conta ++ ;
    lis1 = lis1->next ;
  }
  return conta ;
}
//================== funzioni non primitive  


/* =====================================================================
   Visualizza la lista ricorsivamente  
   Richiama le primitive  isVuota() 	
 */
void mostraLista(lista lis1){ //stesso ordine di stampa lista RICORSIVA
 
	if (isVuota(lis1)){
		printf("[NULL] \n");
	}
	else{
	    printf("[%d]<->",testa(lis1));
	    mostraLista(lis1->next); //accorcio la lista
    }
}

/* =================================================
   Ritorna la posizione di un elemento cercato
   Richiama le primitiva trova() 	
*/
int posizione(int dato, lista lis1){
   // Autore : prof  
  bool trovato = 0 ;   
  int conta   = 0 ;           // conta posizione
  if (trova(dato, lis1)) {
    while ((!trovato) && (lis1 != NULL)) {
   	  conta++;                // contatore di posizione 
      if (lis1->info != dato)
        lis1 = lis1->next ;
      else 
   	    trovato = true ;      // flag x uscire dalla ricerca
    }  
  }  
  return conta;
}

/* =================================================
   Ritorna la testa della lista 
   Richiama le primitiva isVuota() 	
*/
int testa(lista lis1) {
   // Autore : prof  
  if (isVuota(lis1)){ 
    abort();          // interrompe l'eleborazione  
  }               
  else{
    return lis1->info;
  }
}

