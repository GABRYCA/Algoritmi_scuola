package soluzione3;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainServer {
	
	static final int numGiocatori = 3;
	static final int porta = 1069;

	public static void main(String[] args) {
		System.out.println("Avviato server.");
		try {
			Gioco gioco = new Gioco(numGiocatori);
			Registry registry = LocateRegistry.createRegistry(1099);
			registry.rebind("GiocoService", gioco);
			System.out.println("Servizio registrato con successo!");
		} catch (RemoteException e) {
			e.printStackTrace();
		}
		
		System.out.println("Fine!");
	}

}
