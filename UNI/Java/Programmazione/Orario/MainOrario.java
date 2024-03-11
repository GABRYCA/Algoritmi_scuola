package orari;

public class MainOrario {

	public static void main(String[] args) {
		Orario orario1 = new Orario();
		Orario orario2 = new Orario(11,44);
		Orario orario3 = new Orario("11:45");
		
		System.out.println(orario1);
		System.out.println(orario2);
		System.out.println(orario3.toString());
		
		if (orario2.isMinore(orario1)) {
			System.out.println("Dalle " + orario2.toString() + " di oggi sono passati " +
			orario2.quantoManca(orario1) + " minuti");
		} else if (orario2.isMaggiore(orario1)) {
			System.out.println("Mancano " + orario1.quantoManca(orario2) + " minuti alle " +
			orario2.toString() + " di oggi");
		} else
			System.out.println("L'ora inserita è quella attuale: " + orario2.toString());

		Orario.setSeparatoreTo('.');
		Orario.setFormato24(false);
		System.out.println(orario1);
		System.out.println(orario2);
		System.out.println(orario3.toString());
	}
}
