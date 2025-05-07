package soluzione2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MainServer {
	
	static final int numGiocatori = 3;
	static final int porta = 1069;

	public static void main(String[] args) {
		Gioco gioco = new Gioco(numGiocatori);
		int giocatoriEntrati = 0;
		
		try {
			ServerSocket serverSocket = new ServerSocket(porta);
			System.out.println("Server avviato, in attesa di connessioni...");
			while (true) {
				
				Socket socket = serverSocket.accept();
				
				System.out.println("Ricevuta una connessione...");
				if (giocatoriEntrati >= numGiocatori) {
					System.out.println("Raggiunto il numero massimo di giocatori!");
					continue;
				}
				
				GiocatoreHandler giocatore = new GiocatoreHandler(socket, gioco, giocatoriEntrati++);
				Thread thread = new Thread(giocatore);
				thread.start();
			}
		} catch (IOException e) {
		}
	}

}
