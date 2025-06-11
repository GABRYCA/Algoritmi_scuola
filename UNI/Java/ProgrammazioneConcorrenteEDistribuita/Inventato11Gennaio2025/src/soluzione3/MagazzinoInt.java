package soluzione3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface MagazzinoInt extends Remote {

	void deposita(Prodotto p) throws RemoteException;

	Prodotto preleva() throws RemoteException;
	
	void registra(ClientInt cint) throws RemoteException;
	
	void unregistra(ClientInt cint) throws RemoteException;
	
	

}
