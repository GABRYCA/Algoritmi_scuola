/* File: classeDinamica.cpp                             */
/* Time-stamp: "2014-09-06 03:26:06 paolo"    */
/* Scopo: DEFINIZIONE DI UN vettore di RECORD            */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct s_alunno {           // definizione del record 
  char cognome[30];
  char nome[20];
  int progressivo;
  int classe;
  char sezione;
  char sesso;
  bool ripetente;
  float mediaVoti;
} alunno ;

void visualizza (alunno* punta);
void riempi (alunno* punta, int x);

int  main(){
  int x, tanti;
  printf( "Inserisci il numero di alunni nella classe: " ) ;
  scanf ( "%d", &tanti );            	                     	 // leggo la dimensione del vettore run-time

  alunno* puntaClasse;                                         // def  puntatore
  puntaClasse = (alunno*) malloc ( tanti * sizeof( alunno )) ; // alloca lo spazio  
  for( x = 0 ; x < tanti ; x++){
    printf ( "\ninserisci dati alunno %d :", x + 1 ) ;    // riempio il vettore
    //  inserisci i dati
    riempi (puntaClasse + x, x+1 );
    //visualizzazione del contenuto
    visualizza (puntaClasse + x );
  }
}

void riempi (alunno* punta, int matricola) {
  // accesso ai campi con operatore ->
  punta->progressivo = matricola;
  strcpy(punta->cognome, "Rossi");   // per assegnare una stringa
  strcpy(punta->nome, "Mario");      // per assegnare una stringa
  punta->classe = 3;
  punta->sezione ='C';
  punta->sesso = 'M';
  punta->ripetente = false; 
  punta->mediaVoti = 6.3;
 } 
  
void visualizza (alunno* punta) {
  // accesso ai campi con operatore ->
  printf("\n matricola  : %d\n", punta->progressivo);
  printf(" cognome    : %s\n", punta->cognome);
  printf(" nome       : %s\n", punta->nome);
  printf(" classe     : %d\n", punta->classe);
  printf(" sezione    : %c\n", punta->sezione);
  printf(" sesso      : %c\n", punta->sesso);
  if ( punta->ripetente == 0 )
    printf(" ripetente  : NO\n");
  else
    printf(" ripetente  : SI\n");   
  printf(" media Voti : %3.1f\n", punta->mediaVoti);
 } 
 
