/*Dimensione della console 120x30*/

#include<stdio.h>
#include <graphics.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <iomanip>

#define dimenx 185
#define dimenx2 325
#define dimeny 390
#define dimeny2 419
#define shift 260
#define SIZE 100
#define lento 1000
#define normale 750
#define veloce 250

typedef struct
{
    int r,g,b;
}strrgb;

typedef struct
{
    int x,y,x2,y2,occ,col;
}grandezza;

void vers_numerica(int n, int a, int b, int c);
void vers_grafica(int n, int a, int b, int c, grandezza vet[], grandezza vet2[], grandezza vet3[],strrgb vetcolore[], int speed);
int menu();

int main(void)
{
    grandezza vet[SIZE]={};
    grandezza vet2[SIZE]={};
    strrgb vetcolore[SIZE]={};
    grandezza vet3[SIZE]={};
    clock_t inizio, fine;
    int nd, piolofine, vel;
    int dimy=30;
    int dimx=10;
    double tempo;

    srand(time(NULL));

    inizio=clock();

    switch(menu())
    {
        case 1:

            cout<<"-Inserire il numero di dischi con cui giocare da 2 a 15: ";
            cin>>nd;

            cout<<"-Inserire il piolo su cui ricorstruire la torre da 1 a 3: ";
            cin>>piolofine;

            while(nd<2||nd>15||piolofine<1||piolofine>3)
            {
                if(nd<2||nd>15)
                {
                    cout<<"-ERRORE INSERIMENTO: Inserire il numero di dischi con cui giocare da 2 a 6: ";
                    cin>>nd;
                }
                else
                {
                    cout<<"-Inserire il piolo su cui ricorstruire la torre da 1 a 3: ";
                    cin>>piolofine;
                }
            }

            if(piolofine==2)
            {
                vers_numerica(nd, 1, 2, 3);
            }
            else if(piolofine==3)
            {
                vers_numerica(nd, 1, 3, 2);
            }

            break;

        case 2:

            system("cls");

            cout<<"-Inserire il numero di dischi con cui giocare da 2 a 7: ";
            cin>>nd;

            cout<<"-Inserire il piolo su cui ricorstruire la torre da 2 a 3: ";
            cin>>piolofine;

            cout<<"-1 per andare a velocita' lenta, 2 per velocita' normale, 3 per velocita' elevata: ";
            cin>>vel;

            while(nd<2||nd>7||piolofine<2||piolofine>3||vel<1||vel>3)
            {
                if(nd<2||nd>7)
                {
                    cout<<"-ERRORE INSERIMENTO: Inserire il numero di dischi con cui giocare da 2 a 6: ";
                    cin>>nd;
                }
                else if(piolofine!=2&&piolofine!=3)
                {
                    cout<<"-ERRORE INSERIMENTO: Inserire il piolo su cui ricostruire la torre da 1 a 3: ";
                    cin>>piolofine;
                }
                else
                {
                    cout<<"-ERRORE INSERIMENTO: Inserire la velocita': ";
                    cin>>vel;
                }
            }

            system("cls");

            if(vel==1)
            {
                vel=lento;
            }
            else if(vel==2)
            {
                vel=normale;
            }
            else if(vel==3)
            {
                vel=veloce;
            }

            for(int conta=0;conta<nd;conta++)
            {
                vet[conta].x=dimenx+(dimx*conta);
                vet[conta].x2=dimenx2-(dimx*conta);
                vet[conta].y=dimeny-(dimy*conta);
                vet[conta].y2=dimeny2-(dimy*conta);
                vet[conta].occ=1;
                vet[conta].col=conta;
                vet2[conta].occ=0;
                vet3[conta].occ=0;
                vet2[conta].y=vet[conta].y;
                vet2[conta].y2=vet[conta].y2;
                vet3[conta].y=vet[conta].y;
                vet3[conta].y2=vet[conta].y2;
            }

            rettangolo(0,420,1100,500,arancione,true);
            rettangolo(250,200,260,419,arancione,true);
            rettangolo(510,200,520,419,arancione,true);
            rettangolo(770,200,780,419,arancione,true);

            for(int conta=0;conta<nd;conta++)
            {
                vetcolore[conta].r=rand()%256;
                vetcolore[conta].g=rand()%256;
                vetcolore[conta].b=rand()%256;
            }

            for(int conta=0;conta<nd;conta++)
            {
                rettangolo(vet[conta].x,vet[conta].y,vet[conta].x2,vet[conta].y2,RGB(vetcolore[conta].r,vetcolore[conta].g,vetcolore[conta].b),true);
            }

            if(piolofine==2)
            {
                vers_grafica(nd,1,3,2,vet,vet2,vet3,vetcolore,vel);
            }
            if(piolofine==3)
            {
                vers_grafica(nd,1,2,3,vet,vet2,vet3,vetcolore,vel);
            }

            break;
    }

    fine=clock();

    tempo=(double)(fine-inizio)/CLOCKS_PER_SEC;

    cout<<endl<<"Tempo impiegato: "<<tempo;
}

