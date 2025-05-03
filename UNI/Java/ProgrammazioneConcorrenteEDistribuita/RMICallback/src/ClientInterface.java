import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ClientInterface extends Remote {
	void riceviMessaggio(String messaggio) throws RemoteException;
	String getName() throws RemoteException;
}
