package Esercizio2.SolCallback;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface NewsClient extends Remote {
	public void reportNews(String text) throws RemoteException;
}
