package soluzione3;

import java.rmi.RemoteException;
import java.util.concurrent.ThreadLocalRandom;

class Client extends Thread {
	String name;
	GestoreInt gestorePosta;
	ClientInt client;

	Client(GestoreInt g) {
		this.gestorePosta = g;
	}

	public void run() {
		Messaggio msg;
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(200, 1000));
		} catch (InterruptedException e) {
		}
		try {
			name = gestorePosta.newClient();
			client = new ClientIntImpl(name);
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} // riceve il nome dal gestore della posta
		for (int j = 0; j < 10; j++) {
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(200, 300));
			} catch (InterruptedException e) {
			}
			try {
				// manda messaggio
				String dest = "Client_" + ThreadLocalRandom.current().nextInt(1, 1 + gestorePosta.numClients());
				msg = new Messaggio(name, dest, "msg da " + name + " #" + j);
				gestorePosta.put(msg);
				System.out.println(name + " scrivo " + msg);
			} catch (RemoteException e) {

			}
		}
	}
}
