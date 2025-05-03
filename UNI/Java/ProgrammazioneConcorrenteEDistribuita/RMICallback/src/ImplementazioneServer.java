import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

public class ImplementazioneServer extends UnicastRemoteObject implements ServerInterface {
	
	private final List<ClientInterface> clients;

	protected ImplementazioneServer() throws RemoteException {
		super();
		
		clients = new CopyOnWriteArrayList<>();
		System.out.println("Creato ed esportata implementazione Server.");
	}

	@Override
	public synchronized void registraClient(ClientInterface client) throws RemoteException {
		if (!clients.contains(client)) {
			clients.add(client);
			System.out.println("Registrato client: " + client.getName());
			broadcastMessaggio(client.getName() + " si è unito alla chat!", null);
		}
		
	}

	@Override
	public synchronized void unregistraClient(ClientInterface client) throws RemoteException {
		if (clients.remove(client)) {
			System.out.println("Rimosso client: " + client.getName());
			broadcastMessaggio(client.getName() + " si è disconnesso!", null);
		}
	}

	@Override
	public void broadcastMessaggio(String messaggio, ClientInterface client) throws RemoteException {
		String sender = "Sistema";
		if (client != null) {
			sender = client.getName();
		}
		
		
		String messaggioDaInviare = sender + ": " + messaggio;
		System.out.println("Broadcast: " + messaggioDaInviare);
		
		for (ClientInterface singoloClient : clients) {
			if (client != null && singoloClient.equals(client)) { // Non invio a me stesso
				continue;
			}
			
			singoloClient.riceviMessaggio(messaggioDaInviare);
		}
	}
	

}
