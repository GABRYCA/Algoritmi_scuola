#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>  
#define range  98           // gli sommo 1 dopo la generazione
#define maxLiv 10           // altezza massima dell'albero 
#define cifre   2           // numeri di x cifre

typedef struct s_alberoBin{
  int info;
  char car;
  struct s_alberoBin *sinistro;
  struct s_alberoBin *destro;
} alberoBin;

typedef s_alberoBin* pNodo;   // puntatore ad un nodo  

bool primo;

// funzioni preparatorie ==========================================
int* genera_array (int tanti);
alberoBin* da_array_a_albero(int *vet, int inizio, int dimensione);
void stampa_parentetica(alberoBin *root);
int AlberoVuoto(alberoBin *root);
alberoBin root (alberoBin *tempo);
alberoBin left (alberoBin *tempo);
alberoBin right (alberoBin *tempo);
alberoBin* newNodo(int valore,char car);

// visite classiche
void stampa_preorder(alberoBin *root);
void stampa_postorder(alberoBin *root);
void stampa_inorder(alberoBin *root);
void stampa_per_livello (alberoBin *root);

// funzioni accessorie  
int altezza_albero(alberoBin *root);
int altezza_alberoRic(alberoBin *root);
void visita_livello(alberoBin *root, int voluto, int altezza); 
int chiave_minima(alberoBin *root);
char cerca_chiave (alberoBin *root, int daTrovare, char cod []);
int cancella_chiave (alberoBin *root, int daTrovare);
int conta_nodi(alberoBin *root);
int conta_foglie(alberoBin *root);
int conta_fratelli(alberoBin *root, alberoBin *nodo);
int somma_chiavi(alberoBin *root);
alberoBin* aggiungiNodo(alberoBin *n1, alberoBin *n2);

// calcola l'altezza dell'albero ricorsivamente
int altezza_alberoR(alberoBin *r);

char* cifra(alberoBin *root,char codice[]);

// funzioni per la visualizzazione grafica dell'albero 
void inserisciSpazi(int livcor, int maxliv, alberoBin *root);
int visitaUnLivello(alberoBin *root, int maxliv, int voluto, int altezza); 
void stampa_grafica (alberoBin *root);                     // da migliorare 

// funzioni di utilità non su alberi 
int potenza(int base, int exponent); 
int max(int primo,int secondo);

// da fare ========================================================
int* da_albero_a_array(alberoBin *root);
int inserisci_chiave (alberoBin *root, int daMettere);     // lo inserisce nel ramo più corto 

//------------- alberi di ricerca  ------------------------
bool is_bilanciato(alberoBin *root);
bool is_ordinato(alberoBin *root);
int AVL_bilanciato(alberoBin *root);
alberoBin* ABR_inserisci(alberoBin *root, int daMettere);

bool ABR_ricerca(alberoBin *root, int daCercare);          // ricerca elemento in ABR
bool ABR_ricercaRic(alberoBin *root, int daCercare);       // ricerca ricorsiva in ABR

//------------------------------------ funzioni accessorie 
int max(int primo,int secondo){
  if (primo>secondo)
    return primo;
  else
    return secondo;
}
 
int potenza(int base, int exponent){
  int i, s=1;
  for (i = 0; i < exponent; ++i)
    s *= base;
  return s;
}

// carica albero a partire da un vettore heap 
alberoBin* da_array_a_albero(int *vettore, int inizio, int tanti) {
  alberoBin *tempo;
  if (inizio >= tanti) 
    return NULL;              // superata la fine del vettore
  if (vettore[inizio] == 0)
    return NULL;              // non c'e' nodo dell'albero da aggiungere
  else {
    // creo ed inizializzo il nuovo nodo dell'albero
    tempo = (alberoBin*)malloc(sizeof(alberoBin));
    tempo->info = vettore[inizio];
    tempo->sinistro = NULL;
    tempo->destro = NULL;
  }
  // chiamata ricorsiva per creare il sottoalbero sinistro
  tempo->sinistro = da_array_a_albero(vettore, 2 * inizio + 1, tanti); 
  // chiamata ricorsiva per creare il sottoalbero destro
  tempo->destro = da_array_a_albero(vettore, 2 * inizio + 2, tanti);
  return tempo; //restituisco la radice dell'albero
}

