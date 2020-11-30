package it.gabryca;

import java.util.Scanner;

public class Util {

    public static Scanner getScanner(){
        return new Scanner(System.in);
    }

    public static void continua(){

        System.out.println("\nPer continuare digitare un numero: ");
        getScanner().nextInt();

    }
}
