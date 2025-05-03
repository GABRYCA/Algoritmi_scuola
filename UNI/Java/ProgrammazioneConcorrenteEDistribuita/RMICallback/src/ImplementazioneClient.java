import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ImplementazioneClient extends UnicastRemoteObject implements ClientInterface {

	private final String nome;

	protected ImplementazioneClient(String nome) throws RemoteException {
		super();
		this.nome = nome;
	}

	@Override
	public void riceviMessaggio(String messaggio) throws RemoteException {
		System.out.println("Messaggio: " + messaggio);
		
	}

	@Override
	public String getName() throws RemoteException {
		return this.nome;
	}
	
	
}
