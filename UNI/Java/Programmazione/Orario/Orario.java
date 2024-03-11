package orari;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Orario {
	
	//CAMPI STATICI
	private static char separatore = ':';
	private static boolean formato24 = true;
	
	//CAMPI
	private int ore;
	private int min;
	
	//COSTRUTTORI
	public Orario(int hh, int mm) {
		ore = hh;
		min = mm;
	}
	
	public Orario() {
		GregorianCalendar adesso = new GregorianCalendar();
		ore = adesso.get(Calendar.HOUR_OF_DAY);
		min = adesso.get(Calendar.MINUTE);
	}
	
	public Orario(String s) { //11:37 - 9:12 - 09:12
		ore = Integer.parseInt(s.substring(0,2));
		min = Integer.parseInt(s.substring(3,5));
	}
	
	//METODI
	public int getOre() {
		return ore;
	}

	public int getMin() {
		return min;
	}
	
	public static char getSeparatore() {
		return separatore;
	}
	
	public static void setSeparatoreTo(char ch) {
		separatore = ch;
	}
	
	public static boolean isFormato24Attivo() {
		return formato24;
	}
	
	public static void setFormato24(boolean b) {
		formato24 = b;
	}
		
	public boolean equals(Orario altro) {
		return this.ore == altro.ore && this.min == altro.min;
	}
		
	public boolean isMinore(Orario altro) {
		return this.ore < altro.ore ||
		(this.ore == altro.ore && this.min < altro.min);
	}
	
	public boolean isMaggiore(Orario altro) {
		return this.ore > altro.ore ||
		(this.ore == altro.ore && this.min > altro.min);
	}
	
	public int quantoManca(Orario altro) {
		return (altro.ore - this.ore) * 60 + altro.min - this.min;
	}

	public String toString() {
		String risultato;
		String stringaMinuti = (min < 10 ? "0" : "") + min;
		if (formato24)
			risultato = String.valueOf(ore) + separatore + stringaMinuti;
		else {
			int oraRisultato;
			String suff;
			if (ore == 0) {
				oraRisultato = 12;
				suff = "am";
			} else if (ore > 0 && ore < 12) {
				oraRisultato = ore;
				suff = "am";
			} else if (ore == 12) {
				oraRisultato = 12;
				suff = "pm";
			} else {
				oraRisultato = ore - 12;
				suff = "pm";
			}
			risultato = String.valueOf(oraRisultato) + separatore + stringaMinuti + suff;
		}
		return risultato;
	}
}
