package Esercizio2;

import Esercizio2.Concorrente.BinConcorrente;
import Esercizio2.ConcorrenteMigliorato.BinConcorrenteMigliorato;
import Esercizio2.Sequenziale.BinSequenziale;

public class Main {

	public static void main(String[] args) {
		System.out.println("Ricerche e alberi binari: ");
		System.out.println("Avviando ricerca sequenziale: ");
		BinSequenziale sequenziale = new BinSequenziale();
		
		System.out.println("Avviando ricerca concorrente: ");
		BinConcorrente concorrente = new BinConcorrente();
		
		System.out.println("Avviando ricerca concorrente migliorata: ");
		BinConcorrenteMigliorato concorrenteMigliorato = new BinConcorrenteMigliorato();
		
		System.out.println("Fine!");
	}

}
