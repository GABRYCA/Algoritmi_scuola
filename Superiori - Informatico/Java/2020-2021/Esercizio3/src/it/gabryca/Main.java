package it.gabryca;

public class Main extends Util {

    public static void main(String[] args) {

        int valoreScelto = 1;

        // Messaggio d'inizio.
        printfn("/////////////////////////////////////////////////////////////////");
        printfn("/       Alunno: Gabriele Caretti, Esercizio 3 (Frazioni)        /");
        printfn("/////////////////////////////////////////////////////////////////");

        Frazione frazione = new Frazione();

        while(valoreScelto != 0){


            printf("\nScegliere tra una delle seguenti opzioni:" +
                    "\n0 -> Esci." +
                    "\n1 -> Assegna valore frazioni.");
            if (frazione.getNumeratore(1) != 0){
                printf("\n2 -> Somma frazione 1 e frazione 2." +
                        "\n3 -> Sottrazione frazione 1 e frazione 2." +
                        "\n4 -> Moltiplicazione frazione 1 e frazione 2." +
                        "\n5 -> Divisione frazione 1 e frazione 2." +
                        "\n6 -> Riassegna valore frazione 1." +
                        "\n7 -> Riassegna valore frazione 2." +
                        "\n10 -> Riduci frazione.");
            }
            if (frazione.getNumeratore(3) != 0){
                printf("\n8 -> Dai stesso valore del risultato a frazione 1." +
                        "\n9 -> Dai stesso valore del risultato a frazione 2." +
                        "\n10 -> Vedi risultato frazione 3.");
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

                    continua();
                    break;
                }

                case 2:{

                    printfn("\nHai scelto: somma frazione 1 con frazione 2...");

                    frazione.somma();
                    printfn("\nSomma effettuata con successo!");

                    continua();
                    break;
                }

                case 3:{

                    printfn("\nHai scelto: sottrazione frazione 1 con frazione 2...");

                    frazione.sottrai();
                    printfn("\nSottrazione effettuata con successo!");

                    continua();
                    break;
                }

                case 4:{

                    printfn("\nHai scelto: moltiplicazione frazione 1 con frazione 2...");

                    frazione.moltiplica();
                    printfn("\nMoltiplicazione effettuata con successo!");

                    continua();
                    break;
                }

                case 5:{

                    printfn("\nHai scelto: divisione frazione 1 con frazione 2...");

                    frazione.dividi();
                    printfn("\nDivisione effettuata con successo!");

                    continua();
                    break;
                }

                case 6:{

                    printfn("\nHai scelto: assegna nuovo valore frazione 1...");
                    printf("\nInserire un valore per la frazione 1 (formato a/b, esempio 1/2): ");

                    frazione.setFrazione1(getScanner().next());
                    printfn("\nValore assegnato con successo...");

                    continua();
                    break;
                }

                case 7:{

                    printfn("\nHai scelto: assegna nuovo valore frazione 2...");
                    printf("\nInserire un valore per la frazione 2 (formato a/b, esempio 1/2): ");

                    frazione.setFrazione2(getScanner().next());
                    printfn("\nValore assegnato con successo...");

                    continua();
                    break;
                }

                case 8:{

                    printfn("\nHai scelto: dare valore del risultato alla frazione 1...");

                    frazione.setFrazione1(frazione.stampa(3));

                    printfn("\nValore assegnato con successo a frazione 1!");

                    continua();
                    break;
                }

                case 9:{

                    printfn("\nHai scelto: dare valore del risultato alla frazione 2...");

                    frazione.setFrazione1(frazione.stampa(3));

                    printfn("\nValore assegnato con successo a frazione 2!");

                    continua();
                    break;
                }

                case 10:{

                    printfn("\nHai scelto: vedi valore risultato...");

                    printfn("\nIl valore è " + frazione.stampa(3));

                    continua();
                    break;
                }

                case 11:{

                    printfn("\nHai scelto: riduci frazione...");

                    printf("\nQuale frazione vuoi ridurre (1,2 o 3): ");
                    frazione.riduci(getScanner().nextInt());

                    printfn("\nFrazione ridotta con successo!");

                }

                default:{

                    printfn("\nHai scelto un valore non valido, per favore riprova...");

                    continua();
                    break;
                }

            }

        }
    }
}
