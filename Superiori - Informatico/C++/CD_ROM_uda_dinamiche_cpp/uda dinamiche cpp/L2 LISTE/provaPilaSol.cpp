/* File: provaPila.cpp                                                   */
/* Time-stamp: "2015-07-05 00:28:26                                      */
/* Scopo: allocazione dinamica di una PILA o STACK con lista concatenata */
/* HOEPLI - Informatica in C e C++ - 2016                                */ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   // necessaria la libreria per le var booleane 
#include "pila.h"      // libreria funzioni sulla pila 

#define MAXLEN 20      // lunghezza della stringa di input  

// dichiarazione delle funzioni locali utilizzate
int  mostraMenu (void);

// programma principale
int main(int argc, char *argv[]){
  // dichiarazione variabili locali
  int cePila;   //variabile che indica se la pila è stata creata oppure no
  nodo *pTesta;
  int scelta;
  char elem[MAXLEN];

  // inizializzazioni
  scelta = 0;
  cePila = 0;
  do{
    // ripulisco lo schermo
    system("CLS");
    // chiamo la funzione che crea il menù utente
    scelta = mostraMenu();
    switch (scelta){
      case 1:{
        if (cePila == 0){
          cePila = 1;
          // crea (&pTesta);         
		  pTesta = creaPila();
  	      printf ("\n\tLa pila e' stata creta correttamente!\n\n\t");
       }
        else
          printf ("\n\tOPERAZIONE IMPOSSIBILE: E' stata gia' creata la pila\n\n\t");     
        break;
      }
      case 2:{
        if (cePila == 1)
        {
          printf ("\n\tInserisci elemento da inserire in testa alla pila:  ");
          fflush(stdin);
          scanf("%s", elem);
         //check sul valore immesso
          if (atof(elem) != 0)  {
 //         if ((atof(elem) != 0) || (strcmp(elem,"0") == 0)){
            push1 (&pTesta, atof(elem));
            printf ("\n\tIl nodo e' stato inserito in TESTA alla PILA con successo \n\n\t"); 
          }
          else{
            printf ("\n\tOPERAZIONE IMPOSSIBILE: il valore immesso non e' un numero decimale\n\n\t");
          }
        }
        else
        {
          printf ("\n\tOPERAZIONE IMPOSSIBILE: La pila non e' stata ancora creata!\n\n\t");    
        }
        break;
      }
      case 3:
      {
        if (cePila == 1) {
  //        pTesta = pop (pTesta);
            pop1 (&pTesta);
        }
        else{
          printf ("\n\tOPERAZIONE IMPOSSIBILE: La pila non e' stata ancora creata!\n\n\t");  
        }
        break;
      }
      case 4:
      {
        if (cePila == 1){
          stampaPila (pTesta); 
        }
        else{
          printf ("\n\tOPERAZIONE IMPOSSIBILE: La pila non e' stata ancora creata!\n\n\t");  
        }
        break;
      }
      case 5:
      {
        if (cePila == 1){
          deallocaPila (pTesta); 
          cePila = 0;
        }
        else{
          printf ("\n\tOPERAZIONE IMPOSSIBILE: La pila non e' stata ancora creata!\n\n\t");  
        }
        break;
      }
      case 6:
      {
        if (cePila == 1){
          if (isVuota(pTesta))
            printf ("\n\tLa pila e' vuota!\n\n\t");  
          else
            printf ("\n\tLa pila e' non vuota!\n\n\t");  
        }
        else{
          printf ("\n\tOPERAZIONE IMPOSSIBILE: La pila non e' stata ancora creata!\n\n\t");  
        }
        break;
      }
      case 7:
      {
        if (cePila == 0){
          int tanti = 5;
          pTesta = creaPilaRandom( tanti );
          cePila = 1;
          printf ("\n\t Creata pila con %d elementi \n\n\t" , tanti );  
        }
        else{
          printf ("\n\tOPERAZIONE IMPOSSIBILE: La pila e' gia'  creata!\n\n\t");  
        }
        break;
      }
      case 9:
      {
        if (cePila == 1){
          printf ("\n\tOPERAZIONE CONCETTUALMENTE NON CORRETTA\n");
          printf("\tLa pila non e' ancora stata DEALLOCATA - USCITA FORZATA\n");
          printf("\t(Garbage collection ad opera della CPU)\n\n\t");
        }
        else{
          printf ("\n\tGrazie per averci utilizzato CORRETTAMENTE...\n\n\t");               
        }
      }
   }
   // pausa
   system("PAUSE");

  }while (scelta != 9);
return 0;
}


// FUNZIONE DI CREAZIONE DEL MENU' UTENTE
int mostraMenu (void){
int scelta;
do{
  system("CLS");
  printf ("\n");
  printf ("\t******************************************************\n");
  printf ("\t* STRUTTURA DATI PILA o STACK ALLOCATA DINAMICAMENTE *\n");
  printf ("\t******************************************************\n");
  printf ("\n");
  printf ("\t******************************************************\n");
  printf ("\t*\tMenu' utente principale                      *\n");
  printf ("\t******************************************************\n");
  printf ("\t* 1 CREAZIONE DELLA PILA                             *\n");
  printf ("\t* 2 PUSH - INSERISCI NODO (IN TESTA ALLA PILA)       *\n");
  printf ("\t* 3 POP - PRELEVA NODO (DALLA TESTA DELLA PILA)      *\n");
  printf ("\t* 4 STAMPA LA PILA                                   *\n");
  printf ("\t* 5 DEALLOCA LA PILA                                 *\n");
  printf ("\t* 6 TEST PILA VUOTA                                  *\n");
  printf ("\t* 7 CREA PILA RANDOM                                 *\n");
  printf ("\t*                                                    *\n");
  printf ("\t* 9 =======> USCITA                                  *\n");
  printf ("\t******************************************************\n\n");

  printf ("\tInserire scelta (1, 2, 3, ..  oppure 9)   :    ");
  fflush(stdin);
  scanf("%d", &scelta);

  if ((scelta < 1) || (scelta > 9))  {
    printf ("\n\tERRORE Digitare la scelta corretta.....\n\n\t");
    system("PAUSE");
  }
  else;
  } while ((scelta < 1) || (scelta > 9));
  return scelta;
}



