public class Main {

    public static void main(String[] args) {

        // Scrivo messaggio di benvenuto.
        Util.printfn("""
                ////////////////////////////////////////
                                 JFrame                \s
                ////////////////////////////////////////""");

        int scelta;
        do {

            // Stampo menu.
            Util.printf("\nOpzioni:" +
                    "\n0 -> Esci." +
                    "\n1 -> Frame 1 Somma." +
                    "\n2 -> Frame 2 Divisione." +
                    "\n3 -> Frame 3 Moltiplicazione." +
                    "\n4 -> Tutto in uno." +
                    "\nScelta: ");
            scelta = Util.getScanner().nextInt();

            switch (scelta) {
                case 0: {
                    Util.printfn("\nEsci.");
                    break;
                }
                case 1: {
                    Util.printfn("\nFrame 1 Somma...");
                    SommaFrame somma = new SommaFrame();
                    break;
                }
                case 2: {
                    Util.printfn("\nFrame 2 Divisione...");
                    DivisioneFrame divisione = new DivisioneFrame();
                    break;
                }
                case 3: {
                    Util.printfn("\nFrame 3 Moltiplicazione...");
                    MoltiplicazioneFrame moltiplicazione = new MoltiplicazioneFrame();
                    break;
                }
                default: {
                    Util.printfn("\nOpzione non valida.");
                    break;
                }
            }

        } while (scelta != 0);
        Util.printfn("\nChiuso il programma con successo!");
    }
}