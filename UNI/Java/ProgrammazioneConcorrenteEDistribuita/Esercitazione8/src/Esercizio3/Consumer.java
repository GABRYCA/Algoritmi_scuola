package Esercizio3;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.util.concurrent.ThreadLocalRandom;

public class Consumer extends Thread {
	private String myName;
	private Socket mySocket;
	private ObjectInputStream in;
	private ObjectOutputStream out;

	public Consumer(InetAddress addr, String n) throws IOException {
		this.mySocket = new Socket(addr, 9999);
		this.myName = n;
		this.out = new ObjectOutputStream(mySocket.getOutputStream());
		this.in = new ObjectInputStream(mySocket.getInputStream());
		start();
	}

	private void mySleep() {
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(100, 200));
		} catch (InterruptedException e) {}
	}

	public void run() {
		Roba r;
		System.out.println(myName + " running ");
		try {
			for (int i = 0; i < 8; i++) {
				out.writeObject("get");
				r = (Roba) in.readObject();
				System.out.println(myName + " consumes " + r);
				mySleep();
			} // fine ciclo
			out.writeObject("END");
		} catch (IOException | ClassNotFoundException e) {
			return;
		}
	}
}
