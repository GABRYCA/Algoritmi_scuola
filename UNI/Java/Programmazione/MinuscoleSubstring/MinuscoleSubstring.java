import java.util.Scanner;

public class MinuscoleSubstring {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        System.out.print("Inserire stringa: ");
        String input = in.nextLine();

        if (input == ""){
            System.out.println("Inserire una stringa non vuota! Per favore riprovare.");
            return;
        }

        System.out.println("Stringa modificata (Posizione pari minuscoli, dispari Maiuscoli):");
        for (int i = 0; i < input.length(); i++){
            if (i % 2 == 0) {
                System.out.print(input.substring(i, i + 1).toUpperCase());
            } else {
                System.out.print(input.substring(i, i + 1).toLowerCase());
            }
        }
    }
}