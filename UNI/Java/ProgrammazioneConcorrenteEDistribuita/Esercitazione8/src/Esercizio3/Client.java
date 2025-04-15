package Esercizio3;

import java.io.IOException;
import java.net.InetAddress;
import java.net.UnknownHostException;

public class Client {
	public static void main(String[] args) {
		final int numClients = 3;
		InetAddress addr = null;
		try {
			addr = InetAddress.getByName(null);
		} catch (UnknownHostException e) {
			e.printStackTrace();
			System.exit(0);
		}
		try {
			for (int i = 0; i < numClients; i++) {
				new Producer(addr, "prod_" + i);
				new Consumer(addr, "cons_" + i);
			}
		} catch (IOException e) {
			System.err.println("clinet creation failed");
			e.printStackTrace();
		}
	}
}
