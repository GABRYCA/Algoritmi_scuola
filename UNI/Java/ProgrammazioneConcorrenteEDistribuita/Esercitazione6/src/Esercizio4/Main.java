package Esercizio4;

import Esercizio4.ReadersWriterNoStarvation.ReadersWriterNoStarvation;
import Esercizio4.ReadersWriterPossibleStarvation.ReadersWriterPossibleStarvation;

public class Main {

	public static void main(String[] args) {
		System.out.println("Avviando esercizio ReadersWriter...");
		
		System.out.println("Avviando variante No Starvation...");
		
		ReadersWriterNoStarvation readersWriterNoStarvation = new ReadersWriterNoStarvation();
		
		System.out.println("Fine No Starvation!");
		
		System.out.println("Avviando variante Possibile Starvation...");
		
		ReadersWriterPossibleStarvation readersWriterPossibleStarvation = new ReadersWriterPossibleStarvation();
		
		System.out.println("Fine Possibile Starvation!");
		
		System.out.println("Fine programma!");
	}

}
