#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // necessaria la libreria per le var booleane 

// elemento informazione della lista
typedef int element ;

// elemento della lista 
typedef struct list_element {
  element value;
  struct list_element *next;
} item;
typedef item *list;

// funzioni primitive 
list emptyList(void);  
bool empty(list);
element head(list);
list tail(list);
list cons(element, list);
int ricerca(int e, list l);
list subList(int n, list l);

// funzioni non primitive
void showList(list);     
bool member(element, list);
int length(list l);
list append(list l1, list l2) ;
list reverse(list l);
list copy(list l);
list deleteX(element, list);
list insord(element el, list l);
list mergeList(list l1, list l2);


list emptyList(void) {
return NULL;
}

bool empty(list l) {
  if (l==NULL) 
    return true;
  else 
    return false;
}

element head(list l) {
  if (empty(l)) 
    abort();
  else
 return l->value;
 }

list tail(list l) {
  if (empty(l))
    abort();
  else
    return l->next;
}

list cons(element e, list l) {
  list t;
  t = (list) malloc(sizeof(item));
  t->value = e;
  t->next = l; 
  return t;
 }
 
list insert(int e, list l) { 
  list t;
  t = (list) malloc(sizeof(item));
  t->value = e;
  t->next = l;
  return t; 
}
 
// versione iterativa 	
int ricerca(int e, list l) {
  int trovato = 0;
  while ((l!=NULL)&&!trovato)
    if (l->value == e) 
	  trovato = 1;
    else 
	   l = l->next;
return trovato;
}
 
// Dato un intero positivo n e una lista l
// restituisca una lista che rappresenti la sotto-lista inclusa in
// quella data a partire dall’elemento n-esimo
list subList(int n, list l) {
  if ((n == 1)||(l==NULL)) 
    return l;
  else
 return (subList(n-1, l->next)); 
 }
 
//================== funzioni non primitivae  
 
/* Visualizza sullo schermola gli elementi della lista
   Richiama le primitive:
	  empty() 
	  head()  
	  tail()
 */
void showList(list l) {             // NON PRIMITIVE
  printf("[");
  while (!empty(l)) {
   printf("%d", head(l));
   l = tail(l);
   if (!empty(l)) printf(",");
  } 
  printf("]\n");
}

/* Restituisce vero o falso a seconda se l'elemento dato è presente nella lista data"
   Richiama le primitive:
	  empty() 
	  head()  
	  member()
   VERSIONE RICORSIVA
 */

bool member(element el, list l) {
  if (empty(l)) 
    return false;
  else 
    if (el == head(l)) 
	  return true;
  else 
    return member(el, tail(l));
}
 
// VERSIONE RICORSIVA
int length(list l) {
if (empty(l)) return 0;
else return 1 + length(tail(l));
}
 
list append(list l1, list l2) {
if (empty(l1)) return l2;
else return cons(head(l1), append(tail(l1),l2));
}

list reverse(list l) {
if (empty(l)) return emptyList();
else return append(reverse(tail(l)),
cons(head(l), emptyList()));
}

list copy(list l) {
  if (empty(l)) 
    return l;
  else
    return cons(head(l), copy(tail(l)));
}

list deleteX(element el, list l) {
if (empty(l)) 
   return emptyList();
else 
   if (el == head(l)) 
     return tail(l);
  else 
     return cons(head(l), deleteX(el, tail(l)));
}

list insord(element el, list l) {
  if (empty(l))
    return cons(el, l);
  else 
    if (el <= head(l)) 
	  return cons(el, l);
    else
      return cons(head(l), insord(el, tail(l)));
}
list inputordlist(int n) { 
 element e;
 if  (n < 0 ) 
   abort();
 else 
   if (n == 0) 
	 return emptyList();
   else { 
     scanf("%d", &e);
     return 
     insord(e, inputordlist(n-1));
  } 
}
list mergeList(list l1, list l2) {
  list l3 = copy(l1);
  if (empty(l2)) return l3;
  else if (!member(head(l2), l3))
  l3 = insord(head(l2), l3);
return mergeList(l3, tail(l2)); }



/* File: liste1.h                                   */
/* Time-stamp: "2015-07-05 00:28:26                 */
/* Scopo: libreria liste semplici - x esperimenti   */  
/* HOEPLI - Informatica in C e C++ - 2016           */ 


