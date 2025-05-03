import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ServerInterface extends Remote{
	
	void registraClient(ClientInterface client) throws RemoteException;
	
	void unregistraClient(ClientInterface client) throws RemoteException;
	
	void broadcastMessaggio(String messaggio, ClientInterface client) throws RemoteException;

}
