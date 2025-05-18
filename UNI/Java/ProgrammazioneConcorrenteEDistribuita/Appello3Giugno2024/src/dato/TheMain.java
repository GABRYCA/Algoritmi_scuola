package dato;

import java.util.concurrent.ThreadLocalRandom;

public class TheMain {
	static final int numClients=4;
	public static void main (String args[]) throws InterruptedException {
		CasellePostali leCaselle = new CasellePostali();
		for(int i=0; i<numClients; i++) {
			Thread.sleep(ThreadLocalRandom.current().nextInt(200));
			new Client(leCaselle).start();
		}
	}
}