// calcola l'altezza dell'albero 
int altezza_albero(alberoBin *root){                 
int altezzaSX, altezzaDX;
  if (root == NULL) 
    return -1;                                  // valore di errore 
  else{
    altezzaSX = altezza_albero(root->sinistro); // analisi sottoalbero sx 
    altezzaDX = altezza_albero(root->destro);   // analisi sottoalbero dx   
    return max(altezzaSX, altezzaDX) + 1;       // maggiore dei due rami              
  }
}  

// calcola l'altezza dell'albero ricorsivamente
int altezza_alberoRic(alberoBin *r){
  if (r == NULL)  {
    return 0;
  }
  //passo ricorsivo 
  return (1 + max(altezza_albero(r->sinistro),altezza_albero(r->destro)));
}

// visita del livello voluto  
void visita_livello(alberoBin *root, int voluto, int altezza){  
  if (root != NULL){
    altezza++;
    if (altezza == voluto){
      printf(" %2d ", root->info);
    }
    visita_livello(root->sinistro, voluto, altezza); // analisi figlio sx 
    visita_livello(root->destro, voluto, altezza);   // analisi figlio dx 
  }
}  

// visita per livello dell'albero  
void stampa_per_livello(alberoBin *root) {
  int altezza, livelli, x;
  bool primo = true;
  if (root == NULL){                     // albero è vuoto 
    return;
  }
  altezza = altezza_albero(root);        // calcola altezza dell'albero 
  livelli = altezza +1;                  // individua il numero di livelli 
  for (x = 1; x <= livelli; x++) {       // visualizza un livello alla volta
    primo = true;
    visita_livello(root, x, 0);  
  }
}

// visite negli alberi 
void stampa_preorder(alberoBin *root) {
  if(root != NULL) {
    printf(" %2d ",root->info);
    stampa_preorder(root->sinistro);
    stampa_preorder(root->destro);
  }
}

void stampa_inorder(alberoBin *root){
  if(root != NULL){
    stampa_inorder(root->sinistro);
    printf(" %2d ",root->info);
    stampa_inorder(root->destro);
  }
}

void stampa_postorder(alberoBin *root) {
  if(root != NULL) {
    stampa_postorder (root->sinistro);
    stampa_postorder(root->destro);
    printf(" %2d ",root->info);
  }
}

alberoBin* aggiungiNodo(alberoBin *n1, alberoBin *n2){
  alberoBin *temp; 
  temp = (alberoBin*)malloc(sizeof(alberoBin));		// nuovo nodo dell'albero
  temp->info = (n1->info)+(n2->info) ;			    // inserisco nel nodo il valore contenuto nel vettore
  temp->destro = NULL;
  temp->sinistro = NULL;
  if ((n2->info) >=  (n1->info)){
    temp->sinistro = n2;  
    temp->destro = n1 ;
  }
  else  {
    temp->sinistro = n1; 
    temp->destro = n2; 
  }
  return temp ;   
}

void stampa_parentetica(alberoBin *root){
  if(root == NULL) {
    printf("-");
    return;
  }
  printf("%2d(", root->info);          // stampa il valore della chiave della radice
                                       // e una parentesi aperta
  stampa_parentetica(root->sinistro);  // stampa parentetica del sottoalbero sinistro
  printf(",");                         // stampa la virgola che separa i due sottoalberi
  stampa_parentetica(root->destro);    // stampa parentetica del sottoalbero destro
  printf(")");                         // stampa una parentesi chiusa
}

// genera il vettore heap con i dati da inserire nell'albero  
int* genera_array(int tanti){
  int  x, valore;
  int *vettore;
  vettore = (int*)malloc(sizeof(int)*tanti);
 
  int  riempi = 1;       // riempimento automatico 
  printf("Riempimento manuale = 0 automatico = 1: ");
  scanf("%d", &riempi);
  
  for (x = 0; x < tanti; x++){
    if (riempi == 0)                    // lettura dati 
      scanf("%d", &valore);
    else 
	  valore = (rand() % range + 1);    // generazione casuale 
    vettore[x] = valore;   
  }
 return vettore;  
}

// calcolo ricorsivo della somma dei valori presenti nei nodi 
int somma_chiavi(alberoBin *root){
 if (root == NULL) 
   return 0; 
 return root->info + somma_chiavi(root->sinistro) + somma_chiavi(root->destro);
}


// alberi di ricerca
// alberoBin* aggiungiNodo(alberoBin *n1, alberoBin *n2){
// int inserisci_elemento (alberoBin *root, int daMettere);

