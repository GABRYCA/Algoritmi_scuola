package soluzione3;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainServer {
	
	private static int numResources = 4;

	public static void main(String[] args) {
		ResourceManager rm;
		try {
			rm = new ResourceManager();
		} catch (RemoteException e) {
			e.printStackTrace();
			System.exit(1);
			return;
		}
		
		for (int i = 0; i < numResources; i++) { // Attenzione!
			// le risorse di ciascun tipo sono meno degli utilizzatori!
			rm.put(new Resource(ResourceType.A));
			rm.put(new Resource(ResourceType.B));
		}
		
		try {
			Registry r = LocateRegistry.createRegistry(1099);
			r.rebind("ResourceManager", rm);
		} catch (RemoteException e) {
			System.out.println("Errore creazione registro!");
		}
		
		System.out.println("Server chiuso!");
	}

}
