import java.util.Scanner;

public class Palindroma{
    public static void main(String[] args){

        Scanner in = new Scanner(System.in); // Inizializzo scanner

        System.out.print("Inserire parola: "); // Chiedo input
        String input = in.nextLine(); // Prendo input

        // Verifico che input non sia una linea vuota
        if(input == ""){
            System.out.println("L'input non puo' essere vuoto, per favore riprovare!");
            return;
        }

        input = input.toLowerCase(); // Rendo tutto lowercase per evitare problemi con maiuscole e minuscole

        boolean palindroma = true; // booleano
        for(int i = 0; i < input.length() / 2 + 1; i++){
            if (input.charAt(i) != input.charAt(input.length() - (i + 1))){
                i = input.length(); // Rompo la condizione del ciclo senza usare break;
                palindroma = false;
            }
        }

        // Stampo risultato
        if (palindroma){
            System.out.println("La parola e' polindroma!");
        } else {
            System.out.println("La parola non e' polindroma!");
        }
    }
}