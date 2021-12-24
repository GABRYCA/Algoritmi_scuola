package me.gca;

public class Main {

    public static void main(String[] args) {

        // Messaggio di benvenuto.
        Util.printfn("\n/////////////////////////////////////" +
                "\n// Compito vector di G.C. 4BITI //" +
                "\n/////////////////////////////////////");

        int numeroGiocate;
        Util.printf("\nInserire numero giocate: ");
        numeroGiocate = Util.getScanner().nextInt();

        Util.printfn("\nIl gioco consiste in una sfida da 3 manche di giocatore vs computer." +
                "\nChi vince 2 partite su 3 ad ogni manche, vince." +
                "\nChi vince il maggior numero di manche, vince il gioco.");

        int vittorieFinComputer = 0;
        int vittorieFinGiocatore = 0;
        for (int i = 0; i < numeroGiocate; i++){
            Util.printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||" +
                    "\nRound " + (i + 1) + ":");
            int vittoriecomputer = 0;
            int vittoreGiocatore = 0;
            
            // Manche:
            for (int j = 0; j < 3; j++){
                Util.printf("\n-------------------------");
                // Dado1 del giocatore.
                Dado dado1 = new Dado();
                // Dado2 del computer.
                Dado dado2 = new Dado();
                
                Util.printf("\nIl giocatore sta lanciando i dadi..." +
                        "\nDado 1: " + dado1.getNumero() + ".");
                int sommaGiocatore = dado1.getNumero() + dado1.lanciaDadi();
                Util.printf("\nDado 2: " + dado1.getNumero() +
                        "\nIl giocatore ha fatto un totale di " + sommaGiocatore + "!");
                
                
                Util.printf("\nIl computer sta lanciando i dadi..." + 
                        "\nDado 1: " + dado2.getNumero() + ".");
                int sommaComputer = dado2.getNumero() + dado2.lanciaDadi();
                Util.printf("\nDado 2: " + dado2.getNumero() +
                        "\nIl computer ha fatto un totale di " + sommaComputer + "!");
                
                if (sommaGiocatore == sommaComputer){
                    Util.printfn("\nIl computer e il giocatore in questa manche hanno fatto entrambi " + sommaGiocatore + " punti " +
                            "\nquindi sono in pareggio!");
                } else if (sommaGiocatore > sommaComputer){
                    Util.printfn("\nIl giocatore ha fatto " + sommaGiocatore + " punti mentre il computer " + sommaComputer + "..." +
                            "\nVince il giocatore la manche!" +
                            "\n-------------------------");
                    vittoreGiocatore++;
                } else {
                    Util.printfn("\nIl computer ha fatto " + sommaComputer + " punti mentre il computer " + sommaGiocatore + "..." +
                            "\nVince il computer la manche!" +
                            "\n-------------------------");
                    vittoriecomputer++;
                }
            }
            
            if (vittoriecomputer == vittoreGiocatore){
                Util.printfn("\nPareggio!");
            } else if (vittoreGiocatore > vittoriecomputer){
                Util.printfn("\nHa vinto il giocatore!" +
                        "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                vittorieFinGiocatore++;
            } else {
                Util.printfn("\nHa vinto il computer!" +
                        "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                vittorieFinComputer++;
            }
        }
        
        Util.printf("\nEsito finale delle giocate: ");
        if (vittorieFinComputer == vittorieFinGiocatore){
            Util.printfn("\nPareggio!");
        } else if (vittorieFinGiocatore > vittorieFinComputer){
            Util.printfn("\nHa vinto il giocare con " + vittorieFinGiocatore + " vittore e il computer invece solamente " + vittorieFinComputer + "!");
        } else {
            Util.printfn("\nHa vinto il computer con " + vittorieFinComputer + " vittore e il giocatore invece solamente " + vittorieFinGiocatore + "!");
        }
        
        
    }
}
