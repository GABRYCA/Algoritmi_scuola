package Esercizio2.Dato;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Random;

public class NewsServiceImpl implements NewsService {
	private String theNews = "boh";
	Random rnd = null;

	public NewsServiceImpl() throws RemoteException {
		rnd = new Random();
	}

	public synchronized String readNews() throws RemoteException {
		return theNews;
	}

	public synchronized void updateNews(String s) {
		theNews = s;
	}

	public void exec() {
		try {
			NewsService obj = (NewsService) UnicastRemoteObject.exportObject(this, 3333);
			Registry registro = LocateRegistry.createRegistry(1099);
			registro.rebind("NEWS", obj);
			System.out.println("Server ready");
		} catch (Exception e) {
			System.err.println("Server exception: " + e.toString());
			return;
		}
	}
}
