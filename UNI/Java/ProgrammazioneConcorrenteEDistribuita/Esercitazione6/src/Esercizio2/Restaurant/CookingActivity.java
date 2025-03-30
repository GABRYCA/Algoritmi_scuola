package Esercizio2.Restaurant;

import java.util.concurrent.ThreadLocalRandom;

public class CookingActivity extends Thread {
	private Kitchen myKitchen;
	private String servedOrder;

	public CookingActivity(Kitchen k, String o) {
		myKitchen = k;
		servedOrder = o;
		start();
	}

	public void run() {
		System.out.println("start processing " + servedOrder.toString());
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(400, 800));
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		myKitchen.finished(servedOrder);
	}
}
