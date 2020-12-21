package it.gabryca;

public class Main extends Util {

    public static void main(String[] args) {

        int valoreScelto = 1;

        // Messaggio d'inizio.
        printfn("/////////////////////////////////////////////////////////////////");
        printfn("/       Alunno: Gabriele Caretti, Esercizio 3 (Frazioni)        /");
        printfn("/////////////////////////////////////////////////////////////////");

        while(valoreScelto != 0){

            Frazione frazione = new Frazione();

            printf("\nScegliere tra una delle seguenti opzioni:" +
                    "\n 0 -> Esci." +
                    "\n 1 -> Assegna valore frazioni.");
            if (frazione.getNumeratore(1) != 0){
                printf("\n2 -> Somma frazione 1 e frazione 2." +
                        "\n3 -> Sottrazione frazione 1 e frazione 2." +
                        "\n4 -> Moltiplicazione frazione 1 e frazione 2." +
                        "\n5 -> Divisione frazione 1 e frazione 2." +
                        "\n6 -> Riassegna valore frazione 1." +
                        "\n7 -> Riassegna valore frazione 2.");
            }
            if (frazione.getNumeratore(3) != 0){
                printf("\n8 -> Assegna valore frazione 3 (risultato) a frazione 1." +
                        "\n9 -> Assegna valore frazione 3 (risultato) a frazione 2.");
            }
            printf("\nValore scelto: ");
            valoreScelto = getScanner().nextInt();

            switch (valoreScelto){

                case 0:{

                    printfn("\nHai scelto: esci..." +
                            "\n\nChiusura in corso!");

                    break;
                }

                case 1:{

                    printf("\nHai scelto: assegna valori a frazione 1 e 2..." +
                            "\n\n Inserire un valore per frazione 1 (formato a/b, esempio 1/2): ");

                    frazione.setFrazione1(getScanner().next());
                    printfn("\nValore frazione 1 assegnato con successo!");

                    printf("\nInserire un valore per frazione 2 (formato a/b, esempio 1/2): ");
                    frazione.setFrazione2(getScanner().next());
                    printfn("\nValore frazione 2 assegnato con successo!");

                    break;
                }

                case 2:{

                    printfn("\nHai scelto: somma frazione 1 con frazione 2...");

                    frazione.somma();
                    printfn("\nSomma effettuata con successo!");

                    break;
                }

                case 3:{

                    printfn("\nHai scelto: sottrazione frazione 1 con frazione 2...");

                    frazione.sottrai();
                    printfn("\nSottrazione effettuata con successo!");

                    break;
                }

                case 4:{


                    break;
                }

                case 5:{


                    break;
                }

                case 6:{


                    break;
                }

                case 7:{


                    break;
                }

                case 8:{


                    break;
                }

                case 9:{


                    break;
                }

                default:{

                    printfn("\nHai scelto un valore non valido, per favore riprova...");

                    break;
                }

            }

        }
    }
}
