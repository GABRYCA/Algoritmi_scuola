package it.gabryca;

import java.util.Random;
import java.util.Scanner;

public class Util {

    /**
     * Metodo getScanner è semplicemente uno scanner.
     * Per essere utilizzato non richiede parametri.
     * */
    public static Scanner getScanner(){
        return new Scanner(System.in);
    }

    /**
     * Metodo continua, mette in pausa il codice
     * e attende che l'utente inserisca un numero per continuare.
     * Non richiede parametri
     * */
    public static void continua(){

        printf("\n\nPer continuare digitare un numero: ");
        getScanner().nextInt();

    }

    /**
     * Il metodo printf è essenzialmente un System.out.print ma
     * scritto in modo diverso, richiede un parametro ossia il messaggio.
     * @param message
     * */
    public static void printf(String message){
        System.out.print(message);
    }

    /**
     * Il metodo printf è essenzialmente un System.out.printf ma
     * scritto in modo diverso, richiede un parametro ossia il messaggio.
     * @param message
     * */
    public static void printfn(String message){
        System.out.println(message);
    }

    /**
     * Leggi un vettore di numeri.
     *
     * @param numeroNumeri - Int di numero di numeri da leggere.
     * @param vettore - Vettore contenente i valori
     * */
    public static void letturaVett(int numeroNumeri, int[] vettore) {
        for (int i = 0; i < numeroNumeri; i++){
            printf("\n" + (i + 1) + " - " + vettore[i]);
        }
    }

    /**
     * Ordina un vettore di numeri a seconda del numero massimo contenuto.
     *
     * @param numeroNumeri - Numero di numeri.
     * @param vettore - Vettore con i numeri.
     * */
    public static void ordinamentoMax(int numeroNumeri, int[] vettore) {
        if (numeroNumeri != 0){

            // Trova numero maggiore e minore nel vettore.
            int max = 0, min = 999999;
            for (int i = 0; i < numeroNumeri; i++) {

                // Trova maggiore
                if (max < vettore[i]){
                    max = vettore[i];
                }

                // Trova minore.
                if (min > vettore[i]){
                    min = vettore[i];
                }
            }

            // Vettore temporaneo di appoggio e variabili, ordinamento valori.
            int[] vettoreNuovo = new int[numeroNumeri];
            int contatore = 0;
            for(int i = min; i <= max; i++){

                for(int j = 0; j < numeroNumeri; j++){

                    if(vettore[j] == i){

                        // Assegna il valore al vettore di appoggio.
                        vettoreNuovo[contatore] = vettore[j];
                        contatore++;
                    }
                }
            }

            // Ricopio i numeri del vettore di appoggio nell'originale
            if (numeroNumeri >= 0) System.arraycopy(vettoreNuovo, 0, vettore, 0, numeroNumeri);

            printf("\nOrdinamento effettuato con successo!");

        } else {
            printf("\nIl vettore di numeri contiene 0 valori, per favore generarne uno prima di questa opzione...");
        }
    }

    /**
     * Ordinamento vettore con scambio.
     *
     * @param numeroNumeri - Numero di numeri nel vettore.
     * @param vettore - Vettore con i numeri.
     * */
    public static void ordinamentoScambio(int numeroNumeri, int[] vettore) {
        if (numeroNumeri != 0){

            // Faccio un ciclo per l'intero vettore, ogni valore sara' spostato nella nuova posizione.
            int vecchioNumero;
            for (int i = 0; i < numeroNumeri; i++) {

                // Faccio un ciclo per tutto il vettore a partire dal valore successivo alla posizione di assegnamento.
                for (int j = i + 1; j < numeroNumeri; j++) {

                    // Verifico se il numero che sto verificando e' maggiore di quello attualmente presente.
                    if (vettore[i] > vettore[j]) {

                        // Scambio i valori appoggiandomi ad una variabile temporanea.
                        vecchioNumero = vettore[i];
                        vettore[i] = vettore[j];
                        vettore[j] = vecchioNumero;
                    }
                }
            }

            printf("\nValori ordinati con successo!");

        } else {

            printf("\nIl vettore di numeri contiene 0 valori, per favore generarne uno prima di questa opzione...");

        }
    }

    /**
     * Genera valori tra max e min su un vettore.
     *
     * @param numeroNumeri - Numeri di numeri da generare.
     * @param vettore - Vettore su cui generare i numeri.
     * @param numeroMassimo - Numero massimo.
     * @param numeroMinimo - Numero minimo.
     * */
    public static void genValSuVett(int numeroNumeri, int[] vettore, int numeroMassimo, int numeroMinimo) {
        Random random = new Random();
        for (int i = 0; i < numeroNumeri; i++){
            int finale = (random.nextInt((numeroMassimo + 1) - numeroMinimo) + numeroMinimo);
            vettore[i] = finale;
        }
    }
}