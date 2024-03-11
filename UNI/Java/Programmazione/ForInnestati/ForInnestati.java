public class ForInnestati {

	public static void main(String[] args) {
		int cont = 0;
		for(int i=1; i<=10; i++){
			System.out.print(i + " > ");
			for(int j=1; j<=10; j++, cont++)
				System.out.print(j + " ");
			System.out.println();
		}
		
		System.out.println("cont > "+cont);
		
		cont = 0;
		for(int i=1; i<=10; i++){
			System.out.print(i + " > ");
			for(int j=1; j<=10; j++) {
				System.out.print(j + " > ");
				for(int k=1; k<=10; k++, cont++)
					System.out.print(k + " ");
				System.out.println();
			}	
			System.out.println();
		}
		System.out.println("cont > "+cont);	
		
		//esempio con l'alfabeto
		for(char c='A'; c <= 'Z'; c++) {//eseguito 26x26 volte = 676
			for(char h='z'; h >= 'a'; h--)
				System.out.print("" + (char)c + (char)h + " ");
			System.out.println();
		}
		
		//dare dei valori a n e m
		for(int i=0; i<=n; i++) //eseguito n+1 volte
			for(int j=m; j>=n; j--) //eseguito m-n+1 volte
				System.out.print(i + " " + j); //TOTALE (n+1)(m-n+1) volte
	}
}