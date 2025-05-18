package soluzione3;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainClient {

	static final int numClient = 10;

	public static void main(String[] args) {

		try {
			Registry reg = LocateRegistry.getRegistry(1099);
			try {
				DatiInterface dati = (DatiInterface) reg.lookup("Dati");
				for (int i = 0; i < numClient; i++) {
					Thread thread = new ThreadAzioni(i, dati);
					thread.start();
				}
			} catch (NotBoundException e) {
				e.printStackTrace();
			}
		} catch (RemoteException e) {
			e.printStackTrace();
		}

	}

}
