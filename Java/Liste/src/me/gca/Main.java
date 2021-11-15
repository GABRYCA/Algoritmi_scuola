package me.gca;

public class Main {

    public static void main(String[] args) {

        // Messaggio di benvenuto.
        Util.printf("\nListe di G.C. 4BITI...");

        // Variabile scelta e inizializzazione lista.
        int scelta;
        Lista lista = new Lista();
        do {

            // Opzioni disponibili e input scelta utente.
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

                    // Messaggio.
                    Util.printf("\nHai scelto: Esci...");

                    break;
                }

                case 1:{

                    // Messaggio d'inizio.
                    Util.printf("\nHai scelto: Inserisci...");

                    // Chiedo variabile.
                    String nome;
                    Util.printf("\nInserisci il nome: ");
                    nome = Util.getScanner().nextLine();

                    // Richiamo metodo.
                    lista.inserisci(nome);

                    // Pausa e fine.
                    Util.continua();
                    break;
                }

                case 2:{

                    // Messaggio d'inizio.
                    Util.printf("\nHai scelto: Rimuovi...");

                    // Richiedo variabile.
                    String nome;
                    Util.printf("\nInserisci il nome: ");
                    nome = Util.getScanner().nextLine();

                    // Richiamo metodo.
                    lista.rimuovi(nome);

                    // Pausa e fine.
                    Util.continua();
                    break;
                }


                case 3:{

                    // Messaggio d'inizio.
                    Util.printf("\nHai scelto: Cerca...");

                    // Richiedo variabile.
                    String nome;
                    Util.printf("\nInserisci il nome: ");
                    nome = Util.getScanner().nextLine();

                    // Richiamo metodo.
                    lista.cerca(nome);

                    // Pausa e fine.
                    Util.continua();
                    break;
                }

                case 4:{

                    // Messaggio d'inizio.
                    Util.printf("\nHai scelto: Lettura logica...");

                    // Richiamo metodo.
                    lista.visualizza();

                    // Pausa e fine.
                    Util.continua();
                    break;
                }

                default:{

                    // Comunico l'errore all'utente.
                    Util.printf("\nScelta non valida, per favore riprovare!");

                    break;
                }
            }

        } while (scelta != 0);

        // Messaggio di chiusura.
        Util.printf("\nUscito con successo!");
    }
}
