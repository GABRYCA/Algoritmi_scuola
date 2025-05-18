package soluzione3;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainServer {

	public static void main(String[] args) {
		try {
			Dati iDati = new Dati();
			Registry reg = LocateRegistry.createRegistry(1099);
			reg.rebind("Dati", iDati);
		} catch (RemoteException e) {
			e.printStackTrace();
		}
	}

}
