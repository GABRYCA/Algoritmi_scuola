package it.gabryca;

public class Main extends Util {

    public static void main(String[] args) {

        int valoreScelto = 1;

        printfn("Benvenuto nel menu in Java di Gabriele Caretti!");

        while(valoreScelto != 0) {

            printfn("\nLegenda: " +
                    "\n0 -> Esci." +
                    "\n1 -> Moltiplicazione. " +
                    "\n2 -> Divisione." +
                    "\n3 -> Pag.101 Libro." +
                    "\n4 -> Elevamento a potenza." +
                    "\n5 -> Pari o dispari.\n");

            printf("Scelta: ");
            valoreScelto = getScanner().nextInt();

            switch (valoreScelto){

                case 0:{

                    printfn("Hai scelto: Esci...");
                    printfn("Chiudendo il menu!");

                    break;
                }
                case 1:{

                    // Richiamo metodo
                    new Moltiplicazione().moltiplicazione();
                    continua();

                    break;
                }
                case 2:{

                    // Richiamo metodo
                    new Divisione().divisione();
                    continua();

                    break;
                }
                case 3:{

                    // Richiamo metodo
                    new Primo().altPerArRet();
                    continua();

                    break;
                }
                case 4:{

                    // Richiamo metodo
                    new ElevamentoPot().elevamentoAPot();
                    continua();

                    break;
                }
                case 5:{

                    continua();

                    break;
                }

                default:{

                    printfn("Hai inserito un valore non valido, riprovare!");
                    continua();

                    break;
                }
            }
        }
        printfn("Menu chiuso con successo!");
    }
}
