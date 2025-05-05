package soluzione3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ResourceManagerInterface extends Remote {

	public Resource getA() throws RemoteException;
	public Resource getB() throws RemoteException;
	public void put(Resource r) throws RemoteException;
	
}
