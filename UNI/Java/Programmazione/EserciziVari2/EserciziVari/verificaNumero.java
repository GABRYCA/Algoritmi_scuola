package esercizivari;
import java.util.Scanner;

public class verificaNumero {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Inserisci numero: ");
		
		int numero = in.nextInt();
		
		if(numero < 0)
			System.out.println("Numero negativo");
		else if (numero > 0)
			System.out.println("Numero positivo");
		else
			System.out.println("Zero");
		
		if(numero <= 1)
			System.out.println(" (piccolo)");
		else if(numero >= 1000)
			System.out.println(" (grande)");
	}
}
