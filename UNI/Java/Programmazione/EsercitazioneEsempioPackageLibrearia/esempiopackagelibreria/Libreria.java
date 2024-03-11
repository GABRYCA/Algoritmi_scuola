package esempiopackagelibreria;

import java.util.Date;
import java.util.LinkedList;

public class Libreria extends GestioneLibri{

	public Libreria(LinkedList<Libro> libri) {
		this.libri = libri;
	}

	public Libreria() {
		libri = new LinkedList<Libro>();
	}

	// Metodi Libreria

	@Override
	public String toString() {
		String risultato = "";
		if (libri != null && libri.size() > 0) {
			risultato += "Elenco libri:\n";
			for (Libro lib : libri)
				risultato += lib.toString() + "\n";
		} else // Se la libreria è vuota
			System.out.println("Libreria vuota");
		return risultato;
	}
	
	@Override
	public void richiediLibro(String titolo) {
		if(!(libri != null && libri.size()>0)) {
			System.out.println("Libreria vuota");
			return;
		}
		
		titolo = titolo.toLowerCase();
		boolean esiste = false;
		
		for(Libro lib:libri) {
			if(lib.getTitolo().toLowerCase().equals(titolo)) {
				esiste = true;
				libri.remove(lib);
				break;
			}
		}
		System.out.println(esiste?"Libro venduto":"Libro non disponibile");
	}
}
