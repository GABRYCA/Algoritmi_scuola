package soluzione3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface TavoloInt extends Remote {
	
	public void aspettaTurno(int chiMuove) throws RemoteException;
	public boolean mossa(int chiMuove, String m) throws RemoteException;
	
}
