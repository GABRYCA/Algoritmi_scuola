package Esercizio2.SolCallback;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.List;

public class NewsServiceImpl extends UnicastRemoteObject implements NewsService {
	private static final long serialVersionUID = 1L;
	String laNotizia;
	List<NewsClient> iClienti;

	public NewsServiceImpl() throws RemoteException {
		super();
		laNotizia = "...";
		iClienti = new ArrayList<NewsClient>();
	}

	public synchronized String readNews() throws RemoteException {
		System.out.println("Server: lettura " + laNotizia);
		return laNotizia;
	}

	public synchronized void updateNews(String text) throws RemoteException {
		laNotizia = text;
		System.out.println("Server: notizia corrente=" + laNotizia);
		notifyClients();
	}

	private void notifyClients() {
		for (NewsClient c : iClienti) {
			try {
				c.reportNews(laNotizia);
			} catch (RemoteException e) {
				iClienti.remove(c);
			}
		}
	}

	public synchronized void addClient(NewsClient c) throws RemoteException {
		iClienti.add(c);
	}

	public synchronized void removeClient(NewsClient c) throws RemoteException {
		iClienti.remove(c);
	}
}
