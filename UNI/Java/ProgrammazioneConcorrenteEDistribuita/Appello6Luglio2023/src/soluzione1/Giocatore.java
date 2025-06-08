package soluzione1;

import java.util.Random;

public class Giocatore extends Thread {
	int identificatore;
	TavoloGioco tavolo;
	Giocatore avversario;

	Giocatore(int n, TavoloGioco t) {
		identificatore = n;
		tavolo = t;
		this.setName("giocatore_" + n);
	}
	
	public void setAvversario(Giocatore a) {
		this.avversario = a;
	}

	private void pensa() {
		int a = 0;
		Random rnd = new Random();
		int c2 = 1 + rnd.nextInt(10);
		System.out.println(this.getName() + ": pensa ... ");
		while (true) {
			if (Thread.interrupted()) {
				break;
			}
			for (int j = 0; j < c2 * 100000000; j++) {
				a = 1 - a;
			}
		}
		System.out.println(this.getName() + ": ha finito di pensare.");
	}

	public void run() {
		if (identificatore == 1) {
			avversario.interrupt();
		}
		while (true) {
			pensa();
			tavolo.mossa(identificatore, "mossa_" + identificatore);
			avversario.interrupt();
		}
	}
}
