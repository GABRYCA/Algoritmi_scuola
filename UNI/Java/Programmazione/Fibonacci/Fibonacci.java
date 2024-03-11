import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args){

        Scanner in = new Scanner(System.in);

        System.out.print("Inserire max fibonacci (numero intero): ");
        int input = in.nextInt();

        if (input == 0) {
            System.out.println("Hai inserito un numero non valido, per favore riprovare!");
            return;
        }

        
        int a = 1, b = 1;
        System.out.print("Numeri di Fibonacci tra 0 e " + input + ": \n");
        while (a <= input) {
            int sum = a + b;
            a = b;
            b = sum;
            if (a <= input){
                System.out.println(a);
            }
        }

    }
}