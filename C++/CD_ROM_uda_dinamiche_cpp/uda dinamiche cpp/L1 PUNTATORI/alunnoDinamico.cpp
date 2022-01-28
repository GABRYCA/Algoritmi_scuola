#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct s_alunno {           // definizione del record 
  char cognome[30];
  char nome[20];
  int classe;
  char sezione;
  char sesso;
  bool ripetente;
  float mediaVoti;
} alunno ;

void visualizza (alunno* punta);

int main(){
  alunno* puntaMarioRossi;                                // def  puntatore
  puntaMarioRossi = (alunno*) malloc (sizeof( alunno )) ; // alloca lo spazio  
  //  inserisci i dati
  strcpy(puntaMarioRossi->cognome, "Rossi");   // per assegnare una stringa
  strcpy(puntaMarioRossi->nome, "Mario");      // per assegnare una stringa
  puntaMarioRossi->classe = 3;
  puntaMarioRossi->sezione ='C';
  puntaMarioRossi->sesso = 'M';
  puntaMarioRossi->ripetente = false; 
  puntaMarioRossi->mediaVoti = 6.3;
  //visualizzazione del contenuto
  visualizza (puntaMarioRossi);
}

void visualizza (alunno* punta) {
  // accesso ai campi con operatore ->
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
  
/* File: alunnoDinamico.cpp                   */
/* Time-stamp: "2014-09-06 03:26:06 paolo"    */
/* Scopo: DEFINIZIONE DI UN RECORD            */ 
/* HOEPLI - Informatica in C e C++ - 2016     */

