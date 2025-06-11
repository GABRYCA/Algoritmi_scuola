package soluzione3;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainServer {

	public static void main(String[] args) {
		try {
			Magazzino magazzino = new Magazzino(5);
			Registry reg = LocateRegistry.createRegistry(1099);
			reg.rebind("magazzino", magazzino);
			
			System.out.println("Creato e offrendo servizio magazzino...");
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		
	}

}
