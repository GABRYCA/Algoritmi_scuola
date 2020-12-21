#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int caricamento(int possibili[]);

void gen(int numeriinseriti[], int vett[], int nonvalidi[], int incremento[], int valorinonripetibili[], int incrementinonripetibili[], int mas, int n, int casi);

void visualnum(int numeriinseriti[],int mas);

int numeriposizione(int numtrovare[], int numeriinseriti[], int nonvalidi[], int incremento[], int mas);

void visualizzazione(int x, int y);

void scomposizione (int vett[], int numero, int mas);

void visuali(int vett[]);

int cancellavalori(int vett[], int incremento[],int nonvalidi[], int casi, int mas);

int main()
{
    int possibili[20200]={0};
    int numeriinseriti[4]={0};
    int numsingoli[4];
    int nonvalidi[10];
    int incremento[1]={0};
    int valorinonripetibili[1000];
    int incrementinonripetibili[1]={0};
    int tentativi, numinserito, vittoria, mas, contatore, casi;
    mas=4;
    vittoria=0;
    printf("---BENVENUTO---\n");
    printf("Ora dovrai inserire 4 numeri e il computer dovra' indovinarlo!!\n");
    printf("Quanti tentativi vuoi dare al computer: ");
    scanf("%d", &tentativi);
    printf("---SI INIZIA---\n");
    casi=caricamento(possibili);
    printf("Inserisci il numero: ");
    scanf("%d", &numinserito);
    scomposizione(numsingoli, numinserito, mas);
    for(contatore=0; contatore<tentativi && vittoria==0; contatore++)
    {
        casi=cancellavalori(possibili, incremento, nonvalidi, casi, mas);
        gen(numeriinseriti, possibili, nonvalidi, incremento, valorinonripetibili, incrementinonripetibili, mas, 0, casi);
        visualnum(numeriinseriti, mas);
        if (numeriposizione(numsingoli, numeriinseriti, nonvalidi, incremento, mas) == 1)
        {
            printf("\nFINE, numero trovato!");
            printf("\nL'ha risolto in %d", contatore);
            return 0;
        }
        system("PAUSE");
    }
    if(contatore==tentativi)
    {
        printf("\nFINE, tentativi superati numero non trovato!\n");
        return 0;
    }
}

int caricamento(int possibili[])
{
    int x, n1, n2, n3, n4, casi;
    casi=0;
    x=10;
    for(n1=0; n1<x; n1++)
    {
        for(n2=0; n2<x; n2++)
        {
            if(n1!=n2)
            {
                for(n3=0; n3<x; n3++)
                {
                    if(!(n3==n2 || n3==n1))
                    {
                        for(n4=0; n4<x; n4++)
                        {
                            if(!(n4==n3 || n4==n2 || n4==n1))
                            {
                                possibili[casi]=((n1*10+n2)*10+n3)*10+n4;
                                casi++;
                            }
                        }
                    }
                }
            }
        }
    }
    return casi;
}

void scomposizione(int vett[], int numero, int mas)
{
    int x;
    x=mas-1;
    for( int conta=x; conta>=0; conta--)
    {
        vett[conta]=numero%10;
        numero=(numero-vett[conta])/10;
    }
}

void gen(int numeriinseriti[], int vett[], int nonvalidi[], int incremento[], int valorinonripetibili[], int incrementinonripetibili[], int mas, int n, int casi)
{
    int conta, x, fine, conta2, condizione, condizione2, valore;
    condizione2=1;
    srand(time(0));
    while(condizione2!=0)
    {
        condizione2=1;
        for (conta=0; conta<mas; conta++) //QUANDO CONTA SARA' UGUALE A MAS LA FUNZIONE FINISCE
        {
            fine=0;
            while(fine==0) //QUANDO FINE SARA' UGUALE A 1 SI PASSERA' AL NUMERO SUCCESSIVO
            {
                condizione=0;
                numeriinseriti[conta]=(rand()%10);
                n=incremento[0];
                for(conta2=0; conta2<n; conta2++)
                {
                    if(nonvalidi[conta2]==numeriinseriti[conta])
                    {
                        condizione++;
                    }
                }
                if(condizione==0)
                {
                    fine=1;
                }
                for(x=0; x<conta; x++) //PERMETTE DI CONTROLLARE TUTTI I NUMERI E FINISCE QUANDO X E' UGUALE A CONTA
                {
                    if(numeriinseriti[conta]==numeriinseriti[x])
                    {
                        fine=0;
                    }
                }

            }
        }
        valore=((10*numeriinseriti[3]+numeriinseriti[2])*10+numeriinseriti[1])*10+numeriinseriti[0];
        for(conta=0; conta<casi; conta++)
        {
            if(valore==vett[conta] && condizione2!=0)
            {
                condizione2=0;
            }
        }
        for(conta=0; conta<incrementinonripetibili[0]; conta++)
        {
            if(valorinonripetibili[conta]==valore)
            {
                condizione2++;
            }
        }
    }
    valorinonripetibili[incrementinonripetibili[0]]=valore;
    incrementinonripetibili[0]++;
}

void visualnum(int numeriinseriti[],int mas)
{
    int conta;
    printf("\nI numeri casuali sono: \n");
    for (conta=0;conta<mas;++conta)
    {
        printf("%d-", conta);
        printf("%d \t", numeriinseriti[conta]);
    }
    printf("\n");
}

int numeriposizione(int numtrovare[], int numeriinseriti[], int nonvalidi[], int incremento[], int mas)
{
    int conta, x, y, valbandiara;
    x=0;
    y=0;
    for(conta=0; conta<mas; conta++)
    {
        valbandiara=0;
        if(numeriinseriti[conta]==numtrovare[conta])
        {
            x++;
            valbandiara++;
        }
        else
        {
            for(int contatore=0; contatore<mas; contatore++)
            {
                if(numeriinseriti[conta]==numtrovare[contatore])
                {
                    y++;
                    valbandiara++;
                }
            }
        }
        if(valbandiara==0)
        {
            nonvalidi[incremento[0]]=numeriinseriti[conta];
            incremento[0]++;
        }
    }
    visualizzazione(x, y);
    if(x==mas)
    {
        return 1;
    }
    return 0;
}

void visualizzazione(int x, int y)
{
    int conta;
    printf("[");
    for(conta=0; conta<y; conta++)
    {
        printf("+");
    }
    for(conta=0; conta<x; conta++)
    {
        printf("-");
    }
    printf("]");
    printf("\n");
}

int cancellavalori(int vett[], int incremento[], int nonvalidi[], int casi, int mas)
{
    for(int conta2=0; conta2<incremento[0]; conta2++)
    {
        for(int conta=0; conta<casi; conta++)
        {
            int singolival[mas];
            scomposizione(singolival, vett[conta2], mas);
            for(int conta3=0; conta3<mas; conta3++)
            {
                if(nonvalidi[conta2]==vett[conta3])
                {
                    for(int conta4=conta; conta4<casi-1; conta4++)
                    {
                        vett[conta4]=vett[conta4+1];
                    }
                    casi--;
                }
            }
        }
    }
    return casi;
}

void visuali(int vett[])
{
    printf("\nI numeri casuali sono: \n");
    for (int conta=0;conta<4; conta++)
    {
        printf("%d-", conta);
        printf("%d \t", vett[conta]);
    }
    printf("\n\n");
}
