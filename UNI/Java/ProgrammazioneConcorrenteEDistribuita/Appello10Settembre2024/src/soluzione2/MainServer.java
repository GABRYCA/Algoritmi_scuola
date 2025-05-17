package soluzione2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MainServer {

	public static void main(String[] args) {
		Tavolo gestore = new Tavolo();
		
		try {
			ServerSocket serverSocket = new ServerSocket(1099);
			System.out.println("Server creato con successo, in ascolto...");
			while (true) {
				Socket socket = serverSocket.accept();
				
				Thread thread = new Thread(new ClientHandler(socket, gestore));
				thread.start();
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
