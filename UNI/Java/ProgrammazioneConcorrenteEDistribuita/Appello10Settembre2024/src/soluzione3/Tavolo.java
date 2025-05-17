package soluzione3;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
//classe passiva che contiene i metodi per accedere ai dati
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;
import java.util.Random;

public class Tavolo extends UnicastRemoteObject implements TavoloInt {

	private static final long serialVersionUID = 1L;
	static final int MAXstati = 3;
	Random rnd;
	Hashtable<String, Integer> iGiocatori;

	Tavolo() throws RemoteException {
		super();
		iGiocatori = new Hashtable<String, Integer>();
	}

	public synchronized void iniziaGioco(String nome, int stato) throws RemoteException {
		// bisognerebbe controllare che non sia gia` presente, ma lasciamo stare
		iGiocatori.put(nome, stato);
		notifyAll();
	}

	public synchronized void cambiaStato(String nome, int stato) throws RemoteException  {
		if (iGiocatori.containsKey(nome)) {
			iGiocatori.put(nome, stato);
			notifyAll();
		}
	}

	private synchronized int quantiInStato(int stato) {
		List<Integer> gliStati = new ArrayList<>(iGiocatori.values());
		int count = 0;
		for (int n : gliStati) {
			if (n == stato) {
				count++;
			}
		}
		return count;
	}

	private synchronized boolean condizioneProgressioneOK(int count, int stato) {

		long inizio = System.currentTimeMillis();
		int timeout = 400;
		while (count < stato && (System.currentTimeMillis() - inizio < timeout)) {
			try {
				wait();
			} catch (InterruptedException e) {
			}
			count = quantiInStato(stato);
		}

		return count >= stato;
	}

	public boolean promozione(String nome) throws RemoteException {
		if (iGiocatori.containsKey(nome)) {
			int stato = iGiocatori.get(nome);
			int count;
			count = quantiInStato(stato);
			System.out.println("Tavolo: trovati " + count + " giocatori in stato " + stato + " per " + nome);
			if (condizioneProgressioneOK(count, stato)) {
				if (stato + 1 <= MAXstati) {
					cambiaStato(nome, stato + 1);
				} else {
					cambiaStato(nome, 1); // Presumo che se raggiunga lo stato massimo, lo resetti
				}
				System.out.println("Tavolo: giocatore" + nome + " promosso da " + stato + " a " + iGiocatori.get(nome) + " (NB: Se raggiungo stato massimo, resetto a 1 e continuo il ciclo)");
				return true;
			}
		}
		return false;
	}
}
