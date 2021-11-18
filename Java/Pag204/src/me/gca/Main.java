package me.gca;

import java.util.Scanner;

public class Main {
    final static double PIGRECO = 3.1415;
    public static void main(String[] args) {
        int raggio;
        double perimetro, area;
        raggio = leggiDati();
        perimetro = calcolaPerimetro(raggio);
        area = calcolaArea(raggio);
        stampaRisultati(perimetro, area);
    }
    static int leggiDati(){
        Scanner in = new Scanner(System.in);
        int dato;
        do {
            System.out.print("Inserisci il raggio: ");
            dato = in.nextInt();
        } while (dato <= 0);
        return dato;
    }
    static double calcolaPerimetro(int raggio){
        double numero1;
        numero1 = 2 * raggio * PIGRECO;
        return numero1;
    }
    static double calcolaArea(int raggio){
        double numero1;
        numero1 = raggio * raggio * PIGRECO;
        return numero1;
    }
    static void stampaRisultati(double dato1, double dato2){
        System.out.printf("La misura del perimetro e': %.2f", dato1);
        System.out.printf("La misura dell'area e': %.2f%n", dato2);
    }
}
