package Esercizio2.SolCallback;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class NewsClientImpl extends UnicastRemoteObject implements NewsClient {
	private static final long serialVersionUID = 1L;
	int mioId;
	NewsService ilServer;

	protected NewsClientImpl(int id, NewsService ns) throws RemoteException {
		super();
		mioId = id;
		ilServer = ns;
		ilServer.addClient(this);
	}

	public void reportNews(String text) throws RemoteException {
		System.out.println("News client " + mioId + " riceve:" + text);
	}

}
