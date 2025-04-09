package Esercizio3;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class Server {
	public static final int PORT = 9999;
	final static int BufferCapacity = 8;

	public static void main(String[] args) throws IOException {
		BlockingQueue<String> data = new ArrayBlockingQueue<String>(BufferCapacity);
		ServerSocket s = new ServerSocket(PORT);
		System.out.println("Server pronto");
		while (true) {
			Socket cliSocket = null;
			cliSocket = s.accept();
			new ServerThread(data, cliSocket);
		} // fine ciclo accettazioni
	}
}
