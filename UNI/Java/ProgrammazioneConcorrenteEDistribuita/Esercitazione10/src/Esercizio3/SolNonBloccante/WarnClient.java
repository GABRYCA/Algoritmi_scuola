package Esercizio3.SolNonBloccante;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface WarnClient extends Remote {

	void notifyMe() throws RemoteException;
}
