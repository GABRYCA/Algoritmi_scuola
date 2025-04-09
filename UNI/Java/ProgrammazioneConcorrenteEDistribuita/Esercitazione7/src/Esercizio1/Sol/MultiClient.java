package Esercizio1.Sol;

import java.io.IOException;
import java.net.InetAddress;

public class MultiClient {
	static final int NUM_THREADS = 10;
	static final int MAX_THREADS = 4;
	public static void main(String[] args) throws IOException, InterruptedException {
		InetAddress addr = InetAddress.getByName(null);
		System.out.println(addr);
		int i=0;
		while (i<NUM_THREADS) {
			if (ClientThread.threadCount() < MAX_THREADS)
				new ClientThread(addr, i++);
			else
				Thread.sleep(10);
			Thread.sleep(100);
		}
	}
}
