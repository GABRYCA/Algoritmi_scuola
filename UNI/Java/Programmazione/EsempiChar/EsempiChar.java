
public class EsempiChar {

	public static void main(String[] args){
	
		//stampa l'alfabeto minuscolo in ordine
		for(char c = 'a'; c <= 'z'; c++)
			System.out.print(c+" ");
		
		System.out.println();
		for(int c = 'a'; c <= 'z'; c++)
			System.out.print(c+" ");
		
		System.out.println();
		for(int c = 'a'; c <= 'z'; c++)
			System.out.print((char)c+" ");
		
		System.out.println();
		//stampa l'alfabeto minuscolo al contrario
		for(char c = 'z'; c >= 'a'; c--)
			System.out.print(c+" ");
		
		//CONDIZIONI
		char c;
		
		//la variabile c contiene una lettera maiuscola
		c >= 'A' && c <= 'Z'
		c >= 65 && c <= 90
		//la variabile c contiene una lettera minuscola
		c >= 'a' && c <= 'z'
		c >= 97 && c <= 122
		//la variabile c NON contiene una lettera maiuscola
		c < 'A' || c > 'Z'
		//la variabile c NON contiene una lettera minuscola
		c < 'a' || c > 'z'
		//la variabile c NON contiene una lettera
		(c < 'A' || c > 'Z') && (c < 'a' || c > 'z')
		//la variabile c contiene una lettera
		(c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
	}
}
