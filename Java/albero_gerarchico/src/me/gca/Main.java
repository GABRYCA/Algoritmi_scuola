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
                    "\n4 -> Elimina utente." +
                    "\n5 -> Visualizza nodi inferiori a un certo nome." +
                    "\n6 -> Visualizza nodi superiori a un certo nome." +
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

                case 2:{

                    Util.printfn("\nHai scelto: Cerca utente...");

                    if (albero.numeroUtenti() <= 0){
                        Util.printfn("\nNon sono disponibili utenti!");
                        break;
                    }

                    String nomeUtente;
                    Util.printf("\nNome utente da cercare: ");
                    nomeUtente = Util.getScanner().nextLine();

                    int posUtente = albero.cercaUtente(nomeUtente);
                    if (posUtente != -1){
                        Util.printfn("\nUtente " + nomeUtente + " trovato in posizione " + posUtente + ".");
                    }

                    Util.continua();
                    break;
                }

                case 3:{

                    Util.printfn("\nHai scelto: Visualizza vettore grezzo...");

                    albero.visualizzaVettoreGrezzo();

                    Util.continua();
                    break;
                }

                case 4:{

                    Util.printfn("\nHai scelto: Elimina utente...");

                    if (albero.numeroUtenti() <= 0){
                        Util.printfn("\nNon sono disponibili utenti!");
                        Util.continua();
                        break;
                    }

                    String nomeUtente;
                    Util.printf("\nNome utente da eliminare: ");
                    nomeUtente = Util.getScanner().nextLine();

                   albero.eliminaUtente(nomeUtente);

                   Util.continua();
                   break;
                }

                case 5:{

                    Util.printfn("\nHai scelto: Visualizza nodi inferiori ad un certo utente...");

                    if (albero.numeroUtenti() <= 0){
                        Util.printfn("\nNon sono disponibili utenti!");
                        Util.continua();
                        break;
                    }

                    String nomeUtente;
                    Util.printf("\nNome utente interessato: ");
                    nomeUtente = Util.getScanner().nextLine();

                    albero.visualizzaInferiori(nomeUtente);

                    Util.continua();
                    break;
                }

                case 6:{

                    Util.printfn("\nHai scelto: Visualizza nodi superiori ad un certo utente...");

                    if (albero.numeroUtenti() <= 0){
                        Util.printfn("\nNon sono disponibili utenti!");
                        Util.continua();
                        break;
                    }

                    String nomeUtente;
                    Util.printf("\nNome utente interessato: ");
                    nomeUtente = Util.getScanner().nextLine();

                    albero.visualizzaSuperiori(nomeUtente);

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
