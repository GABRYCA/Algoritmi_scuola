package it.gabryca;

import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

public class Util {

    /**
     * Metodo getScanner è semplicemente uno scanner.
     * Per essere utilizzato non richiede parametri.
     */
    public static Scanner getScanner() {
        return new Scanner(System.in);
    }

    /**
     * Metodo continua, mette in pausa il codice
     * e attende che l'utente inserisca un numero per continuare.
     * Non richiede parametri
     */
    public static void continua() {

        printf("\nPer continuare digitare un numero: ");
        getScanner().nextInt();

    }

    /**
     * Il metodo printf è essenzialmente un System.out.print ma
     * scritto in modo diverso, richiede un parametro ossia il messaggio.
     *
     * @param message
     */
    public static void printf(String message) {
        System.out.print(message);
    }

    /**
     * Il metodo printf è essenzialmente un System.out.printf ma
     * scritto in modo diverso, richiede un parametro ossia il messaggio.
     *
     * @param message
     */
    public static void printfn(String message) {
        System.out.println(message);
    }

    /**
     * Divide in singoli numeri un numero complesso e lo salva dentro un vettore.
     */
    void singoloValVet(int dimensioni, int[] mioVettore, int numeroGeneratoVar) {
        for (int i = 0; i < dimensioni; ++i) {
            mioVettore[i] = numeroGeneratoVar % 10;
            numeroGeneratoVar = (numeroGeneratoVar - mioVettore[i]) / 10;
        }
    }

    /**
     * Mostra i valore contenuti in un vettore.
     */
    void mostraValori(int dimensioni, int[] mioVettore) {

        // Messaggio d'inizio
        printf("\nI valori sono: \n");

        // Ottengo tutti i valori dell'array in base alle dimensioni dichiarate, si noti che 0 è incluso all'inizio
        for (int i = 0; i < dimensioni; i++) {

            // Scrivo i numeri
            printf((i + 1) + "-->" + mioVettore[i] + "\t");

        }
    }

    /**
     * Trova i valori possibili con delle condizioni particolari.
     */
    int trovaValori(int dimensioni, int[] mioVettore) {

        // Prima cifra
        for (int i = 0; i < 10; i++) {

            // Seconda cifra.
            for (int j = 0; j < 10; j++) {

                // Se il valore è diverso va avanti
                if (j != i) {

                    // Terza cifra.
                    for (int k = 0; k < 10; k++) {

                        // Se i valori sono diversi allora va avanti
                        if (!(k == j || k == i)) {

                            // Quarta cifra.
                            for (int l = 0; l < 10; l++) {

                                // Se i valori sono tutti diversi, allora va avanti
                                if (!(l == k || l == j || l == i)) {

                                    // Ottengo valore finale e lo aggiungo, poi incremento le dimensioni.
                                    mioVettore[dimensioni] = ((10 * i + j) * 10 + k) * 10 + l;
                                    dimensioni++;
                                }
                            }
                        }
                    }
                }
            }
        }

        // Comunica che i valori sono stati generati con successo e quanti sono.
        printf("\nSono stati generati i valori con successo!\n");

        return dimensioni;
    }

    /**
     * Verifica se un valore è contenuto in un certo vettore.
     */
    boolean valorePresenteInVet(int dimensioni, int numeroDaTrovare, int[] vettore) {

        for (int i = 0; i < dimensioni; i++) {
            if (vettore[i] == numeroDaTrovare) {
                // Il valore è presente nel vettore
                return true;
            }
        }
        // Non è presente
        return false;
    }

    /**
     * Rimuove un valore dal vettore
     */
    void rimuoviPerPos(int dimensioni, int[] mioVettore,
                       int valore) {

        // Loop per eliminare "valore" e spostare tutti i valori
        for (int i = valore; i < dimensioni - 1; i++) {

            mioVettore[i] = mioVettore[i + 1];

        }
    }

    /**
     * Genera valori diversi in un vettore, utile per uno dei MasterMind in particolare Utente VS PC.
     */
    void genValDivInVet1(int[] mioVettore, int max, int min, int nCifre,
                         int nCifreGenerate) {// Genero N cifre diverse tra loro e le aggiungo al vettore.
        while (nCifreGenerate < nCifre) {

            // Ottiene un numero casuale
            int numeroRandom = ThreadLocalRandom.current().nextInt(min, max + 1);
            int valorePres = 0;

            // Verifica se il numero casuale è già stato aggiunto tra le cifre.
            for (int i = 0; i < nCifreGenerate; i++) {
                if (mioVettore[i] == numeroRandom) {
                    valorePres++;
                }
            }

            // Se il numero NON era presente tra le cifre generate, lo aggiunge tra le cifre generate.
            if (valorePres == 0) {
                mioVettore[nCifreGenerate] = numeroRandom;
                nCifreGenerate++;
            }

        }
    }
}
