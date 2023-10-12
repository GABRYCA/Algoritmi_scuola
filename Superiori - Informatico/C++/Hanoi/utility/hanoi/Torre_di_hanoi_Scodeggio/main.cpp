#include<stdio.h>
#include <graphics.h>
#include <iostream>
#include <time.h>
#include <windows.h>

#define dimensionix 155
#define dimensionix2 355
#define dimensioniy 390
#define dimensioniy2 419
#define spostamento 260
#define ypiolo 130
#define finepiolo 419
#define distanzapiolo 250
#define fineschermox 1030
#define fineschermoy 500

#define SIZE 100

typedef struct
{
    int r,g,b;
}colore;

typedef struct
{
    int x,y,x2,y2;
    int occ;
    int col;
}dimensioni;

void muovi_dischi_num(int n, int a, int b, int c);
void muovi_dischi_grafico(int n, int a, int b, int c, dimensioni vet[], dimensioni vet2[], dimensioni vet3[],colore vetcolore[], int vel);
void disegno(int a, int c, dimensioni vet[], dimensioni vet2[], dimensioni vet3[],colore vetcolore[], int vel);
BOOL setcolor(WORD Color);

int menu()
{
    setcolor(1);
    printf("\n\n\t\tษออออออออออออออออออออออออออออออออ  LA TORRE DI HANOI!  ออออออออออออออออออออออออออออออป\n");
    int i=0;
    setcolor(12);
    printf("\n\n\t\t\t\t\t   ATTENZIONE:USARE LA FINESTRA 125x30\n");
    setcolor(0);
    printf("\n\t\t\t\t\t\t  Cosa vuoi fare?\n\t\t\t\t\t\t  1.Hanoi con numeri\n\t\t\t\t\t\t  2.Hanoi grafico\n\t\t\t\t\t\t  3.Spiegazione e regole del gioco\n\t\t\t\t\t\t  0.esci");
    setcolor(1);
    printf("\n\n\n\t\tศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n");
    setcolor(0);
    printf("\t\t\t\t\t\t  Scelta: ");
    scanf("%d",&i);

    return i;

}

void regole()
{
    setcolor(1);
    printf("\n\n\t\tษออออออออออออออออออออออออออออออออ  SCOPO E REGOLE DEL GIOCO!  อออออออออออออออออออออออออออออออป\n");
    int i=0;
    setcolor(2);
    printf("\n\t\t\t\t\t\t        SCOPO DEL GIOCO:");
    setcolor(0);
    printf("\n\n\t\t        Lo scopo del gioco e' quello di spostare tutti i dischi dal primo piolo a quello\n\t\t        selezionato dall'utente, seguendo queste regole:");
    setcolor(2);
    printf("\n\n\t\t\t\t\t\t       REGOLE DEL GIOCO:");
    setcolor(0);
     printf("\n\n\t\t\t1.I dischi piu' grandi non possono stare sopra dischi piu' piccoli");
     printf("\n\t\t\t2.Posso spostare solo un disco alla volta");
     printf("\n\t\t\t3.Posso spostare solo il disco piu' in alto sul piolo");
    setcolor(1);
    printf("\n\n\n\t\tศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n");
    setcolor(0);
    printf("\nOra che sai le regole, ");
    system("pause");
    system("cls");

}

