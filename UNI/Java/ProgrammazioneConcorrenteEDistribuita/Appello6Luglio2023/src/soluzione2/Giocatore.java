package soluzione2;

import java.net.Socket;
import java.util.concurrent.ThreadLocalRandom;

public class Giocatore extends Thread {
	int identificatore;
	Proxy tavolo;
	Socket socket;

	Giocatore(int n) {
		System.out.println("Creato giocatore: " + n);
		identificatore = n;
		tavolo = new Proxy();
		this.setName("giocatore_" + n);
	}

	private void pensa() {
		int a = 0;
		int c1 = 1 + ThreadLocalRandom.current().nextInt(2, 30);
		int c2 = 1 + ThreadLocalRandom.current().nextInt(2, 30);
		System.out.println(this.getName() + ": pensa ... ");
		for (int i = 0; i < c1 * 1000; i++) {
			for (int j = 0; j < c2 * 1000; j++) {
				a = 1 - a;
			}
		}
		System.out.println(this.getName() + ": ha finito di pensare.");
	}

	public void run() {
		for (int i = 0; i < 10; i++) {
			pensa(); // simula il tempo passato a pensare alla prossima mossa
			tavolo.aspettaTurno(identificatore);
			tavolo.mossa(identificatore, "mossa_" + i + "_da_" + identificatore);
		}
		return;
	}
}
