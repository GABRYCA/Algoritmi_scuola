#include <stdio.h>
#include <stdlib.h>
int main() {
 struct s_vagone{
   int info;                     // campo informazione
   struct s_vagone *gancio;      // campo per il collegamento
 };
 typedef struct s_vagone vagone; // nodo della lista 
 typedef vagone *gancio;         // puntatore al vagone (gancio del vagone)
 //------------------------------------------------------------------------
 // definizione delle variabili statiche 
 gancio  pLocomotore;            // variabile che punta al treno 
 gancio  pCarrozza, pCorrente;   // variabile che punta ad un vagone
 
 // creo il primo elemento e lo collego al locomotore
 pCarrozza = (gancio)malloc(sizeof(vagone));   // allocazione primo elemento    
 pCarrozza->info = 1;		        		   // dati del primo elemento       
 pCarrozza->gancio = NULL;                     // gancio del primo elemento     
 pLocomotore = pCarrozza;                      // lo collego al locomotore      
 
 // creo il secondo elemento 
 pCarrozza = (gancio)malloc(sizeof(vagone));   // allocazione primo elemento   
 pCarrozza->info = 2;					       // dati del primo elemento       
 pCarrozza->gancio = NULL;                     // come lo collego ? 
   
   
 // visualizza il treno ---------------------
 printf("pLocomotore []->");
 pCorrente = pLocomotore;
 while (pCorrente != NULL){
   printf("[%1d]->", pCorrente->info);
   pCorrente = pCorrente->gancio;
 } 
 printf("NULL\n\n");
 // -----------------------------------------


 //  collego il secondo elemento in testa 
 pCarrozza->gancio = pLocomotore;    // collego il treno dopo la carrozza corrente
 pLocomotore =  pCarrozza;           // il locomotore punta alla nuova carrozza
   
  
   
 // visualizza il treno ---------------------
 printf("pLocomotore []->");
 pCorrente = pLocomotore;
 while (pCorrente != NULL){
   printf("[%1d]->", pCorrente->info);
   pCorrente = pCorrente->gancio;
 } 
 printf("NULL\n\n");
 // -----------------------------------------
  
  
/* File: listaTreno.cpp                     */
/* Time-stamp: "2015-07-05 00:28:26         */
/* Scopo:  liste a puntatori                */
/* HOEPLI - Informatica in C e C++ - 2016   */
 

  
 /* 
 // lista numerica creata senza puntatori temporanei 
 nodo lis;                // puntatore al primo elemento della lista 
 pTesta = malloc(sizeof(vagone));        // allocazione primo elemento 
 pTesta->info = 1;
  
 pTesta->next = malloc(sizeof(nodo)); // allocazione secondo elemento
 pTesta->next->info = 2;

 pTesta->next->next = malloc(sizeof(nodo)); // alloc. terzo elemento 
 pTesta->next->next->info = 3;
 pTesta->next->next->next = NULL;

 printf("\n\n Visualizzo la seconda lista \n");
 stampaLista(pTesta);                          // visualizza la lista 
 
  printf("\n\n");
  system("PAUSE");
  */
 
}
 
