package Esercizio3;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

public class Producer extends Thread {
	private String myName;
	private Socket mySocket;
	private ObjectInputStream in;
	private ObjectOutputStream out;
	Random rnd;

	public Producer(InetAddress addr, String n) throws IOException {
		this.mySocket = new Socket(addr, 9999);
		this.myName = n;
		rnd = new Random();
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
		Roba r = null;
		System.out.println(myName + " running ");
		try {
			for (int i = 0; i < 8; i++) {
				mySleep();
				r = new Roba(i, "tipo" + rnd.nextInt(100), "prod+" + myName);
				out.writeObject("put");
				out.writeObject(r);
				System.out.println(myName + " produces " + r);
			} // fine ciclo
			out.writeObject("END");
		} catch (IOException e) {
			return;
		}
	}
}
