package soluzione3;

import java.rmi.RemoteException;
import java.util.concurrent.ThreadLocalRandom;

public class Giocatore extends Thread {
	GiocoInt ilGioco;
	int mioId;
	String mioNome;

	public Giocatore(int id, GiocoInt g) {
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
			try {
				ilGioco.giocata(mioId);
			} catch (RemoteException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			//System.out.println(mioNome + ": " + "gioco");

			 System.out.println(mioNome + "[" + it + "]: " + "leggo");
			try {
				ilGioco.letturaEsito(mioId);
			} catch (RemoteException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			//System.out.println(mioNome + "[" + it + "]: " + "leggo");

		}

		System.out.println(mioNome + " ho finito il gioco e chiuso!");

	}
}
