#include <iostream>
#include "graphics/graphics.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

//QUESTE ELENCATE SONO LE FUNZIONI
void torre_di_hanoi_numerico(int cilindri, int A, int B, int C);
void torre_di_hanoi_grafico(int cilindri, int A, int B, int C);
int prima_posizione(int n);
void visualizzazione_grafica();
void pulizia_grafica();
void riempimento_iniziale();

//QUESTE SONO VARIABILI GLOBALI
int delay, n_cilindri_graf, unita=30, matrice[10][3]={0};
bool pausa=false;

int main()
{
    //SONO VARIABILI
    int scelta, cilindri, torre, grandezza;
    do
    {
        system("CLS");
        cout << "--MENU' HANOI--" <<endl;
        cout << "1: Hanoi numerico." <<endl;
        cout << "2: Hanoi grafico." <<endl;
        cout << "0: Fine." <<endl;
        cin >> scelta;
        system("CLS");
        switch(scelta)
        {
            case 1:
                do
                {
                    system("CLS");
                    cout << "Inserisci il numero di cilindri compreso tra 3 e 10: "<<endl;
                    cin >> cilindri;
                }while(cilindri<3 or cilindri>10);
                do
                {
                    system("CLS");
                    cout << "Inserisci il numero della torre in cui deve andare (2 o 3): "<<endl;
                    cin >> torre;
                }while(torre<2 or torre>3);
                if(!pausa)
                {
                    system("CLS");
                    cout << "Inserisci il delay in millisecondi: "<<endl;
                    cin >> delay;
                }
                if(torre==2)
                {
                    system("CLS");
                    torre_di_hanoi_numerico(cilindri, 1, 2, 3);
                }
                else
                {
                    system("CLS");
                    torre_di_hanoi_numerico(cilindri, 1, 3, 2);
                }
                system("\nPAUSE");
                break;

            case 2:
                do
                {
                    system("CLS");
                    cout << "Inserisci il numero di cilindri compreso tra 3 e 10: "<<endl;
                    cin >> cilindri;
                    n_cilindri_graf=cilindri;
                }while(cilindri<3 or cilindri>10);
                do
                {
                    system("CLS");
                    cout << "Inserisci il numero della torre in cui deve andare (2 o 3): "<<endl;
                    cin >> torre;
                }while(torre<2 or torre>3);
                if(!pausa)
                {
                    system("CLS");
                    cout << "Inserisci il delay in millisecondi: "<<endl;
                    cin >> delay;
                }
                riempimento_iniziale();
                if(torre==2)
                {
                    system("CLS");
                    torre_di_hanoi_grafico(cilindri, 0, 1, 2);
                }
                else
                {
                    system("CLS");
                    torre_di_hanoi_grafico(cilindri, 0, 2, 1);
                }
                if(!pausa)
                {
                    Sleep(10000);
                }
                system("\nPAUSE");
                break;

            case 0:
                cout << "PROGRAMMA TERMINATO." <<endl;
                return 0;

            default:
                cout << "NUMERO SCRITTO NON VALIDO." <<endl;
                system("PAUSE");
        }
    }
    while(scelta!=0);
}

void torre_di_hanoi_numerico(int cilindri, int A, int B, int C)
{
    if(cilindri==1)
    {
        //VADO A VISUALIZZARE
        cout << "Spostato disco "<< cilindri;
        cout << " dalla colonna "<< A;
        cout << " alla colonna "<< B <<endl;
        if(!pausa)
        {
            Sleep(delay);
        }
        return;
    }
    else
    {
        //RICHIAMO LA FUNZIONE DECREMENTANDO CILINDRI
        torre_di_hanoi_numerico(cilindri-1, A, C, B);
        //VADO A VISUALIZZARE
        cout << "Spostato disco "<< cilindri;
        cout << " dalla colonna "<< A;
        cout << " alla colonna "<< B <<endl;
        if(!pausa)
        {
            Sleep(delay);
        }
        //RICHIAMO LA FUNZIONE DECREMENTANDO CILINDRI E SCAMBIANDO LE VARIABILI A B C
        torre_di_hanoi_numerico(cilindri-1, C, B, A);
    }
}

