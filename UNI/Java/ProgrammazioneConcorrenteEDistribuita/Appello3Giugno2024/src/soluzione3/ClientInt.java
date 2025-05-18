package soluzione3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ClientInt extends Remote {
	
	void notifica(Messaggio msg) throws RemoteException;
	
}
