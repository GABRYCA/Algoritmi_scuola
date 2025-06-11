package soluzione2;

public class MainClient {

	public static void main(String[] args) {
		Produttore p1 = new Produttore("Produttore-1");
		Produttore p2 = new Produttore("Produttore-2");

		Consumatore c1 = new Consumatore("Consumatore-1");
		Consumatore c2 = new Consumatore("Consumatore-2");
		Consumatore c3 = new Consumatore("Consumatore-3");

		p1.start();
		p2.start();
		c1.start();
		c2.start();
		c3.start();
	}

}
