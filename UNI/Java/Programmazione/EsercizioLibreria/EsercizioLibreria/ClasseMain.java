package esempiopackagelibreria;

import java.util.LinkedList;

public class ClasseMain {
	
	public static void main(String[] args) {
		Genere[] generi1 = {Genere.AVVENTURA, Genere.ROMANZO};
		Libro libro1 = new Libro("20000 Leghe sotto i mari", "Jack", 150, generi1, true);
		// System.out.println(libro.toString()); 
		
		Libreria libreria = new Libreria();
//		libreria.aggiungiLibro(libro1);
//		libreria.rimuoviLibroTitolo("20000 Leghe sotto i mari");
		
		LinkedList<Libro> libri = new LinkedList<Libro>();
		libri.add(libro1);
		Libreria libreriaPiena = new Libreria(libri);
		System.out.println(libreriaPiena.toString());
	}
}
