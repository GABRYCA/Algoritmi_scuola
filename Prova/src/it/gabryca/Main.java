package it.gabryca;

public class Main extends Util {

    public static void main(String[] args) {

        int valoreScelto = 1;

        System.out.println("Benvenuto nel menu in Java di Gabriele Caretti!");

        while(valoreScelto != 0) {

            System.out.println("\nLegenda: " +
                    "\n0 -> Esci." +
                    "\n1 -> Moltiplicazione. " +
                    "\n2 -> Divisione.\n");

            System.out.print("Scelta: ");
            valoreScelto = getScanner().nextInt();

            switch (valoreScelto){

                case 0:{

                    System.out.println("Hai scelto: Esci...");
                    System.out.println("Chiudendo il menu!");

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
            }
        }
        System.out.println("Menu chiuso con successo!");
    }
}
