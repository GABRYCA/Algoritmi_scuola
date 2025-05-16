package soluzione3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface GestoreInt extends Remote {
	
	public void mossa(String m) throws RemoteException;
	public void registraClient(ClientInt client) throws RemoteException;
	public void unregistraClient(ClientInt client) throws RemoteException;

}
