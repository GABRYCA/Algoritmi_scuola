package Esercizio1;

import Esercizio1.Concorrente.MatConcorrente;
import Esercizio1.ConcorrenteMigliorato.MatConcorrenteMigliorato;
import Esercizio1.Sequenziale.Sequenziale;

public class Main {

	public static void main(String[] args) {
		System.out.println("Avvio programma...");
		System.out.println("Avvio matrice concorrente: ");
		MatConcorrente matConc = new MatConcorrente();
		
		System.out.println("Avvio matrice concorrente migliorata: ");
		MatConcorrenteMigliorato matConcMigliorato = new MatConcorrenteMigliorato();
		
		System.out.println("Avvio matrice sequenziale: ");
		Sequenziale sequenziale = new Sequenziale();
		
		System.out.println("Fine!");
	}

}
