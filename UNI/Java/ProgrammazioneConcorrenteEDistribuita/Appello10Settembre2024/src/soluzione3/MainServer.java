package soluzione3;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainServer {

	public static void main(String[] args) {
		try {
			Tavolo gestore = new Tavolo();
			Registry reg = LocateRegistry.createRegistry(1099);
			reg.rebind("Tavolo", gestore);
		} catch (RemoteException e) {
			e.printStackTrace();
		}
		
	}

}
