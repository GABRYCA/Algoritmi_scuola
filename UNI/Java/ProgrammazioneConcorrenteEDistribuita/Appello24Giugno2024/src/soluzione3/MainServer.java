package soluzione3;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainServer {

	public static void main(String[] args) {
		Tavolo tavolo = new Tavolo();
		
		try {
			Gestore ilGestore = new Gestore(tavolo);
			Registry reg = LocateRegistry.createRegistry(1099);
			reg.rebind("GestoreService", ilGestore);
			System.out.println("Registro GestoreService creato con successo!");
		} catch (RemoteException e) {
		}
		
	}

}
