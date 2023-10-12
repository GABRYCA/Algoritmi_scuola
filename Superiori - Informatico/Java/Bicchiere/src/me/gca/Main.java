package me.gca;

public class Main {

    public static void main(String[] args) {

        // Messaggio di benvenuto.
        Util.printf("\n/////////////////////////////////////" +
                "\n// Compito Bicchiere di G.C. 4BITI //" +
                "\n/////////////////////////////////////");

        Bicchiere bicchiere = new Bicchiere();

        // Chiedo dati in input.
        Util.printf("\n\nCreazione del bicchiere..." +
                "\n\nInserire materiale: ");
        bicchiere.setMateriale(Util.getScanner().next());
        Util.printf("\nMateriale impostato con successo!" +
                "\n\nInserire forma: ");
        bicchiere.setForma(Util.getScanner().next());
        Util.printf("\nForma impostata con successo!");

        // Chiedo altri dati e poi creo il bicchiere.
        Util.printf("\nInserire capacita' (mL): ");
        bicchiere.setCapacita(Util.getScanner().nextFloat());
        Util.printf("\nCapacita' impostata con successo!");

        // Mi assicuro che l'utente inserisca un livello valido.
        do {
            Util.printf("\nInserire livello (0 (vuoto) <= capacita') (mL): ");
            bicchiere.setLivello(Util.getScanner().nextFloat());
            if (bicchiere.getLivello() < 0 || bicchiere.getLivello() > bicchiere.getCapacita()){
                Util.printf("\n\nLivello non valido, per favore riprovare!\n");
            }
        } while (bicchiere.getLivello() < 0 || bicchiere.getLivello() > bicchiere.getCapacita());

        // Riassunto bicchiere creato.
        Util.printf("\n\nBicchiere creato con successo, riepilogo bicchiere: " +
                "\nMateriale: " + bicchiere.getMateriale() +
                "\nForma: " + bicchiere.getForma() +
                "\nCapacita': " + bicchiere.getCapacita() + "mL." +
                "\nLivello: " + bicchiere.getLivello() + "mL.");

        // Menu.
        int scelta;
        do {
            Util.printf("\n\nOpzioni bicchiere: " +
                    "\n0 -> Esci." +
                    "\n1 -> Bevi." +
                    "\n2 -> Riempi." +
                    "\n3 -> Aggiungi una certa quantita'." +
                    "\n4 -> Svuota." +
                    "\n5 -> Informazioni bicchiere." +
                    "\nScelta: ");
            scelta = Util.getScanner().nextInt();

            switch (scelta) {
                case 0:{

                    Util.printf("\nHai scelto: Esci...\n" +
                            "\nUscita in corso!");

                    break;
                }
                case 1:{

                    Util.printf("\nHai scelto: Bevi...\n");

                    float livelloBicchiere = bicchiere.getLivello();

                    if (livelloBicchiere <= 0){
                        Util.printf("\n\nIl bicchiere e' vuoto, non puoi bere l'aria!");
                        Util.continua();
                        break;
                    }

                    // Chiedo all'utente quanto voglia bere.
                    float daBere;
                    Util.printf("\nQuanto vuoi bere? Il bicchiere ha " + livelloBicchiere + "mL:");
                    daBere = Util.getScanner().nextFloat();

                    if (livelloBicchiere < daBere){
                        Util.printf("\nHai inserito una quantita' troppo alta, il bicchiere non la contiene!");
                    } else {
                        bicchiere.setLivello(livelloBicchiere - daBere);
                        Util.printf("\nBevuto con successo " + daBere + "mL, rimangono " + bicchiere.getLivello() + "mL nel bicchiere!");
                    }

                    Util.continua();
                    break;
                }

                case 2:{

                    Util.printf("\nHai scelto: Riempi...\n");

                    float livelloBicchiere = bicchiere.getLivello();
                    if (livelloBicchiere == bicchiere.getCapacita()){
                        Util.printf("\nIl bicchiere e' gia' pieno, non puoi riempirlo di piu'!");
                        break;
                    }

                    float daRiempire = bicchiere.getCapacita() - livelloBicchiere;
                    bicchiere.setLivello(livelloBicchiere + daRiempire);
                    Util.printf("\nBicchiere riempito con successo! E' stato aggiunto " + daRiempire + ", ora contiene " + bicchiere.getLivello() + " ed e' pieno!");

                    Util.continua();
                    break;
                }

                case 3:{

                    Util.printf("\nHai scelto: Riempi di una certa quantita'...\n");

                    float livelloBicchiere = bicchiere.getLivello();
                    if (livelloBicchiere == bicchiere.getCapacita()){
                        Util.printf("\nIl bicchiere e' gia' pieno, non puoi riempirlo di piu'!");
                        break;
                    }

                    float daRiempire;
                    Util.printf("\n\nInserire quantita' da riempire: ");
                    daRiempire = Util.getScanner().nextFloat();

                    if (livelloBicchiere + daRiempire > bicchiere.getCapacita()){
                        Util.printf("\nHai inserito una quantita' troppo alta, il bicchiere e' troppo piccolo!");
                    } else {
                        bicchiere.setLivello(livelloBicchiere + daRiempire);
                        Util.printf("\nBicchiere riempito con successo! Ora contiene " + bicchiere.getLivello() + "mL.");
                    }

                    Util.continua();
                    break;
                }

                case 4:{

                    Util.printf("\nHai scelto: Svuota...\n");

                    float livelloBicchiere = bicchiere.getLivello();
                    if (livelloBicchiere <= 0){
                        Util.printf("\nIl bicchiere e' gia' vuoto!");
                        break;
                    }

                    bicchiere.setLivello(0);
                    Util.printf("\nIl bicchiere e' stato svuotato, " + livelloBicchiere + "mL sono stati buttati!");

                    Util.continua();
                    break;
                }

                case 5:{

                    Util.printf("\nHai scelto: Informazioni bicchiere...\n");

                    // Riassunto bicchiere creato.
                    Util.printf("\n\nInformazioni bicchiere: " +
                            "\nMateriale: " + bicchiere.getMateriale() +
                            "\nForma: " + bicchiere.getForma() +
                            "\nCapacita': " + bicchiere.getCapacita() + "mL" +
                            "\nLivello: " + bicchiere.getLivello() + "mL");

                    Util.continua();
                    break;
                }

                default:{
                    Util.printf("\nValore non valido!");
                    break;
                }
            }
        } while (scelta != 0);

        Util.printf("\n\nProgramma chiuso con successo!");

    }
}
