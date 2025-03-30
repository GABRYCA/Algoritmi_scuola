package Esercizio2.Restaurant;

import java.util.concurrent.ThreadLocalRandom;

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
		myOrder = "order_" + name;
		System.out.println(name + ": I'm ready to place my order " + myOrder);
		theKitchen.putOrder(myOrder);
		theKitchen.isOrderReady(myOrder);
		System.out.println(name + ": I'm eating my order " + myOrder);
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(4000));
		} catch (InterruptedException e) {}
		System.out.println(name + ": I finished eating.");
	}
}
