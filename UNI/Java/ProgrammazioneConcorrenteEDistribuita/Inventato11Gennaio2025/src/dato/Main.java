package dato;

public class Main {
	public static void main(String[] args) {
		Magazzino magazzino = new Magazzino(5);

		Produttore p1 = new Produttore("Produttore-1", magazzino);
		Produttore p2 = new Produttore("Produttore-2", magazzino);

		Consumatore c1 = new Consumatore("Consumatore-1", magazzino);
		Consumatore c2 = new Consumatore("Consumatore-2", magazzino);
		Consumatore c3 = new Consumatore("Consumatore-3", magazzino);

		p1.start();
		p2.start();
		c1.start();
		c2.start();
		c3.start();
	}
}