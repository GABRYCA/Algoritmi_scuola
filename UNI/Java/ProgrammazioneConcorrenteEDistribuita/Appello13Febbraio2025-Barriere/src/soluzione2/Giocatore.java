package soluzione2;

import java.util.concurrent.ThreadLocalRandom;

public class Giocatore extends Thread {
	Proxy ilGioco;
	int mioId;
	String mioNome;

	public Giocatore(int id) {
		ilGioco = new Proxy();
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
			ilGioco.giocata(mioId);
			//System.out.println(mioNome + ": " + "gioco");

			 System.out.println(mioNome + "[" + it + "]: " + "leggo");
			ilGioco.letturaEsito(mioId);
			//System.out.println(mioNome + "[" + it + "]: " + "leggo");

		}

		System.out.println(mioNome + " ho finito il gioco e chiuso!");

	}
}
