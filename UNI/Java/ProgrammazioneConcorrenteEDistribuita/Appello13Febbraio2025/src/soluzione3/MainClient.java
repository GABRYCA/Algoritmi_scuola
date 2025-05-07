package soluzione3;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainClient {
	static final int numGiocatori = 3;

	public static void main(String[] args) {

		try {
			Registry r = LocateRegistry.getRegistry();
			try {
				GiocoInterface g = (GiocoInterface) r.lookup("GiocoService");
				for (int i = 0; i < numGiocatori; i++) {
					new Giocatore(i, g).start();
				}
			} catch (NotBoundException e) {
				e.printStackTrace();
				System.exit(1);
			}

		} catch (RemoteException e) {
			e.printStackTrace();
			System.exit(1);
		}

	}
}
