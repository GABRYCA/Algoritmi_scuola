package soluzione3;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainServer {

	public static void main(String[] args) {
		try {
			TavoloGioco tavolo = new TavoloGioco(0);
			
			Registry reg = LocateRegistry.createRegistry(1099);
			reg.rebind("tavolo", tavolo);
		} catch (RemoteException e) {
			e.printStackTrace();
		}

	}

}
