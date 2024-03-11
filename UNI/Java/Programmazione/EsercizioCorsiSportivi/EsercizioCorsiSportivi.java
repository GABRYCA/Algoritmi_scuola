import java.util.Scanner;

public class EsercizioCorsiSportivi {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		CorsiSportivi[] array = CorsiSportivi.values();
		for (CorsiSportivi corsisportivi: array)
			System.out.println(corsisportivi.ordinal()+1 +" > " + corsisportivi.name());
		
		System.out.print("Inserire il codice di un corso a scelta per avere piu' informazioni (TUTTI per visualizzare tutti i corsi, STOP per terminare) > ");
		
		String scelta = in.nextLine();
		scelta = scelta.toUpperCase();
		
		while(!scelta.equals("STOP")) {
			switch(scelta){
				case "1": System.out.println(schemaCorso(CorsiSportivi.TENNIS));
					break;
				case "2": System.out.println(schemaCorso(CorsiSportivi.BASKET));
					break;
				case "3": System.out.println(schemaCorso(CorsiSportivi.PALLAVOLO));
					break;
				case "4": System.out.println(schemaCorso(CorsiSportivi.CALCIO));
					break;
				case "5": System.out.println(schemaCorso(CorsiSportivi.BASEBALL));
					break;
				case "6": System.out.println(schemaCorso(CorsiSportivi.NUOTO));
					break;
				case "7": System.out.println(schemaCorso(CorsiSportivi.RUGBY));
					break;
				case "8": System.out.println(schemaCorso(CorsiSportivi.HOCKEY));
					break;
				case "TUTTI": 
					for (CorsiSportivi corsisportivi: array)
						System.out.println(schemaCorso(corsisportivi));
					break;
				default: System.out.println("Corso inserito NON valido");
			}
			System.out.print("\nInserire il codice di un corso a scelta per avere piu' informazioni (TUTTI per visualizzare tutti i corsi, STOP per terminare) > ");
			scelta = in.nextLine();
			scelta = scelta.toUpperCase();
		}
	}
	
	public static String schemaCorso(CorsiSportivi corso) {
		String ris = "";
		ris = corso.ordinal()+1 + " " + corso.name() + " " + corso.getOrario();
		return ris;
	}
}