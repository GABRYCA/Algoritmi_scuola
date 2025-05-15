package Esercizio2.SolCallback;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class theServerMain {
	public static void main(String args[]) throws RemoteException {
		NewsServiceImpl obj = new NewsServiceImpl();
		Registry registro = LocateRegistry.createRegistry(1099);
		registro.rebind("NEWS", obj);
		System.out.println("Server ready");
		new NewsUpdater(obj).start();
	}
}