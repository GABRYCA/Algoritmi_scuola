package soluzione2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MainServer {

	public static void main(String[] args) {
		Magazzino magazzino = new Magazzino(5);

		try {
			ServerSocket ss = new ServerSocket(1099);
			
			System.out.println("Server avviato, in attesa di connessioni...");
			
			while (true) {
				Socket s = ss.accept();
				
				System.out.println("Ricevuta richiesta di connessione, creazione handler...");
				
				Thread thread = new Thread(new ClientHandler(s, magazzino));
				thread.start();
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
		}
	}

}
