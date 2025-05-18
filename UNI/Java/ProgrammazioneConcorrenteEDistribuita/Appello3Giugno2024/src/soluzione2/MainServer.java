package soluzione2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MainServer {

	public static void main(String[] args) {
		CasellePostali leCaselle = new CasellePostali();
		
		try {
			ServerSocket serverSocket = new ServerSocket(1099);
			System.out.println("Server di posta avviato, in attesa dei client...");
			while (true) {
				Socket socket = serverSocket.accept();
				
				// Creazione thread e handler con passaggio del socket e leCaselle (risorsa comune)
				Thread thread = new Thread(new ClientHandler(socket, leCaselle));
				thread.start();
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
