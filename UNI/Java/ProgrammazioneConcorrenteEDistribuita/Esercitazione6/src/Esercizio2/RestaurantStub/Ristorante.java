package Esercizio2.RestaurantStub;

import java.util.concurrent.ThreadLocalRandom;

public class Ristorante {

	public Ristorante() {
		Kitchen theKitchen = new Kitchen();
		Chef theChef = new Chef(theKitchen);
		int numClients = 10 + (int) (Math.random() * 20);
		Thread clients[] = new Thread[numClients];
		System.out.println("main: creating " + numClients + " clients");
		for (int i = 0; i < numClients; i++) {
			clients[i] = new Client("Client_" + i, theKitchen);
			clients[i].start();
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(100, 400));
			} catch (InterruptedException e) {}
		}
		for (int i = 0; i < numClients; i++) {
			try {
				clients[i].join();
			} catch (InterruptedException e) {}
		}
		theChef.interrupt();
		System.out.println("All " + numClients + " clients served, restaurant closes!");
	}

}
