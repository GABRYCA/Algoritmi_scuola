package soluzione3;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ClientIntImpl extends UnicastRemoteObject implements ClientInt {
	
	String name;
	
	protected ClientIntImpl(String name) throws RemoteException {
		super();
		this.name = name;
	}

	@Override
	public void notifica(Messaggio msg) throws RemoteException {
		if (name.equalsIgnoreCase(msg.getDestinatario())) {
			System.out.println(name + " ricevuto messaggio " + msg);
		}
	}

}
