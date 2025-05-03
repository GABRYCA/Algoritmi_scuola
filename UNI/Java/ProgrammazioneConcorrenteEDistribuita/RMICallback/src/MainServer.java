import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MainServer {

	public static void main(String[] args) {
		/*if (System.getSecurityManager() == null) {
			System.setSecurityManager(new SecurityManager());
		}*/

		int portaRegistry = Registry.REGISTRY_PORT;

		if (args.length > 0) {
			try {
				portaRegistry = Integer.parseInt(args[0]);
			} catch (NumberFormatException e) {}
		}

		try {
			ImplementazioneServer server = new ImplementazioneServer();
			System.out.println("Creato il server.");

			Registry registry;
			registry = LocateRegistry.createRegistry(portaRegistry);
			
			registry.rebind("ChatRMI", server);
			
			System.out.println("Registrato nel registry nuovo servizio (ChatRMI)");
		} catch (RemoteException e) {}
	}

}
