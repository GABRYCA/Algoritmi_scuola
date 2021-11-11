package me.gca;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int num1, num2, resto;
        System.out.print("\nInserisci due numeri: ");
        num1 = in.nextInt();
        num2 = in.nextInt();
        while (num2 > 0){
            resto = num1 % num2; // calcolo del resto.
            num1 = num2;         // Scambio dei numeri.
            num2 = resto;
        }
        System.out.print("\nIl MCD e' " + num1);
    }
}
