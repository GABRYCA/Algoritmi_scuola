package esempiopackagelibreria;

public class Libro {
	// Campi Libri
	private String titolo;
	private String autore;
	private int numeroPagine;
	private Genere[] generi;
	private boolean disponibile;

	public Libro(String titolo, String autore, int numeroPagine, Genere[] generi, boolean disponibile) {
		this.titolo = titolo;
		this.autore = autore;
		this.numeroPagine = numeroPagine;
		this.generi = generi;
		this.disponibile = disponibile;
	}

	public Libro(String titolo) {
		this.titolo = titolo;
		autore = "Non specificato";
		numeroPagine = 0;
		generi = null;
		disponibile = false;
	}

	public String getTitolo() {
		return titolo;
	}

	public void setTitolo(String titolo) {
		this.titolo = titolo;
	}

	public String getAutore() {
		return autore;
	}

	public int getNumeroPagine() {
		return numeroPagine;
	}

	public void setNumeroPagine(int numeroPagine) {
		this.numeroPagine = numeroPagine;
	}

	public Genere[] getGeneri() {
		return generi;
	}

	public void setGeneri(Genere[] generi) {
		this.generi = generi;
	}

	public boolean isDisponibile() {
		return disponibile;
	}

	public void setDisponibile(boolean disponibile) {
		this.disponibile = disponibile;
	}

	public void setAutore(String autore) {
		this.autore = autore;
	}

	private String stampaGeneri() {
		String risultatoGeneri  = "";
		for(Genere gen: generi) {
			risultatoGeneri += gen + " ";
		}
		return risultatoGeneri;
	}

	@Override
	public String toString() {
		return "Libro " + titolo + " di " + autore + " numero di pagine: " + numeroPagine + " generi: "
				+ stampaGeneri();
	}

}
