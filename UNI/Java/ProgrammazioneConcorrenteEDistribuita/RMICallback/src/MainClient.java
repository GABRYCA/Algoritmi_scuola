import java.rmi.NoSuchObjectException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Scanner;

public class MainClient {

	public static void main(String[] args) {
		/*if (System.getSecurityManager() == null) {
			System.setSecurityManager(new SecurityManager());
		}*/

		String host = "localhost";
		int portaRegistry = Registry.REGISTRY_PORT;
		String username = null;

		if (args.length > 0)
			host = args[0];
		if (args.length > 1) {
			try {
				portaRegistry = Integer.parseInt(args[1]);
			} catch (NumberFormatException e) {
			}
		}

		if (args.length > 2) {
			username = args[2];
		} else {
			Scanner scanner = new Scanner(System.in);
			System.out.print("Inserire il tuo username: ");
			username = scanner.nextLine();
		}

		ImplementazioneClient client = null;
		ServerInterface server = null;

		try {
			client = new ImplementazioneClient(username);
			System.out.println("Creato ed espostato client locale con nome: " + username);

			Registry registry = LocateRegistry.getRegistry(host, portaRegistry);
			System.out.println("Ottenuto registro da: " + host + ":" + portaRegistry);

			try {
				server = (ServerInterface) registry.lookup("ChatRMI");
				server.registraClient(client);

				Scanner scanner = new Scanner(System.in);
				String linea;
				while (scanner.hasNextLine()) {
					linea = scanner.nextLine();
					if ("/quit".equalsIgnoreCase(linea.trim())) {
						break;
					}

					server.broadcastMessaggio(linea, client);
				}

				scanner.close();
			} catch (NotBoundException e) {
			}

		} catch (RemoteException e) {
		} finally {
			if (server != null && client != null) {
				try {
					server.unregistraClient(client);
				} catch (RemoteException e) {
				}
			}
			
			if (client != null) {
				try {
					UnicastRemoteObject.unexportObject(client, true);
				} catch (NoSuchObjectException e) {
				}
			}
		}

		System.out.println("Client terminato");
	}

}
