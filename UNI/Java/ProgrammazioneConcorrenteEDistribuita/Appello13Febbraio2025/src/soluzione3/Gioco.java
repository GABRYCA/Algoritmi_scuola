package soluzione3;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Gioco extends UnicastRemoteObject implements GiocoInterface {
	private int numGiocatori = 0;
	FasiGioco faseCorrente; // la fase corrente: gioco o lettura risultati
	boolean[] hannoFatto; // tiene conto di quanti giocatori hanno giocato (se siamo nella fase di gioco)
							// o hanno letto il risultato (se siamo nella fase di lettura dei risultati)

	private void reset() {
		for (int i = 0; i < numGiocatori; i++) {
			hannoFatto[i] = false;
		}
	}

	private boolean hannoFattoTutti() {
		int count = 0;
		for (int i = 0; i < numGiocatori; i++) {
			if (hannoFatto[i]) {
				count++;
			}
		}
		return count == numGiocatori;
	}

	// solo per debugging
	private void mostraSituazione() {
		System.out.print("fase " + faseCorrente + " : ");
		for (int i = 0; i < numGiocatori; i++) {
			System.out.print(hannoFatto[i] ? "Y" : "N");
		}
		System.out.println();
	}

	public Gioco(int ng) throws RemoteException {
		super();
		numGiocatori = ng;
		hannoFatto = new boolean[ng];
		reset();
		faseCorrente = FasiGioco.Gioco;
		//mostraSituazione();
	}

	public synchronized void giocata(int idGiocatore) {
		while (faseCorrente != FasiGioco.Gioco) {
			try {
				wait();
			} catch (InterruptedException e) {
			}
		}
		hannoFatto[idGiocatore] = true;
		if (hannoFattoTutti()) {
			reset();
			faseCorrente = FasiGioco.LetturaRisultati;
			notifyAll();
		}
		//mostraSituazione();
	}

	public synchronized String letturaEsito(int idGiocatore) {
		while (faseCorrente != FasiGioco.LetturaRisultati) {
			try {
				wait();
			} catch (InterruptedException e) {
			}
		}
		hannoFatto[idGiocatore] = true;
		if (hannoFattoTutti()) {
			reset();
			faseCorrente = FasiGioco.Gioco;
			notifyAll();
		}
		String esito = "";
		for (boolean x : hannoFatto) {
			esito = esito + (x ? "Y" : "N");
		}
		//System.out.println("Esito");
		return esito;
	}
}
