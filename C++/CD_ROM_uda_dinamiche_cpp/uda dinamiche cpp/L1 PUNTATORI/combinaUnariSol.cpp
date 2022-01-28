/* File: combinaUnariSol.cpp               */
/* Time-stamp: "2015-09-29 19:52:48 paolo" */
/* Scopo: relazione tra gli operatori di dereferenziamento * e indirizzo & */
/* HOEPLI - Informatica in C e C++ - 2016  */
int main()
{
  int num = 7,*pi;  // dic. var. intera e punta _intero
  pi = &num;        // al puntatore assegno l'indirizzo
  // modalità di visualizzazione dell'indirizzo della variabile num
  printf("indirizzo di num  = 0x%X\n", &num);
  printf("valore di punta   = 0x%X\n", pi);
  printf("valore di &*punta = 0x%X\n", &*pi);
  putchar('\n');
 // modalità visualizzazione del valore della variabile num
  printf("valore di num    = %d\n", num);
  printf("valore di *punta = %d\n", *pi);
  printf("valore di *&num  = %d\n", *&num);
  printf("\n\n");
}





 

















