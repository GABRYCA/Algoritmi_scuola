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
                    "\n3 -> Pag.101 Libro.\n");

            printf("Scelta: ");
            valoreScelto = getScanner().nextInt();

            switch (valoreScelto){

                case 0:{

                    printfn("Hai scelto: Esci...");
                    printfn("Chiudendo il menu!");

                    break;
                }
                case 1:{

                    new Moltiplicazione().moltiplicazione();

                    continua();

                    break;
                }
                case 2:{

                    new Divisione().divisione();

                    continua();

                    break;
                }
                case 3:{

                    new Primo().altPerArRet();

                    break;
                }
            }
        }
        printfn("Menu chiuso con successo!");
    }
}
