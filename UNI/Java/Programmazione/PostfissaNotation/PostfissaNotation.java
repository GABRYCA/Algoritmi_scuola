package varie;

import java.util.Stack;
import java.util.EmptyStackException;
import java.util.Scanner;

public class PostfissaNotation {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		Stack<Integer> pila = new Stack<Integer>();
		System.out.println("Inserire l'espressione da esaminare");
		System.out.println("(un elemento per riga, = per terminare)");
		
		Integer sx, dx, risultato;
		String riga = in.nextLine();
		try {
			while (!riga.equals("=")) {
			//elaborazione della riga letta
			char selettore = riga.charAt(0);
			switch (selettore) {
				case '+':
				case '-':
				case '*':
				case '/':
					dx = pila.pop();
					sx = pila.pop();
					risultato = calcola(sx, dx, selettore);
					pila.push(risultato);
					break;
				default: //se non e' operazione, dev'essere un numero
					//Integer numero = new Integer(riga); //deprecated
					try {
						Integer numero = Integer.parseInt(riga);
						pila.push(numero);
					} catch(NumberFormatException e) {
						System.err.println("ERRORE: valore input non valido...riprova :-)");
					}
					break;
			}
			riga = in.nextLine();
		}
		risultato = pila.pop();
		if(pila.empty())
			System.out.println("Il risultato è " + risultato);
		else 
			System.err.println("ERRORE: espressione NON corretta :-(");
		} catch(ArithmeticException e) {
			System.err.println("ERRORE: divisione per zero");
		} catch(EmptyStackException e) {
			System.err.println("ERRORE: espressione NON corretta :-(");
		} finally {
			System.out.println("Chiusura programma...");
		}
	}
	
	private static int calcola(int opSx, int opDx, char segno) {
		int ris = 0;
		switch (segno) {
		case '+':
			ris = opSx + opDx;
			break;
		case '-':
			ris = opSx - opDx;
			break;
		case '*':
			ris = opSx * opDx;
			break;
		case '/':
			ris = opSx / opDx;
			break;
		}
		return ris;
	}
}
