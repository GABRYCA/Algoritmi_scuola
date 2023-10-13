/* scrivere un'applicazione che, data in input una stringa,
stampi come risultato la stringa stessa, convertendo i caratteri
in posizione pari in minuscolo e quelli in posizione dispari
in maiuscolo

Java -> JaVa 
012a -> 0-12a 
0A12 -> 0a-12 

u -> 1234
s -> JaVa
s -> java
i -> 0123*/
import java.util.Scanner;

public class Minuscole2 {
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		System.out.print("Inserire una stringa > ");
		String s = in.nextLine();
		s = s.toLowerCase(); //si trasforma la stringa tutta in minuscolo
		
		String ris = "";
		char c;
		
		for(int i=0; i < s.length(); i = i+1) { //oppure i <= s.length()-1;
			c = s.charAt(i);
			/*if(i%2 == 0) //i è pari?
				c = Character.toUpperCase(c);//maiuscolo
			ris = ris + c;*/
			
			//oppure
			/*if(i%2 == 0) //i è pari?
				ris = ris + Character.toUpperCase(c);//maiuscolo
			else 
				ris = ris + c;*/
			
			//oppure
			if(i%2 != 0) //i è dispari?
			//oppure if(!(i%2 == 0)) 
				ris = ris + Character.toLowerCase(c);//minuscolo
			else 
				ris = ris + c;
		}
		
		System.out.print("Stringa modificata > " + ris);
	}
}