package soluzione2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MainServer {

	public static void main(String[] args) {
		Tavolo tavolo = new Tavolo();
		Gestore ilGestore = new Gestore(tavolo);
		
		try {
			ServerSocket serverSocket = new ServerSocket(1099);
			System.out.println("Il server è in ascolto...");
			while (true) {
				Socket socket = serverSocket.accept();
				
				HandlerClient client = new HandlerClient(socket, ilGestore);
				Thread thread = new Thread(client);
				thread.start();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
