import java.util.Scanner;

public class ProvaStringInversa {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Inizializzo scanner

        System.out.print("Inserire stringa da invertire: "); // Chiedo input
        String input = in.nextLine(); // Prendo input utente

        // Se la stringa in input è vuota, fermo tutto
        if (input == ""){
            System.out.println("La stringa non puo' essere vuota! Per favore riprovare"); // Messaggio di errore
            return; // Return che chiude il programma
        }

        System.out.print("\nLinea inversa: ");
        for (int i = input.length() - 1; i >= 0; i--){ // Ciclo che parte dall'ultimo carattere (nota, si parte da 0 con i caratteri, quindi il massimo di "ciao" per esempio, la o è in posizione 3)
            System.out.print(input.charAt(i)); // Stampo il singolo carattere, si poteva anche creare una string d'appoggio e fare (Esempio:) String ciao = ""; ciao += input.charAt(i); e poi printare con System.out.println(ciao)
        }
    }
}