package me.gca;

public class Main {

    public static void main(String[] args) {

        int scelta = 0;
        do {
            Util.printf("\nScelte: " +
                    "\n0 -> Esci." +
                    "\n1 -> Lancia moneta." +
                    "\n2 -> Gioca." +
                    "\nScelta: ");
            scelta = Util.getScanner().nextInt();

            switch (scelta){

                case 0: {

                    Util.printfn("\nHai scelto: Esci...");

                    break;
                }

                case 1: {

                    Util.printfn("\nHai scelto: Lancia moneta...");

                    Moneta moneta = new Moneta();
                    System.out.println(moneta);

                    Util.continua();
                    break;
                }

                case 2:{

                    Util.printfn("\nHai scelto: Gioca...");

                    int sceltaGiocatore = 0;
                    int lanciTesta = 0;
                    Util.printfn("\nGioco del testa o croce - 5 lanci.");
                    Util.printf("Scegli testa (0) oppure croce (1):");
                    sceltaGiocatore = Util.getScanner().nextInt();

                    Moneta moneta = new Moneta();
                    for (int i = 0; i < 5; i++){
                        moneta.lancia();
                        System.out.println(moneta.toString());
                        if (moneta.isTesta()){
                            lanciTesta++;
                        }
                    }
                    if (sceltaGiocatore == 0 && lanciTesta > 2){
                        Util.printfn(" -> Hai vinto !");
                    } else {
                        Util.printfn(" -> Ha vinto il PC!");
                    }

                    Util.continua();
                    break;
                }

                default:{

                    Util.printfn("Scelta non valida, per favore riprovare.");

                    Util.continua();
                    break;
                }

            }

        } while (scelta != 0);

        Util.printf("Uscito con successo!");


    }
}
