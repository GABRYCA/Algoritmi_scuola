package soluzione3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface GestoreInt extends Remote {

	String newClient() throws RemoteException;
	void put(Messaggio msg) throws RemoteException;
	void registra(ClientInt c) throws RemoteException;
	void deregistra(ClientInt c) throws RemoteException;
	int numClients() throws RemoteException;
	
}
