package me.gca;

import java.util.Scanner;

public class Main {
    static final int TANTI = 30;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String parola;
        char[] minuscolo = new char[TANTI];
        System.out.print("\nInserisci una parola: ");
        parola = in.next();
        // Trasforma la stringa letti in un array di caratteri.
        for (int x = 0; x < parola.length(); x++){
            minuscolo[x] = parola.charAt(x); // Primo carattere letto.
        }

        // Trasforma la parola in minuscolo.
        for (int x = 0; x < parola.length(); x++){
            minuscolo[x] = Character.toLowerCase(minuscolo[x]); // In minuscolo.
        }

        System.out.print("La parola in minuscolo: ");
        // Visualizza la parola carattere per carattere.
        for (int x = 0; x < minuscolo.length; x++){
            System.out.print(minuscolo[x]);
        }
    }
}
