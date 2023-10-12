package me.gca;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a, b, c, delta;
        double x1, x2;
        System.out.print("Inserisci il coeff. a: ");
        a = in.nextInt();
        System.out.print("Inserisci il coeff. b: ");
        b = in.nextInt();
        System.out.print("Inserisci il coeff. c: ");
        c = in.nextInt();
        if (a == 0){
            System.out.print("Divisore = 0!");
        } else {
            delta = b * b - 4 * a * c;
            if (delta < 0){
                System.out.print("delta < 0!");
            } else {
                x1 = (-b + Math.sqrt(delta)) / 2 * a;
                x2 = (-b - Math.sqrt(delta)) / 2 * a;
                System.out.println("La radice x1 = " + x1);
                System.out.println("La radice x2 = " + x2);
            }
        }
    }
}
