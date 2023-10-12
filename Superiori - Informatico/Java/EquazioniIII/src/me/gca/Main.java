package me.gca;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        final int VERDE = 0; // dichiaraz. costanti
        final int ROSSO = 2;
        final int ARANCIO = 1;
        int numero;
        System.out.print("Inserire numero tra 0 e 2: ");
        numero = in.nextInt();
        switch (numero){
            case VERDE: {
                System.out.println("il semaforo = VERDE");
                break;
            }
            case ARANCIO: {
                System.out.println("11 semaforo e' ARANCIO");
                break;
            }
            case ROSSO: {
                System.out.println("11 semaforo e' ROSSO");
                break;
            }
            default: {
                System.out.println("digitazione errata!");
            }
        }
    }
}
