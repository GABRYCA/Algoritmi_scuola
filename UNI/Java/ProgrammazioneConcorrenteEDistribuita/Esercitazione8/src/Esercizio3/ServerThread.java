package Esercizio3;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.concurrent.BlockingQueue;

public class ServerThread extends Thread {
	private BlockingQueue<Roba> data;
	private Socket cliSocket;
	private ObjectInputStream in;
	private ObjectOutputStream out;

	public ServerThread(BlockingQueue<Roba> d, Socket s) throws IOException {
		this.data = d;
		this.cliSocket = s;
		this.out = new ObjectOutputStream(s.getOutputStream());
		this.in = new ObjectInputStream(s.getInputStream());
		start();
	}

	public void run() {
		while (true) {
			String str;
			try {
				str = (String) in.readObject();
			} catch (IOException | ClassNotFoundException e) {
				str = "END";
			}
			System.out.println("Server received " + str);
			if (str.equals("END"))
				break;
			try {
				if (str.equals("put")) {
					data.put((Roba) in.readObject());
				}
				if (str.equals("get")) {
					out.writeObject(data.take());
				}
			} catch (IOException | InterruptedException | ClassNotFoundException e) {
				break;
			}
			System.out.println("Server executed command " + str);
		}
		try {
			cliSocket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
