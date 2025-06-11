package soluzione3;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainClient {

	public static void main(String[] args) {
		
		try {
			Registry reg = LocateRegistry.getRegistry(1099);
			MagazzinoInt mint = (MagazzinoInt) reg.lookup("magazzino");
			
			Produttore p1 = new Produttore("Produttore-1", mint);
			Produttore p2 = new Produttore("Produttore-2", mint);

			Consumatore c1 = new Consumatore("Consumatore-1", mint);
			Consumatore c2 = new Consumatore("Consumatore-2", mint);
			Consumatore c3 = new Consumatore("Consumatore-3", mint);

			p1.start();
			p2.start();
			c1.start();
			c2.start();
			c3.start();
		} catch (RemoteException | NotBoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
