package esempiopackagelibreria;

import java.util.Date;
import java.util.LinkedList;

public abstract class GestioneLibri {
	public LinkedList<Libro> libri;

	public abstract void richiediLibro(String titolo);
	
	public void aggiungiLibro(Libro libro) {
		libri.add(libro);
		System.out.println("Il libro \"" + libro.getTitolo() + "\" inserito");
	}

	public void rimuoviLibroTitolo(String titolo) {
		boolean esiste = false;
		titolo = titolo.trim();
		for (int i = 0; i < libri.size(); i++) {
			if (libri.get(i).getTitolo().equals(titolo)) {
				libri.remove(i);
				esiste = true;
			}
			if (esiste)
				System.out.println("Il libro \"" + titolo + "\" e' stato rimosso");
			else
				System.out.println("Il libro \"" + titolo + "\" non e' stato rimosso");
		}
	}

	public void rimuoviLibroAutore(String autore) {
		boolean esiste = false;
		autore = autore.trim();
		for (int i = 0; i < libri.size(); i++) {
			if (libri.get(i).getAutore().equals(autore)) {
				esiste = true;
				libri.remove(i);
			}
		}
		if (esiste)
			System.out.println("I libri di \"" + autore + "\" sono stati rimossi");
		else
			System.out.println("I libri di \"" + autore + "\" non sono stati rimossi");
	}

	public void rimuoviLibroPagine() {
		int pagineLibro = 50;
		int pagineRivista = 20;
		int contatore = 0;
		for (int i = 0; i < libri.size(); i++) {
			if (libri.get(i).getNumeroPagine() <= pagineLibro && libri.get(i) instanceof Libro
					|| libri.get(i).getNumeroPagine() <= pagineRivista && libri.get(i) instanceof Rivista) {
				libri.remove(i);
				contatore++;
			}
		}
		System.out.println(contatore > 0 ? "Rimossi libri con meno di 50 pagine o riviste con meno di 20"
				: "Non sono stati trovati libri con meno di 50 pagine o riviste con meno di 20");
	}

	public Libro[] libriAutore(String autore) {
		if (libri == null && libri.size() <= 0)
			return null;
		int contatore = 0;
		for (Libro lib : libri) {
			if (lib.getAutore().toLowerCase().equals(autore.toLowerCase())) {
				contatore++;
			}
		}
		Libro[] risultato = new Libro[contatore];

		contatore = 0;
		for (Libro lib : libri) {
			if (lib.getAutore().toLowerCase().equals(autore.toLowerCase())) {
				risultato[contatore++] = lib;
			}
		}
		return risultato;
	}

	public Rivista[] rivisteRecenti(Date data) {
		final int totRiviste = 5;
		Rivista[] risultato = new Rivista[totRiviste];
		if (libri == null && libri.size() <= 0)
			return null;

		int i = 0;
		for (Libro riv : libri) {
			if (i >= totRiviste)
				break;
			if (riv instanceof Rivista && ((Rivista) riv).getDataPubblicazione().compareTo(data) < 0)
				risultato[i++] = (Rivista) riv;
		}
		return risultato;
	}

	public void eliminaRivisteData(Date data) {
		if (libri == null && libri.size() <= 0) {
			System.out.println("Libreria vuota");
			return;
		} else {
			for (Libro riv : libri) {
				if (riv instanceof Rivista && ((Rivista) riv).getDataPubblicazione().compareTo(data) < 0)
					libri.remove(riv);
			}
		}
	}

	public LinkedList<Libro> libriDisponibili(boolean disponibili) {
		// se disponibile = true => stampa libri disponibili
		// se disponibile = false => stampa libri non disponibili
		LinkedList<Libro> risultato = new LinkedList<Libro>();
		if (libri == null && libri.size() <= 0)
			return null;

		for (Libro lib : libri) {
			if (lib.isDisponibile() && disponibili)
				risultato.add(lib);
			else if (!lib.isDisponibile() && !disponibili)
				risultato.add(lib);
		}
		return risultato;
	}
}
