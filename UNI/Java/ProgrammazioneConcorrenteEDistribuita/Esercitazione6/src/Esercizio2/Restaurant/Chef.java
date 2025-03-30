package Esercizio2.Restaurant;

public class Chef extends Thread {
	private Kitchen theKitchen;

	public Chef(Kitchen k) {
		this.theKitchen = k;
		this.setName("The Chef");
		start();
	}

	public void run() {
		while (true) {
			try {
				String orderToServe = theKitchen.getNextOrder();
				System.out.println("Chef: I'm starting to prepare order " + orderToServe);
				theKitchen.prepare(orderToServe);
			} catch (InterruptedException e) {
				break;
			}
		}
		System.out.println("The kitchen closes down");
	}
}
