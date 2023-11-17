package esempiopackagelibreria;

import java.util.LinkedList;

public class Biblioteca extends GestioneLibri {

	public Biblioteca(LinkedList<Libro> libri) {
		this.libri = libri;
	}

	public Biblioteca() {
		libri = new LinkedList<Libro>();
	}

	@Override
	public String toString() {
		if (libri != null && libri.size() > 0) {
			String risultato = "";
			risultato += "Libri in biblioteca: \n";
			for (Libro lib : libri)
				risultato += lib.toString() + "\n";
			return risultato;
		} else
			return "Biblioteca vuota";
	}

	@Override
	public void richiediLibro(String titolo) {
		if (!(libri != null && libri.size() > 0)) {
			System.out.println("Libreria vuota");
			return;
		}

		titolo = titolo.toLowerCase();
		boolean esiste = false;
		for (Libro lib : libri) {
			if (lib.getTitolo().toLowerCase().equals(titolo)) {
				lib.setDisponibile(false);
				esiste = true;
				break;
			}
		}
		System.out.println(esiste ? "Libro dato in prestito" : "Libro non disponibile");
	}

}
