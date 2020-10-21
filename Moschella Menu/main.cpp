#include <iostream>
#include <stdio.h>
int moltiplicazione(int a, int b);
int divisione (int a, int b);
int pari(int a);
float interezza(float a);
int mcd(int a, int b);
int numperfetti(int a, int b);
int media(int a);
int cifre(int a);
int cifre2(int a);
int potenza(int a,int b);
int numcifre(int a);
int maxemin(int a,int b);
int radice(int a);
int main() {
    int a, b, c;
    printf("inserire una lettera tra quelle predisposte per far partire un algoritmo\n");
    printf("1 moltiplicazione\n");
    printf("2 divisione\n");
    printf("3 numero pari e dispari7\n");
    printf("4 verifica interezza numero\n");
    printf("5 tabellina tra due numeri\n");
    printf("6 mcd\n");
    printf("7 numeri perfetti\n");
    printf("8 media\n");
    printf("9 visualizzare numero cifre\n");
    printf("10 ricostruire numero partendo dall' ultima cifra\n");
    printf("11 potenza\n");
    printf("12 numero cifre\n");
    printf("13 numero max e min\n");
    printf("14 radice\n");
    scanf("%d", &a);
    switch (a) {

        case 1 : {
            printf("algortimo per il calcolo della moltiplicazione\n");
            printf("inserisci il primo fattore\n");
            scanf("%d", &b);
            printf("inserisci il secondo fattore\n");
            scanf("%d", &c);
            printf("il risultato della moltilplicazione è: %d\n", moltiplicazione(b, c));
            break;
        }
        case 2: {
            printf("algoritmo per il calcolo della divisione\n");
            printf("inserisci il dividendo\n");
            scanf("%d", &b);
            printf("inserisci il divisore\n");
            scanf("%d", &c);
            printf("il risultato della divisione tra i due numeri inseriti è: %d\n", divisione(b, c));
            break;
        }
        case 3: {
            printf("algortimo per il calcolo del numero pari\n");
            printf("inserisci un numero\n");
            scanf("%d", &b);
            if (pari(b) == 0) {
                printf("il tuo numero è pari ");
            } else {
                printf("il tuo numero è dispari");
            }

            break;
        }
        case 4: {
            float decimale;
            printf("algortimo calcolo numero intero\n");
            printf("inserisci un numero\n");
            scanf("%f", &decimale);
            if (interezza(a) == 0) {
                printf("il tuo numero inserito è intero\n");
            } else {
                printf("il tuo numero inserito è decimale\n");


            }
            break;
        }
        case 5: {
            printf("algortimo per la tavola pittagorica\n");
            printf("inserisci il primo valore\n");
            scanf("%d", &a);
            printf("inserisci il secondo valore\n");
            scanf("%d", &b);
            while (a <= b) {
                printf("la tabellina del numero %d\n:", a);
                for (int conta = 0; conta <= 10; conta++) {
                    printf("\n%d", moltiplicazione(a, conta));
                }
                a++;
            }
            break;
        }
        case 6: {
            printf("algoritmo per il calcolo del mcd\n");
            printf("inserisci un valore a tua scelta\n");
            scanf("%d", &a);
            printf("inserisci il secondo valore a tua scelta\n");
            scanf("%d", &b);
            printf("l mcd tra i due valori inseriti è: %d\n", mcd(a, b));
            break;
        }
        case 7: {
            printf("alogortimo per il calcolo dei numeri perfetti");
            printf("inserisci il primo valore\n");
            scanf("%d", &a);
            printf("inserisci il secondo valore\n");
            scanf("%d", &b);
            printf("il tuo numero reale tra i due valori inseriti è:%d\n", numperfetti(a, b));
            break;
        }
        case 8: {
            printf("algoritmo per il calcolo della media del numero inserito\n");
            printf("inserisci il valore per il calcolo della media\n");
            scanf("%d", &a);
            printf("la media del numero inserito è:%d", media(a));
            break;
        }
        case 9: {
            printf("algortimo per il calcolo del numero di cifre\n");
            printf("inserisci un numero\n");
            scanf("%d", &a);
            printf("il numero di cifre del tuo numero inserito è:%d\n", cifre(a));
            break;
        }
        case 10: {
            printf("algoritmo creato per ricostruire una cifra partendo dall ultima\n");
            printf("inserisci un numero\n");
            scanf("%d", &a);
            printf("la cifra ricostruita è: %d\n", cifre2(a));
            break;
        }
        case 11: {
            printf("algortimo per il calcolo dell elevamento a potenza tra due numeri\n");
            printf("inserisci il primo valore\n");
            scanf("%d", &a);
            printf("inserisci il secondo valore\n");
            scanf("%d", &b);
            printf("l elevamento a potenza effettuato è: %d\n", potenza(a, b));
            break;

        }
        case 12: {
            printf("algoritmo per il calcolo del numero di cifre\n");
            printf("inserisci un valore a tua scelta\n");
            scanf("%d", &a);
            printf("il numero della cifra insertita è: %d\n", numcifre(a));
            break;
        }
        case 13: {
            printf("algoritmo creato per il calcolo del numero massimo e minimo tra piu valori inseriti\n");
            printf("inserisci il primo numero\n");
            scanf("%d", &a);
            printf("inserisci il secondo numero\n");
            scanf("%d", &b);
            if (maxemin (a>b)){
                printf("il numero è il maggiore\n");
            }
            else{
                printf("il numero è il minore");
            }
            break;
        }
        case 14: {
            printf("algoritmo per il calcolo della radice di un numero inserito\n");
            printf("inserisci un numero sotto radice");
            scanf("%d", &a);
            printf("la radice del numero inserito è:%d", radice(a));
            break;
        }


            return 0;
    }
}
int moltiplicazione(int a, int b) {
    int prodotto = 0;
    for (int conta = 1; conta <= b; ++conta) {
        prodotto = prodotto + a;
    }
    return prodotto;
}
int divisione(int a, int b) {
    int conta = 0;
    for (; a >= b; ++conta) {
        a = a - b;
    }
    return conta;
}
int pari(int a) {
    for (; a >= 2; a = a - 2) {
    }
    return a;
}

int mcd(int a, int b) {
    int resto;
    while (b > 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}
int potenza(int a, int b){
    for(;a>b;b=a*a);
    return a;
}
int numcifre(int a, int b){
    for(int conta=0;a>0 );

}
int radice(int a, int b){
    for(int radice=a;radice>b)
}