package soluzione3;

import java.rmi.RemoteException;
import java.util.Random;

public class Consumatore extends Thread {
	private final MagazzinoInt magazzino;

	public Consumatore(String nome, MagazzinoInt m) {
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
				try {
					Prodotto p = magazzino.preleva();
					if (p == null) {
						System.out.println("Richiesta terminazione (server non disponibile), terminazione in corso!");
						return;
					}
					System.out.println(getName() + " ha consumato: " + p);
					// Simula il tempo di consumo
					Thread.sleep(random.nextInt(1500));
				} catch (RemoteException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}