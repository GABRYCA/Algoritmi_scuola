/* implementare un'applicazione in grado di calcolare i giorni mancanti alla
fine dell'anno */
import java.util.GregorianCalendar;
import java.util.Calendar;
//oppure
import prog.utili.Data;
import prog.utili.MeseDellAnno;

public class GiorniMancantiFineAnno {
	
	public static void main(String[]args) {
		//definizione del giorno corrente
		GregorianCalendar today = new GregorianCalendar();
		//oppure 
		//Data oggi = new Data();
		Data oggi = new Data(28,2,2023);
		
		//estrazione di giorno/mese/anno dal giorno corrente
		System.out.println("OGGI > " + today.toString());
		System.out.print("giorno > " + today.get(Calendar.DAY_OF_MONTH));
		System.out.print(" mese > " + today.get(Calendar.MONTH));
		System.out.println(" anno > " + today.get(Calendar.YEAR));
		
		System.out.println("OGGI > " + oggi.toString());
		System.out.print("giorno > " + oggi.getGiorno());
		System.out.print(" mese > " + oggi.getMese());
		System.out.println(" anno > " + oggi.getAnno());
		
		int giorno = oggi.getGiorno();
		int mese = oggi.getMese();
		int anno = oggi.getAnno();
		
		//calcolo dei giorni mancanti tra oggi e la fine dell'anno
		//1. giorni mancanti alla fine del mese corrente
		MeseDellAnno meseCorrente = oggi.getMeseDellAnno();
		int giorniMeseCorrente = meseCorrente.numeroGiorni(anno);
		int giorniMancantiFineMeseCorrente = giorniMeseCorrente - giorno;
		
		System.out.println("Mese corrente name > " + meseCorrente.name());
		System.out.println("Mese corrente ordinal > " + meseCorrente.ordinal());
		System.out.println("Mese corrente toString > " + meseCorrente.toString());
		System.out.println("Giorni mancanti alla fine del mese > " + giorniMancantiFineMeseCorrente);
		
		//2. somma dei giorni dei mesi successivi a quello corrente
		int giorniMancantiFineAnno = giorniMancantiFineMeseCorrente;
		
		if(meseCorrente != MeseDellAnno.DICEMBRE){
			switch(meseCorrente.successivo()) {
				case GENNAIO: //non viene mai eseguito
					giorniMancantiFineAnno += 31;
				case FEBBRAIO:
					giorniMancantiFineAnno += oggi.isInAnnoBisestile()? 29:28;
				case MARZO:
					giorniMancantiFineAnno += 31;
				case APRILE:
					giorniMancantiFineAnno += 30;
				case MAGGIO:
					giorniMancantiFineAnno += 31;
				case GIUGNO:
					giorniMancantiFineAnno += 30;
				case LUGLIO:
					giorniMancantiFineAnno += 31;
				case AGOSTO:
					giorniMancantiFineAnno += 31;
				case SETTEMBRE:
					giorniMancantiFineAnno += 30;
				case OTTOBRE:
					giorniMancantiFineAnno += 31;
				case NOVEMBRE:
					giorniMancantiFineAnno += 30;
				case DICEMBRE:
					giorniMancantiFineAnno += 31;
			}
		}
		System.out.println("Giorni mancanti alla fine dell'anno > " + giorniMancantiFineAnno);
	}
}