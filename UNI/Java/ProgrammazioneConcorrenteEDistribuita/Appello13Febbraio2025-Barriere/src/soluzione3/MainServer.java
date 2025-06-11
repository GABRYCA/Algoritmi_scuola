package soluzione3;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainServer {

	static final int numGiocatori = 3;

	public static void main(String[] args) {
		try {
			Gioco g = new Gioco(numGiocatori);
			Registry reg = LocateRegistry.createRegistry(1099);
			reg.rebind("gioco", g);
			
			System.out.println("Rebindato il gioco e pronto ad accogliere richieste...");
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		
	}

}
