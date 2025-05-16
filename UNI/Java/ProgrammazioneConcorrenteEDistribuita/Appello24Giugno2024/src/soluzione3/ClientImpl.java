package soluzione3;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ClientImpl extends UnicastRemoteObject implements ClientInt {

	String idClient;
	
	protected ClientImpl(String idClient) throws RemoteException {
		super();
		this.idClient = idClient;
	}

	@Override
	public void aggiornaStato(String stato) throws RemoteException {
		System.out.println(idClient + "-> Stato aggiornato a: " + stato);
	}

}
