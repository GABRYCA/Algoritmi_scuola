package soluzione3;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class TavoloGioco extends UnicastRemoteObject implements TavoloInt {
	int aChiTocca;

	TavoloGioco(int primo) throws RemoteException {
		super();
		aChiTocca = primo;
	}

	public synchronized void aspettaTurno(int chiMuove) {
		while (aChiTocca != chiMuove) {
			try {
				wait();
			} catch (InterruptedException e) {
			}
		}
	}

	public synchronized int chiDiTurno() {
		return aChiTocca;
	}

	public synchronized boolean mossa(int chiMuove, String m) {
		if (aChiTocca == chiMuove) {
			System.out.println("Giocatore " + chiMuove + " ha fatto mossa " + m);
			aChiTocca = 1 - aChiTocca;
			notifyAll();
			return true;
		} else {
			return false;
		}
	}
}
