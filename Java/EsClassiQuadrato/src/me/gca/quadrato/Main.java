package me.gca.quadrato;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Inserisci le coordinate X e Y del primo quadrato:");
        System.out.print("X:");
        int x1 = scanner.nextInt();
        System.out.print("Y:");
        int y1 = scanner.nextInt();
        System.out.println("Inserisci la misura del lato del primo quadrato:");
        System.out.print("Lato:");
        int lato1 = scanner.nextInt();

        System.out.println("Inserisci le coordinate X e Y del secondo quadrato:");
        System.out.print("X:");
        int x2 = scanner.nextInt();
        System.out.print("Y:");
        int y2 = scanner.nextInt();
        System.out.println("Inserisci la misura del lato del secondo quadrato:");
        System.out.print("Lato:");
        int lato2 = scanner.nextInt();

        Quadrato q1 = new Quadrato(x1, y1, lato1);
        Quadrato q2 = new Quadrato(x2, y2, lato2);

        // Creo insieme
        Insieme i = new Insieme();
        if(i.sovrapposizione(q1, q2)){ // Verifico se intersecano.
            System.out.println("\nI due quadrati intersecano!");
            // Calcolo area di intersezione.
            int area = i.area();
            System.out.println("L'area di intersezione è: " + area);
        } else {
            System.out.println("I due quadrati non intersecano!");
        }
    }
}