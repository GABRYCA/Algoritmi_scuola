//Inserire una frase e capovolgerla.
import java.util.Scanner;

public class Specchio{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		System.out.print("Inserire frase da capovolgere: ");
		String frase = in.nextLine();
		String cap = "";
			
		for(int i = 0; i < frase.length(); i++)
			cap = frase.charAt(i) + cap;
		
		System.out.println("Frase capovolta: " + cap);
		
		//oppure, partendo dalla fine della stringa
		cap = "";
		for(int i = frase.length()-1; i >= 0; i=i-1)
			cap = cap + frase.charAt(i);
		
		System.out.println("Frase capovolta: " + cap);
	}
}