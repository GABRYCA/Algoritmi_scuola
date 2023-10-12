/* chiedere all'utente di inserire una stringa e un intero
stampare in output se la stringa è lunga come l'intero, oppure più corta */

import java.util.Scanner;

public class IfElseString {
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		//lettura della stringa
		System.out.print("Inserire una stringa > ");
		String s = in.nextLine();
		s = s.trim();
		//lettura dell'intero
		System.out.print("Inserire un intero > ");
		int n = in.nextInt();
		
		if(n <= 0) { //si fa in modo di terminare il programma se l'input è <= 0
			System.out.print("Input non valido...riprova :-( Bye");
			return;
		}
		
		int l = s.length();
		
		if(n == l)
			System.out.println("Il numero corrisponde alla lunghezza della stringa");
		else if(n > l)
				System.out.println("Il numero e' maggiore della lunghezza della stringa");
			 else { 
				System.out.println("Il numero e' minore della lunghezza della stringa");
			    /*se il numero inserito è minore della lunghezza della stringa, 
		        stampare la sotto-stringa di lunghezza pari al valore inserito e
				la sotto-stringa ottenuta a partire dal valore inserito */
				if(n > 0) {
					System.out.println("Sotto-stringa iniziale > " + s.substring(0, n));
					System.out.println("Sotto-stringa finale > " + s.substring(n-1));
				}
			 }
		System.out.println();	 
		
		//non funziona correttamente se n <= 0
		if(n == l)
			System.out.println("Il numero corrisponde alla lunghezza della stringa");
		else if(n > 0 && n < l) {
				System.out.println("Il numero e' minore della lunghezza della stringa");
				System.out.println("Sotto-stringa iniziale > " + s.substring(0, n));
				System.out.println("Sotto-stringa finale > " + s.substring(n-1));	
			 } else 
				System.out.println("Il numero e' maggiore della lunghezza della stringa");
		
	}
}