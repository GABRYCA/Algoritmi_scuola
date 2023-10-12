/* Implementazione di una CODA o QUEUE con allocazione sequenziale e statica*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>      // per poter usare la costante predefinita INT_MAX

#define VERO 0
#define FALSO 1

#define MAXNODI 10

typedef struct
   {
   int Corpo [MAXNODI];  // contiene i nodi della pila (per ipotesi interi)
   int Testa;            // indice dell'elemento dell'array in testa alla pila
   int Fondo;            // indice dell'elemento dell'array in fondo alla pila
                         // N.B. varrà sempre 0 se la pila ha almeno un nodo, 
                         // -1 altrimenti
   } coda;

/* prototipi sottoprogrammi secondo ADT PILA O STACK */
/* procedura Crea coda */
void Crea (coda *p_c);
/* procedura Inserisci */
void Inserisci (coda *p_c, int n);
/* funzione Estrai */
int Estrai (coda *p_c);
/* funzione TestVuota */
int TestVuota (coda c);

/* prototipi sottoprogrammi di utilità */
/* procedura StampaCoda */
void StampaCoda (coda p);

/* programma principale */
int main(int argc, char *argv[])
{
/* dati di input */
int n, scelta;
/* dati di lavoro */
coda c;
int i;

 
/* inizializzazione struttura dati coda */
for (i=0;i<MAXNODI;i++)
   {
   c.Corpo[i] = INT_MAX;    /* i nodi non possono assumere valore 0 */
   }
c.Testa = -1;
c.Fondo = -1;
/* fine inizializzazione della struttura dati coda */

/*  gestione menù utente */
do
   {
   system("CLS");
   printf("**** GESTIONE CODA O QUEUE CON STRUTTURA DATI ALLOCATA STATICAMENTE *****");
   printf("\n1: Crea la coda o queue");
   printf("\n2: Inserisci nodo nella coda o queue (Inserisci)");
   printf("\n3: Preleva nodo dalla coda o queue (Estrai)");
   printf("\n4: Stampa coda o queue");
   printf("\n5: USCITA\n");

   printf("\nN.B. MAX NODI GESTIBILI = %d\n\n", MAXNODI);
   
   /* immissione scelta utente */
   printf("Immetti la scelta: ");
   fflush(stdin);
   scanf("%d",&scelta);

   /* scelta azione da intraprendere in base alla scelta utente */
   switch(scelta)
      {
      case 1:
         {
         /* creazione di una coda vuota */
         Crea(&c);

         break;
         }
      case 2:
         {
         printf("Nodo che si intende inserire in FONDO alla coda (se possibile): ");
         fflush(stdin);
         scanf("%d",&n);
          
         /* inserimento di un nuovo nodo in fondo alla coda */
         Inserisci(&c,n);

         break;
         }
      case 3:
         {
         /* prelevamento di un nodo dalla testa della coda */
         n = Estrai(&c);
         if (n != INT_MAX)
            {
            printf("Il nodo estratto dalla TESTA della coda e': %d\n", n);
            printf("Operazione effettuata!\n");
            }       

         break;
         }
      case 4:
         {
         /* visualizzazione di tutti i nodi ddella pila */
         StampaCoda(c);

         break;
         }
      case 5:
         {
         printf("Arrivederci.....\n");
         break;
         }
      default:
         {
         printf("Scelta non consentita!\n");
         break;
         }

      }
   
   system("PAUSE");

  }
while (scelta != 5);

return 0;
}


/* procedura Crea coda */
void Crea(coda *p_c)
{
/* dati di lavoro */
int i;

/* creazione (o svuotamento) di una nuova coda */
for (i=0;i<MAXNODI;i++)
   {
   (*p_c).Corpo[i] = INT_MAX;
   }

(*p_c).Testa = -1;
(*p_c).Fondo = -1;

printf("Operazione effettuata!\n");

return;
}

/* funzione TestVuota */
int TestVuota (coda c)
{
/* dati di output */
int esito;

/* imposto il valore booleano */
/* N.B. Occorrerà tenere conto delle specificità del linguaggio C 
   relativamente alla numerazione degli indici dei vettori*/
if (c.Testa == -1)  
   {
   esito = VERO;
   }
else
   {
   esito = FALSO;
   }

return (esito);
}

/* procedura Inserisci */
void Inserisci (coda *p_c, int n)
{
/* dati di lavoro */
int i;

/* verifico la possibilità di inserimento di un nodo in FONDO alla coda o queue */
if ((*p_c).Testa == (MAXNODI-1))  /* La pila o stack è piena */
   {
   printf("Il nodo preparato non puo' essere inserito in FONDO!\n");
   printf("La coda o queue e' gia' piena!\n");
   }
else
   {
   /* traslo verso destra tutti i nodi della coda */
   for(i=(*p_c).Testa;i>=0;i--)
      {
      (*p_c).Corpo[i+1] = (*p_c).Corpo[i];
      }
   /* agggiorno il riferimento all'indice dell'elemento in testa alla coda */
   (*p_c).Testa = (*p_c).Testa + 1;         
   /* agggiorno il riferimento all'indice dell'elemento in fondo alla coda */
   (*p_c).Fondo = 0;
   /* inserisco l'elemento in fondo alla coda */                 
   (*p_c).Corpo [(*p_c).Fondo] = n;      /* ossia   (*p_c).Corpo [0] = n  */
   printf("Operazione effettuata!\n");
   }
return;
}


/* funzione Estrai */
int Estrai (coda *p_c)
{
/* valore ritornato dalla funzione */
int val;

/* verifico la possibilità di prelevamento di un nodo dalla TESTA della coda o queue */
if (TestVuota(*p_c) == VERO)    /*ma anche if ((*p_c).Testa == -1)) */
   {
   printf("La coda o queue e' vuota!\n");
   val = INT_MAX;
   }
else
   {
   val = (*p_c).Corpo[(*p_c).Testa];
   (*p_c).Testa = (*p_c).Testa - 1; 
   }

return(val);
}

/* procedura StampaCoda */
void StampaCoda (coda c)
{
/* dati di lavoro */
int i;

/* controllo che la pila o stack abbia nodi */
if (TestVuota(c) == VERO)     /* ma anche if(p.Testa == -1) */
   {
   printf("La coda o queue e' vuota!\n");
   }
else
   {
   /* imposto la stampa della pila o stack user friendly */
   printf("\n");
  
   printf("\t-----------------------------------------------------\n\t");
   for(i=0;i<=c.Testa;i++)
      {
      printf("%4d ",c.Corpo[i]);

      } 
   printf("\n\t-----------------------------------------------------\n");
   printf("\tFondo\t\t\t\t\t\tTesta\n");
   printf("\t %d IN C\t\t\t\t\t\t%2d IN C\n", c.Fondo, c.Testa);
   printf("\t %d NON IN C\t\t\t\t\t%2d NON IN C\n\n", c.Fondo+1, c.Testa+1);
   }

return;
}


/* File: codaStatica.cpp                             */
/* Time-stamp: "2015-07-05 00:28:26                  */
/* Scopo: operazioni elementari sulla coda statica   */  
/* HOEPLI - Informatica in C e C++ - 2016            */ 


