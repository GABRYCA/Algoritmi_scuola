#include <iostream>
#include <stdio.h>
int moltiplicazione(int a, int b);
int main(){
    int a,b,c;
    printf("inserire una lettera tra quelle predisposte per far partire un algoritmo\n");

    printf("1 moltiplicazione\n");
    printf("2 divisione\n");
    printf("3 numero pari e dispari7\n");
    printf("4 verifica interezza numero\n");
    printf("5 tabellina tra due numeri\n");
    printf("6 mcd\n");
    printf("7 numeri reali\n");
    printf("8 media\n");
    printf("9 visualizzare numero cifre\n");
    printf("10 ricostruire numero partendo dall' ultima cifra\n");
    printf("11 potenza\n");
    printf("12 numero cifre\n");
    printf("13 numero max e min\n");
    printf("14 radice\n");
    scanf("%d",&a);
    switch(a){

        case 1 :{
            printf("algortimo per il calcolo della moltiplicazione\n");
            printf("inserisci il primo fattore\n");
            scanf("%d",&b);
            printf("inserisci il secondo fattore\n");
            scanf("%d",&c);
            printf("il risultato della moltilplicazione è: %d\n",moltiplicazione(b,c));
            break;
        }
        case 2:{
        }
        case 3:{
        }
        case 4:{
        }
        case 5:{
        }
        case 6:{
        }
        case 7:{
        }
        case 8:{
        }
        case 9:{
        }
        case 10:{
        }
        case 11:{
        }
        case 12:{
        }
        case 13:{
        }
        case 14:{
        }
    }

    return 0;
}
int moltiplicazione (int a, int b){
    int prodotto=0 ;
    for (int conta = 0; conta == b ; ++conta) {
        prodotto=prodotto+a;

    }
    return prodotto;
}
