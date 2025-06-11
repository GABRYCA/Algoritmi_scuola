package soluzione3;

import java.rmi.RemoteException;
import java.util.Random;

public class Produttore extends Thread {
	private final MagazzinoInt magazzino;
	private int idProdotto = 0;

	public Produttore(String nome, MagazzinoInt m) {
		super(nome);
		this.magazzino = m;
	}

	@Override
	public void run() {
		
		try {
			ClientIntImpl client = new ClientIntImpl(getName());
			magazzino.registra(client);
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		Random random = new Random();
		while (true) {
			try {
				// Simula il tempo di produzione
				Thread.sleep(random.nextInt(1000));
				Prodotto p = new Prodotto(idProdotto++);
				System.out.println(getName() + " ha prodotto: " + p);
				try {
					magazzino.deposita(p);
				} catch (RemoteException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			} catch (InterruptedException e) {
			}
		}
	}
}