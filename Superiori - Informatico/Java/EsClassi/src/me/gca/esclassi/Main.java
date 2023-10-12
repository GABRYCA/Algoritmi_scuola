package me.gca.esclassi;

import java.io.IOException;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("EsClassi G.C. 4BITI...");

        int scelta;
        O o = new O();
        N n = new N();
        S s = new S();
        do {
            System.out.print("Opzioni: " +
                    "\n0 -> Esci." +
                    "\n1 -> Somma di stringhe S usando O." +
                    "\n2 -> Somma di stringhe S1 e S2 usando O." +
                    "\n3 -> Somma di numeri N usando O." +
                    "\n4 -> Somma di numeri N1 e N2 usando O" +
                    "\n5 -> Resetta S e N di O." +
                    "\n6 -> Somma di stringhe S usando S." +
                    "\n7 -> Somma di stringhe S1 e S2 usando S." +
                    "\n8 -> Somma di numeri N usando N." +
                    "\n9 -> Somma di numeri N1 e N3 usando N." +
                    "\nScelta: ");

            switch (scelta = scanner.nextInt()) {
                case 0:{
                    System.out.println("Hai scelto: Esci..." +
                            "\nUscita in corso...");
                    break;
                }
                case 1:{
                    System.out.print("Inserisci la stringa S: ");
                    String str = scanner.next();
                    System.out.println("La somma di " + str + " è " + o.somma(str));
                    System.out.println("Inserire un carattere per continuare e premere invio...");
                    try {
                        System.in.read();
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                    break;
                }
                case 2:{
                    System.out.print("Inserisci la stringa S1: ");
                    String s1 = scanner.next();
                    System.out.print("Inserisci la stringa S2: ");
                    String s2 = scanner.next();
                    System.out.println("La somma di " + s1 + " e " + s2 + " è " + o.somma(s1, s2));
                    System.out.println("Inserire un carattere per continuare e premere invio...");
                    try {
                        System.in.read();
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                    break;
                }
                case 3:{
                    System.out.print("Inserisci il numero N: ");
                    int num = scanner.nextInt();
                    System.out.println("La somma di " + num + " è " + o.somma(num));
                    System.out.println("Inserire un carattere per continuare e premere invio...");
                    try {
                        System.in.read();
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                    break;
                }
                case 4:{
                    System.out.print("Inserisci il numero N1: ");
                    int n1 = scanner.nextInt();
                    System.out.print("Inserisci il numero N2: ");
                    int n2 = scanner.nextInt();
                    System.out.println("La somma di " + n1 + " e " + n2 + " è " + o.somma(n1, n2));
                    System.out.println("Inserire un carattere per continuare e premere invio...");
                    try {
                        System.in.read();
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                    break;
                }
                case 5:{
                    System.out.println("Reset di S e N di O...");
                    o.reset();
                    System.out.println("Reset completato.");
                    System.out.println("Inserire un carattere per continuare e premere invio...");
                    try {
                        System.in.read();
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                    break;
                }
                case 6:{
                    System.out.print("Inserisci la stringa S: ");
                    String str = scanner.next();
                    System.out.println("La somma di " + s + " è " + s.somma(str));
                    System.out.println("Inserire un carattere per continuare e premere invio...");
                    try {
                        System.in.read();
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                    break;
                }
                case 7:{
                    System.out.print("Inserisci la stringa S1: ");
                    String s1 = scanner.next();
                    System.out.print("Inserisci la stringa S2: ");
                    String s2 = scanner.next();
                    System.out.println("La somma di " + s1 + " e " + s2 + " è " + s.somma(s1, s2));System.out.println("Inserire un carattere per continuare e premere invio...");
                    try {
                        System.in.read();
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                    break;
                }
                case 8:{
                    System.out.print("Inserisci il numero N: ");
                    int num = scanner.nextInt();
                    System.out.println("La somma di " + num + " è " + n.somma(num));System.out.println("Inserire un carattere per continuare e premere invio...");
                    try {
                        System.in.read();
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                    break;
                }
                case 9:{
                    System.out.print("Inserisci il numero N1: ");
                    int n1 = scanner.nextInt();
                    System.out.print("Inserisci il numero N2: ");
                    int n2 = scanner.nextInt();
                    System.out.println("La somma di " + n1 + " e " + n2 + " è " + n.somma(n1, n2));
                    System.out.println("Inserire un carattere per continuare e premere invio...");
                    try {
                        System.in.read();
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                    break;
                }

                default:{
                    System.out.println("Valore non valido! Per favore riprovare...");
                    break;
                }
            }
        } while (scelta != 0);

        System.out.println("Uscita effettuata con successo!");
    }
}