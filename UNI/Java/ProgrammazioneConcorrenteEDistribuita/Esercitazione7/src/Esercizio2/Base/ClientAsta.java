package Esercizio2.Base;

import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;

public class ClientAsta {
	public static void main(String[] args) throws IOException, InterruptedException {
		final int numClients = 3;
		InetAddress addr = InetAddress.getByName(null);
		for (int i = 0; i < numClients; i++) {
			String cliName = "cli" + i;
			Socket s = new Socket(addr, 9999);
			new ClientAstaThread(s, cliName);
		}
	}
}
