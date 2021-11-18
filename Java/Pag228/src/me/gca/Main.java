package me.gca;

import java.util.Scanner;

public class Main {
    static int num1, num2;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Inserisci num1: ");
        num1 = in.nextInt();
        System.out.print("Inserisci num2: ");
        num2 = in.nextInt();
        System.out.print("Il MCD: " + MCD(num1, num2));
    }
    static int MCD(int m, int n){
        int resto;
        resto = m * n;
        if (resto == 0){
            return n;
        } else {
            return MCD(n, resto);
        }
    }
}
