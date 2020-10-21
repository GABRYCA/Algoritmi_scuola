#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Inizializzazione variabili
int A=0,B=0,conta=0,Cifre=0,somma=0,Copia_Funzione=0,contatore=0,num=1;
float Conta_Cifre=0,Copia,Decimale_Intero;
//inizializzazione della funzione Stampa radici
void Stampa_radici(int Val1_,int Val2_);
//Inizializzazione funzione rapporto
int Rapporto(int Dividendo,int Divisore);
//Inizializzazione funzione Resto
int Resto(int Dividendo,int Divisore);
//Inizializzazione funzione prodotto
int Prodotto(int Fattore1,int Fattore2);
//funzione senza return per la stampa dei quadrati compresi tra 2 valori
void Stampa_radici(int Val1_,int Val2_){
    int Base=0;
    while(Prodotto(Base,Base)<=Val2_){
        if(Prodotto(Base,Base)>=Val1_){
            printf("%d e' la base del suo quadrato ovvero %d\n",Base,Prodotto(Base,Base));
        }
        Base++;
    }
}
//Funzione senza return per la stampa dei valori
void Stampa_Valori(int Valore){
    while(Valore>0){
        printf("%d\n",Valore-Rapporto(Valore,10)*10);
        Valore=Rapporto(Valore,10);
    }
}
//Funzione M_C_M
int M_C_M(int m_c_m){
    while(Resto(m_c_m,A)!=0||Resto(m_c_m,B)!=0){
        m_c_m++;
    }
    return m_c_m;
}
//Funzione M_C_D
int M_C_D(int m_c_d){
    while(Resto(A,m_c_d)!=0||Resto(B,m_c_d)!=0){
        m_c_d--;
    }
    return m_c_d;
}
//Funzione Contatore numero cifre
int Numero_Cifre(float contatore_cifre){
    Cifre=0;
    if(contatore_cifre<0){
        contatore_cifre=contatore_cifre*-1;
    }
    contatore_cifre=contatore_cifre/10;
    while(Rapporto(Copia,1)!=contatore_cifre){
        conta=0;
        contatore_cifre=contatore_cifre*10;
        Copia=contatore_cifre;
    }
    while(contatore_cifre>0){
        Cifre++;
        contatore_cifre=Rapporto(contatore_cifre,10);
    }
    return Cifre;
}
//Funzione rapporto
int Rapporto(int Dividendo,int Divisore){
    conta=0;
    while(Dividendo>=Divisore){
        Dividendo=Dividendo-Divisore;
        conta++;
    }
    return conta;
}
//Funzione resto
int Resto(int Dividendo,int Divisore){
    while(Dividendo>=Divisore){
        Dividendo=Dividendo-Divisore;
    }
    return Dividendo;
}
//Funzione prodotto
int Prodotto(int Fattore1,int Fattore2){
    somma=0;
    for(;Fattore2>0;Fattore2--){
        somma=somma+Fattore1;
    }
    return somma;
}
int main()
{
    printf("Premere a per eseguire il programma dei prodotti\nPremere b per eseguire il programma della divisione\nPremere c per eseguire il programma del calcolo numero di cifre\nPremere d per eseguire il programma dei multipli di 7\nPremere e per eseguire il programma del riconoscimento pari/dispari di un valore\nPremere f per eseguire il programma del riconoscimento decimale/intero di un valore\nPremere g per eseguire l'M.C.D tra 2 valori\nPremere h per eseguire l'M.C.M tra 2 valori\nPremere i per eseguire la media di n voti\nPremere j per eseguire il programma del calcolo di n numeri perfetti\nPremere k per eseguire il programma dell'unione delle cifre\nPremere l per eseguire il programma del calcolo della tabella pitagorica in un intervallo di 2 valori\nPremere m per eseguire il programma della scomposizione di un numero nelle sue cifre\nPremere n per eseguire il programma del calcolo dei quadrati perfetti tra 2 valori\n");
    char Alex=getchar();
//Switch con i relativi case per eseguire gli algoritmi
    switch(Alex){
        case 'a':
            //algoritmo prodotto
            printf("Moltiplicazione\nInserisci il primo valore\n");
            scanf("%d",&A);
            printf("Inserisci il secondo valore\n");
            scanf("%d",&B);
            printf("%d",Prodotto(A,B));
            break;
        case 'b':
            //algoritmo rapporto
            printf("Divisione intera\nInserisci il dividendo\n");
            scanf("%d",&A);
            printf("Inserisci il divisore\n");
            scanf("%d",&B);
            printf("Quoziente:%d\nResto:%d",Rapporto(A,B),Resto(A,B));
            break;
        case 'c':
            //algoritmo calcolo numero di cifre
            printf("Calcolo numero di cifre\nInserisci il valore\n");
            scanf("%f",&Conta_Cifre);
            printf("Numero di cifre:%d",Numero_Cifre(Conta_Cifre));
            break;
        case 'd':
            //algoritmo verifica multipli di 7
            printf("Verifica valori multipli di 7\nInserisci il valore\n");
            scanf("%d",&A);
            while(somma<A){
                somma=somma+7;
            }
            if(somma==A){
                printf("%d e' un multiplo di 7",A);
            }else{
                printf("%d non e' un multiplo di 7",A);
            }
            break;
        case 'e':
            //algoritmo verifica pari dispari
            printf("Programma pari/dispari\nInserisci il valore\n");
            scanf("%d",&A);
            if(Resto(A,2)==0){
                printf("%d e' un valore pari",A);
            }else{
                printf("%d e' un valore dispari",A);
            }
            break;
        case 'f':
            //algoritmo verifica decimale/intero
            printf("Decimale/Intero\nInserisci il valore\n");
            scanf("%f",&Decimale_Intero);
            Copia=Decimale_Intero;
            while(Copia>=1){
                Copia--;
            }
            if(Copia==0){
                printf("%.0f e' intero",Decimale_Intero);
            }else{
                printf("%f e' decimale",Decimale_Intero);
            }
            break;
        case 'g':
            //algoritmo calcolo M.C.D
            printf("M.C.D\nInserisci il primo valore\n");
            scanf("%d",&A);
            printf("Inserisci il secondo valore\n");
            scanf("%d",&B);
            if(A>B){
                printf("L'M.C.D e' pari a %d",M_C_D(B));
            }else if(A<B){
                printf("L'M.C.D e' pari a %d",M_C_D(A));
            }else{
                printf("L'M.C.D e' pari a %d",A);
            }
            break;
        case 'h':
            //algoritmo calcolo m.c.m
            printf("m_c_m\nInserisci il primo valore\n");
            scanf("%d",&A);
            printf("Inserisci il secondo valore\n");
            scanf("%d",&B);
            if(A>B){
                printf("L'm.c.m e' pari a %d",M_C_M(A));
            }else if(A<B){
                printf("L'm.c.m e' pari a %d",M_C_M(B));
            }else{
                printf("L'm.c.m e' pari a %d",A);
            }
            break;
        case 'i':
            //algoritmo media voti
            printf("Media voti, verranno contati valori >=0 e <=100\n");
            while(A!=-1){
                printf("Inserisci il valore\n");
                scanf("%d",&A);
                if(A>=0&&A<=100){
                    somma=somma+A;
                    conta++;
                }
            }
            printf("La media e' pari a %f",(float)somma/conta);
            break;
        case 'j':
            //algoritmo calcolo numeri perfetti
            printf("Numeri perfetti\nInserisci il numero di numeri perfetti da visualizzare\n");
            scanf("%d",&A);
            B=1;
            while(A<=0){
                printf("Il valore deve essere maggiore di 0\n");
                scanf("%d",&A);
            }
            while(contatore<A){
                while(B<num){
                    if(Resto(num,B)==0){
                        somma=somma+B;
                    }
                    B++;
                }
                if(somma==num){
                    printf("%d e' un numero perfetto\n",num);
                    contatore++;
                }
                somma=0;
                B=1;
                num++;
            }
            break;
        case 'k':
            //algoritmo unione cifre
            printf("Unione cifre\nPremere 0 per uscire\n");
            scanf("%d",&A);
            while(A!=0){
                if(A>0){
                    B=Numero_Cifre(A);
                    for(;B>0;B--){
                        somma=somma*10;
                    }
                    somma=somma+A;
                }else{
                    printf("Il valore %d non verra' accettato\n",A);
                }
                scanf("%d",&A);
            }
            printf("%d",somma);
            break;
        case 'l':
            //algoritmo esecuzione tabella pitagorica in un intervallo di 2 valori
            printf("Tabella pitagorica da 0 a 10 di un intervallo tra 2 valori\nInserisci il valore iniziale\n");
            scanf("%d",&A);
            printf("Inserisci il valore finale\n");
            scanf("%d",&B);
            if(A>B){
                for(;B<=A;B++){
                    printf("Tabella del %d\n",A);
                    for(conta=0;conta<=10;conta++){
                        printf("%d\n",Prodotto(B,conta));
                    }
                }
            }else if(A<B){
                for(;A<=B;A++){
                    printf("Tabella del %d\n",A);
                    for(conta=0;conta<=10;conta++){
                        printf("%d\n",Prodotto(A,conta));
                    }
                }
            }else{
                printf("Tabella del %d\n",A);
                for(conta=0;conta<=10;conta++){
                    printf("%d\n",Prodotto(A,conta));
                }
            }
            break;
        case 'm':
            printf("Visione cifre di un valore\nInserisci il valore\n");
            scanf("%d",&A);
            Stampa_Valori(A);
            break;
        case 'n':
            printf("Programma calcolo quadrati perfetti\nInserisci il valore iniziale\n");
            scanf("%d",&A);
            printf("Inserisci il valore finale\n");
            scanf("%d",&B);
            if(A>B){
                Copia_Funzione=A;
                A=B;
                B=Copia_Funzione;
            }
            Stampa_radici(A,B);
            break;
        default:
            //case default per segnalare all'utente l'inserimento di un carattere non esistente all'interno dei case
            printf("Hai sbagliato a digitare il valore, quello digitato non e' all'interno dell'elenco\nValore digitato ");
            putchar(Alex);
    }
    return 0;
}
