package varie;

public class Arcobaleno {

	private String[] colori;
	private int numeroColori; //contatore dei colori inseriti
	
	public Arcobaleno(int max) {
		this.colori = new String[max];
		this.numeroColori = 0;
	}
	
	public void aggiungiColore(String colore) { //aggiunge un colore all'array
		if((numeroColori < colori.length) && cercaColore(colore) == -1)
			colori[numeroColori++] = colore;
	}
	
	public void rimuoviColore(String colore) { //elimina il colore dall'array
		int pos = cercaColore(colore);
		if(pos != -1) {
			colori[pos] = colori[numeroColori-1];
			colori[numeroColori-1] = null;
			numeroColori--;
		}
	}
	
	private int cercaColore(String colore) {
		for(int i=0; i<colori.length; i++)
			if(colori[i] != null && colori[i].equals(colore))
				return i;
		return -1;
	}
	
	public int coloriVisibili() { //restituisce il numero di colori presenti nell'array
		return numeroColori;
	}
	
	public String toString() {
		String ris = "Arcobaleno [ ";
		for(String tmp: colori)
			ris += tmp+" ";
		return ris += "]";
	}
	
}
