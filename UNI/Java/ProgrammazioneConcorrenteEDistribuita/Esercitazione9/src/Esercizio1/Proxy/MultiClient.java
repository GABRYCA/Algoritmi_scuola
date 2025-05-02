package Esercizio1.Proxy;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class MultiClient {
	static final int MAX_THREADS = 3;
	static final int CLIENT_THREADS_TOT = Server.MAXclients;

	void exec() {
		InetAddress addr = null;
		try {
			addr = InetAddress.getByName(null);
		} catch (UnknownHostException e) {
			System.err.println("no address");
			System.exit(0);
		}
		int i = 0;
		while (i < CLIENT_THREADS_TOT) {
			if (ClientThread.threadCount() < MAX_THREADS) {
				new ClientThread(addr, i);
				i++;
			} else {
				try {
					Thread.sleep(20);
				} catch (InterruptedException e) {
				}
			}
		}
	}

	public static void main(String[] args) {
		new MultiClient().exec();
	}
}
