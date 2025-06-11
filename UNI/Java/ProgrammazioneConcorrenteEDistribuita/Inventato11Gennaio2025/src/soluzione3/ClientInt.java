package soluzione3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ClientInt extends Remote {
	
	public void notifica() throws RemoteException;

}
