package Esercizio1.SolProxy;

import java.io.IOException;
import java.net.InetAddress;
import java.net.UnknownHostException;

public class MultiClient {
	static final int NUM_THREADS = 12;
	static final int MAX_THREADS = 4;

	void exec(String adr) {
		InetAddress addr;
		try {
			addr = InetAddress.getByName(adr);
		} catch (UnknownHostException e) {
			System.err.println("address creation failed: abort");
			return;
		}
		int i = 0;
		while (i < NUM_THREADS) {
			if (ClientThread.threadCount() < MAX_THREADS) {
				new ClientThread(addr, i);
				i++;
			}
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
			}
		}
	}

	public static void main(String[] args) throws IOException, InterruptedException {
		if (args.length == 1) {
			new MultiClient().exec(args[0]);
		} else {
			new MultiClient().exec("localhost");
		}
	}
}
