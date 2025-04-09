package Esercizio3;

import java.io.IOException;
import java.net.InetAddress;

public class Client {
	public static void main(String[] args) throws IOException, InterruptedException {
		final int numClients = 2;
		InetAddress addr = InetAddress.getByName(null);
		for (int i = 0; i < numClients; i++) {
			new Producer(addr, "prod_" + i);
			new Consumer(addr, "cons_" + i);
		}
	}
}