int main()
{
    int vel=0;
    srand(time(NULL));
    system("color 70");
    dimensioni vet[SIZE]={};
    dimensioni vet2[SIZE]={};
    colore vetcolore[SIZE]={};
    dimensioni vet3[SIZE]={};
  int n,chiusura=1;
  int scelta=0;
  int scelta1=1;
  int cont=0;
  int dimy=30;
  int dimx=10;

  do
  {

      scelta=menu();

      switch(scelta)
      {
          case 1:
              system("cls");
          do {
                if(cont==1)
                {
                    printf("\nErrore. Inserisci i dati correttamente.");
                }
                printf("\nquanti dischi vuoi utilizzare?: ");
                scanf("%d", &n);
                printf("\nSu che piolo vuoi terminare?(2 o 3): ");
                scanf("%d",&chiusura);
                cont=1;
              } while(n <= 0 || chiusura<2 || chiusura>3);
              if(chiusura==3)
              {
                muovi_dischi_num(n, 1, 2, 3);
              }
              else if(chiusura==2)
              {
                  muovi_dischi_num(n, 1, 3, 2);
              }
              printf("\n");
              system("pause");
              system("cls");
              break;
          case 2:
              system("cls");
              cont=0;
              do {
                if(cont==1)
                {
                    printf("\nErrore. Inserisci i dati correttamente.\n");
                    system("pause");
                    system("cls");
                }
                printf("\nquanti dischi vuoi utilizzare?(1-10): ");
                scanf("%d", &n);
                printf("\nSu che piolo vuoi terminare? (2 o 3): ");
                scanf("%d",&chiusura);
                printf("\nSeleziona la velocita': lenta, media o veloce? (1-2-3): ");
                scanf("%d",&vel);
                cont=1;
              } while(n <= 0 || n>10 || chiusura<2 || chiusura>3 || vel<1 || vel> 3);
                system("cls");
                    if(vel==1)
                        vel=1000;
                    else if(vel==2)
                        vel=500;
                    else
                        vel=100;
                    for(cont=0;cont<n;cont++)
                    {
                      vet[cont].x=dimensionix+(dimx*cont);
                      vet[cont].x2=dimensionix2-(dimx*cont);
                      vet[cont].y=dimensioniy-(dimy*cont);
                      vet[cont].y2=dimensioniy2-(dimy*cont);
                      vet[cont].occ=1;
                      vet[cont].col=cont;
                      vet2[cont].occ=0;
                      vet3[cont].occ=0;
                      vet2[cont].y=vet[cont].y;
                      vet2[cont].y2=vet[cont].y2;
                      vet3[cont].y=vet[cont].y;
                      vet3[cont].y2=vet[cont].y2;
                    }
                      for(cont=0;cont<n;cont++)
                      {
                          vetcolore[cont].r=rand()%250;
                          vetcolore[cont].g=rand()%250;
                          vetcolore[cont].b=rand()%250;
                      }
                    rettangolo(0,finepiolo+1,fineschermox,fineschermoy,bianco,true);
                    rettangolo(distanzapiolo,ypiolo,distanzapiolo+10,finepiolo,bianco,true);
                    rettangolo(distanzapiolo*2+10,ypiolo,distanzapiolo*2+20,finepiolo,bianco,true);
                    rettangolo(distanzapiolo*3+20,ypiolo,distanzapiolo*3+30,finepiolo,bianco,true);

                    for(cont=0;cont<n;cont++)
                    {
                        rettangolo(vet[cont].x,vet[cont].y,vet[cont].x2,vet[cont].y2,RGB(vetcolore[cont].r,vetcolore[cont].g,vetcolore[cont].b),true);
                    }
                    if(chiusura==2)
                    {
                      muovi_dischi_grafico(n, 1, 3,2,vet,vet2,vet3,vetcolore,vel);
                    }
                    else
                      muovi_dischi_grafico(n, 1, 2,3,vet,vet2,vet3,vetcolore,vel);
                    system("pause");
                    system("cls");
              break;
          case 3:
              system("cls");
              regole();
              break;
          case 0:
              printf("\nGrazie per aver utilizzato il programma!\n\n");
            scelta1=0;
            break;
          default:
            printf("\n\nIl numero inserito non e' valido. Seleziona un'opzione valida!\n");
            system("pause");
            system("cls");
            break;
        }
  }while(scelta1==1);

    return 0;
}

void muovi_dischi_num(int n, int a,int  b,int c)
{
  if(n == 1) {
    printf("\nMuovi un disco dal piolo %d al piolo %d\n", a, c);
  }
  else {
    muovi_dischi_num(n-1, a, c, b);
    printf("\nMuovi un disco dal piolo %d al piolo %d\n", a, c);
    muovi_dischi_num(n-1, b, a, c);
  }
}

void muovi_dischi_grafico(int n, int a, int b, int c, dimensioni vet[], dimensioni vet2[], dimensioni vet3[],colore vetcolore[], int vel)
{

    if(n==1)
    {
       disegno(a,c,vet,vet2,vet3,vetcolore,vel);
    }
    else
    {
        muovi_dischi_grafico(n-1, a, c, b,vet,vet2,vet3,vetcolore,vel);
        disegno(a,c,vet,vet2,vet3,vetcolore,vel);
        muovi_dischi_grafico(n-1, b, a, c,vet,vet2,vet3,vetcolore,vel);
    }

}

