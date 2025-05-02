package eu.anonymousgca.multi;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MainServer {

	public static void main(String[] args) {
		System.out.println("Avviando il server...");
		
		Counter counter = new Counter();
		
		try {
			ServerSocket socket = new ServerSocket(ServerInterface.PORT);
			System.out.println("Server avviato sulla porta: " + ServerInterface.PORT);
			System.out.println("In attesa di connessioni...");
			
			// Accetto connessioni client
			while(true) {
				Socket clientSocket = socket.accept();
				System.out.println("Ricevuta connessione da: " + clientSocket.getRemoteSocketAddress());
				ClientHandler clientHandler = new ClientHandler(clientSocket, counter);
				
				Thread clientThread = new Thread(clientHandler);
				
				clientThread.start();
				
				System.out.println("Avviato thread " + clientThread.getName() + " per gestire il client.");
			}
		} catch (IOException e) {
			System.out.println("Errore durante l'inizializzazione del server: " + e.getMessage());
			System.exit(1);
		}
	}

}
