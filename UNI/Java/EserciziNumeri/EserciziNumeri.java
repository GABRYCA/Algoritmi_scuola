import java.util.Scanner;

public class EserciziNumeri {
	
	public static void main(String[] args){
	
		//scambio delle variabili
		int a = 2;
		int b = 3;
		
		//NO
		/*a = b;
		b = a;*/
		
		int tmp = a;
		a = b;
		b = tmp;
		
/* implementare un'applicazione che continua ad acquisire un intero fino
a quando l’utente inserisce zero, quindi stampa il minimo
tra i valori inseriti (zero escluso) */

		Scanner in = new Scanner(System.in);
		
		System.out.print("CALCOLO MINORE\nInserire un numero > ");
		int num = in.nextInt();
		//boolean continua = (num != 0);
		int min = num;
		
		while(num != 0) {
			if(num < min)
				min = num;
			
			System.out.print("Inserire un numero > ");
			num = in.nextInt();
			//if(num == 0)
				//continua = false;
		}
		System.out.print("Valore minimo inserito > " + min);
		
		
/* implementare un'applicazione che riceve in ingresso una sequenza 
di interi positivi terminata da uno zero e calcoli come risultato la
media dei valori (escludendo lo zero).
Ogni volta che viene inserito un numero, il programma deve controllare
che sia maggiore o uguale a zero e, nel caso non lo sia, avvisare
l’utente dell’errore e riacquisire un nuovo numero */

		System.out.print("\nCALCOLO MEDIA\nInserire un numero > ");
		num = in.nextInt();
		double media, somma = 0;
		int cont=0;
		
		while(num != 0) {
			if(num > 0) {
				somma += num;
				cont = cont + 1;
			} else {
				System.out.println("ERRORE: valore negativo -> re-inserire!");
			}
			System.out.print("Inserire un numero > ");
			num = in.nextInt();
		}
		if(cont > 0) {
			media = somma/cont;
			System.out.print("Media dei valori inseriti > " + media);
		} else 
			System.out.println("ERRORE: nessun valore inserito!");
		
/* implementare un'applicazione che calcoli la lunghezza della circonferenza
e l'area del cerchio, dato il raggio */
		
		System.out.print("\nRAGGIO\nInserire un numero > ");
		double raggio = in.nextDouble();
		if(raggio >= 0) {
			double circonferenza = 2 * Math.PI * raggio;
			//double cerchio = Math.PI * raggio * raggio;
			double cerchio = Math.PI * Math.pow(raggio,2);
			System.out.println("Lunghezza circonferenza > " + circonferenza);
			System.out.println("Area del cerchio > " + cerchio);
		} else 
			System.out.println("ERRORE: raggio non valido!");
		
/* calcolo del fattoriale di un numero */
		System.out.print("\nFATTORIALE\nInserire un numero > ");
		num = in.nextInt();
		int f = num;
		
		for(int i=num-1; i > 0; i--) //opp. i>=1, i>1
			f = f*i; //occorre considerare il caso num = 0
			
		System.out.println("Fattoriale di "+num+ " > " + f);
		
		//oppure
		f = 1;
		for(int i=1; i<=num; i++)
			f = f*i;
		
		System.out.println("Fattoriale di "+num+ " > " + f);
	}
}