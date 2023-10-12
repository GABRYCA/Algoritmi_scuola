#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "albBinLib.h"
void stampa(char lettere[],int tot[],int max);
void ordina(char lettere[],int tot[],int fine);
void ordinanodi(alberoBin *root[],int tot[],int fine);
void fcodifica (alberoBin *root, char lettera,int parola);
int code;
//Funzione che stampa lettere e frequenze
void stampa(char let[],int tot[],int max){
	int x;
	printf("\n");
	for (x = 0;x < max; x++){
		printf(" %c ", let[x]);			
	}	
	printf("\n");
	for (x = 0;x < max; x++){
		printf(" %d ", tot[x]);
	}
}
//Ordino il vettore delle frequenze 
void ordina(char let[], int tot[], int max)
{
	int x = 0;
	int y = 0;
	int num = 0;
	char car;
	for(x = 0; x < max - 1; x++){
		for(y = 0; y < max - 1; y++){
			if (tot[y] < tot[y+1]){
				num = 0;
				num = tot[y];
				tot[y] = tot[y+1];
				tot[y+1] = num;
				car = let[y];
				let[y] = let[y+1];
				let[y+1] = car;
			}
		}
	}
}
void fcodifica (alberoBin *root, char lettera,int parola){
 
 if(root->car == lettera){
        code = parola;
 }
 else{ 
  if ( root->destro != NULL ){
   parola = (parola*10)+1;
   fcodifica(root->destro,lettera,parola); 
  }
     parola = parola / 10; 
  if ( root->sinistro != NULL ){
   parola = (parola*10)+2; 
   fcodifica(root->sinistro,lettera,parola); 
  }         
 }
}
//Ordino i nodi
void ordinanodi(alberoBin *root[],int tot[],int max)
{	
	alberoBin *temp = NULL ;
 	int x=0;
 	int y=0;
 	int num;
  	for(x=0;x<max-1;x++)
 	{
   		 for(y=0;y<max-1;y++)
		 {
    		if (tot[y]<tot[y+1])
	  		{
        		num=tot[y];
         		tot[y]=tot[y+1];
         		tot[y+1]=num;
         		temp = root[y];
		 		root[y] = root[y+1];
         		root[y+1]= temp;
      		}
   		 }
 	}
}

int main(){
	char stringa[255] = {""};
	int flag, k, x, y, numlet, cont;
	char alfa[255] = {""};
	char cod[255] = {""};
	int freq[255] = {0};
	int contlet = 0;
	int lunghezza = 0;
	float risp, temp;
	y = 0;
	x = 0;
	k = 0;
	cont = 0;
	numlet = 0;
	printf("Inserire la frase\n");
	gets(stringa);
	//Conto ogni carattere
	while(stringa[y] != '\0')	{
	  flag = 0;
	  for (k = 0; k <= x; k++){
		if (stringa[y] == alfa[k]){
	      freq[k]++;
		  flag = 1;
		}
	  }
	  if (flag == 0){
	    alfa[x] = stringa[y];
		freq[x]++;
  	    x++;
	  }
	  y++;
	}
	numlet = x;
	printf("\nVettore delle lettere:");
	stampa(alfa, freq, numlet);
	//Ordino e stampo il vcettore delle frequenze
	printf("\nVettore delle frequenze ordinato:");
	ordina(alfa, freq, numlet);
	stampa(alfa, freq, numlet);
	//Creo tanti nodi quanti i caratteri diversi presenti
	alberoBin *vetNodi[numlet] ;		
	for (x = 0; x < numlet; x++){
  		  vetNodi[x] = newNodo(freq[x], alfa[x]);
  	}
 	//Collego i due nodi con frequenza minore poi riordino
 	contlet = numlet;
	while(numlet>1)	{
      ordinanodi(vetNodi, freq, numlet);
      //sommo le ultime due celle 
      freq[numlet-2] = freq[numlet-2] + freq[numlet-1] ;
      //collego gli ultimi due nodi
      vetNodi[numlet-2] = aggiungiNodo(vetNodi[numlet-1],vetNodi[numlet-2]);
      numlet--;
    }
    printf("\n\n");
    printf("Albero",x);
  	stampa_inorder(vetNodi[0]);
  	printf("\n");
  	stampa_grafica(vetNodi[0]);
  	char codifica[10];   
  	printf("\nCodifica delle lettere\n");
    for (x = 0; x < contlet; x++){
      printf("Lettera %c : ", alfa[x]) ;
      fcodifica(vetNodi[0], alfa[x],0);
      strcpy(codifica, "");
      while ( code >= 1 ){
        if ( code%2 == 0 ){ 
          strcat(codifica,"0");
        }
        else{
         strcat(codifica,"1");
        } 
        code = code/10 ;
      }
      strrev(codifica);
      printf("%s\n",codifica); 
      //alfacode[x]=codifica;
   }
   cont = strlen(stringa);
   printf("\nCodifica delle frase inserita\n\n");
   for (x = 0; x < cont; x++){
     fcodifica(vetNodi[0], stringa[x], 0);
     strcpy(codifica, "");
     while ( code >= 1 ){
       if (  code%2 == 0 ){ 
         strcat(codifica,"0");
       }
       else{
         strcat(codifica, "1");
       }
       code = code / 10 ;
     }
     strrev(codifica);
     printf("%s", codifica); 
     strcat(cod, codifica);
  }
  lunghezza = strlen(cod);
  printf("\n\nBit della frase inserita %d",strlen(stringa)*sizeof(char)*8);
  printf("\nBit della codifica %d",lunghezza);
  temp = lunghezza;
  risp = temp / (strlen(stringa)*sizeof(char)*8);
  risp = (1-risp) * 100;
  printf("\nRisparmio %f %%",risp);
}


/* File: codificaHuffman.cpp                                   */
/* Time-stamp: "2015-07-05 00:28:26                            */
/* Scopo: utilizzao alberi per realizzare il codice di Huffman */
/* HOEPLI - Informatica in C e C++ - 2016                      */

 