alberoBin* ABR_inserisci(alberoBin *root, int daMettere){ 
  alberoBin *temp; 
  if (root == NULL) { //l'albero e' vuoto 
    // creo ed inizializzo il nuovo nodo dell'albero 
    temp = (alberoBin*)malloc(sizeof(alberoBin)); 
    temp->info = daMettere; 
	temp->sinistro = NULL; 
	temp->destro = NULL; 
   	return temp; 
  }
  if (root->info >= daMettere) 
    // il nuovo nodo va inserito nel sottoalbero sinistro 
    root->sinistro = ABR_inserisci(root->sinistro, daMettere);
  else  //il nuovo nodo va inserito nel sottoalbero destro 
    root->destro = ABR_inserisci(root->destro, daMettere);
  return root;
}

 
bool ABR_ricercaRic(alberoBin *root, int daCercare){      // ricerca ricorsiva in ABR
  if (root == NULL) 
    return 0; 
  else
    if  (root->info == daCercare)
      return 1; 
    else
      if  (root->info > daCercare)
        // il  nodo va cercato nel sottoalbero sinistro 
        return 	ABR_ricercaRic(root->sinistro, daCercare);
      else      // il  nodo va cercato nel sottoalbero destro 
        return 	ABR_ricercaRic(root->destro, daCercare);
}

// --- da realizzare versione non ricorsiva      -----------------------------------
bool ABR_ricerca(alberoBin *root, int daCercare){         // ricerca elemento in ABR

}

// disegna un albero bin a partire da un vettore heap 
int visitaUnLivello(alberoBin *root, int maxliv, int voluto, int altezza){
  if (root == NULL) {
  //qui ci metto la parte vuota dell'albero
    inserisciSpazi(maxliv, altezza, root);
    printf("   ");		// questo sostituisce la cifra
    return 0;
  }
  if(voluto == 1){
    inserisciSpazi(maxliv,altezza,root);
    //stampo la lettera
    printf(" %d ",root->info);
  }
  else if (voluto > 1){
    visitaUnLivello(root->sinistro, maxliv, voluto-1, altezza);
    visitaUnLivello(root->destro, maxliv, voluto-1, altezza);
  } 
} 

// =======================================================================
// da perfezionare  
void stampa_grafica (alberoBin *root){
  int h = 1 + altezza_albero(root), x;
  for (x = 0; x <= h; x++){
	primo = true;
	visitaUnLivello(root, x, x, h);      // visita del livello con stampa
	printf("\n");	
  }
}

// da perfezionare 
void inserisciSpazi(int livcor, int maxliv, alberoBin *root){
	//livcor = livello corrente da spaziare
	//maxliv = altezza
	int x = 0;
	int numSpazi_tot = 0;
	int numSpazi_int = 0;
	
	if (primo){	  // se è il primo nodo della riga applico la spaziatura iniziale
		for (x = 1; x <= (maxliv-livcor); x++){	
			numSpazi_tot += pow(2,x);
		}
		for (x = 0; x < numSpazi_tot; x++)
			printf(" ");
		primo = false;
	}
	else{		      // se non è il primo nodo della riga applico la spaziatura intermedia
		for (x = 1; x <= (maxliv-(livcor-1)); x++){
			numSpazi_int += (pow(2,x));
		}
		numSpazi_int--;
		for (x = 0; x < numSpazi_int; x++)
			printf(" ");
	}
	return;
}

//--------------------------------------------------------
//cifra l'albero per compressione con Huffman 
char* cifra(alberoBin *root,char codice[]){
  if ((root->sinistro==NULL)&&(root->destro==NULL)){
    return codice;
  }
  else{
    if(root != NULL){ 
      cifra(root->sinistro,codice+'0');
      cifra(root->destro,codice+'1');
    }   
  } 
}

//Creo il nodo
alberoBin* newNodo(int valore,char lettera){
  alberoBin *temp; 
  temp = (alberoBin*)malloc(sizeof(alberoBin));		//nodo temp
  temp->info = valore ;	
  temp->car=lettera;
  temp->destro = NULL;
  temp->sinistro = NULL; 
return temp ;
}
//----------------------------------------------------------------


/* File: albBinLib.h                               */
/* Time-stamp: "2015-07-05 00:28:26                */
/* Scopo: libreria di funzioni su alberi binari    */
/* HOEPLI - Informatica in C e C++ - 2016          */

 
