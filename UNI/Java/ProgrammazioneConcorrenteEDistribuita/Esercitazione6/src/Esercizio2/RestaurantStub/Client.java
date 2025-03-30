package Esercizio2.RestaurantStub;

public class Client extends Thread {
	private String name;
	private String myOrder;
	private Kitchen theKitchen;

	public Client(String name, Kitchen k) {
		this.name = name;
		this.setName(name);
		this.theKitchen = k;
	}

	public void run() {
		// piazza l'ordine
		// attende che il piatto ordinato sia pronto
		// mangia ed esce
	}
}
