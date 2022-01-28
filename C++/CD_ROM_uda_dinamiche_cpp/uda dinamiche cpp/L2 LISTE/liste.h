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
lista inserisciTesta(int dato, lista lis);    // appende un elemento in testa 
int ricerca(int dato, lista lis1);     	 	  // 0 = non trovato,  1 = trovato
lista subLista(int num, lista lis1) ;         // crea due liste, la prima di num elementi 
bool ctrOrdinata(lista lis1);                 // controlla se lista ordinata crescente 
lista creaListaRandom(int quanti);            // crea lista di quanti elementi in modo casuale 

// funzioni non primitive
int contaElementi(lista lis1);
void mostraLista(lista lis1);     
int testa(lista lis1);                   	  // ritorna valore del primo elemento della lista 
lista coda(lista lis1);                 	  // toglie il primo elemento della lista
bool isMembro(int dato, lista lis1);
lista accodaListe (lista lis1, lista lis2) ;
lista rovesciaLista(lista lis1);
lista copy(lista lis1);                       
lista togliElemento(int dato, lista lis1);
lista inserisciOrdinato(int dato, lista lis1);
lista mergeListe(lista lis1, lista lis2);

//================================================== 
lista listaVuota(void) {
return NULL;
}

bool isVuota(lista lis1) {
  if (lis1 == NULL) 
    return true;
  else 
    return false;
}

lista inserisciTesta(int ele, lista lis1) { 
  lista temp;
  temp = (lista) malloc(sizeof(nodo));
  temp->info = ele;
  temp->next = lis1;
  return temp; 
}
 
// versione iterativa 	
int ricerca(int ele, lista lis1) {
  int trovato = 0;
  while ((lis1 != NULL) && (!trovato))
    if (lis1->info == ele) 
	  trovato = 1;
    else 
	  lis1 = lis1->next;
return trovato;
}
 
// Dato un intero positivo n e una lista l restituisca una lista che rappresenti 
// la sotto-lista inclusa in quella data a partire dall’elemento n-esimo
lista subLista(int num, lista lis1) {
  if ((num == 1)||(lis1 == NULL)) 
    return lis1;
  else
 return (subLista(num-1, lis1->next)); 
 }
 
 puntaNodo creaListaRandom(int quanti){
   int x;
   lista temp, pTesta;
   pTesta = listaVuota();             /* crea lista vuota              */
   for (x = 0; x < quanti; x++){
     temp = (lista) malloc(sizeof(nodo)); 
     temp->info = rand()%9 + 1;       /* genero casualmente il dato     */
     temp->next = pTesta;             /* collego all'ultimo inserito    */
     pTesta = temp;                    /* collego la testa              */
   }
   return pTesta;
};   /* creaListaTesta */


void stampaLista(puntaNodo lista){
  while (lista != NULL) {
    printf("[%1d]->", lista->info);
    lista = lista->next;
  }
  printf("NULL");
};   /* stampaLista */

 
 // versione iterativa 	
bool ctrOrdinata(lista lis1) {
  int ele = 0; 
  while (lis1 != NULL) 
    if (lis1->info < ele) 
	  return false;
    else 
	  lis1 = lis1->next;
return true;
}

// versione ricorsiva 
bool ctrOrdinataR(int ele, lista lis1) {
 
}

//================== funzioni non primitive  

int testa(lista lis1) {
  /* ritorna il valore di testa della lista
    Richiama le primitive:	 isVuota() 	
  */
  if (isVuota(lis1)) 
    abort();                 // interrompe l'eleborazione  
  else
return lis1->info;
}

void mostraLista(lista lis1) {              
 /* Visualizza sullo schermo gli elementi della lista
    Richiama le primitive:	 isVuota() 	 testa()  	 coda()
 */
  printf("[");
  while (!isVuota(lis1)) {
   printf("%d", testa(lis1));
   lis1 = coda(lis1);
   if (!isVuota(lis1)) printf(",");
  } 
  printf("]\n");
}

lista coda(lista lis1) {
 /* ritorna la lista dopo aver tolto il primo elemento 
    Richiama le primitive:	 isVuota() 
 */
  if (isVuota(lis1))
    abort();                  // interrompe l'elaborazione
  else
    return lis1->next;
}

bool isMembro(int ele, lista lis1) {
  /* Restituisce vero o falso a seconda se l'elemento dato è presente nella lista data"
     Richiama le primitive: isVuota() testa()  isMembro() ->VERSIONE RICORSIVA
  */
  if (isVuota(lis1)) 
    return false;
  else 
    if (ele == testa(lis1)) 
	  return true;
  else 
    return isMembro(ele, coda(lis1));
}
 
int contaElementi(lista lis) {
/* Restituisce il numero degli elementi presenti nella lista
   Richiama le primitive:  isVuota()  // VERSIONE RICORSIVA*/
  if (isVuota(lis)) 
    return 0;
  else 
    return 1 + contaElementi(coda(lis));
}
 
lista accodaListe(lista lis1, lista lis2) {
  if (isVuota(lis1)) 
    return lis2;
  else 
    return inserisciTesta(testa(lis1), accodaListe(coda(lis1),lis2));
}

lista rovesciaLista(lista lis1) {
  if (isVuota(lis1)) 
    return listaVuota();
  else 
    return accodaListe(rovesciaLista(coda(lis1)),
  inserisciTesta(testa(lis1), listaVuota()));
}

lista copy(lista lis) {
  if (isVuota(lis)) 
    return lis;
  else
    return inserisciTesta(testa(lis), copy(coda(lis)));
}

lista togliElemento(int ele, lista lis) {
if (isVuota(lis)) 
   return listaVuota();
else 
   if (ele == testa(lis)) 
     return coda(lis);
  else 
     return inserisciTesta(testa(lis), togliElemento(ele, coda(lis)));
}

lista inserisciOrdinato(int ele, lista lis1) {
  if (isVuota(lis1))
    return inserisciTesta(ele, lis1);
  else 
    if (ele <= testa(lis1)) 
	  return inserisciTesta(ele, lis1);
    else
      return inserisciTesta(testa(lis1), inserisciOrdinato(ele, coda(lis1)));
}
lista inputordlista(int num) { 
 int ele;
 if  (num < 0 ) 
   abort();
 else 
   if (num == 0) 
	 return listaVuota();
   else { 
     scanf("%d", &ele);
     return 
     inserisciOrdinato(ele, inputordlista(num-1));
  } 
}

lista mergeListe(lista lis1, lista lis2) {
  lista lis3 = copy(lis1);
  if (isVuota(lis2)) 
    return lis3;
  else 
    if (!isMembro(testa(lis2), lis3))
      lis3 = inserisciOrdinato(testa(lis2), lis3);
  return mergeListe(lis3, coda(lis2)); 
}
 
/* File: liste.h                            */
/* Time-stamp: "2015-07-05 00:28:26         */
/* Scopo: libreria liste semplici           */  
/* HOEPLI - Informatica in C e C++ - 2016   */ 
