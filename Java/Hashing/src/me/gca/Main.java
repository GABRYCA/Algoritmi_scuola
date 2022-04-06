package me.gca;

import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Vector;

public class Main {

    public static void main(String[] args) {

        // Messaggio di benvenuto.
        Util.printfn("\n////////////////////////////////////" +
                "\n         DI G.C. 4BITI              " +
                "\n////////////////////////////////////");

        // Inizializzo tabelle vuote.
        int scelta;
        int[] tabella = new int[0]; // Tabella contenente Hash.
        String[] tabellaStringhe = new String[0]; // Tabella utile solamente per il debug, salva le stringhe originali.
        do {

            // Legenda e input utente.
            Util.printf("\nOpzioni: " +
                    "\n0 -> Esci." +
                    "\n1 -> Aggiungi elemento alla tabella." +
                    "\n2 -> Leggi tabella." +
                    "\n3 -> Hash con MD5." +
                    "\n4 -> Esempio uso dei Vector." +
                    "\nScelta: ");
            scelta = Util.getScanner().nextInt();

            // Opzioni con switch.
            switch (scelta) {

                case 0: {

                    // Messaggio d'uscita.
                    Util.printfn("\nHai scelto: Esci..." +
                            "\n\nUscita in corso...");

                    break;
                }

                case 1: {

                    // Messaggio d'inizio.
                    Util.printfn("\nHai scelto: Aggiungi elemento alla tabella...");

                    // Chiedo dati all'utente.
                    Util.printf("\nInserire la stringa da tradurre in Hash: ");
                    String stringaDaTradurre = Util.getScanner().nextLine();

                    // Calcolo l'hash chiamando la funzione e comunico all'utente..
                    int hash = hash(stringaDaTradurre);
                    Util.printfn("Hash: " + hash);
                    Util.printfn("Resto: " + hash % 50);

                    tabella = addTabella(tabella, hash); // Aggiungo l'Hash calcolato all'"HashTable".
                    tabellaStringhe = addTabella(tabellaStringhe, stringaDaTradurre); // Solo per il debug, salvo la stringa originale.

                    // Messaggio di successo.
                    Util.printfn("\nAggiunto con successo!");
                    break;
                }

                case 2: {

                    // Messaggio d'inizio.
                    Util.printfn("\nHai scelto: Leggi tabella....");

                    // Se la tabella e' vuota sara' inutile stamparla.
                    if (tabella.length == 0) {
                        Util.printfn("\nLa tabella e' vuota.");
                        break;
                    }

                    // Stampo contenuto tabella (inclusa quella di debug, rimovibile in futuro).
                    Util.printfn("\nContenuto tabella: ");
                    for (int i = 0; i < tabella.length; i++) {
                        Util.printfn(i + " -> " + tabella[i] + " | " + tabellaStringhe[i]);
                    }

                    // Pausa.
                    Util.continua();
                    break;
                }

                case 3: {

                    Util.printfn("\nHai scelto: Crea Hash MD5 da input...");

                    Util.printf("\nInserire stringa da tradurre: ");
                    String input = Util.getScanner().nextLine();

                    byte[] bytes = input.getBytes(StandardCharsets.UTF_8);

                    MessageDigest md;
                    try {
                        md = MessageDigest.getInstance("MD5");
                    } catch (NoSuchAlgorithmException e) {
                        e.printStackTrace();
                        return;
                    }

                    byte[] digest = md.digest();
                    BigInteger numeroEnorme = new BigInteger(1, digest);
                    String stringaHash = numeroEnorme.toString(16);

                    // Riempio HASH con 0 fino a 32 caratteri.
                    /*while(stringaHash.length() < 32 ){
                        stringaHash = "0" + stringaHash;
                    }*/

                    Util.printfn("\nHash MD5: " + stringaHash);
                    Util.continua();
                    break;
                }

                case 4: {

                    Util.printfn("\nHai scelto: Esempio uso dei Vector...");

                    Util.printfn("\nSto inserendo delle stringhe di base per testare il vector...");
                    // Esempio uso dei Vector.
                    Vector<String> vettore = new Vector<>();
                    vettore.add("ciao");
                    vettore.add("mondo");

                    Util.printfn("\nContenuto Vettore: " + vettore);

                    Util.printfn("\nInserire testo, scrivere 0 per uscire...");

                    String testo = Util.getScanner().nextLine();
                    while (!testo.equalsIgnoreCase("0")) {
                        vettore.add(testo);
                        testo = Util.getScanner().nextLine();
                    }

                    Util.printfn("\nContenuto Vettore: " + vettore);

                    Util.continua();
                    break;
                }

                default: {

                    // Errore: Scelta non valida.
                    Util.printfn("\nScelta non valida, per favore riprovare!");

                    break;
                }
            }

        } while (scelta != 0);

        // Chiuso con successo.
        Util.printfn("\nChiuso con successo...");
    }


    /**
     * Calcolo Hash.
     *
     * @param stringa
     * @return
     */
    public static int hash(String stringa) {
        int hash = 0; // Inizializzo il valore dell'Hash.

        if (stringa.length() > 0) { // Eseguo il calcolo dell'Hash solamente se la lunghezza della stringa e' maggio di 0.
            char[] singoliCar = stringa.toCharArray(); // Ottengo i singoli caratteri.
            for (int i = 0; i < stringa.length(); i++) {
                hash = 23 * hash + singoliCar[i]; // Moltiplico l'Hash precedente per un numero a scelta e sommo l'ascii
                // del singolo carattere.
            }
        }

        // Ritorno Hash finale, se la stringa e' nulla può essere 0.
        return hash;
    }

    /**
     * Semplice metodo per aggiungere un valore in un vettore esistente di interi, incrementandone la dimensione.
     *
     * @param tabella
     * @param valore
     * @return
     */
    public static int[] addTabella(int[] tabella, int valore) {

        // Tabella temporanea piu' grande.
        int[] nuovaTabella = new int[tabella.length + 1];

        // Copio vecchia tabella in quella nuova usando funzioni gia' esistenti in Java (risparmio 3 righe di codice).
        System.arraycopy(tabella, 0, nuovaTabella, 0, tabella.length);
        nuovaTabella[nuovaTabella.length - 1] = valore; // Aggiungo il nuovo valore.

        // Ritorno la nuova tabella.
        return nuovaTabella;
    }

    /**
     * Semplice metodo per aggiungere una stringa a un vettore di stringhe incrementandone la dimensione.
     *
     * @param tabella
     * @param valore
     * @return
     */
    public static String[] addTabella(String[] tabella, String valore) {

        // Tabella temporanea piu' grande.
        String[] nuovaTabella = new String[tabella.length + 1];

        // Copio contenuto vecchia tabella in nuova, risparmio qualche riga di codice.
        System.arraycopy(tabella, 0, nuovaTabella, 0, tabella.length);
        nuovaTabella[nuovaTabella.length - 1] = valore; // Inserisco il nuovo valore.

        // Ritorno la nuova tabella.
        return nuovaTabella;
    }
}
