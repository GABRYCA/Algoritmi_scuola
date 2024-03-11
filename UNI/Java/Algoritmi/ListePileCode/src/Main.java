import Lista.Lista;
import Pila.Pila;
import Coda.Coda;

import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {

        System.out.println("""
                ////////////////////////////////////////////
                //     Project by GCA - ListePileCode     //
                ////////////////////////////////////////////
                """);

        int scelta = -1;
        while (scelta != 0) {
            Scanner scanner = new Scanner(System.in);
            System.out.println("Scegli: \n" +
                    "0 - Esci\n" +
                    "1 - Lista\n" +
                    "2 - Pila\n" +
                    "3 - Coda\n" +
                    "Scelta:"
            );

            scelta = scanner.nextInt();
            switch (scelta) {
                case 0 -> System.exit(0);
                case 1 -> {
                    Lista lista = new Lista();
                    int sceltaLista = -1;

                    while (sceltaLista != 0) {
                        System.out.println("\nLista, azioni possibili: \n" +
                                "0 - Esci\n" +
                                "1 - Insert\n" +
                                "2 - Size\n" +
                                "3 - Contains\n" +
                                "4 - Print\n" +
                                "5 - Remove\n" +
                                "6 - Remove per Index\n" +
                                "Scelta:");
                        sceltaLista = scanner.nextInt();

                        switch (sceltaLista) {
                            case 0 -> System.out.println("Uscita da lista...\n");
                            case 1 -> {
                                System.out.println("\nInserire il valore da inserire: ");
                                int valore = scanner.nextInt();
                                lista.insert(valore);
                                System.out.println("Valore " + valore + " inserito.");
                                waitForEnter();
                            }
                            case 2 -> {
                                if (lista.isEmpty()) {
                                    System.out.println("La lista è vuota");
                                } else if (lista.size() == 1) {
                                    System.out.println("La lista contiene 1 elemento.");
                                } else {
                                    System.out.println("La lista contiene " + lista.size() + " elementi.");
                                }
                                waitForEnter();
                            }
                            case 3 -> {
                                System.out.println("Inserire il valore da cercare: ");
                                int valore = scanner.nextInt();
                                if (lista.contains(valore)) {
                                    System.out.println("Il valore " + valore + " è presente nella lista.");
                                } else {
                                    System.out.println("Il valore " + valore + " non è presente nella lista.");
                                }
                                waitForEnter();
                            }
                            case 4 -> {
                                System.out.println("Stampa lista: ");
                                lista.print();
                                waitForEnter();
                            }
                            case 5 -> {
                                System.out.println("Inserire il valore da eliminare: ");
                                int valore = scanner.nextInt();
                                if (lista.remove(valore)){
                                    System.out.println("Il valore " +  valore + " è stato rimosso con successo!");
                                } else {
                                    System.out.println("Il valore " + valore + " non è stato trovato!");
                                }
                                waitForEnter();
                            }
                            case 6 -> {
                                System.out.println("Lista attuale: ");
                                lista.print();
                                System.out.println("Inserire la posizione dell'elemento da eliminare (tra 0 e " + (lista.size() - 1) + "):");
                                int posizione = scanner.nextInt();
                                if (lista.removePos(posizione)) {
                                    System.out.println("Rimosso con successo elemento in posizione: " + posizione);
                                } else {
                                    System.out.println("Errore durante la rimozione dell'elemento oppure non trovato!");
                                }
                                waitForEnter();
                            }
                            default -> {
                                System.out.println("Scelta non valida");
                                waitForEnter();
                            }
                        }
                    }
                }
                case 2 -> {
                    Pila pila = new Pila();
                    int sceltaPila = -1;

                    while (sceltaPila != 0) {
                        System.out.println("\nPila, azioni possibili: \n" +
                                "0 - Esci\n" +
                                "1 - Push\n" +
                                "2 - Pop\n" +
                                "3 - Size\n" +
                                "4 - Top\n" +
                                "5 - Contains\n" +
                                "6 - Print\n" +
                                "Scelta:");
                        sceltaPila = scanner.nextInt();

                        switch (sceltaPila) {
                            case 0 -> System.out.println("Uscita da pila...\n");
                            case 1 -> {
                                System.out.println("\nInserire il valore da inserire: ");
                                int valore = scanner.nextInt();
                                pila.push(valore);
                                System.out.println("Valore " + valore + " inserito.");
                                waitForEnter();
                            }
                            case 2 -> {
                                if (pila.isEmpty()) {
                                    System.out.println("La pila è vuota.");
                                } else {
                                    System.out.println("Valore " + pila.pop() + " rimosso.");
                                }
                                waitForEnter();
                            }
                            case 3 -> {
                                if (pila.isEmpty()) {
                                    System.out.println("La pila è vuota");
                                } else if (pila.size() == 1) {
                                    System.out.println("La pila contiene 1 elemento.");
                                } else {
                                    System.out.println("La pila contiene " + pila.size() + " elementi.");
                                }
                                waitForEnter();
                            }
                            case 4 -> {
                                if (pila.isEmpty()) {
                                    System.out.println("La pila è vuota.");
                                } else {
                                    System.out.println("Valore in cima: " + pila.top());
                                }
                                waitForEnter();
                            }
                            case 5 -> {
                                System.out.println("Inserire il valore da cercare: ");
                                int valore = scanner.nextInt();
                                if (pila.contains(valore)) {
                                    System.out.println("Il valore " + valore + " è presente nella pila.");
                                } else {
                                    System.out.println("Il valore " + valore + " non è presente nella pila.");
                                }
                                waitForEnter();
                            }
                            case 6 -> {
                                System.out.println("Stampa pila: ");
                                pila.print();
                                waitForEnter();
                            }
                            default -> {
                                System.out.println("Scelta non valida");
                                waitForEnter();
                            }
                        }
                    }
                }
                case 3 -> {
                    Coda coda = new Coda();
                    int sceltaCoda = -1;

                    while (sceltaCoda != 0) {
                        System.out.println("\nCoda, azioni possibili: \n" +
                                "0 - Esci\n" +
                                "1 - Enqueue\n" +
                                "2 - Dequeue\n" +
                                "3 - Size\n" +
                                "4 - Front\n" +
                                "5 - Contains\n" +
                                "6 - Print\n" +
                                "Scelta:");
                        sceltaCoda = scanner.nextInt();

                        switch (sceltaCoda) {
                            case 0 -> System.out.println("Uscita da coda...\n");
                            case 1 -> {
                                System.out.println("\nInserire il valore da inserire: ");
                                int valore = scanner.nextInt();
                                coda.enqueue(valore);
                                System.out.println("Valore " + valore + " inserito.");
                                waitForEnter();
                            }
                            case 2 -> {
                                if (coda.isEmpty()) {
                                    System.out.println("La coda è vuota.");
                                } else {
                                    System.out.println("Valore " + coda.dequeue() + " rimosso.");
                                }
                                waitForEnter();
                            }
                            case 3 -> {
                                if (coda.isEmpty()) {
                                    System.out.println("La coda è vuota");
                                } else if (coda.size() == 1) {
                                    System.out.println("La coda contiene 1 elemento.");
                                } else {
                                    System.out.println("La coda contiene " + coda.size() + " elementi.");
                                }
                                waitForEnter();
                            }
                            case 4 -> {
                                if (coda.isEmpty()) {
                                    System.out.println("La coda è vuota.");
                                } else {
                                    System.out.println("Valore in front: " + coda.front());
                                }
                                waitForEnter();
                            }
                            case 5 -> {
                                System.out.println("Inserire il valore da cercare: ");
                                int valore = scanner.nextInt();
                                if (coda.contains(valore)) {
                                    System.out.println("Il valore " + valore + " è presente nella coda.");
                                } else {
                                    System.out.println("Il valore " + valore + " non è presente nella coda.");
                                }
                                waitForEnter();
                            }
                            case 6 -> {
                                System.out.println("Stampa coda: ");
                                coda.print();
                                waitForEnter();
                            }
                            default -> {
                                System.out.println("Scelta non valida");
                                waitForEnter();
                            }
                        }
                    }
                }
                default -> {
                    System.out.println("Scelta non valida");
                    waitForEnter();
                }
            }
        }
    }

    public static void waitForEnter() {
        System.out.println("\nPremere invio per continuare...");
        try {
            System.in.read();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}