package dato;

public class ClienteDati {

	public static void main(String[] args) {
		Dati iDati = new Dati();
		iDati.aggiungiDato("potipu", "info potipu");
		iDati.aggiungiDato("patagarru", "info patagarru");
		iDati.aggiungiDato("svicolone", "info svicolone");
		String chiaveDaCercare = "svicolone";
		if (iDati.esisteDato(chiaveDaCercare)) {
			String num = iDati.trovaDato(chiaveDaCercare);
			System.out.println("Info di " + chiaveDaCercare + " e` " + num);
		} else {
			System.out.println(chiaveDaCercare + " non trovato ");
		}
	}
}
