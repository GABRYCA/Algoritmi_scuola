package Esercizio2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	static final int PORT = 8999;
	static final int MAXclients = 10;

	public static void main(String[] args) throws IOException {
		ServerSocket s = new ServerSocket(PORT);
		Bank theBank = new Bank(MAXclients);
		System.out.println("Server Started");
		try {
			while (true) {
				Socket socket = s.accept();
				System.out.println("Server accepts connection");
				new BankServerThread(socket, theBank);
			}
		} finally {
			s.close();
		}
	}
}
