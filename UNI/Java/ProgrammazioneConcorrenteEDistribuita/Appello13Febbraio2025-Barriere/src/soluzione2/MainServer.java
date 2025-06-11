package soluzione2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MainServer {

	static final int numGiocatori = 3;

	public static void main(String[] args) {
		Gioco g = new Gioco(numGiocatori);

		try {
			ServerSocket ss = new ServerSocket(1099);
			
			System.out.println("Server creato con successo e in ascolto...");

			while (true) {
				
				Socket s = ss.accept();
				
				// Creazione handler
				Thread thread = new Thread(new GiocatoreHandler(s, g));
				thread.start();
				
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
