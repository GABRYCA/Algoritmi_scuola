package Esercizio2.SolCallback;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MultiClient {
	static final int CLIENT_TOT =4;
	void exec() throws RemoteException, NotBoundException {
		Registry registro = LocateRegistry.getRegistry(1099);
		NewsService news = (NewsService) registro.lookup("NEWS");
		for(int i=0; i<CLIENT_TOT; i++) {
			new NewsClientImpl(i, news);
			System.out.println("main: creato client "+i);
			try {
				Thread.sleep(400);
			} catch (InterruptedException e) { 	}	
		}
	}
	public static void main(String[] args) {
		try {
			new MultiClient().exec();
		} catch (RemoteException | NotBoundException e) {
			System.out.println("MultiClient failed");
		}
	}
}