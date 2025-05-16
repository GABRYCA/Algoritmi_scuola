package soluzione2;

import java.util.concurrent.ThreadLocalRandom;

public class Giocatore extends Thread {
	Proxy ilGestore;

	Giocatore(int id) {
		ilGestore = new Proxy();
		this.setName("Giocatore_" + id);
	}

	void mySleep(int a, int b) {
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(a, b));
		} catch (InterruptedException e) {
		}
	}

	public void run() {
		while (true) {
			if (ThreadLocalRandom.current().nextBoolean()) {
				System.out.println(this.getName() + " vuole leggere");
				// legge
				String situazione = ilGestore.leggi();
			} else {
				// scrive
				System.out.println(this.getName() + " vuole muovere");
				String miaMossa = "mossa_" + ThreadLocalRandom.current().nextInt(1, 10);
				ilGestore.mossa(miaMossa);
			}
		}
	}
}
