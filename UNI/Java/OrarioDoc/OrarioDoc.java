package orari;

import java.io.Serializable;
import java.util.Calendar;
import java.util.GregorianCalendar;

/**
 * Un oggetto della classe <code>OrarioDoc</code> rappresenta
 * un orario, nel formato ore e minuti.
 * 
 * @author JavaCourse
 * @version 1.0
 */

public class OrarioDoc implements Serializable {
	
	//CAMPI
	private int hh;
	private int mm;
	private static char sep = ':';
	private static boolean format24 = true;
	
	//COSTRUTTORI
	/**
	 * Costruisce un oggetto che rappresenta l'orario 
	 * attuale, cioè l'orario relativo all'istante in cui 
	 * viene invocato.
	 */
	public OrarioDoc() {
		GregorianCalendar now = new GregorianCalendar();
		hh = now.get(Calendar.HOUR_OF_DAY);
		mm = now.get(Calendar.MINUTE);
	}
	
	/**
	 * Costruisce un oggetto che rappresenta l'orario, in 
	 * cui le ore sono date dal primo parametro e i minuti 
	 * dal secondo.
	 * @param hh le ore
	 * @param mm i minuti
	 */
	public OrarioDoc(int hh, int mm) {
		this.hh = hh;
		this.mm = mm;
	}
	
	/**
	 * Costruisce un oggetto che rappresenta l'orario 
	 * indicato nella stringa fornita tramite il parametro.
	 * @param s la stringa che rappresenta l'orario, 
	 * nel formato "hh:mm"
	 */
	public OrarioDoc(String s) {
		hh = Integer.parseInt(s.substring(0,2));
		mm = Integer.parseInt(s.substring(3,5));
	}

	//METODI
	
	/**
	 * Restituisce le ore
	 * @return le ore
	 */
	public int getOre() {
		return hh;
	}
	
	/**
	 * Restituisce i minuti
	 * @return i minuti
	 */
	public int getMinuti() {
		return mm;
	}
	
	public void setSeparatore(char sep) {
		this.sep = sep;
	}
	
	public static void setFormat24(boolean format) {
		format24 = format;
	}
	
	public static boolean isFormato24Attivo() {
		return format24;
	}
	
	public boolean equals(OrarioDoc altro) {
		return this.hh == altro.hh && this.mm == altro.mm;
	}
	
	public boolean equals(Object altro) {
		if(altro instanceof OrarioDoc)
			return this.equals((OrarioDoc)altro);
		else return false;
	}
	
	public boolean isMinore(OrarioDoc altro) {
		return hh < altro.hh ||
				(hh == altro.hh && mm < altro.mm);
	}
	
	public boolean isMaggiore(OrarioDoc altro) {
		return hh > altro.hh ||
				(hh == altro.hh && mm > altro.mm);
	}
	
	/**
	 * Restituisce il numero di minuti che intercorrono 
	 * tra l'orario rappresentato dall'oggetto che esegue 
	 * il metodo e quello rappresentato dall'oggetto 
	 * fornito tramite il parametro, considerati come 
	 * orari riferiti alla stessa giornata.
	 * Se l'orario rappresentato dall'oggetto che esegue 
	 * il metodo è minore di quello fornito tramite il 
	 * parametro, il risultato sarà un numero positivo; 
	 * se invece è maggiore, il risultato sarà un numero 
	 * negativo.
	 * 
	 * @param altro l'orario di cui calcolare la differenze
	 * @return l'intero che rappresenta quanto manca
	 */
	public int quantoManca(OrarioDoc altro) {
		return (altro.hh - hh) * 60 + altro.mm - mm;
	}
	
	public String toString() {
		String stringaMinuti = (mm < 10 ? "0" : "") + mm;
		if (format24)
			return String.valueOf(hh) + sep + stringaMinuti;
		else {
			int oraRisultato;
			String suff;
			if (hh == 0) {
				oraRisultato = 12;
				suff = "am";
			} else if (hh > 0 && hh < 12) {
				oraRisultato = hh;
				suff = "am";
			} else if (hh == 12) {
				oraRisultato = 12;
				suff = "pm";
			} else {
				oraRisultato = hh - 12;
				suff = "pm";
			}
			return String.valueOf(oraRisultato) + sep
			+ stringaMinuti + suff;
		}
	}
}

