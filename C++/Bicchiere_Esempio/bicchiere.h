#include<stdio.h>
#include<stdlib.h>
#include<string.h>


class Bicchiere
{
   private:
     char forma[20];
     char materiale[20];
     float capacita;
     float livello;
   public:
     Bicchiere();
     Bicchiere(char *, char *, float, float);
     ~Bicchiere();
     char *GetForma();
     char *GetMateriale();
     float GetCapacita();
     float GetLivello();
     void SetForma(char *);
     void SetMateriale(char *);
     void SetCapacita(float);
     void SetLivello(float);
     void Riempi();
     void Svuota();
};
