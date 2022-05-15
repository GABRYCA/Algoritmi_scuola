public class Main {

    public static boolean finestraAperta = false;

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
                    "\n4 -> Calcolatrice 1." +
                    "\n5 -> Calcolatrice 2." +
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
                case 4: {
                    Util.printfn("\nCalcolatrice 1...");
                    Calcolatrice calcolatrice = new Calcolatrice();
                    break;
                }
                case 5: {
                    Util.printfn("\nCalcolatrice 2 e WindowListener...");
                    Calcolatrice2 calcolatrice2 = new Calcolatrice2();
                    finestraAperta = true;
                    while (finestraAperta) {
                        try {
                            Thread.sleep(1000);
                        }
                        catch (InterruptedException ignored) {
                        }
                    }
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