package esercizivari;

import java.util.Scanner;

public class OperazioniStringa {
	private static Scanner in = new Scanner(System.in);

	public static void main(String[] args) {
		String fraseInput = "";
		System.out.println("Inserisci una frase");
		boolean flag = true;
		do {
			fraseInput = in.nextLine();
			for (int i = 0; i < fraseInput.length(); i++) {
				char c = fraseInput.charAt(i);
				if (Character.isDigit(c)) {
					System.out.println("Inserisci una frase senza numeri");
					flag = true;
					break;
				} else
					flag = false;
			}
		} while (flag);

		menu(fraseInput);
	}

	private static void menu(String fraseInput) {
		int comando = 0;
		while (comando < 1 || comando > 3) {
			System.out.println("Scegli un comando tra:\n1) Sostituisci un carattere"
					+ "\n2) Trova la prima occorrenza di un carattere\n3) Esci");
			try {
				comando = in.nextInt();
				if (comando < 1 || comando > 3)
					System.out.println("Comando errato!");
			} catch (Exception e) {
				System.out.println("Comando errato!");
				in.nextLine();
			}
			in.nextLine();

			switch (comando) {
			case 1:
				fraseInput = sostituisciCarattere(fraseInput);
				break;
			}
		}
	}

	private static String sostituisciCarattere(String fraseInput) {
		boolean flag = true;
		char vecchioCar = ' ';
		do {
			System.out.println("Inserisci carattere da sostituire in \"" + fraseInput + "\"");
			vecchioCar = in.nextLine().charAt(0);
			if (fraseInput.contains(Character.toString(vecchioCar)))
				flag = false;
			else
				System.out.println("Carattere non valido");
		} while (flag);

		char nuovoCar = ' ';
		do {
			System.out.println("Inserire nuovo carattere: ");
			nuovoCar = in.nextLine().charAt(0);
			if (!Character.isDigit(nuovoCar))
				break;
			else
				System.out.println("Carattere non valido");
		} while (true);

		String vecchiaFrase = fraseInput;
		fraseInput = fraseInput.replace(vecchioCar, nuovoCar);
		System.out.println("\"" + vecchiaFrase + "\"" + "--> \"" + fraseInput + "\"");
		return fraseInput;
	}
}
