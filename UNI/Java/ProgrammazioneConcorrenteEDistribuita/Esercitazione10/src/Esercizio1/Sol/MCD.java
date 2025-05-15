package Esercizio1.Sol;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface MCD extends Remote {
	public int mcd(int n, int m) throws RemoteException;
}
