package me.gca;

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
}