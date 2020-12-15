package it.gabryca;

public class Main extends Util {

    public static void main(String[] args) {

        // Dichiaro variabile
        int valoreScelto = 1;

        // Messaggio di Benvenuto
        printfn("Benvenuto nel menu in Java di Gabriele Caretti!");

        // Inizia il ciclo del menu
        while(valoreScelto != 0) {

            // Legenda
            printfn("\nLegenda: " +
                    "\n0 -> Esci." +
                    "\n1 -> Moltiplicazione. " +
                    "\n2 -> Divisione." +
                    "\n3 -> Pag.101 Libro." +
                    "\n4 -> Elevamento a potenza." +
                    "\n5 -> Pari o dispari." +
                    "\n6 -> Tabellina compresa tra 2 numeri." +
                    "\n7 -> M.C.D.\n");

            // Richiedo input
            printf("Scelta: ");
            valoreScelto = getScanner().nextInt();

            // Switch tra i vari metodi del menu
            switch (valoreScelto){

                case 0:{

                    // Messaggi d'uscita
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

                    // Richiamo metodo
                    new PariODispari().pariDispari();
                    continua();

                    break;
                }

                case 6:{

                    // Richiamo funzione
                    new TabellinaNumeriInterv().TabellinaNumeriAlg();
                    continua();

                    break;
                }
                case 7:{

                    // Richiamo funzione
                    new MCD().MCDAlg();
                    continua();

                    break;
                }

                default:{

                    // Messaggio di default in caso di valore inserito non valido
                    printfn("Hai inserito un valore non valido, riprovare!");
                    continua();

                    break;
                }
            }
        }
        // Uscito con successo!
        printfn("Menu chiuso con successo!");
    }
}
