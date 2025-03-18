package Esercizio3;

import Esercizio3.Basic.Parallelo;
import Esercizio3.Graphical.Graphical;
import Esercizio3.Migliorato.Migliorato;

public class Main {

	public static void main(String[] args) {
		System.out.println("Avvio esercizio labirinti...");
		System.out.println("Labirinto Basic: ");
		Parallelo parallelo = new Parallelo();
		
		System.out.println("Labirinto Graphical: ");
		Graphical graphical = new Graphical();
		
		System.out.println("Labirinto migliorato: ");
		Migliorato migliorato = new Migliorato();
		
		System.out.println("Fine!");
	}

}
