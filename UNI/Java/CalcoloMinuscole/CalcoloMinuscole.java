/* implementare un'applicazione che calcoli il numero di caratteri
minuscoli all'interno di una stringa fornita dall'utente */

import java.util.Scanner;

public class CalcoloMinuscole {
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		System.out.print("Inserire una stringa > ");
		String s = in.nextLine();
		int num = 0;
		char c;
		
		for(int i=0; i < s.length(); i=i+1) {
			c = s.charAt(i);
			if(Character.isLowerCase(c))
				num = num + 1;
		}
		System.out.println("Numero caratteri minuscoli > " + num);
		
		//oppure
		/*for(int i=0; i < s.length(); i=i+1)
			if(Character.isLowerCase(s.charAt(i)))
				num = num + 1;*/
			
		//traduzione in ciclo while
		int i = 0;
		num = 0;
		while(i < s.length()){
			c = s.charAt(i);
			if(Character.isLowerCase(c))
				num = num + 1;
			i=i+1;
		}
		System.out.println("Numero caratteri minuscoli > " + num);
		
		//traduzione in ciclo do-while - errore in caso di stringa vuota
		i = 0;
		num = 0;
		do {
			c = s.charAt(i);
			if(Character.isLowerCase(c))
				num = num + 1;
			i=i+1;
		} while(i < s.length());
		
		System.out.print("Numero caratteri minuscoli > " + num);
	}
}