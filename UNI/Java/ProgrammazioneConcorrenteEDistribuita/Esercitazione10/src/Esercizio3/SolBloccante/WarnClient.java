package Esercizio3.SolBloccante;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface WarnClient extends Remote {
	public void notifyWarn() throws RemoteException;
}
