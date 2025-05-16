package soluzione3;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainClient {
	public static void main(String[] args) {
		for (int i = 1; i < 4; i++) {
			try {
				Registry reg = LocateRegistry.getRegistry(1099);
				try {
					GestoreInt gestore = (GestoreInt) reg.lookup("GestoreService");
					new Giocatore(i, gestore).start();
				} catch (NotBoundException e) {
				}
			} catch (RemoteException e) {
			}

		}
	}
}
