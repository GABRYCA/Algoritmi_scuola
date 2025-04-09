package Esercizio1.Sol;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MultiServer {
	static final int PORT = 8080;

	public static void main(String[] args) throws IOException {
		ServerSocket s = new ServerSocket(PORT);
		System.out.println("Server Started");
		try {
			while (true) {
				Socket socket = s.accept();
				System.out.println("Server accepts connection");
				try {
					new SegmentServer(socket);
				} catch (IOException e) {
					// If it fails, close the socket,
					// otherwise the thread will close it:
					socket.close();
				}
			}
		} finally {
			s.close();
		}
	}
}
