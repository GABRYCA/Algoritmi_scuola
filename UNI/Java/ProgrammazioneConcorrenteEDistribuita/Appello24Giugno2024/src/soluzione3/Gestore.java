package soluzione3;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

public class Gestore extends UnicastRemoteObject implements GestoreInt {
	int numModificheAttive;
	int numLettori;
	Tavolo ilTavolo;
	
	List<ClientInt> clients;

	public Gestore(Tavolo t) throws RemoteException {
		super();
		numModificheAttive = 0;
		numLettori = 0;
		ilTavolo = t;
		clients = new CopyOnWriteArrayList<>();
	}

	private void situazioneThread() {
		System.out.println(" [#modificanti=" + numModificheAttive + ", #leggenti=" + numLettori + "]");
	}

	private synchronized void puoLeggere() {
		while (numModificheAttive > 0) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		numLettori++;
	}
	
	private synchronized void puoMossa() {
		while (numModificheAttive > 0 || numLettori > 0) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		numModificheAttive++;
	}

	private synchronized void uscendoLettura() {
		numLettori--;
		notifyAll();
	}
	
	private synchronized void uscendoMossa() {
		numModificheAttive--;
		notifyAll();
	}

	public String leggi() {
		puoLeggere();
		System.out.print(Thread.currentThread().getName() + " legge situazione "
				+ (numModificheAttive > 0 ? " illegalmente ******" : ""));
		situazioneThread();
		String stato = ilTavolo.leggi();
		uscendoLettura();
		return stato;
	}

	public void mossa(String m) {
		puoMossa();
		System.out.print(Thread.currentThread().getName() + " effettua mossa "
				+ (numModificheAttive > 1 || numLettori > 0 ? " illegalmente ******" : ""));
		situazioneThread();
		// esecuzione della mossa
		ilTavolo.prendiPedina();
		// a questo punto la situazione del tavolo da gioco e` inconsistente
		ilTavolo.mettiPedina();
		for (ClientInt client : clients) {
			try {
				client.aggiornaStato(ilTavolo.leggi());
			} catch (RemoteException e) {
				e.printStackTrace();
			}
		}
		uscendoMossa();
	}

	@Override
	public void registraClient(ClientInt client) throws RemoteException {
		this.clients.add(client);
	}

	@Override
	public void unregistraClient(ClientInt client) throws RemoteException {
		this.clients.remove(client);
	}
}
