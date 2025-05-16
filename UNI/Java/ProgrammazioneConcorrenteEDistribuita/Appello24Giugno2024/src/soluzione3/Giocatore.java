package soluzione3;

import java.rmi.RemoteException;
import java.util.concurrent.ThreadLocalRandom;

public class Giocatore extends Thread {
	GestoreInt ilGestore;
	ClientInt client;

	Giocatore(int id, GestoreInt g) {
		ilGestore = g;
		this.setName("Giocatore_" + id);
		try {
			client = new ClientImpl(getName());
		} catch (RemoteException e) {
		}
	}

	void mySleep(int a, int b) {
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(a, b));
		} catch (InterruptedException e) {
		}
	}

	public void run() {
		try {
			ilGestore.registraClient(client);
		} catch (RemoteException e) {
		}
		while (true) {
			System.out.println(this.getName() + " vuole muovere");
			String miaMossa = "mossa_" + ThreadLocalRandom.current().nextInt(1, 10);
			try {
				ilGestore.mossa(miaMossa);
			} catch (RemoteException e) {
			}
		}
	}
}
