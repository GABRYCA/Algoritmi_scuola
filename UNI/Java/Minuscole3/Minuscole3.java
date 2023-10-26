import java.util.Scanner;
 //provare ad usare substring
 public class Minuscole3 {
	 public static void main(String[] args){
		 Scanner in = new Scanner(System.in);
		 
		 System.out.print("Inserisci frase: ");
		 String frase = in.nextLine();
		 frase = frase.toLowerCase().trim();
		 /*frase = frase.toLowerCase();
		 frase = frase.trim();*/
		 String ris = "";
		 String c;
		 
		 for (int i = 0; i < frase.length(); i++){
			 c = frase.substring(i, i+1);
			
			 if(i%2==1)
				 c = c.toUpperCase();
			 ris = ris + c;
		 }
		 
		 System.out.println("Frase modificata: " + ris);
	 }
 }