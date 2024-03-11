/* scrivere un applicazione che data input come stringa stampi risultato la stringa stessa convertendo i caratteri in posizione pari
in maiuscolo e quelli in posizione dispari in minuscolo */

import java.util.Scanner;
import prog.io.ConsoleOutputManager;

public class MinuscoleAlternativo {
	
	public static void main (String [] args) {
		
		ConsoleOutputManager out = new ConsoleOutputManager();
		Scanner in = new Scanner(System.in);
		out.println("Inserire una stringa ");
		String S = in.nextLine();
		S = S.trim();
		
		if (S.length()==0) 
			return;
		
		int length = S.length();
		
		String Sub1,Sub2;
		
		for(int i=0;i<length;i=i+1)
		{
			Sub1 = S.substring(0,i);
			Sub2 = S.substring(i);
			if (i%2==0)
				Sub2 = Sub2.toUpperCase();
			else
				Sub2 = Sub2.toLowerCase();
			
			S = Sub1 + Sub2;
		}
		
		out.println("Stringa : " + S);
	}
}