void vers_numerica(int n,int a,int b,int c)
{
    if(n == 1)
    {
        cout<<"Muovi un disco dal piolo "<<a<<" al piolo "<<c<<endl;
    }
    else
    {
        vers_numerica(n-1, a, c, b);
        cout<<"Muovi un disco dal piolo "<<a<<" al piolo "<<c<<endl;
        vers_numerica(n-1, b, a, c);
    }
}

void vers_grafica(int n, int a, int b, int c, grandezza vet[], grandezza vet2[], grandezza vet3[],strrgb vetcolore[],int speed)
{
    int piolo1=0,piolo3=0;

    if(n==1)
    {
        Sleep(speed);

        if(a==1)
        {
            while(vet[piolo1].occ!=0)
            {
                piolo1++;
            }

            piolo1--;
            vet[piolo1].occ=0;

            rettangolo(vet[piolo1].x,vet[piolo1].y,vet[piolo1].x2,vet[piolo1].y2,RGB(12,12,12),true);
            rettangolo(250,vet[piolo1].y,260,vet[piolo1].y2,arancione,true);
        }

        if(a==2)
        {
            while(vet2[piolo1].occ!=0)
            {
                piolo1++;
            }

            piolo1--;
            vet2[piolo1].occ=0;

            rettangolo(vet2[piolo1].x,vet2[piolo1].y,vet2[piolo1].x2,vet2[piolo1].y2,RGB(12,12,12),true);
            rettangolo(510,vet2[piolo1].y,520,vet2[piolo1].y2,arancione,true);
        }
        if(a==3)
        {
            while(vet3[piolo1].occ!=0)
            {
                piolo1++;
            }

            piolo1--;
            vet3[piolo1].occ=0;

            rettangolo(vet3[piolo1].x,vet3[piolo1].y,vet3[piolo1].x2,vet3[piolo1].y2,RGB(12,12,12),true);
            rettangolo(770,vet3[piolo1].y,780,vet3[piolo1].y2,arancione,true);
        }

        if(c==1)
        {
            while(vet[piolo3].occ!=0)
            {
                piolo3++;
            }

            if(a==2)
            {
                vet[piolo3].x=vet2[piolo1].x-shift;
                vet[piolo3].x2=vet2[piolo1].x2-shift;
                vet[piolo3].col=vet2[piolo1].col;
            }

            if(a==3)
            {
                vet[piolo3].x=vet3[piolo1].x-(shift*2);
                vet[piolo3].x2=vet3[piolo1].x2-(shift*2);
                vet[piolo3].col=vet3[piolo1].col;
            }
            rettangolo(vet[piolo3].x,vet[piolo3].y,vet[piolo3].x2,vet[piolo3].y2,RGB(vetcolore[vet[piolo3].col].r,vetcolore[vet[piolo3].col].g,vetcolore[vet[piolo3].col].b),true);
            vet[piolo3].occ=1;
        }

        else if(c==2)
        {
            while(vet2[piolo3].occ!=0)
            {
                piolo3++;
            }

            if(a==1)
            {
                vet2[piolo3].x=vet[piolo1].x+shift;
                vet2[piolo3].x2=vet[piolo1].x2+shift;
                vet2[piolo3].col=vet[piolo1].col;
            }

            if(a==3)
            {
                vet2[piolo3].x=vet3[piolo1].x-shift;
                vet2[piolo3].x2=vet3[piolo1].x2-shift;
                vet2[piolo3].col=vet3[piolo1].col;
            }

            rettangolo(vet2[piolo3].x,vet2[piolo3].y,vet2[piolo3].x2,vet2[piolo3].y2,RGB(vetcolore[vet2[piolo3].col].r,vetcolore[vet2[piolo3].col].g,vetcolore[vet2[piolo3].col].b),true);
            vet2[piolo3].occ=1;
        }

        else if(c==3)
        {
            while(vet3[piolo3].occ!=0)
            {
                piolo3++;
            }

            if(a==1)
            {
                vet3[piolo3].x=vet[piolo1].x+(shift*2);
                vet3[piolo3].x2=vet[piolo1].x2+(shift*2);
                vet3[piolo3].col=vet[piolo1].col;
            }

            if(a==2)
            {
                vet3[piolo3].x=vet2[piolo1].x+shift;
                vet3[piolo3].x2=vet2[piolo1].x2+shift;
                vet3[piolo3].col=vet2[piolo1].col;
            }

            rettangolo(vet3[piolo3].x,vet3[piolo3].y,vet3[piolo3].x2,vet3[piolo3].y2,RGB(vetcolore[vet3[piolo3].col].r,vetcolore[vet3[piolo3].col].g,vetcolore[vet3[piolo3].col].b),true);
            vet3[piolo3].occ=1;
        }
    }
    else
    {
        vers_grafica(n-1, a, c, b,vet,vet2,vet3,vetcolore,speed);
        Sleep(speed);

        if(a==1)
        {
            while(vet[piolo1].occ!=0)
            {
                piolo1++;
            }

            piolo1--;
            vet[piolo1].occ=0;

            rettangolo(vet[piolo1].x,vet[piolo1].y,vet[piolo1].x2,vet[piolo1].y2,RGB(12,12,12),true);
            rettangolo(250,vet[piolo1].y,260,vet[piolo1].y2,arancione,true);
        }

        if(a==2)
        {
            while(vet2[piolo1].occ!=0)
            {
                piolo1++;
            }
            piolo1--;
            vet2[piolo1].occ=0;

            rettangolo(vet2[piolo1].x,vet2[piolo1].y,vet2[piolo1].x2,vet2[piolo1].y2,RGB(12,12,12),true);
            rettangolo(510,vet2[piolo1].y,520,vet2[piolo1].y2,arancione,true);
        }

        if(a==3)
        {
            while(vet3[piolo1].occ!=0)
            {
                piolo1++;
            }

            piolo1--;
            vet3[piolo1].occ=0;

            rettangolo(vet3[piolo1].x,vet3[piolo1].y,vet3[piolo1].x2,vet3[piolo1].y2,RGB(12,12,12),true);
            rettangolo(770,vet3[piolo1].y,780,vet3[piolo1].y2,arancione,true);
        }

        if(c==1)
        {
            while(vet[piolo3].occ!=0)
            {
                piolo3++;
            }

            if(a==2)
            {
                vet[piolo3].x=vet2[piolo1].x-shift;
                vet[piolo3].x2=vet2[piolo1].x2-shift;
                vet[piolo3].col=vet2[piolo1].col;
            }

            if(a==3)
            {
                vet[piolo3].x=vet3[piolo1].x-(shift*2);
                vet[piolo3].x2=vet3[piolo1].x2-(shift*2);
                vet[piolo3].col=vet3[piolo1].col;
            }

            rettangolo(vet[piolo3].x,vet[piolo3].y,vet[piolo3].x2,vet[piolo3].y2,RGB(vetcolore[vet[piolo3].col].r,vetcolore[vet[piolo3].col].g,vetcolore[vet[piolo3].col].b),true);
            vet[piolo3].occ=1;
        }

        else if(c==2)
        {
            while(vet2[piolo3].occ!=0)
            {
                piolo3++;
            }
            if(a==1)
            {
                vet2[piolo3].x=vet[piolo1].x+shift;
                vet2[piolo3].x2=vet[piolo1].x2+shift;
                vet2[piolo3].col=vet[piolo1].col;
            }
            if(a==3)
            {
                vet2[piolo3].x=vet3[piolo1].x-shift;
                vet2[piolo3].x2=vet3[piolo1].x2-shift;
                vet2[piolo3].col=vet3[piolo1].col;
            }

            rettangolo(vet2[piolo3].x,vet2[piolo3].y,vet2[piolo3].x2,vet2[piolo3].y2,RGB(vetcolore[vet2[piolo3].col].r,vetcolore[vet2[piolo3].col].g,vetcolore[vet2[piolo3].col].b),true);
            vet2[piolo3].occ=1;
        }
        else if(c==3)
        {
            while(vet3[piolo3].occ!=0)
            {
                piolo3++;
            }

            if(a==1)
            {
                vet3[piolo3].x=vet[piolo1].x+(shift*2);
                vet3[piolo3].x2=vet[piolo1].x2+(shift*2);
                vet3[piolo3].col=vet[piolo1].col;
            }

            if(a==2)
            {
                vet3[piolo3].x=vet2[piolo1].x+shift;
                vet3[piolo3].x2=vet2[piolo1].x2+shift;
                vet3[piolo3].col=vet2[piolo1].col;
            }

            rettangolo(vet3[piolo3].x,vet3[piolo3].y,vet3[piolo3].x2,vet3[piolo3].y2,RGB(vetcolore[vet3[piolo3].col].r,vetcolore[vet3[piolo3].col].g,vetcolore[vet3[piolo3].col].b),true);
            vet3[piolo3].occ=1;
        }

        vers_grafica(n-1, b, a, c,vet,vet2,vet3,vetcolore,speed);
    }
}

int menu()
{
    int i;
    system("color 1e");
    cout<<"\t\t\t\t\t\t\t#################"<<endl;
    cout<<"\t\t\t\t\t\t\t#TORRE DI HANOI!#"<<endl;
    cout<<"\t\t\t\t\t\t\t#################"<<endl<<endl<<">Questo gioco ha lo scopo di andare a ricostruire la torre di dischi sul paletto selezionato dall'utente";
    cout<<endl<<">L'unica regola e' quella che non possono essere messi dischi di dimensione minore al di sotto di dischi di \ndimensione maggiore";
    cout<<endl<<endl<<"Selezionare la modalita' che si vuole eseguire..."<<endl<<"-1.Versione numerica"<<endl<<"-2.Versione grafica"<<endl<<"Scelta: ";
    cin>>i;

    while(i>2&&i<1)
    {
        cout<<endl<<"ERRORE INSERIMENTO: inserire una scelta di inserimento valida: ";
        cin>>i;
    }

    system("color 0f");
    system("cls");

    return i;
}
