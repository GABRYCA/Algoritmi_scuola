/* File: _listeLib.cpp                              */
/* Time-stamp: "2015-07-05 00:28:26                 */
/* Scopo: file incompleto per prove e esercitazioni */ 
/* HOEPLI - Informatica in C e C++ - 2016           */
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
bool isVuota(lista lis1);               	  // vero se lista vuota						
void stampaLista(lista lis1);                 // visualizza la lista                   
lista inserisciTesta(int dato, lista lis);    // appende un elemento in testa 			
bool  trova (int dato, lista lis1);     	  // vero se dato è nella lista			
lista subLista(int num, lista lis1) ;         // crea due liste, la prima di num elementi
bool ctrOrdinata(lista lis1);                 // controlla se lista ordinata crescente 	
lista creaListaRandom(int quanti);            // crea lista di quanti elementi in modo casuale 
int contaElementi(lista lis1);				  // ritorna il nr. degli elementi 																	//	X


// funzioni non primitive
void mostraLista(lista lis1); 				   // visualizza la lista (ricorsiva)     
int posizione(int dato, lista lis1);     	   // 0 = non trovato,  x = posizione 			
int testa(lista lis1);                   	   // ritorna valore del primo elemento della lista 			
lista coda(lista lis1);                 	   // toglie il primo elemento della lista					
bool isMembro(int dato, lista lis1);		   // cerca ricorsivamente un elemento nella lista 															
lista accodaListe (lista lis1, lista lis2) ;   // accoda un elemento alla volta - ricorsivamente															
lista inserisciOrdinato(int dato, lista lis1); // inserisce ricorsivamente un dato in una lista 															


// ===================================================================================================
// funzioni da realizzare durante le vacanza di Natale 
  int ripetizioni (int dato, lista lis1);        	 // trova il numero di occorrenze in una lista
  int piuRipetuto (lista lis1);                   	 // trova l'elemento con più ripetizione nella lista 
  int cambiaTutti (int dato1, int dato2,lista lis1); // sostituisci tutte le occorrenze di dato1 con dato2  
  lista rovesciaLista(lista lis1);
  lista scambiaPosto(int dato, lista lis1);          // scambia un elemento con suo predecessore
  lista copy(lista lis1, lista lis2);                       
  lista togliElemento(int dato, lista lis1);
  lista mergeListe(lista lis1, lista lis2);          // fusione ordinata di due liste      
  lista ordinaLista(lista lis1);                     // ordinamento crescente dei dati di una lista x inserzione  
  lista bubbleLista(lista lis1);                     // ordinamento con bubble sort 
//====================================================================================================


//================================================== 
lista listaVuota(void) {
   // Autore : prof  
return NULL;
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
void stampaLista(lista lis1){
   // Autore : prof  
  while (lis1 != NULL) {
    printf("[%1d]->", lis1->info);
    lis1 = lis1->next;
  }
  printf("NULL \n");
};   /* stampaLista */

//------------------------------------------
lista inserisciTesta(int ele, lista lis1) { 
   // Autore : prof  
  lista temp;
  temp = (lista) malloc(sizeof(nodo));
  temp->info = ele;
  temp->next = lis1;
  return temp; 
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
   // Autore : prof  
  int conta = 1 ; 
  while ((lis1 != NULL) && (conta != num)){      // calcolo posizione 
    conta ++ ;	
    lis1 = lis1->next ;
  }
  if (conta == num){                             // ritorno posizione
    return lis1 ;
  }
  else {
    return NULL ;                                // posizione non trovata
  }
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
lista creaListaRandom(int quanti){
   // Autore : prof  
  int x;
  puntaNodo pNodo;                 
  puntaNodo pTesta;                
  pTesta= NULL;           // inizializzazione dei puntatore iniziale  
  for (x = 0; x < quanti; x++){
    pNodo = (puntaNodo)malloc(sizeof(nodo));   // allocazione nuovo elemento     
    pNodo->info = rand()%9 + 1;                // genero casualmente il dato     
    pNodo->next = pTesta;                      // collego all'ultimo inserito    
    pTesta=pNodo;                              // aggorno testa della lista        
  }
  return pTesta;
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


/* =================================================
   Visualizza la lista ricorsivamente 
   Richiama le primitive  isVuota() 	
 */
void mostraLista(lista lis1){ //stesso ordine di stampa lista RICORSIVA
   // Autore : prof  
  if (isVuota(lis1)){
 	printf("[NULL] \n");
  }
  else{
    printf("[%d]->",testa(lis1));
    mostraLista(coda(lis1)); //accorcio la lista
  }
}

/* =================================================
   Ritorna la posizione di un  elemento cercato
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
   // Autore : prof  
int testa(lista lis1) {
  if (isVuota(lis1)){ 
    abort();          // interrompe l'eleborazione  
  }               
  else{
    return lis1->info;
  }
}

/* =================================================
   Ritorna la coda della lista 
   Richiama le primitiva isVuota() 	
*/
   // Autore : prof  
lista coda(lista lista){
  if (isVuota(lista)){
    abort();
  }  
  else{
    return lista->next;
  }
}

/* =================================================
   Ritorna se un elemento è presente ricorsivamente() 
   Richiama le primitiva isVuota() 	
*/
   // Autore : prof  
bool isMembro(int dato, lista lis1){
  if (isVuota(lis1)){
    return false;
  }
  else{
    if (lis1->info == dato){
      return true ; 
    }
    else{
      if (lis1 == NULL){
        return false ;
      }
      else{
        return isMembro(dato, lis1->next) ;
      }
    }
  }
}


/* ============================================================
   Accoda due liste ricorsivamente - un dato alla volta  
   Richiama le primitiva isVuota() inserisciTesta() accodaListe()	
*/
   // Autore : prof  
lista accodaListe(lista lis1, lista lis2) {
  if (isVuota(lis1)){
    return lis2;
  }
  else{
    if (isVuota(lis2)){
      return lis1;
    }
    else{
     /* primo elemento della lista viene inserito nell'altra lista (lis1 + lis2) 
	   lis1 si accorcia tutte le volte*/
      return inserisciTesta(testa(lis1), accodaListe(coda(lis1),lis2)) ;
    }
  }
} 

 
/* ============================================================
   Accoda due liste ricorsivamente - un dato alla volta  
   Richiama le primitiva isVuota() inserisciTesta() inserisciOrdinato()
*/
   // Autore : prof  
lista inserisciOrdinato(int dato, lista lis1){
  if ((isVuota(lis1)) || (dato <= testa(lis1))) {
    return inserisciTesta(dato, lis1) ;  
  }
  else{
    /* Il primo elemento viene reinserito 
	  la ricorsione controlla la parte restante della lista che si accorcia continuamente*/
    return inserisciTesta(testa(lis1), inserisciOrdinato(dato, coda(lis1))) ;  
  }
}
 
 

