package soluzione3;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainClient {

	final static int numGiocatori = 6;

	public static void main(String[] args) {

		try {
			Registry reg = LocateRegistry.getRegistry(1099);
			try {
				TavoloInt t = (TavoloInt) reg.lookup("Tavolo");
				for (int i = 0; i < numGiocatori; i++) {
					new Giocatore(i + 1, t).start();
				}
			} catch (NotBoundException e) {
				e.printStackTrace();
			}

		} catch (RemoteException e) {
			e.printStackTrace();
		}

	}

}
