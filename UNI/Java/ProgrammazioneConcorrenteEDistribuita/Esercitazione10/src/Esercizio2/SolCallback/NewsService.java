package Esercizio2.SolCallback;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface NewsService extends Remote {
	public String readNews() throws RemoteException;

	public void updateNews(String text) throws RemoteException;

	public void addClient(NewsClient c) throws RemoteException;

	public void removeClient(NewsClient c) throws RemoteException;
}
