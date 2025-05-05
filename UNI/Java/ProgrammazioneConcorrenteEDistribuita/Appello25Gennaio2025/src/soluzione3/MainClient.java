package soluzione3;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainClient {

	public static void main(String[] args) {
		System.out.println("Avviando utente...");

		Registry r;
		try {
			r = LocateRegistry.getRegistry();
			ResourceManagerInterface repo;
			try {
				repo = (ResourceManagerInterface) r.lookup("ResourceManager");
				User user = new User(repo);
				Thread thread = new Thread(user);
				thread.start();
			} catch (NotBoundException e) {
				System.out.println("Errore creazione Thread e fetch registro");
			}

		} catch (RemoteException e) {
			System.out.println("Errore remoto");
			e.printStackTrace();
		}

		System.out.println("Fine user - main.");
	}
}
