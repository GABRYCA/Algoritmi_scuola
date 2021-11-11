package me.gca;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int anni = 0;
        String dato;
        System.out.print("\nQuanti anni hai? ");
        anni = in.nextInt();
        if ((anni > 10) || (anni < 80)){
            System.out.print("Ingresso a pagamento");
        } else {
            System.out.print("Ingresso gratuito");
        }
    }
}
