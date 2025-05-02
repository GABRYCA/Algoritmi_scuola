package Esercizio0;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MultiServer {
	static final int PORT = 9099;

	void exec() {
		ServerSocket s;
		try {
			s = new ServerSocket(PORT);
			System.out.println("Server Started");
			while (true) {
				Socket socket = s.accept();
				System.out.println("Server accepted connection");
				new SegmentSlave(socket);
			}
		} catch (IOException e1) {
			System.err.println("Server closing (I/O error)");
			return;
		}
	}

	public static void main(String[] args) {
		new MultiServer().exec();
		System.err.println("Server closed");
	}
}
