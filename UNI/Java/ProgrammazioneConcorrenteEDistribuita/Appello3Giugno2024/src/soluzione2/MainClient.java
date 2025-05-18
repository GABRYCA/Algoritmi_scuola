package soluzione2;

import java.util.concurrent.ThreadLocalRandom;

public class MainClient {
	
	static final int numClients = 4;


	public static void main(String[] args) {
		for (int i = 0; i < numClients; i++) {
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(200));
			} catch (InterruptedException e) {
			}
			new Client().start();
		}
	}

}
