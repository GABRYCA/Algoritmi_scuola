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
void listaVuota(lista *pHead, lista *pTail); // ritorna una lista vuota			
void creaListaRandom(int quanti, puntaNodo *pHead, puntaNodo *pTail); // crea lista  
bool isVuota(lista pHead);               	 // vero se lista vuota						
void stampaListaHT(lista pHead);             // visualizza la lista dalla testa                    
void stampaListaTH(lista pHead);             // visualizza la lista dalla coda                     
bool trova (int dato, lista pHead);       	 // vero se dato è nella lista			
bool ctrOrdinata(lista pHead);               // controlla se lista ordinata crescente 	
int contaElementi(lista pHead);				 // ritorna il nr. degli elementi 																	//	X
lista inserisciTesta(int dato, lista pHead); // appende un elemento in testa 			
lista inserisciCoda (int dato, lista pHead); // appende un elemento in coda 			
lista subLista(int num, lista pHead);        // crea due liste, la prima di num elementi

// funzioni da fare non primitive
void mostraLista(lista pHead); 				   // visualizza la lista (ricorsiva)     
int posizione(int dato, lista pHead);     	   // 0 = non trovato,  x = posizione 			
int testa(lista pHead);                   	   // ritorna valore del primo elemento 			
lista coda(lista pHead);                 	   // toglie il primo elemento della lista					
lista accodaListe (lista pHead1, lista pHead2);// accoda un elemento alla volta 															
lista inserisciOrdinato(int dato, lista pHead);// inserisce un dato in una lista 															
int ripetizioni (int dato, lista pHead);       // trova il numero di occorrenze di dato
lista cambiaTutti (int dato1, int dato2, lista pHead); // sostituisci dato1 con dato2  
lista rovesciaLista(lista pHead);
lista scambiaPosto(int dato, lista pHead);     // scambia dato con il suo predecessore           
lista togliElemento(int dato, lista pHead);
lista mergeListe(lista lis1, lista lis2);      // fusione ordinata di due liste      
lista ordinaLista(lista pHead);                // ordinamento crescente x selezione  
lista bubbleLista(lista pHead);                // ordinamento con bubble sort 
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
  while (lis1 != NULL) {
    printf("[%1d]->", lis1->info);
    lis1 = lis1->next;
  }
  printf("NULL \n");
};   /* stampaListaTesta */

//------------------------------
void stampaListaTH(lista lis1){
  while (lis1 != NULL) {
    printf("[%1d]->", lis1->info);
    lis1 = lis1->prec;
  }
  printf("NULL \n");
};   /* stampaListaCoda */

//------------------------------------------
lista inserisciTesta(int elem, puntaNodo pHead) { 
  puntaNodo temp;                       // creo nuovo nodo
  temp = (puntaNodo) malloc(sizeof(nodo));
  temp->info = elem;                    // aggiunge l'elemento inserito da input alla lista temporanea
  temp->next = pHead;                   // accoda alla lista temporanea la lista lis1
  temp->prec = NULL;
  pHead->prec = temp;
  return temp;                          // ritorna la lista completa con aggiunto l'elemento di testa
}

//------------------------------------------
lista coda(lista lis1){                 //  Rimuove il primo elemento dalla lista
  lista pNodo;
  if (isVuota(lis1)) {
    abort(); 
  }
  else
  { 
   // DA FARE 
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
  puntaNodo pNodo;                            // nuovo nodo da inserire
  for (x = 0; x < quanti; x++){
    pNodo = (puntaNodo)malloc(sizeof(nodo));  // allocazione nuovo elemento     
    pNodo->info = rand() % 9 + 1;             // genero casualmente il dato       
    // lista da testa a coda
    pNodo->next = *pHead;                     // collego all'ultimo inserito    
    pNodo->prec = NULL ;                      // ultimo elemento della lista dalla coda    
    if (x == 0){                              // primo elemento 
      // inizializza la lista da coda a testa col primo elemento 
      pNodo->prec = *pTail;                   // collego all'ultimo inserito    
      *pTail  = pNodo;                        // aggiorno coda che coincide con la testa         
    } 
    else {
      (*pHead)->prec = pNodo;                 // collego all'ultimo inserito      
    } 
    *pHead = pNodo;                           // aggiorno testa della lista          
  }
}


//-------------------------------------------
int contaElementi(lista lis1){
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
void mostraLista(lista lis1){          //stesso ordine di stampa lista RICORSIVA
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

/* =================================================
   Ritorna la testa della lista 
*/
lista inserisciOrdinato(int dato, lista lis1)
{
  if ((isVuota(lis1)) || (dato <= testa(lis1))) 
  {
    return inserisciTesta(dato, lis1) ;  
  }
  else if (contaElementi(lis1)==0)
  	{
  		 return inserisciTesta(testa(lis1), inserisciOrdinato(dato, coda(lis1))) ;
	}
	else
	{
		lis1=coda(lis1);
		return inserisciTesta(testa(lis1), inserisciOrdinato(dato, coda(lis1))) ;  
	}
}

//Non ho potuto testarla perchè la funzione isMembro non è ancora stata fatta
lista cambiaTutti (int dato1, int dato2, lista lis1){
	lista temp;
	if (trova(dato1,lis1))	//se il dato è presente allora eseguo
	{
		while (lis1 != NULL)
		{
			if (lis1->info == dato1)	//se trovo una corrispondenza
			{
				temp = inserisciCoda(dato2,temp);		//sostituisco il dato con dato2
			}
			else
			{
				temp = inserisciCoda(lis1->info,temp);	//altrimenti copio il dato normale
			}
			lis1 = lis1->next;
		}
		return temp;
	}
	else 
	{
		return lis1;	//se il dato non è presente allora ritorno lis1
	}
}

int ripetizioni (int dato, lista lis1) 
{
  int el,ripe=0;
  el = contaElementi(lis1);
  while(el > 0)
  {
    if (lis1->info == dato)
	{
	   ripe++;
	}
	lis1 = lis1->next;
	el--;
  }
  return ripe;
}


//*======================================================
lista mergeListe(lista lis1, lista lis2){
  //*****LE LISTE DEVONO ESSERE GIA' ORDINATE*********
  if (isVuota(lis2)){ //seconda lista è vuota
	return lis1 ;
  }
  else{ //si inserisce il secondo
   lis1 = inserisciOrdinato(testa(lis2),lis1);
    return mergeListe(lis1,coda(lis2)) ;
  }	
}

 
/* File: _listeLibBid.h                     */
/* Time-stamp: "2015-07-05 00:28:26         */
/* Scopo: libreria per liste bidirezionali  */  
/* HOEPLI - Informatica in C e C++ - 2016   */ 

 

