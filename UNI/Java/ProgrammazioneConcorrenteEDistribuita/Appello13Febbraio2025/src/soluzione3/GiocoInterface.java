package soluzione3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface GiocoInterface extends Remote {
	
	public void giocata(int id) throws RemoteException;
	public String letturaEsito(int id) throws RemoteException;

}
