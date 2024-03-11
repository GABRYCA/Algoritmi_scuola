package esempiopackagelibreria;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.LinkedList;
import java.util.Scanner;

import esempiopackagelibreria.Rivista.SottoGenere;

public class LibreriaMain {
	private static Scanner in = new Scanner(System.in);

	public static void main(String[] args) {
		Libreria lib = new Libreria();
		menu(lib);
	}

	private static void menu(Libreria lib) {
		System.out.println("Inserisci operazione: ");
		System.out.println("0) Mostra libri/riviste della libreria\n1) Inserisci libro\n"
				+ "2) Inserisci rivista\n3) Elimina libri per Titolo\n4) Elimina libri di un autore\n"
				+ "5) Elimina libri con meno di 50 pagine o riviste con meno di 20 pagine\n"
				+ "6) Mostra libri di un autore\n7) Mostra riviste più recenti\n"
				+ "8) Elimina riviste entro una data\n9) Esci");
		System.out.println("--->");

		int scelta = 0;
		do {
			scelta = in.nextInt();
			if (scelta < 0 || scelta > 9)
				System.out.println("Valore non valido!!\nInserire un nuovo numero.");
		} while (scelta < 0 || scelta > 9);
		in.nextLine();
		switch (scelta) {
		case 0:
			System.out.println(lib.toString());
			break;
		case 1:
			lib.aggiungiLibro(inserisciLibro(true));
			break;
		case 2:
			lib.aggiungiLibro(inserisciLibro(false));
			break;
		case 3:
			lib.rimuoviLibroTitolo(verificaTitolo(lib));
			break;
		case 4:
			lib.rimuoviLibroAutore(verificaAutore(lib));
			break;
		case 5:
			lib.rimuoviLibroPagine();
			break;
		case 6:
			mostraLibriAutore(lib);
			break;
		case 7:
			mostraRivisteRecenti(lib);
			break;
		case 8:
			eliminaRivisteRecenti(lib);
			break;
		case 9:
			System.err.println("Chiusura app");
			break;
		}
		if(scelta != 9)
			menu(lib);
	}

	private static Libro inserisciLibro(boolean tipo) {
		System.out.println("Inserisci il titolo del" + (tipo ? " libro" : "la rivista: "));
		String titolo = in.nextLine();

		System.out.println("Inserisci l'autore: ");
		String autore = in.nextLine();

		String elencoGeneri = "";
		Genere[] tuttiGeneri = Genere.values();
		for (Genere gen : tuttiGeneri)
			elencoGeneri += gen + " ";

		System.out.println("Inserisci i generi(" + elencoGeneri + ")e premi invio per terminare");

		String inputGenere = "";
		LinkedList<Genere> generi = new LinkedList<Genere>();
		boolean flag = true;
		do {
			inputGenere = in.nextLine();
			if (inputGenere.isEmpty())
				flag = false;
			else if (esisteGenere(inputGenere.toUpperCase()))
				generi.add(Genere.valueOf(inputGenere.toUpperCase()));
			else
				System.out.println("Il genere non esiste");
		} while (flag);

		Genere[] generiArray = new Genere[generi.size()];
		for (int i = 0; i < generiArray.length; i++)
			generiArray[i] = generi.get(i);

		int numeroPagine = 0;
		System.out.println("Inserisci numero di pagine: ");
		do {
			numeroPagine = in.nextInt();
			if (numeroPagine <= 0)
				System.out.println("Il numero di pagine deve essere > 0\nInserisci di nuovo il numero di pagine: ");
		} while (numeroPagine <= 0);

		in.nextLine();

		boolean disponibile = false;
		char c;
		do {
			System.out.println("Inserisci disponibilita' (si/no): ");
			c = Character.toLowerCase(in.nextLine().charAt(0));
			if (c == 's')
				disponibile = true;
			else if (c == 'n')
				disponibile = false;
			else
				System.out.println("Valore inserito errato.");
		} while (!(c == 's' || c == 'n'));

		if (!tipo) {
			elencoGeneri = "";
			SottoGenere[] sottoGeneri = SottoGenere.values();
			for (SottoGenere sog : sottoGeneri) {
				elencoGeneri += sog + " ";
			}

			boolean sogEsiste = false;
			inputGenere = "";
			do {
				System.out.println("Inserisci tipologia di rivista (" + elencoGeneri + ")");
				inputGenere = in.nextLine().trim().toUpperCase();
				for (SottoGenere sog : SottoGenere.values())
					if (sog.toString().equals(sottoGeneri)) {
						sogEsiste = true;
						break;
					}
				System.out.println("Sottogenere non corretto");
			} while (!sogEsiste);

			Date data = inputData();

			return new Rivista(titolo, autore, numeroPagine, generiArray, disponibile, SottoGenere.valueOf(inputGenere),
					data);
		} else
			return new Libro(titolo, autore, numeroPagine, generiArray, disponibile);

	}

	private static boolean esisteGenere(String genere) {
		boolean esiste = false;
		for (Genere gen : Genere.values()) {
			if (gen.toString().equals(genere)) {
				esiste = true;
				break;
			}
		}
		return esiste;
	}

	private static Date inputData() {
		String formato = "dd-mm-yyyy";
		System.out.println("Inserisci data (" + formato + ")");
		String dataInput = in.nextLine().trim().toLowerCase();

		Date data = new Date();
		try {
			data = new SimpleDateFormat(formato).parse(dataInput);
		} catch (ParseException e) {
			e.printStackTrace();
		}

		return data;
	}

	private static String verificaTitolo(Libreria lib) {
		String titolo = "";
		boolean flag = true;

		do {
			System.out.println("Inserisci il titolo del libro: ");
			titolo = in.nextLine().trim();
			for (Libro libro : lib.getLibri()) {
				if (libro.getTitolo().toLowerCase().equals(titolo.toLowerCase())) {
					flag = false;
				}
			}
			if (flag)
				System.out.println("Titolo inesistente");
		} while (flag);
		return titolo;
	}

	private static String verificaAutore(Libreria lib) {
		String autore = "";
		boolean flag = true;

		do {
			System.out.println("Inserisci l'autore del libro: ");
			autore = in.nextLine().trim();
			for (Libro libro : lib.getLibri()) {
				if (libro.getAutore().toLowerCase().equals(autore.toLowerCase())) {
					flag = false;
				}
			}
			if (flag)
				System.out.println("Autore inesistente");
		} while (flag);
		return autore;
	}

	private static void mostraLibriAutore(Libreria lib) {
		Libro[] libri = lib.libriAutore(verificaAutore(lib));
		for (Libro libro : libri) {
			System.out.println(libro.toString());
			System.out.println("--------------------------------------------");
		}
	}

	private static void mostraRivisteRecenti(Libreria lib) {
		Date data = inputData();
		Rivista[] riviste = lib.rivisteRecenti(data);
		if (riviste != null)
			for (Rivista riv : riviste)
				if (riv != null)
					System.out.println(riv.toString());
	}
	
	private static void eliminaRivisteRecenti(Libreria lib) {
		Date data = inputData();
		lib.eliminaRivisteData(data);
	}
}
