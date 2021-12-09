package me.gca;

public class Main {

    public static void main(String[] args) {
        Persona p = new Persona("Sordi", "Alberto");
        System.out.println("\nPersona   \n-------");
        p.stampa();

        Sportivo s = new Sportivo("Rossi", "Valenino", "Motociclismo");
        System.out.println("\nSportivo  \n-------");
        s.stampa();

        Calciatore c = new Calciatore("Maradona", "Diego", "calcio", "Napoli");
        System.out.println("\nCalciatore \n-------");
        c.stampa();
    }
}
