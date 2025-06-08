package soluzione3;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainClient {
	
	public static void main(String[] args) {
		
		try {
			Registry reg = LocateRegistry.getRegistry(1099);
			TavoloInt t = (TavoloInt) reg.lookup("tavolo");
			
			Thread g1 = new Giocatore(0, t);
			Thread g2 = new Giocatore(1, t);
			g1.start();
			g2.start();
		} catch (RemoteException | NotBoundException e) {
		}
		
		
	}
	
}
