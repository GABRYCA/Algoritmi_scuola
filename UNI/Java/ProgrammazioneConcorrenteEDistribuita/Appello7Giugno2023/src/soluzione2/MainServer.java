package soluzione2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MainServer {

	public static void main(String[] args) {
		Dati iDati = new Dati();

		try {
			ServerSocket serverSocket = new ServerSocket(1099);
			System.out.println("Server creato e in ascolto...");
			while (true) {
				Socket socket = serverSocket.accept();
				 
				Thread thread = new Thread(new ClientHandler(socket, iDati));
				thread.start();
			}
		} catch (IOException e) {
		}
		
	}

}
