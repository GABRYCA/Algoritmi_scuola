package Esercizio3.Dato;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface WarnClient extends Remote {
	public void notifyWarn() throws RemoteException;
}
