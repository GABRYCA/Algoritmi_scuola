package me.gca;

public class Main {

    public static void main(String[] args) {

        Util.printf("\nListe di G.C. 4BITI...");

        int scelta;
        Lista lista = new Lista();
        do {

            Util.printf("\n\nOpzioni:" +
                    "\n0 -> Esci." +
                    "\n1 -> Inserisci" +
                    "\n2 -> Rimuovi" +
                    "\n3 -> Cerca" +
                    "\n4 -> Lettura logica." +
                    "\nScelta: ");
            scelta = Util.getScanner().nextInt();

            switch (scelta){

                case 0:{

                    Util.printf("\nHai scelto: Esci...");

                    break;
                }

                case 1:{

                    Util.printf("\nHai scelto: Inserisci...");

                    String nome;
                    Util.printf("\nInserisci il nome: ");
                    nome = Util.getScanner().nextLine();

                    lista.inserisci(nome);

                    Util.continua();
                    break;
                }

                case 2:{

                    Util.printf("\nHai scelto: Rimuovi...");

                    String nome;
                    Util.printf("\nInserisci il nome: ");
                    nome = Util.getScanner().nextLine();

                    lista.rimuovi(nome);

                    Util.continua();
                    break;
                }


                case 3:{

                    Util.printf("\nHai scelto: Cerca...");

                    String nome;
                    Util.printf("\nInserisci il nome: ");
                    nome = Util.getScanner().nextLine();

                    lista.cerca(nome);

                    Util.continua();
                    break;
                }

                case 4:{

                    Util.printf("\nHai scelto: Lettura logica...");

                    lista.visualizza();

                    Util.continua();
                    break;
                }

                default:{

                    Util.printf("\nScelta non valida, per favore riprovare!");

                    break;
                }
            }

        } while (scelta != 0);
        Util.printf("\nUscito con successo!");
    }
}
