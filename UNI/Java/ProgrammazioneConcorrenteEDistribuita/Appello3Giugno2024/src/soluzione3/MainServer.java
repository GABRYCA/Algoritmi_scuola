package soluzione3;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainServer {

	public static void main(String[] args) {
		try {
		CasellePostali leCaselle = new CasellePostali();
		
		try {
			Registry reg = LocateRegistry.createRegistry(1099);
			reg.rebind("Posta", leCaselle);
		} catch (RemoteException e) {
		}
		} catch (RemoteException e) {}
		
	}

}