void disegno(int a, int c, dimensioni vet[], dimensioni vet2[], dimensioni vet3[],colore vetcolore[], int vel)
{
    Sleep(vel);
    int posa=0,posc=0;

        if(a==1)
    {
        while(vet[posa].occ!=0)
        {
            posa++;
        }
        posa--;
        vet[posa].occ=0;
        rettangolo(vet[posa].x,vet[posa].y,vet[posa].x2,vet[posa].y2,RGB(192,192,192),true);
        rettangolo(250,vet[posa].y,260,vet[posa].y2,bianco,true);
    }
    if(a==2)
    {
        while(vet2[posa].occ!=0)
        {
            posa++;
        }
        posa--;
        vet2[posa].occ=0;
        rettangolo(vet2[posa].x,vet2[posa].y,vet2[posa].x2,vet2[posa].y2,RGB(192,192,192),true);
        rettangolo(510,vet2[posa].y,520,vet2[posa].y2,bianco,true);
    }
    if(a==3)
    {
        while(vet3[posa].occ!=0)
        {
            posa++;
        }
        posa--;
        vet3[posa].occ=0;
        rettangolo(vet3[posa].x,vet3[posa].y,vet3[posa].x2,vet3[posa].y2,RGB(192,192,192),true);
        rettangolo(770,vet3[posa].y,780,vet3[posa].y2,bianco,true);
    }

    if(c==1)
    {
        while(vet[posc].occ!=0)
        {
            posc++;
        }
        if(a==2)
        {
            vet[posc].x=vet2[posa].x-spostamento;
            vet[posc].x2=vet2[posa].x2-spostamento;
            vet[posc].col=vet2[posa].col;
        }
        if(a==3)
        {
            vet[posc].x=vet3[posa].x-(spostamento*2);
            vet[posc].x2=vet3[posa].x2-(spostamento*2);
            vet[posc].col=vet3[posa].col;
        }
        rettangolo(vet[posc].x,vet[posc].y,vet[posc].x2,vet[posc].y2,RGB(vetcolore[vet[posc].col].r,vetcolore[vet[posc].col].g,vetcolore[vet[posc].col].b),true);
        vet[posc].occ=1;
    }
    else if(c==2)
    {
        while(vet2[posc].occ!=0)
        {
            posc++;
        }
        if(a==1)
        {
            vet2[posc].x=vet[posa].x+spostamento;
            vet2[posc].x2=vet[posa].x2+spostamento;
            vet2[posc].col=vet[posa].col;
        }
        if(a==3)
        {
            vet2[posc].x=vet3[posa].x-spostamento;
            vet2[posc].x2=vet3[posa].x2-spostamento;
            vet2[posc].col=vet3[posa].col;
        }
        rettangolo(vet2[posc].x,vet2[posc].y,vet2[posc].x2,vet2[posc].y2,RGB(vetcolore[vet2[posc].col].r,vetcolore[vet2[posc].col].g,vetcolore[vet2[posc].col].b),true);
        vet2[posc].occ=1;
    }
   else if(c==3)
    {
        while(vet3[posc].occ!=0)
        {
            posc++;
        }
        if(a==1)
        {
            vet3[posc].x=vet[posa].x+(spostamento*2);
            vet3[posc].x2=vet[posa].x2+(spostamento*2);
            vet3[posc].col=vet[posa].col;
        }
        if(a==2)
        {
            vet3[posc].x=vet2[posa].x+spostamento;
            vet3[posc].x2=vet2[posa].x2+spostamento;
            vet3[posc].col=vet2[posa].col;
        }
        rettangolo(vet3[posc].x,vet3[posc].y,vet3[posc].x2,vet3[posc].y2,RGB(vetcolore[vet3[posc].col].r,vetcolore[vet3[posc].col].g,vetcolore[vet3[posc].col].b),true);
        vet3[posc].occ=1;
    }
}



BOOL setcolor(WORD Color)
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
const WORD fgAttributes = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const WORD bgAttributes = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
if(hCon==INVALID_HANDLE_VALUE)
return FALSE;
CONSOLE_SCREEN_BUFFER_INFO csbi;
if(!GetConsoleScreenBufferInfo(hCon,&csbi))
return FALSE;
Color = (Color & fgAttributes) | (csbi.wAttributes & bgAttributes);
if(!SetConsoleTextAttribute(hCon,Color))
return FALSE;
}


