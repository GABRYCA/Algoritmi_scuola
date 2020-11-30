package it.gabryca;

import java.util.Scanner;

public class Primo extends Util {

    public void altPerArRet(){
        // Fare in Java moltiplicazioni e divisioni, simile in C ma in Java

        // Input
        // InputStreamReader input = new InputStreamReader(System.in);
        // BufferedReader tastiera = new BufferedReader(input);

        // Dichiaro variabili
        int base, altezza, area, perimetro;

        // Richiedo input
        System.out.print("Inserire la base: ");
        base = getScanner().nextInt();
        System.out.print("Inserire l'altezza: ");
        altezza = getScanner().nextInt();

        // Eseguo calcoli
        perimetro = (base + altezza) * 2;
        area = base * altezza;

        // Comunico risultati
        System.out.println("Il perimetro misura: " + perimetro);
        System.out.println("L'area misura: " + area);
    }

}
