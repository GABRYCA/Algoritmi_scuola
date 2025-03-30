package Esercizio2.RestaurantStub;

public class Chef extends Thread {
	private Kitchen theKitchen;

	public Chef(Kitchen k) {
		this.theKitchen = k;
		this.setName("The Chef");
		start();
	}

	public void run() {
		while (true) {
			// aspetta IL PROSSIMO ORDINE
			// da` disposizioni alla cucina di preparare il piatto ordinato
		}
		System.out.println("The chef goes home");
	}
}
