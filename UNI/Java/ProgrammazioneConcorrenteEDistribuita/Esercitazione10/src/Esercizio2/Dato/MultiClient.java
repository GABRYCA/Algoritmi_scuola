package Esercizio2.Dato;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MultiClient {
	static final int MAX_THREADS = 3;
	static final int CLIENT_THREADS_TOT = 6;

	void exec() throws RemoteException, NotBoundException {
		Registry registro = LocateRegistry.getRegistry(1099);
		NewsService news = (NewsService) registro.lookup("NEWS");
		int i = 0;
		while (i < CLIENT_THREADS_TOT) {
			if (NewsClientThread.threadCount() < MAX_THREADS) {
				new NewsClientThread(i, news);
				i++;
			} else {
				try {
					Thread.sleep(40);
				} catch (InterruptedException e) {
				}
			}
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