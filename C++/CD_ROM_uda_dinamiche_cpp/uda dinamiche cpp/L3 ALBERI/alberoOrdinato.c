 
 /* esempio di gestione albero binario */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 30
typedef struct tnode *Treeptr;
typedef struct tnode {    /* nodo dell'albero              */
  char  *word;          /* puntatore al testo            */
  int  count;           /* numero di occorrenze          */ 
  Treeptr left, right;  /* figli di sinistra e di destra */
 } Treenode;

 char *strdupz(char *);
 Treeptr addtree(Treeptr, char *);
 void treeprint(Treeptr);
 Treeptr talloc(void);
 void StampaAlbero(Treeptr, int);

/* costruisce albero dinamico inserendo parole */
int main(void)
{
  Treenode *root;
  char word[MAXWORD];
  char *fine = "END";

  root = NULL;
  printf("\ninserisci una parola alla volta <END termina la sequenza>\n");
  scanf("%s", word);
  while(*word != *fine)
  {
    root = addtree(root, word);
	scanf("%s", word);
  }
  printf("\n    ALBERO ORDINATO\n");
  treeprint(root);
  printf("\n");
  printf("\n    STRUTTURA DELL'ALBERO\n");
  printf("\n");    	
  StampaAlbero(root, 1);
  return 0;
}

/* aggiunge un nodo con w, a livello di *p o sotto */
Treenode *addtree(Treenode *p, char *w)
{
  int cond;
  if (p == NULL )    /* nuova parola */
  {
    p = talloc();    /* crea un nuovo nodo */
    p->word = strdupz(w);
    p->count = 1;
    p->left = p->right = NULL;
   }
   else if ((cond = strcmp(w, p->word)) == 0)
     p->count++;    /* parola ripetuta */
   else if (cond < 0)   /* minore: sottoalbero sinistro */
	 p->left = addtree(p->left, w);
   else                 /* maggiore: sottoalbero destro */
     p->right = addtree(p->right, w);
   return p;
}
 
/* visita e stampa dell'albero p in ordine simmetrico */
void treeprint(struct tnode *p)
{
  if (p != NULL)
  {
    treeprint (p->left);
    printf("%s (%d)\n", p->word, p->count);
    treeprint(p->right);
  }
}

/* stampa la forma e il contenuto dell'albero */
void StampaAlbero(Treenode *p, int l)
{
  int i;
  if (p != NULL)
  {
   StampaAlbero(p->right, l + 1);
   for (i = 0; i < l; i++)
    printf("  ");
	printf("%s\n",p->word);
	StampaAlbero(p->left, l + 1);
  }
}

/* crea un tnode */
Treenode *talloc(void)
{
  return (Treeptr)malloc(sizeof(Treenode));
}

/* crea una copia della stringa letta s */
char *strdupz(char *s)
{
  char *p;
  p = (char *)malloc(strlen(s) + 1);
  if (p != NULL) 
     strcpy(p, s);
  return p;
}

