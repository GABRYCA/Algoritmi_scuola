/* Implementazione di una PILA o STACK con allocazione sequenziale e statica */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>      // per poter usare la costante predefinita INT_MAX
#define VERO 0
#define FALSO 1
#define MAXNODI 10
typedef struct
   {
   int corpo [MAXNODI];  // contiene i nodi della pila (per ipotesi interi)
   int testa;            // indice dell'elemento dell'array in testa alla pila
   } pila;
/* procedura SvuotaPila */
void crea (pila *p_p);
/* procedura Push */
void push (pila *p_p, int n);
/* funzione Pop */
int pop(pila *p_p);
/* funzione TestVuota */
int testPilaVuota (pila p);
/* procedura StampaPila */
void stampaPila (pila p);

int main(int argc, char *argv[]){
/* dichiarazione delle variabili */
  int n, scelta;
  pila p;
  int i;
/* inizializzazione struttura pila */
  for (i=0;i<MAXNODI;i++){
    p.corpo[i] = INT_MAX;      /* i nodi non possono assumere valore 0 */
  }
  p.testa = -1;

 /*  gestione menù utente */
  do{
   system("CLS");
   printf("*** GESTIONE PILA CON STRUTTURA DATI ALLOCATA STATICAMENTE ***");
   printf("\n*  1: Crea la pila                                           *");
   printf("\n*  2: Inserisci un nuovo nodo nella pila (PUSH)              *");
   printf("\n*  3: Preleva un nodo dalla pila (POP)                       *");
   printf("\n*  4: Stampa il contenuto della pila                         *");
   printf("\n*  5: USCITA                                                 *");
   printf("\n*  N.B. NELLA PILA SI POSSONO INSERIRE AL MASSIMO %d NODI    *", MAXNODI);
   printf("\n************************************************************** \n\n");
   
     /* immissione scelta utente */
   printf("Immetti la scelta: ");
   fflush(stdin);
   scanf("%d",&scelta);
   /* scelta azione da intraprendere in base alla scelta utente */
   switch(scelta){
     case 1:{
       crea(&p);    /* creazione di una pila vuota */
       break;
     }
     case 2:{
       printf("Nodo che si intende inserire in TESTA alla pila (se possibile): ");
       fflush(stdin);
       scanf("%d",&n);
       /* inserimento di un nuovo nodo in testa alla pila */
       push(&p,n);
       break;
     }
     case 3:{
       /* prelevamento di un nodo dalla testa della pila */
       n = pop(&p);
       if(n != INT_MAX){
         printf("Il nodo estratto dalla TESTA della pila e': %d\n", n);
         printf("Operazione effettuata!\n");
       }       
       break;
     }
     case 4: {
       stampaPila(p); /* visualizzazione di tutti i nodi ddella pila */
       break;
     }
     case 5:{
       printf("Termine elaborazione ....\n");
       break;
     }
     default:{
       printf("Scelta non consentita!\n");
       break;
   }
  }
  system("PAUSE");
  }
  while (scelta != 5);

return 0;
}

/* procedura Crea pila */
void crea(pila *p_p){
  int i;
  /* creazione (o svuotamento) di una nuova pila */
  for (i=0;i<MAXNODI;i++){
   (*p_p).corpo[i] = INT_MAX;
  }
  (*p_p).testa = -1;
  printf("Operazione effettuata!\n");
  return;
}

/* procedura Push */
void push (pila *p_p, int n){
  /* verifico la possibilità di inserimento di un nodo in TESTA alla pila o stack */
  if ((*p_p).testa == (MAXNODI-1))  /* La pila o stack è piena */
  {
    printf("Il nodo preparato non puo' essere inserito in TESTA!\n");
    printf("La pila o stack e' gia' piena!\n");
  }
  else
  {
    (*p_p).testa = (*p_p).testa + 1;
    (*p_p).corpo[(*p_p).testa] = n;
    printf("Operazione effettuata!\n");
  }
return;
}

/* funzione Pop */
int pop (pila *p_p){
  int val;
  /* verifico la possibilità di prelevamento di un nodo dalla TESTA della pila o stack */
  if (testPilaVuota(*p_p) == VERO)    /*ma anche if ((*p_p).Testa == -1)) */
  {
    printf("La pila o stack e' vuota!\n");
    val = INT_MAX;
  }
  else
  {
    val = (*p_p).corpo[(*p_p).testa];
   (*p_p).testa = (*p_p).testa - 1; 
  }
return(val);
}

/* funzione TestVuota */
int testPilaVuota (pila p){
  /* dati di output */
  int esito;
  /* imposto il valore booleano */
  if (p.testa == -1)  
    esito = VERO;
  else
    esito = FALSO;
return (esito);
}

/* procedura StampaPila */
void stampaPila (pila p){
  int i;
  /* controllo che la pila o stack abbia nodi */
  if (testPilaVuota(p) == VERO)     /* ma anche if(p.Testa == -1) */
    printf("La pila o stack e' vuota!\n");
  else
  {
    /* imposto la stampa della pila o stack user friendly */
    printf("\n");
    printf("       __                       __   \n");
    for(i=p.testa;i>=0;i--){
      printf("\t| %2d^ Nodo = %5d\t|   ", i+1, p.corpo[i]);
      if (i==p.testa)
        printf(" %d Testa della pila o stack  (%d NON IN C)\n", p.testa, p.testa+1);
      else
        printf("\n");
    } 
    printf("\t|_______________________|   ");
    printf("-1 Fondo della pila o stack  (0 NON IN C)\n\n\n");
   }
return;
}

/* File: pilaStatica.cpp                             */
/* Time-stamp: "2015-07-05 00:28:26                  */
/* Scopo: operazioni elementari sulla pila statica   */  
/* HOEPLI - Informatica in C e C++ - 2016            */ 

