/* Un gruppo di x bambini, il giorno di Halloween, decide di uscire per andare 
a fare "dolcetto o scherzetto". Il valore di x deve essere passato come parametro
al metodo main. Scrivere un'applicazione in grado di calcolare il
numero di risposte "dolcetto" o "scherzetto" ricevuto dalle persone 'importunate'.
Nessuna informazione deve essere inserita dall'utente: è il computer stesso che 
attribuisce casualmente una risposta ("dolcetto o scherzetto") per ogni bambino.
Al termine della simulazione, comunicare in output il numero di "dolcetto" e di 
"scherzetto" e, in caso di "dolcetto" la media dei dolci ricevuti dal totale dei
bambini.
*/
import java.util.Random;

public class Halloween {

	public static void main(String[] args) {
		
		Random ran = new Random();
		
		//int dim = Integer.parseInt(args[0];
		//int[] bambini = new int[dim];
		int[] bambini = new int[Integer.parseInt(args[0])]; //inserire controllo sull'input dell'utente
		int contDolcetto = 0;
		
		for(int i=0; i < bambini.length; i++) {
			System.out.println("Bambino "+ (i+1) + " Dolcetto o Scherzetto?");
			boolean risposta = ran.nextBoolean();
			if(risposta) {
				bambini[i] = ran.nextInt(9)+1;
				contDolcetto++;
				System.out.println("Dolcetto! Dolcetti ricevuti > "+bambini[i]+"\n");
			} else 
				System.out.println("Scherzetto!\n");
		}
		double sommaDolcetti = 0;
		for(int i=0; i < bambini.length; i++)
			sommaDolcetti += bambini[i];
		//double mediaDolcetti = sommaDolcetti/bambini.length;
		
		System.out.println("Numero \"Dolcetto\" > "+contDolcetto);
		System.out.println("Media Dolcetti ricevuti > "+(sommaDolcetti/bambini.length));
		System.out.println("Numero \"Scherzetto\" > "+(bambini.length-contDolcetto));
	}
}
		