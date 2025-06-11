package soluzione2;

import java.util.Random;

public class Consumatore extends Thread {
	private final Proxy magazzino;

	public Consumatore(String nome) {
		super(nome);
		this.magazzino = new Proxy();
	}

	@Override
	public void run() {
		Random random = new Random();
		while (true) {
			try {
				Prodotto p = magazzino.preleva();
				if (p == null) {
					System.out.println("Richiesta terminazione (server non disponibile), terminazione in corso!");
					return;
				}
				System.out.println(getName() + " ha consumato: " + p);
				// Simula il tempo di consumo
				Thread.sleep(random.nextInt(1500));
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}