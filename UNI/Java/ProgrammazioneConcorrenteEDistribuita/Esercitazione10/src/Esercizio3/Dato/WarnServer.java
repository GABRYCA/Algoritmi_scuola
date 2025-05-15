package Esercizio3.Dato;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface WarnServer extends Remote {
	public void WarnAt(int X, WarnClient c) throws RemoteException;
}
