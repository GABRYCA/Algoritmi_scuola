package soluzione2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerMain {
	
	public static void main(String[] args) {
		TavoloGioco t = new TavoloGioco(0);
		int giocatori = 0;
		try {
			ServerSocket ss = new ServerSocket(1099);
			System.out.println("Server avviato con successo, in attesa dei giocatori...");
			while (true) {
				Socket socket = ss.accept();
				
				if (giocatori <= 1) { 
				
					giocatori++;
					System.out.println("Ricevuta connessione giocatore: " + giocatori);
					Thread thread = new Thread(new GestoreGiocatore(socket, t));
					thread.start();
					
				} else {
					System.out.println("Raggiunto il numero massimo di giocatori.");
					socket.close();
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
