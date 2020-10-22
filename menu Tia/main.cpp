#include <stdio.h>
#include <iostream>
int main () {
    int caso, ris , a , b , c , cont ;

                    printf("digita numero per visualizzare l'algoritmo\n") ;

                    printf("1 moltiplicazione\n ") ;
                    printf("2 divisione\n") ;
                    printf("3 pari o dispari\n ") ;
                    printf("4 verifica se numero intero\n ") ;
                    printf("5 tabellina di tutti i numeri\n ") ;
                    printf("6 MCD\n ") ;
                    printf("7 numeri reali\n ") ;
                    printf("8 media\n ") ;
                    printf("9 cifre di un numero separate\n ") ;
                    printf("10 ricostruire il numero date le cifre\n") ;


                    printf("Il numero che hai inserito è: ");
                    scanf("%i",&caso);
                    while(caso!=0)
                     {
                         switch(caso){
                            
                            
                            case 1:

                                 printf("Hai scelto: moltiplicazione\n ");
                                 printf("Inserisci il primo numero: \n");
                                 scanf("%d",&a);
                                 printf("Inserisci il secondo numero: \n");
                                 scanf("%d",&b);
                                 ris=a*b;
                                 printf("Il prodotto è: %d\n",ris);

                                break;


                            case 2:

                                 printf("Hai scelto: divisione\n");
                                 printf("Inserisci il primo numero: ");
                                 scanf("%d",&a);
                                 printf("Inserisci il secondo numero: ");
                                 scanf("%d",&b);
                                 ris=a/b;
                                 printf("Il risultato è: %d\n",ris);
                                break;


                            case 3:

                                 printf("Hai scelto: pari o dispari\n");
                                 printf("Inserisci numero") ;
                                while(a > 2) ;
                                {
                                     a = a - 2
                                }
                                 if(a=0){
                             printf(" il numero è pari") ;
                        }
                        else{
                            printf("il numero è dispari") ;
                        }
                                break;


                            case 4:

                                 printf("Hai scelto: verifica se numero intero\n");
                                printf("inserisci numero: \n")
                                scanf("%d",&a);
                                while(a > 1)
                                {
                                    a = a - 1;
                                }
                                if(x=0){
                                    printf("il numero è intero\n");
                                }

                                else{
                                    printf("il numero è intero\n");
                                }

                                break;


                            case 5:

                                 printf("Hai scelto:tabellina di tutti i numeri\n");
                                printf("Inserisci un numero: \n")
                                scanf("%d",&a);
                                printf("Inserisci un altro numero: \n")
                                scanf("%d",&b);
                                while(>=b)
                                {
                                    cont = 1
                                    while(a>=b)
                                    {
                                        c = c + a
                                        cont = cont + 1
                                    }
                                    a = a + 1;
                                }

                                break;


                            case 6:

                                 printf("Hai scelto:MCD");
                                printf("inserisci un numero: \n");
                                scanf("%d",a);
                                printf("inserisci un altro numero: \n");
                                scanf("%d",b);
                                while(b > 0)
                                {
                                    resto = a % b;
                                    a = b
                                    b = resto
                                }
                                printf("L'M.C.D. è:%d",a)

                                break;


                            case 7:

                                 printf("Hai scelto:numeri reali");
                                printf("inserisci un numero: \n");
                                scanf("%d",a);
                                cont = a;
                                ris = 0;
                                while(cont = 0)
                                {
                                    if(a>cont){
                                        if(a = 0){
                                            ris = ris + cont
                                        }
                                        else{
                                        }
                                    }
                                    else{
                                        a = a -cont         //  DA FINIRE
                                    }
                                    cont = cont - 1

                                }

                                break;


                            case 8:

                                 printf("Hai scelto:media");

                                break;


                            case 9:

                                 printf("Hai scelto:cifre di un numero separate");
                                
                                break;


                            case 10:

                                 printf("Hai scelto:ricostruire il numero date le cifre");

                                break;


                        }
                    }
                    return 0;
                }