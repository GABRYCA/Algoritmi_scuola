#include "bicchiere.h"


/* metodi costruttori */
Bicchiere::Bicchiere()
{
   strcpy(forma,"");
   strcpy(materiale,"");
   capacita = 0;
   livello = 0;
   printf("nuovo bicchiere creato!\n");
}

Bicchiere::Bicchiere(char *f, char *m, float c, float l)
{
   strcpy(forma, f);
   strcpy(materiale, m);
   capacita = c;
   livello = l;
   printf("nuovo bicchiere creato!\n");
}

/* metodo distruttore */
Bicchiere::~Bicchiere()
{
   printf("oggetto eliminato!\n");                                         
}

/* metodi get */
char *Bicchiere::GetForma()
{
     return forma;     
}

char *Bicchiere::GetMateriale()
{
     return materiale;     
}

float Bicchiere::GetCapacita()
{
      return capacita;      
}
     
float Bicchiere::GetLivello()
{
      return livello;      
}

/* metodi set */
void Bicchiere::SetForma(char *f)
{
     strcpy(forma, f);     
}

void Bicchiere::SetMateriale(char *m)
{
     strcpy(materiale, m);     
}

void Bicchiere::SetCapacita(float c)
{
     capacita = c;     
} 

void Bicchiere::SetLivello(float l)
{
     livello = l;     
}
     
void Bicchiere::Riempi()
{
     livello = capacita;     
}

void Bicchiere::Svuota()
{
     livello = 0;     
}
