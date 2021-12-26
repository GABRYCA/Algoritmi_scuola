package me.gca;

public class Main {

    public static void main(String[] args) {

        // Messaggio di benvenuto.
        Util.printfn("\n/////////////////////////////////////" +
                "\n// Compito vector di G.C. 4BITI //" +
                "\n/////////////////////////////////////");

        Albero albero = new Albero();
        int scelta;
        do{

            Util.printf("\nOpzioni: " +
                    "\n0 -> Esci." +
                    "\n1 -> Aggiungi utente." +
                    "\n2 -> Cerca utente." +
                    "\n3 -> Visualizza vettore grezzo." +
                    "\nScelta: ");
            scelta = Util.getScanner().nextInt();

            switch (scelta){

                case 0:{
                    Util.printfn("\nHai scelto: Esci..." +
                            "\n\nUscita in corso...");
                    break;
                }
                case 1:{
                    Util.printfn("\nHai scelto: Aggiungi utente...");

                    String nomeUtente;
                    String nomePadre = "null";
                    Util.printf("\nNome Utente: ");
                    nomeUtente = Util.getScanner().nextLine();
                    if (albero.numeroUtenti() > 0){
                        Util.printf("\nQuando richiesto il nome del padre, inserire 'null' se non si vuole" +
                                "\nassegnare un padre all'utente, oppure inserire un nome valido per impostare un padre." +
                                "\nATTENZIONE! Se si inserisce un nome padre non valido, l'utente non sarà aggiunto!" +
                                "\n\nNome padre: ");
                        nomePadre = Util.getScanner().nextLine();
                    }

                    if (!nomePadre.equalsIgnoreCase("null")){
                        albero.aggiungiUtente(nomePadre, nomeUtente);
                    } else {
                        albero.aggiungiUtente(null, nomeUtente);
                    }

                    Util.continua();
                    break;
                }

                default:{

                    Util.printfn("\nOpzione non valida, per favore riprovare!");

                    break;
                }
            }

        } while (scelta != 0);

        Util.printfn("\nUscito con successo!");
    }
}
