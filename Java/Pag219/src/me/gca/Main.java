package me.gca;

import java.util.Scanner;

public class Main {
    static int num1, num2;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("\nInserisci valore per num1: ");
        num1 = in.nextInt();
        System.out.print("Inserisci valore per num2:");
        num2 = in.nextInt();
        scambia();
        System.out.println("num1 contiene: " + num1);
        System.out.println("num2 contiene: " + num2);
    }
    public static void scambia(){
        int tempo;
        tempo = num1;
        num2 = tempo;
    }
}
