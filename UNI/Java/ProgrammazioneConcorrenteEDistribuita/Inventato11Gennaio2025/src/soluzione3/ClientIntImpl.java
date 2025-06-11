package soluzione3;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ClientIntImpl extends UnicastRemoteObject implements ClientInt {
	
	String name;
	
	public ClientIntImpl(String name) throws RemoteException {
		super();
		this.name = name;
	}

	public void notifica() throws RemoteException {
		System.out.println(name + " ha ricevuto una notifica di deposito dal server!");
	}
}
