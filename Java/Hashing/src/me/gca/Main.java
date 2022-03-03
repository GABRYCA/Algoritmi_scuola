package me.gca;

public class Main {

    public static void main(String[] args) {

        Util.printfn("\n////////////////////////////////////" +
                     "\n         DI G.C. 4BITI              " +
                     "\n////////////////////////////////////");

        int scelta;
        int[] tabella = new int[0];
        String[] tabellaStringhe = new String[0];
        do {

            Util.printf("\nOpzioni: " +
                    "\n0 -> Esci." +
                    "\n1 -> Aggiungi elemento alla tabella." +
                    "\n2 -> Leggi tabella." +
                    "\nScelta: ");
            scelta = Util.getScanner().nextInt();

            switch (scelta){

                case 0:{

                    Util.printfn("\nHai scelto: Esci..." +
                            "\n\nUscita in corso...");

                    break;
                }

                case 1:{

                    Util.printfn("\nHai scelto: Aggiungi elemento alla tabella...");

                    Util.printf("\nInserire la stringa da tradurre in Hash: ");
                    String stringaDaTradurre = Util.getScanner().nextLine();

                    int hash = hash(stringaDaTradurre);
                    Util.printfn("Hash: " + hash);
                    Util.printfn("Resto: " + hash % 50);

                    tabella = addTabella(tabella, hash);
                    tabellaStringhe = addTabella(tabellaStringhe, stringaDaTradurre);

                    Util.printfn("\nAggiunto con successo!");
                    break;
                }

                case 2:{

                    Util.printfn("\nHai scelto: Leggi tabella....");

                    Util.printfn("\nContenuto tabella: ");
                    for (int i = 0; i < tabella.length; i++){
                        Util.printfn(i + " -> " + tabella[i] + " | " + tabellaStringhe[i]);
                    }

                    Util.continua();
                    break;
                }

                default:{

                    Util.printfn("\nScelta non valida, per favore riprovare!");

                    break;
                }
            }

        } while (scelta != 0);

        Util.printfn("\nChiuso con successo...");
    }

    public static int hash(String stringa){
        int hash = 0;

        int hashTemp = hash;
        if (stringa.length() > 0) {
            char[] car = stringa.toCharArray();

            for (int i = 0; i < stringa.length(); i++) {
                hashTemp = 31 * hashTemp + car[i];
            }
            hash = hashTemp;
        }

        return hash;
    }

    public static int[] addTabella(int[] tabella, int valore){

        int[] nuovaTabella = new int[tabella.length + 1];

        System.arraycopy(tabella, 0, nuovaTabella, 0, tabella.length);
        nuovaTabella[nuovaTabella.length-1] = valore;

        return nuovaTabella;
    }

    public static String[] addTabella(String[] tabella, String valore){

        String[] nuovaTabella = new String[tabella.length + 1];

        System.arraycopy(tabella, 0, nuovaTabella, 0, tabella.length);
        nuovaTabella[nuovaTabella.length-1] = valore;

        return nuovaTabella;
    }
}
