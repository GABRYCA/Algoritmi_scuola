import java.util.Scanner;

public class Fattoriale {
    public static void main(String[] args){
        
        Scanner in = new Scanner(System.in);

        System.out.print("Inserire max fattoriale (numero intero): ");
        int input = in.nextInt();

        if (input == 0) {
            System.out.println("Numero non valido, per favore riprovare!");
            return;
        }

        int sum = 1;
        for (int i = 1; i <= input; i++) {
            sum *= i;
        }

        System.out.println("Fattoriale: " + sum);
    }
}