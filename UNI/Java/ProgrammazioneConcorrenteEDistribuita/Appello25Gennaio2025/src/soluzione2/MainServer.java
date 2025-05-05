package soluzione2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MainServer {
	
	private static int numResources = 4;

	public static void main(String[] args) {
		ResourceManager rm = new ResourceManager();
		for (int i = 0; i < numResources; i++) { // Attenzione!
			// le risorse di ciascun tipo sono meno degli utilizzatori!
			rm.put(new Resource(ResourceType.A));
			rm.put(new Resource(ResourceType.B));
		}
		
		try {
			ServerSocket serverSocket = new ServerSocket(8888);
			
			while (true) {
				System.out.println("In attesa di connessioni...");
				Socket socket = serverSocket.accept();
				
				System.out.println("Connessione ricevuta, creazione handler...");
				
				ClientHandler handler = new ClientHandler(socket, rm);
				// Creo nuovo thread
				Thread thread = new Thread(handler);
				thread.start();
			}
		} catch (IOException e) {
		}
		
		System.out.println("Server chiuso!");
	}

}
