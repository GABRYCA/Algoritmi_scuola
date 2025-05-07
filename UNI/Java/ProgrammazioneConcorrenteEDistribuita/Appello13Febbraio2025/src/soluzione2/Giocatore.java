package soluzione2;

import java.util.concurrent.ThreadLocalRandom;

public class Giocatore extends Thread {
	Proxy ilGioco;
	int mioId;
	String mioNome;

	public Giocatore(int id) {
		Proxy g = new Proxy(id);
		ilGioco = g;
		mioId = id;
		mioNome = "giocatore_" + id;
	}

	private void dormitina() {
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(100, 200));
		} catch (InterruptedException e) {
		}
	}

	public void run() {
		for (int it = 0; it < 10; it++) {
			System.out.println(mioNome + ": " + "gioco");
			ilGioco.giocata();
			System.out.println(mioNome + "[" + it + "]: " + "leggo");
			ilGioco.letturaEsito();
		}
	}
}
