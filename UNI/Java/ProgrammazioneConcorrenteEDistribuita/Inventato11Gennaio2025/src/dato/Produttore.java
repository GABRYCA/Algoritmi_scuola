package dato;

import java.util.Random;

public class Produttore extends Thread {
	private final Magazzino magazzino;
	private int idProdotto = 0;

	public Produttore(String nome, Magazzino magazzino) {
		super(nome);
		this.magazzino = magazzino;
	}

	@Override
	public void run() {
		Random random = new Random();
		while (true) {
			try {
				// Simula il tempo di produzione
				Thread.sleep(random.nextInt(1000));
				Prodotto p = new Prodotto(idProdotto++);
				System.out.println(getName() + " ha prodotto: " + p);
				magazzino.deposita(p);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}