package Esercizio3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.util.concurrent.ThreadLocalRandom;

public class Producer extends Thread {
	private String myName;
	private Socket mySocket;
	private BufferedReader in;
	private PrintWriter out;

	public Producer(InetAddress addr, String n) throws IOException {
		this.mySocket = new Socket(addr, 9999);
		this.myName = n;
		this.in = new BufferedReader(new InputStreamReader(mySocket.getInputStream()));
		this.out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(mySocket.getOutputStream())), true);
		start();
	}

	public void run() {
		for (int i = 0; i < 8; i++) {
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(100, 200));
			} catch (InterruptedException e) {
			}
			out.println("put");
			System.out.println("Producing " + myName + "_" + i);
			out.println(myName + "_" + i);
		} // fine ciclo
		out.println("END");
	}
}