void torre_di_hanoi_grafico(int cilindri, int A, int B, int C)
{
    if(cilindri==1)
    {
        //VADO A SPOSTARE IL PRIMO CILINDRO IN CIMA
        matrice[prima_posizione(A)][A]=0;
        matrice[prima_posizione(B)+1][B]=1;
        if(!pausa)
        {
            Sleep(delay);
        }
        //FACCIO LA VISUALIZZAZIONE GRAFICA
        visualizzazione_grafica();
        return;
    }
    else
    {
        //RICHIAMO LA FUNZIONE DECREMENTANDO CILINDRI
        torre_di_hanoi_grafico(cilindri-1, A, C, B);
        //VADO A SPOSTARE IL CILINDRO IN CIMA
        matrice[prima_posizione(A)][A]=0;
        matrice[prima_posizione(B)+1][B]=cilindri;
        if(!pausa)
        {
            Sleep(delay);
        }
        //FACCIO LA VISUALIZZAZIONE GRAFICA
        visualizzazione_grafica();
        //RICHIAMO LA FUNZIONE DECREMENTANDO CILINDRI E SCAMBIANDO LE VARIABILI A B C
        torre_di_hanoi_grafico(cilindri-1, C, B, A);
    }
}

int prima_posizione(int n)
{
    int n1=-1;
    //VADO A CERCARE LA POSIZIONE DELL'ELEMENTO IN CIMA ALLA MATRICE
    while(true)
    {
        if(matrice[n1+1][n]!=0)
        {
            n1++;
        }
        else
        {
            return n1;
        }
    }
}

void visualizzazione_grafica()
{
    int parametro=30, centro, altezza, coordinate, orizzontale, verticale;
    pulizia_grafica();
    //VADO A VISUALIZZARE LA BASE E LE TRE ASTE
    rettangolo(2*parametro, 11*parametro, 16*parametro, 9*parametro, bianco, true);
    linea(4*parametro, 9*parametro, 4*parametro, 1*parametro, bianco);
    linea(9*parametro, 9*parametro, 9*parametro, 1*parametro, bianco);
    linea(14*parametro, 9*parametro, 14*parametro, 1*parametro, bianco);
    orizzontale=(2*parametro-16*parametro)/(n_cilindri_graf*1.5);
    verticale=(9*parametro-1*parametro)/(n_cilindri_graf*1);
    //VADO A VISUALIZZARE PER OGNI ASTA I SUOI CERCHI
    for(int conta=0; conta<3; conta++)
    {
        printf("\nVet %d ", conta);
        altezza=9*parametro;
        //GRAZIE A QUESTI IF VADO A PRENDERE IL CENTRO PER L'ASTA CHE MI SERVE
        if(conta==0)
        {
            centro=4*parametro;
        }
        else if(conta==1)
        {
            centro=9*parametro;
        }
        else if(conta==2)
        {
            centro=14*parametro;
        }
        //VADO A VISUALIZZARE CILINDRO PER CILINDRO
        for(int conta2=0; conta2<n_cilindri_graf; conta2++)
        {
            if(matrice[conta2][conta]!=0)
            {
                printf("\t[%d]", matrice[conta2][conta]);
                coordinate=(matrice[conta2][conta]*orizzontale)/5;
                rettangolo(centro-coordinate, altezza, centro+coordinate, altezza-verticale, blu, false);
            }
            altezza-=verticale;
        }
    }
}

void pulizia_grafica()
{
    //VADO A CREARE UN RETTANGOLO NERO PER PULIRE LA SCHERMATA
    rettangolo(0, 0, 10000, 10000, nero, true);
}

void riempimento_iniziale()
{
    //VADO A SETTARE I VALORI INIZIALI
    for(int conta=0; conta<n_cilindri_graf; conta++)
    {
        matrice[conta][0]=n_cilindri_graf-conta;
    }
}
