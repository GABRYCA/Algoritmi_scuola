package soluzione3;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

//Risorsa condivisa con problemi di concorrenza.
public class Magazzino extends UnicastRemoteObject implements MagazzinoInt {
	private final Prodotto[] prodotti;
	private final int capacita;
	private int count;
	private int in; // Indice per depositare
	private int out; // Indice per prelevare
	private List<ClientInt> clients;

	public Magazzino(int capacita) throws RemoteException {
		super();
		this.capacita = capacita;
		this.prodotti = new Prodotto[capacita];
		this.count = 0;
		this.in = 0;
		this.out = 0;
		this.clients = new CopyOnWriteArrayList<>();
	}
	
	public synchronized void pieno() {
		while (count == capacita) {
			try {
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	public synchronized void vuoto() {
		while (count == 0) {
			try {
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	public synchronized void sblocca() {
		notifyAll();
	}

	// Metodo per depositare un prodotto
	public synchronized void deposita(Prodotto prodotto) {
		
		pieno();

		// PROBLEMA: Sezione Critica non protetta (Corsa Critica / Race Condition)
		prodotti[in] = prodotto;
		System.out.println("DEPOSITATO: " + prodotto + " in posizione " + in);
		in = (in + 1) % capacita;
		count++;
		
		for (ClientInt client : clients) {
			try {
				client.notifica();
			} catch (RemoteException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		sblocca();
	}

	// Metodo per prelevare un prodotto
	public synchronized Prodotto preleva() {
		
		vuoto();

		// PROBLEMA: Sezione Critica non protetta (Corsa Critica / Race Condition)
		Prodotto prodotto = prodotti[out];
		System.out.println("PRELEVATO: " + prodotto + " da posizione " + out);
		out = (out + 1) % capacita;
		count--;
		sblocca();
		return prodotto;
	}

	@Override
	public void registra(ClientInt cint) throws RemoteException {
		clients.add(cint);
	}

	@Override
	public void unregistra(ClientInt cint) throws RemoteException {
		clients.remove(cint);
	}
}