package soluzione3;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.concurrent.ThreadLocalRandom;

public class MainClient {
	
	static final int numClients = 4;


	public static void main(String[] args) {
		
		try {
		Registry reg = LocateRegistry.getRegistry(1099);
		GestoreInt gestore = (GestoreInt) reg.lookup("Posta");
		
		for (int i = 0; i < numClients; i++) {
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(200));
			} catch (InterruptedException e) {
			}
			new Client(gestore).start();
		}
		} catch (RemoteException | NotBoundException e) {
			
		}
	}

}
