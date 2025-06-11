package soluzione3;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainClient {

	static final int numGiocatori = 3;

	public static void main(String[] args) {
		
		try {
			Registry reg = LocateRegistry.getRegistry(1099);
			GiocoInt g = (GiocoInt) reg.lookup("gioco");
			
			for (int i = 0; i < numGiocatori; i++) {
				new Giocatore(i, g).start();
			}
		} catch (RemoteException | NotBoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
